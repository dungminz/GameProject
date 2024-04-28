#include <vector>
#include "Game.h"

// struct Data {
//     SDL_Texture* texture;
//     int flames;
//     vector<SDL_Rect> clips;

//     Data(SDL_Texture* _texture, int _flames, int _clips[][4])
//     :   texture(_texture),
//         flames(_flames),
//     {
//         for(int i=0; i<flames; i++) {
//             clips.x=_clips[i][0];
//             clips
//         }
//     }
// };

struct Sprite {

    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFlame = 0;
    int flames;
    int ticks=0;

    void init(SDL_Texture *_texture, const int flames, const int _clips[][4]);
    void tick();
    void update();
    SDL_Rect *getCurrentClip();

};
