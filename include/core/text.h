/*Independent text module*/
#ifndef  _MAIKAZE_TEXT_H_
#define _MAIKAZE_TEXT_H_

#include "object.h"
#include "locale.h"
#include "window.h"
#include "theme.h"

const int TBOLD = 0x0001;
const int TITALIC = 0x0010;
const int TUNDERLINE = 0x0100;


class Text: Object
{
public:
    Text(Win* iwin, stdstr itext);
    void Create(Win* iwin, stdstr itext, stdstr ifont, int isize, 
        Color ibclr, Color itclr, int ix, int iy, int iw, int ih, int istyle,
        bool ieditable, bool iwrap, bool ichosen, bool ishow);
    ~Text(); 
    
    void ReDraw();
    void Draw();

    void TextChanged();
    void Click();
    void Suspend();
    void Left();
    void Focus();
    void LoseFocus();

    
    Color tclr;
    Color bclr;
    stdstr font;
    int size;
    int style;

    
    bool editable = false;
    bool chosen = false;
    bool wrap = true;

protected:
    map<SDL_Surface*, SDL_Surface*> texture;
};



#endif // ! _MAIKAZE_TEXT_H_
