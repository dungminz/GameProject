#include "../Header/Screen.h"


Menu::Menu() :pick(SOUND_PICK) {}

Menu::~Menu() {}



bool Menu::check_mouse(int pos_x, int pos_y) {

    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    if(std::hypot(pos_x-mouse_x, pos_y-mouse_y)<=ICON_R) return true;
    else return false;
}

bool Menu::check_mouse(int pos_x, int pos_y, int w, int h) {

    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    SDL_Rect A({pos_x-w/2, pos_y-h/2, w, h});
    SDL_Rect B({mouse_x, mouse_y, 1, 1});

    if(SDL_HasIntersection(&A, &B)) return true;
    else return false;
}




void Menu::initBegin() {

    screen_begin = TextureManager::loadTexture(SCREEN_BEGIN_IMG);

    choose_play = false;
    play_choosen = TextureManager::loadTexture(PLAY_CHOOSEN_IMG);
    play_unchoose = TextureManager::loadTexture(PLAY_UNCHOOSE_IMG);

    choose_mute = false;
    unmute = TextureManager::loadTexture(UNMUTE_IMG);
    mute = TextureManager::loadTexture(MUTE_IMG);

    choose_exit = false;
    exit_choosen = TextureManager::loadTexture(EXIT_CHOOSEN_IMG);
    exit_unchoose = TextureManager::loadTexture(EXIT_UNCHOOSE_IMG);    
}

void Menu::renderBegin() {

    choose_play = check_mouse(CHOOSE_PLAY_X, CHOOSE_PLAY_Y);
    choose_mute = check_mouse(CHOOSE_MUTE_X, CHOOSE_MUTE_Y);
    choose_exit = check_mouse(CHOOSE_EXIT_X, CHOOSE_EXIT_Y);

    SDL_RenderClear(Game::renderer);

    TextureManager::draw(screen_begin);

    if(choose_play) 
        TextureManager::drawIcon(play_choosen, CHOOSE_PLAY_X, CHOOSE_PLAY_Y);
    else 
        TextureManager::drawIcon(play_unchoose, CHOOSE_PLAY_X, CHOOSE_PLAY_Y);

    if(mute_choosen) 
        TextureManager::drawIcon(mute, CHOOSE_MUTE_X, CHOOSE_MUTE_Y);
    else
        TextureManager::drawIcon(unmute, CHOOSE_MUTE_X, CHOOSE_MUTE_Y);

    if(choose_exit) 
        TextureManager::drawIcon(exit_choosen, CHOOSE_EXIT_X, CHOOSE_EXIT_Y);
    else
        TextureManager::drawIcon(exit_unchoose, CHOOSE_EXIT_X, CHOOSE_EXIT_Y);

    SDL_RenderPresent(Game::renderer);
}

void Menu::cleanBegin() {

    SDL_DestroyTexture(screen_begin);
    SDL_DestroyTexture(play_choosen);
    SDL_DestroyTexture(play_unchoose);
    SDL_DestroyTexture(mute);
    SDL_DestroyTexture(unmute);
    SDL_DestroyTexture(exit_choosen);
    SDL_DestroyTexture(exit_unchoose);
}




void Menu::initEnd() {

    choose_replay = false;

    screen_end = TextureManager::loadTexture(SCREEN_END_IMG);
    replay_choosen = TextureManager::loadTexture(REPLAY_CHOOSEN_IMG);
    replay_unchoose = TextureManager::loadTexture(REPLAY_UNCHOOSE_IMG);
}

void Menu::renderEnd() {

    choose_replay = check_mouse(CHOOSE_REPLAY_X, CHOOSE_REPLAY_Y);

    SDL_RenderClear(Game::renderer);

    TextureManager::draw(screen_end);
    if(choose_replay) TextureManager::drawIcon(replay_choosen, 
                        CHOOSE_REPLAY_X, CHOOSE_REPLAY_Y);
    else TextureManager::drawIcon(replay_unchoose, 
                        CHOOSE_REPLAY_X, CHOOSE_REPLAY_Y);

    TextureManager::drawText(std::to_string(score), Game::bigfont, black, 
                                        SCORE_X, SCORE_Y);
    TextureManager::drawText("Best score : "+std::to_string(highscore), Game::mediumfont, black, 
                                    HIGH_SCORE_X, HIGH_SCORE_Y);

    SDL_RenderPresent(Game::renderer);
}

