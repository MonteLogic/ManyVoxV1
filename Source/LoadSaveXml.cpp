/*
  ==============================================================================

    LoadSaveXml.cpp
    Created: 6 Apr 2021 2:56:45pm
    Author:  deckard

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LoadSaveXml.h"

//==============================================================================
LoadSaveXml::LoadSaveXml()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    printNodeOne = "Printed node one, this statement was not replaced.";
    printNodeTwo = "Node two";
    printNodeThree = "Node three";

    loadData();
    

}

LoadSaveXml::~LoadSaveXml()
{
}


void LoadSaveXml::loadData(){
  std::cout << "This is a big STATEMENT!!!"; 
  Logger::outputDebugString("Statement 4, This statement is coming from LoadSaveXml.h , gracias");


        Logger::outputDebugString("Statement 5, This statement is inside the method loadData");

  
        auto dir = juce::File::getCurrentWorkingDirectory();

        int numTries = 0;

        while (! dir.getChildFile ("Resources").exists() && numTries++ < 15)
            dir = dir.getParentDirectory();

        auto myxmlfile = dir.getChildFile ("Resources").getChildFile ("FilePaths.xml");








        auto outputNameofFile = myxmlfile.getFullPathName();

        Logger::outputDebugString(outputNameofFile);


        if (myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);
            Logger::outputDebugString("Existent");

            auto xmlMadeThing = juce::XmlDocument::parse(myxmlfile);
            


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

  //            XmlElement writeNodeThree ("PATHS");



              nodeThree->setAttribute ("ID", "changed");
              xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());






            }

        }

        if (!myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);
            Logger::outputDebugString("Non-Existent");

        }



}