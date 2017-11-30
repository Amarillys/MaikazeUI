/*start on 171130*/
#ifndef _MAIKAZE_LABEL_H_
#define _MAIKAZE_LABEL_H_

#include "object.h"
#include "locale.h"
#include "font.h"
#include "theme.h"
#include "window.h"

class Label: public Object
{
public:
    Label(Win* iwin, stdstr itext, int isize, int ix, int iy, int iw, int ih, bool ishow);
    Label(Win* iwin, int isize, stdstr iname, int ix, int iy, int iw, int ih, bool ishow);
    ~Label();
    void Draw();
    void ReDraw();

    Color clr;
    Color textclr;
    stdstr name;
    stdstr text;
    stdstr textfont;
    int textsize;

private:
    void Create(Win* iwin, stdstr itext, int isize, int ix, int iy, int iw, int ih, bool ishow);
    SDL_Surface* sur;
};

#endif