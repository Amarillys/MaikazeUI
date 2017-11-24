/**/

#include "../include/core/object.h"

Object::Object()
{
    id = reinterpret_cast<u32>(this);
}

void Object::Click()
{
    f_click();
}

void Object::Draw()
{
}

void Object::Left()
{
    f_left();
}

void Object::ReDraw()
{
}

void Object::Show()
{
    f_show();
}

void Object::Suspend()
{
    f_suspend();
}

void Object::Hide()
{
    f_hide();
}

void Object::Rec()
{
}

void Object::Set(Win * iwin)
{
    if (!set)
        father = iwin;
}

Win * Object::GetFather()
{
    return father;
}

u32 Object::getid()
{
    return id;
}
