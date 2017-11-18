/**/
#include "../include/core/button.h"

extern FontSys fsys;
extern Theme DEFTHEME;
extern LocaleFile* lang;

Button::Button(Win* iwin, const char* icaption, int ix, int iy, int iw, int ih)
{
    Create(iwin, icaption, "", ix, iy, iw, ih);
}

Button::Button(Win * iwin, int ix, int iy, int iw, int ih, const char * iname)
{
    Create(iwin, lang->ReadString(lang->curLang, iname).c_str(), iname, ix, iy, iw, ih);
}

Button::~Button()
{
    f_click();
}

void Button::Create(Win* iwin, const char * icaption, const char * iname, int ix, int iy, int iw, int ih)
{
    Set(iwin);
    w = to0(iw);
    h = to0(ih);
    x = to0(ix);
    y = to0(iy);
    name = iname;
    showtext = icaption;
    sur = SDL_CreateRGBSurface(0, w, h, 24, 0, 0, 0, 0);
    cs = CONTRARY;
    SwitchCS(cs);
    st = MouseLeft;
    curclr = inclr;
    Draw();
}

void Button::DrawBg()
{
    SwitchCS(cs);
    curclr = (st == MouseLeft ? inclr : clr);
    SDL_Rect srect{ 0, 0, w, h };
    SDL_Rect drect{ x, y, w, h };
    FillCRectSimple(sur, curclr, GetFather()->GetBgColor());
    Refresh(GetFather()->GetRen(), sur, srect, drect);
}

void Button::DrawFont()
{
    fsys.ShowFontAutoPos(showtext.c_str(), x, y, w, h, GetFather()->GetRen(), fontclr);
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
    Draw();
    f_suspend();
}

void Button::Left()
{
    st = MouseLeft;
    SetCursor(MOUSE_NORMAL);
    Draw();
    f_left();
}

void Button::Hide()
{
    f_click();
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
            static_cast<uint8_t>(DEFTHEME.WinBg.b + 10 * addclr), static_cast<uint8_t>(DEFTHEME.WinBg.a + 10 * addclr) };
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
