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

 


private:

   String newString = "YeahYeah";

    //void saveData();
    void loadData();
    void saveDuration(String timeInFull);

    void writeData();

    // FILE * myxmlfile;
    // FILE * dir;

    juce::File myxmlfile;
    juce::File dir;


      // getFirstChildElement
       juce::XmlElement* nodeOne = nullptr;
       juce::XmlElement* nodeTwo = nullptr;
       juce::XmlElement* nodeThree = nullptr;
       juce::XmlElement* nodeFour = nullptr;
//statement

    
    std::shared_ptr<juce::XmlElement> xmlMadeThing;


    String printNodeOne;
    String printNodeTwo;
    String printNodeThree; // I think printNodeThree maybe destroyed once the scope ends. 
    String printNodeFour; 

    String newTimeInFull;





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoadSaveXml)
};