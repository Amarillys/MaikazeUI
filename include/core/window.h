/*

*/
#ifndef  MKZ_WIN_H_
#define MKZ_WIN_H_

#include "base.h"

class Win 
{
public:
    Win();
    Win(stdstr ititle);
    Win(stdstr ititle, int iw, int ih);
    Win(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags);
    //Win(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags, bool show);

    void Draw();
    void Show();
    void Hide();
    void SetTitle(stdstr ititle);

    ~Win();


private:
    SDL_Window* win;
    SDL_Renderer * ren;
    SDL_Surface* sur;

    stdstr title;
    int x, y, w, h;
    bool imgbg;
    Color bgcolor = Default;

    Uint32 flags;

    void Create(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags);

};


#endif // ! MKZ_WIN_H_