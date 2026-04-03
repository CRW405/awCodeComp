#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char content[256];
	struct Node *pNext;
	struct Node *pPrev;
} Node;

Node* pNewNode(char content[]) {
	Node* pNew = (Node*)malloc(sizeof(Node));
	
	strcpy(pNew->content, content);
	pNew->pNext = NULL;
	pNew->pPrev = NULL;
	return pNew;
}

void insertNode(Node *pPrev, Node *pNew, Node *pNext) {
	pPrev->pNext = pNew;
	pNew->pPrev = pPrev;
	if (pNext != NULL) {
		pNew->pNext = pNext;
		pNext->pPrev = pNew;
	}
}

void appendNode(Node *head, Node *pNew) {
	Node *pNext = pHead;
	while (pNext->pNext != NULL) {
		pNext = pNext->pNext;
	}
	insertNode(pNext, pNew, NULL);
}

void prependNode(Node *pHead, Node *pNew) {
	Node *first = pHead;
	while (first->pPrev != NULL) {
		first = first->pPrev;
	}
	pNew->pNext = first;
	first->pPrev = pNew;
}

Node* head(Node *pNode) {
	Node *pPrev = pNode;
	while (pPrev->pPrev != NULL) {
		pPrev = pPrev->pPrev;
	}
	return pPrev;
}

int size(Node *pNode) {
	Node *pNext = head(pNode);
	int i = 1;
	while (pNext->pNext != NULL) {
		pNext = pNext->pNext;
		i++;
	}
	return i;
}

Node* tail(Node *pNode) {
	Node *pNext = pNode;
	while (pNext->pNext != NULL) {
		pNext = pNext->pNext;
	}
	return pNext;
}

Node* at(int index, Node *pNode) {
	int i = 0;
	Node *pCurrent = head(pNode);
	while (pCurrent != NULL && i < index) {
		pCurrent = pCurrent->pNext;
		i++;
	}
	return pCurrent;
}

const char * pop(char* output, Node *pNode){
	Node *ppBeginning = head(pNode);
	Node *pNewHead = pBeginning->pNext;
	strcpy(output, pBeginning->content);
	pNewHead->pPrev = NULL;
	free(pBeginning);
	return output;
}

bool contains(Node *pHead, char value[]) {
	Node *pNext = pHead;
	while (pNext != NULL) {
		if (strcmp(pNext->content, value) == 0) {
			return true;
		}
		pNext = pNext->pNext;
	}
	return false;
}

int findIndex(Node *pNode, char value[]) {
	int index = 0;
	Node *pNext = head(pNode);
	while (pNext != NULL) {
		if (strcmp(pNext->content, value) == 0) {
			return index;
		}
		pNext = pNext->pNext;
		index++;
	}

	return -1;
}

char *toString(Node *pNode) {
	Node *pBeginning = head(pNode);
	int len = size(pBeginning);
	Node *pNext = pBeginning;
	char *buffer = "";
	while (pNext->pNext != NULL) {
		asprintf(&buffer, "%s(%s) -> ", buffer, pNext->content);
		pNext = pNext->pNext;
	}
	asprintf(&buffer, "%s(%s) -> NULL", buffer, pNext->content);
	return buffer;
}

void insertArr(int index, char *arr[], int arrLength, Node *pNode) {
	Node *pPrev = at(index, pNode);
	Node *pNext = pPrev->pNext;
	Node *pNew;

	for (int i = 0; i < arrLength; i++) {
		pNew = pNewNode(arr[i]);
		pPrev->pNext = pNew;
		pNew->pPrev = pPrev;
		pPrev = pNew;
	}
	pNew->pNext = pNext;
}

void removeAt(int index, Node *pNode) {
	Node *remove = at(index, pNode);
	Node *pPrev = remove->pPrev;
	Node *pNext = remove->pNext;

	pPrev->pNext = pNext;
	pNext->pPrev = pPrev;
	
	free(remove);
}
