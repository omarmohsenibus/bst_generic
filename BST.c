#include "BST.h"

struct node *insert(struct node *tree, void *data, size_t data_size, int(*compare)(void *, void *)) {
	if (tree == NULL) {
		struct node *new_node = malloc(sizeof(struct node));
		new_node->data = malloc(data_size);

		memcpy(new_node->data, data, data_size);
		new_node->left = NULL;
		new_node->right = NULL;

		return new_node;
	}

	if (compare(data, tree->data) < 0) { //data < tree->data LEFT
		tree->left = insert(tree->left, data, data_size, compare);
	}
	else if (compare(data, tree->data) > 0) { //data > tree->data RIGHT
		tree->right = insert(tree->right, data, data_size, compare);
	}

	return tree;
}

struct node *search(struct node *tree, void *data, size_t data_size, int(*compare)(void *, void *)){
	if(tree == NULL || compare(tree->data, data) == 0){
		return tree;
	}

	if(compare(data, tree->data) > 0){
		return search(tree->right, data, data_size, compare);
	}

	return search(tree->left, data, data_size, compare);
}

void delete_node(struct node **tree, void *data, size_t data_size, int(*compare)(void *, void *)){
	if(*tree == NULL)	return;

	if(compare(data, (*tree)->data) < 0){ //data > (*tree)->data
		delete_node((*tree)->left, data, data_size, compare);
	} else if(compare(data, (*tree)->data) > 0) { //data > (*tree)->data
		delete_node((*tree)->right, data, data_size, compare);
	} else if(compare(data, (*tree)->data) == 0) {
		if((*tree)->left == NULL){
			struct node *tmp = (*tree)->right;
			free(tree);
			return;
		} else if((*tree)->right == NULL){
			struct node *tmp = *tree;
			return;
		}
	}

}