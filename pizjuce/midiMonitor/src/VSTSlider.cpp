#include "VSTSlider.h"

VSTSlider::VSTSlider(AudioProcessor* owner, int index) : Slider("VST Slider")
{
    this->owner = owner;
    this->vstIndex = index;
};

VSTSlider::~VSTSlider() {};

const String VSTSlider::getTextFromValue(double value)
{
    if (owner && vstIndex>-1) return owner->getParameterText(vstIndex);
    else return String(value)+"?";
};

void VSTSlider::setOwner(AudioProcessor* owner, int index)
{
    this->owner = owner;
    this->vstIndex = index;
};
