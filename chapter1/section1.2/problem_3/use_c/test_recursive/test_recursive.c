#include<stdio.h>
#include<math.h>
#define LIMIT 15

int main() {

  int i;
  char map[8][3]={
        {'A','B','C'}, {'D','E','F'}, {'G','H','I'}, {'J','K','L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'}
	  };
  int brand_number=234;
  int size = (int)log10(brand_number) + 1;
  int brand_digit[size];
  i = size;
  while(i >= 0) {
    brand_digit[--i] = brand_number % 10;
    brand_number /= 10;
  }
  for (i=0;i<size;i++) {
    printf("%d\n",brand_digit[i]);
  }
  printf("size is %d\n",size);

  int j[size];
  for(j[0]=0;j[0]<3;j[0]++) {
    for(j[1]=0;j[1]<3;j[1]++) {
      for(j[2]=0;j[2]<3;j[2]++) {
	char name2[LIMIT];
	int k;
	for (k=0;k<size;k++) {
	  name2[k]=map[brand_digit[k]-2][j[k]];
	}
	name2[k]='\0';
	printf("%s\n",name2);
      }
    }
  }

  return 0;
}
