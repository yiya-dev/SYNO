#pragma once
#include <juce_audio_devices/juce_audio_devices.h>

namespace syno
{
class AudioEngine final
{
public:
    AudioEngine();
    ~AudioEngine();

    AudioEngine(const AudioEngine&) = delete;
    AudioEngine& operator=(const AudioEngine&) = delete;

    bool initialise();
    void shutdown();

    bool isInitialised() const noexcept;

    double getSampleRate() noexcept;
    int getBufferSize() noexcept;
    int getInputChannelCount() noexcept;
    int getOutputChannelCount() noexcept;

private:
    juce::AudioDeviceManager deviceManager;
    bool initialised = false;
};
}