#pragma once

#include <juce_audio_devices/juce_audio_devices.h>

namespace syno
{
class AudioEngine final : private juce::AudioIODeviceCallback
{
public:
    AudioEngine();
    ~AudioEngine() override;

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
    // juce::AudioIODeviceCallback
    void audioDeviceIOCallbackWithContext(
        const float* const* inputChannelData,
        int numInputChannels,
        float* const* outputChannelData,
        int numOutputChannels,
        int numSamples,
        const juce::AudioIODeviceCallbackContext& context) override;

    void audioDeviceAboutToStart(juce::AudioIODevice* device) override;
    void audioDeviceStopped() override;

    juce::AudioDeviceManager deviceManager;

    bool initialised = false;

    double sampleRate = 0.0;
    double phase = 0.0;
    double phaseIncrement = 0.0;
};
}