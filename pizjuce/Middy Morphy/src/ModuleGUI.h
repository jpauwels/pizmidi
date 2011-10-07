#pragma once


#include "ZoomableShiftableComponent.h"
#include "JuceHeader.h"

class Module;
class ModulePane;

class ModuleGUI : public ZoomableShiftableComponent {
  public:
    ModuleGUI(Module * module);


  private:
    bool selectionBool;

    Module* module;

    juce::ComponentDragger dragger;

    ModulePane* pane;


  public:
    void mouseDrag(const MouseEvent & e);

    void mouseUp(const MouseEvent & e);

    void mouseDown(const MouseEvent & e);

    virtual void setOriginalBounds(const Rectangle<int> bounds);

    virtual Rectangle<int> getOriginalBounds();

    void paint(Graphics & g);

    void setPane(ModulePane * pane);

    void startDrag();

    void drag(const MouseEvent & e);

    bool isSelected();

    Module* getModule();

};

