#include "..\include\core\event.h"

EVT evttf(SDL_Event * ievt)
{
    EVT ret;
    switch (ievt->type)
    {
    case SDL_MOUSEMOTION:
        ret.type = MOUSE_MOVE;
        ret.x = ievt->motion.x;
        ret.y = ievt->motion.y;
        break;

    case SDL_KEYDOWN:
        ret.x = ievt->motion.x;
        ret.y = ievt->motion.y;
        ret.type = KEY_DOWN;
        ret.value = ievt->key.keysym.sym;
        break;

    case SDL_MOUSEBUTTONDOWN:
        ret.type = MOUSE_LDOWN;
        break;

    case SDL_MOUSEBUTTONUP:
        ret.type = MOUSE_LUP;
        break;

    default:
        ret.type = TYPE_NULL;
        break;
    }
    return ret;
}
