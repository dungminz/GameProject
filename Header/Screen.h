#pragma once

#include "Game.h"
#include "Bird.h"

const int CHOOSE_PLAY_X = SCREEN_WIDTH/2;
const int CHOOSE_PLAY_Y = SCREEN_HEIGHT/2;

const int CHOOSE_REPLAY_X = SCREEN_WIDTH/2;
const int CHOOSE_REPLAY_Y = SCREEN_HEIGHT/2;

const int CHOOSE_VOLUME_X = SCREEN_WIDTH/2-150;
const int CHOOSE_VOLUME_Y = SCREEN_HEIGHT/2;

const int CHOOSE_BIRD_TEXT_X = SCREEN_WIDTH/2;
const int CHOOSE_BIRD_TEXT_Y = SCREEN_HEIGHT/6;

const int CHOOSE_EGGBIRD_X = SCREEN_WIDTH/4;
const int CHOOSE_EGGBIRD_Y = SCREEN_HEIGHT/2;
const int EGGBIRD_CHOOSEN_W = EGGBIRD_REAL_W*2.5;
const int EGGBIRD_CHOOSEN_H = EGGBIRD_REAL_H*2.5;

const int CHOOSE_UNICORNBIRD_X = SCREEN_WIDTH/4*3;
const int CHOOSE_UNICORNBIRD_Y = SCREEN_HEIGHT/2;
const int UNICORNBIRD_CHOOSEN_W = UNICORNBIRD_REAL_W*3;
const int UNICORNBIRD_CHOOSEN_H = UNICORNBIRD_REAL_H*2.5;

const int HIGH_SCORE_X = SCREEN_WIDTH/2;
const int HIGH_SCORE_Y = SCREEN_HEIGHT/2+100;

const int SCORE_X = SCREEN_WIDTH/2;
const int SCORE_Y = SCREEN_HEIGHT/2-85;

const std::string SCREEN_BEGIN_IMG = "../Image/Screen/screen_begin.png";
const std::string SCREEN_END_IMG = "../Image/Screen/screen_end.png";
const std::string SCREEN_CHOOSE_IMG = "../Image/Screen/screen_choose.png";
const std::string SCREEN_PAUSE_IMG = "../Image/Screen/screen_pause.png";
const std::string SCREEN_TUTORIAL_IMG = "../Image/Screen/screen_tutarial.png";

const std::string PLAY_CHOOSEN_IMG = "../Image/Screen/play_choosen.png";
const std::string PLAY_UNCHOOSE_IMG = "../Image/Screen/play_unchoose.png";

const std::string REPLAY_CHOOSEN_IMG = "../Image/Screen/replay_choosen.png";
const std::string REPLAY_UNCHOOSE_IMG = "../Image/Screen/replay_unchoose.png";

const std::string EGGBIRD_CHOOSEN_IMG = "../Image/Screen/eggbird_choosen.png";
const std::string EGGBIRD_UNCHOOSE_IMG = "../Image/Screen/eggbird_unchoose.png";

const std::string UNICORNBIRD_CHOOSEN_IMG = "../Image/Screen/unicornbird_choosen.png";
const std::string UNICORNBIRD_UNCHOOSE_IMG = "../Image/Screen/unicornbird_unchoose.png";

const std::string VOLUME_CHOOSEN_IMG = "../Image/Screen/music_on.png";
const std::string VOLUME_UNCHOOSE_IMG = "../Image/Screen/music_off.png";

const std::string NEXT_CHOOSEN_IMG = "../Image/Screen/next_choosen.png";
const std::string NEXT_UNCHOOSE_IMG = "../Image/Screen/next_unchoose.png";

const std::string EXIT_CHOOSEN_IMG = "../Image/Screen/exit_on.png";
const std::string EXIT_UNCHOOSE_IMG = "../Image/Screen/exit_off.png";

struct Menu {

    Sound pick;
    int score = 0;

    SDL_Texture* screen_begin;
    bool choose_play;
    SDL_Texture* play_choosen;
    SDL_Texture* play_unchoose;
    bool choose_volume;
    SDL_Texture* volume_choosen;
    SDL_Texture* volume_unchoose;
    bool choose_exit;
    SDL_Texture* exit_choosen;
    SDL_Texture* exit_unchoose;

    SDL_Texture* screen_end;
    bool choose_replay;
    SDL_Texture* replay_choosen;
    SDL_Texture* replay_unchoose;

    SDL_Texture* screen_choose;
    bool choose_bird1;
    SDL_Texture* bird1_choosen;
    SDL_Texture* bird1_unchoose;
    bool choose_bird2;
    SDL_Texture* bird2_choosen;
    SDL_Texture* bird2_unchoose;

    // bool choose_bird1;
    // SDL_Texture* eggbird_choosen;
    // SDL_Texture* eggbird_unchoose;
    // bool choose_unicornbird;
    // SDL_Texture* unicornbird_choosen;
    // SDL_Texture* unicornbird_unchoose;

    Menu();
    ~Menu();

    bool check_mouse(int pos_x, int pos_y);
    bool check_mouse(int pos_x, int pos_y, int w, int h);

    void initBegin();
    void renderBegin();
    void cleanBegin();

    void initChooseMainBird();
    void renderChooseMainBird();
    void cleanChooseMainBird();

    void initChooseSupportBird();
    void renderChooseSupportBird();

    void initPause();
    void renderPause();

    void initEnd();
    void renderEnd();
    void cleanEnd();
};