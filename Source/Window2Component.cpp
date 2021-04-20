/*
  ==============================================================================

    Window2Component.cpp
    Created: 18 Apr 2021 4:41:00am
    Author:  deckard

  ==============================================================================
*/

#include "Window2Component.h"

// I gotta find out terms for the process of adding : and params to the 
// left of these constructors.
Window2Component::Window2Component() : window2Button("Button in window 2")
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.
        
        setSize (getWidth(), getHeight());
        addAndMakeVisible (window2Button);
    }
    
Window2Component::~Window2Component (){
}
    



void Window2Component::paint (Graphics& g) 
{
        /* This demo code just fills the component's background and
           draws some placeholder text to get you started.

           You should replace everything in this method with your own
           drawing code..
        */

        g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

        g.setColour (Colours::red);
        g.drawRect (getLocalBounds(), 2);   // draw an outline around the component

        g.setColour (Colours::white);
        g.setFont (14.0f);
        g.drawText ("Window2Component", getLocalBounds(),
                    Justification::centred, true);   // draw some placeholder text
}
    
    
    
void Window2Component::resized() 
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..
 
        window2Button.setBounds (20, 20, 140, 40);
    }

// Begin Window2 logic.


// This function is fully described in another function. 
// I did not write it like a constructor before. 
Window2::Window2(const String& name, Colour backgroundColour, int buttonsNeeded)
    : DocumentWindow (name, backgroundColour, buttonsNeeded)
    {
     
        
        setBounds (20, 20, 300, 400);
        setResizable (true, false);
        setUsingNativeTitleBar (true);
        setContentOwned (&window2Component, false);
        
    }
    

void Window2:: closeButtonPressed(){

    setVisible(false);
}



Window3::Window3(const String& name, Colour backgroundColour, int buttonsNeeded)
    : DocumentWindow (name, backgroundColour, buttonsNeeded)
    {
     
        
        setBounds (20, 20, 300, 400);
        setResizable (true, false);
        setUsingNativeTitleBar (true);
        setContentOwned (&window2Component, false);
        
    }


void Window3:: closeButtonPressed(){

    setVisible(false);
}