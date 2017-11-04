/*

*/
#ifndef  MKZ_WIN_H_
#define MKZ_WIN_H_

#include "init.h"

class Win 
{
public:
    Win();
    Win(stdstr ititle);
    Win(stdstr ititle, int iw, int ih);
    Win(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags);

    void Show();
    void Hide();
    void SetTitle(stdstr ititle);

    ~Win();

private:
    SDL_Window* win;

    stdstr title;
    int x, y, w, h;
    Uint32 flags;

    void Create(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags);

};


#endif // ! MKZ_WIN_H_