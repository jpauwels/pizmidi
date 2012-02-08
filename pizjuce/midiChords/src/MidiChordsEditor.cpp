/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  31 Jan 2012 8:42:55am

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
      textEditor (0),
      copyButton (0),
      pasteButton (0),
      previewButton (0),
      chordEditor (0),
      pcButton (0),
      nextButton (0),
      prevButton (0),
      triggerNoteLabel (0),
      learnChanSlider (0),
      demoLabel (0),
      guitar (0),
      versionLabel (0),
      transposeInputButton (0),
      toAllChannelsButton (0),
      infoButton (0),
      specialMenuButton (0),
      outputChannelSlider (0),
      applyChannelButton (0),
      label (0),
      label2 (0),
      viewButton (0),
      setupButton (0),
      infoBox (0)
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
    chordLearnButton->setButtonText (L"Learn");
    chordLearnButton->setConnectedEdges (Button::ConnectedOnBottom);
    chordLearnButton->addListener (this);

    addAndMakeVisible (triggerLearnButton = new TextButton (L"triggerLearn"));
    triggerLearnButton->setTooltip (L"When on, displayed trigger note follows input note");
    triggerLearnButton->setButtonText (L"Follow Input");
    triggerLearnButton->setConnectedEdges (Button::ConnectedOnBottom);
    triggerLearnButton->addListener (this);

    addAndMakeVisible (channelSlider = new ChannelSlider (L"channel"));
    channelSlider->setTooltip (L"Trigger channel");
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
                                                 L"Trigger Note:"));
    triggerLabel->setFont (Font (15.0000f, Font::plain));
    triggerLabel->setJustificationType (Justification::centredRight);
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
    transposeSlider->setRange (-12, 12, 1);
    transposeSlider->setSliderStyle (Slider::LinearBar);
    transposeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    transposeSlider->setColour (Slider::backgroundColourId, Colours::white);
    transposeSlider->addListener (this);

    addAndMakeVisible (velocitySlider = new Slider (L"velocity"));
    velocitySlider->setTooltip (L"Velocity for \"Play Chord\" button");
    velocitySlider->setRange (1, 127, 1);
    velocitySlider->setSliderStyle (Slider::RotaryVerticalDrag);
    velocitySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    velocitySlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f000000));
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
    chordMenuButton->setButtonText (L"Menu");
    chordMenuButton->setConnectedEdges (Button::ConnectedOnBottom);
    chordMenuButton->addListener (this);

    addAndMakeVisible (presetNameLabel = new Label (L"new label",
                                                    L"preset name"));
    presetNameLabel->setTooltip (L"Preset Name (double-click to edit)");
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

    addAndMakeVisible (copyButton = new TextButton (L"copy"));
    copyButton->setButtonText (L"Copy");
    copyButton->setConnectedEdges (Button::ConnectedOnRight | Button::ConnectedOnTop);
    copyButton->addListener (this);

    addAndMakeVisible (pasteButton = new TextButton (L"paste"));
    pasteButton->setButtonText (L"Paste");
    pasteButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnTop);
    pasteButton->addListener (this);

    addAndMakeVisible (previewButton = new TextButton (L"play"));
    previewButton->setTooltip (L"Plays currently displayed chord");
    previewButton->setButtonText (L"Play Chord");
    previewButton->setColour (TextButton::buttonColourId, Colour (0xff7ca17c));

    addAndMakeVisible (chordEditor = new Label (L"new label",
                                                L"chord"));
    chordEditor->setTooltip (L"Double-click to type a chord");
    chordEditor->setFont (Font (15.0000f, Font::plain));
    chordEditor->setJustificationType (Justification::centred);
    chordEditor->setEditable (false, true, false);
    chordEditor->setColour (Label::backgroundColourId, Colours::white);
    chordEditor->setColour (Label::outlineColourId, Colour (0xb3000000));
    chordEditor->setColour (TextEditor::textColourId, Colours::black);
    chordEditor->setColour (TextEditor::backgroundColourId, Colour (0x0));
    chordEditor->addListener (this);

    addAndMakeVisible (pcButton = new ToggleButton (L"new toggle button"));
    pcButton->setTooltip (L"Change program when receiving MIDI Program Change");
    pcButton->setButtonText (L"Use Program Change");
    pcButton->addListener (this);

    addAndMakeVisible (nextButton = new TextButton (L"next"));
    nextButton->setTooltip (L"Select next higher trigger note");
    nextButton->setButtonText (L">");
    nextButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnBottom);
    nextButton->addListener (this);

    addAndMakeVisible (prevButton = new TextButton (L"prev"));
    prevButton->setTooltip (L"Select previous trigger note");
    prevButton->setButtonText (L"<");
    prevButton->setConnectedEdges (Button::ConnectedOnRight | Button::ConnectedOnBottom);
    prevButton->addListener (this);

    addAndMakeVisible (triggerNoteLabel = new Label (L"new label",
                                                     L"G8 (127)"));
    triggerNoteLabel->setTooltip (L"Currently displayed trigger note (double-click to edit)");
    triggerNoteLabel->setFont (Font (15.0000f, Font::bold));
    triggerNoteLabel->setJustificationType (Justification::centredLeft);
    triggerNoteLabel->setEditable (false, true, false);
    triggerNoteLabel->setColour (Label::textColourId, Colours::white);
    triggerNoteLabel->setColour (TextEditor::textColourId, Colours::black);
    triggerNoteLabel->setColour (TextEditor::backgroundColourId, Colours::white);
    triggerNoteLabel->addListener (this);

    addAndMakeVisible (learnChanSlider = new ChannelSlider (L"channel"));
    learnChanSlider->setTooltip (L"Chord Input Channel, used for Learn and left-click entering notes");
    learnChanSlider->setRange (0, 16, 1);
    learnChanSlider->setSliderStyle (Slider::LinearBar);
    learnChanSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    learnChanSlider->setColour (Slider::backgroundColourId, Colours::white);
    learnChanSlider->addListener (this);

    addAndMakeVisible (demoLabel = new Label (L"new label",
                                              L"UNREGISTERED\nDEMO VERSION"));
    demoLabel->setFont (Font (L"OCR A Extended", 10.0000f, Font::plain));
    demoLabel->setJustificationType (Justification::centredRight);
    demoLabel->setEditable (false, false, false);
    demoLabel->setColour (TextEditor::textColourId, Colours::black);
    demoLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (guitar = new ChordsGuitar (ownerFilter->chordKbState, ownerFilter));
    guitar->setName (L"new component");

    addAndMakeVisible (versionLabel = new Label (L"new label",
                                                 L"99.99.99"));
    versionLabel->setFont (Font (12.0000f, Font::plain));
    versionLabel->setJustificationType (Justification::centredLeft);
    versionLabel->setEditable (false, false, false);
    versionLabel->setColour (TextEditor::textColourId, Colours::black);
    versionLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (transposeInputButton = new ToggleButton (L"new toggle button"));
    transposeInputButton->setTooltip (L"When checked, incoming trigger notes are transposed by the opposite of the \"Transpose\" slider.");
    transposeInputButton->setButtonText (L"Also Transpose Input");
    transposeInputButton->addListener (this);

    addAndMakeVisible (toAllChannelsButton = new ToggleButton (L"new toggle button"));
    toAllChannelsButton->setTooltip (L"When checked, CCs (and other control messages) are sent to all MIDI channels. Otherwise they are passed through on the original channel.");
    toAllChannelsButton->setButtonText (L"CCs to All Channels");
    toAllChannelsButton->addListener (this);

    addAndMakeVisible (infoButton = new TextButton (L"new button"));
    infoButton->setButtonText (L"?");
    infoButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnTop);
    infoButton->addListener (this);

    addAndMakeVisible (specialMenuButton = new TextButton (L"new button"));
    specialMenuButton->setButtonText (L"Global Functions...");
    specialMenuButton->addListener (this);

    addAndMakeVisible (outputChannelSlider = new ChannelSlider (L"channel"));
    outputChannelSlider->setTooltip (L"Output channel (\"Multi\" is as saved, otherwise overrides chord\'s saved channel)");
    outputChannelSlider->setRange (0, 16, 1);
    outputChannelSlider->setSliderStyle (Slider::LinearBar);
    outputChannelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    outputChannelSlider->setColour (Slider::backgroundColourId, Colours::white);
    outputChannelSlider->addListener (this);

    addAndMakeVisible (applyChannelButton = new TextButton (L"new button"));
    applyChannelButton->setTooltip (L"Applies input channel to selected chord");
    applyChannelButton->setButtonText (L"Apply");
    applyChannelButton->setConnectedEdges (Button::ConnectedOnLeft);
    applyChannelButton->addListener (this);

    addAndMakeVisible (label = new Label (L"new label",
                                          L"Out Channel"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (L"new label",
                                           L"Transpose"));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (viewButton = new TextButton (L"view"));
    viewButton->setTooltip (L"Switch between keyboard & guitar views");
    viewButton->setButtonText (L"View");
    viewButton->setConnectedEdges (Button::ConnectedOnTop);
    viewButton->addListener (this);

    addAndMakeVisible (setupButton = new TextButton (L"new button"));
    setupButton->setButtonText (L"Setup");
    setupButton->setConnectedEdges (Button::ConnectedOnTop);
    setupButton->addListener (this);

    addAndMakeVisible (infoBox = new TextEditor (L"new text editor"));
    infoBox->setMultiLine (true);
    infoBox->setReturnKeyStartsNewLine (false);
    infoBox->setReadOnly (true);
    infoBox->setScrollbarsShown (true);
    infoBox->setCaretVisible (false);
    infoBox->setPopupMenuEnabled (true);
    infoBox->setColour (TextEditor::backgroundColourId, Colour (0xf2ffffff));
    infoBox->setColour (TextEditor::outlineColourId, Colours::black);
    infoBox->setColour (TextEditor::shadowColourId, Colour (0x38000000));
    infoBox->setText (String::empty);


    //[UserPreSize]

    fretsSlider = new FretsSlider (L"new slider");
    fretsSlider->setRange (5, maxFrets, 1);
    fretsSlider->setSliderStyle (Slider::LinearHorizontal);
    fretsSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    fretsSlider->addListener (this);
	fretsSlider->setMouseClickGrabsKeyboardFocus(false);

    stringsSlider = new StringsSlider (L"new slider");
    stringsSlider->setRange (1, maxStrings, 1);
    stringsSlider->setSliderStyle (Slider::LinearHorizontal);
    stringsSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    stringsSlider->addListener (this);
	stringsSlider->setMouseClickGrabsKeyboardFocus(false);

	for (int i=0;i<maxStrings;i++) {
		stringSlider[i]= new NoteSlider (L"new slider");
		stringSlider[i]->setRange (-1, 127, 1);
		stringSlider[i]->setSliderStyle (Slider::LinearHorizontal);
		stringSlider[i]->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
		stringSlider[i]->addListener (this);
		stringSlider[i]->setBottomOctave(ownerFilter->bottomOctave);
		stringSlider[i]->setMouseClickGrabsKeyboardFocus(false);
	}

	this->setMouseClickGrabsKeyboardFocus(false);
	chordKeyboard->setMouseClickGrabsKeyboardFocus(false);
	triggerKeyboard->setMouseClickGrabsKeyboardFocus(false);
	chordLearnButton->setMouseClickGrabsKeyboardFocus(false);
	triggerLearnButton->setMouseClickGrabsKeyboardFocus(false);
	channelSlider->setMouseClickGrabsKeyboardFocus(false);
	learnChanSlider->setMouseClickGrabsKeyboardFocus(false);
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
	toAllChannelsButton->setMouseClickGrabsKeyboardFocus(false);
	specialMenuButton->setMouseClickGrabsKeyboardFocus(false);
	applyChannelButton->setMouseClickGrabsKeyboardFocus(false);
	outputChannelSlider->setMouseClickGrabsKeyboardFocus(false);
	label->setMouseClickGrabsKeyboardFocus(false);
	label2->setMouseClickGrabsKeyboardFocus(false);
	guitar->setMouseClickGrabsKeyboardFocus(false);
	setupButton->setMouseClickGrabsKeyboardFocus(false);

	guitar->setMouseCursor(MouseCursor::PointingHandCursor);
	chordKeyboard->setMouseCursor(MouseCursor::PointingHandCursor);
	triggerKeyboard->setMouseCursor(MouseCursor::PointingHandCursor);

	//channelSlider->setAllText("Any");
	learnChanSlider->setAllText("All");
	outputChannelSlider->setAllText("Multi");
	textEditor->addListener(this);
	textEditor->setTextToShowWhenEmpty("Add chord",Colours::grey);
	pizButton->addListener(this);
	pizButton->setTooltip("http://thepiz.org/plugins");
	previewButton->addMouseListener(this,false);
	velocitySlider->setPopupDisplayEnabled(true,this);
	velocitySlider->setDoubleClickReturnValue(true,100);
	triggerKeyboard->addMouseListener(this,false);

	variationSlider->setVisible(false);
	transposeDownButton->setVisible(false);
	transposeUpButton->setVisible(false);
	guitar->setVisible(false);

	File chordPath(getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"mappings");
	browser = new FileBrowserComponent(FileBrowserComponent::openMode|FileBrowserComponent::useTreeView|FileBrowserComponent::canSelectFiles,
			chordPath,&fileFilter,0);
	browser->addListener(this);

	Font const defaultFont = infoBox->getFont();
	infoBox->setVisible(false);
	infoBox->setFont(Font(18.f,Font::bold));
	infoBox->insertTextAtCaret("Insert Piz Here-> midiChords v." + String(JucePlugin_VersionString) + "\n\n");
	infoBox->setFont(defaultFont.boldened());
	infoBox->insertTextAtCaret("== Host Info ==\n");
	infoBox->setFont(defaultFont);
	infoBox->insertTextAtCaret(getFilter()->hostInfo + "\n\n");
	infoBox->setFont(defaultFont.boldened());
	infoBox->insertTextAtCaret("== Documentation ==\n");
	infoBox->setFont(defaultFont);
	infoBox->insertTextAtCaret(File(getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"readme.txt").loadFileAsString());

	const int middleC = getFilter()->getBottomOctave()+5;
	chordKeyboard->setOctaveForMiddleC(middleC);
	triggerKeyboard->setOctaveForMiddleC(middleC);
	guitar->setOctaveForMiddleC(middleC);

	static NonShinyLookAndFeel Look;
	LookAndFeel::setDefaultLookAndFeel (&Look);

	mode = Normal;
    //[/UserPreSize]

    setSize (640, 400);


    //[Constructor] You can add your own custom stuff here..
	versionLabel->setText(JucePlugin_VersionString,false);
	ownerFilter->addChangeListener(this);
	if (!ownerFilter->demo)
		demoLabel->setVisible(false);
	updateParametersFromFilter();
    //[/Constructor]
}

