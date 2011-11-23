#include<stdio.h>
#define N 30

int is_palindrome(char *num, int size);
void convert_base(int num, int base);

int main() {
  int base=2;
  int i;
  for (i=1;i<=N;i++) {
    int square=i*i;
    printf("%d %d ",i,square);
    convert_base(square, base);
    printf("\n");
  }

  return 0;
}
int is_palindrome(char *num, int size) {
  int i=size-1;
  int j=0;
  while(i>j) {
    if(num[i]!=num[j]) {
      return 0;
    }
    else {
      i--;
      j++;
    }
  }
  return 1;
}
void convert_base(int num, int base) {
  int num_tmp=num;
  while (num_tmp!=0) {
    int base_num=num_tmp % base;
    num_tmp /= base;
    printf("%d",base_num);
  }
}
