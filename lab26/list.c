#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void insertInOrder(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

void sortList(Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        // Список пуст или содержит только один элемент, он уже отсортирован
        return;
    }

    Node *sorted = NULL;
    Node *current = *head;

    while (current != NULL) {
        Node *next = current->next;

        // Извлекаем текущий узел из исходного списка
        current->next = NULL;

        Node *temp = sorted;
        Node *prev = NULL;

        // Ищем место для вставки текущего узла в отсортированный список
        while (temp != NULL && temp->data < current->data) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == NULL) {
            // Вставка в начало отсортированного списка
            current->next = sorted;
            sorted = current;
        } else {
            // Вставка в середину или конец отсортированного списка
            prev->next = current;
            current->next = temp;
        }

        current = next;
    }

    *head = sorted; // Обновляем указатель на голову
}