#include<stdio.h>
#include<stdlib.h>
int main() {
    int n, n2, i, * ptr;
    printf("Enter Number of elements: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    printf("Address of previously allocated memory: \n");
    for (i = 0;i < n;i++) {
        printf("%p\n", ptr + i);
    }
    printf("\nEnter new size:");
    scanf("%d", &n2);
    ptr = realloc(ptr, n2 * sizeof(int));
    printf("Address of newly allocated memory: \n");

    for (i = 0;i < n2;i++) {
        printf("%p\n", ptr + i);
    }
    free(ptr);
    return 0;
}
