#include "include\demo\mainwin.h"
#include "include\core\process.h"
#include <fstream>

//window system
vector<Win*> winmgr;
int FindWin(int iid);
void DelWin(Win* iwin);

Theme DEFTHEME;
Cfg* cfg = new Cfg("maikaze.cfg");
void InitTheme();

float ZOOM = 1;
//Cursor system, defined at base.h
SDL_Cursor* MOUSE_HAND;
SDL_Cursor* MOUSE_BUSY;
SDL_Cursor* MOUSE_CROSSHAIR;
SDL_Cursor* MOUSE_NO;
SDL_Cursor* MOUSE_NORMAL;
SDL_Cursor* MOUSE_SIZE_ALL;
SDL_Cursor* MOUSE_SIZE_NESW;
SDL_Cursor* MOUSE_SIZE_NS;
SDL_Cursor* MOUSE_SIZE_NWSE;
SDL_Cursor* MOUSE_SIZE_WE;
SDL_Cursor* MOUSE_WAIT;

void InitCursor();
void QuitCursor();

//Config File system
LocaleFile* lang = new LocaleFile("locale.cfg");
void InitLanguage();

stdstr FONT = cfg->ReadString("Main", "Font");

Mainwin* mw;

int main(int argc, char * argv[])
{
    //init system start
    //Please ensure that this(Init(SDL_INIT_EVERYTHING)) is the first line.
    init(SDL_INIT_EVERYTHING);

    InitCursor();
    InitTheme();
    InitLanguage();

    mw = new Mainwin();
    winmgr.push_back(mw);
    //init system end
    //event system start
    SDL_Event evt;
    SDL_Thread *thread = SDL_CreateThread(TestThread, "TestThread", (void*)(mw->btn2));
    //SDL_DetachThread(thread);  /* will go away on its own upon completion. */

    while (true)
    {
        SDL_Delay(REFRESHTIME);

        if (SDL_PollEvent(&evt))
            winmgr[FindWin(evt.motion.windowID)]->EvtRec(evttf(&evt));

    }
    //event system end

    //clear system start
    for (Win* w : winmgr)
        DelWin(w);

    QuitCursor();
    SDL_Quit();
    delete cfg;
    //clear system end

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
    if (cfgtheme == "Hikari")
        DEFTHEME = Hikari;
}

void InitLanguage()
{
    lang->SetLocale(cfg->ReadString("Main", "Language"));
}

void InitCursor()
{
    MOUSE_BUSY = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_WAITARROW);
    MOUSE_CROSSHAIR = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
    MOUSE_HAND = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
    MOUSE_NORMAL = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    MOUSE_NO = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_NO);
    MOUSE_SIZE_WE = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEWE);
    MOUSE_SIZE_NS = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
    MOUSE_SIZE_ALL = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZEALL);
    MOUSE_SIZE_NESW = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENESW);
    MOUSE_SIZE_NWSE = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENWSE);
    MOUSE_WAIT = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_WAIT);
}

void QuitCursor()
{
     SDL_FreeCursor(MOUSE_BUSY);
     SDL_FreeCursor(MOUSE_CROSSHAIR);
     SDL_FreeCursor(MOUSE_NORMAL);
     SDL_FreeCursor(MOUSE_HAND);
     SDL_FreeCursor(MOUSE_NO);
     SDL_FreeCursor(MOUSE_SIZE_NS);
     SDL_FreeCursor(MOUSE_SIZE_WE);
     SDL_FreeCursor(MOUSE_SIZE_ALL);
     SDL_FreeCursor(MOUSE_SIZE_NESW);
     SDL_FreeCursor(MOUSE_SIZE_NWSE);
     SDL_FreeCursor(MOUSE_WAIT);
}