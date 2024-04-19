#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void printList(CircularLinkedList* list) {
    if (list->head == NULL) {
            printf("Нет элементов\n");
            return;
        }

    Iterator iter;
    initIterator(&iter, list);
    
    for (int i = 0; i < list->size; i++) {
        printf("%d ", getNext(&iter));
    }
    printf("\n");
}

int main() {
    CircularLinkedList list;
    initCircularLinkedList(&list);
    
    int choice, data, k;
    
    do {
        printf("Выберите действие:\n");
        printf("1. Вставить новый элемент в конец списка\n");
        printf("2. Удалить определенный элемент\n");
        printf("3. Печать списка\n");
        printf("4. Подсчет длины списка\n");
        printf("5. Поменять местами (k-1)-й и (k+1)-й элементы\n");
        printf("0. Выйти\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Введите значение нового элемента: ");
                scanf("%d", &data);
                append(&list, data);
                break;
            case 2:
                printf("Введите значение элемента для удаления: ");
                scanf("%d", &data);
                deleteNode(&list, data);
                break;
            case 3:
                printf("Список: ");
                printList(&list);
                break;
            case 4:
                printf("Длина списка: %d\n", countLength(&list));
                break;
            case 5:
                printf("Введите значение параметра k: ");
                scanf("%d", &k);
                k -= 1;
                swapElements(&list, k);
                break;
            case 0:
                deleteList(&list);
                break;
            default:
                printf("Некорректный ввод.\n");
        }
    } while (choice != 0);
    
    return 0;
}