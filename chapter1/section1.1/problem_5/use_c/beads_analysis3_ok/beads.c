/*
ID: wernheo1
LANG: C
TASK: beads
*/

/* This solution simply changes the string s into ss, then for every starting
// symbol it checks if it can make a sequence simply by repeatedly checking 
// if a sequence can be found that is longer than the current maximum one.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  FILE *input, *output;
  input = fopen("beads.in","r");
  output = fopen("beads.out","w");

  int n, max=0, current, state, i, j;
  char c;
  char tmp[400],s[800];
  fscanf(input,"%d %s",&n,tmp);
  strcpy(s,tmp);
  strcat(s,tmp);
  
  for(i=0; i<n; i++) {
    c = (char) s[i];
    if(c == 'w')
      state = 0;
    else
      state = 1;
    j = i;
    current = 0;
    while(state <= 2) { 
      // dont go further in second string than starting position in first string
      while(j<n+i && (s[j] == c || s[j] == 'w')) { 
        current++;
        j++;
      }
      state++;
      c = s[j];
    }
    if(current > max)
      max = current;
  }
    
  fprintf(output,"%d\n",max);
  fclose(input);
  fclose(output);
  exit(0);
  return 0;
}
