/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  10 Jan 2012 4:47:43pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIDICHORDSEDITOR_MIDICHORDSEDITOR_2161ACA0__
#define __JUCER_HEADER_MIDICHORDSEDITOR_MIDICHORDSEDITOR_2161ACA0__

//[Headers]     -- You can add your own extra header files here --
#include "MidiChords.h"
#include "../../common/ChannelSlider.h"
#include "../../common/GuitarNeckComponent.h"
#include "../../common/LookAndFeel.h"

class ChordsGuitar : public GuitarNeckComponent
{
public:
	ChordsGuitar(MidiKeyboardState &state, MidiChords* ownerFilter)
		: GuitarNeckComponent(state),
		owner(0)
	{
		owner = ownerFilter;
		s = &state;
	}
private:
	MidiChords* owner;
    MidiKeyboardState* s;

	void mouseDraggedToKey(int fret, int string, const MouseEvent& e)
	{
	}

	bool mouseDownOnKey(int fret, int string, const MouseEvent &e) {
		FrettedNote n(fret,string);
		int midiNoteNumber = getNote(n);
		int oldNoteOnString = getNote(FrettedNote(getStringFret(string),string));
		if (e.mods.isPopupMenu())
		{
			PopupMenu m;
			m.addSectionHeader(getNoteName(midiNoteNumber,owner->bottomOctave)+ " (" + String(midiNoteNumber)+")");
			for (int i=1;i<=16;i++)
			{
				m.addItem(i,"Ch "+String(i),true,s->isNoteOn(i,midiNoteNumber));
			}
			int result = m.show();
			if (result!=0)
			{
				if (s->isNoteOn(result,midiNoteNumber)) {
					s->noteOff(result,midiNoteNumber);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,false,result);
				}
				else {
					s->noteOn(result,midiNoteNumber,127);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,true,result);
				}
			}
		}
		else
		{
			const int chordChan = 0;//roundToInt(owner->getParameter(kLearnChannel)*16.f);
			if (chordChan==0)
			{
				if (s->isNoteOn(string+1,midiNoteNumber)) {
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,false,string+1);
				}
				else {
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,true,string+1);
					if (oldNoteOnString>=0)
						owner->selectChordNote(owner->getCurrentTrigger(),oldNoteOnString,false,string+1);
				}
			}
			else {
				if (s->isNoteOn(chordChan,midiNoteNumber)) {
					//s->noteOff(this->getMidiChannel(),midiNoteNumber);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,false,chordChan);
				}
				else {
					//s->noteOn(this->getMidiChannel(),midiNoteNumber,1.f);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,true,chordChan);
					if (oldNoteOnString>=0)
						owner->selectChordNote(owner->getCurrentTrigger(),oldNoteOnString,false,chordChan);
				}
			}
		}
		return true;
	}
};

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
		Colour c (textColour);

		if (isDown)
			c = c.overlaidWith (findColour (keyDownOverlayColourId));
		else if (s->isNoteOnForChannels(0xffff,midiNoteNumber))
			c = c.overlaidWith(Colours::brown.withAlpha(0.4f));

		if (isOver)
			c = c.overlaidWith (findColour (mouseOverKeyOverlayColourId));

		g.setColour (c);
		g.fillRect (x, y, w, h);

		if (isDown)
		{
			g.setColour (textColour);
			g.drawRect (x, y, w, h);
		}
		else
		{
			const int xIndent = jmax (1, jmin (w, h) / 8);

			g.setColour (c.brighter());
			g.fillRect (x + xIndent, y, w - xIndent * 2, 7 * h / 8);
		}
		Font f (jmin (12.0f, w * 0.9f));
		f.setHorizontalScale (0.8f);
		g.setFont (f);
		g.setColour (Colours::white);
		g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 4, Justification::centredBottom, 1);
	}
	void drawWhiteNote(int midiNoteNumber, Graphics& g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour& lineColour, const Colour& textColour)
	{
		const int chordChan = roundToInt(owner->getParameter(kLearnChannel)*16.f);
		Colour c (Colours::transparentWhite);
		if (isDown)
			c = findColour (keyDownOverlayColourId);
		else if (s->isNoteOnForChannels(0xffff,midiNoteNumber))
			c = Colours::brown.withAlpha(0.4f);
		if (isOver)
			c = c.overlaidWith (findColour (mouseOverKeyOverlayColourId));

		g.setColour (c);
		g.fillRect (x, y, w, h);

		g.setColour (textColour);

		Font f (jmin (12.0f, getKeyWidth() * 0.9f));
		f.setHorizontalScale (0.8f);
		f.setBold (midiNoteNumber==60);
		g.setFont (f);
		Justification justification (Justification::centredBottom);

		g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 16, Justification::centredBottom, 1);

		const String text (getWhiteNoteText (midiNoteNumber));
		if (! text.isEmpty())
			g.drawFittedText (text, x + 2, y + 2, w - 4, h - 4, justification, 1);
		g.setColour (lineColour);
		g.fillRect (x, y, 1, h);

		if (midiNoteNumber == getRangeEnd())
		{
			g.fillRect (x + w, y, 1, h);
		}



		//MidiKeyboardComponent::drawWhiteNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,lineColour,textColour);
		//this->getMidiChannelsToDisplay()
		//Font f (jmin (12.0f, w * 0.9f));
		//f.setHorizontalScale (0.8f);
		//f.setBold (midiNoteNumber==60);
		//g.setFont (f);
		//g.setColour (textColour);
		//g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 16, Justification::centredBottom, 1);
	}

