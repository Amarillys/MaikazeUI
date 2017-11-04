#include "../include/core/init.h"

void init(u32 flags)
{
    if (SDL_Init(flags) < 0) {
        printf("SDL initialize fail:%s\n", SDL_GetError());
        exit(-1);
    }
}
