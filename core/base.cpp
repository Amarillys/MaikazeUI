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



void FillCRectSimple(SDL_Surface* isur, Color irgb, Color ibg)
{
    Fill(isur, irgb);
    if (SDL_MUSTLOCK(isur))
        SDL_LockSurface(isur);

    //default RGB
    int r = 0;
    int g = 1;
    int b = 2;
    if (isur->format->format == SDL_PIXELFORMAT_BGR24)
    {
        r = 2;
        b = 0;
    }
    int addclr = ibg.r > irgb.r ? 1 : -1;
    Color Dark0 = ibg;
    Color Dark1 = Color{ static_cast<uint8_t>(ibg.r + addclr * 5),
        static_cast<uint8_t>(ibg.g + addclr * 5),
        static_cast<uint8_t>(ibg.b + addclr * 5) };
    Color Dark2 = Color{ static_cast<uint8_t>(ibg.r + addclr * 5),
        static_cast<uint8_t>(ibg.g + addclr * 5),
            static_cast<uint8_t>(ibg.b + addclr * 5) };
    Color Dark3 = Color{ static_cast<uint8_t>(irgb.r + addclr * 5),
        static_cast<uint8_t>(irgb.g + addclr * 5),
            static_cast<uint8_t>(irgb.b + addclr * 5) };
    
    int w = isur->w;
    int h = isur->h;
    if (isur->h < CircleDevide * 10)
    {
        ((uint8_t *)isur->pixels)[Fuck(1, 1, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(w, 1, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(1, h, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(w, h, w) + r] = Dark0.r;

        ((uint8_t *)isur->pixels)[Fuck(1, 1, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(w, 1, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(1, h, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(w, h, w) + g] = Dark0.g;
            
        ((uint8_t *)isur->pixels)[Fuck(1, 1, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(w, 1, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(1, h, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(w, h, w) + b] = Dark0.b;

        ((uint8_t *)isur->pixels)[Fuck(2, 1, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(w - 1, 1, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(1, 2, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(w, 2, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(1, h - 1, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(w, h - 1, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(2, h, w) + r] =
            ((uint8_t *)isur->pixels)[Fuck(w - 1, h, w) + r] = Dark1.r;

        ((uint8_t *)isur->pixels)[Fuck(2, 1, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(w - 1, 1, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(1, 2, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(w, 2, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(1, h - 1, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(w, h - 1, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(2, h, w) + g] =
            ((uint8_t *)isur->pixels)[Fuck(w - 1, h, w) + g] = Dark1.g;

        ((uint8_t *)isur->pixels)[Fuck(2, 1, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(w - 1, 1, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(1, 2, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(w, 2, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(1, h - 1, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(w, h - 1, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(2, h, w) + b] =
            ((uint8_t *)isur->pixels)[Fuck(w - 1, h, w) + b] = Dark1.b;
    }
    else
    {

    }


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
