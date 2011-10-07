#ifndef imagePluginFilter_PAD_H
#define imagePluginFilter_PAD_H

#include "juce_amalgamated.h"
#include "DrawablePad.h"

class MidiPad  : public Component,
                 public ButtonListener,
                 public FileDragAndDropTarget
{
public:
    //==============================================================================
	MidiPad ();  
    ~MidiPad();

    void paint (Graphics&);
    void resized();
    void buttonClicked (Button*);
    void filesDropped (const StringArray &files, int x, int y);
    bool isInterestedInFileDrag (const StringArray& files);
    void setButtonText (const String&);
    void setTooltip (String text);
    void setColour(const Colour&);
    void setTriggeredOnMouseDown(const bool);
    void addButtonListener (ButtonListener *const);
	void clearIcon();

    DrawablePad* drawableButton;


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
	Label* label;
    MidiPad (const MidiPad&);
    const MidiPad& operator= (const MidiPad&);
};

#endif