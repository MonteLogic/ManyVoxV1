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
    
    printNodeOne = "This printed node one, in string format.";
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
}


