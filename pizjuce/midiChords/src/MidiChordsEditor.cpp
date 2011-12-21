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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MidiChordsEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidiChordsEditor::MidiChordsEditor (MidiChords* const ownerFilter)
    : AudioProcessorEditor (ownerFilter),
      toggleButton (0),
      chordNameLabel (0),
      chordKeyboard (0),
      triggerKeyboard (0),
      chordLearnButton (0),
      triggerLearnButton (0),
      channelSlider (0),
      outputLabel (0),
      pizButton (0),
      triggerLabel (0),
      clearChordButton (0),
      resetChordButton (0),
      clearAllButton (0),
      resetAllButton (0),
      transposeUpButton (0),
      transposeDownButton (0),
      transposeChordUpButton (0),
      transposeChordDownButton (0),
      transposeSlider (0),
      velocitySlider (0),
      variationSlider (0),
      normalButton (0),
      octaveButton (0),
      globalButton (0),
      flatsButton (0),
      transposeChordUpButton2 (0),
      transposeChordDownButton2 (0),
      chordMenuButton (0),
      presetNameLabel (0),
      presetMenuButton (0),
      textEditor (0)
{
    addAndMakeVisible (toggleButton = new ToggleButton (L"new toggle button"));
    toggleButton->setButtonText (L"Guess chord name");
    toggleButton->addListener (this);

    addAndMakeVisible (chordNameLabel = new Label (L"new label",
                                                   L"chord name"));
    chordNameLabel->setFont (Font (15.0000f, Font::bold));
    chordNameLabel->setJustificationType (Justification::centred);
    chordNameLabel->setEditable (false, false, false);
    chordNameLabel->setColour (Label::backgroundColourId, Colour (0x279a3c3c));
    chordNameLabel->setColour (Label::outlineColourId, Colour (0xb3000000));
    chordNameLabel->setColour (TextEditor::textColourId, Colours::black);
    chordNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (chordKeyboard = new ChordsKeyboardComponent (ownerFilter->chordKbState, ownerFilter));

    addAndMakeVisible (triggerKeyboard = new TriggerKeySelectorKeyboard (ownerFilter->triggerKbState, ownerFilter));

    addAndMakeVisible (chordLearnButton = new TextButton (L"chordLearn"));
    chordLearnButton->setTooltip (L"Learn next input chord");
    chordLearnButton->setButtonText (L"Learn Chord");
    chordLearnButton->setConnectedEdges (Button::ConnectedOnBottom);
    chordLearnButton->addListener (this);

    addAndMakeVisible (triggerLearnButton = new TextButton (L"triggerLearn"));
    triggerLearnButton->setTooltip (L"When on, displayed trigger note follows input note");
    triggerLearnButton->setButtonText (L"Follow Input");
    triggerLearnButton->setConnectedEdges (Button::ConnectedOnBottom);
    triggerLearnButton->addListener (this);

    addAndMakeVisible (channelSlider = new ChannelSlider (L"channel"));
    channelSlider->setTooltip (L"Input/output channel");
    channelSlider->setRange (0, 16, 1);
    channelSlider->setSliderStyle (Slider::LinearBar);
    channelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    channelSlider->setColour (Slider::backgroundColourId, Colours::white);
    channelSlider->addListener (this);

    addAndMakeVisible (outputLabel = new Label (L"new label",
                                                L"Output"));
    outputLabel->setFont (Font (15.0000f, Font::plain));
    outputLabel->setJustificationType (Justification::centredRight);
    outputLabel->setEditable (false, false, false);
    outputLabel->setColour (Label::textColourId, Colours::white);
    outputLabel->setColour (TextEditor::textColourId, Colours::black);
    outputLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (pizButton = new PizButton());
    addAndMakeVisible (triggerLabel = new Label (L"new label",
                                                 L"Trigger Note"));
    triggerLabel->setFont (Font (15.0000f, Font::plain));
    triggerLabel->setJustificationType (Justification::centred);
    triggerLabel->setEditable (false, false, false);
    triggerLabel->setColour (Label::textColourId, Colours::white);
    triggerLabel->setColour (TextEditor::textColourId, Colours::black);
    triggerLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (clearChordButton = new TextButton (L"clear"));
    clearChordButton->setTooltip (L"Clear current chord");
    clearChordButton->setButtonText (L"Clear");
    clearChordButton->setConnectedEdges (Button::ConnectedOnRight | Button::ConnectedOnBottom);
    clearChordButton->addListener (this);

    addAndMakeVisible (resetChordButton = new TextButton (L"reset"));
    resetChordButton->setTooltip (L"Reset current chord to just the trigger note");
    resetChordButton->setButtonText (L"Reset");
    resetChordButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnBottom);
    resetChordButton->addListener (this);

    addAndMakeVisible (clearAllButton = new TextButton (L"clear"));
    clearAllButton->setButtonText (L"Clear All");
    clearAllButton->setConnectedEdges (Button::ConnectedOnRight);
    clearAllButton->addListener (this);

    addAndMakeVisible (resetAllButton = new TextButton (L"reset"));
    resetAllButton->setButtonText (L"Reset All");
    resetAllButton->setConnectedEdges (Button::ConnectedOnLeft);
    resetAllButton->addListener (this);

    addAndMakeVisible (transposeUpButton = new TextButton (L"transpose"));
    transposeUpButton->setButtonText (L"->");
    transposeUpButton->setConnectedEdges (Button::ConnectedOnLeft);
    transposeUpButton->addListener (this);

    addAndMakeVisible (transposeDownButton = new TextButton (L"transpose"));
    transposeDownButton->setButtonText (L"<-");
    transposeDownButton->setConnectedEdges (Button::ConnectedOnRight);
    transposeDownButton->addListener (this);

    addAndMakeVisible (transposeChordUpButton = new TextButton (L"transpose"));
    transposeChordUpButton->setTooltip (L"Shift chord up one semitone");
    transposeChordUpButton->setButtonText (L">");
    transposeChordUpButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnBottom);
    transposeChordUpButton->addListener (this);

    addAndMakeVisible (transposeChordDownButton = new TextButton (L"transpose"));
    transposeChordDownButton->setTooltip (L"Shift chord down one semitone");
    transposeChordDownButton->setButtonText (L"<");
    transposeChordDownButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnBottom);
    transposeChordDownButton->addListener (this);

    addAndMakeVisible (transposeSlider = new Slider (L"transpose"));
    transposeSlider->setTooltip (L"Transpose output by semitones");
    transposeSlider->setRange (-48, 48, 1);
    transposeSlider->setSliderStyle (Slider::LinearBar);
    transposeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    transposeSlider->setColour (Slider::backgroundColourId, Colours::white);
    transposeSlider->addListener (this);

    addAndMakeVisible (velocitySlider = new Slider (L"velocity"));
    velocitySlider->setRange (-10, 10, 0.1);
    velocitySlider->setSliderStyle (Slider::LinearBar);
    velocitySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    velocitySlider->addListener (this);

    addAndMakeVisible (variationSlider = new Slider (L"Variation"));
    variationSlider->setRange (0, 100, 0.1);
    variationSlider->setSliderStyle (Slider::LinearBar);
    variationSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    variationSlider->addListener (this);

    addAndMakeVisible (normalButton = new TextButton (L"new button"));
    normalButton->setTooltip (L"Full mode: a separate chord is defined for every input note");
    normalButton->setButtonText (L"Full");
    normalButton->setConnectedEdges (Button::ConnectedOnRight | Button::ConnectedOnTop);
    normalButton->setRadioGroupId (1);
    normalButton->addListener (this);

    addAndMakeVisible (octaveButton = new TextButton (L"new button"));
    octaveButton->setTooltip (L"Octave mode: 12 chords are defined which are transposed to every octave");
    octaveButton->setButtonText (L"Octave");
    octaveButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop);
    octaveButton->setRadioGroupId (1);
    octaveButton->addListener (this);

    addAndMakeVisible (globalButton = new TextButton (L"new button"));
    globalButton->setTooltip (L"Global mode: one defined chord is transposed relative to the root note");
    globalButton->setButtonText (L"Global");
    globalButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnTop);
    globalButton->setRadioGroupId (1);
    globalButton->addListener (this);

    addAndMakeVisible (flatsButton = new ToggleButton (L"new toggle button"));
    flatsButton->setButtonText (L"flats");
    flatsButton->addListener (this);

    addAndMakeVisible (transposeChordUpButton2 = new TextButton (L"transpose"));
    transposeChordUpButton2->setTooltip (L"Shift chord up one octave");
    transposeChordUpButton2->setButtonText (L">>");
    transposeChordUpButton2->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnBottom);
    transposeChordUpButton2->addListener (this);

    addAndMakeVisible (transposeChordDownButton2 = new TextButton (L"transpose"));
    transposeChordDownButton2->setTooltip (L"Shift chord down one octave");
    transposeChordDownButton2->setButtonText (L"<<");
    transposeChordDownButton2->setConnectedEdges (Button::ConnectedOnRight | Button::ConnectedOnBottom);
    transposeChordDownButton2->addListener (this);

    addAndMakeVisible (chordMenuButton = new TextButton (L"chordMenu"));
    chordMenuButton->setButtonText (L"Chords");
    chordMenuButton->setConnectedEdges (Button::ConnectedOnBottom);
    chordMenuButton->addListener (this);

    addAndMakeVisible (presetNameLabel = new Label (L"new label",
                                                    L"preset name"));
    presetNameLabel->setTooltip (L"Preset Name");
    presetNameLabel->setFont (Font (15.0000f, Font::bold));
    presetNameLabel->setJustificationType (Justification::centred);
    presetNameLabel->setEditable (true, true, false);
    presetNameLabel->setColour (Label::backgroundColourId, Colour (0x27a1b404));
    presetNameLabel->setColour (Label::outlineColourId, Colour (0xb3000000));
    presetNameLabel->setColour (TextEditor::textColourId, Colours::black);
    presetNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    presetNameLabel->addListener (this);

    addAndMakeVisible (presetMenuButton = new TextButton (L"presets"));
    presetMenuButton->setTooltip (L"Preset Menu");
    presetMenuButton->setButtonText (L">");
    presetMenuButton->setConnectedEdges (Button::ConnectedOnLeft);
    presetMenuButton->addListener (this);

    addAndMakeVisible (textEditor = new TextEditor (L"new text editor"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setColour (TextEditor::outlineColourId, Colours::black);
    textEditor->setText (String::empty);


    //[UserPreSize]
	this->setMouseClickGrabsKeyboardFocus(false);
	chordKeyboard->setMouseClickGrabsKeyboardFocus(false);
	triggerKeyboard->setMouseClickGrabsKeyboardFocus(false);
	chordLearnButton->setMouseClickGrabsKeyboardFocus(false);
	triggerLearnButton->setMouseClickGrabsKeyboardFocus(false);
	channelSlider->setMouseClickGrabsKeyboardFocus(false);
	outputLabel->setMouseClickGrabsKeyboardFocus(false);
	pizButton->setMouseClickGrabsKeyboardFocus(false);
	triggerLabel->setMouseClickGrabsKeyboardFocus(false);
	clearChordButton->setMouseClickGrabsKeyboardFocus(false);
	resetChordButton->setMouseClickGrabsKeyboardFocus(false);
	clearAllButton->setMouseClickGrabsKeyboardFocus(false);
	resetAllButton->setMouseClickGrabsKeyboardFocus(false);
	transposeUpButton->setMouseClickGrabsKeyboardFocus(false);
	transposeDownButton->setMouseClickGrabsKeyboardFocus(false);
	transposeChordUpButton->setMouseClickGrabsKeyboardFocus(false);
	transposeChordDownButton->setMouseClickGrabsKeyboardFocus(false);
	transposeSlider->setMouseClickGrabsKeyboardFocus(false);
	velocitySlider->setMouseClickGrabsKeyboardFocus(false);
	variationSlider->setMouseClickGrabsKeyboardFocus(false);
	normalButton->setMouseClickGrabsKeyboardFocus(false);
	octaveButton->setMouseClickGrabsKeyboardFocus(false);
	globalButton->setMouseClickGrabsKeyboardFocus(false);
	toggleButton->setMouseClickGrabsKeyboardFocus(false);
	chordNameLabel->setMouseClickGrabsKeyboardFocus(false);
	flatsButton->setMouseClickGrabsKeyboardFocus(false);
    chordMenuButton->setMouseClickGrabsKeyboardFocus(false);
    presetNameLabel->setMouseClickGrabsKeyboardFocus(false);
    presetMenuButton->setMouseClickGrabsKeyboardFocus(false);

	textEditor->addListener(this);
	textEditor->setTextToShowWhenEmpty("Add chord",Colours::grey);

	pizButton->addListener(this);
	pizButton->setTooltip("http://thepiz.org/plugins");

	velocitySlider->setVisible(false);
	variationSlider->setVisible(false);
	//transposeChordDownButton->setVisible(false);
	//transposeChordUpButton->setVisible(false);
	transposeDownButton->setVisible(false);
	transposeUpButton->setVisible(false);
	static NonShinyLookAndFeel Look;
	LookAndFeel::setDefaultLookAndFeel (&Look);
	mode = Normal;
    //[/UserPreSize]

    setSize (640, 400);


    //[Constructor] You can add your own custom stuff here..
	ownerFilter->addChangeListener(this);
	updateParametersFromFilter();
    //[/Constructor]
}

MidiChordsEditor::~MidiChordsEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	getFilter()->removeChangeListener(this);
    //[/Destructor_pre]

    deleteAndZero (toggleButton);
    deleteAndZero (chordNameLabel);
    deleteAndZero (chordKeyboard);
    deleteAndZero (triggerKeyboard);
    deleteAndZero (chordLearnButton);
    deleteAndZero (triggerLearnButton);
    deleteAndZero (channelSlider);
    deleteAndZero (outputLabel);
    deleteAndZero (pizButton);
    deleteAndZero (triggerLabel);
    deleteAndZero (clearChordButton);
    deleteAndZero (resetChordButton);
    deleteAndZero (clearAllButton);
    deleteAndZero (resetAllButton);
    deleteAndZero (transposeUpButton);
    deleteAndZero (transposeDownButton);
    deleteAndZero (transposeChordUpButton);
    deleteAndZero (transposeChordDownButton);
    deleteAndZero (transposeSlider);
    deleteAndZero (velocitySlider);
    deleteAndZero (variationSlider);
    deleteAndZero (normalButton);
    deleteAndZero (octaveButton);
    deleteAndZero (globalButton);
    deleteAndZero (flatsButton);
    deleteAndZero (transposeChordUpButton2);
    deleteAndZero (transposeChordDownButton2);
    deleteAndZero (chordMenuButton);
    deleteAndZero (presetNameLabel);
    deleteAndZero (presetMenuButton);
    deleteAndZero (textEditor);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiChordsEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffd8d8d8));

    g.setGradientFill (ColourGradient (Colours::white,
                                       61.0f, (float) (-31),
                                       Colour (0xe7e7e7),
                                       61.0f, 23.0f,
                                       false));
    g.fillRect (0, 0, 640, 100);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (568.0f, 64.0f, 66.0f, 106.0f, 10.0000f);

    g.setGradientFill (ColourGradient (Colours::black,
                                       0.0f, 336.0f,
                                       Colour (0xff828282),
                                       0.0f, 376.0f,
                                       false));
    g.fillRect (0, 360, proportionOfWidth (1.0000f), 40);

    g.setColour (Colours::black);
    g.setFont (Font (L"OCR A Std", 35.7000f, Font::plain));
    g.drawText (L"midiChords",
                85, 24, 248, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (L"Channel:",
                14, 307, 59, 24,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (L"OCR A Std", 15.0000f, Font::plain));
    g.drawText (L"Insert Piz Here\x2014>",
                85, 0, 248, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (L"Transpose:",
                440, 376, 80, 16,
                Justification::centredRight, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (L"Trigger Mode:",
                318, 306, 138, 24,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.fillRect (6, 213, getWidth() - 12, 93);

    g.setColour (Colours::black);
    g.fillRect (6, 85, getWidth() - 12, 93);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (540.0f, 190.0f, 94.0f, 106.0f, 10.0000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiChordsEditor::resized()
{
    toggleButton->setBounds (369, 40, 150, 24);
    chordNameLabel->setBounds (369, 60, 144, 26);
    chordKeyboard->setBounds (8, 87, getWidth() - 16, 89);
    triggerKeyboard->setBounds (8, 215, getWidth() - 16, 89);
    chordLearnButton->setBounds (6, 64, 80, 21);
    triggerLearnButton->setBounds (6, 192, 80, 21);
    channelSlider->setBounds (80, 312, 104, 16);
    outputLabel->setBounds (573, 64, 54, 24);
    pizButton->setBounds (8, 10, 74, 40);
    triggerLabel->setBounds (544, 191, 86, 24);
    clearChordButton->setBounds (174, 64, 40, 21);
    resetChordButton->setBounds (214, 64, 40, 21);
    clearAllButton->setBounds (8, 368, 64, 24);
    resetAllButton->setBounds (72, 368, 64, 24);
    transposeUpButton->setBounds (173, 368, 32, 24);
    transposeDownButton->setBounds (144, 368, 29, 24);
    transposeChordUpButton->setBounds (306, 64, 23, 21);
    transposeChordDownButton->setBounds (283, 64, 23, 21);
    transposeSlider->setBounds (528, 376, 104, 16);
    velocitySlider->setBounds (169, 338, 104, 16);
    variationSlider->setBounds (281, 338, 104, 16);
    normalButton->setBounds (442, 306, 64, 24);
    octaveButton->setBounds (506, 306, 64, 24);
    globalButton->setBounds (570, 306, 64, 24);
    flatsButton->setBounds (513, 64, 48, 24);
    transposeChordUpButton2->setBounds (329, 64, 25, 21);
    transposeChordDownButton2->setBounds (258, 64, 25, 21);
    chordMenuButton->setBounds (90, 64, 80, 21);
    presetNameLabel->setBounds (414, 9, 191, 26);
    presetMenuButton->setBounds (605, 9, 25, 26);
    textEditor->setBounds (82, -35, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidiChordsEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
		getFilter()->setParameterNotifyingHost(kGuess,toggleButton->getToggleState() ? 1.f : 0.f);
        //[/UserButtonCode_toggleButton]
    }
    else if (buttonThatWasClicked == chordLearnButton)
    {
        //[UserButtonCode_chordLearnButton] -- add your button handler code here..
		if (getFilter()->getParameter(kLearnChord)>0)
			getFilter()->setParameterNotifyingHost(kLearnChord,0.f);
		else
			getFilter()->setParameterNotifyingHost(kLearnChord,1.f);
        //[/UserButtonCode_chordLearnButton]
    }
    else if (buttonThatWasClicked == triggerLearnButton)
    {
        //[UserButtonCode_triggerLearnButton] -- add your button handler code here..
		if (getFilter()->getParameter(kFollowInput)>0)
			getFilter()->setParameterNotifyingHost(kFollowInput,0.f);
		else
			getFilter()->setParameterNotifyingHost(kFollowInput,1.f);
        //[/UserButtonCode_triggerLearnButton]
    }
    else if (buttonThatWasClicked == clearChordButton)
    {
        //[UserButtonCode_clearChordButton] -- add your button handler code here..
		getFilter()->clearChord(getFilter()->getCurrentTrigger());
        //[/UserButtonCode_clearChordButton]
    }
    else if (buttonThatWasClicked == resetChordButton)
    {
        //[UserButtonCode_resetChordButton] -- add your button handler code here..
		getFilter()->resetChord(getFilter()->getCurrentTrigger());
        //[/UserButtonCode_resetChordButton]
    }
    else if (buttonThatWasClicked == clearAllButton)
    {
        //[UserButtonCode_clearAllButton] -- add your button handler code here..
		getFilter()->clearAllChords();
        //[/UserButtonCode_clearAllButton]
    }
    else if (buttonThatWasClicked == resetAllButton)
    {
        //[UserButtonCode_resetAllButton] -- add your button handler code here..
		getFilter()->resetAllChords();
        //[/UserButtonCode_resetAllButton]
    }
    else if (buttonThatWasClicked == transposeUpButton)
    {
        //[UserButtonCode_transposeUpButton] -- add your button handler code here..
		getFilter()->transposeAll(true);
        //[/UserButtonCode_transposeUpButton]
    }
    else if (buttonThatWasClicked == transposeDownButton)
    {
        //[UserButtonCode_transposeDownButton] -- add your button handler code here..
		getFilter()->transposeAll(false);
        //[/UserButtonCode_transposeDownButton]
    }
    else if (buttonThatWasClicked == transposeChordUpButton)
    {
        //[UserButtonCode_transposeChordUpButton] -- add your button handler code here..
		getFilter()->transposeChord(getFilter()->getCurrentTrigger(),true);
        //[/UserButtonCode_transposeChordUpButton]
    }
    else if (buttonThatWasClicked == transposeChordDownButton)
    {
        //[UserButtonCode_transposeChordDownButton] -- add your button handler code here..
		getFilter()->transposeChord(getFilter()->getCurrentTrigger(),false);
        //[/UserButtonCode_transposeChordDownButton]
    }
    else if (buttonThatWasClicked == normalButton)
    {
        //[UserButtonCode_normalButton] -- add your button handler code here..
		getFilter()->setParameterNotifyingHost(kMode,((float)Normal)/(float)(numModes-1));
        //[/UserButtonCode_normalButton]
    }
    else if (buttonThatWasClicked == octaveButton)
    {
        //[UserButtonCode_octaveButton] -- add your button handler code here..
        getFilter()->setParameterNotifyingHost(kMode,((float)Octave)/(float)(numModes-1));
        //[/UserButtonCode_octaveButton]
    }
    else if (buttonThatWasClicked == globalButton)
    {
        //[UserButtonCode_globalButton] -- add your button handler code here..
        getFilter()->setParameterNotifyingHost(kMode,((float)Global)/(float)(numModes-1));
        //[/UserButtonCode_globalButton]
    }
    else if (buttonThatWasClicked == flatsButton)
    {
        //[UserButtonCode_flatsButton] -- add your button handler code here..
		getFilter()->setParameterNotifyingHost(kFlats,flatsButton->getToggleState() ? 1.f : 0.f);
        //[/UserButtonCode_flatsButton]
    }
    else if (buttonThatWasClicked == transposeChordUpButton2)
    {
        //[UserButtonCode_transposeChordUpButton2] -- add your button handler code here..
		getFilter()->transposeCurrentChordByOctave(true);
        //[/UserButtonCode_transposeChordUpButton2]
    }
    else if (buttonThatWasClicked == transposeChordDownButton2)
    {
        //[UserButtonCode_transposeChordDownButton2] -- add your button handler code here..
		getFilter()->transposeCurrentChordByOctave(false);
        //[/UserButtonCode_transposeChordDownButton2]
    }
    else if (buttonThatWasClicked == chordMenuButton)
    {
        //[UserButtonCode_chordMenuButton] -- add your button handler code here..
		StringArray list;
		listChordFiles(list);
		PopupMenu menu;
		menu.addCustomItem(-1,textEditor,150,24,false);
		for (int i=0;i<list.size();i++)
		{
			if (list[i].isNotEmpty())
			{
				if (list[i].startsWith("--"))
					menu.addSeparator();
				else if (list[i].startsWithChar('#'))
					menu.addSectionHeader(list[i].fromFirstOccurrenceOf("#",false,false));
				else
					menu.addItem(i+1,list[i].upToFirstOccurrenceOf(":",false,false));
			}
		}
		int result = menu.showAt(chordMenuButton);
		if (result!=0)
		{
			if (result>0)
				loadChord(list[result-1]);
		}
        //[/UserButtonCode_chordMenuButton]
    }
    else if (buttonThatWasClicked == presetMenuButton)
    {
        //[UserButtonCode_presetMenuButton] -- add your button handler code here..
		StringArray list;
		listPresetFiles(list);
		PopupMenu menu;
		menu.addItem(-1,"Save...");
		menu.addSeparator();
		for (int i=0;i<list.size();i++)
		{
			if (list[i].isNotEmpty())
			{
				menu.addItem(i+1,list[i]);
			}
		}
		int result = menu.showAt(presetMenuButton);
		if (result!=0)
		{
			if (result>0)
				loadPreset(list[result-1]);
			else if (result==-1)
				getFilter()->savePreset(presetNameLabel->getText());
		}
        //[/UserButtonCode_presetMenuButton]
    }

    //[UserbuttonClicked_Post]
    else if (buttonThatWasClicked == pizButton)
    {
		URL("http://thepiz.org/plugins").launchInDefaultBrowser();
	}
    //[/UserbuttonClicked_Post]
}

void MidiChordsEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == channelSlider)
    {
        //[UserSliderCode_channelSlider] -- add your slider handling code here..
		getFilter()->setParameterNotifyingHost(kChannel,(float)channelSlider->getValue()/16.f);
        //[/UserSliderCode_channelSlider]
    }
    else if (sliderThatWasMoved == transposeSlider)
    {
        //[UserSliderCode_transposeSlider] -- add your slider handling code here..
		getFilter()->setParameterNotifyingHost(kTranspose,(float)(transposeSlider->getValue()+48)/96.f);
        //[/UserSliderCode_transposeSlider]
    }
    else if (sliderThatWasMoved == velocitySlider)
    {
        //[UserSliderCode_velocitySlider] -- add your slider handling code here..
        //[/UserSliderCode_velocitySlider]
    }
    else if (sliderThatWasMoved == variationSlider)
    {
        //[UserSliderCode_variationSlider] -- add your slider handling code here..
        //[/UserSliderCode_variationSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MidiChordsEditor::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == presetNameLabel)
    {
        //[UserLabelCode_presetNameLabel] -- add your label text handling code here..
		getFilter()->changeProgramName(getFilter()->getCurrentProgram(),presetNameLabel->getText());
		getFilter()->updateHostDisplay();
        //[/UserLabelCode_presetNameLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MidiChordsEditor::changeListenerCallback (ChangeBroadcaster* source)
{
	if (source==getFilter())
		updateParametersFromFilter();
}

void MidiChordsEditor::updateParametersFromFilter()
{
	MidiChords* const filter = getFilter();
	const int newMode = roundToInt(filter->getParameter(kMode)*(numModes-1));

	chordLearnButton->setToggleState(filter->getParameter(kLearnChord)>0,false);
	triggerLearnButton->setToggleState(filter->getParameter(kFollowInput)>0,false);
	channelSlider->setValue(filter->getParameter(kChannel)*16.f,false);
	toggleButton->setToggleState(filter->getParameter(kGuess)>0,false);
	flatsButton->setToggleState(filter->getParameter(kFlats)>0,false);

	normalButton->setToggleState(newMode==Normal,false);
	octaveButton->setToggleState(newMode==Octave,false);
	globalButton->setToggleState(newMode==Global,false);

	chordNameLabel->setText(getCurrentChordName(),false);

	if (mode!=newMode)
	{
		if (newMode==Global) {
			triggerLabel->setText("Root Note",false);
			triggerKeyboard->setKeyWidth(16.f);
			triggerKeyboard->setAvailableRange(0,127);
			triggerKeyboard->setLowestVisibleKey(36);
		}
		else if (newMode==Octave) {
			triggerLabel->setText("Trigger Note",false);
			triggerKeyboard->setAvailableRange(60,71);
			triggerKeyboard->setKeyWidth((float)triggerKeyboard->getWidth()/7.f);
		}
		else {
			triggerLabel->setText("Trigger Note",false);
			triggerKeyboard->setKeyWidth(16.f);
			triggerKeyboard->setAvailableRange(0,127);
			triggerKeyboard->setLowestVisibleKey(36);
		}
		mode = newMode;
	}
	if (presetNameLabel->getText() != getFilter()->getProgramName(getFilter()->getCurrentProgram()))
		presetNameLabel->setText(getFilter()->getProgramName(getFilter()->getCurrentProgram()),false);

	repaint();
}

String const MidiChordsEditor::getCurrentChordName()
{
	if (getFilter()->getParameter(kGuess)==0.f)
		return String::empty;

	Array<int> chord;
	for (int n=0;n<128;n++)
	{
		if (getFilter()->chordKbState.isNoteOn(1,n))
			chord.add(n);
	}
	return getFirstRecognizedChord(chord,getFilter()->getParameter(kFlats)>0.f);
}

void MidiChordsEditor::listChordFiles(StringArray &list)
{
	File chordPath(getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"chords");
	Array<File> files;
	chordPath.findChildFiles(files,File::findFiles,true);
	for (int i=0;i<files.size();i++)
	{
		StringArray s;
		s.addLines(files[i].loadFileAsString());
		for (int line=0;line<s.size();line++)
		{
			if (!s[line].startsWithChar(';'))
			{
				list.add(s[line]);
			}
		}
	}
}

void MidiChordsEditor::listPresetFiles(StringArray &list)
{
	File mappingsPath(getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"mappings");
	Array<File> files;
	mappingsPath.findChildFiles(files,File::findFiles,true);
	for (int i=0;i<files.size();i++)
	{
		list.add(files[i].getFileNameWithoutExtension());
	}
}

void MidiChordsEditor::loadChord(String chorddef)
{
	const int t = getFilter()->getCurrentTrigger();
	getFilter()->clearChord(t);
	StringArray sa;
	sa.addTokens(chorddef.fromLastOccurrenceOf(":",false,true)," ",String::empty);
	for(int i=0;i<sa.size();i++)
	{
		getFilter()->selectChordNote(t,t+sa[i].getIntValue(),true);
	}
}

void MidiChordsEditor::loadPreset(String filename)
{
	String mappingsPath = getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"mappings";

	const int t = getFilter()->getCurrentTrigger();

	getFilter()->clearAllChords();

	StringArray lines;
	lines.addLines(File(mappingsPath+File::separatorString+filename+".chords").loadFileAsString());
	for(int ln=0;ln<lines.size();ln++)
	{
		if (!lines[ln].startsWithChar(';'))
		{
			int t = lines[ln].upToFirstOccurrenceOf(":",false,false).getIntValue();
			//getFilter()->clearChord(t);
			StringArray sa;
			sa.addTokens(lines[ln].fromLastOccurrenceOf(":",false,true)," ",String::empty);
			for(int i=0;i<sa.size();i++)
			{
				getFilter()->selectChordNote(t,t+sa[i].getIntValue(),true);
			}
		}
	}
	presetNameLabel->setText(filename,false);
	getFilter()->changeProgramName(getFilter()->getCurrentProgram(),filename);
	getFilter()->updateHostDisplay();
}

void MidiChordsEditor::saveChord(String name)
{
	const int t = getFilter()->getCurrentTrigger();
	String chordString = name + ":";
	for (int n=0;n<128;n++)
	{
		if (getFilter()->chordKbState.isNoteOn(1,n))
			chordString += " " + String(t-n);
	}
	File chordFile(getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"chords"+File::separatorString+"User.txt");
	chordFile.appendText(chordString+"\n");
}

void MidiChordsEditor::textEditorTextChanged(TextEditor &editor) {

}

void MidiChordsEditor::textEditorReturnKeyPressed(TextEditor &editor) {
	if (&editor==textEditor) {
		saveChord(textEditor->getText());
		PopupMenu::dismissAllActiveMenus();
		textEditor->clear();
	}
}

void MidiChordsEditor::textEditorEscapeKeyPressed(TextEditor &editor) {

}

void MidiChordsEditor::textEditorFocusLost(TextEditor &editor) {

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiChordsEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public ChangeListener, public TextEditorListener"
                 constructorParams="MidiChords* const ownerFilter" variableInitialisers="AudioProcessorEditor (ownerFilter)"
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="640" initialHeight="400">
  <BACKGROUND backgroundColour="ffd8d8d8">
    <RECT pos="0 0 640 100" fill="linear: 61 -31, 61 23, 0=ffffffff, 1=e7e7e7"
          hasStroke="0"/>
    <ROUNDRECT pos="568 64 66 106" cornerSize="10" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="0 360 100% 40" fill="linear: 0 336, 0 376, 0=ff000000, 1=ff828282"
          hasStroke="0"/>
    <TEXT pos="85 24 248 30" fill="solid: ff000000" hasStroke="0" text="midiChords"
          fontname="OCR A Std" fontsize="35.7" bold="0" italic="0" justification="36"/>
    <TEXT pos="14 307 59 24" fill="solid: ff000000" hasStroke="0" text="Channel:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="85 0 248 30" fill="solid: ff000000" hasStroke="0" text="Insert Piz Here&#8212;&gt;"
          fontname="OCR A Std" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="440 376 80 16" fill="solid: ff000000" hasStroke="0" text="Transpose:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="34"/>
    <TEXT pos="318 306 138 24" fill="solid: ff000000" hasStroke="0" text="Trigger Mode:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <RECT pos="6 213 12M 93" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="6 85 12M 93" fill="solid: ff000000" hasStroke="0"/>
    <ROUNDRECT pos="540 190 94 106" cornerSize="10" fill="solid: ff000000" hasStroke="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="58723bf0e9d70b49" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="369 40 150 24" buttonText="Guess chord name"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="84701c0c650fe2e" memberName="chordNameLabel"
         virtualName="" explicitFocusOrder="0" pos="369 60 144 26" bkgCol="279a3c3c"
         outlineCol="b3000000" edTextCol="ff000000" edBkgCol="0" labelText="chord name"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="36"/>
  <GENERICCOMPONENT name="" id="8e79ee27297830eb" memberName="chordKeyboard" virtualName=""
                    explicitFocusOrder="0" pos="8 87 16M 89" class="ChordsKeyboardComponent"
                    params="ownerFilter-&gt;chordKbState, ownerFilter"/>
  <GENERICCOMPONENT name="" id="c10b054d27a5aad0" memberName="triggerKeyboard" virtualName=""
                    explicitFocusOrder="0" pos="8 215 16M 89" class="TriggerKeySelectorKeyboard"
                    params="ownerFilter-&gt;triggerKbState, ownerFilter"/>
  <TEXTBUTTON name="chordLearn" id="79a1c0e1c1db8e39" memberName="chordLearnButton"
              virtualName="" explicitFocusOrder="0" pos="6 64 80 21" tooltip="Learn next input chord"
              buttonText="Learn Chord" connectedEdges="8" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="triggerLearn" id="99ff483968f1f65d" memberName="triggerLearnButton"
              virtualName="" explicitFocusOrder="0" pos="6 192 80 21" tooltip="When on, displayed trigger note follows input note"
              buttonText="Follow Input" connectedEdges="8" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="channel" id="c08fa2a5fc963392" memberName="channelSlider"
          virtualName="ChannelSlider" explicitFocusOrder="0" pos="80 312 104 16"
          tooltip="Input/output channel" bkgcol="ffffffff" min="0" max="16"
          int="1" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="53b1a84fa5d6099" memberName="outputLabel"
         virtualName="" explicitFocusOrder="0" pos="573 64 54 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Output" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <JUCERCOMP name="" id="bad9b853cca3ec4a" memberName="pizButton" virtualName=""
             explicitFocusOrder="0" pos="8 10 74 40" sourceFile="../../common/PizButton.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="9c19fc858eab3133" memberName="triggerLabel"
         virtualName="" explicitFocusOrder="0" pos="544 191 86 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Trigger Note" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="clear" id="729ec8a8b3111b3" memberName="clearChordButton"
              virtualName="" explicitFocusOrder="0" pos="174 64 40 21" tooltip="Clear current chord"
              buttonText="Clear" connectedEdges="10" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="706edfe98019c25d" memberName="resetChordButton"
              virtualName="" explicitFocusOrder="0" pos="214 64 40 21" tooltip="Reset current chord to just the trigger note"
              buttonText="Reset" connectedEdges="9" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="clear" id="ee6085145dcb39d2" memberName="clearAllButton"
              virtualName="" explicitFocusOrder="0" pos="8 368 64 24" buttonText="Clear All"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="d63567d98d87183b" memberName="resetAllButton"
              virtualName="" explicitFocusOrder="0" pos="72 368 64 24" buttonText="Reset All"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="f59df0e454cbaec8" memberName="transposeUpButton"
              virtualName="" explicitFocusOrder="0" pos="173 368 32 24" buttonText="-&gt;"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="3fe107b4cf733d10" memberName="transposeDownButton"
              virtualName="" explicitFocusOrder="0" pos="144 368 29 24" buttonText="&lt;-"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="b392a950edbb9665" memberName="transposeChordUpButton"
              virtualName="" explicitFocusOrder="0" pos="306 64 23 21" tooltip="Shift chord up one semitone"
              buttonText="&gt;" connectedEdges="11" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="330f12de98d7240c" memberName="transposeChordDownButton"
              virtualName="" explicitFocusOrder="0" pos="283 64 23 21" tooltip="Shift chord down one semitone"
              buttonText="&lt;" connectedEdges="11" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="transpose" id="e04428ac0ed97dc9" memberName="transposeSlider"
          virtualName="" explicitFocusOrder="0" pos="528 376 104 16" tooltip="Transpose output by semitones"
          bkgcol="ffffffff" min="-48" max="48" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocity" id="d173a9d6025fabc0" memberName="velocitySlider"
          virtualName="" explicitFocusOrder="0" pos="169 338 104 16" min="-10"
          max="10" int="0.1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Variation" id="992cbb80661db8e9" memberName="variationSlider"
          virtualName="" explicitFocusOrder="0" pos="281 338 104 16" min="0"
          max="100" int="0.1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="ea513687ce233abe" memberName="normalButton"
              virtualName="" explicitFocusOrder="0" pos="442 306 64 24" tooltip="Full mode: a separate chord is defined for every input note"
              buttonText="Full" connectedEdges="6" needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="new button" id="5d77a8c6aac13eed" memberName="octaveButton"
              virtualName="" explicitFocusOrder="0" pos="506 306 64 24" tooltip="Octave mode: 12 chords are defined which are transposed to every octave"
              buttonText="Octave" connectedEdges="7" needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="new button" id="4ec8d27f5555ec05" memberName="globalButton"
              virtualName="" explicitFocusOrder="0" pos="570 306 64 24" tooltip="Global mode: one defined chord is transposed relative to the root note"
              buttonText="Global" connectedEdges="5" needsCallback="1" radioGroupId="1"/>
  <TOGGLEBUTTON name="new toggle button" id="fb8f2d76e48f6291" memberName="flatsButton"
                virtualName="" explicitFocusOrder="0" pos="513 64 48 24" buttonText="flats"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="transpose" id="9c9792c55f67c803" memberName="transposeChordUpButton2"
              virtualName="" explicitFocusOrder="0" pos="329 64 25 21" tooltip="Shift chord up one octave"
              buttonText="&gt;&gt;" connectedEdges="9" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="1f97de47eccc1b3c" memberName="transposeChordDownButton2"
              virtualName="" explicitFocusOrder="0" pos="258 64 25 21" tooltip="Shift chord down one octave"
              buttonText="&lt;&lt;" connectedEdges="10" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="chordMenu" id="384cb651e909e8bd" memberName="chordMenuButton"
              virtualName="" explicitFocusOrder="0" pos="90 64 80 21" buttonText="Chords"
              connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="4ef6103879c88f80" memberName="presetNameLabel"
         virtualName="" explicitFocusOrder="0" pos="414 9 191 26" tooltip="Preset Name"
         bkgCol="27a1b404" outlineCol="b3000000" edTextCol="ff000000"
         edBkgCol="0" labelText="preset name" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <TEXTBUTTON name="presets" id="fdd2c5f83e8c75c9" memberName="presetMenuButton"
              virtualName="" explicitFocusOrder="0" pos="605 9 25 26" tooltip="Preset Menu"
              buttonText="&gt;" connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="fbf538174362a2ae" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="82 -35 150 24" outlinecol="ff000000"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
