#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct sllnode {
	int number;
	struct sllnode* next;
} node;

node* create_node(int value) {
	node* n = malloc(sizeof(node));
	if (n == NULL) {
		printf("Failed to create new memory.\n");
		return n;
	}
	n->number = value;
	n->next = NULL;
	return n;
}

bool search_iteratively(node* head, int value) {
	node* temp = head;
	int index = 0;
	while (temp != NULL) {
		if (temp->number == value) {
			printf("Found value %i at index %i\n", value, index);
			return true;
		}
		temp = temp->next;
		index++;
	}
	printf("Did not find value %i\n", value);
	return false;
}

bool search_recursively(node* head, int value) {
	if (head == NULL) {
		printf("Did not find value %i\n", value);
		return false;
	}
	if (head->number == value) {
		printf("Found value %i\n", value);
		return true;
	}
	return search_recursively(head->next, value);
}

node* insert(node* head, int value) {
	node* new_node = create_node(value);
	if (head != NULL)
		new_node->next = head;
	head = new_node;
	return head;
}

void print_linked_list(node* head) {
	if (head == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	node* temp = head;
	while (temp != NULL) {
		printf("%i, ", temp->number);
		temp = temp->next;
	}
	printf("\n");
}

void delete_all_nodes_iteratively(node* head) {
	node* temp = head;
	while (temp != NULL) {
		temp = head->next;
		free(head);
		head = temp;
	}
}

void delete_all_nodes_recursively(node* head) {
	if (head == NULL) {
		return;
	}
	delete_all_nodes_recursively(head->next);
	free(head);
}

node* delete_node_at_index(node* head, int index) {
	node* temp = head;
	node* node_to_be_deleted = head;
	if (head == NULL) {
		printf("Linked list is already empty.\n");
		return head;
	}
	if (index == 0) {
		head = temp->next;
		free(temp);
		return head;
	}
	for (int i = 1; i <= index && temp->next != NULL; i++) {
		if (i == index) {
			node_to_be_deleted = temp->next;
			printf("delete elements %i at index %i\n", node_to_be_deleted->number, i);
			temp->next = temp->next->next;
			free(node_to_be_deleted);
			return head;
		}
		temp = temp->next;
	}
	printf("Error: index is out of range.\n");
	return head;
}

node* insert_value_with_index(node* head, int value, int index) {
	// temp is always pointed to one node before the current index except index 0
	// when index is 1, temp will be pointed to the node at index 0
	node* temp = head;
	node* new_node = create_node(value);
	if (index == 0) {
		new_node->next = head;
		head = new_node;
		return head;
	}
	for (int i = 1; i <= index && temp != NULL; i++) {
		if (i == index) {
			new_node->next = temp->next;
			temp->next = new_node;
			return head;
		}
		temp = temp->next;
	}
	printf("Error: index is out of range.\n");
	return head;
}

node* insert_value_to_the_end(node* head, int value) {
	node* temp = head;
	node* new_node = create_node(value);
	if (head == NULL) {
		head = new_node;
		return head;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	return head;
}

int main() {
	node* list = NULL;
	printf("insert elements into lists:\n");
	list = insert(list, 10);
	list = insert_value_to_the_end(list, 20);
	list = insert_value_with_index(list, 30, 1);
	list = insert_value_with_index(list, 40, 0);
	print_linked_list(list);
	printf("\nsearch elements in lists:\n");
	search_iteratively(list, 20);
	search_recursively(list, 50);
	search_recursively(list, 10);
	printf("\ndelete elements from lists:\n");
	delete_node_at_index(list, 9);
	delete_node_at_index(list, 3);
	print_linked_list(list);
	printf("\ndelete all elements from lists.\n");
	//delete_all_nodes_iteratively(list);
	delete_all_nodes_recursively(list);

	return 0;
}