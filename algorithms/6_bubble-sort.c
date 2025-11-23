/* 
 * Один из наиболее медленных видов сортировки - попарное сравнение двух соседних элементов и перетасовка их в порядке возрастания.
 * Квадратичная сложность
 */

#include <stdio.h>

int array[7] = {8, 4, 3, -5, 2, 9, 10};

int bubble_sort(int arr[], int len) {
  // Thanks to nested loop that both start with first element we can pairly compair two elements
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap two elements
        int min = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = min;
      }
    }
  }

  return 0;
}

int main() {
  unsigned int len = sizeof(array) / sizeof(int);
  bubble_sort(array, len);
  for (int i = 0; i < len; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
}