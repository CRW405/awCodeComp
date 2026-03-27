#ifndef LL_H
#define LL_H

typedef struct Node Node;

Node* newNode(char content[]);

void insertNode(Node *prev, Node *new, Node *next);
void appendNode(Node *head, Node *new);
void prependNode(Node *head, Node *new);
Node* head(Node *node);
int size(Node *node);
Node* tail(Node *node);
Node* at(int index, Node *node);
const char * pop(char* output, Node *node);
bool contains(Node *head, char value[]);
int findIndex(Node *node, char value[]);
char *toString(Node *node);
void insertArr(int index, char *arr[], int arrLength, Node *node);
void removeAt(int inedx, Node *node);

#endif

