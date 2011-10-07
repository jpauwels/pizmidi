#include "juce_amalgamated.h"
#include "juce_StandaloneFilterWindow.h"

//==============================================================================
/** This is the application object that is started up when Juce starts. It handles
    the initialisation and shutdown of the whole application.
*/
class StandalonePizPlugin : public JUCEApplication
{
    /* Important! NEVER embed objects directly inside your JUCEApplication class! Use
       ONLY pointers to objects, which you should create during the initialise() method
       (NOT in the constructor!) and delete in the shutdown() method (NOT in the
       destructor!)

       This is because the application object gets created before Juce has been properly
       initialised, so any embedded objects would also get constructed too soon.
   */
    StandaloneFilterWindow* window;

public:
    //==============================================================================
    StandalonePizPlugin()
        : window (0)
    {
        // NEVER do anything in here that could involve any Juce function being called
        // - leave all your startup tasks until the initialise() method.
    }

    ~StandalonePizPlugin()
    {
        // Your shutdown() method should already have done all the things necessary to
        // clean up this app object, so you should never need to put anything in
        // the destructor.

        // Making any Juce calls in here could be very dangerous...
    }

    //==============================================================================
    void initialise (const String& commandLine)
    {
        // just create the main window...
		ApplicationProperties* appProperties = ApplicationProperties::getInstance(); 

		appProperties->setStorageParameters (JucePlugin_Name,
											 "xml",
											 ((File::getSpecialLocation(File::currentExecutableFile)).getParentDirectory()).getFullPathName(),
											 2000,
											 PropertiesFile::ignoreCaseOfKeyNames
											 | PropertiesFile::storeAsXML);

		window = new StandaloneFilterWindow(JucePlugin_Name,Colours::white);


        window->toFront (true);
        window->setVisible (true);

    }

    void shutdown()
    {
        // clear up..

        if (window != 0)
            delete window;
    }

    //==============================================================================
    const String getApplicationName()
    {
        return T(JucePlugin_Name);
    }

    const String getApplicationVersion()
    {
        return T(JucePlugin_VersionString);
    }

    bool moreThanOneInstanceAllowed()
    {
        return true;
    }

    void anotherInstanceStarted (const String& commandLine)
    {
    }
};


//==============================================================================
// This macro creates the application's main() function..
START_JUCE_APPLICATION (StandalonePizPlugin)
