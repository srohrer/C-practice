#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "randinputs.h"

#define MAX_NUM_SIZE 20

typedef struct tree {
	struct tree *left;
	struct tree *right;
	int data;
} tree;

int append_n(char **str, int n, int memsize) {
	char newstr[MAX_NUM_SIZE + 2] = { 0 };

	int newlen = 1;
	for (int i = n; i > 0; i = i / 10) {
		newlen++;
	}

	sprintf(newstr, "%d ", n);

	int newmem = memsize;

	while (newmem < strlen(*str) + strlen(newstr)) {
		newmem = newmem * 2;
	}

	if (newmem != memsize) {
		*str = realloc(*str, newmem);
	}

	strcat(*str, newstr);
}

void free_tree(tree* tre) {
	if (!tre) {
		return;
	}
	free_tree(tre->left);
	free_tree(tre->right);
	free(tre);
}

int search(tree *tre, int n) {
	if (!tre) {
		return 0;
	}

	if (tre->data == n) {
		return 1;
	}
	if (n > tre->data) {
		return search(tre->right, n);
	}
	if (n < tre->data) {
		return search(tre->left, n);
	}
	return 0;
}

//returns -1 for error, 1 for already present in tree, 0 for successful insert
int insert(tree **tre, int n) {
	if (!tre) {
		return -1;
	}

	if (!(*tre)) {
		*tre = malloc(sizeof(tree));
		(*tre)->left = NULL;
		(*tre)->right = NULL;
		(*tre)->data = n;
		return 0;
	}

	if (n == (*tre)->data) {
		return 1;
	}
	if (n > (*tre)->data) {
		return insert(&((*tre)->right), n);
	}
	if (n < (*tre)->data) {
		return insert(&((*tre)->left), n);
	}

	return -1;
}

void pretraverse(char* str, int* memsize, tree *tre) {
	if (!tre) {
		return;
	}

	*memsize = append_n(&str, tre->data, *memsize);
	pretraverse(str, memsize, tre->left);
	pretraverse(str, memsize, tre->right);
}

char *preorder(tree *tre) {
	char *result = malloc(sizeof(char) * 10);
	result[0] = '\0';
	int memsize = 10;

	pretraverse(result, &memsize, tre);

	return result;
}

void intraverse(char* str, int* memsize, tree *tre) {
	if (!tre) {
		return;
	}

	intraverse(str, memsize, tre->left);
	*memsize = append_n(&str, tre->data, *memsize);
	intraverse(str, memsize, tre->right);
}

char *inorder(tree *tre) {
	char *result = malloc(sizeof(char) * 10);
	result[0] = '\0';
	int memsize = 10;

	intraverse(result, &memsize, tre);

	return result;
}

void postraverse(char* str, int* memsize, tree *tre) {
	if (!tre) {
		return;
	}

	postraverse(str, memsize, tre->left);
	postraverse(str, memsize, tre->right);
	*memsize = append_n(&str, tre->data, *memsize);
}

char *postorder(tree *tre) {
	char *result = malloc(sizeof(char) * 10);
	result[0] = '\0';
	int memsize = 10;

	postraverse(result, &memsize, tre);

	return result;
}

int main() {
	tree *tre = NULL;

	int_output* inputs = randinput(10,25, 0, 100);

	for (int i = 0; i < inputs->len; i++) {
		insert(&tre, (inputs->array)[i]);
	}

	printf("preorder : %s\n", preorder(tre));
	printf("inorder : %s\n", inorder(tre));
	printf("postorder : %s\n", postorder(tre));
}