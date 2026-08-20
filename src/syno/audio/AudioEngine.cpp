#include "AudioEngine.h"

#include <cmath>

namespace syno
{
namespace
{
constexpr double testFrequencyHz = 440.0;
constexpr double twoPi = 6.283185307179586476925286766559;
}

AudioEngine::AudioEngine() = default;

AudioEngine::~AudioEngine()
{
    shutdown();
}

bool AudioEngine::initialise()
{
    if (initialised)
        return true;

    const auto& audioTypes =
        deviceManager.getAvailableDeviceTypes();

    juce::Logger::writeToLog(
        "SYNO AudioEngine: available audio types:"
    );

    for (const auto* type : audioTypes)
    {
        if (type == nullptr)
            continue;

        juce::Logger::writeToLog(
            "  - " + type->getTypeName()
        );
    }

    const auto error = deviceManager.initialise(
        0,      // no input requested for the first audio test
        2,      // two output channels
        nullptr,
        true
    );

    juce::Logger::writeToLog(
        "SYNO AudioEngine: current audio type = "
        + deviceManager.getCurrentAudioDeviceType()
    );

    auto* currentDevice =
        deviceManager.getCurrentAudioDevice();

    if (currentDevice != nullptr)
    {
        juce::Logger::writeToLog(
            "SYNO AudioEngine: current device = "
            + currentDevice->getName()
        );
    }
    else
    {
        juce::Logger::writeToLog(
            "SYNO AudioEngine: current device = NONE"
        );
    }

    if (error.isNotEmpty())
    {
        juce::Logger::writeToLog(
            "SYNO AudioEngine initialisation failed: " + error
        );

        return false;
    }

    if (auto* device = deviceManager.getCurrentAudioDevice())
    {
        juce::Logger::writeToLog(
            "SYNO AudioEngine: audio type = "
            + deviceManager.getCurrentAudioDeviceType()
        );

        juce::Logger::writeToLog(
            "SYNO AudioEngine: device = "
            + device->getName()
        );

        juce::Logger::writeToLog(
            "SYNO AudioEngine: sample rate = "
            + juce::String(device->getCurrentSampleRate())
        );

        juce::Logger::writeToLog(
            "SYNO AudioEngine: buffer size = "
            + juce::String(device->getCurrentBufferSizeSamples())
        );
    }
    else
    {
        juce::Logger::writeToLog(
            "SYNO AudioEngine: no current audio device."
        );

        return false;
    }

    deviceManager.addAudioCallback(this);

    initialised = true;

    juce::Logger::writeToLog(
        "SYNO AudioEngine initialised."
    );

    return true;
}

void AudioEngine::shutdown()
{
    if (!initialised)
        return;

    deviceManager.removeAudioCallback(this);
    deviceManager.closeAudioDevice();

    initialised = false;

    sampleRate = 0.0;
    phase = 0.0;
    phaseIncrement = 0.0;

    juce::Logger::writeToLog(
        "SYNO AudioEngine shutdown."
    );
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

void AudioEngine::audioDeviceAboutToStart(juce::AudioIODevice* device)
{
    if (device == nullptr)
        return;

    sampleRate = device->getCurrentSampleRate();

    if (sampleRate > 0.0)
        phaseIncrement = (twoPi * testFrequencyHz) / sampleRate;
    else
        phaseIncrement = 0.0;

    phase = 0.0;

    juce::Logger::writeToLog(
        "SYNO audio device started. Sample rate: "
        + juce::String(sampleRate)
    );
}

void AudioEngine::audioDeviceIOCallbackWithContext(
    const float* const* inputChannelData,
    int numInputChannels,
    float* const* outputChannelData,
    int numOutputChannels,
    int numSamples,
    const juce::AudioIODeviceCallbackContext&)
{
    juce::ignoreUnused(inputChannelData, numInputChannels);

    if (outputChannelData == nullptr || numOutputChannels <= 0)
        return;

    for (int channel = 0; channel < numOutputChannels; ++channel)
    {
        if (outputChannelData[channel] == nullptr)
            continue;

        auto* output = outputChannelData[channel];

        for (int sample = 0; sample < numSamples; ++sample)
        {
            output[sample] = static_cast<float>(
                0.15 * std::sin(phase)
            );

            phase += phaseIncrement;

            if (phase >= twoPi)
                phase -= twoPi;
        }
    }
}

void AudioEngine::audioDeviceStopped()
{
    juce::Logger::writeToLog(
        "SYNO audio device stopped."
    );
}
}
