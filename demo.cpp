#include "include\core\base.h"
#include "include\core\font.h"
#include "include\demo\mainwin.h"

extern FontSys fsys("consolas.ttf");

vector<Win*> winmgr;
int FindWin(int iid);
void DelWin(Win* iwin);

int main(int argc, char * argv[])
{
    init(SDL_INIT_EVERYTHING);

    Mainwin* mw = new Mainwin();
    winmgr.push_back(mw);

    Win* sw = new Win("Second Window", 640, 480, 100, 200, SDL_WINDOW_SHOWN);
    winmgr.push_back(sw);

    SDL_Event evt;

    while (true)
    {
        SDL_Delay(REFRESHTIME);

        if (SDL_PollEvent(&evt))
            winmgr[FindWin(evt.motion.windowID)]->EvtRec(evttf(&evt));
    }
    
    for (Win* w : winmgr)
        DelWin(w);
    SDL_Quit();
    return 0;
}

/*return -1 if failed to find the window*/
int FindWin(int iid)
{
    for (unsigned int i = 0; i < winmgr.size(); ++i)
        if (winmgr[i]->GetID() == iid)
            return i;
    return 0;
}

void DelWin(Win * iwin)
{
    for (auto it = winmgr.begin(); it != winmgr.end(); ++it)
        if ((*it)->GetID() == iwin->GetID())
        {
            winmgr.erase(it);
            return;
        }
}
