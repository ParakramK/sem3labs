#include <stdio.h>

int counter = 0;

void towerOfHanoi(int n, char source, char intermediate, char destination) {
    if (n == 0) {
        return;
    }
    counter++;
    towerOfHanoi(n - 1, source, destination, intermediate);
    printf("Move disk %d from %c tower to %c tower\n", n, source, destination);
    towerOfHanoi(n - 1, intermediate, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'X', 'Y', 'Z');
    printf("The total number of iterations required is: %d\n", counter);
    return 0;
}


