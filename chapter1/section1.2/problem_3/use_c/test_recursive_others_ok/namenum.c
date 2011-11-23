#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 12

char num[WIDTH+1],sol[WIDTH+1];
int maxlen;
void calc (int charloc) {
  if (charloc == maxlen) {
    sol[charloc] = '\0';
    printf("%s\n", sol);
    return;
  }
  switch(num[charloc]){
    case '2':sol[charloc] = 'A'; calc(charloc+1);
	     sol[charloc] = 'B'; calc(charloc+1);
	     sol[charloc] = 'C'; calc(charloc+1);
	     break; 
    case '3':sol[charloc] = 'D'; calc(charloc+1);
	     sol[charloc] = 'E'; calc(charloc+1);
	     sol[charloc] = 'F'; calc(charloc+1);
	     break; 
    case '4':sol[charloc] = 'G'; calc(charloc+1);
	     sol[charloc] = 'H'; calc(charloc+1);
	     sol[charloc] = 'I'; calc(charloc+1);
	     break; 
    case '5':sol[charloc] = 'J'; calc(charloc+1);
	     sol[charloc] = 'K'; calc(charloc+1);
	     sol[charloc] = 'L'; calc(charloc+1);
	     break; 
    case '6':sol[charloc] = 'M'; calc(charloc+1);
	     sol[charloc] = 'N'; calc(charloc+1);
	     sol[charloc] = 'O'; calc(charloc+1);
	     break; 
    case '7':sol[charloc] = 'P'; calc(charloc+1);
	     sol[charloc] = 'R'; calc(charloc+1);
	     sol[charloc] = 'S'; calc(charloc+1);
	     break; 
    case '8':sol[charloc] = 'T'; calc(charloc+1);
	     sol[charloc] = 'U'; calc(charloc+1);
	     sol[charloc] = 'V'; calc(charloc+1);
	     break; 
    case '9':sol[charloc] = 'W'; calc(charloc+1);
	     sol[charloc] = 'X'; calc(charloc+1);
	     sol[charloc] = 'Y'; calc(charloc+1);
	     break;
  }
}

int main(){
  //num[0]='2'; num[1]='3'; num[2]='4'; num[3]='\0';
  num[0]='4';
  num[1]='7';
  num[2]='3';
  num[3]='4';
  num[4]='\0';
  maxlen = strlen(num);
  calc (0);

  return 0;
}
