// JUCE 1.51
//==============================================================================

#ifdef _MSC_VER
  #pragma warning (disable : 4996 4100)
#endif

#include "reaper_plugin.h"
#ifdef _WIN32
  #include <windows.h>
#elif defined (LINUX)
  #include <X11/Xlib.h>
  #include <X11/Xutil.h>
  #include <X11/Xatom.h>
  #undef KeyPress
#else
  #include <Carbon/Carbon.h>
#endif

#ifdef PRAGMA_ALIGN_SUPPORTED
  #undef PRAGMA_ALIGN_SUPPORTED
  #define PRAGMA_ALIGN_SUPPORTED 1
#endif

#include "juce_IncludeCharacteristics.h"

#if JucePlugin_Build_VST

//==============================================================================
/*  These files come with the Steinberg VST SDK - to get them, you'll need to
    visit the Steinberg website and jump through some hoops to sign up as a
    VST developer.

    Then, you'll need to make sure your include path contains your "vstsdk2.3" or
    "vstsdk2.4" directory.

    Note that the JUCE_USE_VSTSDK_2_4 macro should be defined in JucePluginCharacteristics.h
*/
#if JUCE_USE_VSTSDK_2_4
 #ifdef __GNUC__
  #define __cdecl
 #endif

 // VSTSDK V2.4 includes..
 #include "public.sdk/source/vst2.x/audioeffectx.h"
 #include "public.sdk/source/vst2.x/aeffeditor.h"
 #include "public.sdk/source/vst2.x/audioeffectx.cpp"
 #include "public.sdk/source/vst2.x/audioeffect.cpp"

 #if ! VST_2_4_EXTENSIONS
  #error // You're probably trying to include the wrong VSTSDK version - make sure your include path matches the JUCE_USE_VSTSDK_2_4 flag
 #endif

#else
 // VSTSDK V2.3 includes..
 #include "source/common/audioeffectx.h"
 #include "source/common/AEffEditor.hpp"
 #include "source/common/audioeffectx.cpp"
 #include "source/common/AudioEffect.cpp"

 #if (! VST_2_3_EXTENSIONS) || VST_2_4_EXTENSIONS
  #error // You're probably trying to include the wrong VSTSDK version - make sure your include path matches the JUCE_USE_VSTSDK_2_4 flag
 #endif

 #define __aeffect__  // (needed for juce_VSTMidiEventList.h to work)

 typedef long VstInt32;
 typedef long VstIntPtr;
 enum Vst2StringConstants
 {
   kVstMaxNameLen       = 64,
   kVstMaxLabelLen      = 64,
   kVstMaxShortLabelLen = 8,
   kVstMaxCategLabelLen = 24,
   kVstMaxFileNameLen   = 100
 };

 enum VstSmpteFrameRate
 {
    kVstSmpte24fps    = 0,  ///< 24 fps
    kVstSmpte25fps    = 1,  ///< 25 fps
    kVstSmpte2997fps  = 2,  ///< 29.97 fps
    kVstSmpte30fps    = 3,  ///< 30 fps
    kVstSmpte2997dfps = 4,  ///< 29.97 drop
    kVstSmpte30dfps   = 5,  ///< 30 drop
    kVstSmpteFilm16mm = 6,  ///< Film 16mm
    kVstSmpteFilm35mm = 7,  ///< Film 35mm
    kVstSmpte239fps   = 10, ///< HDTV: 23.976 fps
    kVstSmpte249fps   = 11, ///< HDTV: 24.976 fps
    kVstSmpte599fps   = 12, ///< HDTV: 59.94 fps
    kVstSmpte60fps    = 13  ///< HDTV: 60 fps
 };

 struct VstMidiSysexEvent
 {
    VstInt32 type;          ///< #kVstSysexType
    VstInt32 byteSize;      ///< sizeof (VstMidiSysexEvent)
    VstInt32 deltaFrames;   ///< sample frames related to the current block start sample position
    VstInt32 flags;         ///< none defined yet (should be zero)
    VstInt32 dumpBytes;     ///< byte size of sysexDump
    VstIntPtr resvd1;       ///< zero (Reserved for future use)
    char* sysexDump;        ///< sysex dump
    VstIntPtr resvd2;       ///< zero (Reserved for future use)
 };

 typedef int VstSpeakerArrangementType;
#endif

//==============================================================================
#ifdef _MSC_VER
  #pragma pack (push, 8)
#endif

#include "PizAudioProcessor.h"
//#include "juce_PluginHeaders.h"
#if JUCE_VERSION >= ((1<<16)+(50<<8))
#include "../common/juce_PluginHostType_old.h"
#endif

int vstVirtualKeyCodeConversionTable[]=
{
      VKEY_BACK, KeyPress::backspaceKey,
      VKEY_TAB, KeyPress::tabKey,
      VKEY_CLEAR, 0,
      VKEY_RETURN, KeyPress::returnKey,
      VKEY_PAUSE, 0,
      VKEY_ESCAPE, KeyPress::escapeKey,
      VKEY_SPACE, KeyPress::spaceKey,
      VKEY_NEXT, 0,
      VKEY_END, KeyPress::endKey,
      VKEY_HOME, KeyPress::homeKey,

      VKEY_LEFT, KeyPress::leftKey,
      VKEY_UP, KeyPress::upKey,
      VKEY_RIGHT, KeyPress::rightKey,
      VKEY_DOWN, KeyPress::downKey,
      VKEY_PAGEUP, KeyPress::pageUpKey,
      VKEY_PAGEDOWN, KeyPress::pageDownKey,

      VKEY_SELECT, 0,
      VKEY_PRINT, 0,
      VKEY_ENTER, KeyPress::returnKey,
      VKEY_SNAPSHOT, 0,
      VKEY_INSERT, KeyPress::insertKey,
      VKEY_DELETE, KeyPress::deleteKey,
      VKEY_HELP, 0,
      VKEY_NUMPAD0, KeyPress::numberPad0,
      VKEY_NUMPAD1, KeyPress::numberPad1,
      VKEY_NUMPAD2, KeyPress::numberPad2,
      VKEY_NUMPAD3, KeyPress::numberPad3,
      VKEY_NUMPAD4, KeyPress::numberPad4,
      VKEY_NUMPAD5, KeyPress::numberPad5,
      VKEY_NUMPAD6, KeyPress::numberPad6,
      VKEY_NUMPAD7, KeyPress::numberPad7,
      VKEY_NUMPAD8, KeyPress::numberPad8,
      VKEY_NUMPAD9, KeyPress::numberPad9,
      VKEY_MULTIPLY, KeyPress::numberPadMultiply,
      VKEY_ADD, KeyPress::numberPadAdd,
      VKEY_SEPARATOR, KeyPress::numberPadSeparator,
      VKEY_SUBTRACT, KeyPress::numberPadSubtract,
      VKEY_DECIMAL, KeyPress::numberPadDecimalPoint,
      VKEY_DIVIDE, KeyPress::numberPadDivide,
      VKEY_F1, KeyPress::F1Key,
      VKEY_F2, KeyPress::F2Key,
      VKEY_F3, KeyPress::F3Key,
      VKEY_F4, KeyPress::F4Key,
      VKEY_F5, KeyPress::F5Key,
      VKEY_F6, KeyPress::F6Key,
      VKEY_F7, KeyPress::F7Key,
      VKEY_F8, KeyPress::F8Key,
      VKEY_F9, KeyPress::F9Key,
      VKEY_F10, KeyPress::F10Key,
      VKEY_F11, KeyPress::F11Key,
      VKEY_F12, KeyPress::F12Key,
      VKEY_NUMLOCK, 0,
      VKEY_SCROLL, 0,

      VKEY_SHIFT, 0,
      VKEY_CONTROL, 0,
      VKEY_ALT, 0,

      VKEY_EQUALS, 0
};

bool isShiftDown=false;
void convertVstKeyInputToKeyCodeAndTextCharacter(int opCode, VstIntPtr value, int index, int &keyCode, int &textCharacter)
{
   keyCode=0;
   textCharacter=0;

   if (opCode==effEditKeyDown)
   {
      if (value==VKEY_SHIFT) isShiftDown=true;
      else
         for (int i=0; i<sizeof(vstVirtualKeyCodeConversionTable)/(2*sizeof(int));i++)
            if (value==vstVirtualKeyCodeConversionTable[i*2])
            {
               keyCode=vstVirtualKeyCodeConversionTable[i*2+1];
               break;
            }
      
      textCharacter=index; // ascii
      if (isShiftDown && textCharacter>=97 && textCharacter<=122) textCharacter-=(97-65); // A-Z -> a-z
   }
   else if (opCode==effEditKeyUp)
   {
      if (value==VKEY_SHIFT) isShiftDown=false;
   }
}


