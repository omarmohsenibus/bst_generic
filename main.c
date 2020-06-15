#include "BST.h"

int compare_int(void *a, void *b) {
	int *pa = a;
	int *pb = b;

	return *pa - *pb;
}




int main(void) {
	struct node *bst = NULL;

	int data = 8;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 3;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 1;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 6;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 4;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 7;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 10;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 14;
	bst = insert(bst, &data, sizeof(int), compare_int);
	data = 13;
	bst = insert(bst, &data, sizeof(int), compare_int);

	char buffer[100] = { 0 };
	print(bst, buffer);

	return 0;
}