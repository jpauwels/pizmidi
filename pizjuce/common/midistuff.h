#ifndef PIZ_MIDI_STUFF_H
#define PIZ_MIDI_STUFF_H

#define NOT_PLAYING (-999)
#define ANY_CHANNEL (0)
#define MIDI_NOTEOFF (0x80)
#define MIDI_NOTEON  (0x90)
#define midiScaler ((float)0.007874015748031496062992125984252)

inline int floatToMidi(float f, bool learnspace=true) {
    if (learnspace) return roundFloatToInt(f*128.f) - 1;
    return roundFloatToInt(f*127.f);
}
inline float midiToFloat(int n, bool learnspace=true) {
    if (learnspace) return (float)(n+1)*0.0078125f;
    return (float)n * (float)0.007874015748031496062992125984252;
}

inline int floatToChannel(float f) { return roundFloatToInt(f * 16.0f); }
inline float channelToFloat(int c) { return (float)c * 0.0625f; }

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
