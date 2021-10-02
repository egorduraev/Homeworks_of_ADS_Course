#include <stdio.h>

int main() {
    int number;
    printf ("Введите пожалуйста, число: ");
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
    if (s == 2) printf("Число %d является простым", number); else printf("Число %d не является простым", number);
    return 0;
}
