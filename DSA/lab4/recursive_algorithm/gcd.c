#include <stdio.h>
int GCD(int num1, int num2) {
    if (num1 % num2 == 0) {
        return num2;
    }
    return GCD(num2, num1 % num2);
}

int main() {
    int a, b;
    printf("Enter any two numbers: ");
    scanf("%d%d", &a, &b);
    printf("The GCD of %d and %d is %d\n", a, b, GCD(a, b));
    return 0;
}

