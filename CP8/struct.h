#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>
#include <stdlib.h>

// Структура элемента списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Структура для линейного кольцевого списка
typedef struct {
    Node* head;
    Node* tail;
    int size;
} CircularLinkedList;

// Структура для итератора
typedef struct {
    Node* current;
} Iterator;


Node* createNode(int data);
void deleteList(CircularLinkedList* list);
void initCircularLinkedList(CircularLinkedList* list);
void append(CircularLinkedList* list, int data);
void deleteNode(CircularLinkedList* list, int data);
void printList(CircularLinkedList* list);
int countLength(CircularLinkedList* list);
void swapElements(CircularLinkedList* list, int k);

void initIterator(Iterator* iterator, CircularLinkedList* list);
int getNext(Iterator* iterator);
int getValue(Iterator* iterator);
int isEnd(Iterator* iterator, CircularLinkedList* list);

#endif
