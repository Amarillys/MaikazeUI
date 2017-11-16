/*
Initilizer v0.01
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef MKZ_INIT_H_
#define MKZ_INIT_H_

#define vname_(x) #x
#define vname(x) vname_(x)

#include "../sdl/SDL.h"
#include "../sdl/SDL_ttf.h"
#include <iostream>

using stdstr = std::string;
using u32 = Uint32;

const int REFRESHTIME = 30;
const int CircleDevide = 56;
void init(u32 flags); 

using Color = SDL_Color;

/*Color Style*/
enum CStyle
{
    CONTRARY,
    TRANSPARENT
};

enum Status
{
    OnFocus,
    MouseSuspend,
    MouseLeft
};

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
inline void dp(SDL_Surface* isur, int ix, int iy, Color irgb)
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

void Refresh(SDL_Renderer* iren, SDL_Surface* isur);

inline int Fuck(int ix, int iy, int iw){
    return ((iy - 1) * iw + ix - 1) * 3 + (iw % 4) * (iy - 1);
}

void Refresh(SDL_Renderer* iren, SDL_Surface* isur, SDL_Rect& isrect, SDL_Rect& idrect);
void Refresh(SDL_Renderer* iren, SDL_Texture* itex, SDL_Rect& isrect, SDL_Rect& idrect);

int min(int ia, int ib);
int max(int ia, int ib);
int abs(int ia);
Color Str2Clr(stdstr istr);
void FillCRectSimple(SDL_Surface* isur, Color irgb, Color ibg);
void Fill(SDL_Surface* isur, Color irgb);
#endif // !MKZ_INIT_H_