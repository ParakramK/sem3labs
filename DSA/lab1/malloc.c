#include<stdio.h>
#include<stdlib.h>
int main() {
    int n, i, * ptr, sum = 0;
    printf("Enter Number of elements: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory can't be allocated");
        exit(0);
    }
    else {
        printf("Enter ELements: ");
        for (i = 0;i < n;i++) {
            scanf("%d", ptr + i);
            sum += *(ptr + i);
        }
        printf("Sum is: %d\n", sum);
        free(ptr);
    }
    return 0;
}