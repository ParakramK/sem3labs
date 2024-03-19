// WAP TO SORT AN ARRAY USING SELECTION SORT
#include<stdio.h>

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size) {
    int small, index;
    for (int i = 0;i < size - 1;i++) {
        small = arr[i];
        for (int j = i;j < size - 1;j++) {
            if (arr[j] < small) {
                small = arr[j];
                index = j;
            }
        }
        if (small != arr[i]) {
            arr[index] = arr[i];
            arr[i] = small;
        }
    }
}

int main() {
    int arr[] = { 4, 8, 9, 0, 11, 56, 79, 22 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting:\n");
    displayArray(arr, size);

    selectionSort(arr, size);
    printf("\nArray after sorting:\n");
    displayArray(arr, size);
    return 0;
}