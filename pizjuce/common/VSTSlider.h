#ifndef Piz_VSTSlider_h
#define Piz_VSTSlider_h

#include "JuceHeader.h"

class VSTSlider : public Slider
{
public:
    VSTSlider(String name);
    ~VSTSlider();
    const String getTextFromValue (double value);
    void setOwner(AudioProcessor*, int);
    float mapToVSTRange();
    void setVSTSlider(float x);
private:
    AudioProcessor* ownerPlugin;
    int vstIndex;
};
#endif
