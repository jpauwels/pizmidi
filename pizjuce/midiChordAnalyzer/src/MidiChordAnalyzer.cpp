#include "MidiChordAnalyzer.h"
#include "MidiChordAnalyzerEditor.h"

//==============================================================================
/**
    This function must be implemented to create a new instance of your
    plugin object.
*/
PizAudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MidiChordAnalyzer();
}

//==============================================================================
MidiChordAnalyzerPrograms::MidiChordAnalyzerPrograms ()
: ValueTree("MidiChordAnalyzerValues")
{
	this->setProperty("lastProgram",0,0);
	this->setProperty("Version",3,0);
	for (int p=0;p<numProgs;p++) 
	{
		ValueTree progv("ProgValues");
		progv.setProperty("progIndex",p,0);

		progv.setProperty("Channel",0,0);
		progv.setProperty("Flats",false,0);

		progv.setProperty("Name","Program "+ String(p+1),0);
		progv.setProperty("lastUIWidth",600,0);
		progv.setProperty("lastUIHeight",400,0);
	}
}

//==============================================================================
MidiChordAnalyzer::MidiChordAnalyzer() : programs(0), curProgram(0)
{
	DBG("MidiChordAnalyzer()");

	fillChordDatabase();
	programs = new MidiChordAnalyzerPrograms();
    if (!loadDefaultFxb())
	{
		channel = 0;
		flats = false;
		lastUIWidth = 480;
		lastUIHeight = 200;
	}

	init = true;
	setCurrentProgram(0);
}

MidiChordAnalyzer::~MidiChordAnalyzer()
{
	DBG("~MidiChordAnalyzer()");
	if (programs) deleteAndZero(programs);
}

//==============================================================================
const String MidiChordAnalyzer::getName() const
{
    return JucePlugin_Name;
}

int MidiChordAnalyzer::getNumParameters()
{
    return numParams;
}

void MidiChordAnalyzer::setCurrentProgram (int index)
{
    //save non-parameter info to the old program, except the first time
    if (!init) 
		copySettingsToProgram(curProgram);
    init = false;

    //then set the new program
    curProgram = index;
	programs->setProperty("lastProgram",index,0);
	channel = programs->get(index,"Channel");
	flats = programs->get(index,"Flats");

    lastUIWidth = programs->get(index,"lastUIWidth");
    lastUIHeight = programs->get(index,"lastUIHeight");
}

float MidiChordAnalyzer::getParameter (int index)
{
    switch (index)
    {
    case kChannel: return ((float)channel)/16.f;
	case kFlats: return flats ? 1.f : 0.f;

	default: return 0.0f;
    }
}

void MidiChordAnalyzer::setParameter (int index, float newValue)
{
    if (index==kChannel)
    {
        channel = roundToInt(newValue*16.f);
        sendChangeMessage();
    }
    else if (index==kFlats)
    {
        flats = newValue>0.f;
        sendChangeMessage();
    }
}

const String MidiChordAnalyzer::getParameterName (int index)
{
    if (index == kChannel)        return "Channel";
	if (index == kFlats)		  return "Flats";
	return String::empty;
}

const String MidiChordAnalyzer::getParameterText (int index)
{
    if (index == kChannel)
		return channel==0 ? "Any" : String(channel);
    if (index == kFlats)
        return flats ? "Yes" : "No";  
	return String::empty;
}

const String MidiChordAnalyzer::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String MidiChordAnalyzer::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool MidiChordAnalyzer::isInputChannelStereoPair (int index) const
{
    return true;
}

bool MidiChordAnalyzer::isOutputChannelStereoPair (int index) const
{
    return true;
}

//==============================================================================
void MidiChordAnalyzer::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void MidiChordAnalyzer::releaseResources()
{
}

void MidiChordAnalyzer::processBlock (AudioSampleBuffer& buffer,
                                MidiBuffer& midiMessages)
{

	chordKbState.processNextMidiBuffer(midiMessages,0,buffer.getNumSamples(),true);

	MidiBuffer::Iterator mid_buffer_iter(midiMessages);
	MidiMessage m(0xf0);
	int sample;
	while(mid_buffer_iter.getNextEvent(m,sample)) 
	{
		if (channel==0 || m.isForChannel(channel))
		{
			if (m.isNoteOn()) {
				sendChangeMessage();
			}
			else if (m.isNoteOff()) {
				sendChangeMessage();
			}
		}
	}
	

    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
AudioProcessorEditor* MidiChordAnalyzer::createEditor()
{
    return new MidiChordAnalyzerEditor (this);
}

//==============================================================================
void MidiChordAnalyzer::getStateInformation (MemoryBlock& destData)
{
	copySettingsToProgram(curProgram);
	MemoryOutputStream m(destData,false);
	programs->writeToStream(m);
}

void MidiChordAnalyzer::getCurrentProgramStateInformation (MemoryBlock& destData)
{
	copySettingsToProgram(curProgram);
	MemoryOutputStream m(destData,false);
	programs->getChild(curProgram).writeToStream(m);
}

void MidiChordAnalyzer::setStateInformation (const void* data, int sizeInBytes)
{
	MemoryInputStream m(data,sizeInBytes,false);
	ValueTree vt = ValueTree::readFromStream(m);
	if (vt.isValid())
	{
			programs->removeAllChildren(0);
			for (int i=0;i<vt.getNumChildren();i++)
			{
				programs->addChild(vt.getChild(i).createCopy(),i,0);
			}
	}
	init=true;
	setCurrentProgram(vt.getProperty("lastProgram",0));
}

void MidiChordAnalyzer::setCurrentProgramStateInformation (const void* data, int sizeInBytes)
{
	MemoryInputStream m(data,sizeInBytes,false);
	ValueTree vt = ValueTree::readFromStream(m);
	if(vt.getChildWithName("NoteMatrix_T0").isValid())
	{
		programs->removeChild(programs->getChild(curProgram),0);
		programs->addChild(vt,curProgram,0);
		programs->getChild(curProgram).setProperty("progIndex",curProgram,0);
	}
	init=true;
	setCurrentProgram(curProgram);
}

void MidiChordAnalyzer::copySettingsToProgram(int index)
{
	programs->set(index,"Channel",channel);
    programs->set(index,"Name",getProgramName(index));
	programs->set(index,"lastUIHeight",lastUIHeight);
    programs->set(index,"lastUIWidth",lastUIWidth);
	programs->set(index,"Flats",flats);
}

