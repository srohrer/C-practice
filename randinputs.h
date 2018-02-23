#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct int_output {
	int* array;
	int len;
} int_output;

int_output* randinput(int min, int max, int low, int high, int seed) {
	srand(time(0));

	if (seed != -1) {
		srand(seed);
	}

	int len = min + (rand())%(max - min);

	int_output* result = malloc(sizeof(int_output));

	result->len = len;
	result->array = malloc(sizeof(int) * len);

	printf("Input is : ");

	for (int i = 0; i < len; i++) {
		(result->array)[i] = low + (rand())%(high - low);
		printf("%d ", (result->array)[i]);
	}

	printf("\n");

	return result;
}