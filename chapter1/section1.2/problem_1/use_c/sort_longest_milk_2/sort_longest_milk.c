/*
ID: wernheo1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
  int i,j,k,size,temp;
  FILE *in,*out;
  in = fopen("test.6.longest.milk", "r");
  out = fopen ("test.6.longest.time.list", "w");
  fscanf(in, "%d", &size);

  int time[2*size];
  for (i=0;i<2*size;i++) {
    fscanf(in, "%d", &time[i]);
    if (time[i]<=0) { printf("%d\n",time[i]); }
  }
  fclose(in);

  for (i = (2*size - 1); i > 0; i--) {
    for (j = 1; j <= i; j++) {
      if (time[j-1] > time[j]) {
        temp = time[j-1];
        time[j-1] = time[j];
        time[j] = temp;
      }
    }
    for (k=0;k<=i;k++) {
      printf("%d ", time[k]);
    }
    printf("\n");
  }
  for (i=0;i<2*size;i++) {
    fprintf(out, "%d ", time[i]);
  }
  fclose(out);
  return 0;
}
