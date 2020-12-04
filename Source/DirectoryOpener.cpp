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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "DirectoryOpener.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DirectoryOpener::DirectoryOpener ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label.reset (new Label ("new label",
                            TRANS("Input File")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (26, 24, 80, 24);

    fileBrowse.reset (new TextButton ("fileBrowse"));
    addAndMakeVisible (fileBrowse.get());
    fileBrowse->setButtonText (TRANS("Browse"));
    fileBrowse->addListener (this);

    fileBrowse->setBounds (32, 96, 150, 24);

    filePath.reset (new TextEditor ("filePath"));
    addAndMakeVisible (filePath.get());
    filePath->setMultiLine (false);
    filePath->setReturnKeyStartsNewLine (false);
    filePath->setReadOnly (false);
    filePath->setScrollbarsShown (true);
    filePath->setCaretVisible (true);
    filePath->setPopupMenuEnabled (true);
    filePath->setText (String());

    filePath->setBounds (32, 56, 416, 24);

    label2.reset (new Label ("new label",
                             TRANS("Folder to Process")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (32, 160, 150, 24);

    folderPath.reset (new TextEditor ("folderPath"));
    addAndMakeVisible (folderPath.get());
    folderPath->setMultiLine (false);
    folderPath->setReturnKeyStartsNewLine (false);
    folderPath->setReadOnly (false);
    folderPath->setScrollbarsShown (true);
    folderPath->setCaretVisible (true);
    folderPath->setPopupMenuEnabled (true);
    folderPath->setText (String());

    folderPath->setBounds (32, 192, 408, 24);

    folderBrowse.reset (new TextButton ("folderBrowse"));
    addAndMakeVisible (folderBrowse.get());
    folderBrowse->setButtonText (TRANS("Browse"));
    folderBrowse->addListener (this);

    folderBrowse->setBounds (32, 240, 150, 24);

    btnProcess.reset (new TextButton ("btnProcess"));
    addAndMakeVisible (btnProcess.get());
    btnProcess->setButtonText (TRANS("Process"));
    btnProcess->addListener (this);

    btnProcess->setBounds (32, 296, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

DirectoryOpener::~DirectoryOpener()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    fileBrowse = nullptr;
    filePath = nullptr;
    label2 = nullptr;
    folderPath = nullptr;
    folderBrowse = nullptr;
    btnProcess = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DirectoryOpener::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DirectoryOpener::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DirectoryOpener::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == fileBrowse.get())
    {
        //[UserButtonCode_fileBrowse] -- add your button handler code here..
        fileBrowser();
        //[/UserButtonCode_fileBrowse]
    }
    else if (buttonThatWasClicked == folderBrowse.get())
    {
        //[UserButtonCode_folderBrowse] -- add your button handler code here..
        folderBrowser();
        //[/UserButtonCode_folderBrowse]
    }
    else if (buttonThatWasClicked == btnProcess.get())
    {
        //[UserButtonCode_btnProcess] -- add your button handler code here..
        process();
        //[/UserButtonCode_btnProcess]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void DirectoryOpener::folderBrowser()
{
    FileChooser myChooser("Choose a directory...",File::getCurrentWorkingDirectory(),"*.cpp,*.txt,*.h",
    true);
    if (myChooser.browseForDirectory())
    {
        auto result = myChooser.getURLResult();
        folderPathStr = result.isLocalFile() ? result.getLocalFile().getFullPathName()
                                                        : result.toString (true);
        folderPath->setText (folderPathStr);
    }
}
void DirectoryOpener::fileBrowser()
{
    FileChooser myChooser ("Please select the file you want to load...",
    File::getCurrentWorkingDirectory(),
    "*.cpp,*.txt,*.h");
    if (myChooser.browseForFileToOpen())
    {
        File ourFile (myChooser.getResult());
        filePathStr = ourFile.getFullPathName();
        filePath->setText (filePathStr);
    }
}

void DirectoryOpener::process()
{
    if (filePathStr.isNotEmpty())
    {
      processFile();
    }
    if (folderPathStr.isNotEmpty())
    {
        processFolder();
    }

}

void DirectoryOpener::processFile()
{
    int fir = 0, sec = 0;
    StringArray data,tempData;
    data.clear();
    tempData.clear();
    File ourFile (filePathStr);
    String wholeFile;
    wholeFile.clear();
    wholeFile = ourFile.loadFileAsString();
    fir = wholeFile.indexOf("TRANS(");
    while (fir > 1)
    {
        sec = wholeFile.indexOf(fir,")");
        String fetched =  wholeFile.substring(fir + 6, sec );
        if (!data.contains(fetched +  " = " + fetched))
        {
           data.add(fetched +  " = " + fetched);
        }
        fir = wholeFile.indexOf(sec, "TRANS(");
    }
    File f = juce::File::getCurrentWorkingDirectory().getChildFile("stringData.txt");
    if( !f.existsAsFile() )
    {
        auto result = f.create();
        if( !result.wasOk() )
        {
            DBG( "failed creating file!" );
            jassertfalse; //pause so we can see the error message
            return;  //bail
        }
    }
    else
    {
        String wholeFile = f.loadFileAsString();
        tempData.addLines(wholeFile);
        for (int a= 0; a < tempData.size(); a++)
        {
            if (data.contains(tempData[a]))
            {
               data.removeString(tempData[a]);
            
            }
        }

    }
    for (int a= 0; a < data.size(); a++  )
    {
        f.appendText(data[a] +"\n");
    }

}
void DirectoryOpener::processFolder()
{
    StringArray data,tempData;
    data.clear();
    tempData.clear();
    juce::DirectoryIterator itr(folderPathStr, true,"*.cpp, *.h, *.txt");
    while (itr.next())
    {
        int fir = 0, sec = 0;
        File theFileItFound (itr.getFile());
        String wholeFile = theFileItFound.loadFileAsString();
        fir = wholeFile.indexOf("TRANS(");
        while (fir > 1)
        {
            sec = wholeFile.indexOf(fir,")");
            String fetched =  wholeFile.substring(fir + 6, sec );
            if (!data.contains(fetched +  " = " + fetched))
            {
            data.add(fetched +  " = " + fetched);
            }
            fir = wholeFile.indexOf(sec, "TRANS(");
        }

    }
    File f = juce::File::getCurrentWorkingDirectory() .getChildFile ("stringData.txt");
    if( !f.existsAsFile() )
    {
        auto result = f.create();
        if( !result.wasOk() )
        {
            DBG( "failed creating file!" );
            jassertfalse; //pause so we can see the error message
            return;  //bail
        }
    }
    else
    {
        String wholeFile = f.loadFileAsString();
         tempData.addLines(wholeFile);
         for (int a= 0; a < tempData.size(); a++)
         {

             if (data.contains(tempData[a]))
             {
                data.removeString(tempData[a]);
             
             }
         }

    }
    for (int a= 0; a < data.size(); a++  )
    {

        f.appendText(data[a] +"\n");
    }

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DirectoryOpener" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="ae6304902a0d0a15" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="26 24 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Input File" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="fileBrowse" id="8178dc14ae8cf506" memberName="fileBrowse"
              virtualName="" explicitFocusOrder="0" pos="32 96 150 24" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="filePath" id="1950047376058bda" memberName="filePath" virtualName=""
              explicitFocusOrder="0" pos="32 56 416 24" initialText="" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="c3d30e54c478b91d" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="32 160 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Folder to Process" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="folderPath" id="61e01c3abafb8ba4" memberName="folderPath"
              virtualName="" explicitFocusOrder="0" pos="32 192 408 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="folderBrowse" id="30caf8f36f6a13a" memberName="folderBrowse"
              virtualName="" explicitFocusOrder="0" pos="32 240 150 24" buttonText="Browse"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="btnProcess" id="c3c9bb914095809" memberName="btnProcess"
              virtualName="" explicitFocusOrder="0" pos="32 296 150 24" buttonText="Process"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