void Menu::cleanEnd() {

    SDL_DestroyTexture(screen_end);
    SDL_DestroyTexture(replay_choosen);
    SDL_DestroyTexture(replay_unchoose);
}




void Menu::initChooseMainBird() {
    
    choose_back = false;
    choose_eggbird = false;
    choose_unicornbird = false;

    screen_choose = TextureManager::loadTexture(SCREEN_CHOOSE_IMG);
    back_choosen = TextureManager::loadTexture(BACK_CHOOSEN_IMG);
    back_unchoose = TextureManager::loadTexture(BACK_UNCHOOSE_IMG);
    eggbird_choosen = TextureManager::loadTexture(EGGBIRD_CHOOSEN_IMG);
    eggbird_unchoose = TextureManager::loadTexture(EGGBIRD_UNCHOOSE_IMG);
    unicornbird_choosen = TextureManager::loadTexture(UNICORNBIRD_CHOOSEN_IMG);
    unicornbird_unchoose = TextureManager::loadTexture(UNICORNBIRD_UNCHOOSE_IMG);
}

void Menu::renderChooseMainBird() {

    choose_back = check_mouse(CHOOSE_BACK_X, CHOOSE_BACK_Y);
    choose_eggbird = check_mouse(CHOOSE_EGGBIRD_X, CHOOSE_EGGBIRD_Y, 
                        EGGBIRD_CHOOSEN_W, EGGBIRD_CHOOSEN_H);
    choose_unicornbird = check_mouse(CHOOSE_UNICORNBIRD_X, CHOOSE_UNICORNBIRD_Y, 
                        UNICORNBIRD_CHOOSEN_W, UNICORNBIRD_CHOOSEN_H);

    SDL_RenderClear(Game::renderer);

    TextureManager::draw(screen_choose);
    TextureManager::drawText("Choose Main Bird", Game::mediumfont, black, 
                    CHOOSE_BIRD_TEXT_X, CHOOSE_BIRD_TEXT_Y);

    if(choose_back)
        TextureManager::drawIcon(back_choosen,
                        CHOOSE_BACK_X, CHOOSE_BACK_Y,
                        ICON_SIZE/3*2, ICON_SIZE/3*2);
    else
        TextureManager::drawIcon(back_unchoose,
                        CHOOSE_BACK_X, CHOOSE_BACK_Y,
                        ICON_SIZE/3*2, ICON_SIZE/3*2);

    if(choose_eggbird) 
        TextureManager::drawIcon(eggbird_choosen,
                        CHOOSE_EGGBIRD_X, CHOOSE_EGGBIRD_Y,
                        EGGBIRD_CHOOSEN_W/2.5*3, EGGBIRD_CHOOSEN_H/2.5*3);
    else 
        TextureManager::drawIcon(eggbird_unchoose,
                        CHOOSE_EGGBIRD_X, CHOOSE_EGGBIRD_Y,
                        EGGBIRD_CHOOSEN_W, EGGBIRD_CHOOSEN_H);

    if(choose_unicornbird) 
        TextureManager::drawIcon(unicornbird_choosen,
                        CHOOSE_UNICORNBIRD_X, CHOOSE_UNICORNBIRD_Y,
                        UNICORNBIRD_CHOOSEN_W/2.5*3, UNICORNBIRD_CHOOSEN_H/2.5*3);
    else 
        TextureManager::drawIcon(unicornbird_unchoose,
                        CHOOSE_UNICORNBIRD_X, CHOOSE_UNICORNBIRD_Y,
                        UNICORNBIRD_CHOOSEN_W, UNICORNBIRD_CHOOSEN_H);

    SDL_RenderPresent(Game::renderer);
}

