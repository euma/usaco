/*
ID: wernheo1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>

int is_connect(int start1,int end1,int start2,int end2);

int main() {
  int i,j,i_start,size,temp;
  FILE *in,*out;
  in = fopen("milk2.in", "r");
  out = fopen ("milk2.out", "w");
  fscanf(in, "%d", &size);

  int start[size];
  int end[size];
  for (i=0;i<size;i++) {
    fscanf(in, "%d %d", &start[i],&end[i]);
  }

  printf("sort before:\n");
  for (i=0;i<size;i++) {
    printf("%d %d\n",start[i],end[i]);
  }
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
  printf("sort after:\n");
  for (i=0;i<size;i++) {
    printf("%d %d\n",start[i],end[i]);
  }
  int idle_time=0;
  int longest_idle_time=0;

  int milk_time=0;
  int longest_milk_time=0;

  int connect_start;
  int connect_end;

  connect_end=0;/*i stand for current connect start point*/
  connect_start=connect_end;
  while (connect_end<size-1) {
    int find=0;
    for (j=connect_end+1;j<size;j++) {
      if (is_connect(start[connect_end],end[connect_end],start[j],end[j])) {
        find++;
        if (end[j]>=end[connect_end]) {
          connect_end=j;
        }
      }
      else { break; }
    }
    if (find > 0) { continue; }
    else {
      printf("%d\n",connect_end);
       milk_time=end[connect_end]-start[connect_start];
      if (milk_time > longest_milk_time) { longest_milk_time=milk_time; }
      if (connect_end+1<size) {
        idle_time=start[connect_end+1]-end[connect_end];
        if (idle_time > longest_idle_time) { longest_idle_time=idle_time; }
        connect_start=connect_end+1;
      }
      connect_end++;
    }
  }
  printf("%d %d\n",longest_milk_time,longest_idle_time);
  return 0;
}
int is_connect(int start1,int end1,int start2,int end2) {
  if (start1<=start2 && start2<=end1) {
    return 1;
  }
  else if (start1<=end2 && end2<=end1) {
    return 1;
  }
  else { return 0; }
}
