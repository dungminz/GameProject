#include "../Header/Background.h"
#include "../header/DrawTexture.h"

void Background::init() {
    texture = DrawTexture::loadTexture("bg2.png");
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Background::scroll(int distance) {
    scrollingOffset-=distance;
    if(scrollingOffset<0) scrollingOffset = width;
}

void Background::update() {
    scroll(INITIAL_DISTANCE);
}

void Background::render() {
    DrawTexture::draw(texture, scrollingOffset, 0);
    DrawTexture::draw(texture, scrollingOffset-width, 0);
}