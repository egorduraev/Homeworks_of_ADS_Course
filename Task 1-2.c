#include <stdio.h>
#include <stdlib.h>
#define true 1 == 1
#define false 1 != 1
#define SZ 10
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1


typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void init() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins (int pr, int dat) {
    Node *node = (Node*) malloc (sizeof(Node));
    node -> dat = dat;
    node -> pr = pr;

    if (items == 0) {
        arr[tail++] = node;
        items++;
    } else if(items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    } else {
        int idx = 0;
        idx = tail % SZ;
        arr[idx] = node;
        items++;
        tail++;
    }
}


Node* rem() {
    if (items == 0) {
        return 0;
    } else {
        int idx = 0;
        int idx1 = 0;
        int pr = arr[head] -> pr;
        for ( int i = head; i < tail; ++i) {
            idx1 = i % SZ;
            if (pr > (arr[idx1] -> pr)) {
                pr = arr[idx1] -> pr;
            }

        }
        int i = 0;
        for (i = head; i < tail; ++i) {
            idx = i % SZ;
            if ((arr[idx] -> pr) == pr)
                break;
        }
        if (i == head) {
            idx = head++ % SZ;
            Node *tmp = arr[idx];
            arr[idx] = NULL;
            items--;
            return tmp;
        } else {
            int idxz = 0;
            Node *tmp = arr[idx];
            i--;
            while (i >= head) {
                idx = i % SZ;
                idxz = (i + 1) % SZ;
                arr[idxz] = arr[idx];
                i--;
            }
            arr[idx] = NULL;
            items--;
            head++;
            return tmp;
        }
    }
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[* , *}");
        else
            printf("[%d, %d]", arr[i] -> pr, arr[i] -> dat);
    }
    printf(" ]\n");
}


int cursor = -1;
int Stack[SIZE];
int push(int data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

int pop() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void ToBin(int num) {
    while(num != 0) {
        push(num % 2);
        num = num / 2;
    }
}

int main()
{
    printf("TASK 1: \n");
    init();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(5, 88);
    ins(1, 99);
    ins(6, 100);
    printQueue();
    for (int i = 0; i < 3; ++i) {
        Node* n = rem();
        printf("pr = %d, dat = %d \n", n -> pr, n -> dat);
    }
    printQueue();
    ins(1, 110);
    ins(3, 120);
    ins(6, 130);
    printQueue();
    for (int i = 0; i < 5; ++i) {
        Node* n = rem();
        printf("pr = %d, dat = %d \n", n -> pr, n -> dat);
    }
    printQueue();

    ins(2, 140);
    ins(4, 150);
    printQueue();

    printf("TASK 2: \n");
    int num;
    printf("Please, enter the number: ");
    scanf("%d", &num);
    ToBin(num);
    while (cursor != -1) {
        printf("%d ", pop());
    }
    return 0;
}
