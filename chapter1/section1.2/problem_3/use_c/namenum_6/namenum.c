/*
ID: wernheo1
LANG: C
TASK: namenum
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#define LIMIT 15

int main() {
  int i;
  char map[8][3]={
    {'A','B','C'}, {'D','E','F'}, {'G','H','I'}, {'J','K','L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'}
  };
  int brand_number=0;
  FILE *in,*out;
  in = fopen("namenum.in", "r");
  out = fopen ("namenum.out", "w");
  fscanf(in, "%d", &brand_number);


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
  printf("size is %d\n",size);
  /*
  if (size==1) {
  }
  else if (size==2) {
  }
  else if (size==3) {
  }
  else if (size==4) {
  */
    //int j1,j2,j3,j4;
    int j[4];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    //printf("%c%c%c%c\n",map[brand_digit[0]-2][j1],map[brand_digit[1]-2][j2],map[brand_digit[2]-2][j3],map[brand_digit[3]-2][j4]);
	    char str2[LIMIT];
	    /*
	    str2[0]=map[brand_digit[0]-2][j1];
	    str2[1]=map[brand_digit[1]-2][j2];
	    str2[2]=map[brand_digit[2]-2][j3];
	    str2[3]=map[brand_digit[3]-2][j4];
	    str2[4]='\0';
	    */
	    int k;
	    for (k=0;k<4;k++) {
	      str2[k]=map[brand_digit[k]-2][j[k]];
	    }
	    str2[k]='\0';
	    printf("%s\n",str2);
	    FILE *data;
	    data=fopen("namenumdict.txt","r");
	    char str[LIMIT];
	    int res=0;
	    do {
	      res=fscanf(data,"%s",str);
	      //if (strcmp(str2,str)==0) { find=1; printf("%s\n",str); }
	      if (strcmp(str2,str)==0) { fprintf(out,"%s\n",str); }
	      //printf("%s\n",str);
	    }while(res != EOF);
	    fclose(data);
	  }
	}
      }
    }
    /*
  }
  else if (size==5) {
  }
  */

  return 0;
}
