// WAP TO FIND THE FACTORIAL OF ANY NUMBER USING RECUSIVE ALGORITHM

#include <stdio.h>

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    return (num * factorial(num - 1));
}

int main() {
    int num;
    printf("Enter any number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error! Factorial of negative number does not exist.\n");
        return 0;
    }
    printf("The factorial of %d is %d\n", num, factorial(num));
    return 0;
}

