#include "..\include\core\label.h"

extern float ZOOM;
extern Theme DEFTHEME;
extern LocaleFile* lang;
extern stdstr FONT;
Label::Label(Win* iwin, stdstr itext, int isize, int ix, int iy, int iw, int ih, bool ishow)
{
    name = itext;
    Create(iwin, itext, isize, ix, iy, iw, ih, ishow);
}

Label::Label(Win * iwin, int isize, stdstr iname, int ix, int iy, int iw, int ih, bool ishow)
{
    name = iname;
    text = lang->ReadString(lang->curLang, name);
    Create(iwin, text, isize, ix, iy, iw, ih, ishow);
}

void Label::Create(Win * iwin, stdstr itext, int isize, int ix, int iy, int iw, int ih, bool ishow)
{
    Set(iwin);
    text = itext;
    x = to0(ix);
    y = to0(iy);
    w = to0(iw);
    h = to0(ih);
    dx = static_cast<int>(x * ZOOM);
    dy = static_cast<int>(y * ZOOM);
    dw = static_cast<int>(w * ZOOM);
    dh = static_cast<int>(h * ZOOM);
    textsize = isize;
    textfont = FONT;
    clr = { 0x00, 0x00, 0x00, 0x00 };
    sur = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
    if (ishow)
        Draw();
}

Label::~Label()
{
    if (sur != nullptr)
        SDL_FreeSurface(sur);
}

void Label::Draw()
{
    if (lang->ReadString(lang->curLang, name) != "")
        text = lang->ReadString(lang->curLang, name);
    textclr = DEFTHEME.LABELCOLOR;
    Fill(sur, clr);
    ShowFontAutoPosCustom(textfont, textsize, text.c_str(), x, y, w, h, GetFather()->GetRen(), textclr);
}

void Label::ReDraw()
{
    textsize = (int)(textsize / (dx * 1.0 / x) * ZOOM);
    dx = static_cast<int>(x * ZOOM);
    dy = static_cast<int>(y * ZOOM);
    dw = static_cast<int>(w * ZOOM);
    dh = static_cast<int>(h * ZOOM);
    SDL_FreeSurface(sur);
    sur = SDL_CreateRGBSurfaceWithFormat(0, dw, dh, 32, SDL_PIXELFORMAT_RGBA32);
}

