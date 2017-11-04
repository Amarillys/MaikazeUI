#include "../include/core/base.h"

void init(u32 flags)
{
    if (SDL_Init(flags) < 0) {
        printf("SDL initialize fail:%s\n", SDL_GetError());
        exit(-1);
    }
}


void Refresh(SDL_Renderer * iren, SDL_Surface * isur)
{
    SDL_Texture * tex = SDL_CreateTextureFromSurface(iren, isur);
    SDL_RenderCopy(iren, tex, 0, 0);
    SDL_RenderPresent(iren);
}

void Fill(SDL_Surface * isur, Color irgb)
{
    SDL_LockSurface(isur);
    for (int i = 0; i < isur->w * isur->h * 3; )
    {
        ((uint8_t *)isur->pixels)[i++] = irgb.r;
        ((uint8_t *)isur->pixels)[i++] = irgb.g;
        ((uint8_t *)isur->pixels)[i++] = irgb.b;
    }
    SDL_UnlockSurface(isur);
}