#ifdef _MSC_VER
  #pragma pack (pop)
#endif

#undef MemoryBlock

class JuceVSTWrapper;
static bool recursionCheck = false;
static JUCE_NAMESPACE::uint32 lastMasterIdleCall = 0;

BEGIN_JUCE_NAMESPACE
 extern void juce_callAnyTimersSynchronously();

 #if JUCE_MAC
  extern void initialiseMac();
  extern void* attachComponentToWindowRef (Component* component, void* windowRef);
  extern void detachComponentFromWindowRef (Component* component, void* nsWindow);
  extern void setNativeHostWindowSize (void* nsWindow, Component* editorComp, int newWidth, int newHeight);
  extern void checkWindowVisibility (void* nsWindow, Component* component);
  extern void forwardCurrentKeyEventToHost (Component* component);
 #endif

 #if JUCE_LINUX
  extern Display* display;
  extern bool juce_postMessageToSystemQueue (void* message);
 #endif
END_JUCE_NAMESPACE

#if defined (_DEBUG)
#define MAKE_LOG 1
    String dbg = "banana";
    int PorPR = 0;
    AudioPlayHead::CurrentPositionInfo lastPos;
#endif

//==============================================================================
#if JUCE_WINDOWS

namespace
{
    HWND findMDIParentOf (HWND w)
    {
        const int frameThickness = GetSystemMetrics (SM_CYFIXEDFRAME);

        while (w != 0)
        {
            HWND parent = GetParent (w);

            if (parent == 0)
                break;

            TCHAR windowType [32];
            zeromem (windowType, sizeof (windowType));
            GetClassName (parent, windowType, 31);

            if (String (windowType).equalsIgnoreCase ("MDIClient"))
            {
                w = parent;
                break;
            }

            RECT windowPos;
            GetWindowRect (w, &windowPos);

            RECT parentPos;
            GetWindowRect (parent, &parentPos);

            const int dw = (parentPos.right - parentPos.left) - (windowPos.right - windowPos.left);
            const int dh = (parentPos.bottom - parentPos.top) - (windowPos.bottom - windowPos.top);

            if (dw > 100 || dh > 100)
                break;

            w = parent;

            if (dw == 2 * frameThickness)
                break;
        }

        return w;
    }
}

//==============================================================================
#elif JUCE_LINUX

class SharedMessageThread : public Thread
{
public:
    SharedMessageThread()
      : Thread ("VstMessageThread"),
        initialised (false)
    {
        startThread (7);

        while (! initialised)
            sleep (1);
    }

    ~SharedMessageThread()
    {
        signalThreadShouldExit();
        JUCEApplication::quit();
        waitForThreadToExit (5000);
        clearSingletonInstance();
    }

    void run()
    {
        initialiseJuce_GUI();
        initialised = true;

        MessageManager::getInstance()->setCurrentThreadAsMessageThread();

        while ((! threadShouldExit()) && MessageManager::getInstance()->runDispatchLoopUntil (250))
        {
        }
    }

    juce_DeclareSingleton (SharedMessageThread, false)

private:
    bool initialised;
};

juce_ImplementSingleton (SharedMessageThread)

#endif

//==============================================================================
// A component to hold the AudioProcessorEditor, and cope with some housekeeping
// chores when it changes or repaints.
class EditorCompWrapper  : public Component,
                           public AsyncUpdater
{
    JuceVSTWrapper* wrapper;

public:
    EditorCompWrapper (JuceVSTWrapper* const wrapper_,
                       AudioProcessorEditor* const editor)
        : wrapper (wrapper_)
    {
        setOpaque (true);
        editor->setOpaque (true);

        setBounds (editor->getBounds());
        editor->setTopLeftPosition (0, 0);
        addAndMakeVisible (editor);

#if JUCE_WIN32
        addMouseListener (this, true);
#endif
    }

    ~EditorCompWrapper()
    {
        deleteAllChildren();
    }

    void paint (Graphics& g)
    {
    }

    void paintOverChildren (Graphics& g)
    {
        // this causes an async call to masterIdle() to help
        // creaky old DAWs like Nuendo repaint themselves while we're
        // repainting. Otherwise they just seem to give up and sit there
        // waiting.
        triggerAsyncUpdate();
    }

#if JUCE_MAC
    bool keyPressed (const KeyPress& kp)
    {
        // If we have an unused keypress, move the key-focus to a host window
        // and re-inject the event..
        forwardCurrentKeyEventToHost (this);
        return true;
    }
#endif

    AudioProcessorEditor* getEditorComp() const
    {
        return dynamic_cast <AudioProcessorEditor*> (getChildComponent (0));
    }

    void resized()
    {
        Component* const c = getChildComponent (0);

        if (c != 0)
            c->setBounds (0, 0, getWidth(), getHeight());
    }

    void childBoundsChanged (Component* child);
    void handleAsyncUpdate();

#if JUCE_WIN32
    void mouseDown (const MouseEvent&)
    {
        broughtToFront();
    }

    void broughtToFront()
    {
        // for hosts like nuendo, need to also pop the MDI container to the
        // front when our comp is clicked on.
        HWND parent = findMDIParentOf ((HWND) getWindowHandle());

        if (parent != 0)
        {
            SetWindowPos (parent,
                          HWND_TOP,
                          0, 0, 0, 0,
                          SWP_NOMOVE | SWP_NOSIZE);
        }
    }
#endif

    //==============================================================================
    juce_UseDebuggingNewOperator
};

static Array<void*> activePlugins;


