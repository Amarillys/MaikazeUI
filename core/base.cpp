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

void Fill(SDL_Surface * isur, Color irgb)
{
    if (SDL_MUSTLOCK(isur))
        SDL_LockSurface(isur);

    int pos = 0;

    //default RGB
    int r = 0;
    int g = 1;
    int b = 2;
    int a = 3;
    switch (isur->format->format)
    {
    case SDL_PIXELFORMAT_BGR24:
        r = 2;
        b = 0;
        for (int line = 0; line < isur->h; ++line)
        {
            for (int i = 0; i < isur->w; ++i)
            {
                ((uint8_t *)isur->pixels)[pos + r] = irgb.r;
                ((uint8_t *)isur->pixels)[pos + g] = irgb.g;
                ((uint8_t *)isur->pixels)[pos + b] = irgb.b;
                pos += 3;
            }
            //magic sdl
            pos += isur->w % 4;
        }
        break;
    
    case SDL_PIXELFORMAT_RGBA32:
        for (int line = 0; line < isur->h; ++line)
        {
            for (int i = 0; i < isur->w; ++i)
            {
                ((uint8_t *)isur->pixels)[pos + r] = irgb.r;
                ((uint8_t *)isur->pixels)[pos + g] = irgb.g;
                ((uint8_t *)isur->pixels)[pos + b] = irgb.b;
                ((uint8_t *)isur->pixels)[pos + a] = irgb.a;
                pos += 4;
            }
        }
        break;

    default:
        //
        break;
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
        {/*
            opx_dst[(ilength - i - 1) * 4 + 0] = ipx_src[i * 4 + 0];
            opx_dst[(ilength - i - 1) * 4 + 1] = ipx_src[i * 4 + 1];
            opx_dst[(ilength - i - 1) * 4 + 2] = ipx_src[i * 4 + 2];*/
            opx_dst[(ilength - i - 1) * 4 + 3] = ipx_src[i * 4 + 3];
        }
}

void copypx(uint8_t * opx_dst, uint8_t * ipx_src, size_t ilength)
{
    for (size_t i = 0; i < ilength; ++i)
        for (int c = 0; c < 4; ++c)
        {/*
         opx_dst[(ilength - i - 1) * 4 + 0] = ipx_src[i * 4 + 0];
         opx_dst[(ilength - i - 1) * 4 + 1] = ipx_src[i * 4 + 1];
         opx_dst[(ilength - i - 1) * 4 + 2] = ipx_src[i * 4 + 2];*/
            opx_dst[i * 4 + 3] = ipx_src[i * 4 + 3];
        }
}


/*171128 Rewrite CircleRect Filling Algorithm
/*Now only support RGBA32*/
void FillCRectSimple(SDL_Surface* isur, Color irgb, Color ibg, int ir)
{
    Fill(isur, irgb);
    if (SDL_MUSTLOCK(isur))
        SDL_LockSurface(isur);
    int w = isur->w;
    int h = isur->h;
    //for (int i = 0; i < isur->w * isur->h * 4; i++)
    //default: fout angle is same.
    if (ir == 2 || 3 || 4 || 5 || 10)
    {
        switch (ir)
        {
        case 2:
            for (int iy = 0; iy < ir; iy++)
                for (int ix = 0; ix < ir; ix++)
                {
                    ((uint8_t*)isur->pixels)[(iy * w + ix) * 4 + 3] = CR2[iy][ix];
                }
            break;
        case 3:
            for (int iy = 0; iy < ir; iy++)
                for (int ix = 0; ix < ir; ix++)
                {
                    ((uint8_t*)isur->pixels)[(iy * w + ix) * 4 + 3] = CR3[iy][ix];
                }
            break;
        case 4:
            for (int iy = 0; iy < ir; iy++)
                for (int ix = 0; ix < ir; ix++)
                {
                    ((uint8_t*)isur->pixels)[(iy * w + ix) * 4 + 3] = CR4[iy][ix];
                }
            break;
        case 5:
            for (int iy = 0; iy < ir; iy++)
                for (int ix = 0; ix < ir; ix++)
                {
                    ((uint8_t*)isur->pixels)[(iy * w + ix) * 4 + 3] = CR5[iy][ix];
                }
            break;
        case 10:
            for (int iy = 0; iy < ir; iy++)
                for (int ix = 0; ix < ir; ix++)
                {
                    ((uint8_t*)isur->pixels)[(iy * w + ix) * 4 + 3] = CR10[iy][ix];
                }
            break;
        default:
            break;
        }
    }
    else
    {

    }
    //Part2
    for (int iy = 0; iy < ir; ++iy)
        copypx_r(&(((uint8_t*)isur->pixels)[((iy + 1) * w - ir) * 4]), &(((uint8_t*)isur->pixels)[iy * w * 4]), ir);
    //Part3
    for (int iy = h - 1; iy > h - ir; --iy)
        copypx(&(((uint8_t*)isur->pixels)[iy * w  * 4]), &(((uint8_t*)isur->pixels)[(h - iy - 1) * w * 4]), ir);
    //Part4
    for (int iy = h - 1; iy > h - ir; --iy)
        copypx(&(((uint8_t*)isur->pixels)[((iy + 1) * w - ir) * 4]), &(((uint8_t*)isur->pixels)[((h - iy) * w - ir)* 4]), ir);
    //((uint8_t*)isur->pixels)[w * 4 * 2 + 3] = 50;



    if (SDL_MUSTLOCK(isur))
        SDL_UnlockSurface(isur);
}

int TestThread(void *ptr)
{
    int cnt;

    for (cnt = 0; cnt < 10; ++cnt) {
        printf("\nThread counter: %d", cnt);
        SDL_Delay(500);
    }

    return cnt;
}
