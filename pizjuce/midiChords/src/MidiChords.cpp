#include "MidiChords.h"
#include "MidiChordsEditor.h"

//==============================================================================
/**
    This function must be implemented to create a new instance of your
    plugin object.
*/
PizAudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MidiChords();
}

//==============================================================================
MidiChordsPrograms::MidiChordsPrograms ()
: ValueTree("midiChordsValues")
{
	this->setProperty("lastProgram",0,0);
	for (int p=0;p<numProgs;p++) 
	{
		ValueTree progv("ProgValues");
		progv.setProperty("progIndex",p,0);

		progv.setProperty("Channel",0,0);
		progv.setProperty("FollowInput",true,0);
		progv.setProperty("Transpose",0,0);
		progv.setProperty("ChordMode",Normal,0);
		progv.setProperty("Root",60,0);
		progv.setProperty("Guess",true,0);
		progv.setProperty("Flats",false,0);
		progv.setProperty("UsePC",false,0);

		//progv.setProperty("Velocity",0.f,0);

		progv.setProperty("Name","Program "+ String(p+1),0);
		progv.setProperty("lastUIWidth",600,0);
		progv.setProperty("lastUIHeight",400,0);
		progv.setProperty("lastTrigger",60,0);

		ValueTree noteMatrix("NoteMatrix");
		for (int i=0;i<128;i++) {
			noteMatrix.setProperty("T"+String(i)+"_0-31", 0, 0);
			noteMatrix.setProperty("T"+String(i)+"_32-63", 0, 0);
			noteMatrix.setProperty("T"+String(i)+"_64-95", 0, 0);
			noteMatrix.setProperty("T"+String(i)+"_96-127", 0, 0);
		}
		progv.addChild(noteMatrix,0,0);

		this->addChild(progv,p,0);
	}

	//DBG(this->createXml()->createDocument(""));
}

//==============================================================================
MidiChords::MidiChords() : programs(0), curProgram(0)
{
	DBG("MidiChords()");
	fillChordDatabase();
	programs = new MidiChordsPrograms();
	memset(numChordNotes,0,sizeof(numChordNotes));
    if (!loadDefaultFxb())
	{
		channel = 0;
		follow = true;
		usepc = false;
		transpose = 0;
		mode = Normal;
		root = 60;
		guess = true;
		flats = false;
		velocity = 0.f;
		lastUIWidth = 600;
		lastUIHeight = 400;
		for (int i=0;i<128;i++)
			selectChordNote(i,i,true);
		selectTrigger(60);
	}
	memset(notePlaying,0,sizeof(notePlaying));
	memset(chordNotePlaying,0,sizeof(chordNotePlaying));
	for (int c=0;c<16;c++)
		for (int i=0;i<128;i++)
			outputNote[c][i]=-1;
	learn = false;
	learning = 0;
	playFromGUI = playingFromGUI = false;
	playButtonTrigger = curTrigger;
	init = true;
	setCurrentProgram(0);
}

MidiChords::~MidiChords()
{
	DBG("~MidiChords()");
	if (programs) deleteAndZero(programs);
}

//==============================================================================
const String MidiChords::getName() const
{
    return JucePlugin_Name;
}

int MidiChords::getNumParameters()
{
    return numParams;
}

void MidiChords::setCurrentProgram (int index)
{
    //save non-parameter info to the old program, except the first time
    if (!init) 
		copySettingsToProgram(curProgram);
    init = false;

    //then set the new program
    curProgram = index;
	programs->setProperty("lastProgram",index,0);
	channel = programs->get(index,"Channel");
	follow = programs->get(index,"FollowInput");
	transpose = programs->get(index,"Transpose");
	mode = programs->get(index,"ChordMode");
	root = programs->get(index,"Root");
	guess = programs->get(index,"Guess");
	flats = programs->get(index,"Flats");

	//usepc = programs->get(index,"UsePC");

    lastUIWidth = programs->get(index,"lastUIWidth");
    lastUIHeight = programs->get(index,"lastUIHeight");
	learn = false;
	
	for (int i=0;i<128;i++) {
		progKbState[curProgram][i].reset();
		for (int n=0;n<128;n++)
		{
			if (programs->getChordNote(index,i,n))
				progKbState[curProgram][i].noteOn(1,n,128);
		}
	}
	selectTrigger(programs->get(index,"lastTrigger"));
    sendChangeMessage();  
}

