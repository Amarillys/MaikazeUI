/**/

#include "../include/core/font.h"

extern stdstr FONT;

void ShowFontAutoPosCustom(stdstr ifont, int isize, const char * istr, int ix, int iy, int iw, int ih, SDL_Renderer * iren, SDL_Color iclr)
{
    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    TTF_Font* font = TTF_OpenFont(ifont.c_str(), isize);
    if (font == NULL)
    {
        fprintf(stderr, "font open failure %s\n", SDL_GetError());
        exit(-1);
    }
    SDL_Surface* fsur = TTF_RenderUTF8_Blended(font, istr, iclr);
    Refresh(iren, fsur, SDL_Rect{ 0, 0, fsur->w, fsur->h }, SDL_Rect{ to0(ix + (iw - fsur->w) / 2), to0(iy + (ih - fsur->h) / 2), fsur->w, fsur->h });
    SDL_FreeSurface(fsur);
    TTF_CloseFont(font);
}

void ShowFontCustom(stdstr ifont, int isize, const char * istr, int ix, int iy, SDL_Renderer * iren, SDL_Color iclr)
{
    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    TTF_Font* font = TTF_OpenFont(ifont.c_str(), isize);
    if (font == NULL)
    {
        fprintf(stderr, "font open failure %s\n", SDL_GetError());
        exit(-1);
    }
    SDL_Surface* fsur = TTF_RenderUTF8_Blended(font, istr, iclr);
    Refresh(iren, fsur, SDL_Rect{ 0, 0, fsur->w, fsur->h }, SDL_Rect{ ix, iy, fsur->w, fsur->h });
    SDL_FreeSurface(fsur);
    TTF_CloseFont(font);
}

void ShowFont(int isize, const char * istr, int ix, int iy, SDL_Renderer * iren, SDL_Color iclr)
{
    ShowFontCustom(FONT, isize, istr, ix, iy, iren, iclr);
}

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

void FontSys::ShowFont(const char* istr, int ix, int iy, SDL_Renderer* iren)
{
    SDL_Surface* fsur = TTF_RenderText_Blended(font, istr, SDL_Color{ 0x80, 0xda, 0xd0, 0x00});
    Refresh(iren, fsur, SDL_Rect{ 0, 0, fsur->w, fsur->h }, SDL_Rect{ix, iy, fsur->w, fsur->h});
}

void FontSys::ShowFontAutoPos(const char* istr, int ix, int iy, int iw, int ih, SDL_Renderer* iren, SDL_Color iclr)
{
    SDL_Surface* fsur = TTF_RenderUTF8_Blended(font, istr, iclr);
    Refresh(iren, fsur, SDL_Rect{ 0, 0, fsur->w, fsur->h }, SDL_Rect{ ix + (iw - fsur->w) / 2, iy + (ih - fsur->h) / 2, fsur->w, fsur->h });
}