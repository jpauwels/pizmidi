
/*
    This file includes the entire juce source tree via the amalgamated file.

    You could add the amalgamated file directly to your project, but doing it
    like this allows you to put your app's config settings in the
    juce_AppConfig.h file and have them applied to both the juce headers and
    the source code.
*/

#include "AppConfig.h"
#ifdef _DEBUG
#include "amalgamation/juce_amalgamated_template.cpp"
#else
#include "juce_amalgamated.cpp"
#endif
