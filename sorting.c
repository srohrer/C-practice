#include "randinputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct int_heap {
	struct int_heap *left;
	struct int_heap *right;
	int val;
}	int_heap;

void print_array(int* array, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void insert(int* array, int input, int len) {
	int i = 0;

	while(i < len && input > array[i]) {
		i++;
	}

	int prev = input;

	while(i <= len) {
		int tmp = array[i];
		array[i] = prev;
		prev = tmp;
		i++;
	}
}

void insertion_sort(int* input, int len) {
	for (int i = 0; i < len; i++) {
		insert(input, input[i], i);
	}
}

void selects(int* array, int pos, int len) {
	int lowest = pos;

	for(int i = pos; i < len; i++) {
		if (array[i] < array[lowest]) {
			lowest = i;
		}
	}

	int tmp = array[pos];
	array[pos] = array[lowest];
	array[lowest] = tmp;
}

void selection_sort(int* input, int len) {
	for (int i = 0; i < len; i++) {
		selects(input, i, len);
	}
}

void merge(int* input, int pos, int len, int maxlen) {
	if (maxlen - pos <= len) {
		return;
	}

	int mergedlen = len * 2;

	if (maxlen - pos <= len * 2) {
		mergedlen = maxlen - pos;
	}

	int i = pos;
	int j = pos + len;
	int n = 0;

	int* mergedarray = malloc(sizeof(int) * (mergedlen + 1));

	while (n < mergedlen) {
		if (i >= pos + len) {
			mergedarray[n] = input[j];
			n++;
			j++;
			continue;
		}
		if (j >= pos + len*2 || j >= maxlen) {
			mergedarray[n] = input[i];
			n++;
			i++;
			continue;
		}
		if (input[j] < input[i]) {
			mergedarray[n] = input[j];
			n++;
			j++;
			continue;
		}
		if (input[i] <= input[j]) {
			mergedarray[n] = input[i];
			n++;
			i++;
			continue;
		}
	}

	memcpy(&(input[pos]), mergedarray, n*sizeof(int));
	free(mergedarray);
}

void merge_sort(int* input, int len) {
	for (int i = 1; i < len; i = i * 2) {
		for (int j = 0; j < len; j = j + i*2) {
			merge(input, j, i, len);
		}
	}
}

void bubble_sort(int* input, int len) {
	int swaps = 1;
	while(swaps != 0) {
		swaps = 0;
		for (int i = 0; i < len-1; i++) {
			if (input[i] > input[i+1]) {
				int tmp = input[i];
				input[i] = input[i+1];
				input[i+1] = tmp;
				swaps++;
			}
		}
	}
}

int main() {
	int_output* inputs = randinput(10, 30, 0, 100, -1);

	bubble_sort(inputs->array, inputs->len);

	print_array(inputs->array, inputs->len);
}