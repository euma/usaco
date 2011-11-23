#include<stdio.h>
#include<math.h>
#define N 30

int is_palindrome(char *number, int size);
void convert_base(int number, int base, int *buffer, int buffer_size);
double log_base(int number, int base);

int main() {
  /*
  is_palindrome function test is OK!
  int size=3;
  char number[size+1];
  number[0]='1'; number[1]='2'; number[2]='2'; number[3]='\0';
  */
  /*
  int size=4;
  char number[size+1];
  number[0]='1'; number[1]='2'; number[2]='3'; number[3]='1';number[4]='\0'; 
  if (is_palindrome(number, size)) {
    printf("%s is palindrome\n",number);
  }
  else {
    printf("%s is not palindrome\n",number);
  }
  */
  /*
  for (i=1;i<=N;i++) {
    int square=i*i;
    printf("%d %d\n",i,square);
  }
  */
  /*
  int base=4;
  int number=5;
  double log_number=log_base(number, base);
  printf("%f\n",log_number);
  printf("%d\n",(int)log_number);
  printf("base size = ");
  if (log_number != (int)log_number) {
    printf("%d\n",(int)log_number+1);
  }
  else {
    printf("%d\n",(int)log_number);
  }
  */
  int base=2;
  int number=5;
  double log_number=log_base(number, base);
  int buffer_size=0;
  if (log_number != (int)log_number) {
    buffer_size=(int)log_number+1;
  }
  else {
    buffer_size=(int)log_number;
  }
  printf("%d\n",buffer_size);
  int buffer[buffer_size];
  convert_base(number, base, buffer, buffer_size);
  int i;
  for (i=0;i<buffer_size;i++) {
    printf("%d(%c)",buffer[i]);
  }

  return 0;
}
int is_palindrome(char *number, int size) {
  int i=size-1;
  int j=0;
  while(i>j) {
    if(number[i]!=number[j]) {
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
    printf("%d %d\n",buffer_size,base_number);
    buffer_size--;
    buffer[buffer_size]=base_number;
    number_tmp /= base;
  }
}
double log_base(int number, int base) {
  return (log(number)/log(base));
}
