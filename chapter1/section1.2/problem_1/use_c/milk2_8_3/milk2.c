/*
ID: wernheo1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>

int is_connect(int start1,int end1,int start2,int end2);
/*this time I can bubble sort a little*/
int main() {
  int i,j,size,temp;
  FILE *in,*out;
  //in = fopen("milk2.in.sort.part.2", "r");
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
       if ((start[j-1] == start[j]) && (end[j-1]>end[j])) {
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
    int find=0;
    int tmp_i=i;
    j=i+1;
    while (j<size) {
      if (is_connect(start[i],end[i],start[j],end[j])==1) {
        printf("%d %d* ",start[j],end[j]);
        find++;
        tmp_i=j;
        if (end[j]>end[connect_end]){ connect_end=j; }
      }
      else { break; }
      j++;
    }
    printf("\n--------------------\n");
    if (find == 0) {
      //printf("\n###############################\n");
      printf("connect point: %d: %d(%d) %d(%d)",tmp_i,connect_start,start[connect_start],connect_end,end[connect_end]);
      milk_time=end[connect_end]-start[connect_start];
      printf("-> %d, ",milk_time);
      if (milk_time > longest_milk_time) {
        //printf("\n###############################\n");
        //printf("longest connect point: %d: %d(%d) %d(%d)",tmp_i,connect_start,start[connect_start],connect_end,end[connect_end]);
        //printf("-> %d, ",milk_time);
        //printf("\n###############################\n");
        longest_milk_time=milk_time;
      }
      if (connect_end+1<size && tmp_i+1<size) {
        idle_time=start[tmp_i+1]-end[connect_end];
        printf("%d\n",idle_time);
        if (idle_time > longest_idle_time) {
          //printf("%d\n",idle_time);
          longest_idle_time=idle_time;
          //printf("###############################\n");
        }
      }
      //printf("###############################\n");
      i=tmp_i+1;
      connect_start=i;
      connect_end=i;
    } else { i=tmp_i; }
  }
  fprintf(out,"%d %d\n",longest_milk_time,longest_idle_time);
  fclose(out);
  return 0;
}
int is_connect(int start1,int end1,int start2,int end2) {
  if (start1<=end2 && end2<=end1) {
    return 1;
  }
  else if (start1<=start2 && start2<=end1) {
    return 1;
  }
  else { return 0; }
}
