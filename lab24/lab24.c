#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> 

// Операторы
#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'
#define MOD '%'
#define POW '^'
#define LPAR '('
#define RPAR ')'

// Структура для хранения выражения
typedef struct Expression {
    char *str;
    int len;
} Expression;

// Структура для хранения стека
typedef struct Stack {
    int *data;
    int top;
    int size;
} Stack;

// Инициализация стека
Stack *stack_init(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->data = (int *)malloc(sizeof(int) * size);
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Освобождение памяти, выделенной для стека
void stack_free(Stack *stack) {
    if (stack != NULL) {
        free(stack->data);
        free(stack);
    }
}

// Добавление элемента в стек
void stack_push(Stack *stack, int value) {
    if (stack->top + 1 >= stack->size) {
        stack->size *= 2;
        int *new_data = (int *)realloc(stack->data, sizeof(int) * stack->size);
        if (new_data == NULL) {
            return;
        }
        stack->data = new_data;
    }
    stack->data[++stack->top] = value;
}

// Извлечение элемента из стека
int stack_pop(Stack *stack) {
    if (stack->top == -1) {
        return 0;
    }
    return stack->data[stack->top--];
}

// Проверка стека на пустоту
int stack_empty(Stack *stack) {
    return stack->top == -1;
}

// Получение верхнего элемента стека без его удаления
int stack_peek(Stack *stack) {
    if (stack_empty(stack)) {
        return 0;
    }
    return stack->data[stack->top];
}

// Получение приоритета оператора
int get_precedence(char op) {
    switch (op) {
        case ADD:
        case SUB:
            return 1;
        case MUL:
        case DIV:
        case MOD:
            return 2;
        case POW:
            return 3;
        case LPAR:
        case RPAR:
            return 0;
        default:
            return -1;
    }
}

// Выполнение операции
int perform_operation(char op, int operand1, int operand2) {
    switch (op) {
        case ADD:
            return operand1 + operand2;
        case SUB:
            return operand1 - operand2;
        case MUL:
            return operand1 * operand2;
        case DIV:
            if (operand2 == 0) {
                printf("Ошибка: деление на ноль.\n");
                return 0;
            }
            return operand1 / operand2;
        case MOD:
            if (operand2 == 0) {
                printf("Ошибка: деление на ноль.\n");
                return 0;
            }
            return operand1 % operand2;
        case POW:
            return (int)pow(operand1, operand2);
        default:
            return 0;
    }
}

// Обработка выражения в скобках
int evaluate_parentheses(Expression *expr, int start, int end) {
    Stack *op_stack = stack_init(expr->len);
    Stack *num_stack = stack_init(expr->len);

    for (int i = start + 1; i < end; i++) {
        char c = expr->str[i];

        if (isdigit(c)) {
            int num = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
                c = expr->str[i];
            }
            i--;
            stack_push(num_stack, num);
        } else if (c == LPAR) {
            stack_push(op_stack, LPAR);
        } else if (c == RPAR) {
            while (stack_peek(op_stack) != LPAR) {
                int op = stack_pop(op_stack);
                int operand2 = stack_pop(num_stack);
                int operand1 = stack_pop(num_stack);
                int result = perform_operation(op, operand1, operand2);
                stack_push(num_stack, result);
            }
            stack_pop(op_stack);
        } else if (c == ADD || c == SUB || c == MUL || c == DIV || c == MOD || c == POW) {
            while (!stack_empty(op_stack) && get_precedence(stack_peek(op_stack)) >= get_precedence(c)) {
                int op = stack_pop(op_stack);
                int operand2 = stack_pop(num_stack);
                int operand1 = stack_pop(num_stack);
                int result = perform_operation(op, operand1, operand2);
                stack_push(num_stack, result);
            }
            stack_push(op_stack, c);
        }
    }

    while (!stack_empty(op_stack)) {
        int op = stack_pop(op_stack);
        int operand2 = stack_pop(num_stack);
        int operand1 = stack_pop(num_stack);
        int result = perform_operation(op, operand1, operand2);
        stack_push(num_stack, result);
    }

    int result = stack_pop(num_stack);

    stack_free(op_stack);
    stack_free(num_stack);

    return result;
}

