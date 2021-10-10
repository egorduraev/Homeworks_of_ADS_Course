#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** initArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}

void fillArray(int** array, const int row, const int col, int begin, int end) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            array[i][j] = rand() % end + begin;
        }
    }
}

void printArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}


void bubbleSort(int** arr, int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < row; k++)
            {
                for (int l = 0; l < col; l++)
                {
                    if (arr[i][j] < arr[k][l])
                    {
                        int tmp = arr[i][j];
                        arr[i][j] = arr[k][l];
                        arr[k][l] = tmp;
                    }
                }
            }
        }
    }
}

int main()
{
    const int row = 5;
    const int col = 5;
    int begin = 0;
    int end = 10;
    int** arr = initArray(arr, row, col);
    fillArray(arr, row, col, begin, end);
    printArray(arr, row, col);
    bubbleSort(&arr[0], row, col);
    printf("\n\n");
    printArray(arr, row, col);

    return 0;
}
