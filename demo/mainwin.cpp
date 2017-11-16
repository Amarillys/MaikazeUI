#include "..\include\demo\mainwin.h"
#include "..\include\core\locale.h"
#include "..\include\core\theme.h"

extern LocaleFile* lang;
extern Mainwin* mw;
extern Theme DEFTHEME;

Mainwin::Mainwin()
{
    btn = new Button(this, 128, 128, 160, 50, "test");
    btn->f_suspend = TestBtn_Suspend;
    btn->f_left = TestBtn_Left;
    btn->f_click = TestBtn_Click;
    Add(btn);

    btn2 = new Button(this, u8"¹þ¹þ", 328, 328, 160, 50);
    btn2->SwitchCS(TRANSPARENT);
    btn2->Draw();
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
//    mw->btn2->Draw();
}