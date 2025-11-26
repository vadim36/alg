/* 
 * Сортировка выбором
 * Самый простой вид сортировки - сравнение текущего значения со всеми значениями массива и, таким образом, нахождение наименьшего и наибольшего
 * Квадратичная сложность (точнее половины квадрата, но коэффициенты не учитываются в нотации большого О)
 */

#include <stdio.h>
#include <stdlib.h>

int array[7] = {8, 4, 3, -5, 2, 9, 10};

int selection_sort(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    // Index of current minimal element
    int min_i = i;
    // Enumerate all other elements of the array. Because of i + 1 we have complexity O(0.5n^2)
    for (int j = i+1; j < len; j++) {
      // Compare with current minimal element
      if (arr[j] < arr[min_i]) {
        min_i = j;
      }
    }

    int min = arr[min_i];
    // Swap element with current
    arr[min_i] = arr[i];
    arr[i] = min;
  }

  return 0;
}

int main() {
  unsigned int len = sizeof(array) / sizeof(int);
  selection_sort(array, len);
  for (int i = 0; i < len; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
}