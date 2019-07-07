#include <stdio.h>
#include <stdlib.h>

void dump (int *a, int size) {
  for (int i = 0; i < size; i++) {
    if (i > 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

void sort_internal(int *a, int n, int g) {
  int i, j, v;
  for (i = g; i < n; i++) {
    dump(a, n);
    v = a[i];
    for (j = i - g; (j >= 0) && (a[j] > v); j = j - g) {
      a[j + g] = a[j];
    }
    a[j + g] = v;
  }
}

void sort(int *a, int n) {
  int m = 2;
  int g[2] = { 1, 4 };
  for (int i = m - 1; i >= 0; i--) {
    sort_internal(a, n, g[i]);
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
