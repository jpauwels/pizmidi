#pragma once
#include "TextBoxSlider.h"

#include "JuceHeader.h"

class Controller;
class MidiMorph;
namespace juce { class TextEditor; } 
namespace juce { class Slider; } 
class ControllerValue;
class TextBoxSlider;
namespace juce { class Label; } 

class ControllerGUI : public juce::TextEditorListener, public juce::ChangeListener, public juce::Component, public juce::SliderListener, public juce::LabelListener {
  public:
    ControllerGUI(Controller * controller, MidiMorph * core);

    ~ControllerGUI();


  private:
    bool isSelected;

    Controller* controller;

    MidiMorph* core;

    juce::TextEditor* name;


  public:
    void resized();

    void paint(Graphics & g);

    void paintOverChildren(Graphics & g);

    void mouseUp(const MouseEvent & e);

    //()=
    void sliderValueChanged(Slider* slider);

    void setSelected(bool shouldDrawSelected);

    void changeListenerCallback(void* objectThatHasChanged);

    void refreshControllerData();

    virtual void textEditorTextChanged(TextEditor& editor);

    //  (       ) 
    virtual void textEditorReturnKeyPressed(TextEditor & editor);

    virtual void textEditorEscapeKeyPressed(TextEditor & editor);

    virtual void textEditorFocusLost(TextEditor & editor);


  private:
    TextBoxSlider* test;

    TextBoxSlider* ccNo;


  public:
    void labelTextChanged(Label * labelThatHasChanged);


  private:
    TextBoxSlider* channel;

    TextBoxSlider* value;

    juce::Label* labCc;

    juce::Label* labCh;

    juce::Colour lineColour;

};

