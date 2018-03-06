#include "..\include\demo\mainwin.h"

extern LocaleFile* lang;
extern Mainwin* mw;
extern Theme DEFTHEME;
extern float ZOOM;
extern stdstr FONT;
Mainwin::Mainwin(): Win("MaikazeUI", 640, 480)
{
    btn = new Button(this, 128, 128, 200, 50, "test", 24, false);
    btn->cr = 5;
    btn->f_suspend = TestBtn_Suspend;
    btn->f_left = TestBtn_Left;
    btn->f_click = TestBtn_Click;
    btn->Draw();
    Add(btn);

    btn2 = new Button(this, u8"计时", 328, 328, 300, 60, 24, true);
    btn2->SwitchCS(TRANSPARENT);
    btn2->Draw();
    btn2->f_click = []() 
    {
        DEFTHEME = DK;
        mw->btn->font = "c:/windows/fonts/msyh.ttc";
        mw->Draw();
        ZOOM = 1.0;
        mw->ReDraw();
    };

    btn2->f_suspend = []()
    {
        printf("btn2's bgcolor is %d %d %d %d\n", mw->btn2->clr.r, mw->btn2->clr.g, mw->btn2->clr.b, mw->btn2->clr.a );
    };
    Add(btn2);

    btn3 = new Button(this, u8"退出", 128, 408, 160, 50, 24, true);
    btn3->SwitchCS(TRANSPARENT);
    btn3->Draw();
    btn3->f_click = []()
    {
        exit(0);
    };
    Add(btn3);

    tb = new TextBox(this, 100, 200, 300, 40, true);
    Add(tb);

    testlbl = new Label(this, u8"中文", 30, 50, 50, 200, 70, true);
    testlbl_lang = new Label(this, 30, "testlbl_lang", 300, 100, 300, 60, true);
    Add(testlbl);
    Add(testlbl_lang);
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
    mw->btn->font = FONT;
    mw->btn2->showtext = u8"老妖婆";
    DEFTHEME = Hikari;
    mw->Draw();
    ZOOM = 1.5;
    mw->ReDraw();
}
