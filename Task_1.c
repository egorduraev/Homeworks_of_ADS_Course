#include <stdio.h>

int main() {
    int number;
    printf ("������� ����������, �����: ");
    scanf("%d", &number);
    int s = 0;
    int i = 1;
    while (i <= number) {
        if (number % i++ == 0)  {
            s++;
        }
        else {
            continue;
        }
        if (s == 3) {
            break;
        }
    }
    if (s == 2) printf("����� %d �������� �������", number); else printf("����� %d �� �������� �������", number);
    return 0;
}
