#pragma once


#include "JuceHeader.h"

namespace juce { class TextEditor; } 
namespace juce { class String; } 
namespace juce { class Colour; } 
namespace juce { class Component; } 

class D3CKLook : public juce::LookAndFeel {
  public:
    int getDefaultScrollbarWidth();

    //    int  thumbSize,      bool  isMouseOver,      bool  isMouseDown    )   
    void drawScrollbar(Graphics & g, ScrollBar & scrollbar, int x, int y, int width, int height, bool isScrollbarVertical, int thumbStartPosition, int thumbSize, bool isMouseOver, bool isMouseDown);

    void drawScrollbarButton(Graphics & g, ScrollBar & scrollbar, int width, int height, int buttonDirection, bool isScrollbarVertical, bool isMouseOver, bool isButtonDown);

    //  (   &     ) 
    int getScrollbarButtonSize(ScrollBar & scrollbar);

    //getMinimumScrollbarThumbSize  (   &     ) 
    int getMinimumScrollbarThumbSize(ScrollBar & scrollbar);

    //  (   &  g,      int  width,      int  height,      TextEditor &  textEditor    )   
    void drawTextEditorOutline(Graphics & g, int width, int height, juce::TextEditor & textEditor);

    void drawPopupMenuItem(Graphics & g, int width, int height, bool isSeperator, bool isActive, bool isHightlited, bool isTicked, bool hasSubmenu, const String & text, const String & shortcutText, Image * image, const juce::Colour *const textColour);

    void drawPopupMenuBackground(Graphics & g, int width, int height);

    DropShadower* createDropShadowerForComponent(juce::Component * comp);

};

