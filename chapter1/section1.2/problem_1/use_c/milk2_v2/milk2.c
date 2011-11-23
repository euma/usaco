#include<stdio.h>
int main() {
  int i, j, temp;
  int size=3;
  int start[3]={300,1500,700};
  int end[3]={1000,2100,1200};

  printf("sort before:\n");
  for (i=0;i<size;i++) {
    printf("%d %d\n",start[i],end[i]);
  }
  printf("---------------------\n");
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
  printf("---------------------\n");
  int in_interval=1;
  int milk_time=0;
  int longest_milk_time=0;
  int idle_time=0;
  int longest_idle_time=0;
  int end_time=0;
  for (i=0;i<size;i++) {
    if (end[i]>end_time) { end_time=end[i]; }
  }
  for (i=start[0];i<end_time;i++) {
    
    int not_find=0;
    for (j=0;j<size;j++) {
      if (i>=start[j] && i<=end[j]) {
        break;
      }
      else { not_find++; }
    }
    if (not_find == size) {
      in_interval=0;
      if (milk_time > longest_milk_time) {
        longest_milk_time=milk_time;
      }
      milk_time=0;
    }
    else {
      in_interval=1;
      if (idle_time > longest_idle_time) {
        longest_idle_time=idle_time;
      }
      idle_time=0;
    }
    if (in_interval==1) { milk_time++; }
    else { idle_time++; }
  }
  printf("%d %d\n",longest_milk_time-1,longest_idle_time+1);
  return 0;
}
