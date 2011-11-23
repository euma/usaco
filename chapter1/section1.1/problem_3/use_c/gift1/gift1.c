/*
ID: wernheo1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_LEN 20

int main(void)
{
  FILE *in, *out;
  char * return_pointer;
  int NP=0;
  char str_buf[MAX_LEN + 1]; // One extra byte needed for the null character

  //in = fopen("input.txt", "r");
  //in = fopen("ride.in", "r");
  in = fopen("gift1.in", "r");
  if (in == NULL) {
    perror("Failed to open file \"gift1.in\"");
    exit (1);
    //return EXIT_FAILURE;
  }

  //while(fgets(str_buf, sizeof str_buf, in) != NULL)
  return_pointer=fgets(str_buf, sizeof str_buf, in);
  if (return_pointer == NULL) {
    perror("Failed to get string in opened file \"gift1.in\"");
    exit (2);
    //return EXIT_FAILURE;
  }
  NP=atoi(str_buf);
  printf("%d\n",NP);
   //puts(str_buf);
  //out = fopen("output.txt", "w");
  out = fopen("gift1.out", "w");
  //fgets(group, sizeof group, in);

  //fprintf(out, "GO\n");
  fclose(in);
  fclose(out);
  exit (0);
  return 0;
}
