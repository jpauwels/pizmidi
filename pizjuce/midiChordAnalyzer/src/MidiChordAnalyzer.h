#ifndef MidiChordAnalyzerPLUGINFILTER_H
#define MidiChordAnalyzerPLUGINFILTER_H

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../common/PizAudioProcessor.h"
#include "../../common/midistuff.h"
#include "../../common/ChordFunctions.h"
#include "../../common/key.h"

enum parameters {
    kChannel, 
	kFlats,

    numParams,
	numProgs = 1
};


class MidiChordAnalyzerPrograms : ValueTree {
public:
	friend class MidiChordAnalyzer;
	MidiChordAnalyzerPrograms ();
	~MidiChordAnalyzerPrograms () {};

	void set(int prog, const var::identifier &name, const var &newValue)
	{
		this->getChild(prog).setProperty(name,newValue,0);
	}

	const var get(int prog, const var::identifier &name)
	{
		return this->getChild(prog).getProperty(name);
	}

	MidiChordAnalyzerPrograms(ValueTree& tree)
	{
		this->getChild(0).getParent() = tree.createCopy();
	}
};

//==============================================================================
class MidiChordAnalyzer  : public PizAudioProcessor,
                    public ChangeBroadcaster
{
public:
    //==============================================================================
    MidiChordAnalyzer();
    ~MidiChordAnalyzer();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

	void processBlock (AudioSampleBuffer& buffer,
                       MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();

    //==============================================================================
    const String getName() const;
	bool hasEditor() const {return true;}

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

	bool acceptsMidi() const {return true;}
    bool producesMidi() const {return true;}

    //==============================================================================
    int getNumPrograms()                                        { return numProgs; }
    int getCurrentProgram()                                     { return curProgram; }
    void setCurrentProgram (int index);
    const String getProgramName (int index)                     { return programs->get(index,"Name"); }
    void changeProgramName (int index, const String& newName)   { programs->set(index,"Name",newName); }
	void copySettingsToProgram(int index);
	
    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    void getCurrentProgramStateInformation (MemoryBlock& destData);
    void setCurrentProgramStateInformation (const void* data, int sizeInBytes);

    //==============================================================================
	MidiKeyboardState chordKbState;
	//String getCurrentChordName();
	int lastUIWidth, lastUIHeight;
    //==============================================================================
    juce_UseDebuggingNewOperator

private:
	MidiChordAnalyzerPrograms* programs;
	int curProgram;
	int curTrigger;

	bool init;

    int channel;
	bool flats;
	AudioPlayHead::CurrentPositionInfo lastPosInfo;
};

#endif
