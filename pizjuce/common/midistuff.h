#ifndef PIZ_MIDI_STUFF_H
#define PIZ_MIDI_STUFF_H

#include "JuceHeader.h"

#define NOT_PLAYING (-999)
#define ANY_CHANNEL (0)
#define MIDI_NOTEOFF (0x80)
#define MIDI_NOTEON  (0x90)
#define midiScaler ((float)0.007874015748031496062992125984252)

const String Flat("b");//(L"\x266d");
const String Natural(L"\x266e");
const String Sharp("#");//(L"\x266f");
const String Diminished("o");//(L"\x0080");

enum NoteNames {nC,nDb,nD,nEb,nE,nF,nGb,nG,nAb,nA,nBb,nB};

inline int floatToMidi(float f, bool learnspace=true) {
    if (learnspace) return roundToInt(f*128.f) - 1;
    return roundToInt(f*127.f);
}
inline float midiToFloat(int n, bool learnspace=true) {
    if (learnspace) return (float)(n+1)*0.0078125f;
    return (float)n * (float)0.007874015748031496062992125984252;
}

inline int floatToChannel(float f) { return roundToInt(f * 16.0f); }
inline float channelToFloat(int c) { return (float)c * 0.0625f; }

inline int getNoteValue(String noteName)
{
	if (noteName.equalsIgnoreCase("C") || noteName.equalsIgnoreCase("B#") || noteName.equalsIgnoreCase("Dbb"))
		return nC;
	if (noteName.equalsIgnoreCase("C#") || noteName.equalsIgnoreCase("Db") || noteName.equalsIgnoreCase("Bx"))
		return nDb;
	if (noteName.equalsIgnoreCase("D") || noteName.equalsIgnoreCase("Ebb") || noteName.equalsIgnoreCase("Cx"))
		return nD;
	if (noteName.equalsIgnoreCase("Eb") || noteName.equalsIgnoreCase("D#") || noteName.equalsIgnoreCase("Fbb"))
		return nEb;
	if (noteName.equalsIgnoreCase("E") || noteName.equalsIgnoreCase("Fb") || noteName.equalsIgnoreCase("Dx"))
		return nE;
	if (noteName.equalsIgnoreCase("F") || noteName.equalsIgnoreCase("E#") || noteName.equalsIgnoreCase("Gbb"))
		return nF;
	if (noteName.equalsIgnoreCase("Gb") || noteName.equalsIgnoreCase("F#") || noteName.equalsIgnoreCase("Ex"))
		return nGb;
	if (noteName.equalsIgnoreCase("G") || noteName.equalsIgnoreCase("Fx") || noteName.equalsIgnoreCase("Abb"))
		return nG;
	if (noteName.equalsIgnoreCase("Ab") || noteName.equalsIgnoreCase("G#"))
		return nAb;
	if (noteName.equalsIgnoreCase("A") || noteName.equalsIgnoreCase("Gx") || noteName.equalsIgnoreCase("Bbb"))
		return nA;
	if (noteName.equalsIgnoreCase("Bb") || noteName.equalsIgnoreCase("A#") || noteName.equalsIgnoreCase("Cbb"))
		return nBb;
	if (noteName.equalsIgnoreCase("B") || noteName.equalsIgnoreCase("Cb") || noteName.equalsIgnoreCase("Ax"))
		return nB;
	return -1;
}

inline String getNoteName(int noteNumber, int baseOctave=-2) {
    String Note = String::empty;
    switch (noteNumber%12) {
        case  0: Note="C" ; break;
        case  1: Note="C#"; break;
        case  2: Note="D" ; break;
        case  3: Note="D#"; break;
        case  4: Note="E" ; break;
        case  5: Note="F" ; break;
        case  6: Note="F#"; break;
        case  7: Note="G" ; break;
        case  8: Note="G#"; break;
        case  9: Note="A" ; break;
        case 10: Note="A#"; break;
        case 11: Note="B" ; break;
        default:            break;
    }
    return Note + String((noteNumber/12)+baseOctave);
}

inline String getNoteNameWithoutOctave(int noteNumber, bool sharps = true) {
    String Note = String::empty;
	if (sharps) 
	{
		switch (noteNumber%12) {
			case  0: Note="C" ; break;
			case  1: Note="C"+Sharp; break;
			case  2: Note="D" ; break;
			case  3: Note="D"+Sharp; break;
			case  4: Note="E" ; break;
			case  5: Note="F" ; break;
			case  6: Note="F"+Sharp; break;
			case  7: Note="G" ; break;
			case  8: Note="G"+Sharp; break;
			case  9: Note="A" ; break;
			case 10: Note="A"+Sharp; break;
			case 11: Note="B" ; break;
			default:            break;
		}
	}
	else {
		switch (noteNumber%12) {
			case  0: Note="C" ; break;
			case  1: Note="D"+Flat; break;
			case  2: Note="D" ; break;
			case  3: Note="E"+Flat; break;
			case  4: Note="E" ; break;
			case  5: Note="F" ; break;
			case  6: Note="G"+Flat; break;
			case  7: Note="G" ; break;
			case  8: Note="A"+Flat; break;
			case  9: Note="A" ; break;
			case 10: Note="B"+Flat; break;
			case 11: Note="B" ; break;
			default:            break;
		}
	}
	return Note;
}

inline int mapToRange(float x,float in1,float in2,float out1,float out2) {
      float slope = ((float)(out2-out1))/((float)(in2-in1));
      float b = out1 - slope * in1;
      return roundFloatToInt(slope * x + b);
}

inline int CombineBytes(unsigned char lsb, unsigned char msb)
{
	return (((unsigned int)msb) << 7) | (unsigned int)lsb;
}

#endif
