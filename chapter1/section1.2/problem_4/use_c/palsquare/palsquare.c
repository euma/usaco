#include<stdio.h>
#define N 300

int main() {
  int base=10;
  int i;
  for (i=1;i<=N;i++) {
    printf("%d %d\n",i,i*i);
  }
  return 0;
}
