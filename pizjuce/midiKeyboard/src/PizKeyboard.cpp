#include "PizKeyboard.h"
#include "PizKeyboardEditor.h"

bool PizKeyboard::isCapsLockOn()
{
#if JUCE_WIN32
	return (GetKeyState(VK_CAPITAL) & 0x0001)!=0;
#elif JUCE_MAC
	return true;
#elif JUCE_LINUX
	return true;
#endif
}

//==============================================================================
/**
    This function must be implemented to create a new instance of your
    plugin object.
*/
PizAudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PizKeyboard();
}

//==============================================================================
PizKeyboard::PizKeyboard()
{
	DBG("PizKeyboard()");
    if (!loadDefaultFxb())
	{
		keyPosition=48;
		width = 0.25f;
		velocity = 1.f;
		useY = false;
		channel = 0;
		octave = 4;
		toggle = false;
		hide = false;
		usepc = false;
		qwerty = false;
		capslock = false;
		//sendnotesonpc = true;
		lastUIWidth = 560;
		lastUIHeight = 140;
	}
	sendHeldNotes=false;
	clearHeldNotes=false;
	lastProgram=0;
	curProgram=0;

	ccqwertyState[0] = KeyPress::isKeyCurrentlyDown(KeyPress::tabKey);
	ccqwertyState[1] = KeyPress::isKeyCurrentlyDown(KeyPress::createFromDescription("`").getKeyCode());
	ccState[0] = false;
	ccState[1] = false;
	for (int i = keymapLength; --i >= 0;) 
		qwertyState[i] = KeyPress::isKeyCurrentlyDown(keymap[i]);
}

PizKeyboard::~PizKeyboard()
{
	DBG("~PizKeyboard()");
}

//==============================================================================
const String PizKeyboard::getName() const
{
    return "midiKeyboard";
}

int PizKeyboard::getNumParameters()
{
    return numParams;
}

float PizKeyboard::getParameter (int index)
{
    switch (index)
    {
    case kWidth: return width;
    case kVelocity: return velocity;
    case kUseY: return useY ? 1.f : 0.f;
    case kChannel: return ((float)channel)/15.f;
	case kToggleInput: return toggle ? 1.f : 0.f;
	case kHidePanel: return hide ? 1.f : 0.f;
	case kQwertyAnywhere: return qwerty ? 1.f : 0.f;
	case kCapsLock: return capslock ? 1.f : 0.f;
	case kUseProgCh: return usepc ? 1.f : 0.f;
	case kSendHeldNotes: return 0.f;
	case kClearHeldNotes: return 0.f;
    default: return 0.0f;
    }
}

void PizKeyboard::setParameter (int index, float newValue)
{
    if (index == kWidth)
    {
        if (width != newValue)
        {
            width = newValue;
            sendChangeMessage ();
        }
    }
    else if (index==kChannel)
    {
        channel = roundFloatToInt(newValue*15.f);
        sendChangeMessage();
    }
    else if (index==kVelocity)
    {
        velocity = newValue;
        sendChangeMessage();
    }
    else if (index==kUseY)
    {
        useY = newValue>=0.5f;
        sendChangeMessage();
    }
    else if (index==kToggleInput)
    {
        toggle = newValue>=0.5f;
        sendChangeMessage();
    }
    else if (index==kHidePanel)
    {
        hide = newValue>=0.5f;
        sendChangeMessage();
    }
    else if (index==kQwertyAnywhere)
    {
        qwerty = newValue>=0.5f;
        sendChangeMessage();
    }
    else if (index==kCapsLock)
    {
        capslock = newValue>=0.5f;
        sendChangeMessage();
    }
    else if (index==kUseProgCh)
    {
        usepc = newValue>=0.5f;
        sendChangeMessage();
    }
	else if (index==kSendHeldNotes)
		if (newValue) sendHeldNotes=true;

	else if (index==kClearHeldNotes)
		if (newValue) clearHeldNotes=true;
}

const String PizKeyboard::getParameterName (int index)
{
    if (index == kWidth)
        return T("KeyWidth");
    else if (index == kChannel)
        return T("Channel");
    if (index == kVelocity)
        return T("Velocity");
    if (index == kUseY)
        return T("Use Y");
	if (index == kToggleInput)
		return T("Toggle");
	if (index == kHidePanel)
		return T("HidePanel");
	if (index == kQwertyAnywhere)
		return T("QwertyAnywhere");
	if (index == kCapsLock)
		return T("UseCapsLock");
	if (index == kUseProgCh)
		return T("UseProgCh");
	if (index == kSendHeldNotes)
		return T("SendHeldNotes");
	if (index == kClearHeldNotes)
		return T("Reset");
    return String::empty;
}

