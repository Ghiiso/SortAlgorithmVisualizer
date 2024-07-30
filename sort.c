void swap(int* array, int index1, int index2) {
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

int* bubbleSort(int* array, int length) {
    for(int i = 0; i < length - 1; i++) {
		for(int j = 0; j < length - i - 1; j++) {
			if(array[j] > array[j + 1]) {
				swap(array, j, j+1);
			}
		}
	}
    return array;
}

int bubbleSortStep(int* array, int length) {
	static int i = 0;
	static int j = 0;

	if(i < length) {
		if(j < length - i - 1) {
			if(array[j] > array[j + 1]) {
				swap(array, j, j+1);
			}
			return j++;
		}
		else {
			i++;
			j = 0;
			return j;
		}
	}
	else 
		return -1;
}