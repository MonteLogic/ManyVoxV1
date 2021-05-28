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


    loadData();
    // writeData();


    

    // counterFunc();

  

}

LoadSaveXml::~LoadSaveXml()
{
}


void LoadSaveXml::saveDuration(String timeInFull){

    std::cout << "Time in full: " << timeInFull << std::endl;

    newTimeInFull = timeInFull;


    // writeData();
    
  

}



int LoadSaveXml::counterB=0;
void LoadSaveXml::loadData(){
  // A preamble to queue all files. 
       // Uncomment this out again to figure out
       // when loadData is being called.
       counterB++;
        std::cout << "counterB: " << counterB << std::endl;

        dir = juce::File::getCurrentWorkingDirectory();

        ///numTries = 0;

        while (! dir.getChildFile ("Resources").exists() && numTries++ < 15)
            dir = dir.getParentDirectory();

//        std::cout << dir << std::endl;

        myxmlfile = dir.getChildFile ("Resources").getChildFile ("FilePaths.xml");

        auto outputNameofFile = myxmlfile.getFullPathName();
        numTries = 0;

        if (myxmlfile.exists()) {

            Logger::outputDebugString(outputNameofFile);

            std::cout << "myxmlfile.exists() "<< std::endl;

            xmlMadeThing = juce::XmlDocument::parse(myxmlfile);

     
            if (xmlMadeThing->hasTagName("PATHS"))
            {
                // Checking to see if the file exist and is reading the tags.
                // What if I get relative path from and save it? 
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



            if (newTimeInFull.isNotEmpty() )    {

             std::cout << "New timeInFull isNotEmpty" << std::endl;

            }
    
          }

      }

         std::cout << "loadData has been fired: " << counterB << " times" << std::endl;

}










void LoadSaveXml::writeData(){

              std::cout << "writeData() pre" << std::endl;  

              auto directDir = juce::File("/home/deck/Documents/ManyVoxV1-e5ad740841934c1522db7b637c4ef5d6e598760e/Resources/FilePaths.xml");

              std::cout << "writeData()" << std::endl;  
                       


          if (newTimeInFull.isNotEmpty()){

              if(directDir.exists()){

                if (directDir.hasWriteAccess()){

                    xmlMadeThing = juce::XmlDocument::parse(directDir);

                    nodeOne = xmlMadeThing->getFirstChildElement();

                    printNodeOne = nodeOne->getAllSubText();

                  
                  // Lets see if nodeOne is the problem.
                 std::cout << "printNodeOne is: " << printNodeOne << std::endl;  
 
                  std::cout << "About to set Attribute" << std::endl;  
                  
                  nodeOne->setAttribute ("ID", newTimeInFull);
                  std::cout << "About to write" << std::endl;  
                  xmlMadeThing->writeTo(directDir, XmlElement::TextFormat());
            }
            }
          }
          


          if (newTimeInFull.isEmpty()){

            
          }





          //=====================================================


          //  nodeOne->setAttribute ("ID", newTimeInFull);
          // xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());



        }
    

