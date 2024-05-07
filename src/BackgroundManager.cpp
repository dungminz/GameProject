#include "../Header/BackgroundManager.h"
#include "../Header/TextureManager.h"


BackgroundManager::BackgroundManager() {}

BackgroundManager::BackgroundManager(typeOfBackground _type, 
                std::string _ground_img, int _frames_layer, 
                                const std::string _clips[])
{
    type = _type;
    ground_img = _ground_img;
    frames_layer = _frames_layer;

    layer_img = new std::string[frames_layer];
    layer_texture = new SDL_Texture*[frames_layer];

    for(int i=0; i<frames_layer; i++)
        layer_img[i] = _clips[i];

    setTexture();
}

BackgroundManager::~BackgroundManager() {

    if(layer_img) delete[] layer_img;
    if(ground_texture) SDL_DestroyTexture(ground_texture);
    
    for(int i=0; i<frames_layer; i++)
        if(layer_texture[i]) SDL_DestroyTexture(layer_texture[i]);
    if(layer_texture) delete[] layer_texture;
}


void BackgroundManager::setTexture() {

    ground_texture = TextureManager::loadTexture(ground_img);

    for(int i=0; i<frames_layer; i++) {
        layer_texture[i] = TextureManager::loadTexture(layer_img[i]);
    }
}