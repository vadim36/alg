/*
 * Поиск в отсортированном массиве с логарифмической сложностью(log base 2). 
 * Достигается посредством уменьшения массива поиска(search space) в два раза за каждую операцию. 
 */ 

#include <stdio.h>

int array[5] = {1, 4, 5, 7, 8};

int binary_search (int arr[], int len, int item) {
  // Define boundaries of search space
  int left = 0;
  int right = len - 1;

  // You can use "left < right" condition if you 1) right = len; or 2) you handle case if right == left out of the loop
  while (left <= right) {
    int mid = left + (right - left) / 2; //We need adding left to avoid integer overflowing
    //Either you can use the binary operator: left + right >> 1; - Divides (left + right) on 2^1

    if (arr[mid] == item) {
      return mid;
    }

    // Conditioning of what's part of an array to cut
    if (item > arr[mid]) {
      left = mid + 1; // item > mid, so we need to exclude mid
    } else {
      right = mid; // item <= mid, so we include mid
    }
  }

  return -1;
}

int main() {
  unsigned int len = sizeof(array) / sizeof(int);
  printf("%d\n", binary_search(array, len, 8));
}