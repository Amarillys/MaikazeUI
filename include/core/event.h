/**/

#ifndef MKZ_EVENT_H_
#define MKZ_EVENT_H_

#include "../sdl/SDL.h"

const int TYPE_NULL = -1;
const int TYPE_MOUSE = 0;
const int TYPE_KEYBOARD = 1;

const int MOUSE_MOVE = 1;
const int MOUSE_DOWN = 2;
const int MOUSE_UP = 3;
const int MOUSE_CLICK = 5;

const int KEY_DOWN = 6;
const int KEY_UP = 7;
const int KEY_CLICK = 13;

struct EVT
{
    int type;
    int x;
    int y;
    int value;
};

EVT evttf(SDL_Event* ievt);
#endif // !MKZ_EVENT_H_
