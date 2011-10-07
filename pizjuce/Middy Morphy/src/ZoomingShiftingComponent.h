#pragma once


#include "JuceHeader.h"
#include "Origin.h"

namespace juce { class XmlElement; } 
class ZoomableShiftableComponent;

class ZoomingShiftingComponent : public juce::Component {
  public:
    juce::XmlElement* getXml(const String tagName);

    void setFromXml(juce::XmlElement * data);

    void dragOrigin(const MouseEvent & e);

    void startDragOrigin();


  private:
    Origin origin;


  public:
    void zoom(float multX, float multY, float x, float y);

    //drag the origin around
    //call the reArrangeChildren
    void shift(const juce::Point<int> newPosition);

    //call all childrens reposition method
    void rePositionChildren();

    float getXOffset();

    float getYOffset();


  private:
    float zoomFactorX;

    float zoomFactorY;

    OwnedArray<ZoomableShiftableComponent> zoomedComponents;


  public:
    float getZoomFactorX();

    float getZoomFactorY();

    void childBoundsChanged(juce::Component * component);


  private:
    juce::ComponentDragger dragger;


  public:
    ZoomingShiftingComponent();

    void deleteAllZoomedComps();

    void addZoomedComp(ZoomableShiftableComponent * zsComp, bool doZoom =true);

    void removeZoomedComp(ZoomableShiftableComponent * comp);

};

