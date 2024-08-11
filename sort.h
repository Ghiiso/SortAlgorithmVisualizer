#ifndef _SORT_H
#define _SORT_H

void bubbleSort(scene_t* scene, int* a, int length);
void insertionSort(scene_t* scene, int* a, int length);
void mergeSort(scene_t* scene, int* a, int length, int p, int r);
void quickSort(scene_t* scene, int arr[], int low, int high, int length);
#endif