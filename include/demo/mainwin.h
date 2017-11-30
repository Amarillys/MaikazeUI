/*Demo*/
#ifndef MAIKAZE_MAINWIN_H_
#define MAIKAZE_MAINWIN_H_

#include "../core/window.h"
#include "../core/button.h"
#include "../core/label.h"
#include "../core/textbox.h"
#include "../core/locale.h"
#include "../core/theme.h"

void TestBtn_Suspend();
void TestBtn_Left();
void TestBtn_Click();

class Mainwin : public Win
{
public:
    //
    Mainwin();
    Button* btn;
    Button* btn2;
    Label *testlbl;
    Label *testlbl_lang;
    TextBox* tb;

private:
};

#endif