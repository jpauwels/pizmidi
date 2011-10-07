#pragma once


#include "JuceHeader.h"

class ZoomingShiftingComponent;

class ZoomableShiftableComponent : public juce::Component {
  public:
    virtual Rectangle<int> getOriginalBounds() = 0;

    virtual void setOriginalBounds(const Rectangle<int> bounds);

    //returns
    float getZoomFactorX();

    //returns
    float getZoomFactorY();

    //calcu
    void rePosition();


  private:
    ZoomingShiftingComponent* zoomingComponent;


  public:
    void setZoomer(ZoomingShiftingComponent * zoomer);

    void refreshOriginalBounds();

};

