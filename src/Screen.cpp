#include "../Header/Screen.h"


Menu::Menu() :pick(SOUND_PICK) {}

Menu::~Menu() {
    
}

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

    choose_volume = false;
    volume_choosen = TextureManager::loadTexture(VOLUME_CHOOSEN_IMG);
    volume_unchoose = TextureManager::loadTexture(VOLUME_UNCHOOSE_IMG);
}

void Menu::renderBegin() {

    choose_play = check_mouse(CHOOSE_PLAY_X, CHOOSE_PLAY_Y);
    choose_volume = check_mouse(CHOOSE_VOLUME_X, CHOOSE_VOLUME_Y);

    SDL_RenderClear(Game::renderer);

    TextureManager::draw(screen_begin);

    if(choose_play) 
        TextureManager::drawIcon(play_choosen, CHOOSE_PLAY_X, CHOOSE_PLAY_Y);
    else 
        TextureManager::drawIcon(play_unchoose, CHOOSE_PLAY_X, CHOOSE_PLAY_Y);

    if(choose_volume) 
        TextureManager::drawIcon(volume_choosen, CHOOSE_VOLUME_X, CHOOSE_VOLUME_Y);
    else
        TextureManager::drawIcon(volume_unchoose, CHOOSE_VOLUME_X, CHOOSE_VOLUME_Y);

    SDL_RenderPresent(Game::renderer);
}

void Menu::cleanBegin() {

    SDL_DestroyTexture(screen_begin);
    SDL_DestroyTexture(play_choosen);
    SDL_DestroyTexture(play_unchoose);
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
    TextureManager::drawText(std::to_string(score), Game::mediumfont, black, 
                                        SCORE_X, SCORE_Y);
    TextureManager::drawText("High score : "+std::to_string(highscore), Game::mediumfont, black, 
                                    HIGH_SCORE_X, HIGH_SCORE_Y);

    SDL_RenderPresent(Game::renderer);
}


void Menu::cleanEnd() {

    SDL_DestroyTexture(screen_end);
    SDL_DestroyTexture(replay_choosen);
    SDL_DestroyTexture(replay_unchoose);
}


void Menu::initChooseMainBird() {

    choose_bird1 = false;
    choose_bird2 = false;

    screen_choose = TextureManager::loadTexture(SCREEN_CHOOSE_IMG);
    bird1_choosen = TextureManager::loadTexture(EGGBIRD_CHOOSEN_IMG);
    bird1_unchoose = TextureManager::loadTexture(EGGBIRD_UNCHOOSE_IMG);
    bird2_choosen = TextureManager::loadTexture(UNICORNBIRD_CHOOSEN_IMG);
    bird2_unchoose = TextureManager::loadTexture(UNICORNBIRD_UNCHOOSE_IMG);
    
}

void Menu::renderChooseMainBird() {

    choose_bird1 = check_mouse(CHOOSE_EGGBIRD_X, CHOOSE_EGGBIRD_Y, 
                        EGGBIRD_CHOOSEN_W, EGGBIRD_CHOOSEN_H);

    choose_bird2 = check_mouse(CHOOSE_UNICORNBIRD_X, CHOOSE_UNICORNBIRD_Y, 
                        UNICORNBIRD_CHOOSEN_W, UNICORNBIRD_CHOOSEN_H);

    SDL_RenderClear(Game::renderer);

    TextureManager::draw(screen_choose);
    TextureManager::drawText("Choose Main Bird", Game::mediumfont, black, 
                    CHOOSE_BIRD_TEXT_X, CHOOSE_BIRD_TEXT_Y);

    if(choose_bird1) 
        TextureManager::drawIcon(bird1_choosen,
                        CHOOSE_EGGBIRD_X, CHOOSE_EGGBIRD_Y,
                        EGGBIRD_CHOOSEN_W/2.5*3, EGGBIRD_CHOOSEN_H/2.5*3);
    else 
        TextureManager::drawIcon(bird1_unchoose,
                        CHOOSE_EGGBIRD_X, CHOOSE_EGGBIRD_Y,
                        EGGBIRD_CHOOSEN_W, EGGBIRD_CHOOSEN_H);

    if(choose_bird2) 
        TextureManager::drawIcon(bird2_choosen,
                        CHOOSE_UNICORNBIRD_X, CHOOSE_UNICORNBIRD_Y,
                        UNICORNBIRD_CHOOSEN_W/2.5*3, UNICORNBIRD_CHOOSEN_H/2.5*3);
    else 
        TextureManager::drawIcon(bird2_unchoose,
                        CHOOSE_UNICORNBIRD_X, CHOOSE_UNICORNBIRD_Y,
                        UNICORNBIRD_CHOOSEN_W, UNICORNBIRD_CHOOSEN_H);

    SDL_RenderPresent(Game::renderer);
}


void Menu::cleanChooseMainBird() {

    SDL_DestroyTexture(screen_choose);
    SDL_DestroyTexture(bird1_choosen);
    SDL_DestroyTexture(bird1_unchoose);
    SDL_DestroyTexture(bird2_choosen);
    SDL_DestroyTexture(bird2_unchoose);
}