#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char content[256];
	struct Node *next;   
	struct Node *prev;   
} Node;

Node newNode(char content[]) {
	printf("%s\n", "newNode()");
	struct Node new;
	
	strcpy(new.content, content);
	new.next = NULL;
	new.prev = NULL;
	return new;
}

void appendNode(Node prev, Node new) {
	printf("%s\n", "appendNode()");
	prev.next = &new;
	new.prev = &prev;
}

int size(Node head) {
	printf("%s\n", "size()");
	Node next = head;
	int i = 0;
	while (next.next != NULL) {
		next = *next.next;
		i++;
	}
	return i;
}

Node head(Node node) {
	printf("%s\n", "head()");
	Node prev = node;
	while (prev.prev != NULL) {
		prev = *prev.prev;
	}
	return prev;
}

Node tail(Node node) {
	printf("%s\n", "tail()");
	Node next = node;
	while (next.next != NULL) {
		next = *next.next;
	}
	return next;
}

Node at(int index, Node head) {
	printf("%s\n", "at()");
	int i = 0;
	Node current = head;
	while (&current != NULL && i < index) {
		current = *current.next;
		i++;
	}
	return current;
}

const char * pop(char* output, Node head){
	printf("%s\n", "pop()");
	Node newHead = *head.next;
	strcpy(output, head.content);
	newHead.prev = NULL;
	// NOTE: Look into proper memory management
	return output;
}

int findIndex(Node head, char value[]) {
	printf("%s\n", "findIndex()");
	int index = -1;
	Node next = head;
	int count = 0;
	while (&next != NULL) {
		if (next.content == value) {
			return index;
		}
	}
	return index;
}

char *toString(Node head) {
	printf("%s\n", "toString()");
	int len = size(head);
	Node next = head;
	char *buffer = "NULL -> ";
	while (next.next != NULL) {
		asprintf(&buffer, "%s(%s) -> ", buffer, next.content);
		next = *next.next;
	}
	asprintf(&buffer, "%s(%s) -> NULL", buffer, next.content);
	return buffer;
}

int main(int argc, char *argv[])
{
	Node head = newNode("A");
	printf("%s\n", toString(head));

	appendNode(head, newNode("B"));
	printf("%s\n", toString(head));

	return EXIT_SUCCESS;
}
