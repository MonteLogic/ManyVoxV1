/*
  ==============================================================================

    LoadSaveXml.h
    Created: 6 Apr 2021 2:56:45pm
    Author:  deckard

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LoadSaveXml  : public juce::Component
{
public:
    LoadSaveXml();
    ~LoadSaveXml() override;

    void loadData();

    


    String printNodeOne;
    String printNodeTwo;
    String printNodeThree;



private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoadSaveXml)
};
