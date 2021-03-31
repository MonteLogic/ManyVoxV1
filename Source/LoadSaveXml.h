/*
  ==============================================================================

    LoadSaveXml.h
    Created: 22 Mar 2021 5:02:11am
    Author:  dc

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/

class LoadSaveXml  : public juce::Component
{

public:

    LoadSaveXml()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
  
        Logger::outputDebugString("Statement 4, This statement is coming from LoadSaveXml.h , gracias");

        loadData();

    }

    ~LoadSaveXml() override
    {
    }



    String printNodeOne;
    String printNodeTwo;
    String printNodeThree;



    void loadData() {

        Logger::outputDebugString("Statement 5, This statement is inside the method loadData");

        auto dir = juce::File::getCurrentWorkingDirectory();

        dir = dir.getParentDirectory();

        auto dirTwo = dir.getParentDirectory();
        // auto myxmlfile = dir.getChildFile("resources").getChildFile("filepaths.xml");

        auto myxmlfile = dirTwo.getChildFile("Resources").getChildFile("FilePaths.xml");

        auto outputNameofFile = myxmlfile.getFullPathName();

        Logger::outputDebugString(outputNameofFile);



        String changeTest = "9, Has not changed.";
        

        if (myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);
            Logger::outputDebugString("Existent");

            xmlMadeThing = juce::XmlDocument::parse(myxmlfile);
            


            if (xmlMadeThing->hasTagName("PATHS"))
            {
                // Checking to see if the file exist and is reading the tags.
                Logger::outputDebugString("Statement 6, The xml file does have that tag name.");


                // Reading the xml string. 

                auto* nodeOne = xmlMadeThing->getFirstChildElement();

                printNodeOne = nodeOne->getAllSubText();

                Logger::outputDebugString(printNodeOne);


                auto nodeTwo = nodeOne->getNextElement();

                printNodeTwo = nodeTwo->getAllSubText();

                Logger::outputDebugString(printNodeTwo);

                //
                auto nodeThree = nodeTwo->getNextElement();

                printNodeThree = nodeThree->getAllSubText();

                Logger::outputDebugString(printNodeThree);

            }


            if (xmlMadeThing->hasTagName("fooNonExistentTagName"))
            {
                Logger::outputDebugString("Statement ****");
            }
        }

        if (!myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);
            Logger::outputDebugString("Non-Existent");

        }

    }


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoadSaveXml)
    
   std::unique_ptr<juce::XmlElement> xmlMadeThing;
    juce::XmlElement* madeList = nullptr;


};



