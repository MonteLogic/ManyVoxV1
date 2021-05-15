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
    // I think saveData hits before loadData.
    //saveData();


    

}

LoadSaveXml::~LoadSaveXml()
{
}


void LoadSaveXml::loadData(){
  // A preamble to queue all files. 


  
        auto dir = juce::File::getCurrentWorkingDirectory();

        int numTries = 0;

        while (! dir.getChildFile ("Resources").exists() && numTries++ < 15)
            dir = dir.getParentDirectory();

        auto myxmlfile = dir.getChildFile ("Resources").getChildFile ("FilePaths.xml");





        auto outputNameofFile = myxmlfile.getFullPathName();

      

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


              auto nodeThree = nodeTwo->getNextElement();

              printNodeThree = nodeThree->getAllSubText();

              Logger::outputDebugString(printNodeThree);

  //            XmlElement writeNodeThree ("PATHS");



              nodeThree->setAttribute ("ID", "changed1");
              xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());






            }

        }

        if (!myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);
            Logger::outputDebugString("Non-Existent");

        }


}



// This works
void LoadSaveXml::saveDuration(String timeInFull){

    std::cout << "Time in full: " << timeInFull << std::endl;


}




// void LoadSaveXml::saveData(){




  
  
//       xmlMadeThing = juce::XmlDocument::parse(myxmlfile);

      
//       auto* nodeThinger = xmlMadeThing->getFirstChildElement();

//       auto printNodeThinger= nodeThinger->getAllSubText();

//      std::cout << "print: " << printNodeThinger << std::endl;
//       std::cout << "print: " << 5 << std::endl;


// }