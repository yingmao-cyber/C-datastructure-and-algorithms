#include<stdio.h>
#include<stdlib.h>

typedef struct sllnode {
	int number;
	struct sllnode* left;
	struct sllnode* right;
} node;

node* create_node(int value) {
	node* n = malloc(sizeof(node));
	if (!n) {
		printf("Failed to create new memory.\n");
		return n;
	}
	n->number = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

node* insert_node(node* head, int value) {
	node* new_node = create_node(value);
	if (head == NULL) {
		head = new_node;
		return head;
	}
	if (value < head->number) {
		head->left = insert_node(head->left, value);
	}
	else if (value > head->number) {
		head->right = insert_node(head->right, value);
	}
	return head;
}

void insert_node_with_void_output(node** head, int value) {
	node* new_node = create_node(value);
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	if (value < (*head)->number) {
		insert_node_with_void_output(&(*head)->left, value);
	}
	else if (value > (*head)->number) {
		insert_node_with_void_output(&(*head)->right, value);
	}
}

void free_nodes(node* head) {
	if (head == NULL) {
		return;
	}
	free_nodes(head->left);
	free_nodes(head->right);
	free(head);
	head = NULL;
}

void search(node* head, int value) {
	if (head == NULL) {
		printf("Did not find value: %i\n", value);
		return;
	}
	if (head->number == value) {
		printf("Found value: %i\n", value);
		return;
	}
	else if (value < head->number) {
		search(head->left, value);
	}
	else {
		search(head->right, value);
	}
}

int main() {
	/*
	node* tree = NULL;
	tree = insert_node(tree, 4);
	tree = insert_node(tree, 3);
	tree = insert_node(tree, 7);
	tree = insert_node(tree, 9);
	tree = insert_node(tree, 1);
	tree = insert_node(tree, 5);
	tree = insert_node(tree, 10);
	search(tree, 3);
	search(tree, 1);
	search(tree, 9);
	search(tree, 13);
	search(tree, 0);
	search(tree, 6);
	free_nodes(tree);
	*/
	node* tree = NULL;
	insert_node_with_void_output(&tree, 4);
	insert_node_with_void_output(&tree, 3);
	insert_node_with_void_output(&tree, 7);
	insert_node_with_void_output(&tree, 5);
	insert_node_with_void_output(&tree, 6);
	search(tree, 3);
	search(tree, 6);
	search(tree, 0);
	search(tree, 8);
	free_nodes(tree);
	return 0;
}