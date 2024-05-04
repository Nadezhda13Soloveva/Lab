# Отчет по лабораторной работе № 24
## по курсу "Практикум программирования"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Преобразование арифметических выражений с применением деревьев.  
2. **Цель работы**: Составить программу выполнения заданных преобразований арифметических выражений с применением деревьев. Программа должна вводить и печатать выражения в исходном (текстовом) виде, преобразовывать их в деревья, выполнять заданные преобразования путем обращения к подпрограммам и печатать результаты в виде дерева и в текстовом представлении.  
3. **Задание (Вариант №):** Вариант №43:  
   Преобразование: По заданному многочлену от *x* построить выражение, являющееся производной данного многочлена.      
4. **Алгоритм решения:**  
   **ДЕРЕВО:**  
   *Node*: Структура узла дерева выражения.  
   *P.S.: Преобразование в дерево реализовано на основе алгоритма Дейкстры сложностью O(n).*  
   - *Функция newNode()*: Cоздает новый узел с заданным значением.
   - *Функция nextToken()*: Извлекает следующий токен (число или оператор) из строки выражения. Она пропускает пробельные символы и возвращает NULL, если достигнут конец строки.
   - *Функция parseFactor()*: Обрабатывает факторы (числа и выражения в скобках).
   - *Функция parsePower()*: Обрабатывает возведение в степень.
   - *Функция parseTerm()*: Обрабатывает термы (умножение и деление).
   - *Функция parseExpression()*: Обрабатывает выражения (сложение и вычитание).
   - *Функция freeTree()*: Рекурсивно освобождает память, выделенную для дерева разбора.
   - *Функция copyNode()*: Создает копию узла и всего поддерева, которое он представляет.
   - *Функция printTree()*: Печатает дерево визуально, отображая структуру дерева с отступами.  

   **КАЛЬКУЛЯТОР:**  
   *P.S.: Реализован для сокращения исходного многочлена для упрощения нахождения производной.*
   - *Функция parse()*: Эта функция анализирует математическую формулу и разделяет её на лексемы (числа и операторы). Она возвращает массив строк, где каждая строка является лексемой, и устанавливает nlex в количество лексем.
   - *Функция initStacks()*: Инициализирует стеки для чисел (num) и операторов (oper), устанавливая их указатели в начальное положение.
   - *Функции pushNum(double v) и popNum()*: Функции для работы со стеком чисел. pushNum добавляет число в стек, а popNum извлекает последнее число из стека.
   - *Функция isEmptyNum()*: Проверяет, пуст ли стек чисел.
   - *Функция showStack()*: Выводит содержимое стека чисел на экран.
   - *Функции pushOp(char op) и popOp()*: Функции для работы со стеком операторов. pushOp добавляет оператор в стек, а popOp извлекает последний оператор из стека.
   - *Функции isEmptyOp() и peekOp()*: isEmptyOp проверяет, пуст ли стек операторов, а peekOp позволяет посмотреть на верхний элемент стека без его извлечения.
   - *Функция showStackOp()*: Выводит содержимое стека операторов на экран.
   - *Функция prty()*: Возвращает приоритет оператора для выполнения операций в правильном порядке.
   - *Функция exec()*: Выполняет арифметическую операцию между двумя числами с использованием заданного оператора.
   - *Функция calc()*: Вычисляет значение выражения, представленного в виде массива лексем. Использует стеки для обработки операторов и чисел в соответствии с их приоритетами.
   - *Функция calculator()*: Главная функция, которая использует parse для разбиения формулы на лексемы, а затем calc для вычисления результата. Освобождает память после завершения вычислений.

    **Немного про алгоритм Дейкстры:**     
    I. *Чтение элементов: Алгоритм последовательно читает элементы (операнды и операторы) входного выражения.*    
    II. *Обработка операндов: Каждый операнд немедленно добавляется в выходное постфиксное выражение или в соответствующий узел дерева разбора.*    
    III. *Обработка операторов: Операторы добавляются в стек или в дерево с учетом их приоритета. Если оператор имеет более высокий приоритет, чем верхний элемент стека, он помещается на вершину стека. В противном случае операторы из стека добавляются в выходное выражение до тех пор, пока не будет найден оператор с меньшим приоритетом.*    
    IV. *Завершение выражения: После чтения всех элементов входного выражения, оставшиеся операторы из стека добавляются в выходное выражение.*  
     
