#========================================
# S e t t i n g s
#========================================
CC = g++
DYN = .so
VST = ../vstsdk2.4/
OUT = release/
SDK = $(VST)public.sdk/source/vst2.x/
FFLAGS = -fmessage-length=0 -finline-functions -fvisibility=hidden -fPIC -fno-exceptions -fno-rtti
CFLAGS = -Wall -Wno-multichar -Os -c $(FFLAGS) -I$(VST)
LFLAGS = -Wall -s -shared

#========================================
# O b j e c t s
#========================================
# (common)
#----------------------------------------
OBJM = vstplugmain
OBJA = audioeffect
OBJX = audioeffectx
OBJC = $(OBJM).o $(OBJA).o $(OBJX).o

$(OBJM).o : $(SDK)$(OBJM).cpp
	$(CC) $(CFLAGS) common/$(OBJM).cpp
	
$(OBJX).o : $(SDK)$(OBJX).cpp
	$(CC) $(CFLAGS) $(SDK)$(OBJX).cpp
	
$(OBJA).o : $(SDK)$(OBJA).cpp
	$(CC) $(CFLAGS) $(SDK)$(OBJA).cpp
#----------------------------------------
# (output)
#----------------------------------------
OBJE = midi2qwerty16 midi16CCRouter midiAlias midiAudioToCC midiBlackKeyFilter midiCCModulator midiCCReset midiCCStepper midiCCToggle midiChannelFilter midiChannelize midiChordHold midiChordSplit midiChs_noGUI midiConverter3 midiDelay midiDuplicateBlocker midiExactDelay midiFingered midiForceToKey midiForceToRange midiInvertNotes midiKeySplit midiKeySplit4 midiNotchFilter midiNoteGroups midiNotesToCC midiNoteToggle midiNRPNConverter midiOverlappingNoteKiller midiPitchBendQuantize midiPolyphony midiProbability midiProgramChange midiScaleChanger midiSimpleLFO midiSostenuto midiStrum midiStuckNoteKiller midiSwing midiTranspose midiTriggerList midiVelocityScale

#========================================
# B u i l d
#========================================
# all / clean
#----------------------------------------
all: $(OBJE)

clean:
	rm -f *.o $(OUT)*.so
	
cleanobj:
	rm -f *.o
#----------------------------------------
# individual
#----------------------------------------
midi2qwerty16: $(OBJC) midi2qwerty16.o
	$(CC) $(LFLAGS) -L/usr/X11R6/lib $(OBJC) midi2qwerty16.o -o $(OUT)midi2qwerty16$(DYN) -lX11 -lXtst
