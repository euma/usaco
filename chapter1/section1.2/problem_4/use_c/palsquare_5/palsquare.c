#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 20

int is_palindrome(int *number, int size);
void convert_base(int number, int base, int *buffer, int buffer_size);
double log_base(int number, int base);

int main() {

  int base=16;
  int i,j;
  int buffer[N*N];
  for (i=1;i<=N;i++) {
    int square=i*i;
    double log_square=log_base(square, base);
    int buffer_size=(int)log_square+1;
    printf("%d %d (%d) ", i, square, buffer_size);
    convert_base(square, base, buffer, buffer_size);
    for (j=0;j<buffer_size;j++) {
      if (buffer[j]<10) {
        printf("%d",buffer[j]);
      }
      else if (buffer[j]==10) {
        printf("%c",'A');
      }
      else if (buffer[j]==11) {
        printf("%c",'B');
      }
      else if (buffer[j]==12) {
        printf("%c",'C');
      }
      else if (buffer[j]==13) {
        printf("%c",'D');
      }
      else if (buffer[j]==14) {
        printf("%c",'E');
      }
      else if (buffer[j]==15) {
        printf("%c",'F');
      }
      else if (buffer[j]==16) {
        printf("%c",'G');
      }
      else if (buffer[j]==17) {
        printf("%c",'H');
      }
      else if (buffer[j]==18) {
        printf("%c",'I');
      }
      else if (buffer[j]==19) {
        printf("%c",'J');
      }
      else if (buffer[j]==20) {
        printf("%c",'K');
      }
      else {
	exit(1);
      }
    }

    if (is_palindrome(buffer, buffer_size)) {
      printf(" is palindrome\n");
    }
    else { 
      printf("\n");
    }
  }

  return 0;
}
int is_palindrome(int *number, int size) {
  int i=size-1;
  int j=0;
  while(i>j) {
    printf(" (%d<%d>,%d<%d>)",number[i],i,number[j],j);
    if( number[i] != number[j] ) {
      return 0;
    }
    else {
      i--;
      j++;
    }
  }
  return 1;
}
void convert_base(int number, int base, int *buffer, int buffer_size) {
  int number_tmp=number;
  while (number_tmp!=0) {
    int base_number=number_tmp % base;
    buffer_size--;
    buffer[buffer_size]=base_number;
    //printf("(%d %d)",buffer_size,base_number);
    number_tmp /= base;
  }
}
double log_base(int number, int base) {
  return (log(number)/log(base));
}
