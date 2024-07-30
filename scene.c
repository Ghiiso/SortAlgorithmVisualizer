#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h> 
#include "constants.h"
#include "Vector2.h"
#include "types.h"
#include "scene.h"

void initScene(scene_t* this) {
    this->window = SDL_CreateWindow (
                        "window",
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        SCREEN_WIDTH,
                        SCREEN_HEIGHT,
                        0
                    );
    this->renderer = SDL_CreateRenderer (
                        this->window,
                        -1,
                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
                    );
    this->texture = SDL_CreateTexture (
                        this->renderer,
                        SDL_PIXELFORMAT_ABGR8888,
                        SDL_TEXTUREACCESS_STREAMING,
                        SCREEN_WIDTH,
                        SCREEN_HEIGHT
                    );
    this->camera.position = (Vector2) {0,0}; 
    this->camera.angle = 0;
    this->exit = 0;
}

int vectorToSceneCoords(Vector2 v) {
    return ((SCREEN_WIDTH * v.y) + v.x) % (SCREEN_WIDTH*SCREEN_HEIGHT);
}

void drawPoint(scene_t* scene, point_t point) {
    scene->pixels[vectorToSceneCoords(point.position)] = point.color;
}

void drawRectangle(int x, int y, int width, int height, SDL_Color color, struct SDL_Renderer* renderer) {
    SDL_Rect rectangle;

    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = width;
    rectangle.h = height;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rectangle);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}

void drawRectangles(int* array, int length, int iteration, struct SDL_Renderer* renderer) {
    int totalWidth = SCREEN_WIDTH - 2 * MARGIN;
    int rectSpace = (totalWidth / length) <= MAX_SIZE ? (totalWidth / length) : MAX_SIZE; 

    for(int index = 0; index < length; index++) {
        SDL_Color color = iteration == index ? (SDL_Color) {0, 255, 0, 255} : (SDL_Color) {255, 255, 255, 255};
        drawRectangle (
            MARGIN + rectSpace * index, 
            SCREEN_HEIGHT, 
            rectSpace * (1 - SPACING),
            -array[index] * HEIGHT,
            color,
            renderer
        );
    }
}