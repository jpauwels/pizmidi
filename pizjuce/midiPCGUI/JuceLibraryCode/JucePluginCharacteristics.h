/*

    IMPORTANT! This file is auto-generated each time you save your
    project - if you alter its contents, your changes may be overwritten!

    This header file contains configuration options for the plug-in. If you need to change any of
    these, it'd be wise to do so using the Jucer, rather than editing this file directly...

*/

#ifndef __PLUGINCHARACTERISTICS_JJSENAUIU__
#define __PLUGINCHARACTERISTICS_JJSENAUIU__

#define JucePlugin_Build_VST    1  // (If you change this value, you'll also need to re-export the projects using the Jucer)
#define JucePlugin_Build_AU     0  // (If you change this value, you'll also need to re-export the projects using the Jucer)
#define JucePlugin_Build_RTAS   0  // (If you change this value, you'll also need to re-export the projects using the Jucer)
#define JucePlugin_Build_VSTMA	1

#define JucePlugin_Website				"http://thepiz.org"
#define JucePlugin_Email				"piz@thepiz.org"
#define JucePlugin_GUID1				0x3e9c7567
#define JucePlugin_GUID2				0xcbfc4510
#define JucePlugin_GUID3				0x8a65e731
#define JucePlugin_GUID4				0xf237ed98
#define JucePlugin_Name                 "midiPCGUI"
#define JucePlugin_Desc                 "MIDI Program Change plugin (with GUI)"
#define JucePlugin_Manufacturer         "Insert Piz Here"
#define JucePlugin_ManufacturerCode     'IPHz'
#define JucePlugin_PluginCode           'mpcg'
#define JucePlugin_MaxNumInputChannels  0
#define JucePlugin_MaxNumOutputChannels 2
#define JucePlugin_PreferredChannelConfigurations   {0, 1}, {0, 2}
#define JucePlugin_IsSynth              1
#define JucePlugin_WantsMidiInput       1
#define JucePlugin_ProducesMidiOutput   1
#define JucePlugin_SilenceInProducesSilenceOut  0
#define JucePlugin_TailLengthSeconds    0
#define JucePlugin_EditorRequiresKeyboardFocus  0
#define JucePlugin_VersionCode          0x10200
#define JucePlugin_VersionString        "1.2.0"
#define JucePlugin_VSTUniqueID          JucePlugin_PluginCode
#define JucePlugin_VSTCategory          kPlugCategSynth
#define JucePlugin_AUMainType           kAudioUnitType_MusicDevice
#define JucePlugin_AUSubType            JucePlugin_PluginCode
#define JucePlugin_AUExportPrefix       midiPCGUIAU
#define JucePlugin_AUExportPrefixQuoted "midiPCGUIAU"
#define JucePlugin_AUManufacturerCode   JucePlugin_ManufacturerCode
#define JucePlugin_CFBundleIdentifier   org.thepiz.midiPCGUI
#define JucePlugin_AUCocoaViewClassName midiPCGUIAU_V1
#define JucePlugin_RTASCategory         ePlugInCategory_SWGenerators
#define JucePlugin_RTASManufacturerCode JucePlugin_ManufacturerCode
#define JucePlugin_RTASProductId        JucePlugin_PluginCode
#define JUCE_USE_VSTSDK_2_4             1

#endif   // __PLUGINCHARACTERISTICS_JJSENAUIU__
