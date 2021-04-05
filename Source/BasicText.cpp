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

void BasicText::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("BasicText", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void BasicText::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
