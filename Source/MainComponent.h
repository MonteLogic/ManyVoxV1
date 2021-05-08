/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "LoadSaveXml.h" 
#include "Window2Component.h"
#include "TableTutorialComponent.h"


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

    void notVisibleFunc();
    void toggleButtonClicked();
    void toggleButtonOff();

    int viewToView =  390;


    
    void playButtonClicked();
    void stopButtonClicked();
    void transportStateChanged(TransportState newState);
    void changeListenerCallback (ChangeBroadcaster *source) override;

    String convertTimeToString(int convertToInt, int minutes, String timeInMinutes, String timeInSeconds, String timeInFull);

    void openWindow2();
    void openWindow3();
    
    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> playSource;
    AudioTransportSource transport;
    

    TextButton openButton;
    TextButton playButton;
    TextButton stopButton;
    TextButton thirdButton;

    TextButton listXmlValues;

    TextButton credits;
    
    LoadSaveXml x1;

    TextButton toggleBtn;

    // Start open "new" window logic.

    TextButton openWindow2Button;
    TextButton openWindow3Button;

    std::unique_ptr<Window2> window2;
    std::unique_ptr<Window3> window3;
    
    
    



    //==============================================================================
    // Your private member variables go here...

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
