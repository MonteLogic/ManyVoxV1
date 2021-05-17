/*
  ==============================================================================
    LoadSaveXml.cpp
    Created: 6 Apr 2021 2:56:45pm
    Author:  deckard
  ==============================================================================
*/

#include <JuceHeader.h>
#include "LoadSaveXml.h"
#include "MainComponent.h"


//==============================================================================
LoadSaveXml::LoadSaveXml()
{

    loadData();
    writeData();


    printNodeOne = "Printed node one, this statement was not replaced.";
    printNodeTwo = "Node two";
    printNodeThree = "Node three";


    

}

LoadSaveXml::~LoadSaveXml()
{
}


// void LoadSaveXml::saveDuration(String timeInFull){

//     std::cout << "Time in full: " << timeInFull << std::endl;

//     newTimeInFull = timeInFull;


//     writeData();
    
  

// }




void LoadSaveXml::loadData(){
  // A preamble to queue all files. 

  
        dir = juce::File::getCurrentWorkingDirectory();

        int numTries = 0;

        while (! dir.getChildFile ("Resources").exists() && numTries++ < 15)
            dir = dir.getParentDirectory();

        myxmlfile = dir.getChildFile ("Resources").getChildFile ("FilePaths.xml");

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

                nodeOne = xmlMadeThing->getFirstChildElement();
            std::cout << "nodeOne first reference: " << nodeOne << std::endl;

                printNodeOne = nodeOne->getAllSubText();
              Logger::outputDebugString(printNodeOne);


              nodeTwo = nodeOne->getNextElement();

               printNodeTwo = nodeTwo->getAllSubText();

               Logger::outputDebugString(printNodeTwo);


              nodeThree = nodeTwo->getNextElement();

              printNodeThree = nodeThree->getAllSubText();

          
              std::cout << printNodeThree << std::endl;
              
              std::cout << newTimeInFull << std::endl;
          //    writeData();


              nodeThree->setAttribute ("ID", "Changed5");
              xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());



            }

        }

        if (!myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);
            Logger::outputDebugString("Non-Existent");

        }


}


void LoadSaveXml::writeData(){

          nodeOne->setAttribute ("ID", "This is changed from writeData(),");
          xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());
        

        //   if (newTimeInFull.isEmpty() )    {

        //     std::cout << "New timeInFull isEmpty" << std::endl;
                      

        // }
        // if (newTimeInFull.isNotEmpty() )    {

        //      std::cout << "New timeInFull isNotEmpty" << std::endl;
        //   // The below lines uncommented produce a segmentation fault. 
        //    nodeOne->setAttribute ("ID", newTimeInFull);
        //   xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());
        // }
 

}