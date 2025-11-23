// Наиболее очевидный разряд алгоритмов с линейной переборкой массива

#include <stdio.h>

int array[5] = {1, 4, 5, 7, 8};

int linear_search(int arr[5], int len, int item) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == item) {
      return i;
    }
  }
  return -1;
}

int main() {
  unsigned int len = sizeof(array) / sizeof(int);
  printf("%d\n", linear_search(array, len, 8));
}