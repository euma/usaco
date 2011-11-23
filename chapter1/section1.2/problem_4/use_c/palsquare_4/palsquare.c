#include<stdio.h>
#include<math.h>
#define N 20

int is_palindrome(int *number, int size);
void convert_base(int number, int base, int *buffer, int buffer_size);
double log_base(int number, int base);

int main() {

  int base=10;
  int i,j;
  int buffer[N*N];
  for (i=1;i<=N;i++) {
    int square=i*i;
    double log_square=log_base(square, base);
    int buffer_size=(int)log_square+1;
    printf("%d %d (%d) ", i, square, buffer_size);
    convert_base(square, base, buffer, buffer_size);
    for (j=0;j<buffer_size;j++) {
      printf("%d",buffer[j]);
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
