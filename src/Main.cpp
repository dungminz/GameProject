#include <iostream>

#include "../Header/Game.h"
#include "../Header/CommonFunction.h"
#include "../Header/AnimationManager.h"
#include "../Header/Enemy.h"
#include "../Header/Bird.h"


Game game;

// static Animation eggbird_ani, diamond_ani, evilbird_ani;

void init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    Game::window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //full screen
    //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (Game::window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit( "SDL_image error:", IMG_GetError());

    Game::renderer = SDL_CreateRenderer(Game::window, -1, SDL_RENDERER_ACCELERATED |
                                            SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (Game::renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(Game::renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

Animation* setEggBird() {
    Animation* eggbird_ani = new Animation;
    eggbird_ani->setInformation(EGGBIRD, EGGBIRD_IMG, FLAMES_EGGBIRD, 
                CLIPS_EGGBIRD, EGGBIRD_REAL_W, EGGBIRD_REAL_H);
    return eggbird_ani;
}

Animation* setDiamond() {
    Animation* diamond_ani = new Animation;
    diamond_ani->setInformation(DIAMOND, DIAMOND_IMG, 
            FLAMES_DIAMOND, DIAMOND_REAL_W, DIAMOND_REAL_H);
    return diamond_ani;
}

Animation* setDiamondCollapsion() {
    Animation* diamond_colappsion_ani = new Animation;
    diamond_colappsion_ani->setInformation(DIAMONDCOLLAPSION, DIAMONDCOLLAPSION_IMG, 
            FLAMES_DIAMONDCOLLAPSION, DIAMONDCOLLAPSION_REAL_W, DIAMONDCOLLAPSION_REAL_H);
    return diamond_colappsion_ani;
}

Animation* setEvilBird() {
    Animation* evilbird_ani = new Animation;
    evilbird_ani->setInformation(EVILBIRD, EVILBIRD_IMG, 
            FLAMES_EVILBIRD, EVILBIRD_REAL_W, EVILBIRD_REAL_H);
    return evilbird_ani;
}

void clean() {
    SDL_DestroyRenderer(game.renderer); game.renderer = nullptr;
    SDL_DestroyWindow(game.window); game.window = nullptr;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    srand(time(0));
    init();
    
    game.init(setEggBird(), nullptr, setDiamond(), setEvilBird());
    while(game.running()) {
        game.handle_events();
        game.update();
        game.render();
        // waitUntilKeyPressed();
        SDL_Delay(10);
    }
    game.clean();
    clean();
    
    return 0;
}