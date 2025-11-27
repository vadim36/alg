/*
 * Сортировка вставками - берем первый элемент за отсортированный и двигаясь по массиву, сравниваем с текущим. 
 * Алгоритм имеет квадратичную скорость. 
 * При чем элементы не сразу становятся на отсортированные места, мы двигаем их по мере сравнения с каждым элементом.
 * Именно поэтому мы можем сравнивать значения не с целым массивом, а с одним элементом.
*/

#include <stdio.h>

int insertion_sort(int* arr, int len) {
  for (int i = 1; i < len; i++) {
    // Increasing the length of sorted subarray
    int sorted = i - 1;
    // If the next element is bigger, swap the current biggest element and sorted subarray and one
    while (sorted >= 0 && arr[sorted] > arr[sorted + 1]) {
      int temp = arr[sorted];
      arr[sorted] = arr[sorted + 1];
      arr[sorted + 1] = temp;
      // Repeat the algorithm til the start of array will reach or the previous element is less than new
      sorted--;
    }
  }
}

int array[7] = {8, 4, 3, -5, 2, 9, 10};

int main() {
  unsigned int len = sizeof(array) / sizeof(int);
  insertion_sort(array, len);
  for (int i = 0; i < len; i++) {
    if (i + 1 == len) {
      printf("%i", array[i]);
    } else {
      printf("%i, ", array[i]);
    }
  }
  printf("\n");
}