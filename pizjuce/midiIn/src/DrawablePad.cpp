#include "DrawablePad.h"

//==============================================================================
DrawablePad::DrawablePad (const String& name)
    : Button (name),
      //buttonState(buttonNormal),
      normalImage (0),
      overImage (0),
      downImage (0),
      disabledImage (0),
      normalImageOn (0),
      overImageOn (0),
      downImageOn (0),
      disabledImageOn (0)
{
    setSize (200, 200);
    backgroundOff = Colour (0xffbbbbff);
    backgroundOn = Colour (0xff3333ff);
    Label = T("Pad");
    setMouseClickGrabsKeyboardFocus (false);
}

DrawablePad::~DrawablePad()
{
    deleteImages();
}

void DrawablePad::deleteImages() 
{
    if (normalImage) deleteAndZero (normalImage);
    deleteAndZero (overImage);
    deleteAndZero (downImage);
    deleteAndZero (disabledImage);
    deleteAndZero (normalImageOn);
    deleteAndZero (overImageOn);
    deleteAndZero (downImageOn);
    deleteAndZero (disabledImageOn);
}

void DrawablePad::setImages (const Drawable* normal,
                     const Drawable* over,
                     const Drawable* down,
                     const Drawable* disabled,
                     const Drawable* normalOn,
                     const Drawable* overOn,
                     const Drawable* downOn,
                     const Drawable* disabledOn)
{
    deleteImages();

    jassert (normal != 0); // you really need to give it at least a normal image..

    if (normal != 0) normalImage = normal->createCopy();
    if (over != 0) overImage = over->createCopy();
    if (down != 0) downImage = down->createCopy();
    if (disabled != 0) disabledImage = disabled->createCopy();
    if (normalOn != 0) normalImageOn = normalOn->createCopy();
    if (overOn != 0) overImageOn = overOn->createCopy();
    if (downOn != 0) downImageOn = downOn->createCopy();
    if (disabledOn != 0) disabledImageOn = disabledOn->createCopy();

    repaint();
}

void DrawablePad::setBackgroundColours (const Colour& toggledOffColour,
                                const Colour& toggledOnColour)
{
    if (backgroundOff != toggledOffColour
         || backgroundOn != toggledOnColour)
    {
        backgroundOff = toggledOffColour;
        backgroundOn = toggledOnColour;

        repaint();
    }
}

const Colour& DrawablePad::getBackgroundColour() const throw()
{
    return getToggleState() ? backgroundOn
                            : backgroundOff;
}

void DrawablePad::drawButtonBackground (Graphics& g,
                                Button& button,
                                const Colour& backgroundColour,
                                bool isMouseOverButton,
                                bool isButtonDown)
{
}

void DrawablePad::paintButton (Graphics& g, bool isMouseOverButton, bool isButtonDown)
{
    Rectangle<int> imageSpace;
    const int insetX = getWidth() / 100;
    const int insetY = getHeight() / 100;
    imageSpace.setBounds (insetX, insetY, getWidth() - insetX * 2, getHeight() - insetY * 2);

    g.setImageResamplingQuality (Graphics::highResamplingQuality);
    g.setOpacity (1.0f);

    const Drawable* imageToDraw = 0;

    if (isEnabled())
    {
        imageToDraw = getCurrentImage();
    }
    else
    {
        imageToDraw = getToggleState() ? disabledImageOn
                                       : disabledImage;

        if (imageToDraw == 0)
        {
            g.setOpacity (0.4f);
            imageToDraw = getNormalImage();
        }
    }

    if (imageToDraw != 0)
    {
		g.fillAll(Colours::transparentBlack);
        imageToDraw->drawWithin (g,
                                 imageSpace.getX(),
                                 imageSpace.getY(),
                                 imageSpace.getWidth(),
                                 imageSpace.getHeight(),
                                 RectanglePlacement::centred,
								 1.f);
    }
	else 
	{
		g.fillAll(getBackgroundColour());
	//	g.setColour (getBackgroundColour().contrasting(0.8f));
	//	g.setFont (Font (9.f, Font::bold));
	//	g.drawText (Label,
	//				proportionOfWidth (0.0447f), proportionOfHeight (0.0499f), proportionOfWidth (0.9137f), proportionOfHeight (0.9137f),
	//				Justification::centred, true);
	}
}
void DrawablePad::resized() {
}

const Drawable* DrawablePad::getCurrentImage() const throw()
{
    if (isDown())
        return getDownImage();

    if (isOver())
        return getOverImage();

    return getNormalImage();
}

const Drawable* DrawablePad::getNormalImage() const throw()
{
    return (getToggleState() && normalImageOn != 0) ? normalImageOn
                                                    : normalImage;
}

const Drawable* DrawablePad::getOverImage() const throw()
{
    const Drawable* d = normalImage;

    if (getToggleState())
    {
        if (overImageOn != 0)
            d = overImageOn;
        else if (normalImageOn != 0)
            d = normalImageOn;
        else if (overImage != 0)
            d = overImage;
    }
    else
    {
        if (overImage != 0)
            d = overImage;
    }

    return d;
}

const Drawable* DrawablePad::getDownImage() const throw()
{
    const Drawable* d = normalImage;

    if (getToggleState())
    {
        if (downImageOn != 0) d = downImageOn;
        else if (overImageOn != 0) d = overImageOn;
        else if (normalImageOn != 0) d = normalImageOn;
        else if (downImage != 0) d = downImage;
        else d = getOverImage();
    }
    else
    {
        if (downImage != 0) d = downImage;
        else d = getOverImage();
    }

    return d;
}