5. **Тестовые данные/Листинг работы:**  
   ```
    hopeee@hopeeenad:~/repository/Lab/lab24$ make
    gcc -std=c99 -Wall -pedantic -o lab24 lab24.o -lm
    hopeee@hopeeenad:~/repository/Lab/lab24$ valgrind --leak-check=full ./lab24
    ==4398== Memcheck, a memory error detector
    ==4398== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==4398== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
    ==4398== Command: ./lab24
    ==4398==
    Введите многочлен: (8-9)x^(10/2) +0*8x^13 -12/6x^(9-9)
    Сокращенный многочлен: -1*x^5-2*x^0
    
                       0
    
                  ^
    
                       x
    
             *
    
                  2
    
        -
    
                       5
    
                  ^
    
                       x
    
             *
    
                       1
    
                  -
    
    Производная многочлена: -5*x^4
    
                  4
    
             ^
    
                  x
    
        *
    
                  5
    
             -
    
    ==4398==
    ==4398== HEAP SUMMARY:
    ==4398==     in use at exit: 0 bytes in 0 blocks
    ==4398==   total heap usage: 97 allocs, 97 frees, 3,021 bytes allocated
    ==4398==
    ==4398== All heap blocks were freed -- no leaks are possible
    ==4398==
    ==4398== For lists of detected and suppressed errors, rerun with: -s
    ==4398== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    hopeee@hopeeenad:~/repository/Lab/lab24$ make
    gcc -std=c99 -Wall -pedantic -c lab24.c
    gcc -std=c99 -Wall -pedantic -o lab24 lab24.o -lm
    hopeee@hopeeenad:~/repository/Lab/lab24$ valgrind --leak-check=full ./lab24
    ==6999== Memcheck, a memory error detector
    ==6999== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==6999== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
    ==6999== Command: ./lab24
    ==6999==
    Введите многочлен: 6/3x^(2*2) -1/0x^7
    Ошибка: Деление на ноль!
    ==6999==
    ==6999== HEAP SUMMARY:
    ==6999==     in use at exit: 40 bytes in 5 blocks
    ==6999==   total heap usage: 20 allocs, 15 frees, 2,264 bytes allocated
    ==6999==
    ==6999== LEAK SUMMARY:
    ==6999==    definitely lost: 0 bytes in 0 blocks
    ==6999==    indirectly lost: 0 bytes in 0 blocks
    ==6999==      possibly lost: 0 bytes in 0 blocks
    ==6999==    still reachable: 40 bytes in 5 blocks
    ==6999==         suppressed: 0 bytes in 0 blocks
    ==6999== Reachable blocks (those to which a pointer was found) are not shown.
    ==6999== To see them, rerun with: --leak-check=full --show-leak-kinds=all
    ==6999==
    ==6999== For lists of detected and suppressed errors, rerun with: -s
    ==6999== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    hopeee@hopeeenad:~/repository/Lab/lab24$
   ``` 

