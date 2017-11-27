/**/

#ifndef MKZ_FONT_H_
#define MKZ_FONT_H_

#include "base.h"
#include <fstream>

void ShowFontAutoPosCustom(stdstr ifont, int isize, const char* istr, int ix, int iy, int iw, int ih, SDL_Renderer * iren, SDL_Color iclr);

class FontSys
{
public:
    FontSys(stdstr ifont);
    void ShowFont(const char* istr, int ix, int iy, SDL_Renderer* iren);
    void ShowFontAutoPos(const char* istr, int ix, int iy, int iw, int ih, SDL_Renderer * iren, SDL_Color iclr);
    ~FontSys();

private:
    TTF_Font * font;
    int size;
};

#endif // !MKZ_FONT_H_
