/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  27 Aug 2012 11:21:42am

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
      chordSaveEditor (0),
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
      strumDirectionButton (0),
      strumButton (0),
      maxTimeSlider (0),
      speedSlider (0),
      accelSlider (0),
      velRampSlider (0),
      infoBox (0),
      tuningSaveEditor (0),
      cachedImage_midichordsLogo_png2 (0)
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

    addAndMakeVisible (chordSaveEditor = new TextEditor (L"new text editor"));
    chordSaveEditor->setMultiLine (false);
    chordSaveEditor->setReturnKeyStartsNewLine (false);
    chordSaveEditor->setReadOnly (false);
    chordSaveEditor->setScrollbarsShown (true);
    chordSaveEditor->setCaretVisible (true);
    chordSaveEditor->setPopupMenuEnabled (true);
    chordSaveEditor->setColour (TextEditor::outlineColourId, Colours::black);
    chordSaveEditor->setText (String::empty);

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
    pcButton->setButtonText (L"Use Program Chg");
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
    demoLabel->setJustificationType (Justification::centred);
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
    toAllChannelsButton->setButtonText (L"CCs to All Chans");
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

    addAndMakeVisible (strumDirectionButton = new TextButton (L"new button"));
    strumDirectionButton->setTooltip (L"Strum Direction");
    strumDirectionButton->setButtonText (L"Down");
    strumDirectionButton->addListener (this);

    addAndMakeVisible (strumButton = new TextButton (L"new button"));
    strumButton->setButtonText (L"Strum");
    strumButton->setConnectedEdges (Button::ConnectedOnRight);
    strumButton->addListener (this);

    addAndMakeVisible (maxTimeSlider = new VSTSlider (L"maxTime"));
    maxTimeSlider->setTooltip (L"Max Strum Time");
    maxTimeSlider->setRange (100, 3000, 1);
    maxTimeSlider->setSliderStyle (Slider::LinearBar);
    maxTimeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    maxTimeSlider->setColour (Slider::backgroundColourId, Colours::white);
    maxTimeSlider->addListener (this);

    addAndMakeVisible (speedSlider = new VSTSlider (L"speed"));
    speedSlider->setTooltip (L"Strum Speed");
    speedSlider->setRange (0, 100, 1);
    speedSlider->setSliderStyle (Slider::LinearBar);
    speedSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    speedSlider->setColour (Slider::backgroundColourId, Colours::white);
    speedSlider->addListener (this);

    addAndMakeVisible (accelSlider = new VSTSlider (L"accel"));
    accelSlider->setTooltip (L"Strum Acceleration");
    accelSlider->setRange (-100, 100, 1);
    accelSlider->setSliderStyle (Slider::LinearBar);
    accelSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    accelSlider->setColour (Slider::backgroundColourId, Colours::white);
    accelSlider->addListener (this);

    addAndMakeVisible (velRampSlider = new VSTSlider (L"velRamp"));
    velRampSlider->setTooltip (L"Strum Velocity Ramp");
    velRampSlider->setRange (-100, 100, 1);
    velRampSlider->setSliderStyle (Slider::LinearBar);
    velRampSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    velRampSlider->setColour (Slider::backgroundColourId, Colours::white);
    velRampSlider->addListener (this);

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

    addAndMakeVisible (tuningSaveEditor = new TextEditor (L"new text editor"));
    tuningSaveEditor->setMultiLine (false);
    tuningSaveEditor->setReturnKeyStartsNewLine (false);
    tuningSaveEditor->setReadOnly (false);
    tuningSaveEditor->setScrollbarsShown (true);
    tuningSaveEditor->setCaretVisible (true);
    tuningSaveEditor->setPopupMenuEnabled (true);
    tuningSaveEditor->setColour (TextEditor::outlineColourId, Colours::black);
    tuningSaveEditor->setText (String::empty);

    cachedImage_midichordsLogo_png2 = ImageCache::getFromMemory (midichordsLogo_png2, midichordsLogo_png2Size);

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
	strumButton->setMouseClickGrabsKeyboardFocus(false);
	strumDirectionButton->setMouseClickGrabsKeyboardFocus(false);

	accelSlider->setOwner(ownerFilter,kAccel);
	velRampSlider->setOwner(ownerFilter,kVelRamp);
	speedSlider->setOwner(ownerFilter,kSpeed);
	maxTimeSlider->setOwner(ownerFilter,kMaxDelay);

	guitar->setMouseCursor(MouseCursor::PointingHandCursor);
	chordKeyboard->setMouseCursor(MouseCursor::PointingHandCursor);
	triggerKeyboard->setMouseCursor(MouseCursor::PointingHandCursor);

	//channelSlider->setAllText("Any");
	learnChanSlider->setAllText("All");
	outputChannelSlider->setAllText("Multi");
	chordSaveEditor->addListener(this);
	chordSaveEditor->setTextToShowWhenEmpty("Save chord (type a name)",Colours::grey);
	tuningSaveEditor->addListener(this);
	tuningSaveEditor->setTextToShowWhenEmpty("Save tuning (type name)",Colours::grey);
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

	File chordPath(getFilter()->dataPath+File::separatorString+"mappings");
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
	infoBox->insertTextAtCaret(File(getFilter()->dataPath+File::separatorString+"readme.txt").loadFileAsString());

	const int middleC = getFilter()->getBottomOctave()+5;
	chordKeyboard->setOctaveForMiddleC(middleC);
	triggerKeyboard->setOctaveForMiddleC(middleC);
	guitar->setOctaveForMiddleC(middleC);

	static NonShinyLookAndFeel Look;
	LookAndFeel::setDefaultLookAndFeel (&Look);

	mode = Normal;
    //[/UserPreSize]

    setSize (640, 420);


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
    deleteAndZero (chordSaveEditor);
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
    deleteAndZero (strumDirectionButton);
    deleteAndZero (strumButton);
    deleteAndZero (maxTimeSlider);
    deleteAndZero (speedSlider);
    deleteAndZero (accelSlider);
    deleteAndZero (velRampSlider);
    deleteAndZero (infoBox);
    deleteAndZero (tuningSaveEditor);


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
    g.drawImageWithin (cachedImage_midichordsLogo_png2,
                       113, 7, 234, 45,
                       RectanglePlacement::centred,
                       false);

    g.setGradientFill (ColourGradient (Colours::black,
                                       0.0f, 331.0f,
                                       Colour (0xff828282),
                                       0.0f, 360.0f,
                                       false));
    g.fillRect (0, 348, proportionOfWidth (1.0000f), 72);

    g.setGradientFill (ColourGradient (Colour (0xff0000),
                                       230.0f, 323.0f,
                                       Colours::black,
                                       230.0f, 377.0f,
                                       false));
    g.drawRect (196, 323, 150, 92, 1);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (568.0f, 76.0f, 66.0f, 106.0f, 10.0000f);

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (L"Trigger Channel:",
                5, 319, 112, 24,
                Justification::centredRight, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.0000f, Font::plain));
    g.drawText (L"Trigger Mode:",
                330, 318, 126, 24,
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

    g.setColour (Colours::black);
    g.setFont (Font (12.0000f, Font::plain));
    g.drawText (L"Strum:",
                219, 328, 53, 16,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (12.0000f, Font::plain));
    g.drawText (L"Max Time",
                204, 351, 62, 16,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (12.0000f, Font::plain));
    g.drawText (L"Vel. Ramp",
                277, 351, 62, 16,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (12.0000f, Font::plain));
    g.drawText (L"Accel",
                277, 380, 62, 16,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (12.0000f, Font::plain));
    g.drawText (L"Speed",
                204, 380, 62, 16,
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
    clearAllButton->setBounds (8, 429, 64, 24);
    resetAllButton->setBounds (69, 441, 64, 24);
    transposeUpButton->setBounds (172, 425, 32, 24);
    transposeDownButton->setBounds (143, 425, 29, 24);
    transposeChordUpButton->setBounds (159, 76, 23, 21);
    transposeChordDownButton->setBounds (136, 76, 23, 21);
    transposeSlider->setBounds (475, 372, 66, 16);
    velocitySlider->setBounds (397, 197, 22, 22);
    variationSlider->setBounds (333, 432, 104, 16);
    normalButton->setBounds (442, 318, 64, 24);
    octaveButton->setBounds (506, 318, 64, 24);
    globalButton->setBounds (570, 318, 64, 24);
    flatsButton->setBounds (519, 76, 48, 24);
    transposeChordUpButton2->setBounds (182, 76, 25, 21);
    transposeChordDownButton2->setBounds (111, 76, 25, 21);
    chordMenuButton->setBounds (55, 76, 52, 21);
    presetNameLabel->setBounds (414, 12, 191, 26);
    presetMenuButton->setBounds (605, 12, 25, 26);
    chordSaveEditor->setBounds (82, -35, 150, 24);
    copyButton->setBounds (211, 73, 38, 21);
    pasteButton->setBounds (249, 73, 38, 21);
    previewButton->setBounds (251, 196, 143, 24);
    chordEditor->setBounds (178, 54, 144, 20);
    pcButton->setBounds (500, 397, 134, 20);
    nextButton->setBounds (113, 204, 23, 21);
    prevButton->setBounds (90, 204, 23, 21);
    triggerNoteLabel->setBounds (558, 203, 73, 24);
    learnChanSlider->setBounds (6, 56, 38, 16);
    demoLabel->setBounds (327, 5, 88, 24);
    guitar->setBounds (8, 99, getWidth() - 16, 89);
    versionLabel->setBounds (352, 28, 58, 24);
    transposeInputButton->setBounds (545, 370, 91, 21);
    toAllChannelsButton->setBounds (364, 397, 129, 20);
    infoButton->setBounds (-1, -1, 19, 18);
    specialMenuButton->setBounds (6, 357, 140, 24);
    outputChannelSlider->setBounds (381, 372, 66, 16);
    applyChannelButton->setBounds (44, 56, 32, 16);
    label->setBounds (368, 357, 91, 13);
    label2->setBounds (461, 357, 91, 13);
    viewButton->setBounds (151, 190, 41, 21);
    setupButton->setBounds (195, 190, 45, 21);
    strumDirectionButton->setBounds (267, 327, 48, 19);
    strumButton->setBounds (142, 391, 54, 21);
    maxTimeSlider->setBounds (202, 364, 66, 16);
    speedSlider->setBounds (202, 393, 66, 16);
    accelSlider->setBounds (275, 393, 66, 16);
    velRampSlider->setBounds (275, 364, 66, 16);
    infoBox->setBounds (proportionOfWidth (0.5000f) - ((500) / 2), proportionOfHeight (0.5000f) - ((300) / 2), 500, 300);
    tuningSaveEditor->setBounds (253, -31, 150, 24);
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
		menu.addCustomItem(-1,chordSaveEditor,150,24,false);
		menu.addSeparator();
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
		//menu.showMenuAsync (PopupMenu::Options().withTargetComponent (chordMenuButton),
		//	ModalCallbackFunction::forComponent (chordMenuCallback, this));
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
		menu.addCustomItem(-2,browser,250,300,false);
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
		getFilter()->toggleUsePC(pcButton->getToggleState());
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
		int result = m.show();//At(specialMenuButton);
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
		getFilter()->fillGuitarPresetList();
		PopupMenu m, custom, chordfiles;
		for (int i=0;i<getFilter()->guitarPresets.size();i++)
			m.addItem(i+1,getFilter()->guitarPresets[i].guitarName,true,isGuitarPreset(i));

		m.addSeparator();
		custom.addCustomItem(-1,tuningSaveEditor,160,18,false);
		custom.addSeparator();

		//File chordsPath(getFilter()->dataPath+File::separatorString+"chords");
		//Array<File> files;
		//chordsPath.findChildFiles(files,File::findFiles,true);
		//for (int i=0;i<files.size();i++)
		//{
		//	if (files[i].hasFileExtension("txt"))
		//		chordfiles.addItem(10000+i,files[i].getFileNameWithoutExtension(),true,
		//			getFilter()->guitarPresets[guitarPreset].chordFile==files[i].getFileName());
		//}
		//custom.addSubMenu("Chord File",chordfiles);

		custom.addCustomItem(-1,fretsSlider,150,18,false);
		custom.addCustomItem(-1,stringsSlider,150,18,false);
		for (int i=0;i<maxStrings;i++)
			custom.addCustomItem(-1,stringSlider[i],150,18,false);
		m.addSubMenu("Customize",custom);

		int result = m.showAt(setupButton);
		if (result>0) {
			if (result>=10000) {
				;
			}
			else
				setUpGuitar(result-1);
		}
        //[/UserButtonCode_setupButton]
    }
    else if (buttonThatWasClicked == strumDirectionButton)
    {
        //[UserButtonCode_strumDirectionButton] -- add your button handler code here..
		getFilter()->setStrumDirection(!getFilter()->getStrumDirection());
        //[/UserButtonCode_strumDirectionButton]
    }
    else if (buttonThatWasClicked == strumButton)
    {
        //[UserButtonCode_strumButton] -- add your button handler code here..
		getFilter()->setParameterNotifyingHost(kStrum,strumButton->getToggleState() ? 0.f : 1.f);
        //[/UserButtonCode_strumButton]
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
    else if (sliderThatWasMoved == maxTimeSlider)
    {
        //[UserSliderCode_maxTimeSlider] -- add your slider handling code here..
		maxTimeSlider->setVSTParam();
        //[/UserSliderCode_maxTimeSlider]
    }
    else if (sliderThatWasMoved == speedSlider)
    {
        //[UserSliderCode_speedSlider] -- add your slider handling code here..
		speedSlider->setVSTParam();
        //[/UserSliderCode_speedSlider]
    }
    else if (sliderThatWasMoved == accelSlider)
    {
        //[UserSliderCode_accelSlider] -- add your slider handling code here..
		accelSlider->setVSTParam();
        //[/UserSliderCode_accelSlider]
    }
    else if (sliderThatWasMoved == velRampSlider)
    {
        //[UserSliderCode_velRampSlider] -- add your slider handling code here..
		velRampSlider->setVSTParam();
        //[/UserSliderCode_velRampSlider]
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
    else if (sliderThatWasMoved == stringSlider[12])
    {
		getFilter()->setStringValue(12,roundToInt(stringSlider[12]->getValue()),true);
		guitar->setStringNote(12,roundToInt(stringSlider[12]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[13])
    {
		getFilter()->setStringValue(13,roundToInt(stringSlider[13]->getValue()),true);
		guitar->setStringNote(13,roundToInt(stringSlider[13]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[14])
    {
		getFilter()->setStringValue(14,roundToInt(stringSlider[14]->getValue()),true);
		guitar->setStringNote(14,roundToInt(stringSlider[14]->getValue()));
    }
    else if (sliderThatWasMoved == stringSlider[15])
    {
		getFilter()->setStringValue(15,roundToInt(stringSlider[15]->getValue()),true);
		guitar->setStringNote(15,roundToInt(stringSlider[15]->getValue()));
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

void MidiChordsEditor::chordMenuCallback (int result, MidiChordsEditor* editor)
{
	if (result!=0)
	{
		if (result>0) {
		//	loadChord(list[result-1]);
		}
	}
}

void MidiChordsEditor::mouseDown(const MouseEvent& e)
{
	if (e.eventComponent==previewButton && !e.mods.isPopupMenu())
		getFilter()->playCurrentChord(true);
	if (e.eventComponent!=infoBox && infoBox->isVisible()) {
		infoBox->setVisible(false);
		infoButton->setToggleState(false,false);
	}
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

	accelSlider->setVSTSlider();
	velRampSlider->setVSTSlider();
	speedSlider->setVSTSlider();
	maxTimeSlider->setVSTSlider();
	strumButton->setToggleState(filter->getParameter(kStrum)>0,false);
	strumDirectionButton->setEnabled(strumButton->getToggleState());
	accelSlider->setEnabled(strumButton->getToggleState());
	velRampSlider->setEnabled(strumButton->getToggleState());
	speedSlider->setEnabled(strumButton->getToggleState());
	maxTimeSlider->setEnabled(strumButton->getToggleState());
	if (filter->getStrumDirection())
		strumDirectionButton->setButtonText("Up");
	else
		strumDirectionButton->setButtonText("Down");

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
	String chordPath = getFilter()->dataPath + File::separatorString + "chords";

	if (guitarPreset>=0 && guitar->isVisible())
		chordPath += File::separatorString + getFilter()->guitarPresets[guitarPreset].chordFile;
	else
		chordPath += File::separatorString + "Chords.txt";

	File chordFile = File(chordPath);
	if (!chordFile.exists())
		chordFile = getFilter()->dataPath + File::separatorString + "chords" + File::separatorString + "Chords.txt";

	StringArray s;
	s.addLines(chordFile.loadFileAsString());
	for (int line=0;line<s.size();line++)
	{
		if (!s[line].startsWithChar(';'))
			list.add(s[line]);
	}

	chordFile = getFilter()->dataPath + File::separatorString + "chords" + File::separatorString + "User.txt";
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
	File mappingsPath(getFilter()->dataPath+File::separatorString+"mappings");
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
		//const int t = getFilter()->getCurrentTrigger();

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
	File chordFile(getFilter()->dataPath+File::separatorString+"chords"+File::separatorString+"User.txt");
	if (chordFile.create())
		chordFile.appendText(chordString+"\n");
}

void MidiChordsEditor::textEditorTextChanged(TextEditor &editor) {

}

void MidiChordsEditor::textEditorReturnKeyPressed(TextEditor &editor) {
	if (&editor==chordSaveEditor) {
		saveChord(chordSaveEditor->getText());
		PopupMenu::dismissAllActiveMenus();
		chordSaveEditor->clear();
	}
	else if (&editor==tuningSaveEditor)
	{
		String tuningString="\""+tuningSaveEditor->getText()+"\", "
			+ String("Chords.txt, ")
			+ String(roundToInt(fretsSlider->getValue()))+" frets, ";
		for (int i=0;i<roundToInt(stringsSlider->getValue());i++)
		{
			if (i>0) tuningString += ",";
			tuningString += String(roundToInt(stringSlider[i]->getValue()));
		}
		File tuningFile(getFilter()->dataPath+File::separatorString+"guitars"+File::separatorString+"GuitarPresets.txt");
		if (tuningFile.create())
			tuningFile.appendText(tuningString+"\n");

		getFilter()->fillGuitarPresetList();
		PopupMenu::dismissAllActiveMenus();
		tuningSaveEditor->clear();
	}
}

void MidiChordsEditor::textEditorEscapeKeyPressed(TextEditor &editor) {
	PopupMenu::dismissAllActiveMenus();
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

void MidiChordsEditor::browserRootChanged (const File& newRoot)
{

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
                 fixedSize="1" initialWidth="640" initialHeight="420">
  <BACKGROUND backgroundColour="ffd8d8d8">
    <RECT pos="0 0 640 100" fill="linear: 61 -31, 61 23, 0=ffffffff, 1=e7e7e7"
          hasStroke="0"/>
    <IMAGE pos="113 7 234 45" resource="midichordsLogo_png2" opacity="1"
           mode="1"/>
    <RECT pos="0 348 100% 72" fill="linear: 0 331, 0 360, 0=ff000000, 1=ff828282"
          hasStroke="0"/>
    <RECT pos="196 323 150 92" fill="solid: a52a85" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="linear: 230 323, 230 377, 0=ff0000, 1=ff000000"/>
    <ROUNDRECT pos="568 76 66 106" cornerSize="10" fill="solid: ff000000" hasStroke="0"/>
    <TEXT pos="5 319 112 24" fill="solid: ff000000" hasStroke="0" text="Trigger Channel:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="34"/>
    <TEXT pos="330 318 126 24" fill="solid: ff000000" hasStroke="0" text="Trigger Mode:"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
    <RECT pos="6 225 12M 93" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="6 97 12M 93" fill="solid: ff000000" hasStroke="0"/>
    <ROUNDRECT pos="462 202 172 36" cornerSize="10" fill="solid: ff000000" hasStroke="0"/>
    <ROUNDRECT pos="250 195 173 26" cornerSize="12" fill="linear: 248 183, 248 215, 0=ff666666, 1=ffbfbfbf"
               hasStroke="0"/>
    <TEXT pos="6 46 71 8" fill="solid: ff000000" hasStroke="0" text="Input Channel"
          fontname="Default font" fontsize="10.7" bold="0" italic="0" justification="36"/>
    <TEXT pos="219 328 53 16" fill="solid: ff000000" hasStroke="0" text="Strum:"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="204 351 62 16" fill="solid: ff000000" hasStroke="0" text="Max Time"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="277 351 62 16" fill="solid: ff000000" hasStroke="0" text="Vel. Ramp"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="277 380 62 16" fill="solid: ff000000" hasStroke="0" text="Accel"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="204 380 62 16" fill="solid: ff000000" hasStroke="0" text="Speed"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="36"/>
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
              virtualName="" explicitFocusOrder="0" pos="8 429 64 24" buttonText="Clear All"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="reset" id="d63567d98d87183b" memberName="resetAllButton"
              virtualName="" explicitFocusOrder="0" pos="69 441 64 24" buttonText="Reset All"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="f59df0e454cbaec8" memberName="transposeUpButton"
              virtualName="" explicitFocusOrder="0" pos="172 425 32 24" buttonText="-&gt;"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="3fe107b4cf733d10" memberName="transposeDownButton"
              virtualName="" explicitFocusOrder="0" pos="143 425 29 24" buttonText="&lt;-"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="b392a950edbb9665" memberName="transposeChordUpButton"
              virtualName="" explicitFocusOrder="0" pos="159 76 23 21" tooltip="Shift chord up one semitone"
              buttonText="&gt;" connectedEdges="11" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="transpose" id="330f12de98d7240c" memberName="transposeChordDownButton"
              virtualName="" explicitFocusOrder="0" pos="136 76 23 21" tooltip="Shift chord down one semitone"
              buttonText="&lt;" connectedEdges="11" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="transpose" id="e04428ac0ed97dc9" memberName="transposeSlider"
          virtualName="" explicitFocusOrder="0" pos="475 372 66 16" tooltip="Transpose output by semitones"
          bkgcol="ffffffff" min="-12" max="12" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velocity" id="d173a9d6025fabc0" memberName="velocitySlider"
          virtualName="" explicitFocusOrder="0" pos="397 197 22 22" tooltip="Velocity for &quot;Play Chord&quot; button"
          rotarysliderfill="7f000000" min="1" max="127" int="1" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Variation" id="992cbb80661db8e9" memberName="variationSlider"
          virtualName="" explicitFocusOrder="0" pos="333 432 104 16" min="0"
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
  <TEXTEDITOR name="new text editor" id="fbf538174362a2ae" memberName="chordSaveEditor"
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
                virtualName="" explicitFocusOrder="0" pos="500 397 134 20" tooltip="Change program when receiving MIDI Program Change"
                buttonText="Use Program Chg" connectedEdges="0" needsCallback="1"
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
         virtualName="" explicitFocusOrder="0" pos="327 5 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="UNREGISTERED&#10;DEMO VERSION" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="OCR A Extended"
         fontsize="10" bold="0" italic="0" justification="36"/>
  <GENERICCOMPONENT name="new component" id="fe343618ae664d49" memberName="guitar"
                    virtualName="" explicitFocusOrder="0" pos="8 99 16M 89" class="ChordsGuitar"
                    params="ownerFilter-&gt;chordKbState, ownerFilter"/>
  <LABEL name="new label" id="9ec8a16d4577cd67" memberName="versionLabel"
         virtualName="" explicitFocusOrder="0" pos="352 28 58 24" edTextCol="ff000000"
         edBkgCol="0" labelText="99.99.99" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="d3b81c8771f45be2" memberName="transposeInputButton"
                virtualName="" explicitFocusOrder="0" pos="545 370 91 21" tooltip="When checked, incoming trigger notes are transposed by the opposite of the &quot;Transpose&quot; slider."
                buttonText="Also Transpose Input" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="b5393aba43fddbf9" memberName="toAllChannelsButton"
                virtualName="" explicitFocusOrder="0" pos="364 397 129 20" tooltip="When checked, CCs (and other control messages) are sent to all MIDI channels. Otherwise they are passed through on the original channel."
                buttonText="CCs to All Chans" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TEXTBUTTON name="new button" id="57021a22a2d1dc95" memberName="infoButton"
              virtualName="" explicitFocusOrder="0" pos="-1 -1 19 18" buttonText="?"
              connectedEdges="5" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="cca12d6113282f95" memberName="specialMenuButton"
              virtualName="" explicitFocusOrder="0" pos="6 357 140 24" buttonText="Global Functions..."
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="channel" id="4905788d8bca0925" memberName="outputChannelSlider"
          virtualName="ChannelSlider" explicitFocusOrder="0" pos="381 372 66 16"
          tooltip="Output channel (&quot;Multi&quot; is as saved, otherwise overrides chord's saved channel)"
          bkgcol="ffffffff" min="0" max="16" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="8efd6a9fa5389ff6" memberName="applyChannelButton"
              virtualName="" explicitFocusOrder="0" pos="44 56 32 16" tooltip="Applies input channel to selected chord"
              buttonText="Apply" connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="17e9cd77311da5c7" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="368 357 91 13" edTextCol="ff000000"
         edBkgCol="0" labelText="Out Channel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="beb727c502d48577" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="461 357 91 13" edTextCol="ff000000"
         edBkgCol="0" labelText="Transpose" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="view" id="d372ec945cfb2f67" memberName="viewButton" virtualName=""
              explicitFocusOrder="0" pos="151 190 41 21" tooltip="Switch between keyboard &amp; guitar views"
              buttonText="View" connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1079b29645f4ab3e" memberName="setupButton"
              virtualName="" explicitFocusOrder="0" pos="195 190 45 21" buttonText="Setup"
              connectedEdges="4" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="3afc44df79bf17dc" memberName="strumDirectionButton"
              virtualName="" explicitFocusOrder="0" pos="267 327 48 19" tooltip="Strum Direction"
              buttonText="Down" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d7138ce195ecfe1d" memberName="strumButton"
              virtualName="" explicitFocusOrder="0" pos="142 391 54 21" buttonText="Strum"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="maxTime" id="f7231d7c45deba2d" memberName="maxTimeSlider"
          virtualName="VSTSlider" explicitFocusOrder="0" pos="202 364 66 16"
          tooltip="Max Strum Time" bkgcol="ffffffff" min="100" max="3000"
          int="1" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="speed" id="a243163cabbb95ac" memberName="speedSlider" virtualName="VSTSlider"
          explicitFocusOrder="0" pos="202 393 66 16" tooltip="Strum Speed"
          bkgcol="ffffffff" min="0" max="100" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="accel" id="5cdb7ff5a14641ba" memberName="accelSlider" virtualName="VSTSlider"
          explicitFocusOrder="0" pos="275 393 66 16" tooltip="Strum Acceleration"
          bkgcol="ffffffff" min="-100" max="100" int="1" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="velRamp" id="5280e3c28d4cfc6a" memberName="velRampSlider"
          virtualName="VSTSlider" explicitFocusOrder="0" pos="275 364 66 16"
          tooltip="Strum Velocity Ramp" bkgcol="ffffffff" min="-100" max="100"
          int="1" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTEDITOR name="new text editor" id="2319ccc237bcf9fc" memberName="infoBox"
              virtualName="" explicitFocusOrder="0" pos="50%c 50%c 500 300"
              bkgcol="f2ffffff" outlinecol="ff000000" shadowcol="38000000"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="663ee95273f8530a" memberName="tuningSaveEditor"
              virtualName="" explicitFocusOrder="0" pos="253 -31 150 24" outlinecol="ff000000"
              initialText="" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: midichordsLogo_png2, 4293, "../../../../../Desktop/midichords logo.png"
static const unsigned char resource_MidiChordsEditor_midichordsLogo_png2[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,234,0,0,0,41,8,6,0,0,0,59,232,181,84,0,0,0,6,98,75,71,68,0,255,0,255,
0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,15,95,0,0,15,95,1,215,138,218,201,0,0,0,7,116,73,77,69,7,220,8,27,15,32,18,115,33,255,124,0,0,16,82,73,68,65,84,120,218,237,157,105,148,84,197,21,128,191,
238,153,193,1,20,4,1,117,4,4,4,65,113,95,112,205,193,53,120,80,131,198,37,196,24,99,212,68,227,26,227,190,128,27,198,24,21,53,71,162,70,209,152,168,199,68,147,104,204,113,79,112,79,220,119,81,193,53,128,
200,34,142,48,195,48,204,244,203,143,186,149,190,83,83,175,251,189,215,111,102,122,164,239,57,239,204,235,154,122,85,183,234,46,117,235,214,173,42,232,124,248,0,8,228,249,90,189,191,15,244,100,205,134,
77,128,22,213,39,246,121,30,168,11,249,230,118,201,179,93,39,224,151,17,26,45,2,182,118,254,247,99,193,179,59,65,79,224,18,96,247,114,71,180,186,11,234,156,2,108,4,12,4,206,5,174,7,230,201,179,170,27,
10,87,95,224,89,96,95,96,97,137,101,101,129,42,224,55,192,92,161,79,0,92,5,220,6,236,231,249,102,93,249,219,163,19,218,26,8,221,6,2,235,59,255,27,3,236,216,205,104,215,11,56,27,152,10,92,7,156,78,5,218,
65,157,16,126,108,136,230,238,42,200,196,204,183,110,129,118,196,133,77,165,172,173,156,244,235,128,197,101,208,55,136,146,13,128,189,157,244,105,192,138,78,234,251,52,161,7,112,159,180,233,191,192,14,
149,17,181,45,172,45,127,123,135,104,238,93,128,33,192,159,129,163,128,125,128,247,128,171,129,102,39,255,32,209,140,253,228,119,3,112,35,48,219,83,246,54,192,9,192,90,50,106,253,10,104,21,38,177,166,
230,247,129,119,129,55,128,83,128,113,192,203,50,250,107,28,183,6,46,148,223,151,139,48,85,1,87,138,41,159,20,122,43,198,13,100,164,245,193,197,98,46,127,14,92,26,34,40,89,201,55,88,181,115,149,140,254,
87,122,250,50,42,184,214,207,234,16,65,235,5,156,5,140,0,234,129,91,128,183,84,219,0,70,10,125,111,2,246,16,122,127,5,92,3,204,247,148,185,23,112,132,180,237,45,224,218,18,250,186,25,56,20,152,8,60,0,
188,36,245,158,233,208,96,141,133,145,210,1,97,230,210,77,106,126,22,0,111,203,223,151,156,124,181,194,168,245,192,171,66,184,165,146,183,191,147,247,71,146,254,5,240,154,188,47,241,152,113,11,129,135,
129,167,36,207,155,242,247,143,78,190,67,164,238,0,248,72,132,251,99,49,131,211,28,81,175,151,121,161,59,234,60,37,202,43,0,38,21,48,239,158,20,197,49,27,120,17,88,38,223,236,90,194,136,122,180,40,210,
209,162,4,110,20,159,131,134,129,64,147,234,195,121,74,17,106,56,73,210,167,201,223,79,69,80,115,162,80,53,156,47,121,62,83,52,124,79,248,64,215,59,26,24,229,121,70,3,235,133,180,173,86,104,28,0,159,0,
91,84,12,223,226,130,122,189,252,127,182,48,4,192,105,30,237,102,25,231,6,135,88,123,169,121,91,149,26,5,47,115,76,173,86,96,134,83,166,101,128,122,153,123,89,124,154,85,89,86,96,214,79,209,153,51,74,
202,250,173,140,66,231,2,231,9,142,247,23,16,196,0,248,110,196,58,118,150,252,127,85,35,110,18,65,245,61,238,232,247,128,40,50,45,108,55,139,240,234,180,19,84,25,39,57,125,177,143,35,128,1,112,188,74,
235,39,105,103,68,192,47,80,202,185,159,131,171,165,235,96,81,2,129,208,96,141,55,125,163,204,29,234,129,205,84,218,124,101,54,175,80,105,199,2,51,133,200,55,138,39,239,95,142,153,106,225,101,160,143,
48,248,82,209,244,174,71,117,29,140,119,122,27,96,165,164,77,7,254,45,66,163,203,116,149,65,26,112,188,35,64,207,3,39,134,228,173,242,180,209,55,247,11,128,9,192,35,192,189,192,225,242,191,92,66,28,47,
4,94,192,120,78,27,129,159,74,249,26,54,16,43,163,74,166,39,13,192,59,242,191,254,34,196,90,233,237,15,60,36,239,115,129,99,196,2,192,233,235,215,129,1,64,141,148,57,15,24,166,172,161,189,69,16,91,67,
250,235,11,177,42,52,180,138,98,188,66,126,31,13,220,81,25,79,163,153,190,174,134,158,36,223,12,8,49,91,126,169,76,173,233,206,60,141,2,26,246,70,167,172,207,101,132,142,2,67,139,180,35,137,233,187,67,
12,103,203,58,242,205,193,69,190,57,68,242,205,76,201,153,180,179,71,112,27,156,180,135,66,250,123,145,242,81,32,74,40,202,60,112,227,2,52,60,175,4,231,213,24,101,69,253,211,51,101,90,163,71,212,229,242,
183,144,167,48,235,153,248,227,152,184,22,154,100,254,114,190,104,195,219,129,7,129,89,14,131,159,6,60,38,35,170,237,131,57,30,103,86,109,204,246,52,169,247,111,3,143,151,224,132,168,41,160,96,194,250,
113,101,72,89,1,112,164,204,189,46,5,46,74,137,126,189,61,138,210,197,111,128,8,192,15,84,127,86,203,252,115,69,129,145,63,12,236,232,127,132,248,34,122,168,50,223,73,208,6,107,222,254,90,126,31,35,124,
83,118,78,164,108,23,212,185,35,102,61,240,64,249,61,65,60,110,59,122,136,150,241,120,22,81,66,134,120,19,31,145,209,118,15,140,183,120,177,195,76,129,26,41,127,34,230,90,181,180,63,231,49,255,50,68,95,
42,176,2,122,172,56,129,166,1,143,202,200,147,84,195,7,138,49,115,5,24,102,44,112,128,188,143,3,182,247,224,125,160,8,233,44,140,7,125,188,204,223,119,74,72,191,76,200,232,238,235,179,135,129,109,5,207,
64,204,206,12,38,168,35,74,153,46,124,137,241,54,31,39,180,203,72,153,173,9,133,170,14,227,245,127,70,230,191,183,135,76,151,214,72,152,31,98,186,204,19,51,206,130,111,137,195,206,25,235,28,103,194,251,
158,242,158,245,212,189,137,56,18,220,188,87,59,249,222,118,76,231,98,112,190,83,222,140,132,138,208,174,45,111,19,49,127,163,167,45,110,196,208,201,146,158,243,228,221,52,1,253,236,186,241,110,78,250,
57,248,3,62,238,243,212,251,161,51,34,31,89,192,34,112,97,92,8,255,36,13,86,216,176,200,212,162,44,160,43,16,179,145,45,86,11,90,173,184,132,252,18,132,117,28,84,11,51,186,230,212,146,144,249,75,79,17,
142,122,252,235,111,22,54,83,117,7,226,184,208,90,190,167,48,118,156,72,169,190,226,49,156,47,166,93,82,232,67,251,101,142,48,232,47,14,155,22,233,195,70,204,210,134,11,195,105,235,101,205,74,29,243,82,
196,49,43,253,214,224,201,63,68,148,112,78,240,252,92,70,71,253,237,218,49,218,157,149,121,101,160,28,65,31,84,220,62,21,168,64,5,42,80,129,10,84,160,252,76,95,196,204,25,163,28,38,111,147,60,148,45,41,
84,169,185,91,18,24,129,137,112,9,196,212,157,155,34,110,89,133,215,112,49,53,107,28,7,135,165,221,103,206,148,161,80,153,148,208,222,10,248,229,39,75,97,135,95,183,134,39,29,71,192,93,9,157,47,93,5,227,
61,206,140,237,82,36,62,152,117,202,231,49,158,238,66,81,54,139,9,223,2,87,129,10,36,134,94,180,223,115,105,29,11,157,181,174,187,59,38,62,244,206,132,223,159,161,112,183,78,177,95,164,136,223,94,30,129,
204,133,60,1,48,185,72,121,27,136,208,63,77,91,47,103,5,146,91,60,96,34,224,62,198,236,197,253,70,10,106,51,109,151,12,150,117,178,160,62,165,4,96,124,130,239,207,84,248,91,165,115,102,74,184,213,16,190,
132,21,22,95,187,78,145,50,175,84,249,47,173,200,89,42,48,72,245,233,23,17,104,80,18,116,69,100,82,35,102,29,109,140,50,243,94,233,228,249,147,14,65,28,38,130,27,7,222,85,102,170,141,181,125,33,5,147,
55,192,196,155,218,245,212,12,102,251,220,173,30,90,233,165,165,98,176,177,122,175,115,190,175,64,50,24,170,222,123,98,214,151,151,127,147,4,213,206,241,118,19,38,111,18,147,172,51,5,53,8,121,143,10,15,
97,22,222,135,9,206,243,82,16,84,11,83,196,156,174,194,108,233,187,48,130,25,86,172,223,114,33,239,21,72,14,57,135,135,58,84,233,117,149,160,46,2,254,214,205,9,245,18,237,247,198,150,170,60,46,33,31,231,
11,249,45,95,81,25,166,2,157,7,157,186,98,146,85,19,99,91,113,85,136,32,87,149,40,224,85,17,38,231,105,41,159,108,72,253,153,18,9,147,237,64,252,251,97,54,12,88,120,36,101,69,16,71,89,103,41,109,219,94,
161,239,147,150,157,13,233,235,76,72,121,85,37,210,165,58,1,31,199,41,59,19,129,223,170,245,7,57,153,195,124,38,105,173,152,181,187,86,149,102,211,55,197,132,213,125,154,0,57,91,110,31,103,20,89,128,63,
36,48,41,216,112,186,205,201,239,174,88,77,178,221,21,238,124,48,11,108,233,40,183,38,140,7,185,20,166,206,97,54,79,247,85,102,239,180,78,50,255,91,48,155,223,237,188,120,21,102,55,81,75,10,102,225,8,
199,201,210,136,57,9,163,53,97,153,195,48,39,47,184,237,104,85,244,14,48,206,202,217,41,240,81,127,242,219,24,51,24,167,231,167,41,241,104,15,199,79,163,121,109,185,200,69,155,248,231,233,228,143,235,
220,28,248,143,178,185,223,16,199,75,157,116,176,77,255,8,19,224,30,7,102,17,238,185,156,82,162,57,97,191,27,68,254,232,22,247,89,69,126,199,206,59,42,253,168,136,117,124,171,0,254,205,132,31,239,17,5,
247,26,33,158,245,130,63,157,242,212,228,110,133,235,45,42,125,87,204,198,108,95,155,238,32,222,86,63,171,188,250,74,29,133,60,213,15,144,119,112,69,29,245,238,115,250,198,194,100,242,123,144,245,211,
154,64,217,89,62,58,8,19,47,238,195,253,21,25,108,70,171,180,122,76,156,119,20,216,154,252,209,62,197,158,247,81,199,193,172,160,253,206,138,22,242,203,14,159,97,22,213,221,244,79,105,127,158,77,24,140,
14,65,196,174,65,206,45,193,172,176,157,187,19,38,32,60,160,125,144,128,110,223,25,142,48,71,21,212,155,241,175,109,218,165,166,82,214,210,206,114,202,77,251,156,89,45,168,215,73,218,173,14,189,3,207,
239,183,99,42,208,45,200,159,87,213,18,66,243,22,69,251,9,17,203,213,35,101,64,126,155,227,31,66,104,172,235,185,37,102,95,93,230,225,79,183,204,133,152,189,171,171,99,10,234,246,5,202,14,235,167,0,217,
202,24,182,5,202,45,204,151,231,240,24,29,112,147,12,233,13,242,104,45,184,168,196,17,100,143,16,70,88,129,127,43,216,234,4,130,58,86,76,194,175,165,204,6,169,195,246,209,207,19,226,94,227,140,240,179,
58,192,204,213,130,250,44,254,117,218,102,233,47,151,246,83,35,214,177,123,8,147,53,168,199,199,87,63,140,48,178,214,58,116,219,54,196,18,104,12,161,247,132,24,60,234,126,219,16,210,47,250,61,170,160,
190,230,200,210,106,167,127,236,147,115,202,95,130,74,180,127,151,99,246,87,46,115,210,91,48,71,114,46,87,136,158,28,147,97,214,23,155,127,16,109,15,180,90,88,194,136,218,87,105,113,189,191,116,67,204,
246,170,13,69,35,213,171,118,232,168,158,40,130,154,81,154,125,136,180,161,78,204,32,91,231,169,9,133,104,136,211,207,147,59,80,80,125,90,124,25,230,152,150,58,204,102,247,177,142,226,120,52,98,29,11,
157,58,238,145,178,108,127,217,19,11,167,123,24,189,216,180,161,214,131,115,224,140,104,7,72,27,134,139,31,97,177,202,127,103,4,254,154,232,40,153,149,152,195,8,214,23,220,55,194,28,187,170,113,207,197,
16,212,129,152,192,8,251,253,207,132,119,135,122,158,193,180,141,126,251,59,78,7,44,37,127,226,223,63,28,164,236,70,225,103,41,237,156,26,11,147,82,18,212,3,29,162,127,47,36,95,111,242,71,142,230,18,140,
168,62,120,46,5,65,221,193,97,186,65,29,40,168,57,167,237,215,134,152,181,39,170,60,175,70,176,116,246,112,248,168,216,57,187,39,57,249,143,139,33,168,238,192,242,26,109,207,95,178,48,85,125,243,98,4,
139,237,81,149,127,129,8,150,15,246,245,224,18,69,80,215,117,4,245,226,8,116,27,133,57,198,38,227,154,27,251,99,78,11,215,158,59,48,39,22,60,39,239,203,157,14,76,219,253,29,119,110,58,68,153,78,139,129,
63,121,230,206,25,49,41,182,0,158,144,223,105,172,63,166,177,150,214,218,1,238,255,98,56,191,43,230,227,233,33,237,88,172,222,215,138,128,147,142,244,90,164,156,131,97,48,3,115,146,32,202,9,152,164,29,
247,72,59,86,120,218,160,79,155,88,229,120,186,125,160,113,248,157,244,65,198,67,155,199,49,39,112,52,196,164,255,87,152,184,96,139,199,69,226,193,62,49,196,236,207,202,84,235,46,251,67,35,223,16,82,73,
179,227,98,183,80,14,151,58,85,123,24,172,213,227,194,215,26,177,145,242,1,119,126,126,112,7,11,233,99,98,146,190,174,250,198,101,224,134,152,130,186,150,195,144,81,174,182,88,154,80,225,91,225,152,66,
219,131,188,3,143,151,216,134,122,94,30,194,23,97,74,183,62,164,76,251,253,27,152,195,220,227,194,81,78,93,27,139,210,90,138,57,96,77,159,126,216,38,242,41,235,32,152,141,208,8,159,160,150,203,89,51,81,
215,254,230,80,62,91,234,230,99,14,215,178,112,122,7,227,54,39,2,205,26,99,10,106,224,240,80,20,126,200,22,16,178,48,176,204,123,24,197,151,94,190,20,133,84,133,9,30,41,197,202,241,65,220,163,95,50,242,
205,96,204,54,79,11,171,197,44,62,75,4,246,110,242,123,181,255,111,97,37,97,136,149,33,154,180,59,65,185,29,60,126,167,98,216,145,226,220,233,40,5,216,35,1,141,171,202,164,159,172,160,62,147,224,155,180,
167,52,113,111,207,11,148,98,222,19,19,43,254,23,218,134,140,230,196,74,152,141,57,234,118,91,171,52,178,196,15,38,214,68,236,69,5,74,133,42,153,19,45,81,12,50,189,147,230,171,81,104,92,91,134,138,173,
199,55,128,238,47,97,46,167,26,36,244,175,167,237,6,139,3,48,142,188,25,122,68,13,74,32,98,119,130,76,9,90,182,163,71,137,11,212,239,193,98,222,181,148,129,160,246,160,251,156,188,145,22,68,145,135,85,
41,241,227,98,204,21,38,35,48,171,40,13,142,9,126,34,112,69,54,129,137,213,88,102,130,154,137,161,105,3,204,218,213,150,36,139,55,237,72,166,152,137,137,246,178,52,153,218,133,56,185,115,212,234,152,237,
137,194,232,185,152,166,102,103,66,77,132,60,227,83,86,8,95,98,14,3,239,131,185,234,115,185,178,168,206,205,38,232,164,114,27,81,155,85,163,235,66,70,76,219,198,245,48,23,61,37,157,159,119,36,180,146,
95,127,204,97,150,146,38,118,241,136,154,139,216,87,122,85,96,0,249,91,208,11,129,190,73,160,169,204,20,254,160,34,10,228,32,162,223,77,20,23,135,42,41,123,156,230,237,44,241,55,189,166,53,162,182,120,
52,75,107,2,109,164,239,141,233,131,185,40,42,231,201,187,149,140,88,250,240,237,52,53,98,169,35,116,22,115,181,99,189,18,140,25,93,196,176,141,78,251,138,205,149,63,82,239,253,200,31,86,23,6,55,208,246,
0,237,57,101,32,168,115,84,155,79,197,108,88,240,201,197,89,228,247,82,199,245,239,28,134,57,193,163,16,63,89,62,122,143,252,50,87,166,186,128,230,8,34,8,170,94,158,41,134,116,141,216,225,181,162,65,71,
58,255,27,37,130,182,10,19,193,177,56,98,227,159,196,236,50,176,129,255,231,97,2,244,207,22,141,212,138,137,86,154,170,20,68,117,76,97,181,237,219,64,70,140,42,41,71,71,196,12,149,54,245,150,246,205,77,
168,120,206,33,31,115,58,76,218,119,139,167,127,51,202,41,241,65,202,130,218,228,224,84,204,244,125,21,19,253,51,78,250,101,34,230,18,167,105,24,15,166,13,48,25,134,89,126,218,83,126,103,49,235,200,247,
18,237,164,138,142,132,105,228,189,237,181,152,0,159,203,68,233,212,96,28,167,151,96,238,77,34,129,178,63,20,115,247,15,152,251,143,46,18,229,176,210,41,39,39,211,179,169,152,117,85,219,79,109,66,161,
244,189,37,15,226,15,9,59,66,165,191,27,209,52,170,198,92,103,231,11,250,15,219,16,176,75,140,78,216,132,124,48,118,88,121,250,249,74,189,31,29,177,142,125,8,223,184,224,139,161,189,191,132,81,251,61,
162,237,176,176,207,200,34,229,221,163,242,222,90,196,172,211,247,173,218,221,42,155,69,192,185,63,249,120,223,98,52,208,65,233,99,35,148,93,235,224,51,180,131,132,245,164,8,125,109,113,111,32,31,246,
249,53,249,8,185,48,56,150,232,7,214,185,177,208,175,103,133,193,45,209,26,66,230,162,250,210,215,79,212,123,67,196,14,24,129,57,2,211,29,61,220,219,203,180,25,190,95,140,17,224,67,209,214,111,58,101,
186,102,253,42,204,190,210,87,84,218,130,136,245,76,86,26,207,61,8,59,227,169,111,18,225,241,162,197,96,95,113,38,100,61,78,26,95,187,182,45,82,222,82,199,105,17,197,108,171,87,78,149,40,30,206,47,133,
6,47,59,74,192,135,111,6,19,170,58,156,104,27,250,91,28,39,207,178,14,18,212,25,228,239,145,13,195,63,131,137,119,223,89,89,26,205,20,143,198,154,73,126,139,33,17,233,154,149,65,229,48,48,219,179,2,204,
213,124,26,198,73,231,127,72,251,88,204,39,164,243,38,197,232,132,203,133,224,185,34,154,42,16,115,46,233,249,179,231,137,50,209,101,55,97,54,43,111,32,121,190,35,105,207,197,40,119,40,38,168,191,53,194,
168,209,92,100,46,18,5,6,2,215,72,255,55,21,168,235,137,8,94,202,209,98,98,206,151,247,40,112,188,148,255,251,4,184,159,34,214,86,163,135,14,31,97,2,210,227,174,133,94,140,255,210,233,142,112,40,13,17,
51,117,57,237,207,159,214,222,248,219,36,253,130,24,117,76,146,233,204,2,252,91,242,236,33,7,239,0,87,201,84,139,255,1,66,108,40,112,71,28,235,166,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiChordsEditor::midichordsLogo_png2 = (const char*) resource_MidiChordsEditor_midichordsLogo_png2;
const int MidiChordsEditor::midichordsLogo_png2Size = 4293;
