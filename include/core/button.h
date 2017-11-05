/*
*/
#ifndef MKZ_BUTTON_H_
#define MKZ_BUTTON_H_

#include "font.h"
#include "window.h"
#include "object.h"

class Button:public Object
{
public:
    void Click();
    void Hide();
    void Show();

    void Draw();

    Button(Win* iwin, int ix, int iy, int iw, int ih);
    ~Button();

    u32 w, h, x, y;
    stdstr text;
    u32 textsize;
    
    void(*f_click)() = callnull;
    void(*f_show)() = callnull;
    void(*f_hide)() = callnull;


private:
    SDL_Surface* sur;
};


#define MKZ_BUTTON_H_
#endif // !MKZ_BUTTON_H_
