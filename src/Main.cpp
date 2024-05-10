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
int highscore = 0;

void init();
void clean();

GameState doPlay();
GameState doBegin();
GameState doEnd();
GameState doChooseMainBird();

static BackgroundManager* background;

static Animation *mainBird, *supportBird_flying, *supportBird_gothit,
                *supportBird_shot, *supportBird_ram, 
                *supportBird_dead, *supportBird_henshin, 
                *supportBird_henshinshot, *collapsionbyByBird, 
                *diamond, *diamondCollapsion, *enemyBird;

bool chooseDay, chooseNight, chooseEggBird, 
        chooseUnicornBird, chooseEagle, chooseEvilBird;

int main(int argc, char *argv[])
{
    srand(time(0));
    init();
    
    GameState state = GameState::Begin;

    game = new Game();
    menu = new Menu();

    Music mus(MUSIC_THEME);
    mus.play();

    // Sound sou(SOUND_PICK);

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
        case GameState::ChooseMainBird:
            state = doChooseMainBird();
            break;            
        default:
            logErrorAndExit("GameState : ", SDL_GetError());
        }        
    }

    mus.stop();
    clean();

    return 0;
}


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

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",
                        Mix_GetError() );
    }

    if (TTF_Init() == -1) 
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
                                        TTF_GetError());

    Game::bigfont = TTF_OpenFont("../Font/OCRAEXT.TTF", 100);
    if (Game::bigfont == nullptr) 
        logErrorAndExit("Load bigfont : ", SDL_GetError());

    Game::mediumfont = TTF_OpenFont("../Font/OCRAEXT.TTF", 45);
    if (Game::mediumfont == nullptr) 
        logErrorAndExit("Load smallfont : ", SDL_GetError());

    Game::smallfont = TTF_OpenFont("../Font/OCRAEXT.TTF", 30);
    if (Game::smallfont == nullptr) 
        logErrorAndExit("Load smallfont : ", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(Game::renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

}

void clean() {

    SDL_DestroyRenderer(game->renderer); game->renderer = nullptr;
    SDL_DestroyWindow(game->window); game->window = nullptr;
    TTF_CloseFont(game->bigfont); game->bigfont = nullptr;
    TTF_CloseFont(game->smallfont); game->smallfont = nullptr;

    delete menu;
    delete game;

    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}





GameState doPlay() {
        
    // background = new BackgroundManager(DAY, DAY_BG, 
    //                         FRAMES_LAYER_DAY, DAY_LAYER);
    
    background = new BackgroundManager(NIGHT, NIGHT_BG, 
                            FRAMES_LAYER_NIGHT, NIGHT_LAYER);

    mainBird = new Animation(EGGBIRD, EGGBIRD_IMG, 
                            FRAMES_EGGBIRD, CLIPS_EGGBIRD, 
                            EGGBIRD_REAL_W, EGGBIRD_REAL_H);

    mainBird = new Animation(UNICORNBIRD, UNICORNBIRD_IMG, 
                        FRAMES_UNICORNBIRD, CLIPS_UNICORNBIRD, 
                        UNICORNBIRD_REAL_W, UNICORNBIRD_REAL_H);

    supportBird_flying = new Animation(EAGLEFLYING, EAGLE_IMG, 
                        FRAMES_EAGLE_FLYING, CLIPS_EAGLE_FLYING, 
                                EAGLE_REAL_W, EAGLE_REAL_H);
    
    supportBird_gothit = new Animation(EAGLEGOTHIT, EAGLE_IMG, 
                    FRAMES_EAGLE_GOT_HIT, CLIPS_EAGLE_GOT_HIT, 
                                EAGLE_REAL_W, EAGLE_REAL_H);
    
    supportBird_shot = new Animation(EAGLESHOT, EAGLE_IMG, 
                        FRAMES_EAGLE_SHOT, CLIPS_EAGLE_SHOT, 
                                EAGLE_REAL_W, EAGLE_REAL_H);
    
    supportBird_ram = new Animation(EAGLERAM, EAGLE_IMG, 
                            FRAMES_EAGLE_RAM, CLIPS_EAGLE_RAM, 
                                EAGLE_REAL_W, EAGLE_REAL_H);
    
    supportBird_dead = new Animation(EAGLEDEAD, EAGLE_IMG, 
                        FRAMES_EAGLE_DEAD, CLIPS_EAGLE_DEAD, 
                                EAGLE_REAL_W, EAGLE_REAL_H);
    
    supportBird_henshin = new Animation(EAGLEHENSHIN, EAGLE_IMG, 
                    FRAMES_EAGLE_HENSHIN, CLIPS_EAGLE_HENSHIN, 
                                EAGLE_REAL_W, EAGLE_REAL_H);
    
    supportBird_henshinshot = new Animation(EAGLEHENSHINSHOT, EAGLE_IMG, 
            FRAMES_EAGLE_HENSHIN_SHOT, CLIPS_EAGLE_HENSHIN_SHOT, 
                                EAGLE_REAL_W, EAGLE_REAL_H);
    
    collapsionbyByBird = new Animation(COLLAPSIONBYEAGLE, COLLAPSION_BY_EAGLE_IMG, 
        FRAMES_COLLAPSION_BY_EAGLE, CLIPS_COLLAPSION_BY_EAGLE,
        COLLAPSION_BY_EAGLE_REAL_W, COLLAPSION_BY_EAGLE_REAL_H);

    diamond = new Animation(DIAMOND, DIAMOND_IMG, 
                            FRAMES_DIAMOND, CLIPS_DIAMOND, 
                            DIAMOND_REAL_W, DIAMOND_REAL_H);
    
    diamondCollapsion = new Animation(DIAMONDCOLLAPSION, DIAMONDCOLLAPSION_IMG, 
            FRAMES_DIAMONDCOLLAPSION, CLIPS_DIAMONDCOLLAPSION, 
            DIAMONDCOLLAPSION_REAL_W, DIAMONDCOLLAPSION_REAL_H);

    enemyBird = new Animation(EVILBIRD, EVILBIRD_IMG, 
                            FRAMES_EVILBIRD, CLIPS_EVILBIRD,
                            EVILBIRD_REAL_W, EVILBIRD_REAL_H);

    // enemyBird = new Animation(ROCKET, ROCKET_IMG, 
    //                         FRAMES_ROCKET, CLIPS_ROCKET,
    //                         ROCKET_REAL_W, ROCKET_REAL_H);

    Timer time;

    game->init(background, mainBird, 
            supportBird_flying, supportBird_gothit, 
            supportBird_shot, supportBird_ram, 
            supportBird_dead, supportBird_henshin, 
            supportBird_henshinshot, collapsionbyByBird, 
            enemyBird, diamond, diamondCollapsion);
                    
    while(game->next_state == GameState::Null) {

        time.start();
        game->handle_events();
        game->update();
        game->render();
        
        time.checkDelayFrame();
    }

    menu->score = game->score;
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

    Timer time_begin;
    SDL_Event event;
    menu->initBegin();
    time_begin.start();

    while(true) {

        // time_begin.start();
        menu->renderBegin();
        
        if(SDL_PollEvent(&event)) {

            switch (event.type)
            {
            case SDL_QUIT:
                return GameState::Quit;
                break;

            case SDL_MOUSEBUTTONUP:
                menu->pick.play();
                if(menu->choose_play) {
                    menu->cleanBegin();
                    return GameState::ChooseMainBird;
                }
                break;

            default: 
                break;
            }
        }
        time_begin.checkDelayFrame();
    }

    menu->cleanBegin();
    return GameState::ChooseMainBird;
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
                break;

            case SDL_MOUSEBUTTONUP:
                if(menu->choose_replay) return GameState::ChooseMainBird;
                break;

            default: 
                break;
            }
        }
    }

    menu->cleanEnd();
}

GameState doChooseMainBird() {
    
    SDL_Event event;
    menu->initChooseMainBird();

    while(true) {

        menu->renderChooseMainBird();
        
        if(SDL_PollEvent(&event)) {

            switch (event.type)
            {
            case SDL_QUIT:
                return GameState::Quit;
            
            case SDL_MOUSEBUTTONUP:
                if(menu->bird1_choosen) return GameState::Play;

            default: break;
            }
            
        }   
    }
    
    menu->cleanChooseMainBird();
}