/**/
#include "base.h"

struct Theme
{
    Color WinBg;
    Color BtnBg;
    Color BtnBgSIn;
    Color BtnBgSOut;
    Color BtnFont;
};

const Theme DK = { {0x28, 0x2d, 0x32},{ 0x30, 0x40, 0x45 } ,
                    { 0x33, 0x43, 0x48 },{ 0x36, 0x46, 0x4B } };
