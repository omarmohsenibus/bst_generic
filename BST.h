#define _CRT_SECURE_NO_WARNINGS
#if !defined BST_H
#define BST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct node {
	void *data;
	struct node *left;
	struct node *right;
};

extern struct node *insert(struct node *tree, void *data, size_t data_size, int(*compare)(void *, void *));



#endif //BST_H