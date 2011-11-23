#include<stdio.h>
#define LIMIT 5

void print_recursive(int size_i, int size);
int size;
int arr[LIMIT];

int main() {
  size=2;
  arr[0]=8;
  arr[1]=12;
  print_recursive(size, size);

  return 0;
}

void print_recursive(int size_i, int size) {
  //printf("%d\n",size-size_i);
  printf("%d\n",arr[size-size_i]);
  //if (size_i<=0) {
  if (size_i<=1) {
    return;
  }
  else {
    print_recursive(size_i-1, size);
  }
}

