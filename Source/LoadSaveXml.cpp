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


    //loadData();

  

}

LoadSaveXml::~LoadSaveXml()
{
}




int LoadSaveXml::counterC=0;
juce::File LoadSaveXml::returnFilePath(){
          

// This could change

    juce::File dir = juce::File::getCurrentWorkingDirectory();




            // This puts you in a place where you CAN access the resources folder. 
            // This puts you in the Project folder. 

    
            if (!myxmlfile.exists()){


            while (! dir.getChildFile ("Resources").exists() && numTries++ < 25){
               dir = dir.getParentDirectory();
            }
            // This just puts you in the

              // If the folder that its in has the name resources then do the following: 1

             myxmlfile= dir.getChildFile ("Resources").getChildFile ("FilePaths.xml");

            }








            if (myxmlfile.exists()){

                std::cout << "myxmlfile.exists()" << std::endl;
                fileName = myxmlfile.getFullPathName();                

            }


            std::cout << numTries << std::endl;
            
            return myxmlfile;






    };




// loadData will have the parameter const xmlPath 
int LoadSaveXml::counterB=0;
void LoadSaveXml::loadData(const String& fileName) {
  // A preamble to queue all files. 
       // Uncomment this out again to figure out
       // when loadData is being called.
       counterB++;
        std::cout << "counterB: " << counterB << std::endl;


            String outputNameofFileThree = fileName;

            String preOutputNameofFile = returnFilePath().getFullPathName();
            

            std::cout << "preOutputNameofFile = " << preOutputNameofFile << std::endl;

            std::cout << "const fileName = " << outputNameofFileThree << std::endl;



              if (returnFilePath().exists()) {

            std::cout << "returnFilePath().exists() within loadData " << std::endl;

            String outputNameofFileTwo = returnFilePath().getFullPathName();

            // String outputNameofFileThree = fileName;
            //outputNameofFile = myxmlfile.getFullPathName();
            std::cout << "outputNameofFileTwo = " << outputNameofFileTwo << std::endl;


            xmlMadeThing = juce::XmlDocument::parse(returnFilePath());

     
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

                      // Why is the below statement being triggered?
                      if (!returnFilePath().exists()) {

                     std::cout << "returnFilePath does not exist. " << std::endl;


                      }
      

         std::cout << "loadData has been fired: " << counterB << " times" << std::endl;

}



void LoadSaveXml::saveDuration(String timeInFull){

    std::cout << "Time in full: " << timeInFull << std::endl;

    newTimeInFull = timeInFull;


}





void LoadSaveXml::writeData(String currentPath){


         std::cout << "Statement " << std::endl;  
         std::cout << "Statement " << std::endl;  


         auto copyIt = returnFilePath();


         auto outputNameofFileXX = returnFilePath().getFullPathName();
         auto myxmlfileReturnPath = returnFilePath().getFullPathName();



         std::cout << "outputNameofFileXX = " << outputNameofFileXX << std::endl;  
         std::cout << "myxmlfileReturnPath = " << outputNameofFileXX << std::endl;  


         
              if (returnFilePath().exists()){

              std::cout <<"returnFilePath().exists() within write data "  << std::endl;  


              }

              if(copyIt.exists()){

              std::cout <<"returnFilePath().exists() within write data "  << std::endl;  


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
    