const String PizKeyboard::getParameterText (int index)
{
    if (index == kWidth)
        return String (width, 2);
    if (index == kChannel)
        return String(channel+1);
    if (index == kVelocity)
        return String (roundFloatToInt(velocity*127.f));
    if (index == kUseY)
        return useY ? "Yes" : "No";
	if (index == kToggleInput)
		return toggle ? "On" : "Off";
	if (index == kHidePanel)
		return toggle ? "Hidden" : "Showing";
	if (index == kQwertyAnywhere)
		return toggle ? "On" : "Off";
	if (index == kCapsLock)
		return capslock ? "On" : "Off";
    if (index == kUseProgCh)
        return usepc ? "Yes" : "No";
	if (index == kSendHeldNotes)
		return "--->";
	if (index == kClearHeldNotes)
		return "--->";
    return String::empty;
}

const String PizKeyboard::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String PizKeyboard::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool PizKeyboard::isInputChannelStereoPair (int index) const
{
    return true;
}

bool PizKeyboard::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool PizKeyboard::acceptsMidi() const
{
    return true;
}

bool PizKeyboard::producesMidi() const
{
    return true;
}

//==============================================================================
void PizKeyboard::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // do your pre-playback setup stuff here..
}

void PizKeyboard::releaseResources()
{
    // when playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void PizKeyboard::processBlock (AudioSampleBuffer& buffer,
                                MidiBuffer& midiMessages)
{
	MidiBuffer output;
	if (lastProgram!=curProgram)
	{
		for (int ch=0;ch<16;ch++) 
		{
			for (int n=0;n<128;n++)
			{
				if (progKbState[lastProgram].isNoteOn(ch,n)) {
					editorKbState.noteOff(ch,n);
				}
			}
		}
		for (int ch=0;ch<16;ch++) 
		{
			for (int n=0;n<128;n++)
			{
				if (progKbState[curProgram].isNoteOn(ch,n)) {
					editorKbState.noteOn(ch,n,velocity);
				}
			}
		}
		lastProgram = curProgram;
		sendChangeMessage();
	}
	if (clearHeldNotes)
	{
		clearHeldNotes=false;
		for (int ch=0;ch<16;ch++) 
		{
			for (int n=0;n<128;n++)
			{
				if (progKbState[curProgram].isNoteOn(ch,n))
					output.addEvent(MidiMessage::noteOff(ch,n),0);
			}
		}
		progKbState[curProgram].reset();
		editorKbState.reset();
		sendChangeMessage();
	}
	if (sendHeldNotes)
	{
		sendHeldNotes=false;
		for (int ch=0;ch<16;ch++) 
		{
			for (int n=0;n<128;n++)
			{
				if (progKbState[curProgram].isNoteOn(ch,n))
					output.addEvent(MidiMessage::noteOn(ch,n,velocity),0);
			}
		}
	}

	if (qwerty && (!capslock || isCapsLockOn()))
	{
		////tab key toggles CC 1
		//if (ccqwertyState[0] != KeyPress::isKeyCurrentlyDown(KeyPress::tabKey)) {
		//	ccqwertyState[0] = KeyPress::isKeyCurrentlyDown(KeyPress::tabKey);
		//	if (ccqwertyState[0])
		//	{
		//		midiMessages.addEvent(MidiMessage::controllerEvent(channel+1,1,ccState[0] ? 0 : 127),0);
		//		ccState[0] = !ccState[0];
		//	}
		//}
		////` is sustain pedal
		//if (ccqwertyState[1] != KeyPress::isKeyCurrentlyDown(96)) {
		//	ccqwertyState[1] = KeyPress::isKeyCurrentlyDown(96);
		//	midiMessages.addEvent(MidiMessage::controllerEvent(channel+1,64,ccqwertyState[1] ? 127 : 0),0);
		//}
		for (int i = keymapLength; --i >= 0;) {
			if (qwertyState[i] != KeyPress::isKeyCurrentlyDown(keymap[i]))
			{
				const int note = 12 * octave + i;
				if (KeyPress::isKeyCurrentlyDown(keymap[i]) != progKbState[curProgram].isNoteOn(channel+1,note)
					&& !ModifierKeys::getCurrentModifiers().isAnyModifierKeyDown())
				{
					if (KeyPress::isKeyCurrentlyDown(keymap[i])) {
						editorKbState.noteOn(channel+1,note,ModifierKeys::getCurrentModifiers().isShiftDown() ? 127 : velocity);
					}
					else if (!toggle) {
						editorKbState.noteOff(channel+1,note);
					}
				}
				else if (toggle && KeyPress::isKeyCurrentlyDown(keymap[i]) && progKbState[curProgram].isNoteOn(channel+1,note))
				{
					editorKbState.noteOff(channel+1,note);
				}
				qwertyState[i] = KeyPress::isKeyCurrentlyDown(keymap[i]);
			}
		}
	}

	if (toggle)
	{
		MidiBuffer::Iterator mid_buffer_iter(midiMessages);
		MidiMessage m(0xf0);
		int sample;
		while(mid_buffer_iter.getNextEvent(m,sample)) {
			if (m.isForChannel(channel+1))
			{
				if (m.isNoteOn()) {
					if (progKbState[curProgram].isNoteOn(m.getChannel(),m.getNoteNumber()))
						output.addEvent(MidiMessage::noteOff(m.getChannel(),m.getNoteNumber()),sample);
					else 
						output.addEvent(m,sample);
				}
				else if (!m.isNoteOff())
					output.addEvent(m,sample);
				else if (m.isProgramChange() && usepc)
				{
					setCurrentProgram(m.getProgramChangeNumber());
					if (lastProgram!=curProgram)
					{
						for (int ch=0;ch<16;ch++) 
						{
							for (int n=0;n<128;n++)
							{
								if (progKbState[lastProgram].isNoteOn(ch,n)) 
									output.addEvent(MidiMessage::noteOff(ch,n),sample);
							}
						}
						editorKbState.reset();
						for (int ch=0;ch<16;ch++) 
						{
							for (int n=0;n<128;n++)
							{
								if (progKbState[curProgram].isNoteOn(ch,n)) {
									editorKbState.noteOn(ch,n,velocity);
									output.addEvent(MidiMessage::noteOn(ch,n,velocity),sample);
								}
							}
						}
						lastProgram = curProgram;
						sendChangeMessage();
					}
				}
			}
		}
	}
	else output = midiMessages;

	editorKbState.processNextMidiBuffer(output,0,buffer.getNumSamples(),true);
	progKbState[curProgram].processNextMidiBuffer (output,0, buffer.getNumSamples(),false);
	midiMessages.clear();
	midiMessages = output;

    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
AudioProcessorEditor* PizKeyboard::createEditor()
{
    return new midiKeyboardEditor (this);
}

//==============================================================================
void PizKeyboard::getStateInformation (MemoryBlock& destData)
{
    // you can store your parameters as binary data if you want to or if you've got
    // a load of binary to put in there, but if you're not doing anything too heavy,
    // XML is a much cleaner way of doing it - here's an example of how to store your
    // params as XML..

    // create an outer XML element..
    XmlElement xmlState (T("MYPLUGINSETTINGS"));

    // add some attributes to it..
    xmlState.setAttribute (T("pluginVersion"), 2);

    xmlState.setAttribute (T("keyWidth"), width);
    xmlState.setAttribute (T("velocity"), velocity);
    xmlState.setAttribute (T("useY"), useY);
    xmlState.setAttribute (T("channel"), channel);
    xmlState.setAttribute (T("toggle"), toggle);
    xmlState.setAttribute (T("hide"), hide);
    xmlState.setAttribute (T("usepc"), usepc);

    xmlState.setAttribute (T("qwerty"), qwerty);
    xmlState.setAttribute (T("octave"), octave);
    xmlState.setAttribute (T("keyPosition"), keyPosition);
    xmlState.setAttribute (T("uiWidth"), lastUIWidth);
    xmlState.setAttribute (T("uiHeight"), lastUIHeight);

    // you could also add as many child elements as you need to here..


    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xmlState, destData);
}

