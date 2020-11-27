/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DirectoryOpener  : public Component,
                         public Button::Listener
{
public:
    //==============================================================================
    DirectoryOpener ();
    ~DirectoryOpener() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void fileBrowser();
    void folderBrowser();
    void process();
    void processFile();
    void processFolder();

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    String filePathStr, folderPathStr;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label;
    std::unique_ptr<TextButton> fileBrowse;
    std::unique_ptr<TextEditor> filePath;
    std::unique_ptr<Label> label2;
    std::unique_ptr<TextEditor> folderPath;
    std::unique_ptr<TextButton> folderBrowse;
    std::unique_ptr<TextButton> btnProcess;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DirectoryOpener)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

