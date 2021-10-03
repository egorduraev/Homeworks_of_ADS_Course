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

void printArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

void setArray(int** array, const int row, const int col, int value) {
    array[row][col] = value;
}

int getArray(int** array, const int row, const int col) {
    return array[row][col];
}

//Task_1
void ToBin(int number, char* res) {
    if (number <= 0) return;
    ToBin(number / 2, res);
    strcat(res, (number % 2 == 0) ? "0" : "1");

}

//Task_2
int mypow(int a, int b) {
    if (b <= 0) return 1;
    return mypow(a, b - 1) * a;
}

int mypowFast(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2 == 0)
        return mypowFast(a * a, b / 2);
    else
        return a * mypowFast(a, b - 1);
}

//Task_3
int routes(int x, int y, int** arr) {
    if (getArray(arr, y, x) == 1) return 0;
    if (x == 0 && y == 0) return 0;
    else if (x == 0) {
        if (routes(x, y - 1, arr) == 0 && y != 1) return 0;
        return 1;
    } else if (y == 0) {
        if (routes(x - 1, y, arr) == 0 && x != 1) return 0;
        return 1;
    }
    return routes(x, y - 1, arr) + routes(x - 1, y, arr);
}


int main() {
//Task_1
    printf("Task 1\n");
    char res[] = "";
    ToBin(29, res);
    printf("%s\n", res);

//Task_2
    printf("Task 2\n");
    printf("%d\n", mypow(5, 3));
    printf("%d\n", mypowFast(5, 3));

//Task_3
    printf("Task 3\n");
    const int size = 6;
    int** arr = initArray(arr, size, size);
    printArray(arr, size, size);
    setArray(arr, 0, 3, 1);
    setArray(arr, 2, 2, 1);
    setArray(arr, 3, 4, 1);
    setArray(arr, 2, 5, 1);
    printArray(arr, size, size);
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x)
            printf("%3d", routes(x, y, arr));
        printf("\n");
    }
    return 0;
}
