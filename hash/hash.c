#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

#define PRIME 3

unsigned hashcode(char *str) {
	unsigned code = 0;

	for (int i = 0; i < strlen(str); i++) {
		code = ((PRIME * code) + (str[i] - '0'));
	}
	return code;
}

Node *newHashMap(int size) {
    Node *hashMap = (Node*)malloc(size * sizeof(Node));
    for (int i = 0; i < size; i++) {
        hashMap[i] = NULL;
    }
    return hashMap;
}

void put(char key[], char val[], Node hashMap[]) {
    unsigned hash = hashcode(key);
    int index = hash % (sizeof(hashMap) / sizeof(hashMap[0]));

    char pair[] = {key, val}
    Node *bucket = hashMap[index];
    Node *entry = newNode(val);

    if (bucket == NULL) {
        bucket = entry;
    } else if (!contains(bucket, val)) {
        appendNode(bucket, newNode(pair));
    } else {
        return;
    }
}

char get(char key[], Node hashMap[]) {
    unsigned hash = hashcode(key);
    int index = hash % (sizeof(hashMap) / sizeof(hashMap[0]));
    
    Node *bucket = hashMap[index];

    if (bucket == NULL) {
        return;
    } else {
        Node *pNext = bucket;
        while (pNext != NULL) {
            if (strcmp(pNext->content, key) == 0) {
                return pNext->content;
            }
            pNext = pNext->pNext;
        }
    }
}

void remove(char key[], Node hashMap[]) {
    unsigned hash = hashcode(key);
    int index = hash % (sizeof(hashMap) / sizeof(hashMap[0]));
    
    Node *bucket = hashMap[index];

    if (bucket == NULL) {
        return;
    } else {
        Node *pNext = bucket;
        while (pNext != NULL) {
            if (strcmp(pNext->content, key) == 0) {
                removeAt(findIndex(bucket, key), bucket);
                return;
            }
            pNext = pNext->pNext;
        }
    }
}

int main(int argc, char *argv[])
{
    printf("=== HASHMAP DEMO ===\n");
    printf("Hashcode for 'hello': %u\n", hashcode("hello"));
    printf("creation and putting\n");
    int size = 10;
    Node pHashMap[size] = newHashMap(size);
    put("hello", "world", pHashMap);
    put("foo", "bar", pHashMap);
    printf("getting\n");
    printf("Value for 'hello': %s\n", get("hello", pHashMap));
    printf("Value for 'foo': %s\n", get("foo", pHashMap));
    // printf("removing\n");
    return EXIT_SUCCESS;
}
