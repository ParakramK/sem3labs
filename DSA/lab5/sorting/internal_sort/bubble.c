// WAP TO IMPLEMENT BUBBLE SORT ALGORITHM
#include <stdio.h>

void displayArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      // swap the elements to sort them in ascending order
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int main() {
  int arr[] = { 4, 8, 9, 0, 11, 56, 79, 22 };
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Array before sorting:\n");
  displayArray(arr, size);

  bubbleSort(arr, size);
  printf("\nArray after sorting:\n");
  displayArray(arr, size);
  return 0;
}
