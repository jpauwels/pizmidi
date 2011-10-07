#pragma once


#include "ModuleGUI.h"
#include "JuceHeader.h"

class Cursor;

class CursorGUI : public ModuleGUI, public juce::ChangeListener {
  private:
    juce::ComponentDragger dragger;


  public:
    void paint(Graphics & g);

    CursorGUI(Cursor * cursor);

    void mouseDown(const MouseEvent & e);

    void mouseDrag(const MouseEvent & e);

    void mouseUp(const MouseEvent & e);

    virtual void changeListenerCallback(void* objectThatHasChanged);


  private:
    Cursor* cursor;


  public:
    ~CursorGUI();

};

