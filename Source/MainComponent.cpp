/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "LoadSaveXml.h" 
#include "DisplayTable.h" 





//==============================================================================
MainComponent::MainComponent() : juce::AudioAppComponent(otherDeviceManager), state(Stopped), openButton("Open"), playButton("Play"), stopButton("Stop"), thirdButton("Current file path"),
listXmlValues("Previous file paths1, Previous file paths2, Previous file paths3, Previous file paths4, Previous file paths5, Previous file paths6, Previous file paths7, Previous file paths8, Previous file paths9 "),table("s")

{
    otherDeviceManager.initialise(2, 2, nullptr, true);
    audioSettings.reset(new AudioDeviceSelectorComponent(otherDeviceManager, 0, 2, 0, 2, true, true, true, true));
    addAndMakeVisible(audioSettings.get());
    
    setAudioChannels (2, 2);
    
    openButton.onClick = [this] {  openButtonClicked(); };
    addAndMakeVisible(&openButton);
    
    playButton.onClick = [this] { playButtonClicked(); };
    playButton.setColour(TextButton::buttonColourId, Colours::green);
    playButton.setEnabled(true);
    addAndMakeVisible(&playButton);
    
    stopButton.onClick = [this] { stopButtonClicked(); };
    stopButton.setColour(TextButton::buttonColourId, Colours::red);
    stopButton.setEnabled(false);
    addAndMakeVisible(&stopButton);

    addAndMakeVisible(&thirdButton);
    addAndMakeVisible(&listXmlValues);
    addAndMakeVisible(&table);


  
  

//    addAndMakeVisible(t.table);

    // Begin fourth button logic.

    LoadSaveXml xTwo;
    xTwo.loadData();

    // The logic of the different strings should
    // now be in this file. 

    String newnew2 = xTwo.printNodeOne + "  " + xTwo.printNodeTwo;



    listXmlValues.setButtonText(newnew2);

    // ===========================


    
    formatManager.registerBasicFormats();
    transport.addChangeListener(this);
    
    setSize (400, 700);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

void MainComponent::logToConsole()
{
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    transport.prepareToPlay(samplesPerBlockExpected, sampleRate);
}



void MainComponent::openButtonClicked()
{

    //StandalonePluginHolder
   

    //choose a file
    FileChooser chooser ("Choose a Wav or AIFF File", File::getSpecialLocation(File::userDesktopDirectory), "*.wav; *.mp3");
    
    //if the user chooses a file
    if (chooser.browseForFileToOpen())
    {
        File myFile;
        

        //what did the user choose?
        myFile = chooser.getResult();
        // This is ^^ where the file is chosen. 
        Logger::outputDebugString("Statement three");

        // String ipsumString = myFile.getFileExtension();
        String ipsumString = myFile.getFullPathName();

       // TextButton showFilename { "File name inserted here" };

        thirdButton.setEnabled(false);
        thirdButton.setButtonText(ipsumString);



        //read the file
        AudioFormatReader* reader = formatManager.createReaderFor(myFile);
        
        if (reader != nullptr)
        {
            //get the file ready to play
            std::unique_ptr<AudioFormatReaderSource> tempSource (new AudioFormatReaderSource (reader, true));
        
            transport.setSource(tempSource.get());
            transportStateChanged(Stopped);
        
            playSource.reset(tempSource.release());
        }
    }
}

void MainComponent::playButtonClicked()
{
    transportStateChanged(Starting);
}

void MainComponent::stopButtonClicked()
{
    transportStateChanged(Stopping);
}

void MainComponent::transportStateChanged(TransportState newState)
{
    if (newState != state)
    {
        state = newState;
        
        switch (state) {
            case Stopped:
                playButton.setEnabled(true);
                transport.setPosition(0.0);
                break;
                
            case Playing:
                playButton.setEnabled(true);
                break;
                
            case Starting:
                stopButton.setEnabled(true);
                playButton.setEnabled(false);
                transport.start();
                break;
                
            case Stopping:
                playButton.setEnabled(true);
                stopButton.setEnabled(false);
                transport.stop();
                break;
        }
    }
}

void MainComponent::changeListenerCallback (ChangeBroadcaster *source)
{
    if (source == &transport)
    {
        if (transport.isPlaying())
        {
            transportStateChanged(Playing);
        }
        else
        {
            transportStateChanged(Stopped);
        }
    }
}



void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    
    transport.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    openButton.setBounds(10, 10, getWidth() - 20, 30);
    playButton.setBounds(10, 50, getWidth() - 20, 30);
    stopButton.setBounds(10, 90, getWidth() - 20, 30);
    thirdButton.setBounds(10, 130, getWidth() - 20, 30);
    listXmlValues.setBounds(10, 170, getWidth() - 20, 30);
    audioSettings->setBounds(10, 200, getWidth() - 20, 100);
    table->setBounds(10, 200, getWidth() - 20, 100);

}


