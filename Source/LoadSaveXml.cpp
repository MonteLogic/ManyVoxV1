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

// I believe I only want loadData to be fired once. 

// loadData is being fired twice. 

//
// I'm trying to run logic that makes it so that loadData doesn't run twice
// thus changing the memory address values(?)
    

// What should counterB or counter equal?
    if (counterB ==0) {

    loadData();


    }

    counterFunc();

  

}

LoadSaveXml::~LoadSaveXml()
{
}


void LoadSaveXml::saveDuration(String timeInFull){

    std::cout << "Time in full: " << timeInFull << std::endl;

    newTimeInFull = timeInFull;


    // writeData();
    
  

}
int LoadSaveXml::counter=0;
   

void LoadSaveXml::counterFunc(){




     counter++;

     std::cout << counter << std::endl;




}


int LoadSaveXml::counterB=0;
void LoadSaveXml::loadData(){
  // A preamble to queue all files. 
       // Uncomment this out again to figure out
       // when loadData is being called.
       counterB++;
        std::cout << "counterB: " << counter << std::endl;

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

              // This writing logic should only be set outside of the loadData function.
              nodeThree->setAttribute ("ID", "Changed6");
              xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());



            }

        }

        if (!myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);
            Logger::outputDebugString("Non-Existent");

        }

         std::cout << "loadData has been fired: " << counterB << " times" << std::endl;



}



void LoadSaveXml::fireWriteData(){

  writeData();


}

void LoadSaveXml::writeData(){

      if (nodeOne != 0){
  
    


          nodeOne->setAttribute ("ID", "This is changed from writeData(),6");
          xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());
        

          if (newTimeInFull.isEmpty() )    {

            std::cout << "New timeInFull isEmpty" << std::endl;

            saveDuration(newTimeInFull);

          nodeOne->setAttribute ("ID", newTimeInFull);
          xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());
                      

        }


        if (newTimeInFull.isNotEmpty() )    {

             std::cout << "New timeInFull isNotEmpty" << std::endl;
          // The below lines uncommented produce a segmentation fault. 
           nodeOne->setAttribute ("ID", newTimeInFull);
          xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());
        }
 

     }


}