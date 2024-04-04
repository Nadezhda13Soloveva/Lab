# Отчет по лабораторной работе № 26
## по курсу "Практикум программирования"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Абстрактные типы данных. Рекурсия. Модульное программирование на Си.  
2. **Цель работы**: Составить и отладить модуль определений и модуль реализации для абстрактного типа данных (стека, очереди, списка или дека, в зависимости от варианта). Составить программный модуль, сортирующий экземпляр указанного абстрактного типа данных заданным методом.  
3. **Задание (Вариант №):** Вариант №4-2:  
   Абстрактный тип данных: Линейный список  
   Процедура: Вставка элемента в линейный список, упорядоченный по возрастанию, с сохранением порядка  
   Метод: Сортировка простой вставкой    
5. **Алгоритм решения:**  
   В начале работы программа предлагает пользователю выбрать действие: *1. Вывести отсортированный список, 2. Вставить элемент, 0. Закончить работу*.  
   * Если пользователь ввёл 1, то происходит сортировка данного списка вызовом функции *sortList()* методом простой вставки. Список перебирается с помощью двух указателей current и next: current указывает на текущий элемент списка, а next - на следующий элемент после current. Если значение текущего элемента больше значения следующего элемента, происходит вставка текущего элемента перед следующим элементом. Повторяется проход по списку для всех элементов, пока список не будет отсортирован. Отсортированный список выводится на экран с помощью функции *printList()*.  
   * Если пользователь ввёл 2, то программа запрашивает значение элемента для вставки и осуществялет его вставку вызовом функции *insertInOrder()*, которая проходится по списку, поэлементно сравнивая новый элемент с тем, что в списке, и вставляет его в нужное место.  
   * Если пользователь ввёл 0, то программа заканчивает свою работу.  
 
7. **Тестовые данные:**  

| Входные данные                                 | Выходные данные                             | Описание тестируемого случая      |
|------------------------------------------------|---------------------------------------------|-----------------------------------|
| Выберите действие:                             |                                             | Пример, включающий в себя         |
| 1. Вывести отсортированный список              |                                             | демонстрацию работы всех команд,  |
| 2. Вставка элемента в список                   |                                             | а также наглядно показывающий     |
| 0. Выход                                       |                                             | механизм добавления нового        |
| Введите код действия: 2                        |                                             | элемента.                         |
| Введите значение для вставки: 5                |                                             |                                   |
| Введите код действия: 2                        |                                             |                                   |
| Введите значение для вставки: 3                |                                             |                                   |
| Введите код действия: 2                        |                                             |                                   |
| Введите значение для вставки: 8                |                                             |                                   |
| Введите код действия: 2                        |                                             |                                   |
| Введите значение для вставки: 6                |                                             |                                   |
| Введите код действия: 2                        |                                             |                                   |
| Введите значение для вставки: 1                |                                             |                                   |
| Введите код действия: 2                        |                                             |                                   |
| Введите значение для вставки: 4                |                                             |                                   |
| Введите код действия: 1                        | Отсортированный список: 1 3 4 5 6 8         |                                   |
| Введите код действия: 2                        |                                             |                                   |
| Введите значение для вставки: 2                |                                             |                                   |
| Введите код действия: 1                        | Отсортированный список: 1 2 3 4 5 6 8       |                                   |
| Введите код действия: 2                        |                                             |                                   |
| Введите значение для вставки: 7                |                                             |                                   |
| Введите код действия: 1                        | Отсортированный список: 1 2 3 4 5 6 7 8     |                                   |
| Введите код действия: 0                        | Программа завершена.                        |                                   |


7. **Протокол**:

  
    Модуль определений: [list.h](/list.h)  
  ```
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
  ```

   Модуль реализации: [list.c](/list.c)   
  ```
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
  ```
  Программный модуль: [program.c](/program.c)  
  ```
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

    while (head != NULL) {
         Node *temp = head;
         head = head->next;
         free(temp);
    }
    return 0;
}
  ```

  Листинг работы:  
  ```
hopeee@hopeeenad:~/repository/Lab/lab26$ make
gcc -std=c99 -Wall -pedantic -c program.c
gcc -std=c99 -Wall -pedantic -c list.c
gcc -std=c99 -Wall -pedantic -o program program.o list.o
hopeee@hopeeenad:~/repository/Lab/lab26$ ./program

Выберите действие:
1. Вывести отсортированный список
2. Вставка элемента в список
0. Выход

Введите код действия: 2

Введите значение для вставки: 5

Введите код действия: 2

Введите значение для вставки: 3

Введите код действия: 2

Введите значение для вставки: 8

Введите код действия: 2

Введите значение для вставки: 6

Введите код действия: 2

Введите значение для вставки: 1

Введите код действия: 2

Введите значение для вставки: 4

Введите код действия: 1

Отсортированный список: 1 3 4 5 6 8
Введите код действия: 2

Введите значение для вставки: 2

Введите код действия: 1

Отсортированный список: 1 2 3 4 5 6 8
Введите код действия: 2

Введите значение для вставки: 7

Введите код действия: 1

Отсортированный список: 1 2 3 4 5 6 7 8
Введите код действия: 0

Программа завершена.
hopeee@hopeeenad:~/repository/Lab/lab26$ ./program

Выберите действие:
1. Вывести отсортированный список
2. Вставка элемента в список
0. Выход

Введите код действия: 4

Некорректный выбор. Попробуйте снова.

Введите код действия: 1

Отсортированный список:
  ```
  
7. **Вывод:** В процессе работы научились определять и реализовывать абстрактые типы данных и действия с ними, познакомились с новыми методами сортировки и найчились их применять на Си. В целом, работа была несложная и интересная, всегда бы так, а не этот ваш КП6.  
Итог: 8/10.   