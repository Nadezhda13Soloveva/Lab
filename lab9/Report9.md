# Отчет по лабораторной работе № 9
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Составление и отладка программы на языке Си  
2. **Цель работы**: Составить и отладить программу на языке С итеративного характера с целочисленными рекуррентными соотношениями, задающими некоторое регулярное движение точки в целочисленной системе координат (i, j) с дискретным временем k и динамическим параметром движения l. Программа должна вывести сообщение об итоге движение: попадание в заданную область плоскости не более чем за 50 шагов  время попадания (номер шага, итерации) или сообщение о промахе, также в результат надо включить время окончания движения, конечные координаты точки и значения динамического параметра движения. Начальные данные движения и параметры соотношений задаются в виде констант программы.  
3. **Задание (Вариант №):** Полоса, ограниченная прямыми i + j + 10 = 0 и i + j + 20 = 0

    Вариант №18:  
   - i(0) = 12 ; j(0) = 4 ; l(0) = 3  
   - i(k+1) = (i(k) * j(k) / (|l(k)| + 1) + j(k) * l(k) / (|i(k)| + 1) + i(k) * l(k) / (|j(k)|+ 1) mod 30  
   - j(k+1) = (i(k) * max(j(k), l(k)) mod 20 + j(k) * min(i(k), l(k)) mod 30 - k  
   - l(k+1) = max(i(k) * j(k), i(k) * l(k), j(k) * l(k)) mod 30 + 20  

4. **Протокол**:  

    Программа на Си: [lab9programm.c](/lab9programm.c)

    ```
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #define MIN(a, b) (((a) < (b)) ? (a) : (b))
    #define MAX(a, b) (((a) > (b)) ? (a) : (b))

    const int I = 12;
    const int J = 4;
    const int L_const = 3;

    int main() {
            int i = I;
            int j = J;
            int k = 0;
            int L = L_const;
            int pre_i = i;
            int pre_j = j;
            int pre_L = L;

            while (k < 50) {
                    pre_i = i;
                    pre_j = j;
                    pre_L = L;
                    i = ((pre_i * pre_j / (abs(pre_L) + 1) + pre_j * pre_L / (abs(pre_i) + 1) + pre_i * pre_L / (abs(pre_j) + 1)) % 30);
                    j = (i * MAX(pre_j, pre_L) % 20 + pre_j * MIN(pre_i, pre_L) % 30 - k);
                    L = (MAX(MAX(pre_i * pre_j, pre_i * pre_L), MAX(pre_i * pre_L, pre_j * pre_L)) % 30 + 20);
                    k++;
                    if (i + j + 10 >= 0 && i + j + 20 <= 0) {
                            printf("Точка попала в заданную область плоскости на шаге %d\n", k);
                            printf("Время попадания: %d\n", k);
                            printf("Координаты точки: (%d, %d)\n", i, j);
                            printf("Значение динамического параметра движения: %d\n", L);
                            return 0;
                    };
            };

            printf("Точка не попала в заданную область плоскости за %d шагов\n", 50);
            printf("Время окончания движения: %d\n", 50);
            printf("Координаты точки: (%d, %d)\n", i, j);
            printf("Значение динамического параметра движения: %d\n", L);
            return 0;
    }
    ```
  
  
    Листинг Bash:
    ```

    user@DESKTOP-IL3KD9K MINGW64 ~ (main)
    $ cd repository

    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ cd lab9

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ ls
    lab9programm.c  readme.md

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c:4:11: error: 'j0' redeclared as different kind of symbol
        4 | const int j0 = 4;
          |           ^~
    In file included from lab9programm.c:1:
    C:/Users/user/gcc/x86_64-w64-mingw32/include/math.h:306:24: note: previous declaration of 'j0' with type 'double(double)'
      306 | _CRTIMP double __cdecl j0 (double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
          |                        ^~
    lab9programm.c: In function 'main':
    lab9programm.c:13:35: error: 'l' undeclared (first use in this function)
       13 |                 i = (i * j / (abs(l) + 1) + j * l / (abs(i) + 1) + i * l / (abs(j) + 1)) % 30
          |                                   ^
    lab9programm.c:13:35: note: each undeclared identifier is reported only once for each function it appears in
    lab9programm.c:13:94: error: expected ';' before 'j'
       13 |                 i = (i * j / (abs(l) + 1) + j * l / (abs(i) + 1) + i * l / (abs(j) + 1)) % 30
          |                                                                                              ^
          |                                                                                              ;
       14 |                 j = i * max(j, l) % 20 + j * min(i, l) % 30 - k
          |                 ~                                                       
    lab9programm.c:26:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
       26 |     printf("Точка не попала в заданную область плоскости за %d шагов\n", 50);
          |     ^~~~~~
    lab9programm.c:2:1: note: include '<stdio.h>' or provide a declaration of 'printf'
        1 |  #include <math.h>
      +++ |+#include <stdio.h>
        2 |
    lab9programm.c:26:5: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
       26 |     printf("Точка не попала в заданную область плоскости за %d шагов\n", 50);
          |     ^~~~~~
    lab9programm.c:26:5: note: include '<stdio.h>' or provide a declaration of 'printf'

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c:5:11: error: 'j0' redeclared as different kind of symbol
        5 | const int j0 = 4;
          |           ^~
    In file included from lab9programm.c:1:
    C:/Users/user/gcc/x86_64-w64-mingw32/include/math.h:306:24: note: previous declaration of 'j0' with type 'double(double)'
      306 | _CRTIMP double __cdecl j0 (double) __MINGW_ATTRIB_DEPRECATED_MSVC2005;
          |                        ^~
    lab9programm.c: In function 'main':
    lab9programm.c:14:35: error: 'l' undeclared (first use in this function)
       14 |                 i = (i * j / (abs(l) + 1) + j * l / (abs(i) + 1) + i * l / (abs(j) + 1)) % 30
          |                                   ^
    lab9programm.c:14:35: note: each undeclared identifier is reported only once for each function it appears in
    lab9programm.c:14:94: error: expected ';' before 'j'
       14 |                 i = (i * j / (abs(l) + 1) + j * l / (abs(i) + 1) + i * l / (abs(j) + 1)) % 30
          |                                                                                              ^
          |                                                                                              ;
       15 |                 j = i * max(j, l) % 20 + j * min(i, l) % 30 - k
          |                 ~                                                       

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c:8:1: error: expected ',' or ';' before 'int'
        8 | int main() {
          | ^~~

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c: In function 'main':
    lab9programm.c:14:94: error: expected ';' before 'j'
       14 |                 i = (i * j / (abs(L) + 1) + j * L / (abs(i) + 1) + i * L / (abs(j) + 1)) % 30
          |                                                                                              ^
          |                                                                                              ;
       15 |                 j = i * max(j, L) % 20 + j * min(i, L) % 30 - k
          |                 ~                                                       

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c: In function 'main':
    lab9programm.c:16:25: warning: implicit declaration of function 'max'; did you mean 'fmax'? [-Wimplicit-function-declaration]
       16 |                 j = i * max(j, L) % 20 + j * min(i, L) % 30 - k;
          |                         ^~~
          |                         fmax
    lab9programm.c:16:46: warning: implicit declaration of function 'min'; did you mean 'main'? [-Wimplicit-function-declaration]
       16 |                 j = i * max(j, L) % 20 + j * min(i, L) % 30 - k;
          |                                              ^~~
          |                                              main
    lab9programm.c:17:19: error: assignment of read-only variable 'L'
       17 |                 L = max(i * j, i * L, j * L) % 30 + 20;
          |                   ^

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c: In function 'main':
    lab9programm.c:15:93: error: expected ')' before ';' token
       15 |                 i = (i * j / (abs(L) + 1) + j * L / (abs(i) + 1) + i * Luser@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c: In function 'main':
    lab9programm.c:16:26: warning: implicit declaration of function 'max'; did you mean 'fmax'? [-Wimplicit-function-declaration]
       16 |                 j = (i * max(j, L) % 20 + j * min(i, L) % 30 - k);
          |                          ^~~
          |                          fmax
    lab9programm.c:16:47: warning: implicit declaration of function 'min'; did you mean 'main'? [-Wimplicit-function-declaration]
       16 |                 j = (i * max(j, L) % 20 + j * min(i, L) % 30 - k);
          |                                               ^~~
          |                                               main
    lab9programm.c:17:19: error: assignment of read-only variable 'L'
       17 |                 L = (max(i * j, i * L, j * L) % 30 + 20);
          |                   ^

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c: In function 'main':
    lab9programm.c:19:26: warning: implicit declaration of function 'max'; did you mean 'fmax'? [-Wimplicit-function-declaration]
       19 |                 j = (i * max(j, L) % 20 + j * min(i, L) % 30 - k);
          |                          ^~~
          |                          fmax
    lab9programm.c:19:47: warning: implicit declaration of function 'min'; did you mean 'main'? [-Wimplicit-function-declaration]
       19 |                 j = (i * max(j, L) % 20 + j * min(i, L) % 30 - k);
          |                                               ^~~
          |                                               main
    C:/Users/user/gcc/bin/../lib/gcc/x86_64-w64-mingw32/13.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\user\AppData\Local\Temp\cc4KDwi6.o:lab9programm.c:(.text+0x115): undefined reference to `max'
    C:/Users/user/gcc/bin/../lib/gcc/x86_64-w64-mingw32/13.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\user\AppData\Local\Temp\cc4KDwi6.o:lab9programm.c:(.text+0x152): undefined reference to `min'
    C:/Users/user/gcc/bin/../lib/gcc/x86_64-w64-mingw32/13.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\user\AppData\Local\Temp\cc4KDwi6.o:lab9programm.c:(.text+0x1a3): undefined reference to `max'
    collect2.exe: error: ld returned 1 exit status

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c
    lab9programm.c: In function 'main':
    lab9programm.c:21:45: error: macro "MAX" passed 3 arguments, but takes just 2
       21 |                 L = (MAX(i * j, i * L, j * L) % 30 + 20);
          |                                             ^
    lab9programm.c:5: note: macro "MAX" defined here
        5 | #define MAX(a, b) (((a) > (b)) ? (a) : (b))
          |
    lab9programm.c:21:22: error: 'MAX' undeclared (first use in this function)
       21 |                 L = (MAX(i * j, i * L, j * L) % 30 + 20);
          |                      ^~~
    lab9programm.c:21:22: note: each undeclared identifier is reported only once for each function it appears in
    lab9programm.c:22:45: error: macro "MAX" passed 3 arguments, but takes just 2
       22 |                 L = (MAX(i * j, i * L, j * L) % 30 + 20);
          |                                             ^
    lab9programm.c:5: note: macro "MAX" defined here
        5 | #define MAX(a, b) (((a) > (b)) ? (a) : (b))
          |
    lab9programm.c:37:1: error: expected declaration or statement at end of input
       37 | }
          | ^

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9proramm.c
    cc1.exe: fatal error: lab9proramm.c: No such file or directory
    compilation terminated.

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ ./lab9programm


    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ vim lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ gcc -o lab9programm lab9programm.c

    user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab9 (main)
    $ ./lab9programm
    Точка не попала в заданную область плоскости за 50 шагов
    Время окончания движения: 50
    Координаты точки: (-11, -41)
    Значение динамического параметра движения: 34

    ```


  5.**Выводы**: В процессе работы научились работать со средой программирования на Си и написали свою первую приветственную программу, её скомпилировали и запустили. Работа понравилась своей относительной простотой и малой времязатратностью, если работать в Visual Studio. Для работы с gcc, конечно, пришлось немного помучаться с установкой, но мы всё смогли и выжили.  
Итог 9/10.
