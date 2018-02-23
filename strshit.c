#include <stdio.h>
#include <string.h>

int strncmpy (char * str1, char * str2, int len) {
	printf("strncmpy\n");

	for (int i = 0; i < len && str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] < str2[i]) {
			return -1;
		}
		if (str1[i] > str2[i]) {
			return 1;
		}
	}

	return 0;
}



char * strstry(char * src, char * target) {

	int srclen = 0;
	int tarlen = 0;

	for (int i = 0; src[i] != '\0'; i++) {
		srclen++;
	}

	for (int i = 0; target[i] != '\0'; i++) {
		tarlen++;
	}

	for (int i = 0; tarlen + i < srclen; i++) {
		if (strncmpy(target, &src[i], tarlen) == 0) {
			return &src[i];
		}
	}

	return "no matching substring\n";
}

int main() {
	/* printf("%i\n", strncmpy("burro", "burrito", 4));
	printf("%i\n", strncmpy("burro", "burrito", 5));
	printf("%i\n", strncmpy("bo", "burrito", 4));
	printf("%i\n", strncmpy("babbb", "babbb", 5));
	printf("%i\n", strncmpy("burro", "burrito", 1));
	printf("%i\n", strncmpy("sam", "bursam", 4));
	printf("%i\n", strncmpy("burro", "burro", 25)); */

	printf("%s\n", strstry("alabobsy", "bob"));

}