#include <stdio.h>
#include <stdlib.h>

//Task_1
int hashingString(char* word) {
    int hash = 0;
    int i = 0;
    while (word[i] > 0) {
        hash += word[i];
        i++;
    }
    return hash;
}

//Task_2
int* greedyAlgorithm(int* coins, int size, int total, int* number) {
    *number = 0;
    int* answer = (int*) calloc(64, sizeof(int));
    int current;
    int j = 0;
    for (int i = 0; i < size; ++i) {
        current = 0;
        while (total - current >= coins[i]) {
            current += coins[i];
            answer[j] = coins[i];
            *number = *number + 1;
            j++;
            if (total == current) return answer;
        }
        total = total - current;
    }
    printf("No solution \n");
    return NULL;
}

void printArray(int* array, int number) {
    for (int i = 0; i < number; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main() {
    //Task_1
    printf("Task 1:\n");
    int hash;
    char * string = (char*) calloc(100, sizeof(char));
    printf("Please enter string\n");
    scanf("%s", string);
    hash = hashingString(string);
    printf("The hash is: %d \n", hash);
    printf("\n");

    //Task_2
    printf("Task 2:\n");
    int coins[5] = {50, 10, 5, 2, 1};
    int number = 0;
    int* array = greedyAlgorithm(coins, 5, 98, &number);
    printf("Answer: \n");
    printArray(array, number);
}
