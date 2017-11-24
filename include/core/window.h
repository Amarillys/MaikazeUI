/*

*/
#ifndef  MKZ_WIN_H_
#define MKZ_WIN_H_

#include "object.h"
#include "event.h"

#include <vector>
using std::vector;

class Win 
{
public:
    Win();
    Win(stdstr ititle);
    Win(stdstr ititle, int iw, int ih);
    Win(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags);
    //Win(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags, bool show);

    void Add(Object* iobj);
    SDL_Renderer * GetRen();
    void Draw();
    void Show();
    void Hide();
    void EvtRec(EVT ievt);
    void ReDraw();
    void SetLogicSize(int iw, int ih);
    SDL_Window* Win::GetWin();
    void SetTitle(stdstr ititle);
    Color GetBgColor();
    int GetID();
    int LocaleObj(int ix, int iy);
    ~Win();


protected:
    SDL_Window* win;
    SDL_Renderer * ren;
    SDL_Surface* sur;
    
    //the status for the focus object.
    int newobj, curobj, lastobj;
    Object* winobj;

    int id;
    stdstr title;
    int x, y, w, h;
    bool imgbg;
    Color bgcolor;
    vector<Object*> objmgr;
    Uint32 flags;

    void Create(stdstr ititle, int iw, int ih, int ix, int iy, u32 iflags);

};


#endif // ! MKZ_WIN_H_