void Menu::cleanChooseMainBird() {

    SDL_DestroyTexture(screen_choose);
    SDL_DestroyTexture(back_choosen);
    SDL_DestroyTexture(back_unchoose);
    SDL_DestroyTexture(eggbird_choosen);
    SDL_DestroyTexture(eggbird_unchoose);
    SDL_DestroyTexture(unicornbird_choosen);
    SDL_DestroyTexture(unicornbird_unchoose);
}




void Menu::initChooseSupportBird() {

    choose_back = false;
    choose_eagle = false;
    choose_chicken = false;

    screen_choose = TextureManager::loadTexture(SCREEN_CHOOSE_IMG);
    back_choosen = TextureManager::loadTexture(BACK_CHOOSEN_IMG);
    back_unchoose = TextureManager::loadTexture(BACK_UNCHOOSE_IMG);
    eagle_choosen = TextureManager::loadTexture(EAGLE_CHOOSEN_IMG);
    eagle_unchoose = TextureManager::loadTexture(EAGLE_UNCHOOSE_IMG);
    chicken_choosen = TextureManager::loadTexture(CHICKEN_CHOOSEN_IMG);
    chicken_unchoose = TextureManager::loadTexture(CHICKEN_UNCHOOSE_IMG);
    
}

void Menu::renderChooseSupportBird() {

    choose_back = check_mouse(CHOOSE_BACK_X, CHOOSE_BACK_Y);
    choose_eagle = check_mouse(CHOOSE_EAGLE_X, CHOOSE_EAGLE_Y, 
                        EAGLE_CHOOSEN_W, EAGLE_CHOOSEN_H);
    choose_chicken = check_mouse(CHOOSE_CHICKEN_X, CHOOSE_CHICKEN_Y, 
                        CHICKEN_CHOOSEN_W, CHICKEN_CHOOSEN_H);

    SDL_RenderClear(Game::renderer);

    TextureManager::draw(screen_choose);
    TextureManager::drawText("Choose Support Bird", Game::mediumfont, black, 
                    CHOOSE_BIRD_TEXT_X, CHOOSE_BIRD_TEXT_Y);

    if(choose_back)
        TextureManager::drawIcon(back_choosen,
                        CHOOSE_BACK_X, CHOOSE_BACK_Y,
                        ICON_SIZE/3*2, ICON_SIZE/3*2);
    else
        TextureManager::drawIcon(back_unchoose,
                        CHOOSE_BACK_X, CHOOSE_BACK_Y,
                        ICON_SIZE/3*2, ICON_SIZE/3*2);

    if(choose_eagle) 
        TextureManager::drawIcon(eagle_choosen,
                        CHOOSE_EAGLE_X, CHOOSE_EAGLE_Y,
                        EAGLE_CHOOSEN_W/2.5*3, EAGLE_CHOOSEN_H/2.5*3);
    else 
        TextureManager::drawIcon(eagle_unchoose,
                        CHOOSE_EAGLE_X, CHOOSE_EAGLE_Y,
                        EAGLE_CHOOSEN_W, EAGLE_CHOOSEN_H);

    if(choose_chicken) 
        TextureManager::drawIcon(chicken_choosen,
                        CHOOSE_CHICKEN_X, CHOOSE_CHICKEN_Y,
                        CHICKEN_CHOOSEN_W/2.5*3, CHICKEN_CHOOSEN_H/2.5*3);
    else 
        TextureManager::drawIcon(chicken_unchoose,
                        CHOOSE_CHICKEN_X, CHOOSE_CHICKEN_Y,
                        CHICKEN_CHOOSEN_W, CHICKEN_CHOOSEN_H);

    SDL_RenderPresent(Game::renderer);
}

void Menu::cleanChooseSupportBird() {

    SDL_DestroyTexture(screen_choose);
    SDL_DestroyTexture(back_choosen);
    SDL_DestroyTexture(back_unchoose);
    SDL_DestroyTexture(eagle_choosen);
    SDL_DestroyTexture(eagle_unchoose);
    SDL_DestroyTexture(chicken_choosen);
    SDL_DestroyTexture(chicken_unchoose);
}