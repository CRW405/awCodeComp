#ifndef LL_H
#define LL_H

typedef struct Node {
    char content[256];
    struct Node *next;
} Node;

Node* newNode(char content[]);

void insertNode(Node *prev, Node *newNode, Node *next);
void appendNode(Node *head, Node *newNode);
void prependNode(Node *head, Node *newNode);
Node* head(Node *node);
int size(Node *node);
Node* tail(Node *node);
Node* at(int index, Node *node);
const char * pop(char* output, Node *node);
bool contains(Node *head, char value[]);
int findIndex(Node *node, char value[]);
char *toString(Node *node);
void insertArr(int index, char *arr[], int arrLength, Node *node);
void removeAt(int index, Node *node);

#endif

