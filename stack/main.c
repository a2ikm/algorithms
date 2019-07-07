#include <stdio.h>
#include <stdlib.h>

int sc = 0, // stackの要素数
    stack[1000];

void push(int v) {
  stack[sc++] = v;
}

int pop() {
  int v = stack[--sc];
  return v;
}

int rpn(char *input) {
  int a, b, i = 0;
  char c;
  while ((c = input[i]) != '\0') {
    switch (c) {
      case '+':
        a = pop();
        b = pop();
        push(b + a);
        break;
      case '-':
        a = pop();
        b = pop();
        push(b - a);
        break;
      case '*':
        a = pop();
        b = pop();
        push(b * a);
        break;
      case '/':
        a = pop();
        b = pop();
        push(b / a);
        break;
      default:
        push((int)c - (int)'0');
    }
    i++;
  }
  return pop();
}

int main(int argc, char **args) {
  char input[] = "12+34-*";
  int result = rpn(input);
  if (result != -3) {
    printf("Expected %d but got %d\n", -3, result);
    return 1;
  }
  return 0;
}
