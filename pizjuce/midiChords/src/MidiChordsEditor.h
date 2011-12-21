/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  21 Dec 2011 8:20:57am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIDICHORDSEDITOR_MIDICHORDSEDITOR_E94B1310__
#define __JUCER_HEADER_MIDICHORDSEDITOR_MIDICHORDSEDITOR_E94B1310__

//[Headers]     -- You can add your own extra header files here --
#include "MidiChords.h"
#include "../../common/ChannelSlider.h"
#include "../../common/LookAndFeel.h"

class ChordsKeyboardComponent : public MidiKeyboardComponent
{
public:
	ChordsKeyboardComponent(MidiKeyboardState &state, MidiChords* ownerFilter)
		: MidiKeyboardComponent(state,MidiKeyboardComponent::horizontalKeyboard),
		owner(0)
	{
		owner = ownerFilter;
		s = &state;
		this->setMidiChannel(1);
		this->setLowestVisibleKey(36);
	}
	void drawBlackNote(int midiNoteNumber, Graphics& g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour& textColour)
	{
		MidiKeyboardComponent::drawBlackNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,textColour);
		Font f (jmin (12.0f, w * 0.9f));
		f.setHorizontalScale (0.8f);
		g.setFont (f);
		g.setColour (Colours::white);
		g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 4, Justification::centredBottom, 1);
	}
	void drawWhiteNote(int midiNoteNumber, Graphics& g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour& lineColour, const Colour& textColour)
	{
		MidiKeyboardComponent::drawWhiteNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,lineColour,textColour);
		Font f (jmin (12.0f, w * 0.9f));
		f.setHorizontalScale (0.8f);
		f.setBold (midiNoteNumber==60);
		g.setFont (f);
		g.setColour (textColour);
		g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 16, Justification::centredBottom, 1);
	}

private:
	MidiChords* owner;
    MidiKeyboardState* s;

	bool mouseDownOnKey(int midiNoteNumber, const MouseEvent &e) {
		if (s->isNoteOn(this->getMidiChannel(),midiNoteNumber)) {
			s->noteOff(this->getMidiChannel(),midiNoteNumber);
			owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,false);
		}
		else {
			s->noteOn(this->getMidiChannel(),midiNoteNumber,128);
			owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,true);
		}
		return false;
	}
};

class TriggerKeySelectorKeyboard : public MidiKeyboardComponent
{
public:
	TriggerKeySelectorKeyboard(MidiKeyboardState &state, MidiChords* ownerFilter)
		: MidiKeyboardComponent(state,MidiKeyboardComponent::horizontalKeyboard), owner(0)
	{
		s = &state;
		owner = ownerFilter;
		this->setMidiChannel(1);
		this->setLowestVisibleKey(36);
	}
	void drawBlackNote(int midiNoteNumber, Graphics& g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour& textColour)
	{
		MidiKeyboardComponent::drawBlackNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,textColour);
		if (roundToInt(owner->getParameter(kMode)*(numModes-1))!=Octave) {
			Font f (jmin (12.0f, w * 0.9f));
			f.setHorizontalScale (0.8f);
			g.setFont (f);
			g.setColour (Colours::white);
			g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 4, Justification::centredBottom, 1);
		}
	}
	void drawWhiteNote(int midiNoteNumber, Graphics& g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour& lineColour, const Colour& textColour)
	{
		if (roundToInt(owner->getParameter(kMode)*(numModes-1))==Octave)
			MidiKeyboardComponent::drawWhiteNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,lineColour,Colours::transparentBlack);
		else {
			if (roundToInt(owner->getParameter(kMode)*(numModes-1))==Global)
				MidiKeyboardComponent::drawWhiteNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,Colours::red,textColour);
			else
				MidiKeyboardComponent::drawWhiteNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,lineColour,textColour);
			Font f (jmin (12.0f, w * 0.9f));
			f.setHorizontalScale (0.8f);
			f.setBold (midiNoteNumber==60);
			g.setFont (f);
			g.setColour (textColour);
			g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 16, Justification::centredBottom, 1);
		}
	}

private:
    MidiKeyboardState* s;
	MidiChords* owner;

	bool mouseDownOnKey(int midiNoteNumber, const MouseEvent &e)
	{
		if (roundToInt(owner->getParameter(kMode)*(numModes-1))==Global)
			owner->setParameterNotifyingHost(kRoot,midiNoteNumber/127.f);
		else
			owner->selectTrigger(midiNoteNumber);
		return false;
	}
};

//[/Headers]

#include "../../common/PizButton.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidiChordsEditor  : public AudioProcessorEditor,
                          public ChangeListener,
                          public TextEditorListener,
                          public ButtonListener,
                          public SliderListener,
                          public LabelListener
{
public:
    //==============================================================================
    MidiChordsEditor (MidiChords* const ownerFilter);
    ~MidiChordsEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	friend class ChordsKeyboardComponent;
	friend class TriggerKeySelectorKeyboard;
    void textEditorTextChanged(TextEditor&);
    void textEditorReturnKeyPressed(TextEditor&);
    void textEditorEscapeKeyPressed(TextEditor&);
    void textEditorFocusLost(TextEditor&);
	void changeListenerCallback (ChangeBroadcaster* source);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void labelTextChanged (Label* labelThatHasChanged);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TooltipWindow tooltipWindow;
    void updateParametersFromFilter();
	String const getCurrentChordName();
	void listChordFiles(StringArray &list);
	void listPresetFiles(StringArray &list);
	void loadChord(String chorddef);
	void saveChord(String name);
	void loadPreset(String filename);

    MidiChords* getFilter() const throw()       { return (MidiChords*) getAudioProcessor(); }
	int mode;
    //[/UserVariables]

    //==============================================================================
    ToggleButton* toggleButton;
    Label* chordNameLabel;
    ChordsKeyboardComponent* chordKeyboard;
    TriggerKeySelectorKeyboard* triggerKeyboard;
    TextButton* chordLearnButton;
    TextButton* triggerLearnButton;
    ChannelSlider* channelSlider;
    Label* outputLabel;
    PizButton* pizButton;
    Label* triggerLabel;
    TextButton* clearChordButton;
    TextButton* resetChordButton;
    TextButton* clearAllButton;
    TextButton* resetAllButton;
    TextButton* transposeUpButton;
    TextButton* transposeDownButton;
    TextButton* transposeChordUpButton;
    TextButton* transposeChordDownButton;
    Slider* transposeSlider;
    Slider* velocitySlider;
    Slider* variationSlider;
    TextButton* normalButton;
    TextButton* octaveButton;
    TextButton* globalButton;
    ToggleButton* flatsButton;
    TextButton* transposeChordUpButton2;
    TextButton* transposeChordDownButton2;
    TextButton* chordMenuButton;
    Label* presetNameLabel;
    TextButton* presetMenuButton;
    TextEditor* textEditor;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MidiChordsEditor (const MidiChordsEditor&);
    const MidiChordsEditor& operator= (const MidiChordsEditor&);
};


#endif   // __JUCER_HEADER_MIDICHORDSEDITOR_MIDICHORDSEDITOR_E94B1310__
