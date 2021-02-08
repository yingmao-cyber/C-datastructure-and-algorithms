#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct sllnode {
	char* string;
	struct sllnode* next;
} node;

int generate_hash(char* string) {
	int sum = 0;
	for (int i = 0; i <= strlen(string); i++) {
		sum += string[i];
	}
	return sum % 10;
}

node* create_node(char* string) {
	node* n = malloc(sizeof(node));
	if (n == NULL) {
		printf("Failed to create new memory.\n");
		return NULL;
	}
	n->string = malloc(strlen(string) + 1);
	if (n->string == NULL) {
		printf("Failed to create new memory.\n");
		free(n);
		return NULL;
	}
	strcpy(n->string, string);
	n->next = NULL;
	return n;
}

node* insert(node* list[], char* string) {
	node* new_node = create_node(string);
	if (new_node == NULL) {
		return list;
	}
	int hash_code = generate_hash(string);
	printf("insert string: %s, hash code : %i\n", string, hash_code);
	node* temp = list[hash_code];
	if (temp != NULL)
		new_node->next = temp;
	list[hash_code] = new_node;
	return list;
}

void print_linked_list(node* list[], int index) {
	node* temp = list[index];
	if (temp == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	while (temp != NULL) {
		printf("%s, ", temp->string);
		temp = temp->next;
	}
	printf("\n");
}

void delete_linked_list_iteratively(node* head) {
	node* temp = head;
	while (temp != NULL) {
		free(head->string);
		temp = head->next;
		free(head);
		head = temp;
	}
}

void delete_linked_list_recursively(node* head) {
	if (head == NULL) {
		return;
	}
	delete_linked_list_recursively(head->next);
	free(head->string);
	free(head);
}

void delete_hash_table(node* list[], int list_size) {
	for (int i = 0; i < list_size; i++) {
		delete_linked_list_recursively(list[i]);
	}
}

bool search_linked_list_recursively(node* head, char* string) {
	if (head == NULL) {
		printf("Did not find string %s\n", string);
		return false;
	}
	if (strcmp(head->string, string) == 0) {
		printf("Found string %s\n", string);
		return true;
	}
	return search_linked_list_recursively(head->next, string);
}

void search_hash_table(node* list[], char* string) {
	int hash_code = generate_hash(string);
	printf("search string: %s, hash code : %i\n", string, hash_code);
	search_linked_list_recursively(list[hash_code], string);
}

int main() {
	// intialise list with each node pointed to NULL pointer
	int size = 10;
	node* list[10];
	for (int i = 0; i < size; i++) {
		list[i] = NULL;
	}

	// insert strings into hash table
	insert(list, "apple");
	insert(list, "orange");
	insert(list, "pear");
	insert(list, "peach");
	insert(list, "blueberry");
	insert(list, "strawberry");
	insert(list, "berry");
	insert(list, "mango");
	insert(list, "avocado");
	
	// print hash table
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("row index: %i\n", i);
		print_linked_list(list, i);
	}
	printf("\n");

	// search
	search_hash_table(list, "apple");
	search_hash_table(list, "kiwi");

	// delete all elements
	delete_hash_table(list, size);

	return 0;
}