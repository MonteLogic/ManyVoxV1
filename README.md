# ManyVoxV1

I'm currently trying to add the TableListBoxTutorial to be opened with a button click. 

TableListBoxTutorial -> https://docs.juce.com/master/tutorial_table_list_box.html


Looking into this block of code for changing visibility of a window. 


```

class MainWindow : public Component
{
public:
    MainWindow()
    {
        addAndMakeVisible (openWindow);
        openWindow.onClick = [&]
        {
            if (window)
                window->bringToFront();
            else
            {
                window = new TopLevelWindow();
                window->addToDesktop ();
                window->centreWithSize (600, 400);
                window->setVisible (true);
            }
    }
    ~MainWindow()
    {
        // there are probably nicer ways using RAII, but this copes with the window being closed and destroyed
        if (window)
            delete window;
    }

    void resized() override
    {
        openWindow.setBounds (10, 10, 70, 25);
    }
private:
    TextButton openWindow { {}, "Window" };
    Component::SafePointer<TopLevelWindow> window;
};



```


If you compiled this it would look like =>  https://imgur.com/a/yUPDsTs

The current function of ManyVox is to summarize vocal stems and use algorithms to reduce volume and avoid the automating of knob movement normally found 
on the channel mixer. 

Thus, reducing the need for compression as well as reducing the amount of time and effort spent on adjusting the volume of a certain vocal stem track.


