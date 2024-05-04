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