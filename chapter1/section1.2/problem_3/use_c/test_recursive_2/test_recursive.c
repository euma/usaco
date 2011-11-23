#include<stdio.h>

void print_recursive(int size);
int main() {
  int size=2;
  print_recursive(size);
  return 0;
}
void print_recursive(int size) {
  printf("%d\n",size);
  if (size<=0) {
    return;
  }
  else {
    print_recursive(size-1);
  }
}

