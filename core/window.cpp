/*

*/

#include "../include/core/window.h"
#include "../include/core/theme.h"

extern Theme DEFTHEME;
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
    w = to0(iw);
    h = to0(ih);
    x = to0(ix);
    y = to0(iy);
    bgcolor = DEFTHEME.WinBg;
    win = SDL_CreateWindow(ititle.c_str(), ix, iy, iw, ih, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, 0);
    sur = SDL_CreateRGBSurface(0, w, h, 24, 0, 0, 0, 0);
    id = SDL_GetWindowID(win);

    //set the window as the base object
    winobj = new Object();
    winobj->x = ix;
    winobj->y = iy;
    winobj->w = iw;
    winobj->h = ih;
    objmgr.push_back(winobj);

    lastobj = 0;
    Draw();
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

void Win::EvtRec(EVT ievt)
{

    switch (ievt.type)
    {
    case MOUSE_MOVE:
        newobj = LocaleObj(ievt.x, ievt.y);
        printf("Rec command: Mouse moves at x:%d y:%d - on Window %d at object: %d\n", ievt.x, ievt.y, id, newobj);
        //judge newobj
        if (newobj != lastobj)
        {
            objmgr[newobj]->Suspend();
            objmgr[lastobj]->Left();
        }
        lastobj = newobj;

        break;
    case KEY_DOWN:
        printf("Rec command: key:%c - on Window %d\n", ievt.value, id);

        break;

    case MOUSE_UP:
        objmgr[newobj]->Click();
        break;

    default:
        break;
    }

}

SDL_Window* Win::GetWin()
{
    return win;
}

void Win::Add(Object* iobj)
{
    objmgr.push_back(iobj);
}

SDL_Renderer* Win::GetRen()
{
    return ren;
}

void Win::Draw()
{
    Fill(sur, bgcolor);
    Refresh(ren, sur, SDL_Rect{ 0, 0, w, h }, SDL_Rect{ 0, 0, w, h });
}

void Win::SetTitle(stdstr ititle)
{
    SDL_SetWindowTitle(win, ititle.c_str());
}

Color Win::GetBgColor()
{
    return bgcolor;
}

int Win::GetID()
{
    return id;
}

int Win::LocaleObj(int ix, int iy)
{
    for (unsigned int i = 1; i < objmgr.size(); ++i)
    {
        if (ix >= objmgr[i]->x
            && iy >= objmgr[i]->y
            && ix <= objmgr[i]->x + objmgr[i]->w
            && iy <= objmgr[i]->y + objmgr[i]->h)
            return i;
    }
    //not found, locale at the father window
    return 0;
}

