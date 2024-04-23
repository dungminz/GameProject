#include "../Header/Background.h"
#include "../header/TextureManager.h"

void Background::init() {
    texture = TextureManager::loadTexture("bg2.png");
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Background::scroll(int distance) {
    scrollingOffset-=distance;
    if(scrollingOffset<0) scrollingOffset = width;
}

void Background::render() {
    scroll(INITIAL_DISTANCE);
    TextureManager::draw(texture, scrollingOffset, 0);
    TextureManager::draw(texture, scrollingOffset-width, 0);
}