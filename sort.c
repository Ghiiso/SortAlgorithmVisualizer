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

int insertionSortStep(int* array, int length) {
	static int i = 0;
	static int j = 0;
	static int pivot;
	static int insideWhile = 0;
	if(i < length) {
		if(!insideWhile) {
			pivot = array[i];
			j = i-1;
		}

		if(j >= 0 && array[j] > pivot) {
			insideWhile = 1;
			array[j+1] = array[j];
			j--;
		}
		else {
			insideWhile = 0;
			array[j+1] = pivot;
			i++;
		}
		return j > 0 ? j : 0;
	}
	else 
		return -1;
}