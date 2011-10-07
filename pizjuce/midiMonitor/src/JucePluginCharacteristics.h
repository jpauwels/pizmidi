#ifndef __MIDIMONITOR_PLUGIN_CHARACTERISTICS_H__
#define __MIDIMONITOR_PLUGIN_CHARACTERISTICS_H__

//==============================================================================
/*                          Plugin Formats to build                           */
#ifndef JucePlugin_Build_Standalone
 #define JucePlugin_Build_Standalone 0
#endif

#ifndef JucePlugin_Build_VSTMA
 #define JucePlugin_Build_VSTMA	0
#endif

#if ! JucePlugin_Build_Standalone && ! JucePlugin_Build_VSTMA
 #define JucePlugin_Build_VST            1
 #define JucePlugin_Build_RTAS           0
 #define JucePlugin_Build_AU             0
#endif

#define JucePlugin_Website				"http://thepiz.org"
#define JucePlugin_Email				"piz@thepiz.org"
#define JucePlugin_GUID1				0x6ADB48DE
#define JucePlugin_GUID2				0x2B4D4F45
#define JucePlugin_GUID3				0xB67E2568
#define JucePlugin_GUID4				0x52346B99

//==============================================================================
/*                              Generic settings                              */
#define JucePlugin_Name								"midiMonitor"
#define JucePlugin_Desc								"piz midi monitor"
#define JucePlugin_Manufacturer						"Insert Piz Here"
#define JucePlugin_ManufacturerCode					'IPHz'
#define JucePlugin_IsSynth                          1
#define Piz_InstID									'mmMM'
#define Piz_EffectID								'mmMx'
#if JucePlugin_IsSynth
  #define JucePlugin_PluginCode						Piz_InstID
#else
  #define JucePlugin_PluginCode						Piz_EffectID
#endif
#define PIZMIDI										1
#define JucePlugin_MaxNumInputChannels              2
#define JucePlugin_MaxNumOutputChannels             2
#define JucePlugin_PreferredChannelConfigurations   { 2, 2 }
#define JucePlugin_TailLengthSeconds				0
#define JucePlugin_WantsMidiInput                   1
#define JucePlugin_ProducesMidiOutput               1
#define JucePlugin_SilenceInProducesSilenceOut      0
#define JucePlugin_EditorRequiresKeyboardFocus      0
#define JucePlugin_VersionCode						0x00010300
#define JucePlugin_VersionString					"1.3"

//==============================================================================
/*                                VST settings                                */
#define JUCE_USE_VSTSDK_2_4                 1
#define JucePlugin_VSTUniqueID              JucePlugin_PluginCode
#if JucePlugin_IsSynth
  #define JucePlugin_VSTCategory            kPlugCategSynth
#else
  #define JucePlugin_VSTCategory            kPlugCategEffect
#endif

//==============================================================================
/*                              AudioUnit settings                            */
#if JucePlugin_IsSynth
  #define JucePlugin_AUMainType             kAudioUnitType_MusicEffect
#else
  #define JucePlugin_AUMainType             kAudioUnitType_Effect
#endif
#define JucePlugin_AUSubType                JucePlugin_PluginCode
#define JucePlugin_AUExportPrefix           midiMonitorAU
#define JucePlugin_AUExportPrefixQuoted     "midiMonitorAU"
#define JucePlugin_AUManufacturerCode       JucePlugin_ManufacturerCode
#define JucePlugin_CFBundleIdentifier       "org.thepiz.midiMonitor"

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
