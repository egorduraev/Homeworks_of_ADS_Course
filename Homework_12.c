#include <stdio.h>
#include <stdlib.h>

typedef int boolean;
#define true 1
#define false 0

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} TreeNode;

TreeNode* treeInsert(TreeNode *t, int data) {
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode *tree) {
    if (tree) {
        printf("%d", tree->key);
        if (tree->left || tree->right) {
            printf("(");
            if (tree->left)
                printTree(tree->left);
            else
                printf("NULL");
            printf(",");
            if (tree->right)
                printTree(tree->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

int checkBalanceOfTree(TreeNode* t) {
    if (t == NULL) {
        return 0;
    }
    int levelL = checkBalanceOfTree(t->left);
    int levelR = checkBalanceOfTree(t->right);
    if (levelL == -1 || levelR == -1 ||
    (((levelL - levelR) > 1) && (levelL - levelR) > 0) ||
    (((levelL - levelR) < -1) && (levelL - levelR) < 0))
        return -1;
    if (levelL > levelR) return levelL + 1; else return levelR + 1;
}

TreeNode* binarySearch(TreeNode* t, int data) {
    if (t == NULL) {
        printf("Not found");
        return NULL;
    }
    if (t->key == data) {
        printf("number %d found with address %p", data, &t);
        return t;
    }
    if (data < t->key) return binarySearch(t->left, data);
    else return binarySearch(t->right, data);

}

int main()
{
    //Task_1
    printf("Task 1: \nWith the initial data of the task:\n");
    int number = 50;
    int size = 1000;
    int balanced;
    int border = 1000;
    balanced = 0;
    for (int i = 0; i < number; ++i) {
        TreeNode *newNode = NULL;
        TreeNode *tree = treeInsert(newNode, rand() % 1000);
        for (int i = 0; i < size; ++i) {
            treeInsert(tree, rand() % 1000);
        }
        if (checkBalanceOfTree(tree) != -1) balanced = balanced + 1;
    }
    printf("%d percent \n", balanced * 100 / number);

    printf("With reduced initial data. To check the functionality:\n");
    number = 10;
    size = 3;
    balanced = 0;
    for (int i = 0; i < number; ++i) {
        TreeNode *newNode = NULL;
        TreeNode *tree = treeInsert(newNode, rand() % 1000);
        for (int i = 0; i < size; ++i) {
            treeInsert(tree, rand() % 1000);
        }
        printTree(tree);
        printf("\n");
        if (checkBalanceOfTree(tree) != -1) balanced = balanced + 1;
    }
    printf("%d percent \n", balanced * 100 / number);

    //Task_2
    printf("Task 2:\n");
    TreeNode *newNode = NULL;
    TreeNode *tree = treeInsert(newNode, rand() % 20);
    for (int i = 0; i < 10; ++i) {
                treeInsert(tree, rand() % 20);
            }
    printTree(tree);
    printf("\n");
    int data;
    printf("Please enter a number to search: ");
    scanf("%d", &data);
    binarySearch(tree, data);
    return 0;
}
