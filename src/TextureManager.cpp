#include "../Header/TextureManager.h"
#include "../Header/CommonFunction.h"

SDL_Texture *TextureManager::loadTexture(const std::string filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture *texture = IMG_LoadTexture(Game::renderer, filename.c_str());
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}

void TextureManager::draw(SDL_Texture *texture) {
    SDL_RenderCopy(Game::renderer, texture, NULL, NULL);
}

void TextureManager::draw(SDL_Texture *texture, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = SCREEN_WIDTH;
    dest.h = SCREEN_HEIGHT;

    // SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(Game::renderer, texture, NULL, &dest);
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect *src, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.h = src->h;
    dest.w = src->w;

    SDL_RenderCopy(Game::renderer, texture, src, &dest);
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
    SDL_RenderCopy(Game::renderer, texture, src, dest);
}