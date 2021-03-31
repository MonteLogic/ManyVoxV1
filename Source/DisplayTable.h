/*
  ==============================================================================

    DisplayTable.h
    Created: 27 Mar 2021 1:54:26pm
    Author:  dc

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MainComponent.h"


class DisplayTable  : public juce::Component, public juce::TableListBoxModel
{
public:
    DisplayTable(MainComponent& c);
    DisplayTable(MainComponent& c) : referenceToTHEMainComponent(c)
    {

        //...
        

    };

    int getNumRows() override
    {
        auto numRows = 0;
        return numRows;
    }

    void paintRowBackground(juce::Graphics& g, int rowNumber, int /*width*/, int /*height*/, bool rowIsSelected) override
    {
        auto alternateColour = getLookAndFeel().findColour(juce::ListBox::backgroundColourId)
            .interpolatedWith(getLookAndFeel().findColour(juce::ListBox::textColourId), 0.03f);
        if (rowIsSelected)
            g.fillAll(juce::Colours::lightblue);
        else if (rowNumber % 2)
            g.fillAll(alternateColour);
    }


    void paintCell(juce::Graphics& g, int rowNumber, int columnId,
        int width, int height, bool rowIsSelected) override
    {
        g.setColour(rowIsSelected ? juce::Colours::darkblue : getLookAndFeel().findColour(juce::ListBox::textColourId));  // [5]
     

   

        g.setColour(getLookAndFeel().findColour(juce::ListBox::backgroundColourId));
        g.fillRect(width - 1, 0, 1, height);                                                                               // [7]
    }




private:
MainComponent& referenceToTHEMainComponent;

JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DisplayTable)




};
