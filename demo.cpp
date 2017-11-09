#include "include\core\base.h"
#include "include\core\font.h"
#include "include\core\window.h"
#include "include\core\button.h"

#include <vector>

using std::vector;
extern FontSys fsys("consolas.ttf");

vector<Win*> winmgr;
int FindWin(int iid);
void DelWin(Win* iwin);

int main(int argc, char * argv[])
{
    init(SDL_INIT_EVERYTHING);

    Win* mw = new Win("Hello MaikazeUI!", 640, 480);
    printf("id:%d\n", SDL_GetWindowID(mw->GetWin()));
    winmgr.push_back(mw);

    Win* sw = new Win("Second Window", 640, 480, 100, 200, SDL_WINDOW_SHOWN);
    Object* btn = new Button(mw, 128, 128, 160, 50);
    winmgr.push_back(sw);

    SDL_Event evt;

    while (true)
    {
        SDL_Delay(REFRESHTIME);

        if (SDL_PollEvent(&evt))
            if (evt.type == SDL_MOUSEMOTION)
                winmgr[FindWin(evt.motion.windowID)]->EvtRec(evttf(&evt));
    }
    
    getchar();
    for (Win* w : winmgr)
        delete w;
    SDL_Quit();
    return 0;
}

/*return -1 if failed to find the window*/
int FindWin(int iid)
{
    int id;
    for (int i = 0; i < winmgr.size(); ++i)
        if (winmgr[i]->GetID() == iid)
            return i;
    return -1;
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
