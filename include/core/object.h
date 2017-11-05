/**/

#ifndef MKZ_OBJECT_H_
#define MKZ_OBJECT_H_

#include "base.h"

class Win;
class Object
{
public:
    Object();
    virtual void Draw();
    virtual void Show();
    virtual void Hide();
    void Set(Win* iwin);
    Win* GetFather();
    //paiting priority
    u32 priority = 0;
    bool shown = true;
    
    u32 getid();

private:
    u32 id = 0;
    bool set = false;
    Win* father;
};

#endif // !MKZ_OBJECT_H_
