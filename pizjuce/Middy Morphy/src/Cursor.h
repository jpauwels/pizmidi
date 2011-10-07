#pragma once


#include "Module.h"
#include "JuceHeader.h"

class MidiMorph;

class Cursor : public Module, public juce::ChangeBroadcaster {
  public:
    Cursor(MidiMorph * core);

    //gets called when the XYItem gets new coordinates
    virtual void moved();


  private:
    MidiMorph* core;


  public:
    juce::Point<float> getCursorPosition();

};

