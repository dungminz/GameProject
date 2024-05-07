#include <iostream>

#include "../Header/Game.h"
#include "../Header/Screen.h"
#include "../Header/CommonFunction.h"
#include "../Header/BackgroundManager.h"
#include "../Header/AnimationManager.h"
#include "../Header/Background.h"
#include "../Header/Enemy.h"
#include "../Header/Bird.h"


Game* game = nullptr;
Menu* menu = nullptr;


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



BackgroundManager* setDay() {

    BackgroundManager* day_ani = new BackgroundManager;

    day_ani->setInformation(DAY, DAY_BG, 
                        FLAMES_LAYER_DAY, DAY_LAYER);
    
    return day_ani;
}

BackgroundManager* setNight() {

    BackgroundManager* night_ani = new BackgroundManager;

    night_ani->setInformation(NIGHT, NIGHT_BG, 
                        FLAMES_LAYER_NIGHT, NIGHT_LAYER);
    
    return night_ani;
}

Animation* setEggBird() {

    Animation* eggbird_ani = new Animation;

    eggbird_ani->setInformation(EGGBIRD, EGGBIRD_IMG, FLAMES_EGGBIRD, 
                CLIPS_EGGBIRD, EGGBIRD_REAL_W, EGGBIRD_REAL_H);
    
    return eggbird_ani;
}

Animation* setEagleFlying() {

    Animation* eagleflying_ani = new Animation;

    eagleflying_ani->setInformation(EAGLEFLYING, EAGLE_IMG, FLAMES_EAGLE_FLYING, 
                CLIPS_EAGLE_FLYING, EAGLE_REAL_W, EAGLE_REAL_H);
    
    return eagleflying_ani;
}

Animation* setEagleGotHit() {

    Animation* eaglegothit_ani = new Animation;

    eaglegothit_ani->setInformation(EAGLEGOTHIT, EAGLE_IMG, FLAMES_EAGLE_GOT_HIT, 
                CLIPS_EAGLE_GOT_HIT, EAGLE_REAL_W, EAGLE_REAL_H);
    
    return eaglegothit_ani;
}

Animation* setEagleShot() {

    Animation* eagleshot_ani = new Animation;

    eagleshot_ani->setInformation(EAGLESHOT, EAGLE_IMG, FLAMES_EAGLE_SHOT, 
                CLIPS_EAGLE_SHOT, EAGLE_REAL_W, EAGLE_REAL_H);
    
    return eagleshot_ani;
}

Animation* setEagleRam() {

    Animation* eagleram_ani = new Animation;

    eagleram_ani->setInformation(EAGLERAM, EAGLE_IMG, FLAMES_EAGLE_RAM, 
                CLIPS_EAGLE_RAM, EAGLE_REAL_W, EAGLE_REAL_H);
    
    return eagleram_ani;
}

Animation* setEagleDead() {

    Animation* eagledead_ani = new Animation;

    eagledead_ani->setInformation(EAGLEDEAD, EAGLE_IMG, FLAMES_EAGLE_DEAD, 
                CLIPS_EAGLE_DEAD, EAGLE_REAL_W, EAGLE_REAL_H);
    
    return eagledead_ani;
}

Animation* setEagleHenshin() {

    Animation* eaglehenshin_ani = new Animation;

    eaglehenshin_ani->setInformation(EAGLEHENSHIN, EAGLE_IMG, FLAMES_EAGLE_HENSHIN, 
                CLIPS_EAGLE_HENSHIN, EAGLE_REAL_W, EAGLE_REAL_H);
    
    return eaglehenshin_ani;
}

Animation* setEagleHenshinShot() {

    Animation* eaglehenshinshot_ani = new Animation;

    eaglehenshinshot_ani->setInformation(EAGLEHENSHINSHOT, EAGLE_IMG, FLAMES_EAGLE_HENSHIN_SHOT, 
                CLIPS_EAGLE_HENSHIN_SHOT, EAGLE_REAL_W, EAGLE_REAL_H);
    
    return eaglehenshinshot_ani;
}

Animation* setDiamond() {

    Animation* diamond_ani = new Animation;

    diamond_ani->setInformation(DIAMOND, DIAMOND_IMG, FLAMES_DIAMOND,
                CLIPS_DIAMOND, DIAMOND_REAL_W, DIAMOND_REAL_H);
    
    return diamond_ani;
}


