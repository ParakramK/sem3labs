#include <stdio.h>
int fibonacci(int num) {
    if (num == 0 || num == 1) {
        return num;
    } else {
        return (fibonacci(num - 1) + fibonacci(num - 2));
    }
}


int main() {
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibonacci Series:\n");
    for (i = 1; i <= num; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
