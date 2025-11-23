/* 
 * Поиск пары в отсортированном массиве за линейное время посредством сближения двух указателей с конца и с начала массива
 */

#include <stdio.h>

int array[5] = {1, 4, 5, 7, 8};

int two_pointers(int arr[], int len, int target) {
  int left = 0;
  int right = len - 1;

  // Not left <= right because we're searching for the pair
  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum == target) {
      return 0;
    }

    if (sum > target) {
      right--; // Move the biggest pointer to smaller values
    } else {
      left++; // Move the smallest to bigger ones
    }
  }

  return -1;
}

int main() {
  unsigned int len = sizeof(array) / sizeof(int);
  printf("%d\n", two_pointers(array, len, 8));
}