#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

/*Вспомогательные функции для работы с одномерными, двумерными массивами,
односвязными и двусвязными списками, взятые из материалов к урокам (geek.с):
*/

void clearIntArray(int* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}

int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);
}

void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}

void setLineValues(int** matrix, int cols, int row, ...) {
    va_list args;
    va_start(args, row);
    for (int i = 0; i < cols; ++i) {
        set2dInt(matrix, row, i, va_arg(args, int));
    }
    va_end(args);
}


//Односвязные списки
typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}

boolean pushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T popOneLinkStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}


//Двусвязные списки
typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

boolean TwoLinkEnqueue(TwoLinkList *queue, T value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}

T TwoLinkDequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}



//Task_1
int visited[6] = {0}; //Матрица посещений

void traversalDepth(int** matrix, int size) {
    OneLinkList* lst = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst); //Инициализируем стек на основе односвязного списка
    pushOneLinkStack(lst, 0); //Записываем в стек текущую вершину (столбец)
    int g;
    visited[0] = 1; //Отмечаем вершину для старта в матрице посещений
    printf("%d\n", 0); //Вывод стартовой вершины "0"
    while (lst->size) { //Цикл пока стек не опустеет ...
        g = 0;
        for (int i = 0; i < size; i++) {
            if (get2dInt(matrix, lst->head->dat, i) == 1 && visited[i] == 0) g = i; //Ищем элемент смежную и не посещенную вершину(в строке)
        }
        if (g == 0) {
            popOneLinkStack(lst); //Отходим назад если дальше нету смежных и не посещенных вершин (уменьшаем стек)
        } else {
            visited[g] = 1;
            printf("%d\n", (int) g);//Вывод вершины, которую посетили
            pushOneLinkStack(lst, g); //Записываем найденную вершину как текушую
        }
    }
}


//Task_2
int visitedRecursive[6] = {0};
void graphTraversalRecursiveFunction (int** matrix, int G, int size) {
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    TwoLinkEnqueue(queue, G);
    while (queue->size > 0) {
        int point = TwoLinkDequeue(queue);
        if (visited[point]) continue;
        visited[point] = true;
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, point, i) == 1) {
                if (i != point)
                    visitedRecursive[i]++;
                if (!visited[i])
                    TwoLinkEnqueue (queue, i);
            }
        }
    }
}

int visitedAdjacencyMatrix[6] = {0};
void graphTraversalAdjacencyMatrix (int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[j][i] == 1)
                if (i != j) visitedAdjacencyMatrix[i]++; //Исключаем направление вершины на самого себя
        }
    }
}



void printIntSortArray(int* array, int size, int offset) {
    T namesgraphs[6];
    for (int i = 0; i < size; i++) {
        namesgraphs[i] = 65 + i;
    }
    int temp1, pos, temp2, tempG1, tempG2;
        for (int i = 1; i < size; ++i) {
            temp1 = array[i];
            tempG1 = namesgraphs[i];
            pos = i - 1;
            while (pos >= 0 && array[pos] > temp1) {
                array[pos + 1] = array[pos];
                namesgraphs[pos + 1] = namesgraphs[pos];
                pos--;
            }
            array[pos + 1] = temp1;
            namesgraphs[pos + 1] = tempG1;
        }
        for (int i = 0; i < (size / 2); i++)
        {
            tempG2 = namesgraphs[size - i - 1];
            temp2 = array[size - i - 1];
            array[size - i - 1] = array[i];
            namesgraphs[size - i - 1] = namesgraphs[i];
            array[i] = temp2;
            namesgraphs[i] = tempG2;
        }
    for (int i = 0; i < size; i++) {
        printf("%c ", namesgraphs[i]);
    }
    printf("\n");
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

int main() {
    //Task_1
    printf("Task_1:\n");
    int** matrix1 = init2dIntArray(matrix1, 6, 6);
    setLineValues(matrix1, 6, 0, 0, 1, 1, 0, 0, 0);
    setLineValues(matrix1, 6, 1, 0, 0, 0, 1, 1, 1);
    setLineValues(matrix1, 6, 2, 0, 0, 0, 0, 0, 1);
    setLineValues(matrix1, 6, 3, 0, 1, 0, 0, 0, 0);
    setLineValues(matrix1, 6, 4, 0, 0, 0, 0, 0, 0);
    setLineValues(matrix1, 6, 5, 0, 0, 0, 0, 1, 0);
    traversalDepth(matrix1, 6);
    clearIntArray(visited, 6);
    printf("\n");

    //Task_2
    printf("Task_2:\n");
    int** matrix2 = init2dIntArray(matrix2, 6, 6);
    setLineValues(matrix2, 6, 0, 0, 1, 0, 0, 0, 0);
    setLineValues(matrix2, 6, 1, 0, 1, 1, 0, 1, 0);
    setLineValues(matrix2, 6, 2, 0, 1, 1, 1, 1, 0);
    setLineValues(matrix2, 6, 3, 0, 1, 0, 0, 1, 0);
    setLineValues(matrix2, 6, 4, 0, 0, 0, 1, 1, 1);
    setLineValues(matrix2, 6, 5, 1, 0, 0, 0, 0, 0);
    graphTraversalRecursiveFunction(matrix2, 0, 6);
    printIntSortArray(visitedRecursive, 6, 0);
    printf("\n");
    graphTraversalAdjacencyMatrix(matrix2, 6);
    printIntSortArray(visitedAdjacencyMatrix, 6, 0);
    return 0;
}
