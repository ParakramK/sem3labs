// Shell Sort in C programming

#include <stdio.h>

// Shell sort
void shellSort(int array[], int n) {
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }

    }
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int data[] = { 4, 8, 9, 0, 11, 56, 79, 22 };
    int size = sizeof(data) / sizeof(data[0]);
    shellSort(data, size);
    printf("Sorted array: \n");
    printArray(data, size);
    return 0;
}