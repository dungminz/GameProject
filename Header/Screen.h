#pragma once

#include "Game.h"


const int CHOOSE_PLAY_X = SCREEN_WIDTH/2;
const int CHOOSE_PLAY_Y = SCREEN_HEIGHT/2;
const int CHOOSE_REPLAY_X = SCREEN_WIDTH/2;
const int CHOOSE_REPLAY_Y = SCREEN_HEIGHT/2;

const std::string SCREEN_BEGIN_IMG = "../Image/Screen/screen_begin.png";
const std::string PLAY_CHOOSEN_IMG = "../Image/Screen/play_choosen.png";
const std::string PLAY_UNCHOOSE_IMG = "../Image/Screen/play_unchoose.png";

const std::string SCREEN_END_IMG = "../Image/Screen/screen_end.png";
const std::string REPLAY_CHOOSEN_IMG = "../Image/Screen/replay_choosen.png";
const std::string REPLAY_UNCHOOSE_IMG = "../Image/Screen/replay_unchoose.png";

struct Menu {

    bool choose_play;
    SDL_Texture* screen_begin;
    SDL_Texture* play_choosen;
    SDL_Texture* play_unchoose;

    bool choose_replay;
    SDL_Texture* screen_end;
    SDL_Texture* replay_choosen;
    SDL_Texture* replay_unchoose;
    Menu();

    // void renderBackground(std::string filename);
    // void renderIcon(std::string filename, int x, int y);

    bool check_mouse(int pos_x, int pos_y);

    void initBegin();
    void renderChooseMainBird();
    void renderChooseSupportBird();
    void renderBegin();

    void initPause();
    void renderPause();

    void initEnd();
    void renderEnd();
};