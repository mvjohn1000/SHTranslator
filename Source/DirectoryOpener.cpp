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

    dialogOpe.reset (new TextButton ("dialogOpe"));
    addAndMakeVisible (dialogOpe.get());
    dialogOpe->setButtonText (TRANS("Open Folder"));
    dialogOpe->addListener (this);

    dialogOpe->setBounds (112, 184, 150, 24);


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

    dialogOpe = nullptr;


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

    if (buttonThatWasClicked == dialogOpe.get())
    {
        //[UserButtonCode_dialogOpe] -- add your button handler code here..
        showWindow();
        //[/UserButtonCode_dialogOpe]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void DirectoryOpener::showWindow()
{
    String nameStr;
    fc.reset (new FileChooser ("Choose a directory...",
                                           File::getCurrentWorkingDirectory(),
                                           "*",
                                           true));

    fc->launchAsync (FileBrowserComponent::openMode | FileBrowserComponent::canSelectDirectories,
     [] (const FileChooser& chooser)
    {
         auto result = chooser.getURLResult();
         auto name = result.isLocalFile() ? result.getLocalFile().getFullPathName()
                                          : result.toString (true);
        StringArray data;
        data.clear();
        juce::DirectoryIterator itr(name, true,"*.cpp, *.h");
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
                if (!data.contains(fetched))
                {
                   data.add(fetched);
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
            f.replaceWithText("");
        }

        for (int a= 0; a < data.size(); a++  )
        {
            f.appendText(data[a] +  " = " + data[a] +"\n");
        }
        });
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
  <TEXTBUTTON name="dialogOpe" id="90f1171ac39300ad" memberName="dialogOpe"
              virtualName="" explicitFocusOrder="0" pos="112 184 150 24" buttonText="Open Folder"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

