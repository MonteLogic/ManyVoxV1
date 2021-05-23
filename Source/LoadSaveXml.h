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

    String printNodeOne;

    void saveDuration(String timeInFull);

    void writeData();



private:

   String newString = "YeahYeah";

    //void saveData();
    void loadData();




   
   static int counterB;



    // FILE * myxmlfile;
    // FILE * dir;

    juce::File myxmlfile;
    juce::File dir;


      // getFirstChildElement
       juce::XmlElement* nodeOne;
       juce::XmlElement* nodeTwo;
       juce::XmlElement* nodeThree;
       juce::XmlElement* nodeFour;
//statement

    
    std::shared_ptr<juce::XmlElement> xmlMadeThing;


    String printNodeTwo;
    String printNodeThree; // I think printNodeThree maybe destroyed once the scope ends. 
    String printNodeFour; 

    String newTimeInFull;





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoadSaveXml)
};