float MidiChords::getParameter (int index)
{
    switch (index)
    {
    case kChannel: return ((float)channel)/16.f;
	case kUseProgCh: return usepc ? 1.f : 0.f;
	case kLearnChord: return learn ? 1.f : 0.f; 
	case kFollowInput: return follow ? 1.f : 0.f; 
	case kTranspose: return ((float)transpose+48)/96.f;
	case kMode: return (float)mode/(float)(numModes-1);
	case kRoot: return (float)root/127.f;
	case kGuess: return guess ? 1.f : 0.f;
	case kFlats: return flats ? 1.f : 0.f;
	default: return 0.0f;
    }
}

void MidiChords::setParameter (int index, float newValue)
{
    if (index==kChannel)
    {
        channel = roundFloatToInt(newValue*16.f);
        sendChangeMessage();
    }
    else if (index==kUseProgCh)
    {
        usepc = newValue>0.f;
        sendChangeMessage();
    }
	else if (index==kLearnChord)
    {
        learn = newValue>0.f;
		learning = 0;
        sendChangeMessage();
    }
	else if (index==kFollowInput)
    {
        follow = newValue>0.f;
        sendChangeMessage();
    }
    else if (index==kTranspose)
    {
        transpose = roundFloatToInt(newValue*96.f)-48;
        sendChangeMessage();
    }
	else if (index==kMode)
	{
		mode = roundFloatToInt(newValue*(numModes-1));
		if (mode==Global)
			selectTrigger(root);
		else
			selectTrigger(curTrigger);
		sendChangeMessage();
    }
	else if (index==kRoot)
	{
		root = roundFloatToInt(newValue*127.f);
		if (mode==Global) {
			selectTrigger(root);
		}
        sendChangeMessage();
    }
    else if (index==kGuess)
    {
        guess = newValue>0.f;
        sendChangeMessage();
    }
    else if (index==kFlats)
    {
        flats = newValue>0.f;
        sendChangeMessage();
    }
}

const String MidiChords::getParameterName (int index)
{
    if (index == kChannel)
        return "Channel";
	if (index == kUseProgCh)
		return "UseProgCh";
	if (index == kLearnChord)
		return "Learn";
	if (index == kFollowInput)
		return "FollowInput";
	if (index == kTranspose)
		return "Transpose";
	if (index == kMode)
		return "TriggerMode";
	if (index == kRoot)
		return "RootNote";
	if (index == kGuess)
		return "GuessChord";
	if (index == kFlats)
		return "Flats";
	return String::empty;
}

const String MidiChords::getParameterText (int index)
{
    if (index == kChannel)
		return channel==0 ? "All" : String(channel);
    if (index == kUseProgCh)
        return usepc ? "Yes" : "No";    
	if (index == kLearnChord)
        return learn ? "Yes" : "No";
	if (index == kFollowInput)
        return follow ? "Yes" : "No";
    if (index == kTranspose) {
		if (transpose>0) return "+" + String(transpose);
		return String(transpose);
	}
	if (index == kMode) {
		if (mode==Normal) return "Full";
		if (mode==Octave) return "Octave";
		if (mode==Global) return "Global";
	}
	if (index==kRoot)
		return String(root);
    if (index == kGuess)
        return guess ? "Yes" : "No";  
    if (index == kFlats)
        return guess ? "Yes" : "No";  

	return String::empty;
}

const String MidiChords::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String MidiChords::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool MidiChords::isInputChannelStereoPair (int index) const
{
    return true;
}

bool MidiChords::isOutputChannelStereoPair (int index) const
{
    return true;
}

//==============================================================================
void MidiChords::prepareToPlay (double sampleRate, int samplesPerBlock)
{

}

void MidiChords::releaseResources()
{

}

