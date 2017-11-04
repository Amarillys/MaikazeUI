/**/

#include "../include/core/button.h"

Button::Button()
{

}

Button::~Button()
{
    f_click();
}

void Button::Click()
{
    f_click();
}

void Button::Show()
{
    f_show();
}

void Button::Hide()
{
    f_click();
}

void Button::Draw()
{
    f_click();

}
