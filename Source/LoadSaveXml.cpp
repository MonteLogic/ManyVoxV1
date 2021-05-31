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

  

}

LoadSaveXml::~LoadSaveXml()
{
}



void findXmlPath(){

  // I want this to return the path but it's going to be in juce::File format



}

// I don't think that this is being called so that value isn't around. 

String returnFilePath(){
          
          auto dirX = juce::File::getCurrentWorkingDirectory();

          auto numTriesX =0;
           while (! dirX.getChildFile ("Resources").exists() && numTriesX++ < 15)
                dirX = dirX.getParentDirectory();


          auto myxmlfileX = dirX.getChildFile ("Resources").getChildFile ("FilePaths.xml");

          auto outputNameofFileX = myxmlfileX.getFullPathName();
                            std::cout << outputNameofFileX << std::endl;

          return outputNameofFileX;





    };



// loadData will have the parameter const xmlPath 
int LoadSaveXml::counterB=0;
void LoadSaveXml::loadData(){
  // A preamble to queue all files. 
       // Uncomment this out again to figure out
       // when loadData is being called.
       counterB++;
        std::cout << "counterB: " << counterB << std::endl;

            if(counterB == 1){

            // This line below is really confusing. 
            if(!myxmlfile.exists()){

            // I think this stays because its static.
            dir = juce::File::getCurrentWorkingDirectory();


            while (! dir.getChildFile ("Resources").exists() && numTries++ < 15)
                dir = dir.getParentDirectory();


            myxmlfile = dir.getChildFile ("Resources").getChildFile ("FilePaths.xml");

            }



              if (myxmlfile.exists()) {

            std::cout << "myxmlfile.exists() "<< std::endl;

            outputNameofFile = myxmlfile.getFullPathName();

            //outputNameofFile = myxmlfile.getFullPathName();
            std::cout << outputNameofFile << std::endl;


            siblingFile = myxmlfile.getSiblingFile("TableData");


                    if(!siblingFile.exists()){

                        std::cout << "siblingFile does not exist to begin with" << std::endl;

                    }

            xmlMadeThing = juce::XmlDocument::parse(myxmlfile);

     
            if (xmlMadeThing->hasTagName("NODES"))
            {
                // Checking to see if the file exist and is reading the tags.
                // What if I get relative path from and save it? 
                Logger::outputDebugString("Statement 6, The xml file does have that tag name.");


                // Reading the xml string. 

              nodeOne = xmlMadeThing->getFirstChildElement();

              printNodeOnePath = nodeOne->getStringAttribute("PATH");
              std::cout << "printNodeOnePath: " << printNodeOnePath << std::endl;

              
              printNodeOne = "printNodeOne";


              std::cout << newTimeInFull << std::endl;
    
          }

        }
      }

         std::cout << "loadData has been fired: " << counterB << " times" << std::endl;

}



void LoadSaveXml::saveDuration(String timeInFull){

    std::cout << "Time in full: " << timeInFull << std::endl;

    newTimeInFull = timeInFull;


}





void LoadSaveXml::writeData(String currentPath){


         std::cout << outputNameofFile << std::endl;

         juce::File* copyFile = &myxmlfile;

         auto copyReturnable = returnFilePath();

         std::cout << copyReturnable << std::endl;  



             if(copyFile->exists()){

              std::cout << "_" << std::endl;  


              }

              if(!copyFile->exists()){

              std::cout << "!" << std::endl;  


              }







            //   if(returnFilePath().exists()){

            //   std::cout << "_" << std::endl;  
            // // std::cout << outputNameofFile << std::endl;


            //   }

            //   if(!returnFilePath().exists()){

            //   std::cout << "!" << std::endl;  
            // // std::cout << outputNameofFile << std::endl;


            //   }


              // I still need to replace the below line with a better file path.

//            auto directDirTwo = juce::File("../Resources/FilePaths.xml");




                        
          //   auto directDir = juce::File::getCurrentWorkingDirectory();


          //    auto directDirTwo = juce::File("/home/deck/Documents/ManyVoxV1/Resources/FilePaths.xml");
             
          //     if (directDir.isDirectory()){

          //     std::cout << "directDir" << std::endl;  

          //     auto directDirNumber = directDirTwo.getNumberOfChildFiles( 2, "*.xml");

          //     std::cout << directDirNumber << std::endl;  

          //     auto outputNameofFileTwo = directDirTwo.getFullPathName();




          //     }

          //     if (!directDir.isDirectory()){

          //     std::cout << "!directDir" << std::endl;  

          //     }

          //     std::cout << "writeData()" << std::endl;  
                       


          // if (newTimeInFull.isNotEmpty()){

          //     if(directDir.exists()){

          //       if (directDir.hasWriteAccess()){

          //           xmlMadeThing = juce::XmlDocument::parse(directDir);

          //           nodeOne = xmlMadeThing->getFirstChildElement();

          //           printNodeOne = nodeOne->getAllSubText();

                  
          //         // Lets see if nodeOne is the problem.
          //        std::cout << "printNodeOne is: " << printNodeOne << std::endl;  
 
          //         std::cout << "About to set Attribute" << std::endl;  
                  


          //         nodeOne->setAttribute ("DURATION", newTimeInFull);
          //         nodeOne->setAttribute ("PATH", currentPath);


          //         std::cout << "About to write" << std::endl;  
          //         xmlMadeThing->writeTo(directDir, XmlElement::TextFormat());
          //   }
          //   }
          // }
          


          // if (newTimeInFull.isEmpty()){

            
          // }





          //=====================================================


          //  nodeOne->setAttribute ("ID", newTimeInFull);
          // xmlMadeThing->writeTo(myxmlfile, XmlElement::TextFormat());



        }
    