Animation* setDiamondCollapsion() {

    Animation* diamond_colappsion_ani = new Animation;

    diamond_colappsion_ani->setInformation(DIAMONDCOLLAPSION, DIAMONDCOLLAPSION_IMG, 
            FLAMES_DIAMONDCOLLAPSION, CLIPS_DIAMONDCOLLAPSION, 
            DIAMONDCOLLAPSION_REAL_W, DIAMONDCOLLAPSION_REAL_H);

    return diamond_colappsion_ani;
}


Animation* setEvilBird() {

    Animation* evilbird_ani = new Animation;

    evilbird_ani->setInformation(EVILBIRD, EVILBIRD_IMG, 
                       FLAMES_EVILBIRD, CLIPS_EVILBIRD,
                       EVILBIRD_REAL_W, EVILBIRD_REAL_H);

    return evilbird_ani;
}


Animation* setCollapsionByEagle() {

    Animation* colapssion_by_eagle = new Animation;

    colapssion_by_eagle->setInformation(COLLAPSIONBYEAGLE, COLLAPSION_BY_EAGLE_IMG, 
        FLAMES_COLLAPSION_BY_EAGLE, CLIPS_COLLAPSION_BY_EAGLE,
        COLLAPSION_BY_EAGLE_REAL_W, COLLAPSION_BY_EAGLE_REAL_H);

    return colapssion_by_eagle;
}

void clean() {

    SDL_DestroyRenderer(game->renderer); game->renderer = nullptr;
    SDL_DestroyWindow(game->window); game->window = nullptr;

    IMG_Quit();
    SDL_Quit();
}

bool play_again = true;

GameState doPlay() {
        
    BackgroundManager* background = setDay();

    Animation* mainBird = setEggBird();
    Animation* supportBird_flying = setEagleFlying();
    Animation* supportBird_gothit = setEagleGotHit();
    Animation* supportBird_shot = setEagleShot();
    Animation* supportBird_ram = setEagleRam();
    Animation* supportBird_dead = setEagleDead();
    Animation* supportBird_henshin = setEagleHenshin();
    Animation* supportBird_henshinshot = setEagleHenshinShot();
    Animation* collapsionbyByBird = setCollapsionByEagle();
    Animation* diamond = setDiamond();
    Animation* diamondCollapsion = setDiamondCollapsion();
    Animation* enemyBird = setEvilBird();

    game->init(background, mainBird, 
            supportBird_flying, supportBird_gothit, 
            supportBird_shot, supportBird_ram, 
            supportBird_dead, supportBird_henshin, 
            supportBird_henshinshot, collapsionbyByBird, 
            enemyBird, diamond, diamondCollapsion);
                    
    while(game->running()) {
        game->handle_events();
        game->update();
        game->render();
        // waitUntilKeyPressed();
        SDL_Delay(10);
    }

    game->clean();

    return GameState::End;
}

GameState doBegin() {

    SDL_Event event;
    menu->initBegin();

    while(true) {

        menu->renderBegin();
        
        if(SDL_PollEvent(&event)) {

            switch (event.type)
            {
            case SDL_QUIT:
                return GameState::Quit;
            
            case SDL_MOUSEBUTTONUP:
                if(menu->choose_play) return GameState::Play;

            default: break;
            }
            
        }
        
    }
}

GameState doEnd() {

    SDL_Event event;
    menu->initEnd();

    while(true) {

        menu->renderEnd();
        
        if(SDL_PollEvent(&event)) {

            switch (event.type)
            {
            case SDL_QUIT:
                return GameState::Quit;
            
            case SDL_MOUSEBUTTONUP:
                if(menu->choose_replay) return GameState::Begin;

            default: break;
            }
            
        }
        
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));
    init();
    
    GameState state = GameState::Begin;

    game = new Game();
    menu = new Menu();

    while(state != GameState::Quit) {

        switch (state)
        {
        case GameState::Begin: 
            state = doBegin(); 
            break;
        case GameState::Play:
            state = doPlay();
            break;
        case GameState::End:
            state = doEnd();
            break;
        default:
            logErrorAndExit("SwitchState", SDL_GetError());
        }        
    }

    clean();

    return 0;
}