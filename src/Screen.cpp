#include "../Header/Screen.h"



Menu::Menu() {}

// void Menu::renderBackground(std::string filename) {

//     SDL_Texture* texture_ = TextureManager::loadTexture(filename);
//     TextureManager::draw(texture_);

// }


// void Menu::renderIcon(std::string filename, int x, int y) {

//     SDL_Texture* texture_ = TextureManager::loadTexture(filename);
//     TextureManager::drawIcon(texture_, x, y);
// }


bool Menu::check_mouse(int pos_x, int pos_y) {

    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    if(std::hypot(pos_x-mouse_x, pos_y-mouse_y)<=ICON_R) return true;
    else return false;
}

void Menu::initBegin() {

    choose_play = false;

    screen_begin = TextureManager::loadTexture(SCREEN_BEGIN_IMG);
    play_choosen = TextureManager::loadTexture(PLAY_CHOOSEN_IMG);
    play_unchoose = TextureManager::loadTexture(PLAY_UNCHOOSE_IMG);
}

void Menu::renderBegin() {

    choose_play = check_mouse(CHOOSE_PLAY_X, CHOOSE_PLAY_Y);

    SDL_RenderClear(Game::renderer);

    TextureManager::draw(screen_begin);
    if(choose_play) TextureManager::drawIcon(play_choosen, CHOOSE_PLAY_X, CHOOSE_PLAY_Y);
    else TextureManager::drawIcon(play_unchoose, CHOOSE_PLAY_X, CHOOSE_PLAY_Y);

    SDL_RenderPresent(Game::renderer);
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
    if(choose_replay) TextureManager::drawIcon(replay_choosen, CHOOSE_REPLAY_X, CHOOSE_REPLAY_Y);
    else TextureManager::drawIcon(replay_unchoose, CHOOSE_REPLAY_X, CHOOSE_REPLAY_Y);

    SDL_RenderPresent(Game::renderer);
}