/*
  ==============================================================================

    BasicText.h
    Created: 5 Apr 2021 1:44:54pm
    Author:  deckard

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class BasicText    : public Component
{
public:
    BasicText();
    ~BasicText();
    
    String bText;



private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicText)
};
