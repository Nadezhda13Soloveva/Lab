#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

void printTreeWithIndent(Node* node, int depth) {
    if (node == NULL) {
        return;
    }
    
    printTreeWithIndent(node->right, depth + 1);
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("%d\n", node->data);
    printTreeWithIndent(node->left, depth + 1);
}

void viewTree(Node* root) {
    if (root == NULL) {
        printf("Дерево пустое\n");
    } else {
        printf("Бинарное дерево с отступами:\n");
        printTreeWithIndent(root, 0);
    }
}

int calculateWidth(Node* root, int level) {
    if (root == NULL) {
        return 0;
    }
    
    if (level == 1) {
        return 1;
    } else if (level > 1) {
        return calculateWidth(root->left, level - 1) + calculateWidth(root->right, level - 1);
    }
    return 0;
}

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } 
    else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

int treeWidth(Node* root) {
    int maxWidth = 0;
    int height = getHeight(root);
    
    for (int i = 1; i <= height; i++) {
        int width = calculateWidth(root, i);
        if (width > maxWidth) {
            maxWidth = width;
        }
    }
    
    return maxWidth;
}

Node* findMinNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

int main() {
    Node* root = NULL;
    char command;
    int data;
    
    do {
        printf("Введите команду (C (CREATE) для добавления узла, V (VIEW) для просмотра дерева, W (WIDTH) для поиска ширины, D (DELETE) для удаления узла, Q (QUIT) для выхода): ");
        scanf(" %c", &command);

        switch(command) {
            
            case 'C':
            case 'c':
                printf("Введите значение для нового узла: ");
                scanf("%d", &data);
                root = insertNode(root, data);
            break;

            case 'V':
            case 'v':
                viewTree(root);
            break;

            case 'W':
            case 'w':
                printf("Ширина бинарного дерева: %d\n", treeWidth(root));
            break;

            case 'D':
            case 'd':
                printf("Введите значение узла для удаления: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
            break;
        }
    } while (command != 'Q' && command != 'q');
    
    return 0;
}