// Оценка выражения
int evaluate_expression(Expression *expr) {
    Stack *op_stack = stack_init(expr->len);
    Stack *num_stack = stack_init(expr->len);

    for (int i = 0; i < expr->len; i++) {
        char c = expr->str[i];

        if (isdigit(c)) {
            int num = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
                c = expr->str[i];
            }
            i--;
            stack_push(num_stack, num);
        } else if (c == LPAR) {
            stack_push(op_stack, LPAR);
        } else if (c == RPAR) {
            while (stack_peek(op_stack) != LPAR) {
                int op = stack_pop(op_stack);
                int operand2 = stack_pop(num_stack);
                int operand1 = stack_pop(num_stack);
                int result = perform_operation(op, operand1, operand2);
                stack_push(num_stack, result);
            }
            stack_pop(op_stack);
        } else if (c == ADD || c == SUB || c == MUL || c == DIV || c == MOD || c == POW) {
            while (!stack_empty(op_stack) && get_precedence(stack_peek(op_stack)) >= get_precedence(c)) {
                int op = stack_pop(op_stack);
                int operand2 = stack_pop(num_stack);
                int operand1 = stack_pop(num_stack);
                int result = perform_operation(op, operand1, operand2);
                stack_push(num_stack, result);
            }
            stack_push(op_stack, c);
        }
    }

    while (!stack_empty(op_stack)) {
        int op = stack_pop(op_stack);
        int operand2 = stack_pop(num_stack);
        int operand1 = stack_pop(num_stack);
        int result = perform_operation(op, operand1, operand2);
        stack_push(num_stack, result);
    }

    int result = stack_pop(num_stack);

    stack_free(op_stack);
    stack_free(num_stack);

    return result;
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
    Node* node = NULL;
    char* token = nextToken(expression);
    if (token == NULL) return NULL;
    
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
    char input[1000];
    int* coeffs = (int*)malloc(50 * sizeof(int));
    int* degrees = (int*)malloc(50 * sizeof(int));

    printf("Введите многочлен: ");
    fgets(input, sizeof(input), stdin);
    

    char* token = strtok(input, " ");

    while (token != NULL) {
        char coefficient[100], degree[100];

        //супер новое

        if (strstr(token, "x") != NULL) {
            if (strstr(token, "x^") != NULL) {
                if (strstr(token, "*x^") != NULL) {                    
                    const char* sub = "*x^";
                    char* pos = strstr(token, sub);
                        
                    // Вычислить длину первой части
                    size_t len1 = pos - token;
                            
                    // Копировать первую часть
                    strncpy(coefficient, token, len1);
                    coefficient[len1] = '\0'; // Добавить нулевой символ в конец строки
                    // Копировать вторую часть
                    strcpy(degree, pos + strlen(sub));

                    //printf("%s\n", coefficient);
                    Expression expr;
                    expr.str = coefficient;
                    expr.len = strlen(coefficient);
                    coeffs[i] = evaluate_expression(&expr);
            
                    degree[strlen(degree)] = '\0';
                    //printf("%s\n", degree); // добавлен завершающий нулевой символ
                    Expression expr1;
                    expr1.str = degree;
                    expr1.len = strlen(degree);
                    degrees[j] = evaluate_expression(&expr1);
                    
                }
                else {
                    sscanf(token, "%*[^x^]x^%s", degree);
                    degree[strlen(degree)] = '\0'; // добавлен завершающий нулевой символ
                    Expression expr1;
                    expr1.str = degree;
                    expr1.len = strlen(degree);
                    degrees[j] = evaluate_expression(&expr1);
                    
                    if (strstr(token, "-x^") != NULL) {
                        coeffs[i] = -1;
                    }
                    else if (strstr(token, "x^") != NULL || strstr(token, "+x^") != NULL) {
                        coeffs[i] = 1;
                    }
                }
            }
            else {
                degrees[j] = 1;
                if (strstr(token, "*x") != NULL) {
                    sscanf(token, "%[^*x]*x", coefficient);
                    coefficient[strlen(coefficient)] = '\0'; // добавлен завершающий нулевой символ
                    Expression expr;
                    expr.str = coefficient;
                    expr.len = strlen(coefficient);
                    coeffs[i] = evaluate_expression(&expr);
                    
                        }
                else{
                    if (strcmp(token, "-x") == 0) {
                        coeffs[i] = -1;
                    }
                    else if (strcmp(token, "+x") == 0 || strcmp(token, "x") == 0) {
                        coeffs[i] = 1;
                    }
                }
            }
        }
        else {
            degrees[j] = 0;
            strcpy(coefficient, token);
            coefficient[strlen(coefficient)] = '\0'; // добавлен завершающий нулевой символ
            Expression expr;
            expr.str = coefficient;
            expr.len = strlen(coefficient);
            coeffs[i] = evaluate_expression(&expr);
            
        }
        i++;
        j++;
        token = strtok(NULL, " ");

        //конец супер нового
    }


    char expression[100] = "\0";
    char new[100];
    int start = 0;
    for (k = 0; k < j; k++){
        if (start == 1){
        if (coeffs[k] > 0){
            strcat(expression, "+");
        }
        }
        if (coeffs[k] != 0){
            snprintf(new, sizeof(new), "%d", coeffs[k]);
            strcat(expression, new);
            if (degrees[k] != 0) {
                strcat(expression, "*x");
            }
            if (degrees[k] > 1){
                strcat(expression, "^");
                snprintf(new, sizeof(new), "%d", degrees[k]);
                strcat(expression, new);
            }
            if (degrees[k] < 0){
                strcat(expression, "^");
                snprintf(new, sizeof(new), "(%d)", degrees[k]);
                strcat(expression, new);
            }
            start = 1;
        }
        
    }

    //вспомогательное
    printf("Коэффициенты: ");
    for (k = 0; k < j; k++){
        printf("%d ", coeffs[k]);
    }
    printf("\n");
    printf("Степени: ");
    for (k = 0; k < j; k++){
        printf("%d ", degrees[k]);
    }
    
    printf("\n");
    //конец вспм

    printf("Сокращенный многочлен: %s\n", expression);
    char* p = expression;
    Node* root = parseExpression(&p);
    printTree(root, 0);
    printf("\n"); 
    freeTree(root);

    char newexpression[100] = "\0";
    int newstart = 0;
    char newnew[50] = "\0";
    for (int k = 0; k < j; k++){
        if (coeffs[k] != 0 && degrees[k] != 0){
            if (newstart == 1){
            if (coeffs[k] * degrees[k] > 0){
                strcat(newexpression, "+");
            }
            }
            

            snprintf(newnew, sizeof(newnew), "%d", coeffs[k] * degrees[k]);
            strcat(newexpression, newnew);
            if (degrees[k] != 1) {
                strcat(newexpression, "*x");
                if (degrees[k] > 2) {
                    strcat(newexpression, "^");
                    snprintf(newnew, sizeof(newnew), "%d", degrees[k] - 1);
                    strcat(newexpression, newnew);
                }
                if (degrees[k] < 0) {
                    strcat(newexpression, "^");
                    snprintf(newnew, sizeof(newnew), "(%d)", degrees[k] - 1);
                    strcat(newexpression, newnew);
                }
                
            }
            newstart = 1;
            
        }
    }
    if (strlen(newexpression) != 0) {
        printf("Производная многочлена: %s\n", newexpression);
        char* np = newexpression;
        Node* newroot = parseExpression(&np);
        printTree(newroot, 0);
        printf("\n"); 
        freeTree(newroot);
    }
    else {
        printf("Производная многочлена: 0\n");
    }
    free(coeffs);
    free(degrees);

    return 0;
}