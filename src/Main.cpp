#include "../Header/Game.h"
#include "../Header/Screen.h"
// #include "../Header/CommonFunction.h"
// #include "../Header/BackgroundManager.h"
// #include "../Header/AnimationManager.h"
#include "../Header/Background.h"
// #include "../Header/Enemy.h"
// #include "../Header/Bird.h"

Game* game = nullptr;
Menu* menu = nullptr;
Music* music = nullptr;
int highscore = 0;
int map = 0;
typeOfBackground map_current;

void init();
void clean();

void changeMute();
void updateMap();

GameState doPlay();
GameState doBegin();
GameState doEnd();
GameState doChooseMainBird();
GameState doChooseSupportBird();

static BackgroundManager* background;

static Animation *mainBird, *supportBird_flying, *supportBird_gothit,
                *supportBird_shot, *supportBird_ram, 
                *supportBird_dead, *supportBird_henshin, 
                *supportBird_henshinshot, *collapsionbyByBird, 
                *diamond, *diamondCollapsion, *enemyBird,
                *rocket, *rocketCollapsion;

int main(int argc, char *argv[]) {

    srand(time(0));
    init();
    
    GameState state = GameState::Begin;

    game = new Game();
    menu = new Menu();
    music = new Music();

    music->setMusic(-1);
    music->play();

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
        case GameState::ChooseSupportBird:
            state = doChooseSupportBird();
            break;     
        default:
            logErrorAndExit("GameState : ", SDL_GetError());
        }        
    }

    music->stop();
    clean();

    return 0;
}


