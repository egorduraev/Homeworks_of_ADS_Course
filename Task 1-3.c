#include <stdio.h>
#include <stdlib.h>

//TASK 1

typedef struct Node {
    char dat;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

void init(List* lst) {
    lst->head = NULL;
    lst->size = 0;
}

void ins(List *lst, char data) {
    Node *new = (Node*) malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}


void printNode(Node *n) {
    if (n == NULL) {
        printf("[]");
    }
    printf("%c", n->dat);
}

void printList(List *lst) {
    Node *current = lst->head;
    if (current == NULL) {
        printNode(current);
    } else {
        do {
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
}

void StrToList(List *lst, char string[], int size) {
    for (int i = 0; i < size; ++i) {
        ins(lst, string[i]);
    }
}

void checkCor(List *lst) {
    char LP ='(';
    char RP ='(';
    char LSB ='[';
    char RSB =']';
    char LB ='{';
    char RB ='}';
    int MP = 0;
    int MSB = 0;
    int MB = 0;
    int M = 0;
    Node *current = lst->head;
    if (current == NULL) {
        printf("NULL");
        return;
    } else {
        do {
            if (current->dat == LP) MP++;
            if (current->dat == LSB) MSB++;
            if (current->dat == LB) MB++;
            if (current->dat == RP) MP--;
            if (current->dat == RSB) MSB--;
            if (current->dat == RB) MB--;
            if (MP < 0) {
                M = 1;
                break;
            }
            if (MSB < 0) {
                M = 1;
                break;
            }
            if (MB < 0) {
                M = 1;
                break;
            }
            current = current->next;
        } while (current != NULL);
        if (M == 1) printf("Incorrect!");
        else printf("Correct!");
    }

//    ( - left parentheses (открывающая или левая скобка)
//    ) - right parentheses (закрывающая или правая скобка)
//    [ - left square bracket (левая квадратная скобка)
//    ] - right square bracket (правая квадратная скобка)
//    { - left brace (левая фигурная скобка)
//    } - right brace (правая фигурная скобка)
}

//TASK 2

void copyToList (List *lst1, List *lst2) {
    Node *current = lst1->head;
    if (current == NULL) {
        printf("NULL");
        return;
    } else {
        do {
            ins(lst2, current->dat);
            current = current->next;
        } while (current != NULL);
    }
}

//TASK 3

typedef struct NodeInt {
    int dat;
    struct NodeInt *next;
} NodeInt;

typedef struct {
    NodeInt *head;
    int size;
} ListInt;

void initInt(ListInt* lst) {
    lst->head = NULL;
    lst->size = 0;
}

void insInt(ListInt *lst, int data) {
    NodeInt *new = (NodeInt*) malloc(sizeof(NodeInt));
    new->dat = data;
    new->next = NULL;

    NodeInt *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

void printNodeInt(NodeInt *n) {
    if (n == NULL) {
        printf("[]");
    }
    printf("%d ", n->dat);
}

void printListInt(ListInt *lst) {
    NodeInt *current = lst->head;
    if (current == NULL) {
        printNodeInt(current);
    } else {
        do {
            printNodeInt(current);
            current = current->next;
        } while (current != NULL);
    }
}

void fillLst(ListInt* lst, int size, int border) {
    for (int i = 0; i < size; ++i) {
        insInt(lst, rand() % border);
    }
}

void seqLst(ListInt *lst, int size) {
    for (int i = 0; i < size; ++i) {
        insInt(lst, i);
    }
}

void checkSeq(ListInt *lst) {
    NodeInt *current = lst->head;
    int check = 0;
    if (current == NULL) {
        printf("NULL");
        return;
    } else {
        do {
            if ((current->dat) > (current->next->dat)) check = 1;
            current = current->next;
        } while (current->next != NULL);
        if (check == 1) printf("Incorrect! \n");
        else printf("Correct! \n");
    }
}
int main()
{
    //TASK 1
    printf("TASK 1: \n");
    List *lst = (List*) malloc(sizeof (List));
    init(lst);
    char string[] = "The incorrect: )(()}{][";
    int size = sizeof(string) / sizeof(string[0]);
    StrToList(lst, string, size);
    printList(lst);
    printf("\n");
    checkCor(lst);
    printf("\n");

    List *lst2 = (List*) malloc(sizeof (List));
    init(lst2);
    char string2[] = "The correct: (({{[]{}}}()))";
    size = sizeof(string2) / sizeof(string2[0]);
    StrToList(lst2, string2, size);
    printList(lst2);
    printf("\n");
    checkCor(lst2);
    printf("\n");

    //TASK 2
    printf("TASK 2: \n");
    List *lst3 = (List*) malloc(sizeof (List));
    init(lst3);
    char string3[] = "Hello, my name is Egor";
    size = sizeof(string3) / sizeof(string3[0]);
    StrToList(lst3, string3, size);
    printList(lst3);
    printf("\n");
    List *lst4 = (List*) malloc(sizeof (List));
    init(lst4);
    copyToList(lst3, lst4);
    printf("New copied list: \n");
    printList(lst4);
    printf("\n");
    printf("Old list: \n");
    printList(lst3);
    printf("\n");

    //TASK 3
    printf("TASK 3: \n");
    ListInt *lst5 = (ListInt*) malloc(sizeof (ListInt));
    initInt(lst5);
    fillLst(lst5, 10, 30);
    printListInt(lst5);
    printf("\n");
    checkSeq(lst5);

    ListInt *lst6 = (ListInt*) malloc(sizeof (ListInt));
    initInt(lst6);
    seqLst(lst6, 10);
    printListInt(lst6);
    printf("\n");
    checkSeq(lst6);

    return 0;
}
