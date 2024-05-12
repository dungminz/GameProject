#pragma once

#include "Game.h"

const std::string MUSIC_THEME_ORIGIN = "../Audio/origin.ogg";
const std::string MUSICS_THEME[9] = {
    "../Audio/1.ogg",
    "../Audio/2.ogg",
    "../Audio/3.ogg",
    "../Audio/4.ogg",
    "../Audio/5.ogg",
    "../Audio/6.ogg",
    "../Audio/7.ogg",
    "../Audio/8.ogg",
    "../Audio/9.ogg",
};
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

    void setMusic(int num = 0);
    void play();
    void reset(int num = 0);
    void pause();
    void resume();
    void stop();
    void free();
};

struct Sound {

    Mix_Chunk* chunk;

    Sound();
    Sound(const std::string file);
    ~Sound() ;

    void play();
};