#pragma once


#include "JuceHeader.h"

namespace juce { class TextEditor; } 
class NumberBox;
namespace juce { class String; } 

class TextBoxSlider : public juce::LabelListener, public juce::Label {
  public:
    void mouseDrag(const MouseEvent & e);

    void labelTextChanged(Label * labelThatHasChanged);

    TextBoxSlider(double initval);

    ~TextBoxSlider();

    void mouseDown(const MouseEvent & e);
    void mouseUp(const MouseEvent & e);


  private:
    int pixelStep;

    double oldValue;

    double value;

    double min;

    double max;

    double step;


  public:
    void setRange(double min, double max, double stepsize, int pixelPerStep);

    juce::TextEditor* createEditorComponent();

    void paintOverChildren(Graphics & g);

    double getValue();


  private:
    // (const String& newText,                       const bool broadcastChangeMessage)
    void setText(const String & newText, const bool broadcastChangeMessage);


  public:
    void setValue(double newVal, bool broadcastChange);

    void resized();

    void textWasEdited();

};

