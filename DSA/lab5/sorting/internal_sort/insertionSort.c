// WAP TO SORT AN ARRAY USING INSERTION SORT.

#include <stdio.h>

void displayArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionSort(int arr[], int size) {
  int step, key, j;
  for (step = 1; step < size; step++) {
    key = arr[step];  // assume second element of array as sorted and
    // compare it with the next unsorted array.
    j = step - 1;
    /* Compare key with each element on the left of it until an element smaller
     than it is found. Move elements of arr[0..i-1] that are greater than key to
     one position ahead of their current position */
    while (key < arr[j] && j >= 0) {  // For descending order, change
      // key<array[j] to key > arr[j]//
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = { 4, 8, 9, 0, 11, 56, 79, 22 };
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Array before sorting:\n");
  displayArray(arr, size);

  insertionSort(arr, size);
  printf("\nArray after sorting:\n");
  displayArray(arr, size);
  return 0;
}

