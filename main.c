#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h> 
#include <time.h>
#include "constants.h"
#include "Vector2.h"
#include "types.h"
#include "scene.h"
#include "sort.h"

void DEBUGPRINTARRAY(int* array, int length) {
    for(int i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {

    int a[] = {79, 85, 83, 5, 25, 34, 36, 38, 61, 89, 9, 68, 18, 86, 43, 35, 42, 59, 94, 47, 98, 2, 49, 99, 90, 21, 48, 69, 91, 6, 55, 45, 3, 15, 32, 76, 64, 82, 88, 39, 30, 62, 16, 84, 33, 46, 87, 22, 66, 20, 26, 23, 92, 77, 73, 44, 51, 31, 67, 80, 41, 52, 17, 1, 50, 28, 10, 13, 74, 70, 56, 78, 93, 75, 63, 72, 57, 12, 53, 24, 19, 40, 65, 71, 14, 54, 60, 37, 4, 96, 97, 95, 81, 29, 7, 11, 8, 58, 27};
    int length = sizeof(a)/sizeof(int);
    int iteration = 0;

    scene_t scene;
    point_t center = (point_t) {(Vector2) {SCREEN_WIDTH/2,SCREEN_HEIGHT/2}, 0xFFFFFF};
    
    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) printf("Error during initialization: %s",SDL_GetError());
    initScene(&scene);
    srand(time(NULL));
    
    // main loop
    while(!scene.exit) {
        const Uint8* keyboard = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) { // event handler
            switch (event.type) {
                case SDL_QUIT:
                    scene.exit = 1;
                    break;
                default:
                    break;
            }
        }
        if(keyboard[SDL_SCANCODE_ESCAPE]) scene.exit = 1;

        SDL_RenderClear(scene.renderer);
            if(keyboard[SDL_SCANCODE_A]) {
                iteration = bubbleSortStep(a, length);
            }
            drawRectangles(a, length, iteration, scene.renderer);
        SDL_RenderPresent(scene.renderer);
    }
    return 0;
}
