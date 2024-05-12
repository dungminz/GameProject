#include "../Header/Graphics.h"
#include "../Header/CommonFunction.h"


SDL_Texture *TextureManager::loadTexture(const std::string filename)
{

    // SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename.c_str());

    SDL_Texture *texture = IMG_LoadTexture(Game::renderer, filename.c_str());
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}


void TextureManager::draw(SDL_Texture *texture) {

    SDL_RenderCopy(Game::renderer, texture, NULL, NULL);
}


void TextureManager::drawBackground(SDL_Texture *texture, int x, int y) {

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = SCREEN_WIDTH;
    dest.h = SCREEN_HEIGHT;

    SDL_RenderCopy(Game::renderer, texture, NULL, &dest);
}


void TextureManager::draw(SDL_Texture *texture, SDL_Rect *src, int x, int y) {

    SDL_Rect dest;
    dest.h = src->h;
    dest.w = src->w;
    dest.x = x-dest.w/2;
    dest.y = y-dest.h/2;

    SDL_RenderCopy(Game::renderer, texture, src, &dest);
}


void TextureManager::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
    
    // SDL_Rect* dest_(dest);
    // dest->x-=dest->w/2;
    // dest->y-=dest->h/2;

    SDL_RenderCopy(Game::renderer, texture, src, dest);
}


void TextureManager::drawCollaption(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
    
    SDL_Rect* dest_(dest);
    dest->x-=dest->w/2;
    dest->y-=dest->h/2;

    SDL_RenderCopy(Game::renderer, texture, src, dest_);
}


void TextureManager::drawAngle(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest, double angle) {
    
    SDL_RenderCopyEx(Game::renderer, texture, src, dest, angle, nullptr, SDL_FLIP_NONE);
}


void TextureManager::drawIcon(SDL_Texture *texture, int x, int y) {

    SDL_Rect dest;
    dest.x = x-ICON_SIZE/2;
    dest.y = y-ICON_SIZE/2;
    dest.h = ICON_SIZE;
    dest.w = ICON_SIZE;

    SDL_RenderCopy(Game::renderer, texture, NULL, &dest);  
}


void TextureManager::drawIcon(SDL_Texture *texture, int x, int y, int w, int h) {

    SDL_Rect dest;
    dest.w = w;
    dest.h = h;
    dest.x = x-w/2;
    dest.y = y-h/2;

    SDL_RenderCopy(Game::renderer, texture, NULL, &dest);
}



SDL_Texture* TextureManager::loadTexture(const std::string filename, 
                        TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* textSurface = 
            TTF_RenderText_Solid( font, filename.c_str(), textColor );
    if( textSurface == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                        SDL_LOG_PRIORITY_ERROR, 
                        "Render text surface %s", TTF_GetError());
        return nullptr;
    }

    // SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename.c_str());

    SDL_Texture* texture = 
            SDL_CreateTextureFromSurface(Game::renderer, textSurface );
    if( texture == nullptr ) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, 
                        SDL_LOG_PRIORITY_ERROR, 
                        "Create texture from text %s", SDL_GetError());
    }
    SDL_FreeSurface( textSurface );
    return texture;
}


void TextureManager::drawText(SDL_Texture *texture, int x, int y) {
    
    SDL_Rect dest;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    dest.x = x-dest.w/2;
    dest.y = y-dest.h/2;

    SDL_RenderCopy(Game::renderer, texture, NULL, &dest);  
}

void TextureManager::drawText(const std::string filename, TTF_Font* font, SDL_Color textColor, int x, int y) {
    SDL_Texture* _text = loadTexture(filename, font, textColor);
    drawText(_text, x, y);
    SDL_DestroyTexture(_text);
}



Music::Music() {}

Music::Music(const std::string filename) {

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename.c_str());

    music = Mix_LoadMUS(filename.c_str());

    if (music == nullptr) {

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
            "Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
}

Music::~Music() {

    if(music) Mix_FreeMusic(music);
}

void Music::setMusic(int num) {

    free();

    int rand_music = rand()%9;
    if(num == -1)
        music = Mix_LoadMUS(MUSIC_THEME_ORIGIN.c_str());
    else if(num>0)
        music = Mix_LoadMUS(MUSICS_THEME[num-1].c_str());
    else 
        music = Mix_LoadMUS(MUSICS_THEME[rand_music].c_str());
        
    if (music == nullptr) 
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
            "Could not load music! SDL_mixer Error: %s", Mix_GetError());

}

void Music::play() {

    if (Mix_PlayingMusic() == 0) 
        Mix_PlayMusic(music, -1);
    else if( Mix_PausedMusic() == 1 )
        Mix_ResumeMusic();
}

void Music::reset(int num) {

    if (Mix_PausedMusic()) {
        // Mix_RewindMusic();
        setMusic(num);
        Mix_PlayMusic(music, -1);
        pause();     
    }
    else {
        // Mix_RewindMusic();
        setMusic(num);
        Mix_PlayMusic(music, -1);
    }
}

void Music::pause() {

    if (Mix_PlayingMusic())
        Mix_PauseMusic();
}

void Music::resume() {

    if(Mix_PausedMusic())
        Mix_ResumeMusic();
}

void Music::stop() {
    
    pause();
    Mix_RewindMusic();
}

void Music::free() {
    if(music) Mix_FreeMusic(music);
}



Sound::Sound() {}

Sound::Sound(const std::string filename) {

    chunk = Mix_LoadWAV(filename.c_str());

    if (chunk == nullptr) {

        logErrorAndExit("Could not load sound! SDL_mixer Error: ", 
                        Mix_GetError());
    }
}

Sound::~Sound() {

    if(chunk) Mix_FreeChunk(chunk);
}


void Sound::play() {

    if(chunk) Mix_PlayChannel( -1, chunk, 0 );
}