//==============================================================================
/**
    This wraps an AudioProcessor as an AudioEffectX...
*/
class JuceVSTWrapper  : public AudioEffectX,
                        private Timer,
                        public AudioProcessorListener,
                        public AudioPlayHead
{
public:
    //==============================================================================
    JuceVSTWrapper (audioMasterCallback audioMaster,
                    PizAudioProcessor* const filter_);


    ~JuceVSTWrapper()
    {
#ifdef MAKE_LOG
        dbg = "destructor";
        DBG(dbg);
#endif
        stopTimer();
        deleteEditor (false);

        hasShutdown = true;

        delete filter;
        filter = 0;

        jassert (editorComp == 0);

        channels.free();
        deleteTempChannels();

        jassert (activePlugins.contains (this));
        activePlugins.removeValue (this);

        if (activePlugins.size() == 0)
        {
#if JUCE_LINUX
            SharedMessageThread::deleteInstance();
#endif
            shutdownJuce_GUI();
        }
    }

    void open()
    {
        if (editorComp == 0)
        {
            checkWhetherWavelabHasChangedThread();
            const MessageManagerLock mmLock;

            AudioProcessorEditor* const ed = filter->createEditorIfNeeded();

            if (ed != 0)
                cEffect.flags |= effFlagsHasEditor;
            else
                cEffect.flags &= ~effFlagsHasEditor;

            filter->editorBeingDeleted (ed);
            delete ed;
        }

        startTimer (1000 / 4);
    }

    void close()
    {
        const NonWavelabMMLock mmLock;
        jassert (! recursionCheck);

        stopTimer();
        deleteEditor (false);
    }

    //==============================================================================
    bool getEffectName (char* name)
    {
		String (JucePlugin_Name).copyToCString (name, 64);
#ifdef MAKE_LOG
        dbg = "getEffectName():" + String(JucePlugin_Name);
        DBG(dbg);
#endif
        return true;
    }

    bool getVendorString (char* text)
    {
        String (JucePlugin_Manufacturer).copyToCString (text, 64);
#ifdef MAKE_LOG
        dbg = "getVendorString():" + String(JucePlugin_Manufacturer);
        DBG(dbg);
#endif
        return true;
    }

    bool getProductString (char* text)
    {
#ifdef MAKE_LOG
        dbg = "getProductString():" + String(JucePlugin_Name);
        DBG(dbg);
#endif
        return getEffectName (text);
    }

    VstInt32 getVendorVersion()
    {
#ifdef MAKE_LOG
        dbg = "getVendorVersion():" + String(JucePlugin_VersionCode);
        DBG(dbg);
#endif
        return JucePlugin_VersionCode;
    }

    VstPlugCategory getPlugCategory()
    {
#ifdef MAKE_LOG
        dbg = "getPlugCategory():" + String(JucePlugin_VSTCategory);
        DBG(dbg);
#endif
        return JucePlugin_VSTCategory;
    }

    VstInt32 canDo (char* text)
    {
        VstInt32 result = 0;

        if (strcmp (text, "receiveVstEvents") == 0
            || strcmp (text, "receiveVstMidiEvent") == 0
            || strcmp (text, "receiveVstMidiEvents") == 0)
        {
#if JucePlugin_WantsMidiInput
            result = 1;
#else
            result = -1;
#endif
        }
        else if (strcmp (text, "sendVstEvents") == 0
                 || strcmp (text, "sendVstMidiEvent") == 0
                 || strcmp (text, "sendVstMidiEvents") == 0)
        {
#if JucePlugin_ProducesMidiOutput
            result = 1;
#else
            result = -1;
#endif
        }
        else if (strcmp (text, "receiveVstTimeInfo") == 0
                 || strcmp (text, "conformsToWindowRules") == 0)
        {
            result = 1;
        }

#ifdef MAKE_LOG
        dbg = "canDo(" + String(text) + "): " + String(result);
        DBG(dbg);
#endif
        return result;
    }

    bool keysRequired()
    {
#ifdef MAKE_LOG
        dbg = "keysRequired(): " + String(JucePlugin_EditorRequiresKeyboardFocus);
        DBG(dbg);
#endif
        return (JucePlugin_EditorRequiresKeyboardFocus) != 0;
    }

    bool getInputProperties (VstInt32 index, VstPinProperties* properties)
    {
#ifdef MAKE_LOG
        dbg = "getInputProperties(" + String(index) + ")" ;
        DBG(dbg);
#endif
        if (filter == 0 || index >= JucePlugin_MaxNumInputChannels)
            return false;

        const String name (filter->getInputChannelName ((int) index));

        name.copyToCString (properties->label, kVstMaxLabelLen - 1);
        name.copyToCString (properties->shortLabel, kVstMaxShortLabelLen - 1);

        if (speakerIn != kSpeakerArrEmpty)
        {
            properties->flags = kVstPinUseSpeaker;
            properties->arrangementType = speakerIn;
        }
        else
        {
            properties->flags = kVstPinIsActive;

            if (filter->isInputChannelStereoPair ((int) index))
                properties->flags |= kVstPinIsStereo;

            properties->arrangementType = 0;
        }

        return true;
    }

    bool getOutputProperties (VstInt32 index, VstPinProperties* properties)
    {
#ifdef MAKE_LOG
        dbg = "getOutputProperties(" + String(index) + ")" ;
        DBG(dbg);
#endif
        if (filter == 0 || index >= JucePlugin_MaxNumOutputChannels)
            return false;

        const String name (filter->getOutputChannelName ((int) index));

        name.copyToCString (properties->label, kVstMaxLabelLen - 1);
        name.copyToCString (properties->shortLabel, kVstMaxShortLabelLen - 1);

        if (speakerOut != kSpeakerArrEmpty)
        {
            properties->flags = kVstPinUseSpeaker;
            properties->arrangementType = speakerOut;
        }
        else
        {
            properties->flags = kVstPinIsActive;

            if (filter->isOutputChannelStereoPair ((int) index))
                properties->flags |= kVstPinIsStereo;

            properties->arrangementType = 0;
        }

        return true;
    }

#ifdef MAKE_LOG
    void setSampleRate(float sampleRate) {
        dbg = "setSampleRate(" + String(sampleRate) + ")" ;
        DBG(dbg);
        AudioEffectX::setSampleRate(sampleRate);
    }
#endif

#ifdef MAKE_LOG
    void setBlockSize(VstInt32 blockSize) {
        dbg = "setBlockSize(" + String(blockSize) + ")" ;
        DBG(dbg);
        AudioEffectX::setBlockSize(blockSize);
    }
#endif
    //==============================================================================
    VstInt32 processEvents (VstEvents* events)
    {
#ifdef MAKE_LOG
        if (events->numEvents) {
            dbg = "processEvents(" + String(events->numEvents) + " events)" ;
            DBG(dbg);
        }
#endif
#if JucePlugin_WantsMidiInput
        VSTMidiEventList::addEventsToMidiBuffer (events, midiEvents);
        return 1;
#else
        return 0;
#endif
    }

    void process (float** inputs, float** outputs, VstInt32 numSamples)
    {
#ifdef MAKE_LOG
        if (PorPR!=-1) {
            dbg = "process(" + String(numSamples) + ")" ;
            DBG(dbg);
            PorPR=-1;
        }
#endif
        const int numIn = numInChans;
        const int numOut = numOutChans;

        AudioSampleBuffer temp (numIn, numSamples);
        int i;
        for (i = numIn; --i >= 0;)
            memcpy (temp.getSampleData (i), outputs[i], sizeof (float) * numSamples);

        processReplacing (inputs, outputs, numSamples);

        AudioSampleBuffer dest (outputs, numOut, numSamples);

        for (i = jmin (numIn, numOut); --i >= 0;)
            dest.addFrom (i, 0, temp, i, 0, numSamples);
    }

    void processReplacing (float** inputs, float** outputs, VstInt32 numSamples)
    {
#ifdef MAKE_LOG
        AudioPlayHead::CurrentPositionInfo pos;
        if (PorPR!=1) {
            dbg = "processReplacing(" + String(numSamples) + ")" ;
            DBG(dbg);
            PorPR=1;
            if (getCurrentPosition(pos)) {
				if (pos.isPlaying && !lastPos.isPlaying) {
					DBG("playing");
				}
				else if (!pos.isPlaying && lastPos.isPlaying) {
					DBG("stopped");
				}
				if (pos.isRecording && !lastPos.isRecording) {
					DBG("recording");
				}
				else if (!pos.isRecording && lastPos.isRecording) {
					DBG("not recording");
				}
                dbg = String(pos.timeSigNumerator)+"/"+String(pos.timeSigDenominator)+" "+String(pos.bpm)+"bpm";
                lastPos=pos;
            }
            else dbg = "no time info";
            DBG(dbg);
        }
        if (getCurrentPosition(pos)) {
			if (pos.isPlaying && !lastPos.isPlaying) {DBG("playing");}
			else if (!pos.isPlaying && lastPos.isPlaying) {DBG("stopped");}
			if (pos.isRecording && !lastPos.isRecording) {DBG("recording");}
			else if (!pos.isRecording && lastPos.isRecording) {DBG("not recording");}
            if (pos.timeSigNumerator!=lastPos.timeSigNumerator || pos.timeSigDenominator!=lastPos.timeSigDenominator) {
                dbg = String(pos.timeSigNumerator)+"/"+String(pos.timeSigDenominator);
                DBG(dbg);
            }
            if (pos.bpm!=lastPos.bpm) {
                dbg = String(pos.bpm)+" bpm";
                DBG(dbg);
            }
            lastPos = pos;
        }
#endif
        if (firstProcessCallback)
        {
            firstProcessCallback = false;

            // if this fails, the host hasn't called resume() before processing
            jassert (isProcessing);

            // (tragically, some hosts actually need this, although it's stupid to have
            //  to do it here..)
            if (! isProcessing)
                resume();

            filter->setNonRealtime (getCurrentProcessLevel() == 4 /* kVstProcessLevelOffline */);

#if JUCE_WIN32
            if (GetThreadPriority (GetCurrentThread()) <= THREAD_PRIORITY_NORMAL
                  && GetThreadPriority (GetCurrentThread()) >= THREAD_PRIORITY_LOWEST)
                filter->setNonRealtime (true);
#endif
        }

#if JUCE_DEBUG && ! JucePlugin_ProducesMidiOutput
        const int numMidiEventsComingIn = midiEvents.getNumEvents();
#endif

        jassert (activePlugins.contains (this));

        {
            const ScopedLock sl (filter->getCallbackLock());

            const int numIn = numInChans;
            const int numOut = numOutChans;

            if (filter->isSuspended())
            {
                for (int i = 0; i < numOut; ++i)
                    zeromem (outputs[i], sizeof (float) * numSamples);
            }
            else
            {
                int i;
                for (i = 0; i < numOut; ++i)
                {
                    float* chan = (float*) tempChannels.getUnchecked(i);

                    if (chan == 0)
                    {
                        chan = outputs[i];

                        // if some output channels are disabled, some hosts supply the same buffer
                        // for multiple channels - this buggers up our method of copying the
                        // inputs over the outputs, so we need to create unique temp buffers in this case..
                        for (int j = i; --j >= 0;)
                        {
                            if (outputs[j] == chan)
                            {
                                chan = (float*) juce_malloc (sizeof (float) * blockSize * 2);
                                tempChannels.set (i, chan);
                                break;
                            }
                        }
                    }

                    if (i < numIn && chan != inputs[i])
                        memcpy (chan, inputs[i], sizeof (float) * numSamples);

                    channels[i] = chan;
                }

                for (; i < numIn; ++i)
                    channels[i] = inputs[i];

                AudioSampleBuffer chans (channels, jmax (numIn, numOut), numSamples);

                filter->processBlock (chans, midiEvents);
            }
        }

        if (! midiEvents.isEmpty())
        {
#if JucePlugin_ProducesMidiOutput
            const int numEvents = midiEvents.getNumEvents();

            outgoingEvents.ensureSize (numEvents);
            outgoingEvents.clear();

            const JUCE_NAMESPACE::uint8* midiEventData;
            int midiEventSize, midiEventPosition;
            MidiBuffer::Iterator i (midiEvents);

            while (i.getNextEvent (midiEventData, midiEventSize, midiEventPosition))
            {
                 jassert (midiEventPosition >= 0 && midiEventPosition < numSamples);

                outgoingEvents.addEvent (midiEventData, midiEventSize, midiEventPosition);
            }

            sendVstEventsToHost (outgoingEvents.events);
#else
            /*  This assertion is caused when you've added some events to the
                midiMessages array in your processBlock() method, which usually means
                that you're trying to send them somewhere. But in this case they're
                getting thrown away.

                If your plugin does want to send midi messages, you'll need to set
                the JucePlugin_ProducesMidiOutput macro to 1 in your
                JucePluginCharacteristics.h file.

                If you don't want to produce any midi output, then you should clear the
                midiMessages array at the end of your processBlock() method, to
                indicate that you don't want any of the events to be passed through
                to the output.
            */
            jassert (midiEvents.getNumEvents() <= numMidiEventsComingIn);
#endif

            midiEvents.clear();
        }
    }

    //==============================================================================
    VstInt32 startProcess () { 
#ifdef MAKE_LOG
        dbg = "startProcess()";
        DBG(dbg);
#endif
        return 0; 
    }

    VstInt32 stopProcess () { 
#ifdef MAKE_LOG
        dbg = "stopProcess()";
        DBG(dbg);
#endif
        return 0;
    }

    void resume()
    {
#ifdef MAKE_LOG
        dbg = "resume()";
        DBG(dbg);
#endif
        if (filter == 0)
            return;

        isProcessing = true;
        channels.calloc (numInChans + numOutChans);

        double rate = getSampleRate();
#ifdef MAKE_LOG
        dbg = "getSampleRate(): " + String(rate);
        DBG(dbg);
#endif
        jassert (rate > 0);
        if (rate <= 0.0)
            rate = 44100.0;

        const int blockSize = getBlockSize();
#ifdef MAKE_LOG
        dbg = "getBlockSize(): " + String(blockSize);
        DBG(dbg);
#endif
        jassert (blockSize > 0);

        firstProcessCallback = true;

        filter->setNonRealtime (getCurrentProcessLevel() == 4 /* kVstProcessLevelOffline */);

        filter->setPlayConfigDetails (numInChans, numOutChans,
                                      rate, blockSize);

        deleteTempChannels();

        filter->prepareToPlay (rate, blockSize);

        midiEvents.ensureSize (2048);
        midiEvents.clear();

        setInitialDelay (filter->getLatencySamples());

        AudioEffectX::resume();

#if JucePlugin_ProducesMidiOutput
        outgoingEvents.ensureSize (512);
#endif

#if JucePlugin_WantsMidiInput && ! JUCE_USE_VSTSDK_2_4
        wantEvents();
#endif
    }

    void suspend()
    {
#ifdef MAKE_LOG
        dbg = "suspend()";
        DBG(dbg);
#endif
        if (filter == 0)
            return;

        AudioEffectX::suspend();

        filter->releaseResources();
        outgoingEvents.freeEvents();

        isProcessing = false;
        channels.free();

        deleteTempChannels();
    }

    bool getCurrentPosition (AudioPlayHead::CurrentPositionInfo& info)
    {
        const VstTimeInfo* const ti = getTimeInfo (kVstPpqPosValid
                                                   | kVstTempoValid
                                                   | kVstBarsValid
                                                   //| kVstCyclePosValid
                                                   | kVstTimeSigValid
                                                   | kVstSmpteValid
                                                   | kVstClockValid);

        if (ti == 0 || ti->sampleRate <= 0)
            return false;

        if ((ti->flags & kVstTempoValid) != 0)
            info.bpm = ti->tempo;
        else
            info.bpm = 0.0;

        if ((ti->flags & kVstTimeSigValid) != 0)
        {
            info.timeSigNumerator = ti->timeSigNumerator;
            info.timeSigDenominator = ti->timeSigDenominator;
        }
        else
        {
            info.timeSigNumerator = 4;
            info.timeSigDenominator = 4;
        }

        info.timeInSeconds = ti->samplePos / ti->sampleRate;

        if ((ti->flags & kVstPpqPosValid) != 0)
            info.ppqPosition = ti->ppqPos;
        else
            info.ppqPosition = 0.0;

        if ((ti->flags & kVstBarsValid) != 0)
            info.ppqPositionOfLastBarStart = ti->barStartPos;
        else
            info.ppqPositionOfLastBarStart = 0.0;

        if ((ti->flags & kVstSmpteValid) != 0)
        {
            AudioPlayHead::FrameRateType rate = AudioPlayHead::fpsUnknown;
            double fps = 1.0;

            switch (ti->smpteFrameRate)
            {
            case kVstSmpte24fps:
                rate = AudioPlayHead::fps24;
                fps = 24.0;
                break;

            case kVstSmpte25fps:
                rate = AudioPlayHead::fps25;
                fps = 25.0;
                break;

            case kVstSmpte2997fps:
                rate = AudioPlayHead::fps2997;
                fps = 29.97;
                break;

            case kVstSmpte30fps:
                rate = AudioPlayHead::fps30;
                fps = 30.0;
                break;

            case kVstSmpte2997dfps:
                rate = AudioPlayHead::fps2997drop;
                fps = 29.97;
                break;

            case kVstSmpte30dfps:
                rate = AudioPlayHead::fps30drop;
                fps = 30.0;
                break;

            case kVstSmpteFilm16mm:
            case kVstSmpteFilm35mm:
                fps = 24.0;
                break;

            case kVstSmpte239fps:       fps = 23.976; break;
            case kVstSmpte249fps:       fps = 24.976; break;
            case kVstSmpte599fps:       fps = 59.94; break;
            case kVstSmpte60fps:        fps = 60; break;

            default:
                jassertfalse // unknown frame-rate..
            }

            info.frameRate = rate;
            info.editOriginTime = ti->smpteOffset / (80.0 * fps);
        }
        else
        {
            info.frameRate = AudioPlayHead::fpsUnknown;
            info.editOriginTime = 0;
        }

        info.isRecording = (ti->flags & kVstTransportRecording) != 0;
        info.isPlaying   = (ti->flags & kVstTransportPlaying) != 0 || info.isRecording;

        return true;
    }

    //==============================================================================
    VstInt32 getProgram()
    {
#ifdef MAKE_LOG
        //dbg = "getProgram(): " + String(filter->getCurrentProgram());
        //DBG(dbg);
#endif
        return filter != 0 ? filter->getCurrentProgram() : 0;
    }

    void setProgram (VstInt32 program)
    {
#ifdef MAKE_LOG
        dbg = "setProgram("+String(program)+")";
        DBG(dbg);
#endif
        if (filter != 0)
            filter->setCurrentProgram (program);
    }

    void setProgramName (char* name)
    {
#ifdef MAKE_LOG
        dbg = "setProgramName("+String(name)+")";
        DBG(dbg);
#endif
        if (filter != 0)
            filter->changeProgramName (filter->getCurrentProgram(), name);
    }

    void getProgramName (char* name)
    {
#ifdef MAKE_LOG
        dbg = "getProgramName(): " + filter->getProgramName (filter->getCurrentProgram());
        DBG(dbg);
#endif
        if (filter != 0)
            filter->getProgramName (filter->getCurrentProgram()).copyToCString (name, 24);
    }

    bool getProgramNameIndexed (VstInt32 category, VstInt32 index, char* text)
    {
#ifdef MAKE_LOG
        dbg = "getProgramNameIndexed("+String(index)+"): " + filter->getProgramName(index);
        DBG(dbg);
#endif
        if (filter != 0 && text !=0 && ((unsigned int) index) < (unsigned int) filter->getNumPrograms())
        {
            filter->getProgramName (index).copyToCString (text, 24);
            return true;
        }

        return false;
    }

    //==============================================================================
    float getParameter (VstInt32 index)
    {
        if (filter == 0)
            return 0.0f;

        jassert (((unsigned int) index) < (unsigned int) filter->getNumParameters());
        return filter->getParameter (index);
    }

    void setParameter (VstInt32 index, float value)
    {
        if (filter != 0)
        {
            jassert (((unsigned int) index) < (unsigned int) filter->getNumParameters());
            filter->setParameter (index, value);
        }
    }

    void getParameterDisplay (VstInt32 index, char* text)
    {
        if (filter != 0)
        {
            jassert (((unsigned int) index) < (unsigned int) filter->getNumParameters());
            filter->getParameterText (index).copyToCString (text, 24); // length should technically be kVstMaxParamStrLen, which is 8, but hosts will normally allow a bit more.
        }
    }

    void getParameterName (VstInt32 index, char* text)
    {
        if (filter != 0)
        {
            jassert (((unsigned int) index) < (unsigned int) filter->getNumParameters());
            filter->getParameterName (index).copyToCString (text, 16); // length should technically be kVstMaxParamStrLen, which is 8, but hosts will normally allow a bit more.
        }
    }

    void audioProcessorParameterChanged (AudioProcessor*, int index, float newValue)
    {
        setParameterAutomated (index, newValue);
    }

    void audioProcessorParameterChangeGestureBegin (AudioProcessor*, int index)
    {
        beginEdit (index);
    }

    void audioProcessorParameterChangeGestureEnd (AudioProcessor*, int index)
    {
        endEdit (index);
    }

    void audioProcessorChanged (AudioProcessor*)
    {
        updateDisplay();
    }

    bool canParameterBeAutomated (VstInt32 index)
    {
#ifdef MAKE_LOG
        dbg = "canParameterBeAutomated("+String(index)+"): " 
            + String(filter->isParameterAutomatable ((int) index));
        DBG(dbg);
#endif
        return filter != 0 && filter->isParameterAutomatable ((int) index);
    }

    class ChannelConfigComparator
    {
    public:
        static int compareElements (const short* const first, const short* const second)
        {
            if (first[0] < second[0])
                return -1;
            else if (first[0] > second[0])
                return 1;
            else if (first[1] < second[1])
                return -1;
            else if (first[1] > second[1])
                return 1;

            return 0;
        }
    };

    bool setSpeakerArrangement (VstSpeakerArrangement* pluginInput,
                                VstSpeakerArrangement* pluginOutput)
    {
        short channelConfigs[][2] = { JucePlugin_PreferredChannelConfigurations };

        Array <short*> channelConfigsSorted;
        ChannelConfigComparator comp;

        for (int i = 0; i < numElementsInArray (channelConfigs); ++i)
            channelConfigsSorted.addSorted (comp, channelConfigs[i]);

        for (int i = channelConfigsSorted.size(); --i >= 0;)
        {
            const short* const config = channelConfigsSorted.getUnchecked(i);
            bool inCountMatches  = (config[0] == pluginInput->numChannels);
            bool outCountMatches = (config[1] == pluginOutput->numChannels);

            if (inCountMatches && outCountMatches)
            {
                speakerIn = (VstSpeakerArrangementType) pluginInput->type;
                speakerOut = (VstSpeakerArrangementType) pluginOutput->type;
                numInChans = pluginInput->numChannels;
                numOutChans = pluginOutput->numChannels;

                filter->setPlayConfigDetails (numInChans, numOutChans,
                                              filter->getSampleRate(),
                                              filter->getBlockSize());
                return true;
            }
        }

        return false;
    }

    //==============================================================================
    VstInt32 getChunk (void** data, bool onlyStoreCurrentProgramData)
    {
#ifdef MAKE_LOG
		if (onlyStoreCurrentProgramData) {DBG("getChunk(preset)");}
		else {DBG("getChunk(bank)");}
#endif
        if (filter == 0)
            return 0;

        chunkMemory.setSize (0);
        if (onlyStoreCurrentProgramData)
            filter->getCurrentProgramStateInformation (chunkMemory);
        else
            filter->getStateInformation (chunkMemory);

		*data = (void*) chunkMemory.getData();

        // because the chunk is only needed temporarily by the host (or at least you'd
        // hope so) we'll give it a while and then free it in the timer callback.
        chunkMemoryTime = JUCE_NAMESPACE::Time::getApproximateMillisecondCounter();

        return (VstInt32) chunkMemory.getSize();
    }

    VstInt32 setChunk (void* data, VstInt32 byteSize, bool onlyRestoreCurrentProgramData)
    {
#ifdef MAKE_LOG
		if (onlyRestoreCurrentProgramData) {DBG("setChunk(preset)");}
		else {DBG("setChunk(bank)");}
#endif
        if (filter == 0)
            return 0;

        chunkMemory.setSize (0);
        chunkMemoryTime = 0;

        if (byteSize > 0 && data != 0)
        {
            if (onlyRestoreCurrentProgramData)
                filter->setCurrentProgramStateInformation (data, byteSize);
            else
                filter->setStateInformation (data, byteSize);
        }

        return 0;
    }

    void timerCallback()
    {
        if (shouldDeleteEditor)
        {
            shouldDeleteEditor = false;
            deleteEditor (true);
        }

        if (chunkMemoryTime > 0
             && chunkMemoryTime < JUCE_NAMESPACE::Time::getApproximateMillisecondCounter() - 2000
             && ! recursionCheck)
        {
            chunkMemoryTime = 0;
            chunkMemory.setSize (0);
        }

#if JUCE_MAC
        if (hostWindow != 0)
            checkWindowVisibility (hostWindow, editorComp);
#endif

        tryMasterIdle();
    }

    void tryMasterIdle()
    {
        if (Component::isMouseButtonDownAnywhere()
             && ! recursionCheck)
        {
            const JUCE_NAMESPACE::uint32 now = JUCE_NAMESPACE::Time::getMillisecondCounter();

            if (now > lastMasterIdleCall + 20 && editorComp != 0)
            {
                lastMasterIdleCall = now;

                recursionCheck = true;
                masterIdle();
                recursionCheck = false;
            }
        }
    }

    void doIdleCallback()
    {
        // (wavelab calls this on a separate thread and causes a deadlock)..
        if (MessageManager::getInstance()->isThisTheMessageThread()
             && ! recursionCheck)
        {
            recursionCheck = true;

            juce_callAnyTimersSynchronously();

            for (int i = ComponentPeer::getNumPeers(); --i >= 0;)
                ComponentPeer::getPeer (i)->performAnyPendingRepaintsNow();

            recursionCheck = false;
        }
    }

    void createEditorComp()
    {
    
        if (hasShutdown || filter == 0)
            return;

        if (editorComp == 0)
        {
#ifdef MAKE_LOG
			DBG("create editor");
#endif
            AudioProcessorEditor* const ed = filter->createEditorIfNeeded();

            if (ed != 0)
            {
                cEffect.flags |= effFlagsHasEditor;
                ed->setOpaque (true);
                ed->setVisible (true);

                editorComp = new EditorCompWrapper (this, ed);
            }
            else
            {
                cEffect.flags &= ~effFlagsHasEditor;
            }
        }

        shouldDeleteEditor = false;
    }

    void deleteEditor (bool canDeleteLaterIfModal)
    {
#ifdef MAKE_LOG
        dbg = "delete editor";
        DBG(dbg);
#endif
        PopupMenu::dismissAllActiveMenus();

        jassert (! recursionCheck);
        recursionCheck = true;

        if (editorComp != 0)
        {
            Component* const modalComponent = Component::getCurrentlyModalComponent();
            if (modalComponent != 0)
            {
                modalComponent->exitModalState (0);

                if (canDeleteLaterIfModal)
                {
                    shouldDeleteEditor = true;
                    recursionCheck = false;
                    return;
                }
            }

#if JUCE_MAC
            if (hostWindow != 0)
            {
                detachComponentFromWindowRef (editorComp, hostWindow);
                hostWindow = 0;
            }
#endif

            filter->editorBeingDeleted (editorComp->getEditorComp());

            deleteAndZero (editorComp);

            // there's some kind of component currently modal, but the host
            // is trying to delete our plugin. You should try to avoid this happening..
            jassert (Component::getCurrentlyModalComponent() == 0);
        }

#if JUCE_LINUX
        hostWindow = 0;
#endif

        recursionCheck = false;
    }

    VstIntPtr dispatcher (VstInt32 opCode, VstInt32 index, VstIntPtr value, void* ptr, float opt)
    {
#if 0
        String o;
        switch(opCode)
        {
        case effOpen:
        case effClose:
        case effSetProgram:
        case effGetProgram:
        case effSetProgramName:
        case effGetProgramName:
        case effGetParamLabel:
        case effGetParamDisplay:
        case effGetParamName:
        case effSetSampleRate:
        case effSetBlockSize:
        case effMainsChanged:
        case effEditGetRect:
        case effEditOpen:
        case effEditClose:
        case effEditIdle:
        case effGetChunk:
        case effSetChunk:
        case effProcessEvents:
        case effCanBeAutomated:
        case effString2Parameter:
        case effGetProgramNameIndexed:
        case effGetInputProperties:
        case effGetOutputProperties:
        case effGetPlugCategory:
        case effOfflineNotify:
        case effOfflinePrepare:
        case effOfflineRun:
        case effProcessVarIo:
        case effSetSpeakerArrangement:
        case effSetBypass:
        case effGetEffectName:
        case effGetVendorString:
        case effGetProductString:
        case effGetVendorVersion:
        case effVendorSpecific:
        case effCanDo:
        case effGetTailSize:
        case 53: //effIdle;
        case effGetParameterProperties:
        case effGetVstVersion:
        case effEditKeyDown:
        case effEditKeyUp:
        case effSetEditKnobMode:
        case effGetMidiProgramName:
        case effGetCurrentMidiProgram:
        case effGetMidiProgramCategory:
        case effHasMidiProgramsChanged:
        case effGetMidiKeyName:
        case effBeginSetProgram:
        case effEndSetProgram:
        case effGetSpeakerArrangement:
        case effShellGetNextPlugin:
        case effStartProcess:
        case effStopProcess:
        case effSetTotalSampleToProcess:
        case effSetPanLaw:
        case effBeginLoadBank:
        case effBeginLoadProgram:
        case effSetProcessPrecision:
        case effGetNumMidiInputChannels:
        case effGetNumMidiOutputChannels:
		default:
        dbg = "dispatcher("
            +String(opCode)+","
            +String(index)+","
			+String(value)+","
			+String((int)(&ptr))+","
			+String(opt)+")"
			;
		DBG(dbg);
		}
#endif
		if (hasShutdown)
			return 0;

		if (opCode == effEditKeyDown || opCode == effEditKeyUp)
		{

#if JUCE_WIN32
			if (editorComp!=0)
			{
				int keyCode, textCharacter;
				convertVstKeyInputToKeyCodeAndTextCharacter(opCode, value, index, keyCode, textCharacter);

				ComponentPeer *peer=editorComp->getPeer();
				if (peer!=0)
					if (keyCode!=0 || textCharacter!=0)
						peer->handleKeyPress (keyCode, textCharacter);

				return 1;
			}
#endif
			return 0;
		}
		else if (opCode == effEditIdle)
		{
			doIdleCallback();
            return 0;
        }
        else if (opCode == effEditOpen)
        {
            checkWhetherWavelabHasChangedThread();
            const MessageManagerLock mmLock;
            jassert (! recursionCheck);

            deleteEditor (true);
            createEditorComp();

            if (editorComp != 0)
            {
                editorComp->setOpaque (true);
                editorComp->setVisible (false);

#if JUCE_WIN32
                editorComp->addToDesktop (0);
                hostWindow = (HWND) ptr;
                HWND editorWnd = (HWND) editorComp->getWindowHandle();
                SetParent (editorWnd, hostWindow);

                DWORD val = GetWindowLong (editorWnd, GWL_STYLE);
                val = (val & ~WS_POPUP) | WS_CHILD;
                SetWindowLong (editorWnd, GWL_STYLE, val);
#elif JUCE_LINUX
                editorComp->addToDesktop (0);
                hostWindow = (Window) ptr;
                Window editorWnd = (Window) editorComp->getWindowHandle();
                XReparentWindow (display, editorWnd, hostWindow, 0, 0);
#else
                hostWindow = attachComponentToWindowRef (editorComp, (WindowRef) ptr);
#endif
                editorComp->setVisible (true);

                return 1;
            }
        }
        else if (opCode == effEditClose)
        {
            checkWhetherWavelabHasChangedThread();
            const MessageManagerLock mmLock;
            deleteEditor (true);
            return 0;
        }
        else if (opCode == effEditGetRect)
        {
            checkWhetherWavelabHasChangedThread();
            const MessageManagerLock mmLock;
            createEditorComp();

            if (editorComp != 0)
            {
                editorSize.left = 0;
                editorSize.top = 0;
                editorSize.right = editorComp->getWidth();
                editorSize.bottom = editorComp->getHeight();

                *((ERect**) ptr) = &editorSize;

                return (VstIntPtr) (pointer_sized_int) &editorSize;
            }
            else
            {
                return 0;
            }
        }

        return AudioEffectX::dispatcher (opCode, index, value, ptr, opt);
    }

    void resizeHostWindow (int newWidth, int newHeight)
    {
        if (editorComp != 0)
        {
#if ! JUCE_LINUX // linux hosts shouldn't be trusted!
            if (! (canHostDo (const_cast <char*> ("sizeWindow")) && sizeWindow (newWidth, newHeight)))
#endif
            {
                // some hosts don't support the sizeWindow call, so do it manually..
#if JUCE_MAC
                setNativeHostWindowSize (hostWindow, editorComp, newWidth, newHeight);
#elif JUCE_LINUX
                Window root;
                int x, y;
                unsigned int width, height, border, depth;

                XGetGeometry (display, hostWindow, &root,
                              &x, &y, &width, &height, &border, &depth);

                newWidth += (width + border) - editorComp->getWidth();
                newHeight += (height + border) - editorComp->getHeight();

                XResizeWindow (display, hostWindow, newWidth, newHeight);
#else
                int dw = 0;
                int dh = 0;
                const int frameThickness = GetSystemMetrics (SM_CYFIXEDFRAME);

                HWND w = (HWND) editorComp->getWindowHandle();

                while (w != 0)
                {
                    HWND parent = GetParent (w);

                    if (parent == 0)
                        break;

                    TCHAR windowType [32];
                    zeromem (windowType, sizeof (windowType));
                    GetClassName (parent, windowType, 31);

                    if (String (windowType).equalsIgnoreCase ("MDIClient"))
                        break;

                    RECT windowPos;
                    GetWindowRect (w, &windowPos);

                    RECT parentPos;
                    GetWindowRect (parent, &parentPos);

                    SetWindowPos (w, 0, 0, 0,
                                  newWidth + dw,
                                  newHeight + dh,
                                  SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);

                    dw = (parentPos.right - parentPos.left) - (windowPos.right - windowPos.left);
                    dh = (parentPos.bottom - parentPos.top) - (windowPos.bottom - windowPos.top);

                    w = parent;

                    if (dw == 2 * frameThickness)
                        break;

                    if (dw > 100 || dh > 100)
                        w = 0;
                }

                if (w != 0)
                    SetWindowPos (w, 0, 0, 0,
                                  newWidth + dw,
                                  newHeight + dh,
                                  SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);
#endif
            }

            if (editorComp->getPeer() != 0)
                editorComp->getPeer()->handleMovedOrResized();
        }
    }


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    PizAudioProcessor* filter;
    JUCE_NAMESPACE::MemoryBlock chunkMemory;
    JUCE_NAMESPACE::uint32 chunkMemoryTime;
    EditorCompWrapper* editorComp;
    ERect editorSize;
    MidiBuffer midiEvents;
    VSTMidiEventList outgoingEvents;
    bool isProcessing;
    bool hasShutdown;
    bool firstProcessCallback;
    int diffW, diffH;
    VstSpeakerArrangementType speakerIn, speakerOut;
    int numInChans, numOutChans;
    HeapBlock <float*> channels;
    Array<void*> tempChannels; // see note in processReplacing()
    bool hasCreatedTempChannels;
    bool shouldDeleteEditor;

    //==============================================================================
    static PluginHostType& getHostType()
    {
        static PluginHostType hostType;
        return hostType;
    }

#if JUCE_WINDOWS   // Workarounds for Wavelab's happy-go-lucky use of threads.
    class NonWavelabMMLock
    {
    public:
        NonWavelabMMLock() : mm (getHostType().isWavelab() ? 0 : new MessageManagerLock())  {}
        ~NonWavelabMMLock() {}

    private:
        ScopedPointer <MessageManagerLock> mm;
    };

    static void checkWhetherWavelabHasChangedThread()
    {
        if (getHostType().isWavelab())
            MessageManager::getInstance()->setCurrentThreadAsMessageThread();
    }
#else
    typedef MessageManagerLock NonWavelabMMLock;
    static void checkWhetherWavelabHasChangedThread() {}
#endif

    //==============================================================================
    void deleteTempChannels()
    {
        for (int i = tempChannels.size(); --i >= 0;)
            juce_free (tempChannels.getUnchecked(i));

        tempChannels.clear();

        if (filter != 0)
            tempChannels.insertMultiple (0, 0, filter->getNumInputChannels() + filter->getNumOutputChannels());

        hasCreatedTempChannels = false;
    }

    const String getHostName()
    {
        char host[256];
        zeromem (host, sizeof (host));
        getHostProductString (host);
        return host;
    }

    const String getHostVendor()
    {
        char host[256];
        zeromem (host, sizeof (host));
        getHostVendorString (host);
        return host;
    }

#if JUCE_MAC
    void* hostWindow;
#elif JUCE_LINUX
    Window hostWindow;
#else
    HWND hostWindow;
#endif
};