void MidiChords::processBlock (AudioSampleBuffer& buffer,
                                MidiBuffer& midiMessages)
{
	MidiBuffer output;
	if (playFromGUI!=playingFromGUI)
	{
		int ch = jmax(channel,1);
		if(playFromGUI)
		{
			for (int n=0;n<128;n++)
			{
				if (progKbState[curProgram][curTrigger].isNoteOn(1,n)) {
					int newNote = n+transpose;
					if (chordNotePlaying[ch][newNote]) {
						ignoreNextNoteOff.add(newNote);
						playingChord[curTrigger].add(newNote);
					}
					else if (newNote < 128 && newNote >= 0) 
					{
						output.addEvent(MidiMessage::noteOn(ch,newNote,1.f),0);
						playingChord[curTrigger].add(newNote);
						chordNotePlaying[ch][newNote]=true;
					}
				}
			}
			notePlaying[ch][curTrigger]=true;
			playingFromGUI = true;
			playButtonTrigger = curTrigger;

		}
		else {
			int numNotes = playingChord[playButtonTrigger].size();
			if (numNotes==0) {
				if (outputNote[ch][curTrigger]!=-1) {
					output.addEvent(MidiMessage::noteOff(ch,outputNote[ch][playButtonTrigger]),0);
					outputNote[ch][playButtonTrigger]=-1;
				}
			}
			else {
				for (int i = 0; i<numNotes; i++) {
					const int chordNote = playingChord[playButtonTrigger][i];
					if (!ignoreNextNoteOff.contains(chordNote)) {
						output.addEvent(MidiMessage::noteOff(ch,chordNote),0);
						chordNotePlaying[ch][chordNote]=false;
					}
					else
						ignoreNextNoteOff.removeValue(chordNote);
				}
				playingChord[playButtonTrigger].clear();
			}
			notePlaying[ch][playButtonTrigger]=false;
			playingFromGUI = false;
		}
		playingFromGUI = playFromGUI;
	}
	MidiBuffer::Iterator mid_buffer_iter(midiMessages);
	MidiMessage m(0xf0);
	int sample;
	while(mid_buffer_iter.getNextEvent(m,sample)) 
	{
		if (m.isProgramChange() && usepc) {// && (m.isForChannel(channel) || channel==0)) {
			if (m.getProgramChangeNumber()<getNumPrograms()) 
				setCurrentProgram(m.getProgramChangeNumber());
		}
		if (channel==0 || m.isForChannel(channel))
		{
			if (m.isNoteOn()) {
				const int ch = m.getChannel();
				const int tnote = m.getNoteNumber();
				const float v = m.getFloatVelocity();
				if (learn)
				{
					if (learning==0) 
					{
						progKbState[curProgram][curTrigger].reset();
						chordKbState.reset();
					}
					learning++;
					selectChordNote(curTrigger,tnote,true);
					int newNote = tnote+transpose;
					if (mode==Global)
						newNote += tnote-root;
					else if (mode==Octave)
						newNote += 12 * (tnote%12);
					if (newNote < 128 && newNote >= 0) {
						output.addEvent(MidiMessage::noteOn(ch,newNote,v),sample);
						outputNote[ch][tnote]=newNote;
					}
				}
				else
				{
					int trigger = tnote;
					if (mode==Octave)
						trigger =  60 + tnote%12;
					else if (mode==Global)
						trigger = root;
					for (int n=0;n<128;n++)
					{
						if (progKbState[curProgram][trigger].isNoteOn(1,n)) {
							int newNote = n+transpose;
							if (mode==Global)
								newNote += tnote-root;
							else if (mode==Octave)
								newNote +=  12 * (tnote/12 - 60/12);
							if (chordNotePlaying[ch][newNote]) {
								ignoreNextNoteOff.add(newNote);
								playingChord[tnote].add(newNote);
							}
							else if (newNote < 128 && newNote >= 0) 
							{
								output.addEvent(MidiMessage::noteOn(ch,newNote,v),sample);
								playingChord[tnote].add(newNote);
								chordNotePlaying[ch][newNote]=true;
							}
						}
					}
					notePlaying[ch][tnote]=true;
					if (follow && mode!=Global)
						selectTrigger(trigger);
				}
			}
			else if (m.isNoteOff()) {
				const int ch = m.getChannel();
				const int note = m.getNoteNumber();
				if (learn)
				{
					learning--;
					if (outputNote[ch][note] < 128 && outputNote[ch][note] >= 0) {
						output.addEvent(MidiMessage::noteOff(ch,outputNote[ch][note]),sample);
						outputNote[ch][note]=-1;
					}
					if (learning<1)
						setParameterNotifyingHost(kLearnChord,0.f);
				}
				else
				{
					int numNotes = playingChord[note].size();
					if (numNotes==0) {
						if (outputNote[ch][note]!=-1) {
							output.addEvent(MidiMessage::noteOff(ch,outputNote[ch][note]),sample);
							outputNote[ch][note]=-1;
						}
					}
					else {
						for (int i = 0; i<numNotes; i++) {
							const int chordNote = playingChord[note][i];
							if (!ignoreNextNoteOff.contains(chordNote)) {
								output.addEvent(MidiMessage::noteOff(ch,chordNote),sample);
								chordNotePlaying[ch][chordNote]=false;
							}
							else
								ignoreNextNoteOff.removeValue(chordNote);
						}
						playingChord[note].clear();
					}
					notePlaying[ch][note]=false;
				}
			}
			else
				output.addEvent(m,sample);
		}
		else
			output.addEvent(m,sample);
	}

	midiMessages.clear();
	midiMessages = output;

    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
AudioProcessorEditor* MidiChords::createEditor()
{
    return new MidiChordsEditor (this);
}

//==============================================================================
void MidiChords::getStateInformation (MemoryBlock& destData)
{
	copySettingsToProgram(curProgram);
	programs->writeToStream(MemoryOutputStream(destData,false));
}

void MidiChords::getCurrentProgramStateInformation (MemoryBlock& destData)
{
	copySettingsToProgram(curProgram);
	programs->getChild(curProgram).writeToStream(MemoryOutputStream(destData,false));
}

void MidiChords::setStateInformation (const void* data, int sizeInBytes)
{
	ValueTree vt = ValueTree::readFromStream(MemoryInputStream(data,sizeInBytes,false));
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

void MidiChords::setCurrentProgramStateInformation (const void* data, int sizeInBytes)
{
	programs->removeChild(programs->getChild(curProgram),0);
	programs->addChild(ValueTree::readFromStream(MemoryInputStream(data,sizeInBytes,false)),curProgram,0);
	programs->getChild(curProgram).setProperty("progIndex",curProgram,0);
	init=true;
	setCurrentProgram(curProgram);
}

void MidiChords::selectTrigger(int index)
{
	if (mode==Octave)
		index = 60 + index%12;
	triggerKbState.noteOff(1,curTrigger);
	triggerKbState.noteOn(1,index,128);
	chordKbState.reset();
	for (int i=0;i<128;i++)
		if (progKbState[curProgram][index].isNoteOn(1,i)) chordKbState.noteOn(1,i,128);
	curTrigger = index;
	programs->set(curProgram,"lastTrigger",index);
	sendChangeMessage();
}

void MidiChords::selectChordNote(int index, int note, bool on)
{
	if (note>=0 && note<128)
	{
		if (on) {
			progKbState[curProgram][index].noteOn(1,note,128);
			if (index==curTrigger) chordKbState.noteOn(1,note,128);
			++numChordNotes[curProgram][index];
		}
		else {
			progKbState[curProgram][index].noteOff(1,note);
			if (index==curTrigger) chordKbState.noteOff(1,note);
			--numChordNotes[curProgram][index];
		}
		programs->setChordNote(curProgram,index,note,on);
		sendChangeMessage();
	}
}

void MidiChords::copySettingsToProgram(int index)
{
	programs->set(index,"Channel",channel);
	programs->set(index,"UsePC",usepc);
	programs->set(index,"FollowInput",follow);
    programs->set(index,"Name",getProgramName(index));
	programs->set(index,"lastUIHeight",lastUIHeight);
    programs->set(index,"lastUIWidth",lastUIWidth);
	programs->set(index,"lastTrigger",curTrigger);
	programs->set(index,"Transpose",transpose);
	programs->set(index,"Mode",mode);
	programs->set(index,"Root",root);
	programs->set(index,"Guess",guess);
	programs->set(index,"Flats",flats);

	for (int i=0;i<128;i++) {
		for (int n=0;n<128;n++)
		{
			programs->setChordNote(index,i,n,progKbState[index][i].isNoteOn(1,n));
		}
	}
}

void MidiChords::clearAllChords()
{
	for (int i=0;i<128;i++) {
		numChordNotes[curProgram][i]=0;
		progKbState[curProgram][i].reset();
		for (int n=0;n<128;n++)
		{
			programs->setChordNote(curProgram,i,n,false);
		}
	}
	chordKbState.reset();
	sendChangeMessage();
}

void MidiChords::resetAllChords() 
{
	for (int i=0;i<128;i++) {
		numChordNotes[curProgram][i]=0;
		progKbState[curProgram][i].reset();
		progKbState[curProgram][i].noteOn(1,i,128);
		for (int n=0;n<128;n++)
		{
			programs->setChordNote(curProgram,i,n,i==n);
		}
	}
	chordKbState.reset();
	chordKbState.noteOn(1,curTrigger,128);
	sendChangeMessage();
}

void MidiChords::clearChord(int trigger)
{
	numChordNotes[curProgram][trigger]=0;
	progKbState[curProgram][trigger].reset();
	for (int n=0;n<128;n++)
	{
		programs->setChordNote(curProgram,trigger,n,false);
	}
	if (trigger==curTrigger) 
	{
		chordKbState.reset();
		sendChangeMessage();
	}

}

void MidiChords::resetChord(int trigger)
{
	numChordNotes[curProgram][trigger]=0;
	progKbState[curProgram][trigger].reset();
	progKbState[curProgram][trigger].noteOn(1,trigger,128);
	for (int n=0;n<128;n++)
	{
		programs->setChordNote(curProgram,trigger,n,trigger==n);
	}
	if (trigger==curTrigger) 
	{
		chordKbState.reset();
		chordKbState.noteOn(1,curTrigger,128);
		sendChangeMessage();
	}
}

void MidiChords::transposeAll(bool up)
{
	chordKbState.reset();
	for (int i=0;i<128;i++)
	{
		bool oldState[128];
		for (int n=0;n<128;n++)
			oldState[n] = progKbState[curProgram][i].isNoteOn(1,n);
		progKbState[curProgram][i].reset();
		for (int n=0;n<128;n++)
		{
			if (oldState[n]) {
				if (up) 
				{
					progKbState[curProgram][i].noteOn(1,n+1,128);
					programs->setChordNote(curProgram,i,n+1,true);
					if (i==curTrigger) 
						chordKbState.noteOn(1,n+1,128);

				}
				else {
					progKbState[curProgram][i].noteOn(1,n-1,128);
					programs->setChordNote(curProgram,i,n-1,true);
					if (i==curTrigger) 
						chordKbState.noteOn(1,n-1,128);
				}
			}
			else {
				if (up) 
					programs->setChordNote(curProgram,i,n+1,false);
				else
					programs->setChordNote(curProgram,i,n-1,false);
			}
		}
	}
	sendChangeMessage();
}

void MidiChords::transposeChord(int trigger, bool up)
{
	bool oldState[128];
	for (int n=0;n<128;n++)
		oldState[n] = progKbState[curProgram][trigger].isNoteOn(1,n);
	progKbState[curProgram][trigger].reset();
	if (trigger==curTrigger) 
		chordKbState.reset();
	for (int n=0;n<128;n++)
	{
		if (oldState[n]) {
			if (up) 
			{
				progKbState[curProgram][trigger].noteOn(1,n+1,128);
				programs->setChordNote(curProgram,trigger,n+1,true);
				if (trigger==curTrigger) 
					chordKbState.noteOn(1,n+1,128);
			}
			else {
				progKbState[curProgram][trigger].noteOn(1,n-1,128);
				programs->setChordNote(curProgram,trigger,n-1,true);
				if (trigger==curTrigger) 
					chordKbState.noteOn(1,n-1,128);
			}
		}
		else {
			if (up) 
				programs->setChordNote(curProgram,trigger,n+1,false);
			else
				programs->setChordNote(curProgram,trigger,n-1,false);
		}
	}
	if (trigger==curTrigger) 
	sendChangeMessage();
}

void MidiChords::transposeCurrentChordByOctave(bool up)
{
	bool oldState[128];
	for (int n=0;n<128;n++)
		oldState[n] = progKbState[curProgram][curTrigger].isNoteOn(1,n);
	progKbState[curProgram][curTrigger].reset();
	chordKbState.reset();
	for (int n=0;n<128;n++)
	{
		if (oldState[n]) {
			if (up) 
			{
				progKbState[curProgram][curTrigger].noteOn(1,n+12,128);
				programs->setChordNote(curProgram,curTrigger,n+12,true);
				chordKbState.noteOn(1,n+12,128);
			}
			else {
				progKbState[curProgram][curTrigger].noteOn(1,n-12,128);
				programs->setChordNote(curProgram,curTrigger,n-12,true);
				chordKbState.noteOn(1,n-12,128);
			}
		}
		else {
			if (up) 
				programs->setChordNote(curProgram,curTrigger,n+12,false);
			else
				programs->setChordNote(curProgram,curTrigger,n-12,false);
		}
	}
	sendChangeMessage();
}


void MidiChords::savePreset(String name)
{
	String contents;
	for (int t=0;t<128;t++)
	{
		for (int n=0;n<128;n++)
		{
			bool used = false;
			String chordString;
			if (progKbState[curProgram][t].isNoteOn(1,n)) {
				chordString += " " + String(t-n);
				used = true;
			}
			if (used) 
				contents += String(n) + ":" + chordString + "\n";
		}
	}
	File chordFile(getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"mappings"+File::separatorString+name+".chords");

	FileChooser myChooser ("Save preset...",chordFile,"*.chords");

	if (myChooser.browseForFileToSave(true))
	{
		File file (myChooser.getResult());
		if (!file.hasFileExtension("chords")) file = file.withFileExtension("chords");

		file.create();
		file.replaceWithText(contents);
	}
}
