/**/

#ifndef MKZ_EVENT_H_
#define MKZ_EVENT_H_

#include "../sdl/SDL.h"

const int TYPE_NULL = -1;
const int TYPE_MOUSE = 0;
const int TYPE_KEYBOARD = 1;

const int MOUSE_MOVE = 1;
const int MOUSE_LDOWN = 2;
const int MOUSE_LUP = 4;
const int MOUSE_LCLICK = 7;

const int KEY_DOWN = 12;
const int KEY_UP = 20;
const int KEY_CLICK = 33;

const int MOUSE_RDOWN = 54;
const int MOUSE_RUP = 88;
const int MOUSE_RCLICK = 143;

struct EVT
{
    int type;
    int x;
    int y;
    int value;
};

EVT evttf(SDL_Event* ievt);
#endif // !MKZ_EVENT_H_
