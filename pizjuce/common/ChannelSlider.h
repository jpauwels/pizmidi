#ifndef PIZ_CHANNEL_SLIDER_HEADER
#define PIZ_CHANNEL_SLIDER_HEADER

class ChannelSlider : public Slider
{
public:
	ChannelSlider(String name) : Slider(name)
	{
		this->setRange(0,16,1);
	};
	~ChannelSlider() {};

	const String getTextFromValue(double value)
	{
		if (value<0.5) return String("Any");
		return String((int)value);
	}

	double getValueFromText(const String &text)
	{
		if (!text.compareIgnoreCase("Any")) return 0;
		return text.getDoubleValue();
	}
};

#endif