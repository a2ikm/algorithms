#include <stdio.h>

void dump (int *a, int size) {
  for (int i = 0; i < size; i++) {
    if (i > 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

void swap(int *a, int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void sort(int *a, int n) {
  int i = 0; // 未ソート部分列の先頭インデックス

  while (i < n) {
    dump(a, n);
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (i < minj) {
      swap(a, i, minj);
    }
    i++;
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