//==============================================================================
void EditorCompWrapper::childBoundsChanged (Component* child)
{
    child->setTopLeftPosition (0, 0);

    const int cw = child->getWidth();
    const int ch = child->getHeight();

    wrapper->resizeHostWindow (cw, ch);
    setSize (cw, ch);

#if JUCE_MAC
    wrapper->resizeHostWindow (cw, ch);  // (doing this a second time seems to be necessary in tracktion)
#endif
}

void EditorCompWrapper::handleAsyncUpdate()
{
    wrapper->tryMasterIdle();
}

//==============================================================================
/** Somewhere in the codebase of your plugin, you need to implement this function
    and make it create an instance of the filter subclass that you're building.
*/
extern PizAudioProcessor* JUCE_CALLTYPE createPluginFilter();


//==============================================================================
static AEffect* pluginEntryPoint (audioMasterCallback audioMaster)
{
    initialiseJuce_GUI();

    try
    {
        if (audioMaster (0, audioMasterVersion, 0, 0, 0, 0) != 0)
        {
            PizAudioProcessor* const filter = createPluginFilter();

            if (filter != 0)
            {
                JuceVSTWrapper* const wrapper = new JuceVSTWrapper (audioMaster, filter);
                return wrapper->getAeffect();
            }
        }
    }
    catch (...)
    {}

    return 0;
}


