/**/

#ifndef MKZ_OBJECT_H_
#define MKZ_OBJECT_H_

#include "init.h"

class Object
{
public:
    Object();
    virtual ~Object();
    virtual void Draw();

private:
    u32 id;

};

#endif // !MKZ_OBJECT_H_
