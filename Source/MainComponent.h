/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
//#include "LoadSaveXml.h" 
#include "BasicText.h" 


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public AudioAppComponent,
                        public ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;



private:
    AudioDeviceManager otherDeviceManager;
    std::unique_ptr <AudioDeviceSelectorComponent> audioSettings;

    juce::Font font           { 14.0f };

    int numRows = 0;
    
    enum TransportState
    {
        Stopped,
        Starting,
        Stopping,
        Playing
    };
    
    TransportState state;
    
    void openButtonClicked();
    void logToConsole();

    
    void playButtonClicked();
    void stopButtonClicked();
    void transportStateChanged(TransportState newState);
    void changeListenerCallback (ChangeBroadcaster *source) override;
    
    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> playSource;
    AudioTransportSource transport;
    
    // This is just display below

    TextButton openButton;
    TextButton playButton;
    TextButton stopButton;
    TextButton thirdButton;

    TextButton listXmlValues;
    
    BasicText txt4;

    



    //==============================================================================
    // Your private member variables go here...

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
