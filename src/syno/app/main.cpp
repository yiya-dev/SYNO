#include <JuceHeader.h>
#include "../audio/AudioEngine.h"

class MainComponent final : public juce::Component
{
public:
    MainComponent()
    {
        setSize(1200, 700);
    }

    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::black);

        g.setColour(juce::Colours::white);
        g.setFont(36.0f);

        g.drawText(
            "SYNO",
            getLocalBounds(),
            juce::Justification::centred,
            true
        );
    }
};

class SynoApplication final : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override
    {
        return "SYNO";
    }

    const juce::String getApplicationVersion() override
    {
        return "0.1.0";
    }

    bool moreThanOneInstanceAllowed() override
    {
        return true;
    }

    void initialise(const juce::String&) override
    {
        audioEngine = std::make_unique<syno::AudioEngine>();

        if (!audioEngine->initialise())
        {
            juce::Logger::writeToLog("SYNO: audio engine failed to initialise.");
        }

        mainWindow = std::make_unique<MainWindow>();
    }

    void shutdown() override
    {
        mainWindow.reset();
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted(const juce::String&) override
    {
    }

private:
    class MainWindow final : public juce::DocumentWindow
    {
    public:
        MainWindow()
            : DocumentWindow(
                "SYNO",
                juce::Colours::black,
                juce::DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MainComponent(), true);
            centreWithSize(getWidth(), getHeight());
            setResizable(true, true);
            setVisible(true);
        }

        void closeButtonPressed() override
        {
            juce::JUCEApplication::getInstance()->systemRequestedQuit();
        }
    };

    std::unique_ptr<MainWindow> mainWindow;
    std::unique_ptr<syno::AudioEngine> audioEngine;
};

START_JUCE_APPLICATION(SynoApplication)