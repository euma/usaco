/*
ID: wernheo1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>

/*this time I don't use is connect function*/

int is_connect(int start1,int end1,int start2,int end2);

int main() {
  int i,j,size,temp;
  FILE *in,*out;
  //in = fopen("milk2.in.sort.part", "r");
  in = fopen("milk2.in", "r");
  out = fopen ("milk2.out", "w");
  fscanf(in, "%d", &size);

  int start[size];
  int end[size];
  for (i=0;i<size;i++) {
    fscanf(in, "%d %d", &start[i],&end[i]);
  }
  fclose(in);

  for (i = (size - 1); i > 0; i--) {
    for (j = 1; j <= i; j++) {
       if (start[j-1] > start[j]) {
         temp = start[j-1];
         start[j-1] = start[j];
         start[j] = temp;
         temp = end[j-1];
         end[j-1] = end[j];
         end[j] = temp;
       }
    }
  }
  
  int idle_time=0;
  int longest_idle_time=0;

  int milk_time=0;
  int longest_milk_time=0;

  int connect_start=0;
  int connect_end=0;
  i=0;
  while (i<size) {
    j=i+1;
    while (j<size && start[j]<=end[connect_end]) {
      if (end[j]>=end[connect_end]) { connect_end=j; }
      j++;
    }
    milk_time=end[connect_end]-start[connect_start];
    if (milk_time > longest_milk_time) { longest_milk_time=milk_time; }
    if (j<size) {
      idle_time=start[j]-end[connect_end];
      if (idle_time > longest_idle_time) { longest_idle_time=idle_time; }
    }
    i=j;
    connect_start=i;
    connect_end=i;
  }
  fprintf(out,"%d %d\n",longest_milk_time,longest_idle_time);
  fclose(out);
  return 0;
}
