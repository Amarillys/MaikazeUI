/*
Initilizer v0.01
*/
#ifndef MKZ_INIT_H_
#define MKZ_INIT_H_

#define vname_(x) #x
#define vname(x) vname_(x)

#include "../sdl/SDL.h"
#include <iostream>

using stdstr = std::string;
using u32 = Uint32;

void init(u32 flags);
inline void to0(int& ix)
{ 
    if (ix < 0)
        ix = 0;
}

#endif // !MKZ_INIT_H_