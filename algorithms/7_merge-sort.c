/*
  Сортировка слиянием - уменьшает сложность по времени, но возрастает по памяти
  За счет выделения ячеек памяти под отсортированный массив - увеличивает сложность по памяти до линейной
  Благодаря делению на левую и правые части (пока длина обоих не достигнет одного элемент) и сортировки их по отдельности, 
  а затем слияние со сравнением левые и правые участи удается уменьшить временную сложность с квадратичной до линейно-логарифмической
*/

#include <stdio.h>
#include <stdlib.h>


int merge_sort(int arr[], int len) {
  // Base case for recursion
  if (len <= 1) return 0;
  int mid = len / 2;
  
  //Prepare left and right arrays
  int left_arr[] = malloc(mid * sizeof(int));
  int right_arr[] = malloc((len - mid) * sizeof(mid));

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
  merge_sort(left_arr, sizeof(left_arr) / sizeof(int));
  merge_sort(right_arr, sizeof(right_arr) / sizeof(int));

  int left_len = sizeof(left_arr) / sizeof(int);
  int right_len = sizeof(right_arr) / sizeof(int);
  int sorted_arr = malloc(len * sizeof(int));



  return 0;
}