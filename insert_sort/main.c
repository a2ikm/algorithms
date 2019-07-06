#include <stdio.h>

void sort(int *a, int size) {
  int i, j, v;
  for (i = 1; i < size; i++) {
    v = a[i];
    for (j = i - 1; (j >= 0) && (a[j] > v); j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = v;
  }
}

int main(int argc, char **args) {
  int a[10] = { 1, 9, 2, 0, 3, 8, 4, 7, 5, 6 };
  sort(a, 10);

  for (int i = 0; i < 10; i++) {
    if (a[i] != i) {
      printf("Expected %d but got %d\n", i, a[i]);
      return 1;
    }
  }

  return 0;
}
