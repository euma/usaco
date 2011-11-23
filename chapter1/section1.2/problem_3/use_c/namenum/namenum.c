#include<stdio.h>
#include<math.h>
#define LIMIT 12
int main() {
  int i,j;
  char map[8][3]={
    {'A','B','C'}, {'D','E','F'}, {'G','H','I'}, {'J','K','L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'}
  };
  for (i=0;i<8;i++) {
    printf("%d: ",i+2);
    for (j=0;j<3;j++) {
      printf("%c ",map[i][j]);
    }
    printf("\n");
  }

  int brand_number=4734;
  int size = log10(brand_number) + 1;
  int brand_digit[size];
  i = size;
  while(i >= 0) {
    brand_digit[--i] = brand_number % 10;
    brand_number /= 10;
  }
  for (i=0;i<size;i++) {
    printf("%d\n",brand_digit[i]);
  }
  return 0;
}
