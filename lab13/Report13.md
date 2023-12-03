# Отчет по лабораторной работе № 11
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Программирование на Си. Множества.  
2. **Цель работы**: Входные строки представляют собой последовательность слов, разделенных пробелами, запятыми, табуляциями или гранцами строк. В соответствии с вариантом задания составить программу проверк характеристик введенных последовательностей слов и печати развернутого ответа. В качестве алфавите берется один из европейских алфавитов. 
3. **Задание (Вариант №):** Вариант №2: Есть ли слово, все согласные которого различны?
4. **Алгоритм решения:**
   Исходя из условий, предложенных в методичке, мною было принято решение о взятии латиницы как алфавита для работы.
   Программа работает в виде конечного автомата, который принимает посимвольно значения из потокового ввода и начинает работу в состоянии START. Каждый корректный символ записывается в строку word, которая обновляется для каждого нового слова. Каждое корректное слово, все согласные которого различны, записывается в общую строку res, которая в итоге  выводится.  
   Состояния:  
   - START: Если символ является латинской буквой, то переход в состояние WORD.  
            Иначе, продолжаем искать корректный первый символ.  
   - WORD: Если символ является латинской буквой, то продолжаем принимать значения.  
           Если символ является разделителем (т.е. '\t', '\n', ' ', ','), то значит слово закончилось и оно корректно введено. Далее проверяем, что все его согласные различны. И в таком случае записываем это слово в общую строку с результатами res.  
           Иначе (т.е. введен некорректный символ), переход в состояние SPACE.  
   - SPACE: Если символ является разделителем (т.е. некорректное слово закончилось), то переход в состояние START.  
            Иначе, продолжаем искать разделитель.  
     В программе реализованы следующие функция: is_consonant(), которая проверяет, является ли символ латинской буквой, и is_unique_consonants(), которая проверяет, вляются ли все согласные в слове различными.
6. **Тестовые данные:**

| Входные данные              | Выходные данные                                                     | Описание тестируемого случая                                        |
|-----------------------------|---------------------------------------------------------------------|---------------------------------------------------------------------|
| zoo like mom    phone,dad   |                                                                     |                                                                     |
| stop,problem sister     bro | There are 7 true words: zoo, like, phone, stop, problem, bro, huge. | Пример работы программы с данными, включающими корректные слова.    |
| coconut pizza, huge         |                                                                     |                                                                     |
|                             |                                                                     |                                                                     |
| mommy dad pizza             |                                                                     |                                                                     |
| sister  sausages,egg        | There aren't any true words.                                        | Пример работы программы с данными, не включающими корректные слова. |
| apple,Lizza,people          |                                                                     |                                                                     |

   
7. **Протокол**:

    Программа на Си: [13.c](/13.c)  
  ```
  #include <stdio.h>
  #include <stdbool.h>
  #include <string.h>
  #include <ctype.h>
  
  bool is_consonant(char ch) {
  // проверяю, что буква согласная
      const char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
      for (int i = 0; i < sizeof(consonants) - 1; i++) {
          if (ch == consonants[i]) {
              return true;
          }
      }
      return false;
  }
  
  bool is_unique_consonants(char* word) {
      // проверяю, что все согласные разные
      int len = strlen(word);
      bool is_consonant_used[26] = { 0 };
      for (int i = 0; i < len; i++) {
          if (is_consonant(word[i])) {
              int index = (int)(tolower(word[i]) - 'a');
              if (is_consonant_used[index]) {
                  return false;
              }
              is_consonant_used[index] = true;
          }
      }
      return true;
  }
  
  int main() {
      enum State {
          START,
          WORD,
          SPACE,
      };
      enum State state = START;
  
  
      char word[1000];
      int wordIdx = 0;
      char input;
      int wordCount = 0;
      char res[1000] = {0};
  
      while ((input = getchar()) != EOF) {
          switch (state) {
              case START:
                  if (isalpha(input)) {
                      word[wordIdx] = input;
                      wordIdx++;
                      state = WORD;
                  }
                  break;
  
              case WORD:
                  if (isalpha(input)) {
                      word[wordIdx] = input;
                      wordIdx++;
                  } 
                  else if (isspace(input) || input == '\n' || input == '\t' || input == ',') {
                      word[wordIdx] = '\0';
                      if (is_unique_consonants(word)) {
                          wordCount++;
                          if (wordCount != 1) {
                              strcat(res, ", ");
                          }
                          strcat(res, word);
                      }
                      wordIdx = 0;
                      state = START;
                  }
                  else {
                      wordIdx = 0; 
                      state = SPACE;
                  }   
                  break;
  
              case SPACE:
                  if (isspace(input) || input == '\n' || input == '\t' || input == ',') {
                      state = START;
                  }
                  break;
          }
      }
      if (wordCount == 0) {
          printf("Nere isn't any true words");
      }
      else {
          printf("There is %d true words: %s\n", wordCount, res);
      }
      return 0;
  }
  ```

  Компиляция:  
  ```
  user@DESKTOP-IL3KD9K MINGW64 ~ (main)
  $ cd repository
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
  $ cd lab13
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab13 (main)
  $ gcc -std=c99 -Wall -pedantic 13.c
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab13 (main)
  $ ./a
  mommy dad stop problem
  play    sister,bro,cry
  mystery       giant 23kdfj
  
  There are 7 true words: stop, problem, play, bro, cry, giant, kdfj.
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab13 (main)
  $ ./a
  zoo like mom    phone,dad
  stop,problem sister     bro
  coconut pizza, huge
  
  There are 7 true words: zoo, like, phone, stop, problem, bro, huge.
  
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab13 (main)
  $ ./a
  mommy dad pizza
  sister  sausages,egg
  apple,Lizza,people
  
  There aren't any true words.
  user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab13 (main)

  ```
  
7. Вывод: В процессе работы закрепили навыки программирования на Си и работы с множествами. В целом работа мне очень понравилась, она далась мне не тяжело и содержание работы было лично для меня интересным.  
Итог: 8/10.   
