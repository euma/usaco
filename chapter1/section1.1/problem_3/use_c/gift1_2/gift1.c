/*
ID: wernheo1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20

int main(void)
{
  FILE *in, *out;
  char * return_pointer;
  int NP=0;
  int i=0;
  char str_buf[MAX_LEN + 1]; // One extra byte needed for the null character
  char name[10][15];

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
  for (i=0;i<NP;i++) {
    return_pointer=fgets(str_buf, sizeof str_buf, in);
    if (return_pointer == NULL) {
      perror("Failed to get string in opened file \"gift1.in\"");
      exit (i+3);
    }
    strcpy(name[i],str_buf);
  }
  for (i=0;i<NP;i++) {
    printf("%s\n",name[i]);
  }
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
