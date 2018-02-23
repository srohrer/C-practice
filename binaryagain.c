#include <stdio.h>

int *bisearch(int* array, int n, int first, int last) {
	if (first == last) {
		return (n == array[first] ? (array+first) : NULL);
	}

	if (first > last) {
		return NULL;
	}

	int mid = (first + last) / 2;
	int midval = array[mid];

	printf("midval is %d, looking for %d\n", midval, n);

	if (midval == n) {
		return array + first;
	}

	if (midval > n) {
		return bisearch(array, n, first, mid-1);
	}

	if (midval < n) {
		return bisearch(array, n, mid+1, last);
	}

	return NULL;
}

int* binary_search(int* array, int n, int len) {
	return bisearch(array, n, 0, len-1);
}

int main() {
	int testarray[8] = {0, 1, 2, 3, 4, 5, 6 , 7};

	int* result = binary_search(testarray, 0, 8);

	int* secondresult = binary_search(testarray, 7, 8);

	int* thirdresult = binary_search(testarray, 5, 8);

	printf("%lu %lu %lu", (unsigned long int)result, (unsigned long int)secondresult, (unsigned long int)thirdresult);

	return 0;
}