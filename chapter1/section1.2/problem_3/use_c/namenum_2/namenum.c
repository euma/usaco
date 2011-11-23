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
  printf("part one ok!\n");

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
  printf("part two ok!\n");
  int j1,j2,j3,j4;
  for(j1=0;j1<3;j1++) {
    for(j2=0;j2<3;j2++) {
     for(j3=0;j3<3;j3++) {
        for(j4=0;j3<3;j3++) {
          printf("%c%c%c%c\n",map[brand_digit[0]-2][j1],map[brand_digit[1]-2][j2],map[brand_digit[2]-2][j3],map[brand_digit[3]-2][j4]);
	}
      }
    }
  }
  return 0;
}
