#include <stdio.h>
#include <math.h>

#define SIZE 11

void initArray(float arr[SIZE])
{
    int cnt = 0;
    float val;
    while (cnt < SIZE) {
        printf("array[%d] = ", cnt);
        scanf("%f", &val);
        arr[cnt++] = val;
        printf("\n");
    }
}

void printSeq(float arr[SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void transformSeq(float arr[SIZE])
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
}

void printTransformSeq(float arr[SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f ", arr[i]);
        if (arr[i] > 400) printf("Arr[%d] exceeding 400!", i);
        printf("\n");
    }
    printf("\n");
}

void invertArray(float arr[SIZE])
{
    float temp;
    for (int i = 0; i < SIZE / 2; i++){
        temp = arr[i];
        arr[i] = arr[SIZE - 1 - i];
        arr[SIZE - 1 - i] = temp;
    }

}

int main()
{
    float array[SIZE];
    initArray(array);
    printf("Sequence:\n");
    printSeq(array);
    printf("Invertion sequence:\n");
    invertArray(array);
    printSeq(array);
    printf("Transform sequence:\n");
    transformSeq(array);
    printTransformSeq(array);
    return 0;
}
