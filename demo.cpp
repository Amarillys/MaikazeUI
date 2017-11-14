#include "include\core\config.h"
#include "include\core\theme.h"
#include "include\core\font.h"
#include "include\demo\mainwin.h"

//#include <locale>
//#include <codecvt>
#include <fstream>

extern FontSys fsys("c:/windows/fonts/FZYansum.ttf");

vector<Win*> winmgr;
int FindWin(int iid);
void DelWin(Win* iwin);

Theme DEFTHEME;
Cfg* cfg = new Cfg("maikaze.cfg");
void InitTheme();
//extern int Theme = ;

int main(int argc, char * argv[])
{
    
    init(SDL_INIT_EVERYTHING);
    InitTheme();
    Mainwin* mw = new Mainwin();
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

void InitTheme()
{
    cfg->SetRoot("Main");
    DEFTHEME.WinBg = { 0x28, 0x2d, 0x32 };
    DEFTHEME.BtnBg = { 0x30, 0x40, 0x45 };
    DEFTHEME.BtnBgSIn = { 0x33, 0x43, 0x48 };
    DEFTHEME.BtnBgSOut = { 0x36, 0x46, 0x4B };


}

/*std::wstring str = L"ABC,ÖÐÎÄ";

std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

std::string narrowStr = conv.to_bytes(str);
{
std::ofstream ofs("test.txt");
ofs << narrowStr;
}

std::wstring wideStr = conv.from_bytes(narrowStr);
{
std::locale::global(std::locale("Chinese-simplified"));
std::wofstream ofs(L"testW.txt");
ofs << wideStr;
}*/