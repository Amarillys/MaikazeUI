/*
*/
#ifndef MKZ_BUTTON_H_
#define MKZ_BUTTON_H_

#include "window.h"
#include "object.h"

class Button:public Object
{
public:
    void Click();
    void Hide();
    void Show();

    void Draw();

    Button();
    ~Button();

    u32 w, h;
    stdstr text;
    u32 textsize;
    
    void(*f_click)() = callnull;
    void(*f_show)() = callnull;
    void(*f_hide)() = callnull;


private:
    Win* father;
    
};


#define MKZ_BUTTON_H_
#endif // !MKZ_BUTTON_H_
