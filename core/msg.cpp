/*

*/

#include "../include/core/window.h"

Win::Win()
{
    Create("Maikaze", 640, 480, SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
}

Win::Win(stdstr ititle)
{
    Create(ititle, 640, 480, SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
}

Win::Win(stdstr ititle, int iw, int ih)
{
    Create(ititle, iw, ih, SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
}

Win::Win(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags)
{
    Create(ititle, iw, ih, ix, iy, iflags);
}

void Win::Create(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags)
{
    to0(iw);
    to0(ih);
    to0(ix);
    to0(iy);

    win = SDL_CreateWindow(ititle.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        iw, ih, SDL_WINDOW_SHOWN);

    printf("Window %s Created.", SDL_GetWindowTitle(win));

}


Win::~Win()
{
    printf("Window %s unconsturcted.", SDL_GetWindowTitle(win));
    SDL_DestroyWindow(win);
}

void Win::Show()
{
    SDL_ShowWindow(win);
}

void Win::Hide()
{
    SDL_HideWindow(win);
}

void Win::SetTitle(stdstr ititle)
{
    SDL_SetWindowTitle(win, ititle.c_str());
}