#pragma once


#include "JuceHeader.h"

class ZoomingShiftingComponent;

class Origin : public juce::Component {
  public:
    void paint(Graphics & g);

    Origin();

    void resized();


  private:
    ZoomingShiftingComponent* owner;


  public:
    void moved();


  private:
    float originalSize;

};

