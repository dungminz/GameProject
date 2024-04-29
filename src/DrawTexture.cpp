
#include "../Header/DrawTexture.h"


SDL_Texture *DrawTexture::loadTexture(const std::string filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture *texture = IMG_LoadTexture(Game::renderer, filename.c_str());
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}

void DrawTexture::draw(SDL_Texture *texture) {
    SDL_RenderCopy(Game::renderer, texture, NULL, NULL);
}

void DrawTexture::draw(SDL_Texture *texture, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;

    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(Game::renderer, texture, NULL, &dest);
}

void DrawTexture::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
    SDL_RenderCopy(Game::renderer, texture, src, dest);
}