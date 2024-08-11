#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h> 
#include "Vector2.h"
#include "types.h"
#include "constants.h"
#include "scene.h"

void swap(int* array, int index1, int index2) {
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

void swapEl(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(scene_t* scene, int* a, int length) {
	for(int i = 0; i < length - 1; i++) {
		for(int j = 0; j < length - i - 1; j++) {
			if(a[j] > a[j + 1]) {
				swap(a, j, j+1);
				drawScene(scene, a, length, j);
			}
		}
	}
}

void insertionSort(scene_t* scene, int* a, int length) {
    for (int i = 1; i < length; ++i) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
			drawScene(scene, a, length, j);
        }
        a[j + 1] = key;
    }
}

int partition(scene_t* scene, int* arr, int low, int high, int length) {

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(arr, i, j);
			drawScene(scene, arr, length, pivot);
        }
    }
    swap(arr, low, j);
	drawScene(scene, arr, length, pivot);
    return j;
}

void quickSort(scene_t* scene, int arr[], int low, int high, int length) {
    if (low < high) {
        int partitionIndex = partition(scene, arr, low, high, length);

        quickSort(scene, arr, low, partitionIndex - 1, length);
        quickSort(scene, arr, partitionIndex + 1, high, length);
    }
}

void merge(scene_t* scene, int* a, int length, int p, int q, int r) {
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);
	if(scene->exit) 
		return;
	int i, j, k=0, b[length];
	i = p;
	j = q+1;

	while (i <= q && j <= r) {
		if(a[i] < a[j]) {
			b[k] = a[i];
			i++;
		} else {
			b[k] = a[j];
			j++;
		}
		k++;
	}

	while (i <= q) {
		b[k] = a[i];
		i++;
		k++;
	}
	while (j <= r) {
		b[k] = a[j];
		j++;
		k++;
	}

	for(k = p; k <= r; k++) {
		a[k] = b[k-p];
		drawScene(scene, a, length, k);
	}
}

void mergeSort(scene_t* scene, int* a, int length, int p, int r) {
  	int q;
  	if(p < r) {
		q = (p+r)/2;
		mergeSort(scene, a, length, p, q);    
		mergeSort(scene, a, length, q+1, r);  
		merge(scene, a, length, p, q, r);     
	}
}