void init() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    Game::window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    // full screen
    // Game::window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    
    if (Game::window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit( "SDL_image error:", IMG_GetError());

    Game::renderer = SDL_CreateRenderer(Game::window, -1, SDL_RENDERER_ACCELERATED |
                                            SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
    //Game::renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (Game::renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",
                                        Mix_GetError() );

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

    delete music;
    delete menu;
    delete game;

    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void changeMute() {
    if(menu->mute_choosen) {
        menu->mute_choosen = false;
        music->resume();
    }
    else {
        menu->mute_choosen = true;
        music->pause();
    }
}

void updateMap() {

    ++map;
    map%=MAPS;

    switch(map) {
        case 0: map_current = DAY; break;
        case 1: map_current = NIGHT; break;
        default: break;
    }
}


GameState doPlay() {
    
    switch (map_current) {

        case DAY:
            background = new BackgroundManager(DAY, DAY_BG, 
                                FRAMES_LAYER_DAY, DAY_LAYER);
            enemyBird = new Animation(EVILBIRD, EVILBIRD_IMG, 
                                FRAMES_EVILBIRD, CLIPS_EVILBIRD,
                                EVILBIRD_REAL_W, EVILBIRD_REAL_H);
            break;

        case NIGHT:
            background = new BackgroundManager(NIGHT, NIGHT_BG, 
                                FRAMES_LAYER_NIGHT, NIGHT_LAYER);
            enemyBird = new Animation(MASKBIRD, MASKBIRD_IMG, 
                            FRAMES_MASKBIRD, CLIPS_MASKBIRD,
                            MASKBIRD_REAL_W, MASKBIRD_REAL_H);
            break;

        default: 
            break;
    }

    if(menu->choose_eggbird) mainBird = new Animation(EGGBIRD, EGGBIRD_IMG, 
                            FRAMES_EGGBIRD, CLIPS_EGGBIRD, 
                            EGGBIRD_REAL_W, EGGBIRD_REAL_H);

    if(menu->choose_unicornbird) mainBird = new Animation(UNICORNBIRD, UNICORNBIRD_IMG, 
                        FRAMES_UNICORNBIRD, CLIPS_UNICORNBIRD, 
                        UNICORNBIRD_REAL_W, UNICORNBIRD_REAL_H);

    if(menu->choose_eagle) {

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
    }

    if(menu->choose_chicken) {

        supportBird_flying = new Animation(CHICKENFLYING, CHICKEN_IMG, 
                            FRAMES_CHICKEN_FLYING, CLIPS_CHICKEN_FLYING, 
                                    CHICKEN_REAL_W, CHICKEN_REAL_H);
        
        supportBird_gothit = new Animation(CHICKENGOTHIT, CHICKEN_IMG, 
                        FRAMES_CHICKEN_GOT_HIT, CLIPS_CHICKEN_GOT_HIT, 
                                    CHICKEN_REAL_W, CHICKEN_REAL_H);
        
        supportBird_shot = new Animation(CHICKENSHOT, CHICKEN_IMG, 
                            FRAMES_CHICKEN_SHOT, CLIPS_CHICKEN_SHOT, 
                                    CHICKEN_REAL_W, CHICKEN_REAL_H);
        
        supportBird_ram = new Animation(CHICKENRAM, CHICKEN_IMG, 
                                FRAMES_CHICKEN_RAM, CLIPS_CHICKEN_RAM, 
                                    CHICKEN_REAL_W, CHICKEN_REAL_H);
        
        supportBird_dead = new Animation(CHICKENDEAD, CHICKEN_IMG, 
                            FRAMES_CHICKEN_DEAD, CLIPS_CHICKEN_DEAD, 
                                    CHICKEN_REAL_W, CHICKEN_REAL_H);
        
        supportBird_henshin = new Animation(CHICKENHENSHIN, CHICKEN_IMG, 
                        FRAMES_CHICKEN_HENSHIN, CLIPS_CHICKEN_HENSHIN, 
                                    CHICKEN_REAL_W, CHICKEN_REAL_H);
        
        supportBird_henshinshot = new Animation(CHICKENHENSHINSHOT, CHICKEN_IMG, 
                FRAMES_CHICKEN_HENSHIN_SHOT, CLIPS_CHICKEN_HENSHIN_SHOT, 
                                    CHICKEN_REAL_W, CHICKEN_REAL_H);
        
        collapsionbyByBird = new Animation(COLLAPSIONBYCHICKEN, COLLAPSION_BY_CHICKEN_IMG, 
            FRAMES_COLLAPSION_BY_CHICKEN, CLIPS_COLLAPSION_BY_CHICKEN,
            COLLAPSION_BY_CHICKEN_REAL_W, COLLAPSION_BY_CHICKEN_REAL_H);
    }

    diamond = new Animation(DIAMOND, DIAMOND_IMG, 
                            FRAMES_DIAMOND, CLIPS_DIAMOND, 
                            DIAMOND_REAL_W, DIAMOND_REAL_H);
    
    diamondCollapsion = new Animation(DIAMONDCOLLAPSION, DIAMONDCOLLAPSION_IMG, 
            FRAMES_DIAMONDCOLLAPSION, CLIPS_DIAMONDCOLLAPSION, 
            DIAMONDCOLLAPSION_REAL_W, DIAMONDCOLLAPSION_REAL_H);

    rocket = new Animation(ROCKET, ROCKET_IMG, 
                    FRAMES_ROCKET, CLIPS_ROCKET,
                    ROCKET_REAL_W, ROCKET_REAL_H);

    rocketCollapsion = new Animation(ROCKETCOLLAPSION, ROCKETCOLLAPSION_IMG, 
                    FRAMES_ROCKETCOLLAPSION, CLIPS_ROCKETCOLLAPSION,
                    ROCKETCOLLAPSION_REAL_W, ROCKETCOLLAPSION_REAL_H);

    Timing time_play;

    game->init(background, mainBird, 
            supportBird_flying, supportBird_gothit, 
            supportBird_shot, supportBird_ram, 
            supportBird_dead, supportBird_henshin, 
            supportBird_henshinshot, collapsionbyByBird, 
            enemyBird, diamond, diamondCollapsion,
            rocket, rocketCollapsion);
                    
    while(game->next_state == GameState::Null) {

        time_play.start();

        game->handle_events();
        game->update();
        game->render();
        
        time_play.checkDelayFrame();
    }

    if(game->next_state == GameState::End) SDL_Delay(1000);

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

    SDL_Event event;
    Timing time_begin;

    GameState next_state = GameState::Null;
    menu->initBegin();

    while(next_state == GameState::Null) {

        time_begin.start();

        menu->renderBegin();
        
        while(SDL_PollEvent(&event)) {

            switch (event.type)
            {
                
                case SDL_QUIT:
                    next_state = GameState::Quit;
                    break;

                case SDL_MOUSEBUTTONUP:
                    menu->pick.play();
                    if(menu->choose_play) 
                        next_state = GameState::ChooseMainBird;
                    if(menu->choose_exit)
                        next_state = GameState::Quit;
                    if(menu->choose_mute) {
                        changeMute();
                    }

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_0: changeMute(); break;
                        case SDLK_1: music->reset(1); break; 
                        case SDLK_2: music->reset(2); break; 
                        case SDLK_3: music->reset(3); break; 
                        case SDLK_4: music->reset(4); break; 
                        case SDLK_5: music->reset(5); break; 
                        case SDLK_6: music->reset(6); break; 
                        case SDLK_7: music->reset(7); break; 
                        case SDLK_8: music->reset(8); break; 
                        case SDLK_9: music->reset(9); break; 
                        default: break;
                    }
                    break;

                default: 
                    break;
            }
        }

        time_begin.checkDelayFrame();
    }

    menu->cleanBegin();
    return next_state;
}

