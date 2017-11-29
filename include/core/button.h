/*
*/
#ifndef MKZ_BUTTON_H_
#define MKZ_BUTTON_H_

#include "font.h"
#include "window.h"
#include "locale.h"
#include "theme.h"

class Button:public Object
{
public:
    void Click();
    void Hide();
    void ReDraw();
    void Show();
    void Suspend();
    void Left();
    void Draw();
    void SwitchCS(CStyle ics);

    Button(Win* iwin, const char* icaption, int ix, int iy, int iw, int ih, int itextsize);

    /*if you prefer read text from config, then you use this construction function.*/
    Button(Win* iwin, int ix, int iy, int iw, int ih, const char* name, int itextsize);
    ~Button();

    stdstr name;
    stdstr showtext;
    u32 textsize;
    stdstr font;
    Color curclr;
    Color clr;
    Color inclr;
    CStyle cs;
    

protected:
    SDL_Surface* sur;
    Color fontclr;
    Status st;

    void Create(Win* iwin, const char* icaption, const char* name, int ix, int iy, int iw, int ih, int itextsize);
    void DrawBg();
    void DrawFont();
    void CheckText();
};


#endif // !MKZ_BUTTON_H_
