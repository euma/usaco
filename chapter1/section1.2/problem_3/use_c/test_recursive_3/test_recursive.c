#include<stdio.h>

void print_recursive(int size_i, int size);
int main() {
  int size=2;
  print_recursive(size, size);
  return 0;
}
void print_recursive(int size_i, int size) {
  printf("%d\n",size-size_i);
  //if (size_i<=0) {
  if (size_i<=1) {
    return;
  }
  else {
    print_recursive(size_i-1, size);
  }
}