//==============================================================================
// Mac startup code..
#if JUCE_MAC

extern "C" __attribute__ ((visibility("default"))) AEffect* VSTPluginMain (audioMasterCallback audioMaster)
{
    initialiseMac();
    return pluginEntryPoint (audioMaster);
}

extern "C" __attribute__ ((visibility("default"))) AEffect* main_macho (audioMasterCallback audioMaster)
{
    initialiseMac();
    return pluginEntryPoint (audioMaster);
}

String getHostPath() {
    return File::getCurrentWorkingDirectory().getFullPathName();
}

//==============================================================================
// Linux startup code..
#elif JUCE_LINUX

extern "C" AEffect* VSTPluginMain (audioMasterCallback audioMaster)
{
    SharedMessageThread::getInstance();

    return pluginEntryPoint (audioMaster);
}

extern "C" __attribute__ ((visibility("default"))) AEffect* main_plugin (audioMasterCallback audioMaster) asm ("main");

extern "C" __attribute__ ((visibility("default"))) AEffect* main_plugin (audioMasterCallback audioMaster)
{
    return VSTPluginMain (audioMaster);
}

__attribute__((constructor)) void myPluginInit()
{
    // don't put initialiseJuce_GUI here... it will crash !
}

__attribute__((destructor)) void myPluginFini()
{
    // don't put shutdownJuce_GUI here... it will crash !
}

