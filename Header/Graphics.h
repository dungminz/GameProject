#pragma once

#include "Game.h"

const std::string MUSIC_THEME = "../Audio/9.ogg";
// const std::string MUSIC_THEME = "../Audio/Running Away - John Charles Fiddy.mp3";
const std::string SOUND_PICK = "../Audio/lost.wav";


struct TextureManager {
            
    static SDL_Texture *loadTexture(const std::string filename);

    static void draw(SDL_Texture *texture);
    static void drawBackground(SDL_Texture *texture, int x, int y);
    static void draw(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    static void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);
    static void drawCollaption(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);
    static void drawAngle(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest, double angle);
    static void drawIcon(SDL_Texture *texture, int x, int y);
    static void drawIcon(SDL_Texture *texture, int x, int y, int w, int h);

    static SDL_Texture* loadTexture(const std::string filename, 
                        TTF_Font* font, SDL_Color textColor);
    static void drawText(SDL_Texture *texture, int x, int y);
    static void drawText(const std::string filename, TTF_Font* font, SDL_Color textColor, int x, int y);
};


struct Music {

    Mix_Music *music;

    Music();
    Music(const std::string filename);
    ~Music();

    void play();
    void pause();
    void stop();
};

struct Sound {

    Mix_Chunk* chunk;

    Sound();
    Sound(const std::string file);
    ~Sound() ;

    void play();
};