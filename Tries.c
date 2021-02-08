#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ALPHABETSIZE 26

typedef struct TrieNode {
	struct TrieNode* list[ALPHABETSIZE];
	bool isEndOfWord;
} trienode;

int char_to_int(char letter) {
	return letter - 'a';
}

trienode* create_node() {
	trienode* node = malloc(sizeof(trienode));
	if (node == NULL) {
		printf("Failed to create memory for trienode.\n");
		return NULL;
	}
	for (int i = 0; i < ALPHABETSIZE; i++) {
		node->list[i] = NULL;
	}
	node->isEndOfWord = false;
	return node;
}

trienode* insert(trienode* head, char* string) {
	if (head == NULL) {
		trienode* new_node = create_node();
		head = new_node;
	}
	trienode* temp = head;
	for (int i = 0; i < strlen(string); i++) {
		int index = char_to_int(string[i]);
		if (temp->list[index] == NULL) {
			trienode* new_node = create_node();
			temp->list[index] = new_node;
		}
		temp = temp->list[index];
	}
	temp->isEndOfWord = true;
	return head;
}

bool search(trienode* head, char* string) {
	if (head == NULL) {
		printf("Tries is empty\n");
		return false;
	}
	trienode* temp = head;
	for (int i = 0; i < strlen(string); i++) {
		int index = char_to_int(string[i]);
		if (temp->list[index] == NULL) {
			printf("String %s does not exist.\n", string);
			return false;
		}
		temp = temp->list[index];
	}
	if (temp->isEndOfWord == true) {
		printf("Found string %s\n", string);
		return true;
	}
	printf("String %s does not exist.\n", string);
	return false;
}

bool is_list_empty(trienode* head) {
	for (int i = 0; i < ALPHABETSIZE; i++) {
		if (head->list[i] != NULL) {
			return false;
		}
	}
	return true;
}

trienode* remove_string(trienode* head, char* string, int depth) {
	if (!head) {
		printf("String %s does not exist. Pointer does not exist.\n", string);
		return NULL;
	}
	if (strlen(string) == depth) {
		if (!head->isEndOfWord) {
			printf("String %s does not exist. isEndOfWord flag is false.\n", string);
			return NULL;
		}
		else {
			head->isEndOfWord = false;
		}
		// Remove the node if it does not have child nodes
		if (is_list_empty(head)) {
			free(head);
			head = NULL;
		}
		return head;
	}
	int index = char_to_int(string[depth]);
	head->list[index] = remove_string(head->list[index], string, depth + 1);

	// For the node that is not the last nodes
	if (is_list_empty(head) && head->isEndOfWord == false) {
		free(head);
		head = NULL;
	}
	return head;
}

void free_trie(trienode* head) {
	if (head == NULL) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		free_trie(head->list[i]);
	}
	free(head);
	head = NULL;
}

int main() {
	trienode* trie = NULL;
	// insert strings
	trie = insert(trie, "app");
	trie = insert(trie, "apple");
	trie = insert(trie, "bag");
	// perform searches
	printf("\n---Perform searches---\n");
	search(trie, "appl");
	search(trie, "apple");
	search(trie, "bag");
	search(trie, "bat");
	// remove strings
	printf("\n---Remove strings---\n");
	printf("remove string cat\n");
	remove_string(trie, "cat", 0);
	printf("remove string ba\n");
	remove_string(trie, "ba", 0);
	printf("remove string bag\n");
	remove_string(trie, "bag", 0);
	printf("remove string app\n");
	remove_string(trie, "app", 0);
	// perform checks
	printf("\n---Perform checks---\n");
	search(trie, "app");
	search(trie, "apple");
	// free memory
	free_trie(trie);
	return 0;
}