/**/

#include "../include/core/button.h"
#include "../include/core/theme.h"

extern FontSys fsys;
extern Theme DEFTHEME;

Button::Button(Win* iwin, const char* icaption, int ix, int iy, int iw, int ih)
{
    Create(iwin, icaption, ix, iy, iw, ih);
}

Button::Button(Win * iwin, int ix, int iy, int iw, int ih, const char * name)
{
    text = u8"fuck";
    Create(iwin, text, ix, iy, iw, ih);
}

Button::~Button()
{
    f_click();
}

void Button::Create(Win* iwin, const char * icaption, int ix, int iy, int iw, int ih)
{
    Set(iwin);
    w = to0(iw);
    h = to0(ih);
    x = to0(ix);
    y = to0(iy);
    text = new char[strlen(icaption)];
    strcpy(text, icaption);
    sur = SDL_CreateRGBSurface(0, w, h, 24, 0, 0, 0, 0);
    curclr = DEFTHEME.BtnBg;
    printf("%d\n", SDL_PIXELFORMAT_BGR24);
    printf("%d\n", sur->format->format);
    Draw();

}

void Button::DrawBg()
{
    SDL_Rect srect{ 0, 0, w, h };
    SDL_Rect drect{ x, y, w, h };
    FillCRectSimple(sur, curclr, GetFather()->GetBgColor());
    Refresh(GetFather()->GetRen(), sur, srect, drect);
}

void Button::DrawFont()
{
    fsys.ShowFontAutoPos(text, x, y, w, h, GetFather()->GetRen());
}

void Button::Click()
{
    f_click();
}

void Button::Show()
{
    f_show();
}

void Button::Suspend()
{
    curclr = DEFTHEME.BtnBgSIn;
    Draw();
    curclr = DEFTHEME.BtnBgSOut;
    Draw();
    f_suspend();
}

void Button::Left()
{
    curclr = DEFTHEME.BtnBgSIn;
    Draw();
    curclr = DEFTHEME.BtnBg;
    Draw();
    f_left();
}

void Button::Hide()
{
    f_click();
}

void Button::Draw()
{
    //f_click();
    DrawBg();
    DrawFont();
}
