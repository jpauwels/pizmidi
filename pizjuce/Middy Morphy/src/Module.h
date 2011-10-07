#pragma once


#include "XYItem.h"

class Module : public XYItem {
  public:
    virtual void mouseDown(const MouseEvent & e );

    virtual void mouseDrag(const MouseEvent &);

    virtual void mouseUp(const MouseEvent & e);

    Colour colour;

    String name;

    int size;

};