MidiChordsEditor::~MidiChordsEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	getFilter()->removeChangeListener(this);

	deleteAndZero (browser);
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
    deleteAndZero (copyButton);
    deleteAndZero (pasteButton);
    deleteAndZero (previewButton);
    deleteAndZero (chordEditor);
    deleteAndZero (pcButton);
    deleteAndZero (nextButton);
    deleteAndZero (prevButton);
    deleteAndZero (triggerNoteLabel);
    deleteAndZero (learnChanSlider);
    deleteAndZero (demoLabel);
    deleteAndZero (guitar);
    deleteAndZero (versionLabel);
    deleteAndZero (transposeInputButton);
    deleteAndZero (toAllChannelsButton);
    deleteAndZero (infoButton);
    deleteAndZero (specialMenuButton);
    deleteAndZero (outputChannelSlider);
    deleteAndZero (applyChannelButton);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (viewButton);
    deleteAndZero (setupButton);
    deleteAndZero (infoBox);


    //[Destructor]. You can add your own custom destruction code here..
    deleteAndZero (fretsSlider);
    deleteAndZero (stringsSlider);
	for (int i=0;i<maxStrings;i++)
		deleteAndZero (stringSlider[i]);
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
    g.fillRoundedRectangle (568.0f, 76.0f, 66.0f, 106.0f, 10.0000f);

    g.setGradientFill (ColourGradient (Colours::black,
                                       0.0f, 331.0f,
                                       Colour (0xff828282),
                                       0.0f, 360.0f,
                                       false));
    g.fillRect (0, 348, proportionOfWidth (1.0000f), 52);

    g.setColour (Colours::black);
    g.setFont (Font (L"OCR A Std", 35.7000f, Font::plain));
    g.drawText (L"midiChords",
                110, 24, 248, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (L"Trigger Channel:",
                14, 319, 103, 24,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (L"OCR A Std", 15.0000f, Font::plain));
    g.drawText (L"Insert Piz Here\x2014>",
                110, 0, 248, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (L"Trigger Mode:",
                318, 318, 138, 24,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.fillRect (6, 225, getWidth() - 12, 93);

    g.setColour (Colours::black);
    g.fillRect (6, 97, getWidth() - 12, 93);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (462.0f, 202.0f, 172.0f, 36.0f, 10.0000f);

    g.setGradientFill (ColourGradient (Colour (0xff666666),
                                       248.0f, 183.0f,
                                       Colour (0xffbfbfbf),
                                       248.0f, 215.0f,
                                       false));
    g.fillRoundedRectangle (250.0f, 195.0f, 173.0f, 26.0f, 12.0000f);

    g.setColour (Colours::black);
    g.setFont (Font (10.7000f, Font::plain));
    g.drawText (L"Input Channel",
                6, 46, 71, 8,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiChordsEditor::resized()
{
    toggleButton->setBounds (372, 50, 150, 24);
    chordNameLabel->setBounds (375, 72, 144, 26);
    chordKeyboard->setBounds (8, 99, getWidth() - 16, 89);
    triggerKeyboard->setBounds (8, 227, getWidth() - 16, 89);
    chordLearnButton->setBounds (6, 76, 45, 21);
    triggerLearnButton->setBounds (6, 204, 80, 21);
    channelSlider->setBounds (123, 323, 66, 16);
    outputLabel->setBounds (573, 76, 54, 24);
    pizButton->setBounds (38, 3, 74, 40);
    triggerLabel->setBounds (464, 203, 97, 24);
    clearChordButton->setBounds (291, 76, 40, 21);
    resetChordButton->setBounds (331, 76, 40, 21);
    clearAllButton->setBounds (9, 408, 64, 24);
    resetAllButton->setBounds (73, 408, 64, 24);
    transposeUpButton->setBounds (173, 404, 32, 24);
    transposeDownButton->setBounds (144, 404, 29, 24);
    transposeChordUpButton->setBounds (159, 76, 23, 21);
    transposeChordDownButton->setBounds (136, 76, 23, 21);
    transposeSlider->setBounds (446, 374, 66, 16);
    velocitySlider->setBounds (397, 197, 22, 22);
    variationSlider->setBounds (334, 411, 104, 16);
    normalButton->setBounds (442, 318, 64, 24);
    octaveButton->setBounds (506, 318, 64, 24);
    globalButton->setBounds (570, 318, 64, 24);
    flatsButton->setBounds (519, 76, 48, 24);
    transposeChordUpButton2->setBounds (182, 76, 25, 21);
    transposeChordDownButton2->setBounds (111, 76, 25, 21);
    chordMenuButton->setBounds (55, 76, 52, 21);
    presetNameLabel->setBounds (414, 12, 191, 26);
    presetMenuButton->setBounds (605, 12, 25, 26);
    textEditor->setBounds (82, -35, 150, 24);
    copyButton->setBounds (211, 73, 38, 21);
    pasteButton->setBounds (249, 73, 38, 21);
    previewButton->setBounds (251, 196, 143, 24);
    chordEditor->setBounds (178, 54, 144, 20);
    pcButton->setBounds (167, 375, 160, 20);
    nextButton->setBounds (113, 204, 23, 21);
    prevButton->setBounds (90, 204, 23, 21);
    triggerNoteLabel->setBounds (558, 203, 73, 24);
    learnChanSlider->setBounds (6, 56, 38, 16);
    demoLabel->setBounds (334, 5, 81, 24);
    guitar->setBounds (8, 99, getWidth() - 16, 89);
    versionLabel->setBounds (352, 28, 58, 24);
    transposeInputButton->setBounds (513, 372, 91, 21);
    toAllChannelsButton->setBounds (167, 354, 149, 20);
    infoButton->setBounds (-1, -1, 19, 18);
    specialMenuButton->setBounds (9, 362, 140, 24);
    outputChannelSlider->setBounds (348, 374, 66, 16);
    applyChannelButton->setBounds (44, 56, 32, 16);
    label->setBounds (335, 359, 91, 13);
    label2->setBounds (432, 359, 91, 13);
    viewButton->setBounds (151, 190, 41, 21);
    setupButton->setBounds (195, 190, 45, 21);
    infoBox->setBounds (proportionOfWidth (0.5000f) - ((500) / 2), proportionOfHeight (0.5000f) - ((300) / 2), 500, 300);
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
			if (result>0) {
				loadChord(list[result-1]);
			}
		}
        //[/UserButtonCode_chordMenuButton]
    }
    else if (buttonThatWasClicked == presetMenuButton)
    {
        //[UserButtonCode_presetMenuButton] -- add your button handler code here..
		//Array<File> list;
		//listPresetFiles(list);
		browser->refresh();

		PopupMenu menu;
		menu.addItem(-1,"Save...");
		menu.addSeparator();
		menu.addCustomItem(0,browser,250,300,false);
		//for (int i=0;i<list.size();i++)
		//{
		//	if (list[i].existsAsFile())
		//	{
		//		menu.addItem(i+1,list[i].getFileNameWithoutExtension());
		//	}
		//}
		int result = menu.showAt(presetMenuButton);
		if (result!=0)
		{
			//if (result>0)
			//	loadPreset(list[result-1]);
			if (result==-1)
				getFilter()->savePreset(presetNameLabel->getText());
		}
        //[/UserButtonCode_presetMenuButton]
    }
    else if (buttonThatWasClicked == copyButton)
    {
        //[UserButtonCode_copyButton] -- add your button handler code here..
		const int t = getFilter()->getCurrentTrigger();
		String chordString = String(t) + ":";
		for (int n=0;n<128;n++)
		{
			for (int c=1;c<=16;c++)
			{
				if (getFilter()->chordKbState.isNoteOn(c,n))
					chordString += " " + String(n-t)+"."+String(c);
			}
		}
		SystemClipboard::copyTextToClipboard(chordString);
        //[/UserButtonCode_copyButton]
    }
    else if (buttonThatWasClicked == pasteButton)
    {
        //[UserButtonCode_pasteButton] -- add your button handler code here..
		chordFromString(SystemClipboard::getTextFromClipboard());
        //[/UserButtonCode_pasteButton]
    }
    else if (buttonThatWasClicked == pcButton)
    {
        //[UserButtonCode_pcButton] -- add your button handler code here..
		getFilter()->setParameterNotifyingHost(kUseProgCh,pcButton->getToggleState() ? 1.f : 0.f);
        //[/UserButtonCode_pcButton]
    }
    else if (buttonThatWasClicked == nextButton)
    {
        //[UserButtonCode_nextButton] -- add your button handler code here..
		getFilter()->selectTrigger(getFilter()->getCurrentTrigger()+1);
        //[/UserButtonCode_nextButton]
    }
    else if (buttonThatWasClicked == prevButton)
    {
        //[UserButtonCode_prevButton] -- add your button handler code here..
		getFilter()->selectTrigger(getFilter()->getCurrentTrigger()-1);
        //[/UserButtonCode_prevButton]
    }
    else if (buttonThatWasClicked == transposeInputButton)
    {
        //[UserButtonCode_transposeInputButton] -- add your button handler code here..
		getFilter()->setParameterNotifyingHost(kInputTranspose,transposeInputButton->getToggleState() ? 1.f : 0.f);
        //[/UserButtonCode_transposeInputButton]
    }
    else if (buttonThatWasClicked == toAllChannelsButton)
    {
        //[UserButtonCode_toAllChannelsButton] -- add your button handler code here..
		getFilter()->setParameterNotifyingHost(kToAllChannels,toAllChannelsButton->getToggleState() ? 1.f : 0.f);
        //[/UserButtonCode_toAllChannelsButton]
    }
    else if (buttonThatWasClicked == infoButton)
    {
        //[UserButtonCode_infoButton] -- add your button handler code here..
		infoBox->moveCaretToTop(false);
		if (infoButton->getToggleState())
			Desktop::getInstance().getAnimator().fadeOut(infoBox,150);
		else
			Desktop::getInstance().getAnimator().fadeIn(infoBox,100);
		//infoBox->setVisible(!infoBox->isVisible());
		infoButton->setToggleState(!infoButton->getToggleState(),false);
        //[/UserButtonCode_infoButton]
    }
    else if (buttonThatWasClicked == specialMenuButton)
    {
        //[UserButtonCode_specialMenuButton] -- add your button handler code here..
		PopupMenu m;
		m.addItem(1,"Clear all chords");
		m.addItem(2,"Reset all chords");
		m.addItem(3,"Copy to all triggers (absolute)");
		m.addItem(4,"Copy to all triggers (relative)");
		m.addItem(5,"Transpose all up one semitone");
		m.addItem(6,"Transpose all down one semitone");
		int result = m.showAt(specialMenuButton);
		if (result!=0)
		{
			if (result==1)
				getFilter()->clearAllChords();
			else if (result==2)
				getFilter()->resetAllChords();
			else if (result==3)
				getFilter()->copyChordToAllTriggers(true);
			else if (result==4)
				getFilter()->copyChordToAllTriggers(false);
			else if (result==5)
				getFilter()->transposeAll(true);
			else if (result==6)
				getFilter()->transposeAll(false);
		}
        //[/UserButtonCode_specialMenuButton]
    }
    else if (buttonThatWasClicked == applyChannelButton)
    {
        //[UserButtonCode_applyChannelButton] -- add your button handler code here..
		getFilter()->applyChannelToChord();
        //[/UserButtonCode_applyChannelButton]
    }
    else if (buttonThatWasClicked == viewButton)
    {
        //[UserButtonCode_viewButton] -- add your button handler code here..
		setupButton->setEnabled(!guitar->isVisible());
		guitar->setVisible(!guitar->isVisible());
		getFilter()->setGuitarView(guitar->isVisible());
        //[/UserButtonCode_viewButton]
    }
    else if (buttonThatWasClicked == setupButton)
    {
        //[UserButtonCode_setupButton] -- add your button handler code here..
		//getFilter()->fillGuitarPresetList();
		PopupMenu m, custom;
		for (int i=0;i<getFilter()->guitarPresets.size();i++)
			m.addItem(i+1,getFilter()->guitarPresets[i].guitarName,true,isGuitarPreset(i));

		m.addSeparator();
		custom.addCustomItem(-1,fretsSlider,150,18,false);
		custom.addCustomItem(-1,stringsSlider,150,18,false);
		for (int i=0;i<maxStrings;i++)
			custom.addCustomItem(-1,stringSlider[i],150,18,false);
		m.addSubMenu("Customize",custom);

		int result = m.showAt(setupButton);
		if (result>0)
			setUpGuitar(result-1);
        //[/UserButtonCode_setupButton]
    }

    //[UserbuttonClicked_Post]
    else if (buttonThatWasClicked == pizButton)
    {
		URL("http://thepiz.org/plugins/?p=midiChords").launchInDefaultBrowser();
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
		getFilter()->setParameterNotifyingHost(kVelocity,(float)(velocitySlider->getValue()-1)/126.f);
        //[/UserSliderCode_velocitySlider]
    }
    else if (sliderThatWasMoved == variationSlider)
    {
        //[UserSliderCode_variationSlider] -- add your slider handling code here..
        //[/UserSliderCode_variationSlider]
    }
    else if (sliderThatWasMoved == learnChanSlider)
    {
        //[UserSliderCode_learnChanSlider] -- add your slider handling code here..
		getFilter()->setParameterNotifyingHost(kLearnChannel,(float)learnChanSlider->getValue()/16.f);
        //[/UserSliderCode_learnChanSlider]
    }
    else if (sliderThatWasMoved == outputChannelSlider)
    {
        //[UserSliderCode_outputChannelSlider] -- add your slider handling code here..
		getFilter()->setParameterNotifyingHost(kOutChannel,(float)outputChannelSlider->getValue()/16.f);
        //[/UserSliderCode_outputChannelSlider]
    }

    //[UsersliderValueChanged_Post]
    else if (sliderThatWasMoved == fretsSlider)
    {
		getFilter()->setNumFrets(roundToInt(fretsSlider->getValue()),true);
		guitar->setNumFrets(roundToInt(fretsSlider->getValue()));
    }
    else if (sliderThatWasMoved == stringsSlider)
    {
		const int s = roundToInt(stringsSlider->getValue());
		getFilter()->setNumStrings(s,true);
		guitar->setNumStrings(s);
		for (int i=0;i<maxStrings;i++)
		{
			stringSlider[i]->setEnabled(i<s);
		}
    }
    else if (sliderThatWasMoved == stringSlider[0])
    {
		getFilter()->setStringValue(0,roundToInt(stringSlider[0]->getValue()),true);
		guitar->setStringNote(0,roundToInt(stringSlider[0]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[1])
    {
		getFilter()->setStringValue(1,roundToInt(stringSlider[1]->getValue()),true);
		guitar->setStringNote(1,roundToInt(stringSlider[1]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[2])
    {
		getFilter()->setStringValue(2,roundToInt(stringSlider[2]->getValue()),true);
		guitar->setStringNote(2,roundToInt(stringSlider[2]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[3])
    {
		getFilter()->setStringValue(3,roundToInt(stringSlider[3]->getValue()),true);
		guitar->setStringNote(3,roundToInt(stringSlider[3]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[4])
    {
		getFilter()->setStringValue(4,roundToInt(stringSlider[4]->getValue()),true);
		guitar->setStringNote(4,roundToInt(stringSlider[4]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[5])
    {
		getFilter()->setStringValue(5,roundToInt(stringSlider[5]->getValue()),true);
		guitar->setStringNote(5,roundToInt(stringSlider[5]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[6])
    {
		getFilter()->setStringValue(6,roundToInt(stringSlider[6]->getValue()),true);
		guitar->setStringNote(6,roundToInt(stringSlider[6]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[7])
    {
		getFilter()->setStringValue(7,roundToInt(stringSlider[7]->getValue()),true);
		guitar->setStringNote(7,roundToInt(stringSlider[7]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[8])
    {
		getFilter()->setStringValue(8,roundToInt(stringSlider[8]->getValue()),true);
		guitar->setStringNote(8,roundToInt(stringSlider[8]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[9])
    {
		getFilter()->setStringValue(9,roundToInt(stringSlider[9]->getValue()),true);
		guitar->setStringNote(9,roundToInt(stringSlider[9]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[10])
    {
		getFilter()->setStringValue(10,roundToInt(stringSlider[10]->getValue()),true);
		guitar->setStringNote(10,roundToInt(stringSlider[10]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[11])
    {
		getFilter()->setStringValue(11,roundToInt(stringSlider[11]->getValue()),true);
		guitar->setStringNote(11,roundToInt(stringSlider[11]->getValue()));
    }
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
    else if (labelThatHasChanged == chordEditor)
    {
        //[UserLabelCode_chordEditor] -- add your label text handling code here..
		chordFromString(chordEditor->getText());
        //[/UserLabelCode_chordEditor]
    }
    else if (labelThatHasChanged == triggerNoteLabel)
    {
        //[UserLabelCode_triggerNoteLabel] -- add your label text handling code here..
		getFilter()->selectTrigger(triggerNoteLabel->getText().getIntValue());
        //[/UserLabelCode_triggerNoteLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MidiChordsEditor::mouseDown(const MouseEvent& e)
{
	if (e.eventComponent==previewButton && !e.mods.isPopupMenu())
		getFilter()->playCurrentChord(true);
}

void MidiChordsEditor::mouseDoubleClick (const MouseEvent& e)
{
	if (e.eventComponent==triggerKeyboard && (e.mods.isShiftDown() || e.mods.isPopupMenu()))
	{
		for (int i=0;i<128;i++)
			getFilter()->setNoteBypassed(i,false);
		triggerKeyboard->repaint();
	}
}

void MidiChordsEditor::mouseUp (const MouseEvent& e)
{
	if (e.eventComponent==previewButton) {
		if (e.mods.isPopupMenu())
		{
			if (getFilter()->isPreviewChordPlaying()) {
				getFilter()->playCurrentChord(false);
				previewButton->setToggleState(false,false);
			}
			else {
				getFilter()->playCurrentChord(true);
				previewButton->setToggleState(true,false);
			}
		}
		else {
			getFilter()->playCurrentChord(false);
			previewButton->setToggleState(false,false);
		}
	}
}

void MidiChordsEditor::chordFromString(String chordString)
{
	const int root = chordString.upToFirstOccurrenceOf(":",false,false).getIntValue();
	const int t = getFilter()->getCurrentTrigger();
	StringArray sa;
	if(chordString.contains(":"))
		chordString = chordString.fromLastOccurrenceOf(":",false,false);
	if (chordString.containsAnyOf("abcdefgABCDEFGmMrRopP#+")/* || !chordString.contains("0")*/)
		chordString = getIntervalStringFromNoteNames(t,chordString,getFilter()->bottomOctave);

	sa.addTokens(chordString," ,",String::empty);
	if (sa.size()>0)
		getFilter()->clearChord(t);
	if (ModifierKeys::getCurrentModifiers().isCommandDown())
	{
		//absolute
		for(int i=0;i<sa.size();i++)
		{
			String s = sa[i].trim();
			if (s.isNotEmpty())
			{
				if(s.contains("."))
					getFilter()->selectChordNote(t,root+s.upToFirstOccurrenceOf(".",false,true).getIntValue(),true,s.fromFirstOccurrenceOf(".",false,true).getIntValue());
				else
					getFilter()->selectChordNote(t,root+s.getIntValue(),true);
			}
		}
	}
	else {
		//relative
		for(int i=0;i<sa.size();i++)
		{
			String s = sa[i].trim();
			if (s.isNotEmpty())
			{
				if(s.contains("."))
					getFilter()->selectChordNote(t,t+s.upToFirstOccurrenceOf(".",false,true).getIntValue(),true,s.fromFirstOccurrenceOf(".",false,true).getIntValue());
				else
					getFilter()->selectChordNote(t,t+s.getIntValue(),true);
			}
		}
	}
	if (guitar->isVisible())
			getFilter()->translateToGuitarChord();
}

void MidiChordsEditor::changeListenerCallback (ChangeBroadcaster* source)
{
	if (source==getFilter())
		updateParametersFromFilter();
}

void MidiChordsEditor::updateParametersFromFilter()
{
	MidiChords* const filter = getFilter();
	const int newMode = roundToInt(filter->getParameter(kMode)*(numModes-1));
	const int chordChan = roundToInt(filter->getParameter(kLearnChannel)*16.f);
	const int outChan = roundToInt(filter->getParameter(kOutChannel)*16.f);
	const int previewVel = roundToInt(filter->getParameter(kVelocity)*126.f)+1;
	const int transpose = roundToInt(filter->getParameter(kTranspose)*96.f)-48;
	const int s = filter->getNumStrings();
	const bool flats = filter->getParameter(kFlats)>0;

	guitar->setVisible(filter->getGuitarView());
	setupButton->setEnabled(filter->getGuitarView());
	fretsSlider->setValue(filter->getNumFrets(),false);
	guitar->setNumFrets(filter->getNumFrets());

	stringsSlider->setValue(s,false);
	guitar->setNumStrings(s);

	guitarPreset = -1;
	for (int i=0;i<filter->guitarPresets.size();i++) {
		if (isGuitarPreset(i))
		{
			guitarPreset = i;
			break;
		}
	}

	for (int i=0;i<maxStrings;i++)
	{
		stringSlider[i]->setEnabled(i<s);
		stringSlider[i]->setValue(filter->getStringValue(i),false);
		guitar->setStringNote(i,filter->getStringValue(i));
	}

	channelSlider->setValue(filter->getParameter(kChannel)*16.f,false);
	learnChanSlider->setValue(chordChan,false);
	outputChannelSlider->setValue(outChan,false);
	velocitySlider->setValue(previewVel,false);
	transposeSlider->setValue(transpose,false);
	chordLearnButton->setToggleState(filter->getParameter(kLearnChord)>0,false);
	triggerLearnButton->setToggleState(filter->getParameter(kFollowInput)>0,false);
	toggleButton->setToggleState(filter->getParameter(kGuess)>0,false);
	flatsButton->setToggleState(flats,false);
	guitar->setFlats(flats);
	pcButton->setToggleState(filter->getParameter(kUseProgCh)>0,false);
	transposeInputButton->setToggleState(filter->getParameter(kInputTranspose)>0,false);
	toAllChannelsButton->setToggleState(filter->getParameter(kToAllChannels)>0,false);

	if (chordChan==0) chordKeyboard->setMidiChannelsToDisplay(0xffff);
	else chordKeyboard->setMidiChannelsToDisplay(1<<(chordChan-1));

	normalButton->setToggleState(newMode==Normal,false);
	octaveButton->setToggleState(newMode==Octave,false);
	globalButton->setToggleState(newMode==Global,false);

	chordNameLabel->setText(getCurrentChordName(),false);

	if (guitar->isVisible())
		guitar->handleAsyncUpdate();


	const int t = getFilter()->getCurrentTrigger();
	String chordString;// = String(t) + ":";
	for (int n=0;n<128;n++) {
		for (int c=1;c<=16;c++) {
			if (getFilter()->chordKbState.isNoteOn(c,n))
				chordString += String(n-t)/*+"."+String(c)*/+" ";
		}
	}
	chordEditor->setText(chordString.trimEnd(),false);

	if (mode!=newMode)
	{
		if (newMode==Global) {
			triggerLabel->setText("Root Note:",false);
			triggerKeyboard->setKeyWidth(16.f);
			triggerKeyboard->setAvailableRange(0,127);
			triggerKeyboard->setLowestVisibleKey(36);
			triggerNoteLabel->setText(getNoteName(t,getFilter()->bottomOctave)+" ("+String(t)+")",false);
		}
		else if (newMode==Octave) {
			triggerLabel->setText("Trigger Note:",false);
			triggerKeyboard->setAvailableRange(60,71);
			triggerKeyboard->setKeyWidth((float)triggerKeyboard->getWidth()/7.f);
			triggerNoteLabel->setText(getNoteNameWithoutOctave(t,!flats),false);
		}
		else {
			triggerLabel->setText("Trigger Note:",false);
			triggerKeyboard->setKeyWidth(16.f);
			triggerKeyboard->setAvailableRange(0,127);
			triggerKeyboard->setLowestVisibleKey(36);
			triggerNoteLabel->setText(getNoteName(t,getFilter()->bottomOctave)+" ("+String(t)+")",false);
		}
		mode = newMode;
	}
	else {
		if (newMode!=Octave)
			triggerNoteLabel->setText(getNoteName(t,getFilter()->bottomOctave)+" ("+String(t)+")",false);
		else
			triggerNoteLabel->setText(getNoteNameWithoutOctave(t),false);
	}

	if (presetNameLabel->getText() != getFilter()->getProgramName(getFilter()->getCurrentProgram()))
		presetNameLabel->setText(getFilter()->getProgramName(getFilter()->getCurrentProgram()),false);

	triggerKeyboard->repaint();
	//repaint();
}

String const MidiChordsEditor::getCurrentChordName()
{
	if (getFilter()->getParameter(kGuess)==0.f)
		return String::empty;

	Array<int> chord;
	for (int n=0;n<128;n++)
	{
		for (int c=0;c<=16;c++)
		{
			if (getFilter()->chordKbState.isNoteOn(c,n))
				chord.add(n);
		}
	}
	return getFirstRecognizedChord(chord,getFilter()->getParameter(kFlats)>0.f);
}

void MidiChordsEditor::listChordFiles(StringArray &list)
{
	String chordPath = getFilter()->getCurrentPath() + File::separatorString
		+ "midiChords" + File::separatorString + "chords";

	if (guitarPreset>=0 && guitar->isVisible())
		chordPath += File::separatorString + getFilter()->guitarPresets[guitarPreset].chordFile;
	else 
		chordPath += File::separatorString + "Chords.txt";

	File chordFile = File(chordPath);
	if (!chordFile.exists())
		chordFile = getFilter()->getCurrentPath() + File::separatorString
			+ "midiChords" + File::separatorString + "chords" + File::separatorString + "Chords.txt";

	StringArray s;
	s.addLines(chordFile.loadFileAsString());
	for (int line=0;line<s.size();line++)
	{
		if (!s[line].startsWithChar(';'))
			list.add(s[line]);
	}

	chordFile = getFilter()->getCurrentPath() + File::separatorString
		+ "midiChords" + File::separatorString + "chords" + File::separatorString + "User.txt";
	s.clear();
	s.addLines(chordFile.loadFileAsString());
	for (int line=0;line<s.size();line++)
	{
		if (!s[line].startsWithChar(';'))
			list.add(s[line]);
	}
}

void MidiChordsEditor::listPresetFiles(Array<File> &list)
{
	File mappingsPath(getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"mappings");
	Array<File> files;
	mappingsPath.findChildFiles(files,File::findFiles,true);
	for (int i=0;i<files.size();i++)
	{
		if (files[i].hasFileExtension("chords") || files[i].hasFileExtension("fxp") || files[i].hasFileExtension("xml"))
			list.add(files[i]);
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
		if (sa[i].trim().isNotEmpty())
		{
			if(sa[i].contains("."))
				getFilter()->selectChordNote(t,t+sa[i].upToFirstOccurrenceOf(".",false,true).getIntValue(),true,sa[i].fromFirstOccurrenceOf(".",false,true).getIntValue());
			else
				getFilter()->selectChordNote(t,t+sa[i].getIntValue(),true);
		}
	}
	if (guitar->isVisible())
		getFilter()->translateToGuitarChord();
}

void MidiChordsEditor::loadPreset(File file)
{
	if (file.hasFileExtension("fxp"))
		getFilter()->loadFxpFile(file);
	else if (file.hasFileExtension("fxb"))
		getFilter()->loadFxbFile(file);
	else if (file.hasFileExtension("xml"))
		getFilter()->readChorderPreset(file);
	else
	{
		const int t = getFilter()->getCurrentTrigger();

		getFilter()->clearAllChords();

		StringArray lines;
		lines.addLines(file.loadFileAsString());
		for(int ln=0;ln<lines.size();ln++)
		{
			if (!lines[ln].startsWithChar(';'))
			{
				if (lines[ln].upToFirstOccurrenceOf(":",false,false).equalsIgnoreCase("Mode"))
				{
					String s = lines[ln].fromLastOccurrenceOf(":",false,true);
					if (s.equalsIgnoreCase("Full"))
						getFilter()->setParameterNotifyingHost(kMode,((float)Normal)/(float)(numModes-1));
					if (s.equalsIgnoreCase("Octave"))
						getFilter()->setParameterNotifyingHost(kMode,((float)Octave)/(float)(numModes-1));
					if (s.equalsIgnoreCase("Global"))
						getFilter()->setParameterNotifyingHost(kMode,((float)Global)/(float)(numModes-1));
				}
				else
				{
					int t = lines[ln].upToFirstOccurrenceOf(":",false,false).getIntValue();
					//getFilter()->clearChord(t);
					StringArray sa;
					sa.addTokens(lines[ln].fromLastOccurrenceOf(":",false,true)," ",String::empty);
					for(int i=0;i<sa.size();i++)
					{
						if(sa[i].trim().isNotEmpty())
						{
							if(sa[i].contains("."))
								getFilter()->selectChordNote(t,t+sa[i].upToFirstOccurrenceOf(".",false,true).getIntValue(),true,sa[i].fromFirstOccurrenceOf(".",false,true).getIntValue());
							else
								getFilter()->selectChordNote(t,t+sa[i].getIntValue(),true);
						}
					}
				}
			}
		}
		presetNameLabel->setText(file.getFileNameWithoutExtension(),false);
		getFilter()->changeProgramName(getFilter()->getCurrentProgram(),file.getFileNameWithoutExtension());
		getFilter()->updateHostDisplay();
	}
}

void MidiChordsEditor::saveChord(String name)
{
	const int curProgram = getFilter()->getCurrentProgram();
	const int t = getFilter()->getCurrentTrigger();
	String chordString = name + ":";
	for (int c=1;c<=16;c++) {
		for (int n=0;n<128;n++)
		{
			if (getFilter()->progKbState[curProgram][t].isNoteOn(c,n))
				chordString += " " + String(n-t) + "." + String(c);
		}
	}
	File chordFile(getFilter()->getCurrentPath()+File::separatorString
		+"midiChords"+File::separatorString+"chords"+File::separatorString+"User.txt");
	if (chordFile.create())
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

void MidiChordsEditor::filesDropped (const StringArray& filenames, int mouseX, int mouseY)
{
	File file = File(filenames[0]);
	if ( file.hasFileExtension("chords") || file.hasFileExtension("fxp") || file.hasFileExtension("fxb")
		|| file.hasFileExtension("xml"))
		loadPreset(file);
	else if (file.getFileName() == "midiChordsKey.txt" || file.getFileName() == "midiChordsKey.zip") {
		getFilter()->readKeyFile(File(filenames[0]));
		if (!getFilter()->demo) {
			demoLabel->setVisible(false);
		}
	}
}

bool MidiChordsEditor::isInterestedInFileDrag (const StringArray& files){
    File file = File(files[0]);
	if ( file.hasFileExtension("chords") || file.hasFileExtension("fxp") || file.hasFileExtension("fxb") || file.hasFileExtension("xml"))
		return true;
	if ( file.getFileName() == "midiChordsKey.txt" || file.getFileName() == "midiChordsKey.zip" )
		return true;
    return false;
}

void MidiChordsEditor::fileClicked(const juce::File &file,const juce::MouseEvent &)
{
	if (file.existsAsFile())
		loadPreset(file);
}

void MidiChordsEditor::fileDoubleClicked (const File &file)
{
	if (file.existsAsFile())
	{
		//loadPreset(file);
		PopupMenu::dismissAllActiveMenus();
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiChordsEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public ChangeListener, public TextEditorListener, public FileDragAndDropTarget, public FileBrowserListener"
                 constructorParams="MidiChords* const ownerFilter" variableInitialisers="AudioProcessorEditor (ownerFilter)"
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="640" initialHeight="400">
  <BACKGROUND backgroundColour="ffd8d8d8">
    <RECT pos="0 0 640 100" fill="linear: 61 -31, 61 23, 0=ffffffff, 1=e7e7e7"
          hasStroke="0"/>
    <ROUNDRECT pos="568 76 66 106" cornerSize="10" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="0 348 100% 52" fill="linear: 0 331, 0 360, 0=ff000000, 1=ff828282"
          hasStroke="0"/>
    <TEXT pos="110 24 248 30" fill="solid: ff000000" hasStroke="0" text="midiChords"
          fontname="OCR A Std" fontsize="35.7" bold="0" italic="0" justification="36"/>
    <TEXT pos="14 319 103 24" fill="solid: ff000000" hasStroke="0" text="Trigger Channel:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="110 0 248 30" fill="solid: ff000000" hasStroke="0" text="Insert Piz Here&#8212;&gt;"
          fontname="OCR A Std" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="318 318 138 24" fill="solid: ff000000" hasStroke="0" text="Trigger Mode:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <RECT pos="6 225 12M 93" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="6 97 12M 93" fill="solid: ff000000" hasStroke="0"/>
    <ROUNDRECT pos="462 202 172 36" cornerSize="10" fill="solid: ff000000" hasStroke="0"/>
    <ROUNDRECT pos="250 195 173 26" cornerSize="12" fill="linear: 248 183, 248 215, 0=ff666666, 1=ffbfbfbf"
               hasStroke="0"/>
    <TEXT pos="6 46 71 8" fill="solid: ff000000" hasStroke="0" text="Input Channel"
          fontname="Default font" fontsize="10.7" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="58723bf0e9d70b49" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="372 50 150 24" buttonText="Guess chord name"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="84701c0c650fe2e" memberName="chordNameLabel"
         virtualName="" explicitFocusOrder="0" pos="375 72 144 26" bkgCol="279a3c3c"
         outlineCol="b3000000" edTextCol="ff000000" edBkgCol="0" labelText="chord name"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="36"/>
  <GENERICCOMPONENT name="" id="8e79ee27297830eb" memberName="chordKeyboard" virtualName=""
                    explicitFocusOrder="0" pos="8 99 16M 89" class="ChordsKeyboardComponent"
                    params="ownerFilter-&gt;chordKbState, ownerFilter"/>
  <GENERICCOMPONENT name="" id="c10b054d27a5aad0" memberName="triggerKeyboard" virtualName=""
                    explicitFocusOrder="0" pos="8 227 16M 89" class="TriggerKeySelectorKeyboard"
                    params="ownerFilter-&gt;triggerKbState, ownerFilter"/>
  <TEXTBUTTON name="chordLearn" id="79a1c0e1c1db8e39" memberName="chordLearnButton"
              virtualName="" explicitFocusOrder="0" pos="6 76 45 21" tooltip="Learn next input chord"
              buttonText="Learn" connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triggerLearn" id="99ff483968f1f65d" memberName="triggerLearnButton"
              virtualName="" explicitFocusOrder="0" pos="6 204 80 21" tooltip="When on, displayed trigger note follows input note"
              buttonText="Follow Input" connectedEdges="8" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="channel" id="c08fa2a5fc963392" memberName="channelSlider"
          virtualName="ChannelSlider" explicitFocusOrder="0" pos="123 323 66 16"
          tooltip="Trigger channel" bkgcol="ffffffff" min="0" max="16"
          int="1" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="53b1a84fa5d6099" memberName="outputLabel"
         virtualName="" explicitFocusOrder="0" pos="573 76 54 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Output" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <JUCERCOMP name="" id="bad9b853cca3ec4a" memberName="pizButton" virtualName=""
             explicitFocusOrder="0" pos="38 3 74 40" sourceFile="../../common/PizButton.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="9c19fc858eab3133" memberName="triggerLabel"
         virtualName="" explicitFocusOrder="0" pos="464 203 97 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Trigger Note:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="clear" id="729ec8a8b3111b3" memberName="clearChordButton"
              virtualName="" explicitFocusOrder="0" pos="291 76 40 21" tooltip="Clear current chord"
              buttonText="Clear" connectedEdges="10" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="706edfe98019c25d" memberName="resetChordButton"
              virtualName="" explicitFocusOrder="0" pos="331 76 40 21" tooltip="Reset current chord to just the trigger note"
              buttonText="Reset" connectedEdges="9" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="clear" id="ee6085145dcb39d2" memberName="clearAllButton"
              virtualName="" explicitFocusOrder="0" pos="9 408 64 24" buttonText="Clear All"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="d63567d98d87183b" memberName="resetAllButton"
              virtualName="" explicitFocusOrder="0" pos="73 408 64 24" buttonText="Reset All"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="f59df0e454cbaec8" memberName="transposeUpButton"
              virtualName="" explicitFocusOrder="0" pos="173 404 32 24" buttonText="-&gt;"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="3fe107b4cf733d10" memberName="transposeDownButton"
              virtualName="" explicitFocusOrder="0" pos="144 404 29 24" buttonText="&lt;-"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="b392a950edbb9665" memberName="transposeChordUpButton"
              virtualName="" explicitFocusOrder="0" pos="159 76 23 21" tooltip="Shift chord up one semitone"
              buttonText="&gt;" connectedEdges="11" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="330f12de98d7240c" memberName="transposeChordDownButton"
              virtualName="" explicitFocusOrder="0" pos="136 76 23 21" tooltip="Shift chord down one semitone"
              buttonText="&lt;" connectedEdges="11" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="transpose" id="e04428ac0ed97dc9" memberName="transposeSlider"
          virtualName="" explicitFocusOrder="0" pos="446 374 66 16" tooltip="Transpose output by semitones"
          bkgcol="ffffffff" min="-12" max="12" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocity" id="d173a9d6025fabc0" memberName="velocitySlider"
          virtualName="" explicitFocusOrder="0" pos="397 197 22 22" tooltip="Velocity for &quot;Play Chord&quot; button"
          rotarysliderfill="7f000000" min="1" max="127" int="1" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Variation" id="992cbb80661db8e9" memberName="variationSlider"
          virtualName="" explicitFocusOrder="0" pos="334 411 104 16" min="0"
          max="100" int="0.1" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="ea513687ce233abe" memberName="normalButton"
              virtualName="" explicitFocusOrder="0" pos="442 318 64 24" tooltip="Full mode: a separate chord is defined for every input note"
              buttonText="Full" connectedEdges="6" needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="new button" id="5d77a8c6aac13eed" memberName="octaveButton"
              virtualName="" explicitFocusOrder="0" pos="506 318 64 24" tooltip="Octave mode: 12 chords are defined which are transposed to every octave"
              buttonText="Octave" connectedEdges="7" needsCallback="1" radioGroupId="1"/>
  <TEXTBUTTON name="new button" id="4ec8d27f5555ec05" memberName="globalButton"
              virtualName="" explicitFocusOrder="0" pos="570 318 64 24" tooltip="Global mode: one defined chord is transposed relative to the root note"
              buttonText="Global" connectedEdges="5" needsCallback="1" radioGroupId="1"/>
  <TOGGLEBUTTON name="new toggle button" id="fb8f2d76e48f6291" memberName="flatsButton"
                virtualName="" explicitFocusOrder="0" pos="519 76 48 24" buttonText="flats"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="transpose" id="9c9792c55f67c803" memberName="transposeChordUpButton2"
              virtualName="" explicitFocusOrder="0" pos="182 76 25 21" tooltip="Shift chord up one octave"
              buttonText="&gt;&gt;" connectedEdges="9" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="1f97de47eccc1b3c" memberName="transposeChordDownButton2"
              virtualName="" explicitFocusOrder="0" pos="111 76 25 21" tooltip="Shift chord down one octave"
              buttonText="&lt;&lt;" connectedEdges="10" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="chordMenu" id="384cb651e909e8bd" memberName="chordMenuButton"
              virtualName="" explicitFocusOrder="0" pos="55 76 52 21" buttonText="Menu"
              connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="4ef6103879c88f80" memberName="presetNameLabel"
         virtualName="" explicitFocusOrder="0" pos="414 12 191 26" tooltip="Preset Name (double-click to edit)"
         bkgCol="27a1b404" outlineCol="b3000000" edTextCol="ff000000"
         edBkgCol="0" labelText="preset name" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="36"/>
  <TEXTBUTTON name="presets" id="fdd2c5f83e8c75c9" memberName="presetMenuButton"
              virtualName="" explicitFocusOrder="0" pos="605 12 25 26" tooltip="Preset Menu"
              buttonText="&gt;" connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="fbf538174362a2ae" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="82 -35 150 24" outlinecol="ff000000"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="copy" id="7eadb69efd0e274e" memberName="copyButton" virtualName=""
              explicitFocusOrder="0" pos="211 73 38 21" buttonText="Copy" connectedEdges="6"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="paste" id="c6429d9f9bdc84d1" memberName="pasteButton" virtualName=""
              explicitFocusOrder="0" pos="249 73 38 21" buttonText="Paste"
              connectedEdges="5" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="play" id="92127eade5a319e5" memberName="previewButton"
              virtualName="" explicitFocusOrder="0" pos="251 196 143 24" tooltip="Plays currently displayed chord"
              bgColOff="ff7ca17c" buttonText="Play Chord" connectedEdges="0"
              needsCallback="0" radioGroupId="0"/>
  <LABEL name="new label" id="5bdae6a44eaf90fa" memberName="chordEditor"
         virtualName="" explicitFocusOrder="0" pos="178 54 144 20" tooltip="Double-click to type a chord"
         bkgCol="ffffffff" outlineCol="b3000000" edTextCol="ff000000"
         edBkgCol="0" labelText="chord" editableSingleClick="0" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="985f12fa947001cc" memberName="pcButton"
                virtualName="" explicitFocusOrder="0" pos="167 375 160 20" tooltip="Change program when receiving MIDI Program Change"
                buttonText="Use Program Change" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TEXTBUTTON name="next" id="112bbd95115b0fee" memberName="nextButton" virtualName=""
              explicitFocusOrder="0" pos="113 204 23 21" tooltip="Select next higher trigger note"
              buttonText="&gt;" connectedEdges="9" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="prev" id="fec45c7b44c486c2" memberName="prevButton" virtualName=""
              explicitFocusOrder="0" pos="90 204 23 21" tooltip="Select previous trigger note"
              buttonText="&lt;" connectedEdges="10" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="f9ca130084b6577" memberName="triggerNoteLabel"
         virtualName="" explicitFocusOrder="0" pos="558 203 73 24" tooltip="Currently displayed trigger note (double-click to edit)"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="ffffffff" labelText="G8 (127)"
         editableSingleClick="0" editableDoubleClick="1" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="channel" id="51b00c0c435d1b05" memberName="learnChanSlider"
          virtualName="ChannelSlider" explicitFocusOrder="0" pos="6 56 38 16"
          tooltip="Chord Input Channel, used for Learn and left-click entering notes"
          bkgcol="ffffffff" min="0" max="16" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="b13bd78310d4145" memberName="demoLabel"
         virtualName="" explicitFocusOrder="0" pos="334 5 81 24" edTextCol="ff000000"
         edBkgCol="0" labelText="UNREGISTERED&#10;DEMO VERSION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="OCR A Extended"
         fontsize="10" bold="0" italic="0" justification="34"/>
  <GENERICCOMPONENT name="new component" id="fe343618ae664d49" memberName="guitar"
                    virtualName="" explicitFocusOrder="0" pos="8 99 16M 89" class="ChordsGuitar"
                    params="ownerFilter-&gt;chordKbState, ownerFilter"/>
  <LABEL name="new label" id="9ec8a16d4577cd67" memberName="versionLabel"
         virtualName="" explicitFocusOrder="0" pos="352 28 58 24" edTextCol="ff000000"
         edBkgCol="0" labelText="99.99.99" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="d3b81c8771f45be2" memberName="transposeInputButton"
                virtualName="" explicitFocusOrder="0" pos="513 372 91 21" tooltip="When checked, incoming trigger notes are transposed by the opposite of the &quot;Transpose&quot; slider."
                buttonText="Also Transpose Input" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="b5393aba43fddbf9" memberName="toAllChannelsButton"
                virtualName="" explicitFocusOrder="0" pos="167 354 149 20" tooltip="When checked, CCs (and other control messages) are sent to all MIDI channels. Otherwise they are passed through on the original channel."
                buttonText="CCs to All Channels" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TEXTBUTTON name="new button" id="57021a22a2d1dc95" memberName="infoButton"
              virtualName="" explicitFocusOrder="0" pos="-1 -1 19 18" buttonText="?"
              connectedEdges="5" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="cca12d6113282f95" memberName="specialMenuButton"
              virtualName="" explicitFocusOrder="0" pos="9 362 140 24" buttonText="Global Functions..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="channel" id="4905788d8bca0925" memberName="outputChannelSlider"
          virtualName="ChannelSlider" explicitFocusOrder="0" pos="348 374 66 16"
          tooltip="Output channel (&quot;Multi&quot; is as saved, otherwise overrides chord's saved channel)"
          bkgcol="ffffffff" min="0" max="16" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="8efd6a9fa5389ff6" memberName="applyChannelButton"
              virtualName="" explicitFocusOrder="0" pos="44 56 32 16" tooltip="Applies input channel to selected chord"
              buttonText="Apply" connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="17e9cd77311da5c7" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="335 359 91 13" edTextCol="ff000000"
         edBkgCol="0" labelText="Out Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="beb727c502d48577" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="432 359 91 13" edTextCol="ff000000"
         edBkgCol="0" labelText="Transpose" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="view" id="d372ec945cfb2f67" memberName="viewButton" virtualName=""
              explicitFocusOrder="0" pos="151 190 41 21" tooltip="Switch between keyboard &amp; guitar views"
              buttonText="View" connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1079b29645f4ab3e" memberName="setupButton"
              virtualName="" explicitFocusOrder="0" pos="195 190 45 21" buttonText="Setup"
              connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="2319ccc237bcf9fc" memberName="infoBox"
              virtualName="" explicitFocusOrder="0" pos="50%c 50%c 500 300"
              bkgcol="f2ffffff" outlinecol="ff000000" shadowcol="38000000"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
