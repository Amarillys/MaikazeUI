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
    void Suspend();
    void Left();
    void Draw();
    

    Button(Win* iwin, const char* icaption, int ix, int iy, int iw, int ih);
    Button(Win* iwin, int ix, int iy, int iw, int ih, const char* name);
    ~Button();

    char* text;
    u32 textsize;
    

private:
    SDL_Surface* sur;
    Color curclr;

    void Create(Win* iwin, const char* icaption, int ix, int iy, int iw, int ih);
    void DrawBg();
    void DrawFont();
};


#define MKZ_BUTTON_H_
#endif // !MKZ_BUTTON_H_
