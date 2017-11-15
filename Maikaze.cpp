#include "include\core\locale.h"
#include "include\core\theme.h"
#include "include\core\font.h"
#include "include\demo\mainwin.h"

#include <fstream>

vector<Win*> winmgr;
int FindWin(int iid);
void DelWin(Win* iwin);

Theme DEFTHEME;
Cfg* cfg = new Cfg("maikaze.cfg");
void InitTheme();

LocaleFile* lang = new LocaleFile("locale.cfg");
void InitLanguage();
extern FontSys fsys(cfg->ReadString("Main", "Font"));

Mainwin* mw;

int main(int argc, char * argv[])
{
    
    init(SDL_INIT_EVERYTHING);
    InitTheme();
    InitLanguage();
    mw = new Mainwin();
    winmgr.push_back(mw);

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
    delete cfg;
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

/*Read the theme settings from config file.*/
void InitTheme()
{
    stdstr cfgtheme = cfg->ReadString("Main", "Theme");
    
    if (cfgtheme == "Dark")
        DEFTHEME = DK;

    //white, custom to do
}

void InitLanguage()
{
    lang->SetLocale(cfg->ReadString("Main", "Language"));
}
