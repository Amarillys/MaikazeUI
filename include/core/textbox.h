#ifndef _MAIKAZE_TEXTBOX_H_
#define _MAIKAZE_TEXTBOX_H_

#include "window.h"
#include "locale.h"
#include "theme.h"
#include <vector>

using std::vector;

class TextBox : public Object
{
public:
    TextBox(Win* iwin, int ix, int iy, int iw, int ih, bool ishow);
    ~TextBox();


    stdstr text;
    stdstr tips;
    stdstr font;
    int textsize;
    Color bcolor;
    Color tcolor;
    bool encrypt = false;
    bool italic = false;
    bool bold = false;
    bool underline = false;
    
    void Click();
    void Draw();
    void OnFocus();
    void ReDraw();

    void(*f_change)() = callnull;
    void(*f_onfocus)() = callnull;
    void(*f_select)() = callnull;
    void(*f_scrollx)() = callnull;
    void(*f_scrolly)() = callnull;

protected:
    vector<SDL_Surface*> fntsur;
    size_t locale;
    SDL_Surface* bg;
	SDL_Surface* ptr;
};


#endif // ! _MAIKAZE_TEXTBOX_H_
