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

    if (TTF_Init() == -1) 
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
                                        TTF_GetError());

    Game::bigfont = TTF_OpenFont("../Font/OCRAEXT.TTF", 100);
    if (Game::bigfont == nullptr) 
        logErrorAndExit("Load bigfont : ", SDL_GetError());
    
    Game::smallfont = TTF_OpenFont("../Font/OCRAEXT.TTF", 30);
    if (Game::smallfont == nullptr) 
        logErrorAndExit("Load smallfont : ", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(Game::renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

}



// BackgroundManager* setDay() {

//     BackgroundManager* day_ani = new BackgroundManager;

//     day_ani->setInformation(DAY, DAY_BG, 
//                         FRAMES_LAYER_DAY, DAY_LAYER);
    
//     return day_ani;
// }

// BackgroundManager* setNight() {

//     BackgroundManager* night_ani = new BackgroundManager;

//     night_ani->setInformation(NIGHT, NIGHT_BG, 
//                         FRAMES_LAYER_NIGHT, NIGHT_LAYER);
    
//     return night_ani;
// }


void clean() {

    SDL_DestroyRenderer(game->renderer); game->renderer = nullptr;
    SDL_DestroyWindow(game->window); game->window = nullptr;
    TTF_CloseFont(game->bigfont);
    TTF_CloseFont(game->smallfont);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool play_again = true;

GameState doPlay() {
        
    BackgroundManager* background = new BackgroundManager(DAY, DAY_BG, 
                        FRAMES_LAYER_DAY, DAY_LAYER);

    // Animation* mainBird = new Animation(EGGBIRD, EGGBIRD_IMG, FRAMES_EGGBIRD, 
    //             CLIPS_EGGBIRD, EGGBIRD_REAL_W, EGGBIRD_REAL_H);

    Animation* mainBird = new Animation(UNICORNBIRD, UNICORNBIRD_IMG, FRAMES_UNICORNBIRD, 
                CLIPS_UNICORNBIRD, UNICORNBIRD_REAL_W, UNICORNBIRD_REAL_H);

    Animation* supportBird_flying = new Animation(EAGLEFLYING, EAGLE_IMG, FRAMES_EAGLE_FLYING, 
                CLIPS_EAGLE_FLYING, EAGLE_REAL_W, EAGLE_REAL_H);
    
    Animation* supportBird_gothit = new Animation(EAGLEGOTHIT, EAGLE_IMG, FRAMES_EAGLE_GOT_HIT, 
                CLIPS_EAGLE_GOT_HIT, EAGLE_REAL_W, EAGLE_REAL_H);
    
    Animation* supportBird_shot = new Animation(EAGLESHOT, EAGLE_IMG, FRAMES_EAGLE_SHOT, 
                CLIPS_EAGLE_SHOT, EAGLE_REAL_W, EAGLE_REAL_H);
    
    Animation* supportBird_ram = new Animation(EAGLERAM, EAGLE_IMG, FRAMES_EAGLE_RAM, 
                CLIPS_EAGLE_RAM, EAGLE_REAL_W, EAGLE_REAL_H);
    
    Animation* supportBird_dead = new Animation(EAGLEDEAD, EAGLE_IMG, FRAMES_EAGLE_DEAD, 
                CLIPS_EAGLE_DEAD, EAGLE_REAL_W, EAGLE_REAL_H);
    
    Animation* supportBird_henshin = new Animation(EAGLEHENSHIN, EAGLE_IMG, FRAMES_EAGLE_HENSHIN, 
                CLIPS_EAGLE_HENSHIN, EAGLE_REAL_W, EAGLE_REAL_H);
    
    Animation* supportBird_henshinshot = new Animation(EAGLEHENSHINSHOT, EAGLE_IMG, FRAMES_EAGLE_HENSHIN_SHOT, 
                CLIPS_EAGLE_HENSHIN_SHOT, EAGLE_REAL_W, EAGLE_REAL_H);
    
    Animation* collapsionbyByBird = new Animation(COLLAPSIONBYEAGLE, COLLAPSION_BY_EAGLE_IMG, 
        FRAMES_COLLAPSION_BY_EAGLE, CLIPS_COLLAPSION_BY_EAGLE,
        COLLAPSION_BY_EAGLE_REAL_W, COLLAPSION_BY_EAGLE_REAL_H);

    Animation* diamond = new Animation(DIAMOND, DIAMOND_IMG, FRAMES_DIAMOND,
                CLIPS_DIAMOND, DIAMOND_REAL_W, DIAMOND_REAL_H);
    
    Animation* diamondCollapsion = new Animation(DIAMONDCOLLAPSION, DIAMONDCOLLAPSION_IMG, 
            FRAMES_DIAMONDCOLLAPSION, CLIPS_DIAMONDCOLLAPSION, 
            DIAMONDCOLLAPSION_REAL_W, DIAMONDCOLLAPSION_REAL_H);

    // Animation* enemyBird = new Animation(EVILBIRD, EVILBIRD_IMG, 
    //                    FRAMES_EVILBIRD, CLIPS_EVILBIRD,
    //                    EVILBIRD_REAL_W, EILBIRD_REAL_H);

    Animation* enemyBird = new Animation(ROCKET, ROCKET_IMG, 
                       FRAMES_ROCKET, CLIPS_ROCKET,
                       ROCKET_REAL_W, ROCKET_REAL_H);


    game->init(background, mainBird, 
            supportBird_flying, supportBird_gothit, 
            supportBird_shot, supportBird_ram, 
            supportBird_dead, supportBird_henshin, 
            supportBird_henshinshot, collapsionbyByBird, 
            enemyBird, diamond, diamondCollapsion);
                    
    while(game->next_state == GameState::Null) {
        game->handle_events();
        game->update();
        game->render();
        // waitUntilKeyPressed();
        SDL_Delay(10);
    }

    highscore = std::max(highscore, game->score);

    game->clean();
    delete background;
    delete diamond; 
    delete diamondCollapsion; 
    delete enemyBird; 
    delete mainBird; 
    delete supportBird_flying; 
    delete supportBird_gothit; 
    delete supportBird_shot; 
    delete supportBird_ram; 
    delete supportBird_dead; 
    delete supportBird_henshin; 
    delete supportBird_henshinshot; 
    delete collapsionbyByBird; 

    if(game->next_state == GameState::Quit) return GameState::Quit;
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