#ifndef __MIDIPADS_PLUGIN_CHARACTERISTICS_H__
#define __MIDIPADS_PLUGIN_CHARACTERISTICS_H__

//==============================================================================
/*                          Plugin Formats to build                           */
#ifndef JucePlugin_Build_Standalone
 #define JucePlugin_Build_Standalone	0
#endif

#if ! JucePlugin_Build_Standalone
 #define JucePlugin_Build_VST           1
 #define JucePlugin_Build_RTAS          0
 #define JucePlugin_Build_AU            1
#endif

//==============================================================================
/*                              Generic settings                              */
#define JucePlugin_Name                             "midiPads"
#define JucePlugin_Desc                             "piz midi pads"
#define JucePlugin_Manufacturer                     "Insert Piz Here"
#define JucePlugin_ManufacturerCode                 'IPHz'
#define JucePlugin_PluginCode                       'm16p'
#define JucePlugin_VersionCode                      0x00010500
#define JucePlugin_VersionString                    "1.5"
#define PIZMIDI										1
#define JucePlugin_MaxNumInputChannels              2
#define JucePlugin_MaxNumOutputChannels             2
#define JucePlugin_PreferredChannelConfigurations   { 2, 2 }
#define JucePlugin_IsSynth                          1
#define JucePlugin_WantsMidiInput                   1
#define JucePlugin_ProducesMidiOutput               1
#define JucePlugin_SilenceInProducesSilenceOut      0
#define JucePlugin_EditorRequiresKeyboardFocus      0
#define JucePlugin_TailLengthSeconds				0

//==============================================================================
/*                                VST settings                                */
#define JUCE_USE_VSTSDK_2_4                 1
#define JucePlugin_VSTUniqueID              JucePlugin_PluginCode
#if JucePlugin_IsSynth
 #define JucePlugin_VSTCategory             kPlugCategSynth
#else
 #define JucePlugin_VSTCategory             kPlugCategEffect
#endif

//==============================================================================
/*                              AudioUnit settings                            */
#if JucePlugin_IsSynth
 #define JucePlugin_AUMainType              kAudioUnitType_MusicEffect
#else
 #define JucePlugin_AUMainType              kAudioUnitType_Effect
#endif

#define JucePlugin_AUSubType                JucePlugin_PluginCode
#define JucePlugin_AUExportPrefix           midiPadsAU
#define JucePlugin_AUExportPrefixQuoted     "midiPadsAU"
#define JucePlugin_AUCocoaViewClassName		midiPadsAU_V1
#define JucePlugin_AUManufacturerCode       JucePlugin_ManufacturerCode
#define JucePlugin_CFBundleIdentifier       "org.thepiz.midiPadsAU"

//==============================================================================
/*                                RTAS settings                               */
#if JucePlugin_IsSynth
  #define JucePlugin_RTASCategory           ePlugInCategory_SWGenerators
#else
  #define JucePlugin_RTASCategory           ePlugInCategory_None
#endif

#define JucePlugin_RTASManufacturerCode     JucePlugin_ManufacturerCode
#define JucePlugin_RTASProductId            JucePlugin_PluginCode


//==============================================================================

#endif
