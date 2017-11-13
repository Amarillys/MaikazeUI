/**/

#ifndef MKZ_OBJECT_H_
#define MKZ_OBJECT_H_

#include "base.h"

class Win;
class Object
{
public:
    Object();
    virtual void Click();
    virtual void Draw();
    virtual void Left();
    virtual void Show();
    virtual void Suspend();
    virtual void Hide();
    virtual void Rec();

    int x, y, w, h;
    void Set(Win* iwin);
    Win* GetFather();
    //paiting priority
    u32 priority = 0;
    bool shown = true;

    void(*f_click)() = callnull;
    void(*f_left)() = callnull;
    void(*f_suspend)() = callnull;
    void(*f_show)() = callnull;
    void(*f_hide)() = callnull;
    
    u32 getid();

private:
    u32 id = 0;
    bool set = false;
    Win* father;
};

#endif // !MKZ_OBJECT_H_
