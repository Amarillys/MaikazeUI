#include "include\core\init.h"
#include "include\core\window.h"

int main(int argc, char * argv[])
{
    init(SDL_INIT_EVERYTHING);

    Win* mw = new Win("Hello MaikazeUI!", 640, 480);
    mw->SetTitle("fuck");


    getchar();
    SDL_Quit();
    return 0;
}