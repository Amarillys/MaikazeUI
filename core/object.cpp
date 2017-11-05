/**/

#include "../include/core/object.h"

Object::Object()
{
    id = reinterpret_cast<u32>(this);
}

void Object::Draw()
{
}

void Object::Show()
{
}

void Object::Hide()
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
