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
    dx = static_cast<int>(x * ZOOM);
    dy = static_cast<int>(y * ZOOM);
    dw = static_cast<int>(w * ZOOM);
    dh = static_cast<int>(h * ZOOM);

    bg = SDL_CreateRGBSurfaceWithFormat(0, dw, dh, 32, SDL_PIXELFORMAT_RGBA32);
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
    Fill(bg, bcolor);
    SDL_Rect srect{ 0, 0, dw, dh };
    SDL_Rect drect{ dx, dy, dw, dh };
    Refresh(GetFather()->GetRen(), bg, srect, drect);
}

void TextBox::OnFocus()
{
    printf("textbox is onfocus\n");
    f_onfocus();

    //Deal and Receive
    //



}

void TextBox::ReDraw()
{
    dx = static_cast<int>(x * ZOOM);
    dy = static_cast<int>(y * ZOOM);
    dw = static_cast<int>(w * ZOOM);
    dh = static_cast<int>(h * ZOOM);
}

void TextBox::Click()
{
	f_click();
	OnFocus();
}