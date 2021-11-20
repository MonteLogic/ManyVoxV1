/*
  ==============================================================================

    FindKey.cpp
    Created: 16 May 2021 9:25:54pm
    Author:  deck

  ==============================================================================
*/

#include "FindKey.h"
#include <keyfinder/keyfinder.h>
#include <keyfinder/audiodata.h>



// Static because it retains useful resources for repeat use
static KeyFinder::KeyFinder k;
 
// Build an empty audio object
KeyFinder::AudioData a;
 
// Prepare the object for your audio stream
a.setFrameRate(yourAudioStream.framerate);
a.setChannels(yourAudioStream.channels);
a.addToSampleCount(yourAudioStream.length);
 
// Copy your audio into the object
for (int i = 0; i < yourAudioStream.length; i++) {
  a.setSample(i, yourAudioStream[i]);
}
 
// Run the analysis
KeyFinder::key_t key = k.keyOfAudio(a);
 
// And do something with the result
doSomethingWith(key);
