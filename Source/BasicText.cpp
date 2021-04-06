/*
  ==============================================================================

    BasicText.cpp
    Created: 5 Apr 2021 1:44:54pm
    Author:  deckard

  ==============================================================================
*/

#include <JuceHeader.h>
#include "BasicText.h"

//==============================================================================
BasicText::BasicText()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    bText = "This is new text declared in the header file";
    std::cout << bText << "     ";

}

BasicText::~BasicText()
{
}