6. **Протокол**:  
    Программа на Си: [lab24.c](/lab24.c)  
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    #include <math.h>
    
    //КАЛЬКУЛЯТОР
    
    #define MAX_SIZE_LEX 20
    
    double num[100];
    int ptrNum;
    
    char oper[100];
    int ptrOp;
    
    char **parse(char *formula, int *nlex) {
        int fsize = strlen(formula);
        char **lex = (char **)calloc(fsize, sizeof(char *));
        int ptrlex = 0; // номер очередной свободной яч. массива lex
        char tmp[MAX_SIZE_LEX + 1]; // место для очередного числа
        int ptr; // номер очередной св. ячейки
        char a; // очередной символ формулы
        char *v;
        int i, j, cpar = 0, flag = 0;
    
        for (j = 0; j < MAX_SIZE_LEX + 1; j++) tmp[j] = 0;
        ptr = 0;
    
        for (i = 0; i < fsize; i++) {
            a = formula[i]; // взяли очередной символ
    
            switch (a) {
                case '(':
                case ')':
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    // блок контроля скобок
                    if (a == '(') cpar++;
                    if (a == ')') cpar--;
    
                    if (cpar < 0) {
                        flag = 1;
                        break;
                    }
    
                    // нужно взять то, что накоплено в tmp, и перенести в lex
                    // создаем строку в дин. памяти и копируем туда tmp
                    if (ptr > 0) {
                        v = (char *)calloc(ptr + 1, sizeof(char));
                        strcpy(v, tmp);
                        lex[ptrlex++] = v;
    
                        // чистим tmp
                        for (j = 0; j < MAX_SIZE_LEX + 1; j++) tmp[j] = 0;
                        ptr = 0;
                    }
    
                    v = (char *)calloc(2, sizeof(char));
                    v[0] = a;
                    lex[ptrlex++] = v;
    
                    break;
    
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '.':
                    tmp[ptr++] = a; // присоединение оч. символа к числу
            }
    
            if (flag != 0) break;
        }
    
        if ((flag == 0) && (cpar == 0)) {
            // обработка последнего числа
            if (ptr > 0) {
                v = (char *)calloc(ptr + 1, sizeof(char));
                strcpy(v, tmp);
                lex[ptrlex++] = v;
            }
    
            // Вернуть лишнюю память
            lex = realloc(lex, sizeof(char *) * ptrlex);
            *nlex = ptrlex;
    
            return lex;
        } else {
            for (i = 0; i < fsize; i++) free(lex[i]);
            free(lex);
            *nlex = 0;
            return NULL;
        }
    }
    
    void initStacks() {
        ptrNum = 0;
        ptrOp = 0;
    }
    
    void pushNum(double v) {
        num[ptrNum++] = v;
    }
    
    double popNum() {
        double z = num[--ptrNum];
        return z;
    }
    
    int isEmptyNum() {
        return ptrNum == 0;
    }
    
    void showStack() {
        int i;
        printf("\n");
        for (i = 0; i < ptrNum; i++) printf("%2d -> %lf\n", i, num[i]);
        printf("\n");
    }
    
    void pushOp(char op) {
        oper[ptrOp++] = op;
    }
    
    char popOp() {
        char op = oper[--ptrOp];
        return op;
    }
    
    int isEmptyOp() {
        return ptrOp == 0;
    }
    
    char peekOp() {
        return oper[ptrOp - 1];
    }
    
    void showStackOp() {
        int i;
        printf("\n");
        for (i = 0; i < ptrOp; i++) printf("%2d -> %c\n", i, oper[i]);
        printf("\n");
    }
    
    int prty(char op) {
        switch (op) {
            case '(':
                return 0;
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return -1; // Добавлено для обработки неподдерживаемых операций
        }
    }
    
    double exec(double a1, double a2, char op) {
        if (op == '/' && a2 == 0) {
            fprintf(stderr, "Ошибка: Деление на ноль!\n");
            exit(EXIT_FAILURE);
        }
    
        switch (op) {
            case '+':
                return a1 + a2;
            case '-':
                return a1 - a2;
            case '*':
                return a1 * a2;
            case '/':
                return a1 / a2;
            case '^':
                return pow(a1, a2);
            default:
                return 0; // Добавлено возвращение 0 для неподдерживаемых операций
        }
    }
    
    double calc(char **lex, int nlex) {
        int ilex;
        int prty_c, prty_p;
        double a1, a2, r = 0; // Инициализация переменной r
    
        initStacks();
    
        char a, op;
    
        for (ilex = 0; ilex < nlex; ilex++) {
            a = lex[ilex][0]; // Первый символ очередной лексемы
    
            if (((a >= '0') && (a <= '9')) || (a == '.')) { // это число
                r = atof(lex[ilex]);
                pushNum(r);
                continue;
            }
    
            if (a == ')') { // опустошаем стеки до появления (
                while (1) {
                    op = popOp();
                    if (op == '(') break;
                    a2 = popNum();
                    a1 = popNum();
                    r = exec(a1, a2, op);
                    pushNum(r);
                }
                continue;
            }
    
            if ((a == '(') || isEmptyOp()) { // левая скобка или любая первая операция
                pushOp(a);
                continue;
            }
    
            // Операция не первая
            prty_c = prty(a); // приоритет текущей операции
            prty_p = prty(peekOp()); // приоритет вершины стека
    
            if (prty_c > prty_p) { // пришла более приоритетная операция
                pushOp(a);
                continue;
            } else { // не более приоритетная операция
                while (!isEmptyOp() && prty_c <= prty(peekOp())) {
                    op = popOp();
                    a2 = popNum();
                    a1 = popNum();
                    r = exec(a1, a2, op);
                    pushNum(r);
                }
                pushOp(a);
            }
        }
    
        while (!isEmptyOp()) {
            op = popOp();
            a2 = popNum();
            a1 = popNum();
            r = exec(a1, a2, op);
            pushNum(r);
        }
    
        r = popNum();
    
        return r;
    }
    
    double calculator(char *formula) {
        int nlex, i;
        double r = 0; // Инициализация переменной r
        char **lex = parse(formula, &nlex);
    
        if (lex != NULL) { // Проверка на NULL перед использованием
            r = calc(lex, nlex);
    
            // Освобождение динамической памяти
            for (i = 0; i < nlex; i++) free(lex[i]);
            free(lex);
        }
        return r;
    }
    
    //ДЕРЕВО
    
    typedef struct _node {
        struct _node* left;
        struct _node* right;
        char* value;
    } Node;
    
    Node* parseExpression(char** expression);
    Node* parseTerm(char** expression);
    Node* parseFactor(char** expression);
    
    Node* newNode(char* value) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->left = NULL;
        node->right = NULL;
        node->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
        strcpy(node->value, value);
        return node;
    }
    
    char* nextToken(char** expression) {
        while (isspace(**expression)) (*expression)++;
        if (**expression == '\0') return NULL;
    
        int length = 0;
        if (isdigit(**expression)) {
            while (isdigit((*expression)[length])) length++;
        } else {
            length = 1;
        }
    
        char* token = (char*)malloc((length + 1) * sizeof(char));
        strncpy(token, *expression, length);
        token[length] = '\0';
        (*expression) += length;
    
        return token;
    }
    
    Node* parseFactor(char** expression) {
        char* token = nextToken(expression);
        if (token == NULL) return NULL;
        Node* node;
        if (strcmp(token, "(") == 0) {
            node = parseExpression(expression);
            free(token);
            token = nextToken(expression);
            if (token == NULL || strcmp(token, ")") != 0) {
                exit(1);
            }
        } else if (strcmp(token, "-") == 0) {
            node = newNode(token);
            node->right = parseFactor(expression);
        } else {
            node = newNode(token);
        }
        free(token);
        return node;
    }
    
    Node* parsePower(char** expression) {
        Node* node = parseFactor(expression);
        char* token;
        while ((token = nextToken(expression)) != NULL) {
            if (strcmp(token, "^") == 0) {
                Node* right = parseFactor(expression);
                Node* parent = newNode(token);
                parent->left = node;
                parent->right = right;
                node = parent;
            } else {
                (*expression)--;
                free(token);
                break;
            }
            free(token);
        }
        return node;
    }
    
    Node* parseTerm(char** expression) {
        Node* node = parsePower(expression);
        char* token;
        while ((token = nextToken(expression)) != NULL) {
            if (strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
                Node* right = parsePower(expression);
                Node* parent = newNode(token);
                parent->left = node;
                parent->right = right;
                node = parent;
            } else {
                (*expression)--;
                free(token);
                break;
            }
            free(token);
        }
        return node;
    }
    
    Node* parseExpression(char** expression) {
        Node* node = parseTerm(expression);
        char* token;
        while ((token = nextToken(expression)) != NULL) {
            if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0) {
                Node* right = parseTerm(expression);
                Node* parent = newNode(token);
                parent->left = node;
                parent->right = right;
                node = parent;
            } else {
                (*expression)--;
                free(token);
                break;
            }
            free(token);
        }
        return node;
    }
    
    void freeTree(Node* node) {
        if (node == NULL) return;
        freeTree(node->left);
        freeTree(node->right);
        free(node->value);
        free(node);
    }
    
    Node* copyNode(Node* node) {
        if (node == NULL) return NULL;
        Node* newnNode = (Node*)malloc(sizeof(Node));
        newnNode->left = copyNode(node->left);
        newnNode->right = copyNode(node->right);
        newnNode->value = (char*)malloc((strlen(node->value) + 1) * sizeof(char));
        strcpy(newnNode->value, node->value);
        return newnNode;
    }  
    
    void printTree(Node* node, int space){
        if (node == NULL) return;
    
        space += 5;
        printTree(node->right, space);
        printf("\n");
        for (int i = 1; i < space; i++)
            printf(" ");
        printf("%s\n", node->value);
    
        printTree(node->left, space);
    
    }
    
    int main() {
    
    
        int i = 0, j = 0, k = 0;
        char input[100];
        int coeffs[50], degrees[50];
    
        printf("Введите многочлен: ");
        fgets(input, sizeof(input), stdin);
    
        char* token = strtok(input, " ");
    
        while (token != NULL) {
            char coefficient[10], degree[10];
            sscanf(token, "%9[^x]x^%9[^ ]", coefficient, degree);
    
            if (strcmp(coefficient, "") == 0 || strcmp(coefficient, "+") == 0 || strcmp(coefficient, "-") == 0) {
                strcat(coefficient, "1");
            }
    
            if (strcmp(degree, "") == 0) {
                strcat(degree, "1");
            }
    
            int len = strlen(degree);
            if (len > 0 && degree[len - 1] == '\n') {
                degree[len - 1] = '\0';
            }
    
            coeffs[i] = calculator(coefficient);
            degrees[j] = calculator(degree);
    
    
            i++;
            j++;
            token = strtok(NULL, " ");
        }
    
        char expression[100] = "\0";
        char new[100];
        for (k = 0; k < j; k++){
            if (k > 0){
                if (coeffs[k] > 0){
                    strcat(expression, "+");
                }
            }
            if (coeffs[k] != 0){
                snprintf(new, sizeof(new), "%d", coeffs[k]);
                strcat(expression, new);
                strcat(expression, "*x^");
                snprintf(new, sizeof(new), "%d", degrees[k]);
                strcat(expression, new);
            }
        }
        printf("Сокращенный многочлен: %s\n", expression);
        char* p = expression;
        Node* root = parseExpression(&p);
        printTree(root, 0);
        printf("\n"); 
        freeTree(root);
    
        char newexpression[100] = "\0";
        for (k = 0; k < j; k++){
            if (coeffs[k] != 0 && degrees[k] != 0){
                if (k > 0){
                    if (coeffs[k] * degrees[k] > 0){
                        strcat(newexpression, "+");
                    }
                }
                if (degrees[k] != 0){
                    snprintf(new, sizeof(new), "%d", coeffs[k] * degrees[k]);
                    strcat(newexpression, new);
                    if (degrees[k] != 1) {
                    strcat(newexpression, "*x^");
                    snprintf(new, sizeof(new), "%d", degrees[k] - 1);
                    strcat(newexpression, new);
                    }
                }
            }
        }
        printf("Производная многочлена: %s\n", newexpression);
        char* np = newexpression;
        Node* newroot = parseExpression(&np);
        printTree(newroot, 0);
        printf("\n"); 
        freeTree(newroot);
        return 0;
    }
    ```
  
7. **Вывод:** Это было трудно, но мы справились. В процессе научились преобразовывать арифметические выражения в деревья. Работа заняла безумно много времени + то ещё насилие над мозгами в конце семестра => дизлайк. Было бы круто, если бы было больше времени и период зачетной сессии не поджимал.  
Итог: 6/10.   
