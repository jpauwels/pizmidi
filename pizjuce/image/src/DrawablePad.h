#ifndef imagePluginFilter_DRAWABLEPAD_H
#define imagePluginFilter_DRAWABLEPAD_H

#include "JuceHeader.h"
class DrawablePad  : public Button
{
public:
    //==============================================================================
    DrawablePad (const String& buttonName);
    ~DrawablePad();

    //==============================================================================
    void setImages (File file);
    void deleteImages();


    //==============================================================================
    void setBackgroundColours (const Colour& toggledOffColour,
                               const Colour& toggledOnColour);

    const Colour& getBackgroundColour() const throw();

    //==============================================================================
    /** Returns the image that the button is currently displaying. */
    const Drawable* getCurrentImage() const throw();
    const Drawable* getNormalImage() const throw();
    const Drawable* getOverImage() const throw();
    const Drawable* getDownImage() const throw();

    //==============================================================================
    juce_UseDebuggingNewOperator

protected:
    /** @internal */
    void drawButtonBackground (Graphics& g,
                               Button& button,
                               const Colour& backgroundColour,
                               bool isMouseOverButton,
                               bool isButtonDown);

    void paintButton (Graphics& g,
                      bool isMouseOverButton,
                      bool isButtonDown);
    void resized();





private:
    //==============================================================================
    Drawable* normalImage;
    Colour backgroundOff, backgroundOn;
    DrawablePad (const DrawablePad&);
    const DrawablePad& operator= (const DrawablePad&);
};

#endif