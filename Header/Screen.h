#pragma once

#include "Game.h"
#include "Bird.h"

const int CHOOSE_PLAY_X = SCREEN_WIDTH/2;
const int CHOOSE_PLAY_Y = SCREEN_HEIGHT/2;

const int CHOOSE_REPLAY_X = SCREEN_WIDTH/2;
const int CHOOSE_REPLAY_Y = SCREEN_HEIGHT/2;

const int CHOOSE_MUTE_X = SCREEN_WIDTH/10*4;
const int CHOOSE_MUTE_Y = SCREEN_HEIGHT/2;

const int CHOOSE_EXIT_X = SCREEN_WIDTH/10*6;
const int CHOOSE_EXIT_Y = SCREEN_HEIGHT/2;

const int CHOOSE_BIRD_TEXT_X = SCREEN_WIDTH/2;
const int CHOOSE_BIRD_TEXT_Y = SCREEN_HEIGHT/6;

const int CHOOSE_EGGBIRD_X = SCREEN_WIDTH/4;
const int CHOOSE_EGGBIRD_Y = SCREEN_HEIGHT/2;
const int EGGBIRD_CHOOSEN_W = EGGBIRD_REAL_W*2;
const int EGGBIRD_CHOOSEN_H = EGGBIRD_REAL_H*2;

const int CHOOSE_UNICORNBIRD_X = SCREEN_WIDTH/4*3;
const int CHOOSE_UNICORNBIRD_Y = SCREEN_HEIGHT/2;
const int UNICORNBIRD_CHOOSEN_W = UNICORNBIRD_REAL_W*2.5;
const int UNICORNBIRD_CHOOSEN_H = UNICORNBIRD_REAL_H*2;

const int CHOOSE_EAGLE_X = SCREEN_WIDTH/4;
const int CHOOSE_EAGLE_Y = SCREEN_HEIGHT/2;
const int EAGLE_CHOOSEN_W = EAGLE_REAL_W*1.5;
const int EAGLE_CHOOSEN_H = EAGLE_REAL_H*1.5;

const int CHOOSE_CHICKEN_X = SCREEN_WIDTH/4*3;
const int CHOOSE_CHICKEN_Y = SCREEN_HEIGHT/2;
const int CHICKEN_CHOOSEN_W = CHICKEN_REAL_W*1.75;
const int CHICKEN_CHOOSEN_H = CHICKEN_REAL_H*1.75;

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

const std::string UNMUTE_IMG = "../Image/Screen/music_on.png";
const std::string MUTE_IMG = "../Image/Screen/music_off.png";

const std::string NEXT_CHOOSEN_IMG = "../Image/Screen/next_choosen.png";
const std::string NEXT_UNCHOOSE_IMG = "../Image/Screen/next_unchoose.png";

const std::string EXIT_CHOOSEN_IMG = "../Image/Screen/exit_choosen.png";
const std::string EXIT_UNCHOOSE_IMG = "../Image/Screen/exit_unchoose.png";

const std::string REPLAY_CHOOSEN_IMG = "../Image/Screen/replay_choosen.png";
const std::string REPLAY_UNCHOOSE_IMG = "../Image/Screen/replay_unchoose.png";

const std::string EGGBIRD_CHOOSEN_IMG = "../Image/Screen/eggbird_choosen.png";
const std::string EGGBIRD_UNCHOOSE_IMG = "../Image/Screen/eggbird_unchoose.png";

const std::string UNICORNBIRD_CHOOSEN_IMG = "../Image/Screen/unicornbird_choosen.png";
const std::string UNICORNBIRD_UNCHOOSE_IMG = "../Image/Screen/unicornbird_unchoose.png";

const std::string EAGLE_CHOOSEN_IMG = "../Image/Screen/eagle_choosen.png";
const std::string EAGLE_UNCHOOSE_IMG = "../Image/Screen/eagle_unchoose.png";

const std::string CHICKEN_CHOOSEN_IMG = "../Image/Screen/chicken_choosen.png";
const std::string CHICKEN_UNCHOOSE_IMG = "../Image/Screen/chicken_unchoose.png";

struct Menu {

    Sound pick;
    int score = 0;

    SDL_Texture* screen_begin;
    bool choose_play;
    SDL_Texture* play_choosen;
    SDL_Texture* play_unchoose;
    bool choose_mute;
    bool mute_choosen;
    SDL_Texture* mute;
    SDL_Texture* unmute;
    bool choose_exit;
    SDL_Texture* exit_choosen;
    SDL_Texture* exit_unchoose;

    SDL_Texture* screen_end;
    bool choose_replay;
    SDL_Texture* replay_choosen;
    SDL_Texture* replay_unchoose;

    SDL_Texture* screen_choose;

    bool choose_eggbird;
    SDL_Texture* eggbird_choosen;
    SDL_Texture* eggbird_unchoose;
    bool choose_unicornbird;
    SDL_Texture* unicornbird_choosen;
    SDL_Texture* unicornbird_unchoose;

    bool choose_eagle;
    SDL_Texture* eagle_choosen;
    SDL_Texture* eagle_unchoose;
    bool choose_chicken;
    SDL_Texture* chicken_choosen;
    SDL_Texture* chicken_unchoose;

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
    void cleanChooseSupportBird();

    void initPause();
    void renderPause();

    void initEnd();
    void renderEnd();
    void cleanEnd();
};