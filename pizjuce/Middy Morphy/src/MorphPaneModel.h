#pragma once


#include "ModulePaneModel.h"
#include "ModuleGUI.h"
#include "JuceHeader.h"
#include "Scene.h"
#include "TextBoxSlider.h"

class Cursor;
class MidiMorph;
class Module;

class MorphPaneModel : public ModulePaneModel,
                       public LabelListener,
                       public Component
{
  private:
    Cursor* cursor;
    MidiMorph* core;
    TextBoxSlider* rateBox;

  public:
    MorphPaneModel(MidiMorph * core);

    virtual int getNumModules();

    void mouseDown(const MouseEvent & e);
    void mouseUp(const MouseEvent & e);
    void mouseDrag(const MouseEvent & e);
    
    virtual Module* getModule(int index);
    virtual ModuleGUI* createGUI(int index);

    void selectionChanged(const Array<ModuleGUI*> & modules);

    void labelTextChanged(Label * labelThatHasChanged);
};

