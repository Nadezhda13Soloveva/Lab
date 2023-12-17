# Отчет по лабораторной работе № 15
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Обработка матриц  
2. **Цель работы**: Составить программу на языке Си, производящую обработку квадратной матрицы порядка NxN (1<=N<=8) из целых чисел.  
3. **Задание (Вариант №):** Вариант №29: Замена всех строк, содержащих максимальный элемент матрицы, на строку с минимальным номером, содержащую минимальный элемент матрицы.  
5. **Алгоритм решения:**
   - Считываю число - размер нашей матрицы N.
   - Создаю матрицу вычисленного размера N x N.
   - Считываю N*N чисел для матрицы из N строк и N столбцов и записываю их в неё. Во время считывания и записи нахожу минимальный элемент, максимальный элемент и минимальный номер сроки, содержащий минимальный элемент.
   - Построчно проверяю на содержание в ней максимального элемента. Если он в ней содержится, то вывожу строку под номером, соответствующим минимальному номеру строки, содержащей минимальный элемент матрицы. Иначе просто вывожу эту строку.  

6. **Тестовые данные:**

| Входные данные | Выходные данные                                       | Описание тестируемого случая    |
|----------------|-------------------------------------------------------|---------------------------------|
| 5              | New matrix:                                           |                                 |
| 13 7 8 5 3     | 9 7 1 4 9                                             |                                 |
| 9 7 1 4 9      | 9 7 1 4 9                                             | Пример для квадратной           |
| 12 11 10 9 13  | 9 7 1 4 9                                             | матрицы 5-го порядка.           |
| 1 2 3 4 5      | 1 2 3 4 5                                             |                                 |
| 4 5 6 7 8      | 4 5 6 7 8                                             |                                 |
|                |                                                       |                                 |
| 0              | No elements                                           | Пример для матрицы 0-го порядка |
|                |                                                       |                                 |
| 1              | New matrix:                                           |                                 |
| 6              | 6                                                     | Пример для матрицы 1-го порядка |

7. **Протокол**:

    Программа на Си: [15.c](/15.c)  
```
   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   
   int main(void) {
       int min_el = 1000000, max_el = -1000000, min_row_with_min = 0;
       int count = 0;
       scanf("%d", &count);
       int matrix[count][count];
       if (count == 0) {
           printf("No elements\n");
       }
       else {
           for (int i = 0; i < count; i++) {
               for (int j = 0; j < count; j++) {
                   scanf("%d", &matrix[i][j]);
                   if (matrix[i][j] < min_el) {
                       min_el = matrix[i][j];
                       min_row_with_min = i;
                   }
                   else if (matrix[i][j] > max_el) {
                       max_el = matrix[i][j];
                   } 
               }
           }
   
           printf("New matrix:\n");
           for (int i = 0; i < count; i++) {
               int find_max = 0;
               for (int j = 0; j < count; j++) {
                   if (matrix[i][j] == max_el) {
                       find_max = 1;
                   }
               }
               if (find_max == 1) {
                   for (int j = 0; j < count; j++) {
                       printf("%d ", matrix[min_row_with_min][j]);
                   }
                   printf("\n");
               }
               else if (find_max == 0) {
                   for (int j = 0; j < count; j++) {
                       printf("%d ", matrix[i][j]);
                   }
                   printf("\n");
               }
           }
   
       }
       return 0;
   }
```

  Компиляция:
```
   user@DESKTOP-IL3KD9K MINGW64 ~ (main)
   $ cd repository
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
   $ cd lab15
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab15 (main)
   $ ls
   15.c  a.exe*  lab15.c  output/  readme.md  test.txt
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab15 (main)
   $ gcc -std=c99 -Wall -pedantic 15.c
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab15 (main)
   $ ./a
   5
   4 5 6 7 8
   13 7 2 3 9
   6 5 4 2 1
   8 9 10 11 13
   1 2 3 4 5
   New matrix:
   4 5 6 7 8
   6 5 4 2 1
   6 5 4 2 1
   6 5 4 2 1
   1 2 3 4 5
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab15 (main)
   $ ./a
   5
   13 7 8 5 3
   9 7 1 4 9
   12 11 10 9 13
   1 2 3 4 5
   4 5 6 7 8
   New matrix:
   9 7 1 4 9
   9 7 1 4 9
   9 7 1 4 9
   1 2 3 4 5
   4 5 6 7 8
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab15 (main)
   $ ./a
   0
   No elements
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab15 (main)
   $ ./a
   1
   6
   New matrix:
   6
   
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab15 (main)
   $


```
  
7. **Вывод:** В процессе работы закрепили навыки программирования на Си, освоили работу с матрицами. В целом работа понравилось, было интересно работать с матрицами.   
   Итог: 9/10.   
