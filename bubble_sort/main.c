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

void sort(int *a, int size) {
  int i = 0; // 未ソート部分列の先頭インデックス
  int flag = 1; // 走査が必要か否か
  while (flag) {
    flag = 0;
    for (int j = size - 1; i < j; j--) {
      if (a[j] < a[j - 1]) {
        swap(a, j - 1, j);

        // swapが発生したら再度swapする必要があるかもしれないので、再度走査する
        flag = 1;
      }
    }
    i++;
    dump(a, size);
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
