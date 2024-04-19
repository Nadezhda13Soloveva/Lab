#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void deleteList(CircularLinkedList* list) {
    Node* current = list->head;
    Node* next;
    
    if (list->head == NULL) {
        return;
    }
    
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != list->head);

    list->head = NULL;
    list->size = 0;
}

// Создание нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Инициализация списка
void initCircularLinkedList(CircularLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Вставка нового элемента в конец списка
void append(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = list->head;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->tail->next = list->head;
    }

    list->size++;
}


// Удаление элемента по значению
void deleteNode(CircularLinkedList* list, int data) {
    if (list->head == NULL) {
        printf("Список пуст\n");
        return;
    }

    Node* current = list->head;
    Node* prev = NULL;

    do {
        if (current->data == data) {
            if (current == list->head) {
                if (list->size == 1) {
                    free(current);
                    list->head = NULL;
                    list->tail = NULL;
                    list->size = 0;
                    return;
                } else {
                    list->head = current->next;
                    list->tail->next = list->head;
                }
            } else {
                prev->next = current->next;
            }

            free(current);
            list->size--;
            return;
        }

        prev = current;
        current = current->next;
    } while (current != list->head);

    printf("Узел с данными %d не найден\n", data);
}


// Подсчет длины списка
int countLength(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Нет элементов\n");
        return 0;
    }
    return list->size;
}

// Обмен элементов
void swapElements(CircularLinkedList* list, int k) {
    if (list->head == NULL) {
        printf("Нет элементов\n");
        return;
    }

    if ((k + 1) < 1 || (k + 1) > list->size) {
        printf("Некорректный параметр\n");
        return;
    }

    if (list->size <= 2) {
        printf("Недостаточно элементов\n");
        return;
    }

    if (k == 0) {
        Node* current = list->head;
        Node* last = list->tail;
        current = current->next;
        int second = current->data;
        current->data = last->data;
        last->data = second;
        return;
        
    }

    int i = 0;
    Node* current = list->head;

    while (i < k - 1) {
        current = current->next;
        i++;
    }

    Node* prev = current;

    while (i < k + 1) {
        current = current->next;
        i++;
    }

    int temp = prev->data;
    prev->data = current->data;
    current->data = temp;
}