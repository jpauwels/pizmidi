#ifndef PIZMIDIKEYBOARDCOMPONENT_H
#define PIZMIDIKEYBOARDCOMPONENT_H

#include "JuceHeader.h"
#include "PizKeyboard.h"

class PizKeyboardComponent : public MidiKeyboardComponent
{
public:
    PizKeyboardComponent(MidiKeyboardState &state, const Orientation orientation);
	bool keyStateChanged(bool isKeyDown);
	void setKeyPressForNote (const KeyPress& key, const int midiNoteOffsetFromC)
	{
		MidiKeyboardComponent::setKeyPressForNote(key,midiNoteOffsetFromC);
		_keyPressNotes.add (midiNoteOffsetFromC);
		_keyPresses.add (key);
	}
	void setKeyPressBaseOctave(int newOctaveNumber)
	{
		baseOctave = newOctaveNumber;
		MidiKeyboardComponent::setKeyPressBaseOctave(newOctaveNumber);
		repaint();
		sendChangeMessage();
	}
	int getKeyPressBaseOctave() {return baseOctave;}
	bool toggle;
	void drawBlackNote(int midiNoteNumber, Graphics& g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour& textColour)
	{
		MidiKeyboardComponent::drawBlackNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,textColour);
		if (hasKeyboardFocus(false) || drawQwerty)
		{
			if (midiNoteNumber >= baseOctave*12 && midiNoteNumber < 32+baseOctave*12) {
				int n = midiNoteNumber - baseOctave*12;
				String key = String::charToString(keymap[n]);
				g.setColour(Colours::white.withMultipliedAlpha(0.5f));
				if (midiNoteNumber/12 == baseOctave && midiNoteNumber%12==0) {
					g.drawEllipse((float)(x+w/4),(float)(y+h-w),(float)(w/2),(float)(w/2),2.f);
				}
				g.setFont((float)(w/2),Font::bold);
				g.drawText(key,x+w/4,y+h-w,w/2,w/2,Justification::centred,false);
			}
		}
		if (drawNoteNumber) {
			Font f (jmin (12.0f, w * 0.9f));
			f.setHorizontalScale (0.8f);
			g.setFont (f);
			g.setColour (Colours::white);
			g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 4, Justification::centredBottom, 1);
		}
	}
	void drawWhiteNote(int midiNoteNumber, Graphics& g, int x, int y, int w, int h, bool isDown, bool isOver, const Colour& lineColour, const Colour& textColour)
	{
		MidiKeyboardComponent::drawWhiteNote(midiNoteNumber,g,x,y,w,h,isDown,isOver,lineColour,drawNoteNumber ? Colours::transparentWhite : textColour);
		if (hasKeyboardFocus(false) || drawQwerty)
		{
			if (midiNoteNumber >= baseOctave*12 && midiNoteNumber < 32+baseOctave*12) {
				int n =  midiNoteNumber - baseOctave*12;
				String key = String::charToString(keymap[n]);
				g.setColour(Colours::grey.withMultipliedAlpha(0.5f));
				if (midiNoteNumber/12 == baseOctave && midiNoteNumber%12==0) {
					g.drawEllipse((float)(x+w/4),(float)(y+h-3*w/4),(float)(w/2),(float)(w/2),2.f);
				}
				g.setFont((float)(w/2),Font::bold);
				g.drawText(key,x+w/4,y+h-3*w/4,w/2,w/2,Justification::centred,false);
			}
		}
		if (drawNoteNumber) {
			Font f (jmin (12.0f, w * 0.9f));
			f.setHorizontalScale (0.8f);
			//f.setBold (midiNoteNumber%12==0);
			g.setFont (f);
			g.setColour (textColour);
			g.drawFittedText (String(midiNoteNumber), x + 2, y + 2, w - 4, h - 4, Justification::centredBottom, 1);
		}
	}

	void focusLost(Component::FocusChangeType cause)
	{
		repaint();
	}

	void setDrawQwerty(bool qwerty)
	{
		drawQwerty = qwerty;
		repaint();
	}

	void setDrawNoteNumber(bool shouldDraw)
	{
		drawNoteNumber = shouldDraw;
		repaint();
	}

private:
	int baseOctave;
    Array<KeyPress> _keyPresses;
	BigInteger _keysPressed;
    Array <int> _keyPressNotes;
    bool mouseDownOnKey(int midiNoteNumber, const MouseEvent &e);
    MidiKeyboardState* s;
	bool drawQwerty;
	bool drawNoteNumber;

	bool isBlackKey(int noteNumber)
	{
		switch (noteNumber%12)
		{
		case  0: return false; //C
		case  1: return true;  //C#
		case  2: return false; //D
		case  3: return true;  //D#
		case  4: return false; //E
		case  5: return false; //F
		case  6: return true;  //F#
		case  7: return false; //G
		case  8: return true;  //G#
		case  9: return false; //A
		case 10: return true;  //A#
		case 11: return false; //B

		default: return false;
		}
	}
};

#endif
