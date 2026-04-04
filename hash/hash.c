#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME 7

// nodes for linked lists
typedef struct Node{
    char *key;
    char *val;
    struct Node *next;
} Node;

// main array of ll's
typedef struct HashTable{
    Node **arr;
    int size;
} HashTable;

unsigned hashcode(char *str) {
	unsigned code = 0;

	for (int i = 0; i < strlen(str); i++) {
		code = ((PRIME * code) + (str[i] - '0'));
	}
	return code;
}

HashTable * newTable(int size) {
    HashTable *table = malloc(sizeof(HashTable));
    table->arr = malloc(sizeof(Node) * size);
    table->size = size;

    for (int i = 0; i < size; i++) {
        table->arr[i] = NULL;
    }
    return table;
}

Node * newNode(char *key, char *val) {
    Node *node = malloc(sizeof(Node));
    node->key = strdup(key);
    node->val = strdup(val);
    node->next = NULL;
    return node;
}

void set(HashTable *table, char *key, char *val) {
    unsigned index = hashcode(key) % table->size;
    Node *cur = table->arr[index];

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            cur->val = val;
            return;
        }
        cur = cur->next;
    }

    Node *new = newNode(key, val);
    new->next = table->arr[index];
    table->arr[index] = new;
}

// get

// remove

int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