private:
	MidiChords* owner;
    MidiKeyboardState* s;

	bool mouseDownOnKey(int midiNoteNumber, const MouseEvent &e) {
		if (e.mods.isPopupMenu())
		{
			PopupMenu m;
			m.addSectionHeader(getNoteName(midiNoteNumber,owner->bottomOctave)+ " (" + String(midiNoteNumber)+")");
			for (int i=1;i<=16;i++)
			{
				m.addItem(i,"Ch "+String(i),true,s->isNoteOn(i,midiNoteNumber));
			}
			int result = m.show();
			if (result!=0)
			{
				if (s->isNoteOn(result,midiNoteNumber)) {
					s->noteOff(result,midiNoteNumber);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,false,result);
				}
				else {
					s->noteOn(result,midiNoteNumber,127);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,true,result);
				}
			}
		}
		else
		{
			const int chordChan = roundToInt(owner->getParameter(kLearnChannel)*16.f);
			if (chordChan==0)
			{
				if (s->isNoteOnForChannels(0xffff,midiNoteNumber))
				{
					for (int c=1;c<=16;c++)
					{
						if (s->isNoteOn(c,midiNoteNumber))
							owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,false,c);
					}
				}
				else
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,true,1);
			}
			else {
				if (s->isNoteOn(chordChan,midiNoteNumber)) {
					//s->noteOff(this->getMidiChannel(),midiNoteNumber);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,false,chordChan);
				}
				else {
					//s->noteOn(this->getMidiChannel(),midiNoteNumber,1.f);
					owner->selectChordNote(owner->getCurrentTrigger(),midiNoteNumber,true,chordChan);
				}
			}
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
		const int mode = roundToInt(owner->getParameter(kMode)*(numModes-1));
		Colour c (textColour);

		if (isDown) {
			c = c.overlaidWith (findColour (keyDownOverlayColourId));
		}

		if (isOver)
			c = c.overlaidWith (findColour (mouseOverKeyOverlayColourId));

		if (mode==Octave) {
			int n=midiNoteNumber%12;
			while (n<128) {
				if (owner->isTriggerNotePlaying(n))
					c = c.overlaidWith (Colours::green.withAlpha(0.6f));
				n += 12;
			}
		}
		else {
			if (owner->isTriggerNotePlaying(midiNoteNumber))
				c = c.overlaidWith (Colours::green.withAlpha(0.6f));
		}

		g.setColour (c);
		g.fillRect (x, y, w, h);

		if (isDown)
		{
			g.setColour (textColour);
			g.drawRect (x, y, w, h);
		}
		else
		{
			const int xIndent = jmax (1, jmin (w, h) / 8);

			g.setColour (c.brighter());
			g.fillRect (x + xIndent, y, w - xIndent * 2, 7 * h / 8);
		}
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
		const int mode = roundToInt(owner->getParameter(kMode)*(numModes-1));
		Colour c (Colours::transparentWhite);

		if (isDown)
			c = findColour (keyDownOverlayColourId);
		if (isOver)
			c = c.overlaidWith (findColour (mouseOverKeyOverlayColourId));
		if (mode==Octave) {
			int n=midiNoteNumber%12;
			while (n<128) {
				if (owner->isTriggerNotePlaying(n))
					c = c.overlaidWith (Colours::green.withAlpha(0.6f));
				n += 12;
			}
		}
		else {
			if (owner->isTriggerNotePlaying(midiNoteNumber))
				c = c.overlaidWith (Colours::green.withAlpha(0.6f));
		}

		g.setColour (c);
		g.fillRect (x, y, w, h);

		if (mode!=Octave) {

			g.setColour (textColour);

			Font f (jmin (12.0f, getKeyWidth() * 0.9f));
			f.setHorizontalScale (0.8f);
			f.setBold (midiNoteNumber==60);
			g.setFont (f);
			Justification justification (Justification::centredBottom);

			g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 16, Justification::centredBottom, 1);

			const String text (getWhiteNoteText (midiNoteNumber));
			if (! text.isEmpty())
				g.drawFittedText (text, x + 2, y + 2, w - 4, h - 4, justification, 1);
		}

		if (mode==Global)
			g.setColour (Colours::red);
		else
			g.setColour (lineColour);

		g.fillRect (x, y, 1, h);

		if (midiNoteNumber == getRangeEnd())
		{
			g.fillRect (x + w, y, 1, h);
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
                          public FileDragAndDropTarget,
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
    bool isInterestedInFileDrag (const StringArray& files);
    void filesDropped (const StringArray& filenames, int mouseX, int mouseY);
    void mouseDown (const MouseEvent& e);
    void mouseUp (const MouseEvent& e);
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
	void listPresetFiles(Array<File> &list);
	void loadChord(String chorddef);
	void saveChord(String name);
	void loadPreset(File file);
	void chordFromString(String chordString);

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
    TextButton* copyButton;
    TextButton* pasteButton;
    TextButton* previewButton;
    Label* chordEditor;
    ToggleButton* pcButton;
    TextButton* nextButton;
    TextButton* prevButton;
    Label* triggerNoteLabel;
    ChannelSlider* learnChanSlider;
    Label* demoLabel;
    ChordsGuitar* guitar;
    Label* versionLabel;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MidiChordsEditor (const MidiChordsEditor&);
    const MidiChordsEditor& operator= (const MidiChordsEditor&);
};


#endif   // __JUCER_HEADER_MIDICHORDSEDITOR_MIDICHORDSEDITOR_2161ACA0__
