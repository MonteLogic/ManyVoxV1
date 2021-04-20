/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "LoadSaveXml.h" 
#include "Window2Component.h"




// I think below is the function declarations and its already cogniscent of the classes that exist.
//==============================================================================
MainComponent::MainComponent() : juce::AudioAppComponent(otherDeviceManager), state(Stopped), openButton("Open"), playButton("Play"), stopButton("Stop"), thirdButton("Current file path"),
listXmlValues("Previous file paths1, Previous file paths2"), toggleBtn("Toggle Credit Button Visiblity"), credits("Developed by wp2mag.blogspot.com"), openWindow2Button("Open Window 2"), openWindow3Button("Open Window 3")

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
    addAndMakeVisible(&credits);
    addAndMakeVisible(&toggleBtn);


    addAndMakeVisible(openWindow2Button);
    addAndMakeVisible(openWindow3Button);
    openWindow2Button.onClick = [this] { openWindow2(); };
    openWindow3Button.onClick = [this] { openWindow3(); };


    notVisibleFunc();

    toggleBtn.onClick = [this] { toggleButtonClicked();  };

    credits.onClick = [this] { toggleButtonOff (); };
    

    std::cout << "This is coming from the MainComponent.cpp file and reading from LoadSaveXml" 
              << x1.printNodeOne;

    listXmlValues.setButtonText(x1.printNodeOne);
  

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

void MainComponent::notVisibleFunc()
{

    credits.setVisible(false); 

}



void MainComponent::toggleButtonClicked()
{

    credits.setVisible(true);
}


void MainComponent::toggleButtonOff()
{

    credits.setVisible(false);
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

// Right here I am going to toggle credits to make it not visible




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


void MainComponent::openWindow2()
{
      if (window2 == nullptr){
      window2.reset( new Window2 ("Window 2",
                                 Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId),
                                 DocumentWindow::allButtons));
      }
      window2->setVisible (true);
}




 void MainComponent::openWindow3()
    {
        if (window3 == nullptr){
            window3.reset( new Window3 ("Window 3",
                                             Desktop::getInstance().getDefaultLookAndFeel().
                                             findColour(ResizableWindow::backgroundColourId),
                                             DocumentWindow::allButtons));
        }
        window3->setVisible (true);
    }



void MainComponent::resized()
{
    openButton.setBounds(10, 10, getWidth() - 20, 30);
    playButton.setBounds(10, 50, getWidth() - 20, 30);
    stopButton.setBounds(10, 90, getWidth() - 20, 30);
    thirdButton.setBounds(10, 130, getWidth() - 20, 30);
    listXmlValues.setBounds(10, 170, getWidth() - 20, 30);
    credits.setBounds(10, 310, getWidth() - 20, 30);
    toggleBtn.setBounds(10, 350, getWidth() - 20, 30);


    openWindow2Button.setBounds(10, 390, getWidth() - 20, 30);
    openWindow3Button.setBounds(10, 430, getWidth() - 20, 30);




 //   audioSettings->setBounds(10, 200, getWidth() - 20, 100);

}


