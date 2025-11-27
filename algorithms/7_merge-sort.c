/*
  Сортировка слиянием - уменьшает сложность по времени, но возрастает по памяти
  За счет выделения ячеек памяти под отсортированный массив - увеличивает сложность по памяти до линейной
  Благодаря делению на левую и правые части (пока длина обоих не достигнет одного элемент) и сортировки этих единичных элементов, 
  а затем слияние со сравнением левые и правые участи удается уменьшить временную сложность с квадратичной до линейно-логарифмической
*/

#include <stdio.h>
#include <stdlib.h>

int merge_sort(int* arr, float len) {
  // Base case for recursion stops
  if (len <= 1) return 0;
  int mid = len / 2;
  
  //Prepare left and right arrays
  int left_len = mid;
  int right_len = len - mid; 
  int* left_arr = malloc(left_len * sizeof(int));
  int* right_arr = malloc(right_len * sizeof(int));

  //Fill left and right arrays with values of orginal one
  int right_i = 0;
  for(int i = 0; i < len; i++) {
    if (i < mid) {
      //Fill the first half of the original array
      left_arr[i] = arr[i];
    } else {
      //And the second half
      right_arr[right_i] = arr[i];
      right_i++;
    }
  }

  // Repeat algortihm for the left and right arrays until the base case
  merge_sort(left_arr, left_len);
  merge_sort(right_arr, right_len);

  // On this stage recursion ends and we have left and right array than now we can merge in sorted order
  int i = 0, l = 0, r = 0; //indicies for sorted array and left and right halves

  // Repeat loop until left and right arrays are merged in right order
  while (l < left_len && r < right_len) {
    if (left_arr[l] < right_arr[r]) {
      arr[i] = left_arr[l];
      l++;
    } else {
      arr[i] = right_arr[r];
      r++;
    }
    i++;
  }

  // Copy the remaining elements if there any
  while (l < left_len) {
    arr[i] = left_arr[l];
    i++;
    l++;
  }

  while (r < right_len) {
    arr[i] = right_arr[r];
    r++;
    i++;
  }
  
  free(left_arr);
  free(right_arr);

  return 0;
}

int array[7] = {8, 4, 3, -5, 2, 9, 10};

int main() {
  unsigned int len = sizeof(array) / sizeof(int);
  merge_sort(array, len);
  for (int i = 0; i < len; i++) {
    if (i + 1 == len) {
      printf("%i", array[i]);
    } else {
      printf("%i, ", array[i]);
    }
  }
  printf("\n");
}