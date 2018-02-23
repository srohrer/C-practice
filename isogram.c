#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "isogram.h"

/* simple recursive solution for when we don't care about stack usage
 *
 * freeing the trees is optional because if stack space is plentiful then the
 * same is probably true for heap space and this is a short-lived program */

#ifdef FREE_TREES
#define free_tree(tree) free_tree(tree)
#else
#define free_tree(tree)
#endif

typedef struct char_node {
    struct char_node *left;
    struct char_node *right;
    char c;
} char_node;

static bool
put_char(char_node **tree, char c) {
    if (tree) {
        if (!*tree) {
            *tree = malloc(sizeof(char_node));
            (*tree)->left = (*tree)->right = NULL;
            (*tree)->c = c;

            return false;
        }
    } else {
        return false;
    }

    return (
        (*tree)->c < c ? put_char(&(*tree)->left, c) :
        (*tree)->c > c ? put_char(&(*tree)->right, c) :
        true
    );
}

#ifdef FREE_TREES
static void
free_tree(char_node **tree) {
    if (tree && *tree) {
        free_tree(&(*tree)->left);
        free_tree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}
#endif

bool
is_isogram(const char * str) {
    char_node *tree = NULL;

    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (
            str[i] != '-' &&
            str[i] != ' ' &&
            put_char(&tree, tolower(str[i]))
        ) {
            free_tree(&tree);
            return false;
        }
    }

    free_tree(&tree);
    return true;
}