midi2qwerty16.o: midi2qwerty16/*.cpp
	$(CC) $(CFLAGS) midi2qwerty16/*.cpp 

midi16CCRouter: $(OBJC) midi16CCRouter.o
	$(CC) $(LFLAGS) $(OBJC) midi16CCRouter.o -o $(OUT)midi16CCRouter$(DYN)
midi16CCRouter.o: midi16CCRouter/*.cpp
	$(CC) $(CFLAGS) midi16CCRouter/*.cpp
	
midiAlias: $(OBJC) midiAlias.o
	$(CC) $(LFLAGS) $(OBJC) midiAlias.o -o $(OUT)midiAlias$(DYN)
midiAlias.o: midiAlias/*.cpp
	$(CC) $(CFLAGS) midiAlias/*.cpp

midiAudioToCC: $(OBJC) midiAudioToCC.o
	$(CC) $(LFLAGS) $(OBJC) midiAudioToCC.o -o $(OUT)midiAudioToCC$(DYN)
midiAudioToCC.o: midiAudioToCC/*.cpp
	$(CC) $(CFLAGS) midiAudioToCC/*.cpp

midiBlackKeyFilter: $(OBJC) midiBlackKeyFilter.o
	$(CC) $(LFLAGS) $(OBJC) midiBlackKeyFilter.o -o $(OUT)midiBlackKeyFilter$(DYN)
midiBlackKeyFilter.o: midiBlackKeyFilter/*.cpp
	$(CC) $(CFLAGS) midiBlackKeyFilter/*.cpp

midiCCModulator: $(OBJC) midiCCModulator.o
	$(CC) $(LFLAGS) $(OBJC) midiCCModulator.o -o $(OUT)midiCCModulator$(DYN)
midiCCModulator.o: midiCCModulator/*.cpp
	$(CC) $(CFLAGS) midiCCModulator/*.cpp

midiCCReset: $(OBJC) midiCCReset.o
	$(CC) $(LFLAGS) $(OBJC) midiCCReset.o -o $(OUT)midiCCReset$(DYN)
midiCCReset.o: midiCCReset/*.cpp
	$(CC) $(CFLAGS) midiCCReset/*.cpp

midiCCStepper: $(OBJC) midiCCStepper.o
	$(CC) $(LFLAGS) $(OBJC) midiCCStepper.o -o $(OUT)midiCCStepper$(DYN)
midiCCStepper.o: midiCCStepper/*.cpp
	$(CC) $(CFLAGS) midiCCStepper/*.cpp

midiCCToggle: $(OBJC) midiCCToggle.o
	$(CC) $(LFLAGS) $(OBJC) midiCCToggle.o -o $(OUT)midiCCToggle$(DYN)
midiCCToggle.o: midiCCToggle/*.cpp
	$(CC) $(CFLAGS) midiCCToggle/*.cpp

midiChannelFilter: $(OBJC) midiChannelFilter.o
	$(CC) $(LFLAGS) $(OBJC) midiChannelFilter.o -o $(OUT)midiChannelFilter$(DYN)
midiChannelFilter.o: midiChannelFilter/*.cpp
	$(CC) $(CFLAGS) midiChannelFilter/*.cpp

midiChannelize: $(OBJC) midiChannelize.o
	$(CC) $(LFLAGS) $(OBJC) midiChannelize.o -o $(OUT)midiChannelize$(DYN)
midiChannelize.o: midiChannelize/*.cpp
	$(CC) $(CFLAGS) midiChannelize/*.cpp

midiChs_noGUI: $(OBJC) midiChs_noGUI.o
	$(CC) $(LFLAGS) $(OBJC) midiChs_noGUI.o -o $(OUT)midiChs_noGUI$(DYN)
midiChs_noGUI.o: midiChs_noGUI/*.cpp
	$(CC) $(CFLAGS) midiChs_noGUI/*.cpp

midiChordHold: $(OBJC) midiChordHold.o
	$(CC) $(LFLAGS) $(OBJC) midiChordHold.o -o $(OUT)midiChordHold$(DYN)
midiChordHold.o: midiChordHold/*.cpp
	$(CC) $(CFLAGS) midiChordHold/*.cpp

midiChordSplit: $(OBJC) midiChordSplit.o
	$(CC) $(LFLAGS) $(OBJC) midiChordSplit.o -o $(OUT)midiChordSplit$(DYN)
midiChordSplit.o: midiChordSplit/*.cpp
	$(CC) $(CFLAGS) midiChordSplit/*.cpp

midiConverter3: $(OBJC) midiConverter3.o
	$(CC) $(LFLAGS) $(OBJC) midiConverter3.o -o $(OUT)midiConverter3$(DYN)
midiConverter3.o: midiConverter3/*.cpp
	$(CC) $(CFLAGS) midiConverter3/*.cpp

midiDelay: $(OBJC) midiDelay.o
	$(CC) $(LFLAGS) $(OBJC) midiDelay.o -o $(OUT)midiDelay$(DYN)
midiDelay.o: midiDelay/*.cpp
	$(CC) $(CFLAGS) midiDelay/*.cpp

midiDuplicateBlocker: $(OBJC) midiDuplicateBlocker.o
	$(CC) $(LFLAGS) $(OBJC) midiDuplicateBlocker.o -o $(OUT)midiDuplicateBlocker$(DYN)
midiDuplicateBlocker.o: midiDuplicateBlocker/*.cpp
	$(CC) $(CFLAGS) midiDuplicateBlocker/*.cpp

midiExactDelay: $(OBJC) midiExactDelay.o
	$(CC) $(LFLAGS) $(OBJC) midiExactDelay.o -o $(OUT)midiExactDelay$(DYN)
midiExactDelay.o: midiExactDelay/*.cpp
	$(CC) $(CFLAGS) midiExactDelay/*.cpp

midiFingered: $(OBJC) midiFingered.o
	$(CC) $(LFLAGS) $(OBJC) midiFingered.o -o $(OUT)midiFingered$(DYN)
midiFingered.o: midiFingered/*.cpp
	$(CC) $(CFLAGS) midiFingered/*.cpp

midiForceToKey: $(OBJC) midiForceToKey.o
	$(CC) $(LFLAGS) $(OBJC) midiForceToKey.o -o $(OUT)midiForceToKey$(DYN)
midiForceToKey.o: midiForceToKey/*.cpp
	$(CC) $(CFLAGS) midiForceToKey/*.cpp

midiForceToRange: $(OBJC) midiForceToRange.o
	$(CC) $(LFLAGS) $(OBJC) midiForceToRange.o -o $(OUT)midiForceToRange$(DYN)
midiForceToRange.o: midiForceToRange/*.cpp
	$(CC) $(CFLAGS) midiForceToRange/*.cpp

midiInvertNotes: $(OBJC) midiInvertNotes.o
	$(CC) $(LFLAGS) $(OBJC) midiInvertNotes.o -o $(OUT)midiInvertNotes$(DYN)
midiInvertNotes.o: midiInvertNotes/*.cpp
	$(CC) $(CFLAGS) midiInvertNotes/*.cpp

midiKeySplit: $(OBJC) midiKeySplit.o
	$(CC) $(LFLAGS) $(OBJC) midiKeySplit.o -o $(OUT)midiKeySplit$(DYN)
midiKeySplit.o: midiKeySplit/*.cpp
	$(CC) $(CFLAGS) midiKeySplit/*.cpp

midiKeySplit4: $(OBJC) midiKeySplit4.o
	$(CC) $(LFLAGS) $(OBJC) midiKeySplit4.o -o $(OUT)midiKeySplit4$(DYN)
midiKeySplit4.o: midiKeySplit4/*.cpp
	$(CC) $(CFLAGS) midiKeySplit4/*.cpp

midiNotchFilter: $(OBJC) midiNotchFilter.o
	$(CC) $(LFLAGS) $(OBJC) midiNotchFilter.o -o $(OUT)midiNotchFilter$(DYN)
midiNotchFilter.o: midiNotchFilter/*.cpp
	$(CC) $(CFLAGS) midiNotchFilter/*.cpp

midiNoteGroups: $(OBJC) midiNoteGroups.o
	$(CC) $(LFLAGS) $(OBJC) midiNoteGroups.o -o $(OUT)midiNoteGroups$(DYN)
midiNoteGroups.o: midiNoteGroups/*.cpp
	$(CC) $(CFLAGS) midiNoteGroups/*.cpp

midiNotesToCC: $(OBJC) midiNotesToCC.o
	$(CC) $(LFLAGS) $(OBJC) midiNotesToCC.o -o $(OUT)midiNotesToCC$(DYN)
midiNotesToCC.o: midiNotesToCC/*.cpp
	$(CC) $(CFLAGS) midiNotesToCC/*.cpp

midiNoteToggle: $(OBJC) midiNoteToggle.o
	$(CC) $(LFLAGS) $(OBJC) midiNoteToggle.o -o $(OUT)midiNoteToggle$(DYN)
midiNoteToggle.o: midiNoteToggle/*.cpp
	$(CC) $(CFLAGS) midiNoteToggle/*.cpp

midiNRPNConverter: $(OBJC) midiNRPNConverter.o
	$(CC) $(LFLAGS) $(OBJC) midiNRPNConverter.o -o $(OUT)midiNRPNConverter$(DYN)
midiNRPNConverter.o: midiNRPNConverter/*.cpp
	$(CC) $(CFLAGS) midiNRPNConverter/*.cpp
	
midiOverlappingNoteKiller: $(OBJC) midiOverlappingNoteKiller.o
	$(CC) $(LFLAGS) $(OBJC) midiOverlappingNoteKiller.o -o $(OUT)midiOverlappingNoteKiller$(DYN)
midiOverlappingNoteKiller.o: midiOverlappingNoteKiller/*.cpp
	$(CC) $(CFLAGS) midiOverlappingNoteKiller/*.cpp

midiPitchBendQuantize: $(OBJC) midiPitchBendQuantize.o
	$(CC) $(LFLAGS) $(OBJC) midiPitchBendQuantize.o -o $(OUT)midiPitchBendQuantize$(DYN)
midiPitchBendQuantize.o: midiPitchBendQuantize/*.cpp
	$(CC) $(CFLAGS) midiPitchBendQuantize/*.cpp

midiPolyphony: $(OBJC) midiPolyphony.o
	$(CC) $(LFLAGS) $(OBJC) midiPolyphony.o -o $(OUT)midiPolyphony$(DYN)
midiPolyphony.o: midiPolyphony/*.cpp
	$(CC) $(CFLAGS) midiPolyphony/*.cpp

midiProbability: $(OBJC) midiProbability.o
	$(CC) $(LFLAGS) $(OBJC) midiProbability.o -o $(OUT)midiProbability$(DYN)
midiProbability.o: midiProbability/*.cpp
	$(CC) $(CFLAGS) midiProbability/*.cpp

midiProgramChange: $(OBJC) midiProgramChange.o
	$(CC) $(LFLAGS) $(OBJC) midiProgramChange.o -o $(OUT)midiProgramChange$(DYN)
midiProgramChange.o: midiProgramChange/*.cpp
	$(CC) $(CFLAGS) midiProgramChange/*.cpp

midiScaleChanger: $(OBJC) midiScaleChanger.o
	$(CC) $(LFLAGS) $(OBJC) midiScaleChanger.o -o $(OUT)midiScaleChanger$(DYN)
midiScaleChanger.o: midiScaleChanger/*.cpp
	$(CC) $(CFLAGS) midiScaleChanger/*.cpp
	
midiSimpleLFO: $(OBJC) midiSimpleLFO.o
	$(CC) $(LFLAGS) $(OBJC) midiSimpleLFO.o -o $(OUT)midiSimpleLFO$(DYN)
midiSimpleLFO.o: midiSimpleLFO/*.cpp
	$(CC) $(CFLAGS) midiSimpleLFO/*.cpp

midiSostenuto: $(OBJC) midiSostenuto.o
	$(CC) $(LFLAGS) $(OBJC) midiSostenuto.o -o $(OUT)midiSostenuto$(DYN)
midiSostenuto.o: midiSostenuto/*.cpp
	$(CC) $(CFLAGS) midiSostenuto/*.cpp

midiStrum: $(OBJC) midiStrum.o
	$(CC) $(LFLAGS) $(OBJC) midiStrum.o -o $(OUT)midiStrum$(DYN)
midiStrum.o: midiStrum/*.cpp
	$(CC) $(CFLAGS) midiStrum/*.cpp

midiStuckNoteKiller: $(OBJC) midiStuckNoteKiller.o
	$(CC) $(LFLAGS) $(OBJC) midiStuckNoteKiller.o -o $(OUT)midiStuckNoteKiller$(DYN)
midiStuckNoteKiller.o: midiStuckNoteKiller/*.cpp
	$(CC) $(CFLAGS) midiStuckNoteKiller/*.cpp

midiSwing: $(OBJC) midiSwing.o
	$(CC) $(LFLAGS) $(OBJC) midiSwing.o -o $(OUT)midiSwing$(DYN)
midiSwing.o: midiSwing/*.cpp
	$(CC) $(CFLAGS) midiSwing/*.cpp

midiTranspose: $(OBJC) midiTranspose.o
	$(CC) $(LFLAGS) $(OBJC) midiTranspose.o -o $(OUT)midiTranspose$(DYN)
midiTranspose.o: midiTranspose/*.cpp
	$(CC) $(CFLAGS) midiTranspose/*.cpp

midiTriggerList: $(OBJC) midiTriggerList.o
	$(CC) $(LFLAGS) $(OBJC) midiTriggerList.o -o $(OUT)midiTriggerList$(DYN)
midiTriggerList.o: midiTriggerList/*.cpp
	$(CC) $(CFLAGS) midiTriggerList/*.cpp

midiVelocityScale: $(OBJC) midiVelocityScale.o
	$(CC) $(LFLAGS) $(OBJC) midiVelocityScale.o -o $(OUT)midiVelocityScale$(DYN)
midiVelocityScale.o: midiVelocityScale/*.cpp
	$(CC) $(CFLAGS) midiVelocityScale/*.cpp
