# Отчет по лабораторной работе № 12
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Техника работы с целыми числами. Системы счисления.  
2. **Цель работы**: Составить программу на языке Си в целом типе данных, которая для любых допустимых и корректно записанных чисел этого типа в десятичном изображении, поступающих на сандартный ввод программы, выполняет указанное вариантом действие над их значениями. Результатом действия над введенным числом является целое и булевское значение в зависимости от варианта.  
3. **Задание (Вариант №):** Вариант №18: Поменять местами вторую и предпоследнюю цифру   
4. **Протокол**:  

    Программа на Си: [lab12programm.c](/lab12programm.c)  
   ```
    #include <stdio.h>
    #include <string.h>
    
    int main() {
        char number[100];
        char output[100][100];
        int i = 0;
    
        fgets(number, sizeof(number), stdin);
        number[strcspn(number, "\n")] = 0;
    
        while (strcmp(number, "") != 0) {
            char second_symbol = number[1];
            char  prelast_symbol = number[strlen(number)-2];
            number[1] = prelast_symbol;
            number[strlen(number)-2] = second_symbol;
            strcpy(output[i], number);
            i++;
            
            fgets(number, sizeof(number), stdin);
            number[strcspn(number, "\n")] = 0;
        }
    
        for (int j = 0; j < i; j++) {
            printf("%s\n", output[j]);
        }
        return 0;
    }
   ```

    Компиляция:  
   ```
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ cd lab12
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ls
    lab12programm.c  output/  readme.md
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ gcc -o lab12programm lab12programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ./lab12programm
    23566578
    45798070
    346796
    
    27566538
    47798050
    396746
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ cat lab12programm.c
    #include <stdio.h>
    #include <string.h>
    
    int main() {
        char number[100];
        int num;
        char output[100][100];
        int i = 0;
    
        fgets(number, sizeof(number), stdin);
        number[strcspn(number, "\n")] = 0;
    
        while (strcmp(number, "") != 0) {
            char second_symbol = number[1];
            char  prelast_symbol = number[strlen(number)-2];
            number[1] = prelast_symbol;
            number[strlen(number)-2] = second_symbol;
            strcpy(output[i], number);
            i++;
    
            fgets(number, sizeof(number), stdin);
            number[strcspn(number, "\n")] = 0;
        }
    
        for (int j = 0; j < i; j++) {
            printf("%s\n", output[j]);
        }
        return 0;
      }
   user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
   $
  
5. Вывод: В процессе работы закрепили навыки программирования на Си и компиляции программ на этом языке, ознакомились с библиотекой для работы со строками *<string.h>*. В целом работа понравилась, она была в меру сложной и самое главное незамысловатой (в отличие от диаграм Тьюринга, например).  
Итог: 9/10.  
