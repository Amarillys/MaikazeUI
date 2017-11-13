/**/

#include "../include/core/button.h"

extern FontSys fsys;

Button::Button(Win* iwin, int ix, int iy, int iw, int ih)
{
    Set(iwin);
    w = to0(iw);
    h = to0(ih);
    x = to0(ix);
    y = to0(iy);
    sur = SDL_CreateRGBSurface(0, w, h, 24, 0, 0, 0, 0);
    curclr = ButtonColor;
    printf("%d\n", SDL_PIXELFORMAT_BGR24);
    printf("%d\n", sur->format->format);
    Draw();
}

Button::~Button()
{
    f_click();
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
    curclr = ButtonSuspendColor;
    Draw();
    f_suspend();
}

void Button::Left()
{
    curclr = ButtonColor;
    Draw();
    f_left();
}

void Button::Hide()
{
    f_click();
}

void Button::Draw()
{
    f_click();
    SDL_Rect srect{0, 0, w, h};
    SDL_Rect drect{x, y, w, h};
    FillCRectSimple(sur, curclr, GetFather()->GetBgColor());
    Refresh(GetFather()->GetRen(), sur, srect, drect);
    //show the text
    fsys.ShowFontAutoPos("quanpother", x, y, w, h, GetFather()->GetRen());
}
