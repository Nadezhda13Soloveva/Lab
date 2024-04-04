#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

struct Node {
    int data;
    Node *next;
};

void insertInOrder(Node **head, int value);
void printList(Node *head);
void sortList(Node **head);

#endif