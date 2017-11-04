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

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

const Color Default{ 0x28, 0x2D, 0x32 };

inline void rto0(int& ix)
{ 
    if (ix < 0)
        ix = 0;
}

inline int to0(int ix)
{
    if (ix < 0)
        return 0;
    return ix;
}

//DrawPixel
inline void dp(SDL_Surface * isur, int ix, int iy, Color irgb)
{    
    int offset = ((iy - 1) * isur->w + ix - 1) * 3;
    ((uint8_t *)isur->pixels)[++offset] = irgb.r;
    ((uint8_t *)isur->pixels)[++offset] = irgb.g;
    ((uint8_t *)isur->pixels)[++offset] = irgb.b;
}

inline void callnull()
{
    printf("call null function.\n");
}

void Refresh(SDL_Renderer * iren, SDL_Surface * isur);
void Fill(SDL_Surface * isur, Color irgb);
#endif // !MKZ_INIT_H_