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
            if(number[0] == '-') {
                if(strlen(number)>2) {
                    char second_symbol = number[2];
                    char  prelast_symbol = number[strlen(number)-2];
                    number[2] = prelast_symbol;
                    number[strlen(number)-2] = second_symbol;
                }
            }
            else {
                if(strlen(number)>1) {
                    char second_symbol = number[1];
                    char  prelast_symbol = number[strlen(number)-2];
                    number[1] = prelast_symbol;
                    number[strlen(number)-2] = second_symbol;
                }
            }
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
    user@DESKTOP-IL3KD9K MINGW64 ~ (main)
    $ cd repository
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ cd lab12
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ls
    a.exe*  lab12programm.c  output/  readme.md
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ cat lab12programm.c
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
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ gcc -std=c99 -Wall -pedantic lab12programm.c && ./lab12programm
    bash: ./lab12programm: No such file or directory
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ gcc -std=c99 -Wall -pedantic lab12programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ./a.out
    bash: ./a.out: No such file or directory
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ./a
    2137459
    79675641
    0
    666
    7895534226
    
    2537419
    74675691
    0
    666
    7295534286
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ gcc -std=c99 -Wall -pedantic lab12programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ./a
    -128642184632
    -8
    -89
    235863265
    1
    0
    
    -138642184622
    -8
    -98
    265863235
    1
    0
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ gcc -std=c99 -Wall -pedantic lab12programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ./a
    -28364283
    -1
    -123
    89
    3
    789
    34826421
    
    -28364283
    -1
    -123
    98
    3
    789
    32826441
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ gcc -std=c99 -Wall -pedantic lab12programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ./a
    -12864321764
    -236
    -3
    -56
    17425
    789
    67
    5
    
    -16864321724
    -236
    -3
    -56
    12475
    789
    67
    5
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ gcc -std=c99 -Wall -pedantic lab12programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $ ./a
    -275397543
    -567
    -67
    -5
    23576245934
    354
    23
    0
    
    -245397573
    -567
    -76
    -5
    23576245934
    354
    32
    0
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab12 (main)
    $

  
5. Вывод: В процессе работы закрепили навыки программирования на Си и компиляции программ на этом языке, ознакомились с библиотекой для работы со строками *<string.h>*. В целом работа понравилась, она была в меру сложной и самое главное незамысловатой (в отличие от диаграм Тьюринга, например).  
Итог: 9/10.  