String getHostPath() {
    return File::getCurrentWorkingDirectory().getFullPathName();
}

//==============================================================================
// Win32 startup code..
#else

extern "C" __declspec (dllexport) AEffect* VSTPluginMain (audioMasterCallback audioMaster)
{
    return pluginEntryPoint (audioMaster);
}

#ifndef _WIN64 // (can't compile this on win64, but it's not needed anyway with VST2.4)
extern "C" __declspec (dllexport) void* main (audioMasterCallback audioMaster)
{
    return (void*) pluginEntryPoint (audioMaster);
}
#endif

#if JucePlugin_Build_RTAS
BOOL WINAPI DllMainVST (HINSTANCE instance, DWORD dwReason, LPVOID)
#else
extern "C" BOOL WINAPI DllMain (HINSTANCE instance, DWORD dwReason, LPVOID)
#endif
{

    if (dwReason == DLL_PROCESS_ATTACH)
        PlatformUtilities::setCurrentModuleInstanceHandle (instance);

    return TRUE;
}

String getHostPath( )
{
   char outInstancePath[256];
   memset ( outInstancePath, 0, 256* sizeof( char ) );

   WCHAR filename[256];
   memset ( filename, 0, 256* sizeof( WCHAR ) );

   DWORD success = GetModuleFileNameW( NULL, filename, 255 );


   if ( success )
   {
      int err = WideCharToMultiByte (
                     0,
                     0,
                     filename,
                     success,
                     outInstancePath,
                     511,
                     NULL,
                     NULL
                  );
	  (void)err;
   }
   else
   {
	   success = GetModuleFileNameA( NULL, outInstancePath, 255 );
   }

   const char* checkString = ".exe";

   int foundloc = 0;
   int countloc = 0;

   for ( int i = 0; i < 256; i++ )
   {
      if ( outInstancePath[ i ] == checkString[ foundloc++ ] )
      {
         if ( foundloc == 4 ) break;
      }
      else
         foundloc = 0;

      countloc++;
   }

   countloc -= 4;

   if ( countloc < 3 )
   {
      countloc = 4;
   }

   for ( int i = countloc; i > 0; i-- )
   {
      if ( outInstancePath[ i ] == '\\' )
      {
         outInstancePath[ i + 1 ] = 0;
         break;
      }
   }
   DBG(outInstancePath);

   return String (outInstancePath);
}

