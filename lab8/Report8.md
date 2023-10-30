# Отчет по лабораторной работе № 8
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Системы программирования на языке Си
2. **Цель работы**: Научиться работать с системой программирования на языке Си с помощью создания приветственной программы.
3. **Задание (Вариант №):**
   - Запустить интерпретатор комнадной строки Microsoft Visual Studio  
   - Запустить редактор текстов  
   - Ввести текст приветственной программы  
   - Скомпилировать программу  
   - Запустить программу  


4. **Протокол**:

  Приветственная программа на Си  [lab8programm.c](/lab8programm.c)  
   ```
    #include <stdio.h>

    int main(){
         printf("Hello, Everyone! This is me first C programm!\n");
         return 0;
    }
   ```
     
  Протокол работы с gcc:  
   ``` 
    user@DESKTOP-IL3KD9K MINGW64 ~ (main)
    $ gcc --version
    gcc.exe (GCC) 13.2.0
    Copyright (C) 2023 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    
    user@DESKTOP-IL3KD9K MINGW64 ~ (main)
    $ which vim
    /usr/bin/vim
    
    user@DESKTOP-IL3KD9K MINGW64 ~ (main)
    $ cd repository
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ ls
     Lab/               'lab 2'/   lab15/         lab7/
     Lab2Listing.md      lab1/     lab2/          lab8/
     Listing2.md         lab10/    lab2test.txt   lab9/
     NewLab2Listing.md   lab11/    lab3/         'n_soliviova@185.5.249.140'
     README.md           lab12/    lab4/
     Report2.md          lab13/    lab5/
     archive.tar         lab14/    lab6/
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ vim lab8programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ ls
     Lab/               'lab 2'/   lab15/         lab7/
     Lab2Listing.md      lab1/     lab2/          lab8/
     Listing2.md         lab10/    lab2test.txt   lab8programm.c
     NewLab2Listing.md   lab11/    lab3/          lab9/
     README.md           lab12/    lab4/         'n_soliviova@185.5.249.140'
     Report2.md          lab13/    lab5/
     archive.tar         lab14/    lab6/
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ cc lab8programm.c
    bash: cc: command not found
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ gcc -std=c99 -Wall -pedantic lab8programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ ./a.out
    bash: ./a.out: No such file or directory
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ gcc -std=c99 -Wall -pedantic lab8programm.c && ./a.out
    bash: ./a.out: No such file or directory
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ ldd ./a.out
    ldd: ./a.out: No such file or directory
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ gcc lab8programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ ./a.out
    bash: ./a.out: No such file or directory
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ gcc -o lab8programm lab8programm.c
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $ ./lab8programm
    Hello, Everyone! This is me first C programm!
    
    user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
    $  

   ```  

   Протокол работы в Visual Studio:
   ```
    **********************************************************************
    ** Visual Studio 2019 Developer Command Prompt v16.11.30
    ** Copyright (c) 2021 Microsoft Corporation
    **********************************************************************
      
    C:\Users\user\repository>cl lab8programm.c
    Оптимизирующий компилятор Microsoft (R) C/C++ версии 19.29.30152 для x86
    (C) Корпорация Майкрософт (Microsoft Corporation).  Все права защищены.
      
    lab8programm.c
    Microsoft (R) Incremental Linker Version 14.29.30152.0
    Copyright (C) Microsoft Corporation.  All rights reserved.
      
    /out:lab8programm.exe
    lab8programm.obj
      
    C:\Users\user\repository>lab8programm.exe
    Hello, Everyone! This is me first C programm!
      
    C:\Users\user\repository>
   ```

  5.**Выводы**: В процессе работы научились работать со средой программирования на Си и написали свою первую приветственную программу, её скомпилировали и запустили. Работа понравилась своей относительной простотой и малой времязатратностью, если работать в Visual Studio. Для работы с gcc, конечно, пришлось немного помучаться с установкой, но мы всё смогли и выжили.  
Итог 9/10.
