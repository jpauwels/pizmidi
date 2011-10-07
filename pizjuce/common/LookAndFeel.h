#ifndef __MIDILOOPER_LOOKANDFEEL_HEADER__
#define __MIDILOOPER_LOOKANDFEEL_HEADER__

#include "JuceHeader.h"

class NonShinyLookAndFeel : public LookAndFeel
{
public:
    //==============================================================================
    NonShinyLookAndFeel();
    virtual ~NonShinyLookAndFeel();

	virtual void getTooltipSize (const String& tipText, int& width, int& height);
	virtual void drawTooltip (Graphics& g, const String& text, int width, int height);

    //==============================================================================
    virtual void drawButtonBackground (Graphics& g,
                                       Button& button,
                                       const Colour& backgroundColour,
                                       bool isMouseOverButton,
                                       bool isButtonDown);


	virtual void drawButtonText (Graphics& g, TextButton& button,
                                  bool /*isMouseOverButton*/, bool /*isButtonDown*/);

	virtual void drawToggleButton (Graphics& g,
                                   ToggleButton& button,
                                   bool isMouseOverButton,
                                   bool isButtonDown);

    virtual void drawTickBox (Graphics& g,
                              Component& component,
                              float x, float y, float w, float h,
                              bool ticked,
                              bool isEnabled,
                              bool isMouseOverButton,
                              bool isButtonDown);

    //==============================================================================
    virtual void drawTextEditorOutline (Graphics& g,
                                        int width, int height,
                                        TextEditor& textEditor);

    //==============================================================================
    /** Fills the background of a popup menu component. */
    virtual void drawPopupMenuBackground (Graphics& g, int width, int height);

    virtual void drawMenuBarBackground (Graphics& g, int width, int height,
                                        bool isMouseOverBar,
                                        MenuBarComponent& menuBar);
	const Font getPopupMenuFont();
    //==============================================================================
    virtual void drawComboBox (Graphics& g, int width, int height,
                               bool isButtonDown,
                               int buttonX, int buttonY,
                               int buttonW, int buttonH,
                               ComboBox& box);

    virtual const Font getComboBoxFont (ComboBox& box);

    //==============================================================================
    virtual void drawLinearSlider (Graphics& g,
                                   int x, int y,
                                   int width, int height,
                                   float sliderPos,
                                   float minSliderPos,
                                   float maxSliderPos,
                                   const Slider::SliderStyle style,
                                   Slider& slider);

    virtual Button* createSliderButton (bool isIncrement);
    virtual Label* createSliderTextBox (Slider& slider);

    //==============================================================================
    virtual void drawCornerResizer (Graphics& g,
                                    int w, int h,
                                    bool isMouseOver,
                                    bool isMouseDragging);

	//==============================================================================
    /** Utility function to draw a shiny, glassy circle (for round LED-type buttons). */
    static void drawGlassSphere (Graphics& g,
                                 float x, float y,
                                 float diameter,
                                 const Colour& colour,
                                 float outlineThickness) throw();

    static void drawGlassPointer (Graphics& g,
                                  float x, float y,
                                  float diameter,
                                  const Colour& colour, float outlineThickness,
                                  int direction) throw();

    /** Utility function to draw a shiny, glassy oblong (for text buttons). */
    static void drawGlassLozenge (Graphics& g,
                                  float x, float y,
                                  float width, float height,
                                  const Colour& colour,
                                  float outlineThickness,
                                  float cornerSize,
                                  bool flatOnLeft, bool flatOnRight,
                                  bool flatOnTop, bool flatOnBottom) throw();

    //==============================================================================
    juce_UseDebuggingNewOperator


private:

    void drawShinyButtonShape (Graphics& g,
                               float x, float y, float w, float h, float maxCornerSize,
                               const Colour& baseColour,
                               float strokeWidth,
                               bool flatOnLeft,
                               bool flatOnRight,
                               bool flatOnTop,
                               bool flatOnBottom) throw();

    NonShinyLookAndFeel (const NonShinyLookAndFeel&);
    NonShinyLookAndFeel& operator= (const NonShinyLookAndFeel&);
};


#endif
