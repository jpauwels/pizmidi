#ifndef MIDIPADSPLUGINFILTER_H
#define MIDIPADSPLUGINFILTER_H

#include "../../common/PizAudioProcessor.h"

#define midiScaler (0.007874016f)

enum parameters{
    kVelOffset,
    kCCOffset,
    kChIn,
    kChOut,
    kUseTrigger,
    kUseVel,
    kThru,
    kSendAft,
    kMono,
    kNoteOnTrig,
    kNumGlobalParams,
    numPads = 128,
    xpos = kNumGlobalParams,
    ypos = xpos+numPads,
    kNumParams = kNumGlobalParams + 2*numPads,
	numPrograms = 32
};

enum layoutNames {
	onepad,
	fourpads,
	foursliders,
	tenpads,
	twelvepads,
	sixteenpads,
	sixteensliders,
	sixtyfourpads,
	hexagonpads,
	mixerpads,
	arrangeit28,
	arrangeit51,
	arrangeit39,
	arrangeit48,
	arrangeit64,
	arrangeit55,
	numLayouts
};

class PadLayouts : public ValueTree {
public:
	PadLayouts () : ValueTree("PadLayouts") {};
	~PadLayouts () {};
	static void setPadLayout(ValueTree& tree, float x, float y, float w, float h)
	{
		tree.setProperty("x",x,0);
		tree.setProperty("y",y,0);
		tree.setProperty("w",w,0);
		tree.setProperty("h",h,0);
	}
	void setPadVisible(int prog, int pad, bool visibility)
	{
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("visible",visibility,0);
	}
};

class MidiPadsPrograms : ValueTree {	
friend class midiPads;
public:
	MidiPadsPrograms ();
	~MidiPadsPrograms () {};
	void set(int prog, const var::identifier &name, const var &newValue)
	{
		this->getChild(prog).getChildWithName("GlobalValues").setProperty(name,newValue,0);
	}
	const var get(int prog, const var::identifier &name)
	{
		return this->getChild(prog).getChildWithName("GlobalValues").getProperty(name);
	}
	void setForPad(int prog, int pad, const var::identifier &name, const var &newValue)
	{
		this->getChild(prog).getChild(pad).setProperty(name,newValue,0);
	}
	void setPadLayout(int prog, int pad, float x, float y, float w, float h)
	{
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("x",x,0);
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("y",y,0);
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("w",w,0);
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("h",h,0);
	}
	void setPadPosition(int prog, int pad, float x, float y)
	{
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("x",x,0);
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("y",y,0);
	}
	void setPadSize(int prog, int pad, float w, float h)
	{
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("w",w,0);
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("h",h,0);
	}
	void setPadVisible(int prog, int pad, bool visibility)
	{
		this->getChild(prog).getChildWithName("Layout").getChild(pad).setProperty("visible",visibility,0);
	}
	bool getPadVisible(int prog, int pad)
	{
		return this->getChild(prog).getChildWithName("Layout").getChild(pad).getProperty("visible");
	}
	Rectangle<float> getPadBounds(int prog, int pad)
	{
		return Rectangle<float>(getChild(prog).getChildWithName("Layout").getChild(pad).getProperty("x"),
								getChild(prog).getChildWithName("Layout").getChild(pad).getProperty("y"),
								getChild(prog).getChildWithName("Layout").getChild(pad).getProperty("w"),
								getChild(prog).getChildWithName("Layout").getChild(pad).getProperty("h"));
	}
	const var getForPad(int prog, int pad, const var::identifier &name)
	{
		return this->getChild(prog).getChild(pad).getProperty(name);
	}

	const var getForPad(int prog, int pad, const var::identifier &name, const var& defaultValue)
	{
		return this->getChild(prog).getChild(pad).getProperty(name,defaultValue);
	}

	MidiPadsPrograms(ValueTree& tree)
	{
		this->getChild(0).getParent() = tree.createCopy();
	}

private:
	float x[numPrograms][numPads];
	float y[numPrograms][numPads];
};


