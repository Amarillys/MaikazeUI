#include "..\include\core\text.h"

extern float ZOOM;
extern Theme DEFTHEME;
extern LocaleFile* lang;
extern stdstr FONT;

Text::Text(Win * iwin, stdstr itext)
{
}

void Text::Create(Win * iwin, stdstr itext, stdstr ifont, int isize,
    Color ibclr, Color itclr, int ix, int iy, int iw, int ih, int istyle, 
    bool ieditable, bool iwrap, bool ichosen, bool ishow)
{
    x = to0(ix);
    y = to0(iy);
    w = to0(iw);
    h = to0(ih);

}

Text::~Text()
{
}

void Text::ReDraw()
{
    dx = static_cast<int>(x * ZOOM);
    dy = static_cast<int>(y * ZOOM);
    dw = static_cast<int>(w * ZOOM);
    dh = static_cast<int>(h * ZOOM);

}

void Text::Draw()
{
}

void Text::TextChanged()
{
}

void Text::Click()
{
}

void Text::Suspend()
{
}

void Text::Left()
{
}

void Text::Focus()
{
}

void Text::LoseFocus()
{
}
