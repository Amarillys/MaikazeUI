/**/

#include "../include/core/object.h"

Object::Object()
{
    id = reinterpret_cast<u32>(this);
}