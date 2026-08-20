#include "AudioEngine.h"

namespace syno
{
AudioEngine::AudioEngine() = default;

AudioEngine::~AudioEngine()
{
    shutdown();
}

bool AudioEngine::initialise()
{
    if (initialised)
        return true;

    const auto error = deviceManager.initialise(
        2,      // requested input channels
        2,      // requested output channels
        nullptr,
        true    // select default device
    );

    if (error.isNotEmpty())
    {
        juce::Logger::writeToLog(
            "SYNO AudioEngine initialisation failed: " + error
        );

        return false;
    }

    initialised = true;

    juce::Logger::writeToLog("SYNO AudioEngine initialised.");

    return true;
}

void AudioEngine::shutdown()
{
    if (!initialised)
        return;

    deviceManager.closeAudioDevice();
    initialised = false;

    juce::Logger::writeToLog("SYNO AudioEngine shutdown.");
}

bool AudioEngine::isInitialised() const noexcept
{
    return initialised;
}

double AudioEngine::getSampleRate() noexcept
{
    if (auto* device = deviceManager.getCurrentAudioDevice())
        return device->getCurrentSampleRate();

    return 0.0;
}

int AudioEngine::getBufferSize() noexcept
{
    if (auto* device = deviceManager.getCurrentAudioDevice())
        return device->getCurrentBufferSizeSamples();

    return 0;
}

int AudioEngine::getInputChannelCount() noexcept
{
    if (auto* device = deviceManager.getCurrentAudioDevice())
        return device->getActiveInputChannels().countNumberOfSetBits();

    return 0;
}

int AudioEngine::getOutputChannelCount() noexcept
{
    if (auto* device = deviceManager.getCurrentAudioDevice())
        return device->getActiveOutputChannels().countNumberOfSetBits();

    return 0;
}
}