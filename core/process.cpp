#include "../include/core/process.h"
#include "../include/core/button.h"

int TestThread(void* btn)
{
    u32 time_start = SDL_GetTicks();
    u32 time_interval = time_start;
    u32 time_last = time_start;
    Button* text = (Button*)btn;
    while (true)
    {
        time_interval = SDL_GetTicks() - time_last;
        if (time_interval > 1000)
        {
            time_last = SDL_GetTicks();
            char t_str[10] = { 0 };
            sprintf(t_str, "%d", SDL_GetTicks() - time_start);
            text->showtext = stdstr(t_str);
            text->Draw();
        }
    }
    return 0;
}
