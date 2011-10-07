#ifndef MIDIPADS_DRAWABLEPAD_H
#define MIDIPADS_DRAWABLEPAD_H

#include "juce_amalgamated.h"
class DrawablePad  : public Button
{
public:
    //==============================================================================
    DrawablePad (const String& buttonName);
    ~DrawablePad();

    //==============================================================================
    void setImages (const Drawable* normalImage,
                    const Drawable* overImage = 0,
                    const Drawable* downImage = 0,
                    const Drawable* disabledImage = 0,
                    const Drawable* normalImageOn = 0,
                    const Drawable* overImageOn = 0,
                    const Drawable* downImageOn = 0,
                    const Drawable* disabledImageOn = 0);


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


    String Label;

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
    Drawable* overImage;
    Drawable* downImage;
    Drawable* disabledImage;
    Drawable* normalImageOn;
    Drawable* overImageOn;
    Drawable* downImageOn;
    Drawable* disabledImageOn;
    Colour backgroundOff, backgroundOn;
    void deleteImages();
    DrawablePad (const DrawablePad&);
    const DrawablePad& operator= (const DrawablePad&);
};

#endif

