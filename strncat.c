#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void test1() {
	char buffer[40] = "00000000000000000000000000000000000000";

	char *buf2 = buffer;

	strncpy(buf2, "bufbufbuf", 9);

	char* futurebuf = buf2 + 10;

	strncpy(futurebuf, "bufbufbuf", 9);

	printf("%s\n", buf2);
}

void test2() {
	char buf[16] = "asdf\n";
	char buf2[16] = "asdf\n";

	snprintf(buf+5, 2, "%s", "asdf\n");

	printf("%s\n", buf);
}

char* testexp() {
	return "Gogogo\n";
}

void test3() {
	char buffer[25] = "bufbufbuf";

	strncat(buffer, testexp(), 10);

	printf("%s\n", buffer);
}

void test4() {
	printf("%lu", strlen("bottles of beer"));
}

void test5() {
	char buffer[256] = "Hello my friends";

	memcpy(buffer + strlen(buffer), "Yoyo", 3);

	printf("%s\n", buffer);
}

int main() {
	test5();
	return 0;
}