#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Heapify function
void heapify(int arr[], int n, int i) {
    int maximum = i;
    int right_index = 2 * i + 2;
    int left_index = 2 * i + 1;

    if (left_index < n && arr[left_index] > arr[maximum])
        maximum = left_index;

    if (right_index < n && arr[right_index] > arr[maximum])
        maximum = right_index;

    if (maximum != i) {
        int temp = arr[i];
        arr[i] = arr[maximum];
        arr[maximum] = temp;
        heapify(arr, n, maximum);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = { 4, 8, 9, 0, 11, 56, 79, 22 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting:\n");
    printArray(arr, size);
    heapsort(arr, size);
    printf("After Heap Sort: ");
    printArray(arr, size);
    return 0;
}
