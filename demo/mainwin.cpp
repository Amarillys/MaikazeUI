#include "..\include\demo\mainwin.h"

Mainwin::Mainwin()
{
    Object* btn = new Button(this, u8"halo���", 128, 128, 160, 50);
    Add(btn);
}
