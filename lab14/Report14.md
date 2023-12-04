# Отчет по лабораторной работе № 14
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Вложенные циклы с параметрами. Обход и линеаризация матриц. 
2. **Цель работы**: Составить программу ввода квадратной матрицы и печати в строку всех её элементов в заданном порядке следования ("улиточка").
3. **Задание (Вариант №):**
   Вариант №10:
     7 6 2 1
     13 8 5 3
     14 12 9 4
     16 15 11 10
5. **Алгоритм решения:**
   - Считываем число - размер нашей матрицы N.
   - Создаю матрицы вычисленного размера N x N.
   - Далее считываю N*N чисел для матрицы из N строк и N столбцов и записываю их в неё.
   - Далее вывожу числа верхнего ряда, правого столбца, нижнего ряда, левого столбца, соответственно сокращая их размеры.
6. **Тестовые данные:**

| Входные данные | Выходные данные                                       | Описание тестируемого случая |
|----------------|-------------------------------------------------------|------------------------------|
| 4              |                                                       |                              |
| 1 2 3 4        |                                                       |                              |
| 21 22 23 24    | Elements: 1 2 3 4 24 34 44 43 42 41 31 21 22 23 33 32 | Пример для квадратной        |
| 31 32 33 34    |                                                       | матрицы 4-го порядка.        |
| 41 42 43 44    |                                                       |                              |
   
7. **Протокол**:

    Программа на Си: [14.c](/14.c)  
```
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  
  int main(void) {
  
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
              }
          }
  
          printf("Elements: ");
  
          int i, j;
          int startRowIndex = 0, endRowIndex = count - 1;
          int startColumnIndex = 0, endColumnIndex = count - 1;
  
          while (startRowIndex <= endRowIndex && startColumnIndex <= endColumnIndex) {
              // Вывод верхней строки
              for (j = startColumnIndex; j <= endColumnIndex; j++) {
                  printf("%d ", matrix[startRowIndex][j]);
              }
              startRowIndex++;
  
              // Вывод правого столбца
              for (i = startRowIndex; i <= endRowIndex; i++) {
                  printf("%d ", matrix[i][endColumnIndex]);
              }
              endColumnIndex--;
  
              // Вывод нижней строки
              if (startRowIndex <= endRowIndex) {
                  for (j = endColumnIndex; j >= startColumnIndex; j--) {
                      printf("%d ", matrix[endRowIndex][j]);
                  }
                  endRowIndex--;
              }
  
              // Вывод левого столбца
              if (startColumnIndex <= endColumnIndex) {
                  for (i = endRowIndex; i >= startRowIndex; i--) {
                      printf("%d ", matrix[i][startColumnIndex]);
                  }
                  startColumnIndex++;
              }
          }
      }
      return 0;
  }

```

  Компиляция:
```
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $ gcc -std=c99 -Wall -pedantic 14.c
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $ ./a
  0
  No elements
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $ ./a
  1
  6
  Elements: 6
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $ ./
  bash: ./: Is a directory
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $ ./a
  2
  4 5
  6 7
  Elements: 4 5 7 6
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $ ./a
  3
  1 2 3
  21 22 23
  31
  32
  33
  Elements: 1 2 3 23 33 32 31 21 22
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $ ./a
  4
  1 2 3 4
  21 22 23 24
  31
  32
  33
  34
  41 42 43 44
  Elements: 1 2 3 4 24 34 44 43 42 41 31 21 22 23 33 32
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab14 (main)
  $

```
  
7. Вывод: В процессе работы закрепили навыки программирования на Си, освоили работу с матрицами. В целом работа понравилось, было интересно работать с матрицами.   
Итог: 8/10.   
