/**/
#include "../include/core/button.h"

extern stdstr FONT;
extern Theme DEFTHEME;
extern LocaleFile* lang;
extern float ZOOM;
Button::Button(Win* iwin, const char* icaption, int ix, int iy, int iw, int ih, int itextsize, bool ishow)
{
    Create(iwin, icaption, "", ix, iy, iw, ih, itextsize, 0, ishow);
}

Button::Button(Win * iwin, int ix, int iy, int iw, int ih, const char * iname, int itextsize, bool ishow)
{
    Create(iwin, lang->ReadString(lang->curLang, iname).c_str(), iname, ix, iy, iw, ih, itextsize, 0, ishow);
}

Button::~Button()
{
    f_click();
}

void Button::Create(Win* iwin, const char * icaption, const char * iname, int ix, int iy, int iw, int ih, int itextsize, int icr,bool ishow)
{
    Set(iwin);
    textsize = itextsize;
    w = to0(iw);
    h = to0(ih);
    x = to0(ix);
    y = to0(iy);
    dx = static_cast<int>(x * ZOOM);
    dy = static_cast<int>(y * ZOOM);
    dw = static_cast<int>(w * ZOOM);
    dh = static_cast<int>(h * ZOOM);
    name = iname;
    showtext = icaption;
    //sur = SDL_CreateRGBSurface(0, dw, dh, 24, 0, 0, 0, 0);
    sur = SDL_CreateRGBSurfaceWithFormat(0, dw, dh, 32, SDL_PIXELFORMAT_RGBA32);
    cs = CONTRARY;
    SwitchCS(cs);
    st = MouseLeft;
    curclr = inclr;
    font = FONT;
    if (ishow)
        Draw();
}

void Button::DrawBg()
{
    SwitchCS(cs);
    curclr = (st == MouseLeft ? inclr : clr);
    SDL_Rect srect{ 0, 0, dw, dh };
    SDL_Rect drect{ dx, dy, dw, dh };
    FillCRectSimple(sur, curclr, cr);
    Refresh(GetFather()->GetRen(), sur, srect, drect);
}

void Button::DrawFont()
{
    ShowFontAutoPosCustom(font, textsize, showtext.c_str(), dx, dy, dw, dh, GetFather()->GetRen(), fontclr);
}

void Button::CheckText()
{
    if (name == "")
        return;
    showtext = lang->ReadString(lang->curLang, name);
    if (showtext == "")
        showtext = name;
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
    st = MouseSuspend;
    SetCursor(MOUSE_HAND);
    f_suspend();
    Draw();
}

void Button::Left()
{
    st = MouseLeft;
    SetCursor(MOUSE_NORMAL);
    f_left();
    Draw();
}

void Button::Hide()
{
    f_click();
}

void Button::ReDraw()
{
    textsize = (int)(textsize  / (dx * 1.0 / x) * ZOOM);
    dx = static_cast<int>(x * ZOOM);
    dy = static_cast<int>(y * ZOOM);
    dw = static_cast<int>(w * ZOOM);
    dh = static_cast<int>(h * ZOOM);
    SDL_FreeSurface(sur);

    sur = SDL_CreateRGBSurfaceWithFormat(0, dw, dh, 32, SDL_PIXELFORMAT_RGBA32);
    //sur = SDL_CreateRGBSurface(0, dw, dh, 24, 0, 0, 0, 0);
}

void Button::Draw()
{
    CheckText();
    DrawBg();
    DrawFont();
}

void Button::SwitchCS(CStyle ics)
{
    int addclr = (DEFTHEME.WinBg.r < 128) ? 1 : -1;
    cs = ics;
    switch (cs)
    {
    case TRANSPARENT:
        inclr = DEFTHEME.WinBg;
        clr = Color{ static_cast<uint8_t>(DEFTHEME.WinBg.r + 10 * addclr), static_cast<uint8_t>(DEFTHEME.WinBg.g + 10 * addclr),
            static_cast<uint8_t>(DEFTHEME.WinBg.b + 10 * addclr), DEFTHEME.WinBg.a };
        fontclr = DEFTHEME.FontColor;
        
        if (DEFTHEME.BtnBg.r == Hikari.BtnBg.r)
            fontclr = DEFTHEME.BtnBg;
        break;

    case CONTRARY:
    default:
        clr = DEFTHEME.BtnBgSOut;
        inclr = DEFTHEME.BtnBg;
        fontclr = DEFTHEME.FontColor;
        break;
    }
}
