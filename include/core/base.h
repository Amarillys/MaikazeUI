/*
Initilizer v0.02
Now only support for RGBA32!
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

extern SDL_Cursor* MOUSE_BUSY;
extern SDL_Cursor* MOUSE_CROSSHAIR;
extern SDL_Cursor* MOUSE_HAND;
extern SDL_Cursor* MOUSE_NO;
extern SDL_Cursor* MOUSE_NORMAL;
extern SDL_Cursor* MOUSE_SIZE_ALL;
extern SDL_Cursor* MOUSE_SIZE_NESW;
extern SDL_Cursor* MOUSE_SIZE_NS;
extern SDL_Cursor* MOUSE_SIZE_NWSE;
extern SDL_Cursor* MOUSE_SIZE_WE;
extern SDL_Cursor* MOUSE_WAIT;

using Color = SDL_Color;

/*Color Style*/
enum CStyle
{
    CONTRARY,
    TRANSPARENT
};

/*Event for Object Status*/
enum Status
{
    OnFocus,
    MouseSuspend,
    MouseLeft
};

const uint8_t CR2[2][2]   = {{75, 228}, {228, 255} };
const uint8_t CR3[3][3]   = {{0, 107, 224}, {107, 255, 255}, {224, 255, 255}};
const uint8_t CR4[4][4]   = {{0, 51, 173, 222}, {51, 217, 255, 255}, {173, 255, 255, 255}, {217, 255, 255, 255}};

const uint8_t CR5[5][5]   = {{  0,   0,  78, 191, 255},
                             {  0, 135, 255, 255, 255},
                             { 78, 255, 255, 255, 255},
                             {191, 255, 255, 255, 255}, 
                             {255, 255, 255, 255, 255}};

const uint8_t CR10[10][10] = {{   0,   0,   0,   0,   0,   0,  89, 171, 222, 255},
                             {   0,   0,   0,   0,  84, 227, 255, 255, 255, 255},
                             {   0,   0,   0, 145, 255, 255, 255, 255, 255, 255},
                             {   0,   0, 145, 255, 255, 255, 255, 255, 255, 255},
                             {   0,  84, 255, 255, 255, 255, 255, 255, 255, 255},
                             {   0, 227, 255, 255, 255, 255, 255, 255, 255, 255},
                             {  89, 255, 255, 255, 255, 255, 255, 255, 255, 255},
                             { 171, 255, 255, 255, 255, 255, 255, 255, 255, 255},
                             { 222, 255, 255, 255, 255, 255, 255, 255, 255, 255},
                             { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}};

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

/*Define the first line as line 0, not line 1*/
inline int pos(int ix, int iy, int iw){
    return iw * iy * 4 + ix;
    //BGR24
    //return ((iy - 1) * iw + ix - 1) * 3 + (iw % 4) * (iy - 1);
}

void Refresh(SDL_Renderer* iren, SDL_Surface* isur, SDL_Rect& isrect, SDL_Rect& idrect);
void Refresh(SDL_Renderer* iren, SDL_Texture* itex, SDL_Rect& isrect, SDL_Rect& idrect);

int min(int ia, int ib);
int max(int ia, int ib);
int abs(int ia);
Color Str2Clr(stdstr istr);
void FillCRectSimple(SDL_Surface* isur, Color irgb, Color ibg, int ir);
void Fill(SDL_Surface* isur, Color irgb);
void SetCursor(SDL_Cursor* icur);

/*the length's unit based on a pixel, one length = one pixel = 4bit(RGBA)*/
void copypx_r(uint8_t* opx_dst, uint8_t* ipx_src, size_t ilength);
void copypx(uint8_t* opx_dst, uint8_t* ipx_src, size_t ilength);
int TestThread(void *ptr);
#endif // !MKZ_INIT_H_