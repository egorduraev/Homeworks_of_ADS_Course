#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encryptionCaesar(char* message, char key) {
    int i = 0;
    while (*message != 0) {
        if (key > 26)
        *message = *message + key;
        message++;
        i++;
    }
    message -= i;
    return message;
}

char* decodingCaesar(char* message, char key) {
    int i = 0;
    while (*message != 0) {
        *message = *message - key;
        message++;
        i++;
    }
    message -= i;
    return message;
}

char* permutation(char* message, int col) {
    int l = strlen(message);
    int len = col * (1 + ((l - 1) / col));
    char* answer = (char*) malloc(sizeof(char) + len);
    int index =0;
    for (int i = 0; i < col; ++i) {
        for (int j = i; j < len; j += col) {
            answer[index++] = (*(message + j)) ? *(message + j) : (char) 'e';
        }
    }
    answer[len] = 0;
    return answer;
}

char* reversePermutation(char* message, int col) {
    int l = strlen(message);
    int len = col * (1 + ((l - 1) / col));
    char* answer = (char*) malloc(sizeof(char) + len);
    col = len / col;
    int index =0;
    for (int i = 0; i < col; ++i) {
        for (int j = i; j < len; j += col) {
            answer[index++] = (*(message + j)) ? *(message + j) : (char) 'e';
        }
    }
    answer[len] = 0;
    return answer;
}

int main() {
    printf("Task 1: \n");
    char * data = (char*) calloc(100, sizeof(char*));
    char key;
    int keyInt;
    printf("Enter key: ");
    scanf("%d", &keyInt);
    key = (char) keyInt;
    printf("Enter text: ");
    scanf("%s", data);
    char * cryptedtext1 = (char*) calloc(100, sizeof(char*));
    cryptedtext1 = encryptionCaesar(data, key);
    printf("Crypted text: ");
    printf("%s\n", cryptedtext1);
    char* decryptedtext1 = (char*) calloc(100, sizeof(char*));
    decryptedtext1 = decodingCaesar(cryptedtext1, key);
    printf("Decrypted text: ");
    printf("%s\n", decryptedtext1);

    printf("Task 2: \n");

    char* text = "thisisasecretmessage";
    int col;
    printf("Enter col: ");
    scanf("%d", &col);
    char * cryptedtext2 = permutation(text, col);
    printf("Crypted text: ");
    printf("%s\n", permutation(text, col));
    char* decryptedtext2 = reversePermutation(cryptedtext2, col);
    printf("Decrypted text: ");
    printf("%s\n", decryptedtext2);
    return 0;
}
