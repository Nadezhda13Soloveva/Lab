#include <stdio.h>
#include "list.h"

int main() {
    Node *head = NULL;
    int choice;

    printf("\nВыберите действие:\n");
    printf("1. Вывести отсортированный список\n");
    printf("2. Вставка элемента в список\n");
    printf("0. Выход\n");
    do {
        printf("\nВведите код действия: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortList(&head);
                printf("\nОтсортированный список: ");
                printList(head);
                break;
            case 2:
                {
                    int value;
                    printf("\nВведите значение для вставки: ");
                    scanf("%d", &value);
                    insertInOrder(&head, value);
                }
                break;
            case 0:
                printf("\nПрограмма завершена.\n");
                break;
            default:
                printf("\nНекорректный выбор. Попробуйте снова.\n");
        }

    } while (choice != 0);

    return 0;
}