void PizKeyboard::setStateInformation (const void* data, int sizeInBytes)
{
    // use this helper function to get the XML from this binary blob..
    ScopedPointer<XmlElement> xmlState = getXmlFromBinary (data, sizeInBytes);

    if (xmlState != 0)
    {
        // check that it's the right type of xml..
        if (xmlState->hasTagName (T("MYPLUGINSETTINGS")))
        {
            // ok, now pull out our parameters..
            width = (float) xmlState->getDoubleAttribute (T("gainLevel"), width); //old name for compatibility
            width = (float) xmlState->getDoubleAttribute (T("keyWidth"), width);
            velocity = (float) xmlState->getDoubleAttribute (T("velocity"), velocity);
            channel = xmlState->getIntAttribute (T("channel"), channel);
            useY = xmlState->getBoolAttribute (T("useY"), useY);
            toggle = xmlState->getBoolAttribute (T("toggle"), toggle);
            hide = xmlState->getBoolAttribute (T("hide"), hide);
            usepc = xmlState->getBoolAttribute (T("usepc"), usepc);
            qwerty = xmlState->getBoolAttribute (T("qwerty"), qwerty);
			keyPosition = xmlState->getIntAttribute (T("keyPosition"), keyPosition);
            octave = xmlState->getIntAttribute (T("octave"), octave);
            lastUIWidth = xmlState->getIntAttribute (T("uiWidth"), lastUIWidth);
            lastUIHeight = xmlState->getIntAttribute (T("uiHeight"), lastUIHeight);
            sendChangeMessage ();
			this->dispatchPendingMessages();
        }
    }
}
