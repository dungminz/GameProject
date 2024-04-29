#include <iostream>
#include "../Header/Game.h"
#include "../Header/DrawTexture.h"
#include "../Header/Bird.h"
#include "../Header/Background.h"

void logErrorAndExit(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s : %s", msg, error);
    SDL_Quit();
}
void waitUntilKeyPressed() {
    SDL_Event e;
    while(true) {
        if(SDL_PollEvent(&e) != 0)
            if(e.type == SDL_KEYDOWN || e.type == SDL_QUIT)
                return;
        SDL_Delay(100);
    }
}

SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;

bool Game::leftPressed = false;
bool Game::rightPressed = false;
bool Game::upPressed = false;
bool Game::downPressed = false;

Bird *bird = nullptr;
Background *background = nullptr;

void Game::init() {
    is_running = true;
    background = new Background();
    if(background) background->init();
        else logErrorAndExit("CreateBackground", SDL_GetError());
    bird = new Bird();
    if(bird) bird->init();
        else logErrorAndExit("CreateBird", SDL_GetError());
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    //Render everything
    background->render();
    bird->render();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    delete background; background = nullptr;
    delete bird; bird = nullptr;
}

void Game::handle_events() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT: is_running = false; break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:  leftPressed=true;  rightPressed=false; break;
                    case SDLK_RIGHT: rightPressed=true; leftPressed=false;  break;
                    case SDLK_UP:    upPressed=true;    downPressed=false;  break;
                    case SDLK_DOWN:  downPressed=true;  upPressed=false;    break;
                    default: break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:  leftPressed=false;  break;
                    case SDLK_RIGHT: rightPressed=false; break;
                    case SDLK_UP:    upPressed=false;    break;
                    case SDLK_DOWN:  downPressed=false;  break;
                    default: break;
                }
                break;
            default: break;
        }
    }
}

void Game::update() {
    background->update();
    bird->update();
}