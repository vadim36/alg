/*
 * Массив - это структура данных, состоящая из последовательных проиндексированных (каждому элементу соответствует индекс) ячеек памяти
 * Стандартный массив - занимает статическое количество памяти
 * Динамический массив - можно увеличивать или уменьшать длину
 */

 /* Сложность операций массива
  * Доступ к элементу (по индексу) - O(1)
  * Поиск элемента (по значению) - O(N)
  */

  /* Как динамический массив расширяет и сужает свою вместимость
   * - Нельзя просто запросить индекс следующей ячейки памяти - она может быть занята другим значением
   * - Так что при изменении вместимости необходимо полностью переносить все его элементы в другой участок памяти с большей вместимость - O(N)
   * - Увеличение вместимости массива называется коэффициентом вместимости
   * - Таким образом не выгодно проводить эту операцию при каждом измении длины - здесь выступает вместимость массива (его реальная длина)
   * - Вместимость массива занимает свободную память под динамическое заполнение элементами
   * - Если длина массива стала меньше определенного порога (например 4), то вместимость может также уменьшиться (например в двое)
   */

  /* Какие операции добавляются в динамическом массиве
   * Вставка - происходит переиндексация последующих элементов в массиве - О(n)
   * Вставка в конец - добавление в заранее подготовленую свободную память, однако если вместимость закончится произойдет 
   * расширение массива - О(1)* - амортизированная константная сложность - множество константных операций добавления амортизируют
   * линейной расширение массива
   * Удаление - О(n) - переиндексация
   */

#include <stdlib.h>
#include <stdio.h>

// Simple dynamic array realization
struct vector {
   int capacity;
   int len;
   int* begin;
};

typedef struct vector Vector;
const int GROW_N = 2;

Vector* new_vector(int* arr, int len) {
   if (len < 0) {
      printf("Length >= 0");
      exit(0);
   }

   int capacity = len * GROW_N;
   if (capacity == 0) {
      capacity = 1;
   }

   int* new_arr = (int*)malloc(capacity * sizeof(int));
   if (new_arr == NULL) {
      printf("Memory doesn't allocated\n");
      exit(1);
   }

   for (int i = 0; i < len; i++) {
      new_arr[i] = arr[i];
   }

   // Malloc function won't be destroyed at the end of the function
   Vector* ptr_to_vector = (Vector*)malloc(sizeof(Vector));
   if (ptr_to_vector == NULL) {
      free(new_arr);
      printf("Memory doesn't allocated\n");
      exit(1);
   }

   // Copy values to allocated structure
   ptr_to_vector->begin = new_arr;
   ptr_to_vector->capacity = capacity;
   ptr_to_vector->len = len;

   return ptr_to_vector;
}


int get(Vector *vector, int i) {
   if (i < -1) {
      printf("Index >= -1\n");
      exit(1);
   }

   if (i == -1) {
      return get(vector, vector->len - 1);
   }

   return *(vector->begin + i);
}

void set(Vector* vector, int el, int set_i) {
   if (set_i < -1) {
      printf("Index >= -1\n");
      exit(1);
   }

   if (set_i == -1) {
      return set(vector, el, vector->len);
   }

   if (set_i >= vector->len) {
      vector->len++;
   }

   if (set_i > vector->capacity) {
      Vector* new_vec = new_vector(vector->begin, set_i);
      return set(new_vec, el, set_i);
   }

   *(vector->begin + set_i) = el;
}

void insertion(Vector* vector, int el, int insertion_i) {
   if (insertion_i < -1) {
      printf("Index >= -1");
      exit(1);
   }

   if (insertion_i == vector->len || insertion_i == -1) {
      return set(vector, el, vector->len);
   }

   int swap = get(vector, insertion_i);
   set(vector, el, insertion_i);
   return insertion(vector, swap, insertion_i + 1);
}

void deletion(Vector* vector, int i) {
   if (i < -1) {
      printf("Index >= -1");
      exit(1);
   }

   if (i >= vector->len) {
      printf("I < vector length");
      exit(1);
   }

   if (i == vector->len -1 || i == -1) {
      *(vector->begin + vector->len - 1) = 0;
   }

   set(vector, i, 0);
   vector->len--;
}

int main() {
   int size = 2;
   int *init_arr = malloc(size * sizeof(int));
   init_arr[0] = 1;
   init_arr[1] = 3;
   Vector* vector = new_vector(init_arr, size);
   free(init_arr);
   free(vector->begin);
   free(vector);
}