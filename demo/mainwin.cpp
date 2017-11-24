#include "..\include\demo\mainwin.h"

extern LocaleFile* lang;
extern Mainwin* mw;
extern Theme DEFTHEME;
extern float ZOOM;
Mainwin::Mainwin(): Win("Fuck Lyp", 640, 480)
{
    btn = new Button(this, 128, 128, 300, 50, "test");
    btn->f_suspend = TestBtn_Suspend;
    btn->f_left = TestBtn_Left;
    btn->f_click = TestBtn_Click;
    Add(btn);

    btn2 = new Button(this, u8"¹þ¹þ", 328, 328, 160, 50);
    btn2->SwitchCS(TRANSPARENT);
    btn2->Draw();
    btn2->f_click = []() 
    {
        DEFTHEME = DK;
        mw->Draw();
        ZOOM = 1.0;
        mw->ReDraw();
    };
    Add(btn2);
}


void TestBtn_Suspend()
{
    lang->SetLocale("Chinese");
}

void TestBtn_Left()
{
    lang->SetLocale("English");
}

void TestBtn_Click()
{
    mw->btn2->showtext = u8"ÀÏÑýÆÅ";
    DEFTHEME = Hikari;
    mw->Draw();
    ZOOM = 1.5;
    mw->ReDraw();
}
