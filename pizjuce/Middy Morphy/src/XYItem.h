#pragma once


#include "JuceHeader.h"

class XYItem : public juce::Point<float> {
  public:
    float getDistance(juce::Point<float> & otherPoint);

    //gets called when the XYItem gets new coordinates
    virtual void moved();

    void setXY(float x, float y);

};

