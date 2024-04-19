#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

// Инициализация итератора
void initIterator(Iterator* iterator, CircularLinkedList* list) {
    iterator->current = list->head;
}

// Переход к следующему элементу
int getNext(Iterator* iter) {
    int value = iter->current->data;
    iter->current = iter->current->next;
    return value;
}

// Получение значения текущего элемента
int getValue(Iterator* iterator) {
    return iterator->current->data;
}

// Проверка на конец списка
int isEnd(Iterator* iterator, CircularLinkedList* list) {
    return iterator->current == list->tail;
}