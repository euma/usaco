/*
ID: wernheo1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
  int i,j,size,temp;
  FILE *in,*out;
  in = fopen("test.6.longest.milk", "r");
  out = fopen ("test.6.longest.time.list", "w");
  fscanf(in, "%d", &size);

  int time[2*size];
  for (i=0;i<size;i+=2) {
    fscanf(in, "%d %d", &time[i],&time[i+1]);
    if (time[i]<=0) { printf("%d\n",time[i]); }
    if (time[i+1]<=0) { printf("%d\n",time[i+1]); }
  }
  fclose(in);

  for (i = (size - 1); i > 0; i--) {
    for (j = 1; j <= i; j++) {
      if (time[i]<=0) { printf("%d\n",time[i]); }
      if (time[i+1]<=0) { printf("%d\n",time[i+1]); }
      if (time[j-1] > time[j]) {
        temp = time[j-1];
        time[j-1] = time[j];
        time[j] = temp;
      }
    }
  }
  for (i=0;i<2*size;i++) {
    if (time[i]<=0) { printf("i=%d: %d\n",i,time[i]); }
    fprintf(out, "%d ", time[i]);
  }
  fclose(out);
  return 0;
}
