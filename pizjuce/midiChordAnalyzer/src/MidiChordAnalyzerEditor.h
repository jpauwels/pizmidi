/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  18 Aug 2012 11:12:24am

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MIDICHORDANALYZEREDITOR_MIDICHORDANALYZEREDITOR_E48551AA__
#define __JUCER_HEADER_MIDICHORDANALYZEREDITOR_MIDICHORDANALYZEREDITOR_E48551AA__

//[Headers]     -- You can add your own extra header files here --
#include "MidiChordAnalyzer.h"
#include "../../common/ChannelSlider.h"
#include "../../common/VSTSlider.h"
#include "../../common/LookAndFeel.h"

typedef class MidiChordAnalyzerEditor;
class ChordAnalyzerKeyboardComponent : public MidiKeyboardComponent
{
public:
	ChordAnalyzerKeyboardComponent(MidiKeyboardState& kbstate, MidiChordAnalyzer* ownerFilter)
		: MidiKeyboardComponent(kbstate,MidiKeyboardComponent::horizontalKeyboard),
		owner(0)
	{
		owner = ownerFilter;
		s = &kbstate;
		this->setMidiChannel(1);
		this->setLowestVisibleKey(36);
	}
	~ChordAnalyzerKeyboardComponent() {};

private:
	MidiChordAnalyzer* owner;
	MidiKeyboardState* s;

	bool mouseDownOnKey(int midiNoteNumber, const MouseEvent &e) {
		MidiChordAnalyzerEditor* editor = ((MidiChordAnalyzerEditor*)(this->getParentComponent()));
		if (e.mods.isPopupMenu()) {
			s->allNotesOff(this->getMidiChannel());
			return false;
		}
		else {
			if (s->isNoteOn(this->getMidiChannel(),midiNoteNumber)) {
				s->noteOff(this->getMidiChannel(),midiNoteNumber);
			}
			else {
				s->noteOn(this->getMidiChannel(),midiNoteNumber,1.f);
			}
			return false;
		}
		return true;
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
class MidiChordAnalyzerEditor  : public AudioProcessorEditor,
                                 public ChangeListener,
                                 public ButtonListener,
                                 public SliderListener
{
public:
    //==============================================================================
    MidiChordAnalyzerEditor (MidiChordAnalyzer* const ownerFilter);
    ~MidiChordAnalyzerEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	friend class ChordAnalyzerKeyboardComponent;
	void changeListenerCallback (ChangeBroadcaster* source);
    void mouseDown (const MouseEvent& e);
    void mouseDoubleClick (const MouseEvent& e);
	void mouseUp (const MouseEvent& e);
	String const getCurrentChordName(int channel);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);

    // Binary resources:
    static const char* snake_gif;
    static const int snake_gifSize;


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TooltipWindow tooltipWindow;
    void updateParametersFromFilter();

    MidiChordAnalyzer* getFilter() const throw()       { return (MidiChordAnalyzer*) getAudioProcessor(); }
    //[/UserVariables]

    //==============================================================================
    Label* chordNameLabel;
    ChordAnalyzerKeyboardComponent* chordKeyboard;
    PizButton* pizButton;
    ToggleButton* flatsButton;
    TextButton* copyButton;
    ChannelSlider* learnChanSlider;
    Label* versionLabel;
    Image cachedImage_snake_gif;
    Path internalPath1;
    Path internalPath2;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MidiChordAnalyzerEditor (const MidiChordAnalyzerEditor&);
    const MidiChordAnalyzerEditor& operator= (const MidiChordAnalyzerEditor&);
};


#endif   // __JUCER_HEADER_MIDICHORDANALYZEREDITOR_MIDICHORDANALYZEREDITOR_E48551AA__
