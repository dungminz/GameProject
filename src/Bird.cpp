#include <iostream>
#include "../Header/Bird.h"

Bird::Bird() {}

void Bird::update() {
    if(Game::currentKeyState[SDL_SCANCODE_UP]) std::cerr<<"UP\n";
    if(Game::currentKeyState[SDL_SCANCODE_DOWN]) std::cerr<<"DOWN\n";
    if(Game::currentKeyState[SDL_SCANCODE_LEFT]) std::cerr<<"LEFT\n";
    if(Game::currentKeyState[SDL_SCANCODE_RIGHT]) std::cerr<<"RIGHT\n";
}