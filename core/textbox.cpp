#include "..\include\core\textbox.h"

extern float ZOOM;
extern Theme DEFTHEME;
extern LocaleFile* lang;

TextBox::TextBox(Win* iwin, int ix, int iy, int iw, int ih, bool ishow)
{
    Set(iwin);
    w = to0(iw);
    h = to0(ih);
    x = to0(ix);
    y = to0(iy);
    dx = (int)x * ZOOM;
    dy = (int)y * ZOOM;
    dw = (int)w * ZOOM;
    dh = (int)h * ZOOM;

    sur = SDL_CreateRGBSurfaceWithFormat(0, dw, dh, 32, SDL_PIXELFORMAT_RGBA32);
    //sur = SDL_CreateRGBSurface(0, dw, dh, 24, 0, 0, 0, 0);
    if (ishow)
        Draw();
}

TextBox::~TextBox()
{
}

void TextBox::Draw()
{
    bcolor = DEFTHEME.TEXTBOXBG;
    Fill(sur, bcolor);
    SDL_Rect srect{ 0, 0, dw, dh };
    SDL_Rect drect{ dx, dy, dw, dh };
    Refresh(GetFather()->GetRen(), sur, srect, drect);
}

void TextBox::OnFocus()
{
    printf("textbox is onfocus\n");
}

void TextBox::ReDraw()
{
    dx = (int)x * ZOOM;
    dy = (int)y * ZOOM;
    dw = (int)w * ZOOM;
    dh = (int)h * ZOOM;
}
