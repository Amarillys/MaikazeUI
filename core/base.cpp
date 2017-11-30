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
    SDL_Rect rect{ 0, 0, isur->w, isur->h };
    SDL_RenderCopy(iren, tex, &rect, &rect);
    SDL_RenderPresent(iren);
    SDL_DestroyTexture(tex);
}

void Refresh(SDL_Renderer* iren, SDL_Surface* isur, SDL_Rect& isrect, SDL_Rect& idrect)
{
    SDL_Texture * tex = SDL_CreateTextureFromSurface(iren, isur);
    SDL_RenderCopy(iren, tex, &isrect, &idrect);
    SDL_RenderPresent(iren);
    SDL_DestroyTexture(tex);
}

void Refresh(SDL_Renderer* iren, SDL_Texture* itex, SDL_Rect& isrect, SDL_Rect& idrect)
{
    SDL_RenderCopy(iren, itex, &isrect, &idrect);
    SDL_RenderPresent(iren);
}

int min(int ia, int ib)
{
    return ia > ib? ib: ia;
}

int max(int ia, int ib)
{
    return ia > ib ? ia : ib;
}

int abs(int ia)
{
    return ia > 0? ia: -ia;
}

Color Str2Clr(stdstr istr)
{
    int r, g, b, a;
    sscanf(istr.c_str(), "#%2x%2x%2x%2x;", &r, &g, &b, &a);
    return Color{ static_cast<uint8_t>(r), static_cast<uint8_t>(g),
        static_cast<uint8_t>(b), static_cast<uint8_t>(a) };
}

/*171130 Remove BGR24*/
void Fill(SDL_Surface * isur, Color irgb)
{
    if (SDL_MUSTLOCK(isur))
        SDL_LockSurface(isur);

    int pos = 0;
    for (int line = 0; line < isur->h; ++line)
        for (int i = 0; i < isur->w; ++i)
        {
            ((uint8_t *)isur->pixels)[pos + 0] = irgb.r;
            ((uint8_t *)isur->pixels)[pos + 1] = irgb.g;
            ((uint8_t *)isur->pixels)[pos + 2] = irgb.b;
            ((uint8_t *)isur->pixels)[pos + 3] = irgb.a;
            pos += 4;
        }

    if (SDL_MUSTLOCK(isur))
        SDL_UnlockSurface(isur);
}

void SetCursor(SDL_Cursor * icur)
{
    if (icur == nullptr)
    {
        //log
        return;
    }
    SDL_SetCursor(icur);
}

void copypx_r(uint8_t * opx_dst, uint8_t * ipx_src, size_t ilength)
{
    for (size_t i = 0; i < ilength; ++i)
        for (int c = 0; c < 4; ++c)
            opx_dst[(ilength - i - 1) * 4 + 3] = ipx_src[i * 4 + 3];
}

void copypx(uint8_t * opx_dst, uint8_t * ipx_src, size_t ilength)
{
    for (size_t i = 0; i < ilength; ++i)
        for (int c = 0; c < 4; ++c)
            opx_dst[i * 4 + 3] = ipx_src[i * 4 + 3];
}


/*171128 Rewrite CircleRect Filling Algorithm
/*Now only support RGBA32*/
void FillCRectSimple(SDL_Surface* isur, Color irgb, int ir)
{
    Fill(isur, irgb);
    if (ir == 0)
        return;

    if (SDL_MUSTLOCK(isur))
        SDL_LockSurface(isur);
    int w = isur->w;
    int h = isur->h;
    if (ir != 2 || 3 || 4 || 5 || 10)
    {
        //base on 10 x 10 alpla bitmap.
        double span = 10.01 / ir;
        for (int iy = 0; iy < ir; ++iy)
            for (int ix = 0; ix < ir; ++ix)
                ((uint8_t*)isur->pixels)[(iy * w + ix) * 4 + 3] = 
                    CR[4][static_cast<int>(span * (iy + 0.5))][static_cast<int>(span * (ix + 0.5))];
    }
    else
    {
        int cr = ir - 2;
        if (ir == 10)
            cr = 4;
        //for (int i = 0; i < isur->w * isur->h * 4; i++)
        //default: four angle is same.    
        for (int iy = 0; iy < ir; iy++)
            for (int ix = 0; ix < ir; ix++)
                ((uint8_t*)isur->pixels)[(iy * w + ix) * 4 + 3] = CR[cr][iy][ix];
    }
        //Part2
        for (int iy = 0; iy < ir; ++iy)
            copypx_r(&(((uint8_t*)isur->pixels)[((iy + 1) * w - ir) * 4]), &(((uint8_t*)isur->pixels)[iy * w * 4]), ir);
        //Part3
        for (int iy = h - 1; iy > h - ir; --iy)
            copypx(&(((uint8_t*)isur->pixels)[iy * w * 4]), &(((uint8_t*)isur->pixels)[(h - iy - 1) * w * 4]), ir);
        //Part4
        for (int iy = h - 1; iy > h - ir; --iy)
            copypx(&(((uint8_t*)isur->pixels)[((iy + 1) * w - ir) * 4]), &(((uint8_t*)isur->pixels)[((h - iy) * w - ir) * 4]), ir);

    if (SDL_MUSTLOCK(isur))
        SDL_UnlockSurface(isur);
}

int TestThread(void *ptr)
{
    return 56;
}
