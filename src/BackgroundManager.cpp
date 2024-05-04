#include "../Header/BackgroundManager.h"


void BackgroundManager::setInformation(typeOfBackground _type, 
            std::string _ground_img, int _flames_layer)
{
    type = _type;
    ground_img = _ground_img;
    flames_layer = _flames_layer;
}


void BackgroundManager::setInformation(typeOfBackground _type, 
                    std::string _ground_img, int _flames_layer, 
                                        const std::string _clips[])

{
    type = _type;
    ground_img = _ground_img;
    flames_layer = _flames_layer;
    for(int i=0; i<flames_layer; i++)
        layer_img.push_back(_clips[i]);
}


void BackgroundManager::setGround(SDL_Texture* _ground_texture) {
    ground_texture = _ground_texture;
}

void BackgroundManager::setLayer(SDL_Texture* _layer_texture) {
    layer_texture.push_back(_layer_texture);
}