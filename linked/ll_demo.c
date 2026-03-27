#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char content[256];
	struct Node *next;
	struct Node *prev;
} Node;

Node* newNode(char content[]) {
	// printf("%s\n", "newNode()");
	Node* new = (Node*)malloc(sizeof(Node));
	
	strcpy(new->content, content);
	new->next = NULL;
	new->prev = NULL;
	return new;
}

void insertNode(Node *prev, Node *new, Node *next) {
	// printf("%s\n", "insertNode()");
	prev->next = new;
	new->prev = prev;
	if (next != NULL) {
		new->next = next;
		next->prev = new;
	}
}

void appendNode(Node *head, Node *new) {
	// printf("%s\n", "appendNode()");
	Node *next = head;
	while (next->next != NULL) {
		next = next->next;
	}
	insertNode(next, new, NULL);
}

void prependNode(Node *head, Node *new) {
	// printf("%s\n", "prependNode()");
	Node *first = head;
	while (first->prev != NULL) {
		first = first->prev;
	}
	new->next = first;
	first->prev = new;
}

Node* head(Node *node) {
	// printf("%s\n", "head()");
	Node *prev = node;
	while (prev->prev != NULL) {
		prev = prev->prev;
	}
	return prev;
}

int size(Node *node) {
	// printf("%s\n", "size()");
	Node *next = head(node);
	int i = 1;
	while (next->next != NULL) {
		next = next->next;
		i++;
	}
	return i;
}

Node* tail(Node *node) {
	// printf("%s\n", "tail()");
	Node *next = node;
	while (next->next != NULL) {
		next = next->next;
	}
	return next;
}

Node* at(int index, Node *node) {
	// printf("%s\n", "at()");
	int i = 0;
	Node *current = head(node);
	while (current != NULL && i < index) {
		current = current->next;
		i++;
	}
	return current;
}

const char * pop(char* output, Node *node){
	// printf("%s\n", "pop()");
	Node *beginning = head(node);
	Node *newHead = beginning->next;
	strcpy(output, beginning->content);
	newHead->prev = NULL;
	free(beginning);
	return output;
}

bool contains(Node *head, char value[]) {
	// printf("%s\n", "contains()");
	Node *next = head;
	while (next != NULL) {
		if (strcmp(next->content, value) == 0) {
			return true;
		}
		next = next->next;
	}
	return false;
}

int findIndex(Node *node, char value[]) {
	// printf("%s\n", "findIndex()");
	int index = 0;
	Node *next = head(node);
	while (next != NULL) {
		if (strcmp(next->content, value) == 0) {
			return index;
		}
		next = next->next;
		index++;
	}

	return -1;
}

char *toString(Node *node) {
	// printf("%s\n", "toString()");
	Node *beginning = head(node);
	int len = size(beginning);
	Node *next = beginning;
	char *buffer = "";
	while (next->next != NULL) {
		asprintf(&buffer, "%s(%s) -> ", buffer, next->content);
		next = next->next;
	}
	asprintf(&buffer, "%s(%s) -> NULL", buffer, next->content);
	return buffer;
}

void insertArr(int index, char *arr[], int arrLength, Node *node) {
	//printf("insertArr()");
	Node *prev = at(index, node);
	Node *next = prev->next;
	Node *new;

	for (int i = 0; i < arrLength; i++) {
		new = newNode(arr[i]);
		prev->next = new;
		new->prev = prev;
		prev = new;
	}
	new->next = next;
}

void removeAt(int index, Node *node) {
	//printf("removeAt()");
	Node *remove = at(index, node);
	Node *prev = remove->prev;
	Node *next = remove->next;

	prev->next = next;
	next->prev = prev;
	
	free(remove);
}

int main(int argc, char *argv[])
{
	printf("=== LinkedList Demo ===\n\n");
	
	printf("1. Creating list and appending values:\n");
	Node *list = newNode("First");
	appendNode(list, newNode("Second"));
	appendNode(list, newNode("Third"));
	printf("List: %s\n", toString(list));
	printf("Size: %d\n\n", size(list));
	
	printf("2. Prepending a value:\n");
	prependNode(list, newNode("Zero"));
	printf("List after prepend: %s\n", toString(list));
	printf("Size: %d\n\n", size(list));
	
	printf("3. Getting head and tail:\n");
	printf("Head: %s\n", head(list)->content);
	printf("Tail: %s\n", tail(list)->content);
	printf("Size: %d\n\n", size(list));
	
	printf("4. Accessing element at index:\n");
	printf("Element at index 0: %s\n", at(0, list)->content);
	printf("Element at index 2: %s\n", at(2, list)->content);
	printf("Element at index 3: %s\n\n", at(3, list)->content);
	
	printf("5. Checking contains():\n");
	printf("Contains 'Second': %s\n", contains(list, "Second") ? "true" : "false");
	printf("Contains 'Nonexistent': %s\n\n", contains(list, "Nonexistent") ? "true" : "false");
	
	printf("6. Finding index of value:\n");
	printf("Index of 'First': %d\n", findIndex(list, "First"));
	printf("Index of 'Third': %d\n", findIndex(list, "Third"));
	printf("Index of 'Missing': %d\n\n", findIndex(list, "Missing"));
	
	printf("7. Popping head:\n");
	char popped[256];
	pop(popped, list);
	list = list->next;
	printf("Popped: %s\n", popped);
	printf("List after pop: %s\n", toString(list));
	printf("New size: %d\n\n", size(list));

	printf("8. Bonus: Inserting array at index:\n");
	char *inserts[] = {"insert1", "insert2", "insert3"};
	int insertsLength = sizeof(inserts) / sizeof(inserts[0]);
	insertArr(1, inserts, insertsLength, list);
	printf("List after inserting array at index 1: %s\n\n", toString(list));

	printf("9. Bonus: Removing node at index\n");
	removeAt(2, list);
	removeAt(2, list);
	printf("List after removing node at index 2 twice: %s\n", toString(list));

	return EXIT_SUCCESS;
}


