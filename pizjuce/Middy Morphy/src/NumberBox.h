#pragma once


#include "JuceHeader.h"

class NumberBox : public juce::TextEditor {
  public:
    // Component::keyPressed  (  const KeyPress &  key   ) 
    bool keyPressed(const KeyPress & key);

};

