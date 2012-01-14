#include "midiMultiProgramChange.hpp"

//for fmod()
#include <cmath>

//for seeding rand()
#include <time.h> 

//for sprintf()
#include <string>

//-------------------------------------------------------------------------------------------------------
AudioEffect* createEffectInstance (audioMasterCallback audioMaster) {
	return new MidiProgramChange (audioMaster);
}

MidiProgramChangeProgram::MidiProgramChangeProgram ()
{
	// default Program Values
	for (int i=0;i<kNumParams;i++) param[i]=0.f;
	param[kThru]=1.f;
	param[kTrigger]=0.4f;
    // default program name
	strcpy (name, "Default");
}

//-----------------------------------------------------------------------------
MidiProgramChange::MidiProgramChange(audioMasterCallback audioMaster)
	: PizMidi(audioMaster, kNumPrograms, kNumParams), programs(0)
{ 
	programs = new MidiProgramChangeProgram[numPrograms];

	if (programs) {
		CFxBank* defaultBank = new CFxBank(kNumPrograms,kNumParams);
		if (readDefaultBank(PLUG_NAME,defaultBank)) {
			if((VstInt32)defaultBank->GetFxID()==PLUG_IDENT) {
				for(int i=0;i<kNumPrograms;i++){
					for (int p=0;p<kNumParams;p++) {
						programs[i].param[p] = defaultBank->GetProgParm(i,p);
					}
					strcpy(programs[i].name,defaultBank->GetProgramName(i));
				}
			}
		}
		else {
			// built-in programs
			for(int i=0;i<kNumPrograms;i++){
		        sprintf(programs[i].name,"Program %d", i+1);
			}
		}
	    setProgram (0);
	}

	trigger=false;
	senttrig=false;
    for (int i=0;i<kNumParams;i++) automated[i]=false;
    
	wait=false;
	delaytime=(int)(sampleRate*0.002f);
	counter=0;
	triggerdelta=0;

	if (programs) setProgram (0);

	init();
}


//-----------------------------------------------------------------------------------------
MidiProgramChange::~MidiProgramChange(){
	if (programs) delete [] programs;
}

//------------------------------------------------------------------------
void MidiProgramChange::setProgram (VstInt32 prog)
{
	MidiProgramChangeProgram* ap = &programs[prog];
	curProgram = prog;
	for (int i=0;i<kNumParams;i++) {
    	setParameter(i,ap->param[i]);
    }
    trigger=true;
}

//------------------------------------------------------------------------
void MidiProgramChange::setProgramName (char *name)
{
	vst_strncpy (programs[curProgram].name, name, kVstMaxProgNameLen);
}

//------------------------------------------------------------------------
void MidiProgramChange::getProgramName (char *name)
{
	strcpy (name, programs[curProgram].name);
}

//-----------------------------------------------------------------------------------------
bool MidiProgramChange::getProgramNameIndexed (VstInt32 category, VstInt32 index, char* text)
{
	if (index < kNumPrograms)
	{
		strcpy (text, programs[index].name);
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------------------
void  MidiProgramChange:: setSampleRate(float sampleRateIn){
   PizMidi::setSampleRate (sampleRateIn);
    delaytime=(int)(sampleRate*0.002f);
}

//-----------------------------------------------------------------------------------------
void MidiProgramChange::setParameter(VstInt32 index, float value){
     MidiProgramChangeProgram* ap = &programs[curProgram];
	if (index==kThru) {
		thru = value>=0.5f;
 		param[index] = value;
		for (int i=0;i<kNumPrograms;i++)
			programs[i].param[index] = value;
	}
	else if (index==kChannel) {
		param[index] = value;
		for (int i=0;i<kNumPrograms;i++)
			programs[i].param[index] = value;
	}
	else if (index == kTrigger) {
        param[index]=value;
		if (value==1.f){// && !senttrig) {
			trigger=true;
			senttrig=true;
		}
		else if (value<1.f && senttrig) senttrig=false;
	}
	else if (index >= kProgram && index < kProgram+16) { 
        program[index-kProgram]=FLOAT_TO_MIDI2(value);
		if (!automated[index]) trigger=true;
        param[index] = ap->param[index] = value;
	}
}

//-----------------------------------------------------------------------------------------
float MidiProgramChange::getParameter(VstInt32 index){
      return param[index];
}

//-----------------------------------------------------------------------------------------
void MidiProgramChange::getParameterName(VstInt32 index, char *label){
	if (index==kThru) {
		strcpy(label, "Thru");
	}
	else if (index >= kProgram && index < kProgram+16) { 
        sprintf(label, "Program %d", index-kProgram+1);
	}
	else if (index==kChannel) {
        strcpy(label, "InChannel");
	}
	else if (index==kTrigger) {
        strcpy(label, "Trigger");
	}
}

//-----------------------------------------------------------------------------------------
void MidiProgramChange::getParameterDisplay(VstInt32 index, char *text){
	if (index==kThru) {
		if (thru) strcpy(text, "Yes");
		else strcpy(text, "No");
	}
	else if (index >= kProgram && index < kProgram+16) { 
        if (program[index-kProgram]==0) strcpy(text, "Off");
        else sprintf(text, "%d", program[index-kProgram]); 
	}
	else if (index==kChannel) {
        sprintf(text, "%d",FLOAT_TO_CHANNEL015(param[index])+1);
	}
	else if (index==kTrigger) {
		if (param[index]==1.f) strcpy(text, "Triggered!");
		else strcpy(text, "Trigger-->");
	}
}

void MidiProgramChange::processMidiEvents(VstMidiEventVec *inputs, VstMidiEventVec *outputs, VstInt32 samples)
{     
	char listenchannel = FLOAT_TO_CHANNEL015(param[kChannel]);
	
	//process incoming events-------------------------------------------------------
    for (unsigned int i=0;i<inputs[0].size();i++) {
        //copying event "i" from input (with all its fields)
		VstMidiEvent tomod = inputs[0][i];
		
        unsigned char status     = tomod.midiData[0] & 0xf0;   // scraping  channel
        char channel    = tomod.midiData[0] & 0x0f;   // isolating channel (0-15)
        char data1      = tomod.midiData[1] & 0x7f;
        //char data2	    = tomod.midiData[2] & 0x7f;
		
		bool discard = !thru;
          	
        //only look at the selected channel
        if (channel == listenchannel) 
        { 
			if (status==MIDI_PROGRAMCHANGE) {
                setProgram(data1);
                updateDisplay();
                discard=true;
			}
    	} // if listenchannel==channel
    	if (!discard) outputs[0].push_back(tomod);
     } //for() inputs loop
	 
	if (trigger) {
		trigger=false;
		for (int ch = 0; ch<16;ch++) {
			if(program[ch]!=0) {
        		//create GUI triggered message
        		VstMidiEvent progch;
        		progch.midiData[0] = MIDI_PROGRAMCHANGE | ch;
        		progch.midiData[1] = program[ch]-1;
        		progch.midiData[2] = 0x0;
        		progch.deltaFrames = triggerdelta;
        		outputs[0].push_back(progch);
				setParameterAutomated(kTrigger,0.4f);
			}
		}
	}
}                                                                                                               