GameState doEnd() {

    SDL_Event event;
    Timing time_end;
    
    GameState next_state = GameState::Null;
    menu->initEnd();

    while(next_state == GameState::Null) {

        time_end.start();

        menu->renderEnd();
        
        while(SDL_PollEvent(&event)) {

            switch (event.type)
            {
                case SDL_QUIT:
                    next_state = GameState::Quit;
                    break;

                case SDL_MOUSEBUTTONUP:
                    if(menu->choose_replay) 
                        next_state = GameState::Begin;
                    break;

                default: 
                    break;
            }
        }

        time_end.checkDelayFrame();
    }

    menu->cleanEnd();

    if(next_state == GameState::Begin) {
        music->reset(-2);
        updateMap();
    }

    return next_state;
}

GameState doChooseMainBird() {
    
    SDL_Event event;
    Timing time_choosemainbird;

    GameState next_state = GameState::Null;
    menu->initChooseMainBird();

    while(next_state == GameState::Null) {

        time_choosemainbird.start();

        menu->renderChooseMainBird();
        
        while(SDL_PollEvent(&event)) {

            switch (event.type)
            {
                case SDL_QUIT:
                    next_state = GameState::Quit;
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    if(menu->choose_eggbird || menu->choose_unicornbird)
                        next_state = GameState::ChooseSupportBird;
                    if(menu->choose_back)
                        next_state = GameState::Begin;
                    break;

                default: 
                    break;
            } 
        }   

        time_choosemainbird.checkDelayFrame();
    }

    menu->cleanChooseMainBird();
    return next_state;
}

GameState doChooseSupportBird() {
    
    SDL_Event event;
    Timing time_choosespbird;

    GameState next_state = GameState::Null;
    menu->initChooseSupportBird();

    while(next_state == GameState::Null) {

        time_choosespbird.start();

        menu->renderChooseSupportBird();
        
        while(SDL_PollEvent(&event)) {

            switch (event.type)
            {
                case SDL_QUIT:
                    next_state = GameState::Quit;
                    break;
                
                case SDL_MOUSEBUTTONUP:
                    if(menu->choose_eagle || menu->choose_chicken)
                        next_state = GameState::Play;
                    if(menu->choose_back)
                        next_state = GameState::ChooseMainBird;
                    break;

                default: 
                    break;
            }
        }   

        time_choosespbird.checkDelayFrame();
    }
    
    menu->cleanChooseSupportBird();
    return next_state;
}