#ifndef Piz_VSTSlider_h
#define Piz_VSTSlider_h

#include "JuceHeader.h"

class VSTSlider : public Slider
{
public:
    VSTSlider(AudioProcessor*,int);
    ~VSTSlider();
    const String getTextFromValue (double value);
    void setOwner(AudioProcessor*, int);
private:
    AudioProcessor* owner;
    int vstIndex;
};
#endif
