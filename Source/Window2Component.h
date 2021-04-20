#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
//==============================================================================
// Refactor this


class Window2Component    : public Component
{
public:
    Window2Component(); 

    // This below could give an error. Maybe something to do with the override keyword being used.
    ~Window2Component() override;

    void paint (Graphics& g) override;

    void resized() override;

private:
    TextButton window2Button; 

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Window2Component)
};




class Window2   : public DocumentWindow
{

public: 
    Window2 (const String& name, Colour backgroundColour, int buttonsNeeded);
    
    void closeButtonPressed();

private:
    // Below is declaring an  object. 
    Window2Component window2Component;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Window2)
};




class Window3   : public DocumentWindow
{

public: 
    Window3 (const String& name, Colour backgroundColour, int buttonsNeeded);
    
    void closeButtonPressed();

private:
    // Below is declaring an  object. 
    Window2Component window2Component;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Window3)
};

