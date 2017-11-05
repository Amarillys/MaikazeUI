/**/

#include "../include/core/font.h"

FontSys::FontSys(stdstr ifont)
{
    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    font = TTF_OpenFont(ifont.c_str(), 24);
    if (font == NULL)
    {
        fprintf(stderr, "font open failure %s\n", SDL_GetError());
        exit(-1);
    }
}

FontSys::~FontSys()
{
    TTF_CloseFont(font);
}

void FontSys::ShowFont(stdstr istring, int ix, int iy, SDL_Renderer* iren)
{
    SDL_Surface* fsur = TTF_RenderText_Blended(font, istring.c_str(), SDL_Color{ 0x80, 0xda, 0xd0, 0x00});
    Refresh(iren, fsur, SDL_Rect{ 0, 0, fsur->w, fsur->h }, SDL_Rect{ix, iy, fsur->w, fsur->h});
}

void FontSys::ShowFontAutoPos(stdstr istring, int ix, int iy, int iw, int ih, SDL_Renderer* iren)
{
    SDL_Surface* fsur = TTF_RenderText_Blended(font, istring.c_str(), SDL_Color{ 0x80, 0xda, 0xd0, 0x00 });
    Refresh(iren, fsur, SDL_Rect{ 0, 0, fsur->w, fsur->h }, SDL_Rect{ ix + (iw - fsur->w) / 2, iy + (ih - fsur->h) / 2, fsur->w, fsur->h });
}