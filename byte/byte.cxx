#include <stdio.h>

int add_two(int a, int b) {
  return a + b;
}

int add_three(int a, int b, int c) {
  return a + b + c;
}

int add_four(int a, int b, int c, int d) {
  return a + b + c + d;
}

int add_five(int a, int b, int c, int d, int f) {
  return a + b + c + d + f;
}

int main() {
  add_two(1, 2);
  add_three(1, 2, 3);
  add_four(1, 2, 3, 4);
  add_five(1, 2, 3, 4, 5);
  return 0;
}
