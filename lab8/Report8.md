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
  Приветственная программа на Си  [lab8.c](/lab8.c)  
   ```
    #include <stdio.h>

    int main(){
        printf("Hello, Everyone!\n");
        return 0;
    }
   ```
  Visual Studio Command Prompt  
   ``` 
    **********************************************************************
    ** Visual Studio 2019 Developer Command Prompt v16.11.30
    ** Copyright (c) 2021 Microsoft Corporation
    **********************************************************************
    
    C:\Users\user\repository\lab8>notepad lab8.c
    
    C:\Users\user\repository\lab8>cl lab8.c
    Оптимизирующий компилятор Microsoft (R) C/C++ версии 19.29.30152 для x86
    (C) Корпорация Майкрософт (Microsoft Corporation).  Все права защищены.
    
    lab8.c
    lab8.c(1): fatal error C1083: Не удается открыть файл включение: studio.h: No such file or directory,
    
    C:\Users\user\repository\lab8>notepad lab8.c
    
    C:\Users\user\repository\lab8>cl lab8.c
    Оптимизирующий компилятор Microsoft (R) C/C++ версии 19.29.30152 для x86
    (C) Корпорация Майкрософт (Microsoft Corporation).  Все права защищены.
    
    lab8.c
    lab8.c(4): error C2015: слишком много знаков в константе
    
    C:\Users\user\repository\lab8>notepad lab8.c
    
    C:\Users\user\repository\lab8>cl lab8.c
    Оптимизирующий компилятор Microsoft (R) C/C++ версии 19.29.30152 для x86
    (C) Корпорация Майкрософт (Microsoft Corporation).  Все права защищены.
    
    lab8.c
    Microsoft (R) Incremental Linker Version 14.29.30152.0
    Copyright (C) Microsoft Corporation.  All rights reserved.
    
    /out:lab8.exe
    lab8.obj
    
    C:\Users\user\repository\lab8>lab8.exe
    Hello, Everyone!
    
    C:\Users\user\repository\lab8>
```

  5.**Выводы**: В процессе работы научились работать со средой программирования на Си и написали свою первую приветственную программу, её скомпилировали и запустили. Работа понравилась своей относительной простотой и малой времязатратностью.  
  Итог 9/10.
