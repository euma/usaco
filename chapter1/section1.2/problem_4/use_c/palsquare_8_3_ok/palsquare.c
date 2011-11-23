/*
ID: wernheo1
LANG: C
TASK: palsquare
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int is_palindrome(int *number, int size);
void convert_base(int number, int base, int *buffer, int buffer_size);
//double log_base(int number, int base);
int log_base(int number, int base);

int main() {
  int max_n=300;
  FILE *in,*out;
  in = fopen("palsquare.in", "r");
  out = fopen ("palsquare.out", "w");
  int base;
  fscanf(in, "%d", &base);
  fclose(in);

  int i;
  //double log_max=log_base(max_n*max_n, 2); int max_size=(int)log_max+1;
  int max_size=log_base(max_n*max_n, 2); 
  int buffer[max_size];

  //double log_max_i=log_base(max_n, 2); int max_size_i=(int)log_max_i+1;
  int max_size_i=log_base(max_n, 2); 
  int buffer_i[max_size_i];


  for (i=1;i<=max_n;i++) {
    int square=i*i;
    //double log_square=log_base(square, base); int buffer_size=(int)log_square+1;
    int buffer_size=log_base(square, base);
    convert_base(square, base, buffer, buffer_size);
    
    if ( is_palindrome(buffer, buffer_size) ) {
      printf("%d %d %d\n",i, square, buffer_size);
      //double log_base_i=log_base(i, base); int buffer_size_i=(int)log_base_i+1;
      int buffer_size_i=log_base(i, base);
      convert_base(i, base, buffer_i, buffer_size_i);
      int j;
      for (j=0;j<buffer_size_i;j++) {
	if (buffer_i[j]<10) {
	  fprintf(out, "%d",buffer_i[j]);
	}
	else if (buffer_i[j]==10) {
	  fprintf(out,"%c",'A');
	}
	else if (buffer_i[j]==11) {
	  fprintf(out,"%c",'B');
	}
	else if (buffer_i[j]==12) {
	  fprintf(out,"%c",'C');
	}
	else if (buffer_i[j]==13) {
	  fprintf(out,"%c",'D');
	}
	else if (buffer_i[j]==14) {
	  fprintf(out,"%c",'E');
	}
	else if (buffer_i[j]==15) {
	  fprintf(out,"%c",'F');
	}
	else if (buffer_i[j]==16) {
	  fprintf(out,"%c",'G');
	}
	else if (buffer_i[j]==17) {
	  fprintf(out,"%c",'H');
	}
	else if (buffer_i[j]==18) {
	  fprintf(out,"%c",'I');
	}
	else if (buffer_i[j]==19) {
	  fprintf(out,"%c",'J');
	}
	else {
	  printf("other thing happened!\n");
	}
      }
      fprintf(out," ");

      for (j=0;j<buffer_size;j++) {
	if (buffer[j]<10){
	  fprintf(out, "%d",buffer[j]);
	}
	else if (buffer[j]==10) {
	  fprintf(out,"%c",'A');
	}
	else if (buffer[j]==11) {
	  fprintf(out,"%c",'B');
	}
	else if (buffer[j]==12) {
	  fprintf(out,"%c",'C');
	}
	else if (buffer[j]==13) {
	  fprintf(out,"%c",'D');
	}
	else if (buffer[j]==14) {
	  fprintf(out,"%c",'E');
	}
	else if (buffer[j]==15) {
	  fprintf(out,"%c",'F');
	}
	else if (buffer[j]==16) {
	  fprintf(out,"%c",'G');
	}
	else if (buffer[j]==17) {
	  fprintf(out,"%c",'H');
	}
	else if (buffer[j]==18) {
	  fprintf(out,"%c",'I');
	}
	else if (buffer[j]==19) {
	  fprintf(out,"%c",'J');
	}
	else {
	  printf("other thing happened!\n");
	}
      }
      fprintf(out,"\n");
    }
  }
  fclose(out);

  exit(0);
  return 0;
}
int is_palindrome(int *number, int size) {
  int i=size-1;
  int j=0;
  while(i>j) {
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
    number_tmp /= base;
  }
}
/*
double log_base(int number, int base) {
  return log(number)/log(base);
}
*/
int log_base(int number, int base) {
  int i=0;
  while (number > 0) {
    number /= base;
    i++;
  }
  return i;
}