#endif

JuceVSTWrapper::JuceVSTWrapper (audioMasterCallback audioMaster,
                PizAudioProcessor* const filter_)
   : AudioEffectX (audioMaster,
                   filter_->getNumPrograms(),
                   filter_->getNumParameters()),
     filter (filter_)
{
    DBG("start VST constructor");
    editorComp = 0;
    chunkMemoryTime = 0;
    isProcessing = false;
    hasShutdown = false;
    firstProcessCallback = true;
    shouldDeleteEditor = false;
	speakerIn = kSpeakerArrEmpty;
	speakerOut = kSpeakerArrEmpty;
    numInChans = JucePlugin_MaxNumInputChannels;
    numOutChans = JucePlugin_MaxNumOutputChannels;

//PIZ=================================================
    bool inst = JucePlugin_IsSynth!=0;
    String currentFileName = File::getSpecialLocation(File::currentApplicationFile).getFileNameWithoutExtension();
    DBG(currentFileName);
#ifdef PIZMIDI
#define PIZ_FX_MAGIC 1
    String hostname = getHostVendor();
    String hostproduct = getHostName();
    if (!hostname.isEmpty()) {
        if (hostname.contains("Ableton")) {
            inst=true;
            numOutChans=2;
        }
        else if (hostname.contains("Steinberg")) {
            inst=true;
            numOutChans=2;
        }
        else if (hostname.contains("Twelve Tone")) {
            inst=true;
            numOutChans=2;
        }
        else if (hostname.contains("Image-Line")) {
            inst=true;
            numInChans=2;
            numOutChans=2;
        }
        else if (hostname.contains("Polac")) {
            inst=true;
            numOutChans=0;
        }
        else if (hostname.contains("Native Instruments")) {
            inst=false;
			numInChans=2;
            numOutChans=2;
        }
        else if (hostname.contains("brainspawn")) {
            inst=true;
			numInChans=2;
            numOutChans=2;
        }
	}
    if (!inst && numOutChans) numInChans=numOutChans;

    hostname = getHostName();
    if (hostname.isEmpty()) hostname="unknown";

    //read "pizmidi.ini" in plugin's directory
	String pizmidiIniPath = File::getSpecialLocation(File::currentApplicationFile).getParentDirectory().getFullPathName() 
		+ File::separatorString + "pizmidi.ini";
    if (!File(pizmidiIniPath).exists()) {
		pizmidiIniPath = File::getSpecialLocation(File::userApplicationDataDirectory).getFullPathName() 
			 + File::separatorString + "pizmidi" + File::separatorString + "pizmidi.ini";
		if (!File(pizmidiIniPath).exists()) {
			pizmidiIniPath = File::getSpecialLocation(File::commonApplicationDataDirectory).getFullPathName()
				+ File::separatorString + "pizmidi" + File::separatorString + "pizmidi.ini";
		}
	}
    if (File(pizmidiIniPath).exists()) {
        StringArray lines;
        lines.addLines(File(pizmidiIniPath).loadFileAsString());
        bool hostmatch=false;
        for (int i=0;i<lines.size();i++) {
			DBG(lines[i]);
            if (!lines[i].startsWithChar(';')) {
				if (lines[i].startsWith("default")) {
                    hostmatch=true;
                }
                else if (lines[i].contains("host=" + hostname)) {
                    hostmatch=true;
                }
                else if (lines[i].contains("host=")) {
                    hostmatch=false;
                }
                if (hostmatch) {
                    if      (lines[i].equalsIgnoreCase("force inst"))    inst=true;
                    else if (lines[i].equalsIgnoreCase("force effect"))  inst=false;
                    else if (lines[i].equalsIgnoreCase("audio outs"))    numOutChans = 2;
                    else if (lines[i].equalsIgnoreCase("no audio outs")) numOutChans = 0;
                    else if (lines[i].equalsIgnoreCase("audio ins"))     numInChans = 2;
                    else if (lines[i].equalsIgnoreCase("no audio ins"))  numInChans = 0;
					else if (lines[i].startsWithIgnoreCase("bottom octave=")) {
						filter->bottomOctave = lines[i].substring(14).getIntValue();
					};
                }
            }
        }
    }
#else 
    String hostname = getHostName();
#endif

	if (hostname=="REAPER") {
		filter->reaper = true;
		if (audioMaster(NULL,0xdeadbeef,0xdeadf00d,0,"TimeMap2_timeToBeats",0.0))
			*(long *)&(filter->TimeMap2_timeToBeats) = (long)audioMaster(NULL,0xdeadbeef,0xdeadf00d,0,"TimeMap2_timeToBeats",0.0);
		else filter->reaper = false;
		if (audioMaster(NULL,0xdeadbeef,0xdeadf00d,0,"GetPlayPosition",0.0))
			*(long *)&(filter->GetPlayPosition) = (long)audioMaster(NULL,0xdeadbeef,0xdeadf00d,0,"GetPlayPosition",0.0);
		else filter->reaper = false;
		if (audioMaster(NULL,0xdeadbeef,0xdeadf00d,0,"GetCursorPosition",0.0))
			*(long *)&(filter->GetCursorPosition) = (long)audioMaster(NULL,0xdeadbeef,0xdeadf00d,0,"GetCursorPosition",0.0);
		else filter->reaper = false;
	}

    int VSTID = (int)(JucePlugin_VSTUniqueID);
#if PIZ_FX_MAGIC
#ifndef Piz_InstID
#define Piz_InstID JucePlugin_VSTUniqueID
#endif
#ifndef Piz_EffectID
#define Piz_EffectID JucePlugin_VSTUniqueID
#endif
    if (currentFileName.containsIgnoreCase("nofx")) {
        //force instrument only
        numInChans = 0;
        inst = true;
        VSTID = (int)(Piz_InstID);
    }
    if (currentFileName.containsIgnoreCase("_inst")) {
        //force instrument only
        numInChans = 0;
        inst = true;
        VSTID = (int)(Piz_InstID);
    }
	else if (currentFileName.containsIgnoreCase("fx")) {
        //force effect only
        numInChans = 2;
        inst = false;
        VSTID = (int)(Piz_EffectID);
	}
#endif
    setUniqueID (VSTID);

#ifndef PIZ_NO_GUI
    if (!currentFileName.containsIgnoreCase("noGUI")) {
        cEffect.flags |= effFlagsHasEditor;
    }
#endif
//====================================================

#if JUCE_MAC || JUCE_LINUX
    hostWindow = 0;
#endif

    filter->setPlayConfigDetails (numInChans, numOutChans, 0, 0);

    filter_->setPlayHead (this);
    filter_->addListener (this);
    cEffect.version = (long) (JucePlugin_VersionCode);


#if JucePlugin_WantsMidiInput && ! JUCE_USE_VSTSDK_2_4
    wantEvents();
#endif


    canProcessReplacing (true);

#if ! JUCE_USE_VSTSDK_2_4
    hasVu (false);
    hasClip (false);
#endif

//PIZ=================================================
    isSynth (inst);
//====================================================
    setNumInputs (numInChans);
    setNumOutputs (numOutChans);

    noTail ((JucePlugin_SilenceInProducesSilenceOut) != 0);
    setInitialDelay (filter->getLatencySamples());
    programsAreChunks (true);

    activePlugins.add (this);

#ifdef MAKE_LOG
    DBG("===HOST INFO===");
    dbg = "canHostDo(sendVstEvents): " + String(canHostDo("sendVstEvents"));
    DBG(dbg);
    dbg = "canHostDo(sendVstMidiEvent): " + String(canHostDo("sendVstMidiEvent"));
    DBG(dbg);
    dbg = "canHostDo(sendVstTimeInfo): " + String(canHostDo("sendVstTimeInfo"));
    DBG(dbg);
    dbg = "canHostDo(receiveVstEvents): " + String(canHostDo("receiveVstEvents"));
    DBG(dbg);
    dbg = "canHostDo(receiveVstMidiEvent): " + String(canHostDo("receiveVstMidiEvent"));
    DBG(dbg);
    dbg = "canHostDo(reportConnectionChanges): " + String(canHostDo("reportConnectionChanges"));
    DBG(dbg);
    dbg = "canHostDo(acceptIOChanges): " + String(canHostDo("acceptIOChanges"));
    DBG(dbg);
    dbg = "canHostDo(sizeWindow): " + String(canHostDo("sizeWindow"));
    DBG(dbg);
    dbg = "canHostDo(offline): " + String(canHostDo("offline"));
    DBG(dbg);
    dbg = "canHostDo(openFileSelector): " + String(canHostDo("openFileSelector"));
    DBG(dbg);
    dbg = "canHostDo(closeFileSelector): " + String(canHostDo("closeFileSelector"));
    DBG(dbg);
    dbg = "canHostDo(startStopProcess): " + String(canHostDo("startStopProcess"));
    DBG(dbg);
    dbg = "canHostDo(shellCategory): " + String(canHostDo("shellCategory"));
    DBG(dbg);
    dbg = "canHostDo(sendVstMidiEventFlagIsRealtime): " + String(canHostDo("sendVstMidiEventFlagIsRealtime"));
    DBG(dbg);

    char* text = new char[256];
	if (getHostVendorString(text)) {DBG("getHostVendorString(): "+String(text));}
	else {DBG("getHostVendorString(): (false)");}
    DBG(dbg);
    dbg = getHostProductString(text)? ("getHostProductString(): " +String(text)) : "getHostProductString(): (false)";
    DBG(dbg);
    dbg = "getHostVendorVersion(): " + String(getHostVendorVersion());
    DBG(dbg);
    dbg = "getHostLanguage(): " + String(getHostLanguage());
    DBG(dbg);
	delete [] text;

    //DBG("===PLUGIN INFO===");
#endif

}

#endif
