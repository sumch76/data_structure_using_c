#include <stdio.h>

int binary_search(int *array, int size, int target) {
  int low = 0;
  int high = size - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (array[mid] == target) {
      return mid;
    } else if (array[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int array[] = {1, 3, 5, 7, 9};
  int size = sizeof(array) / sizeof(array[0]);
  int target = 5;

  int index = binary_search(array, size, target);

  if (index == -1) {
    printf("The target value was not found.\n");
  } else {
    printf("The target value was found at index %d.\n", index);
  }

  return 0;
}