//==============================================================================
class midiPads  : public PizAudioProcessor,
                  public ChangeBroadcaster
{
public:
    //==============================================================================
    midiPads();
    ~midiPads();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

	void processBlock (AudioSampleBuffer& buffer,
                                     MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();

    //==============================================================================
#include "JucePluginCharacteristics.h"
    const String getName() const {return JucePlugin_Name;}
    bool acceptsMidi() const {
#if JucePlugin_WantsMidiInput 
        return true;
#else   
        return false;
#endif
    }
    bool producesMidi() const {
#if JucePlugin_ProducesMidiOutput
        return true;
#else 
        return false;
#endif
    }

	bool hasEditor() const {return true;}

    int getNumParameters()    { return kNumParams; }

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;


    //==============================================================================
#if ONEPROGRAM
    int getNumPrograms()      { return 1; }
#else
    int getNumPrograms()      { return numPrograms; }
#endif
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);
	void copySettingsToProgram(int index);

    //==============================================================================
    void getCurrentProgramStateInformation (MemoryBlock& destData);
    void setCurrentProgramStateInformation (const void* data, int sizeInBytes);
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
	void saveXmlPatch(int index, File file);
	void saveXmlBank(File file);
	bool loadXmlPatch(int index, File file);
	bool loadXmlBank(File file);
	bool loadFxp(File file);
	bool loadFxb(File file);
	void loadDefaultPrograms();

	Rectangle<int> getPadBounds(int index);
	void setPadPosition(int index, float x, float y);
	void setPadSize(int index, float w, float h);

	String getGlobalParamValueName(int index)
	{
		switch(index)
		{
		case kVelOffset:  return "VelOffset";
		case kCCOffset:	  return "CCOffset";
		case kChIn:		  return "ChIn";
		case kChOut:	  return "ChOut";
		case kUseTrigger: return "UseTrigger";
		case kUseVel:	  return "UseVel";
		case kThru:		  return "Thru";
		case kSendAft:	  return "SendAft";
		case kMono:		  return "Mono";
		case kNoteOnTrig: return "NoteOnTrig";
		default:	      return String::empty;
		}
	}

	bool isPadVisible(int index);
	void setPadVisible(int index, bool visibility);
	void setLayout(int prog, int layoutIndex)
	{
		int index = programs->getChild(prog).indexOf(programs->getChild(prog).getChildWithName("Layout"));
		programs->getChild(prog).removeChild(index,0); 
		programs->getChild(prog).addChild(layouts->getChild(layoutIndex).createCopy(),index,0);
	}
	void loadXmlLayout(File file);
	void saveXmlLayout(File file);
	void copyPadSettings(int source, int dest);
	void setProperty(int pad, const var::identifier &name, const var &newValue)
	{
		programs->setForPad(curProgram,pad,name,newValue);
	}
	const var getProperty(int pad, const var::identifier &name, const var defaultReturnValue=0)
	{
		return programs->getForPad(curProgram,pad,name,defaultReturnValue);
	}

    //==============================================================================
    int lastUIWidth, lastUIHeight;

    int Ydata1[numPads]; 
    int Ycc[numPads];
    int Ytype[numPads];
    int Ydata2[numPads]; 
    int Yoff[numPads];
    int trigger[numPads];
    int Xcc[numPads];
    int Xoff[numPads];
    bool SendOff[numPads];
    bool UseX[numPads];
    bool UseY[numPads];
    bool UseYCC[numPads];
    bool UseXPB[numPads];
    bool toggle[numPads];

    float midilisten[numPads];
    float send[numPads];
    float sendoff[numPads];
    float bghue;
    float bgsat;
    float bgbri;
    float contrast;
    String icon[numPads];
    String text[numPads];
    Colour padcolor[numPads];
    bool buttondown[numPads];
    bool isplaying[128];
    int squares;
    bool showdots[numPads];
    bool showvalues[numPads];
    bool editmode;
    bool usemouseup;
    bool hex;
    bool triggered[numPads];
    bool togglestate[numPads];
    int lastx[numPads];
    int lasty[numPads];
    float roundness[numPads];
	float iconsize[numPads];
    bool trig;
    bool dotmoved[numPads];
    int lastxccvalue[numPads];
    int lastyccvalue[numPads];
	bool centeredText[numPads];
	String pluginPath, layoutPath, presetPath, bankPath, iconPath;

    //==============================================================================
    juce_UseDebuggingNewOperator



private:
    float param[kNumParams];
    int triggervel;

    MidiPadsPrograms* programs;
	PadLayouts* layouts;
	void fillLayouts();
    int curProgram;
    
    bool init;
};



#endif
