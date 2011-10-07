piz midi plugins
by Insert Piz Here->

You need the VST SDK version 2.4, available from Steinberg:
http://www.steinberg.net/en/company/3rd_party_developer.html

Put the SDK files into "vstsdk2.4" folder, maintaining folder structure.
	At least the contents of these two folders are required:
	vstsdk2.4/public.sdk/source/vst2.x
	vstsdk2.4/pluginterfaces/vst2.x

	
To compile in Linux:

- Change "vstsdk2.4/pluginterfaces/vst2.x/aeffect.h" as follows.

// ORIGINAL @ line 37

#elif defined(__GNUC__)
	#pragma pack(push,8)
    	#define VSTCALLBACK __cdecl



// REPLACE @ line 37

#elif defined(__GNUC__)
	#pragma pack(push,8)
	#if defined(__linux__)
		#define VSTCALLBACK
	#else
    	#define VSTCALLBACK __cdecl
    #endif


- Open a terminal, cd to "pizmidi" folder, and "make all"

- Compiled plugins are in "pizmidi/release" folder.


To compile in Windows:

- Open "pizmidi.sln" in Microsoft Visual C++ and "Build Solution"


To compile in Mac OS X:

- Open "pizmidi.xcodeproj" in XCode and build the "pizmidi" target