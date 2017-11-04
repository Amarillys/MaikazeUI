/**/

#ifndef MKZ_OBJECT_H_
#define MKZ_OBJECT_H_

#include "base.h"

class Object
{
public:
    Object();
    virtual void Draw() = 0;
    virtual void Show() = 0;
    virtual void Hide() = 0;

    //paiting priority
    u32 priority = 0;
    bool shown = true;
    
    u32 getid() { return id; }

private:
    u32 id = 0;
};

#endif // !MKZ_OBJECT_H_
