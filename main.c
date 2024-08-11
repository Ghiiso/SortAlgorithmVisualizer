#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h> 
#include <time.h>
#include <string.h>
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

void printHelp() {
    printf("\nAvailable algorithms: \n- \"bubble\"\t bubble sort\n- \"insertion\"\t insertion sort\n- \"merge\"\tmerge sort\n- \"quick\"\tquick sort\n");
}

int getArgvIndex(const char* argv1) {
    const char* ALGORITHMS[] = {"bubble", "insertion", "merge", "quick"};
    int length = sizeof(ALGORITHMS)/sizeof(char*);
    int result = 0;
    while(strcmp(argv1, ALGORITHMS[result]) != 0 && result < length)
        result++;
    return result;
}

int main(int argc, char const *argv[]) {

    int a[] = {
        79, 85, 83, 5, 25, 34, 36, 38, 61, 89, 9, 68, 18, 86, 43, 35, 42, 59, 94, 47,
        98, 2, 49, 99, 90, 21, 48, 69, 91, 6, 55, 45, 3, 15, 32, 76, 64, 82, 88, 39,
        30, 62, 16, 84, 33, 46, 87, 22, 66, 20, 26, 23, 92, 77, 73, 44, 51, 31, 67,
        80, 41, 52, 17, 1, 50, 28, 10, 13, 74, 70, 56, 78, 93, 75, 63, 72, 57, 12, 53, 
        24, 19, 40, 65, 71, 14, 54, 60, 37, 4, 96, 97, 95, 81, 29, 7, 11, 8, 58, 27
    };
    int length = sizeof(a) / sizeof(int);

    scene_t scene;
    point_t center = (point_t) {(Vector2) {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}, 0xFFFFFF};
    
    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) 
        printf("Error during initialization: %s",SDL_GetError());
    initScene(&scene);
    srand(time(NULL));

    switch(argc) {
        case 1:
            printHelp();
            bubbleSort(&scene, a, length);
            break;
        case 2:
            switch(getArgvIndex(argv[1])) {
                case 0:
                    bubbleSort(&scene, a, length);
                    break;
                case 1:
                    insertionSort(&scene, a, length);   
                    break;
                case 2:
                    mergeSort(&scene, a, length, 0, length-1);
                    break;
                case 3:
                    quickSort(&scene, a, 0, length-1, length);
                    break;
                default:
                    printHelp();
                    bubbleSort(&scene, a, length);
            }
            break;
        default:
            printHelp();
            exit(1);
    }

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
        if(keyboard[SDL_SCANCODE_ESCAPE]) 
            scene.exit = 1;
        drawScene(&scene, a, length, -1); // removes green rectangle
    }
    return 0;
}