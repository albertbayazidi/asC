#include <sdl_utils.h>

bool init() {
    bool success = SDL_Init(SDL_INIT_VIDEO);
    if (!success) {
        SDL_Log("Initialization failed! Cuz: %s\n", SDL_GetError());
    }
    return success;
}
