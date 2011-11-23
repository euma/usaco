#include<stdio.h>
#define SIZE 11

int main() {
  int i, j;// temp;
  int start[SIZE]={3,8,15,20,29,45,57,62,99,120,137};
  int end[SIZE]={10,18,27,33,39,47,68,72,180,130,146};

//  printf("sort before:\n");
//  for (i=0;i<SIZE;i++) {
//    printf("%d %d\n",start[i],end[i]);
//  }
//  printf("---------------------\n");
//  for (i = (SIZE - 1); i > 0; i--) {
//    for (j = 1; j <= i; j++) {
//       if (start[j-1] > start[j]) {
//         temp = start[j-1];
//         start[j-1] = start[j];
//         start[j] = temp;
//         temp = end[j-1];
//         end[j-1] = end[j];
//         end[j] = temp;
//       }
//    }
//  }
//  printf("sort after:\n");
//  for (i=0;i<SIZE;i++) {
//    printf("%d %d\n",start[i],end[i]);
//  }
//  printf("---------------------\n");
  int in_interval=1;
  int milk_time=0;
  int longest_milk_time=0;
  int idle_time=0;
  int longest_idle_time=0;
  int end_time=0;
  for (i=0;i<SIZE;i++) {
    if (end[i]>end_time) { end_time=end[i]; }
  }
  for (i=start[0];i<=end_time;i++) {
    
    int not_find=0;
    for (j=0;j<SIZE;j++) {
      if (i>=start[j] && i<=end[j]) {
        break;
      }
      else { not_find++; }
    }
    if (i==end_time) {
      milk_time++;
      if (milk_time > longest_milk_time) {
        longest_milk_time=milk_time;
      }
    }
    if (not_find == SIZE) {
      if (in_interval==1) {
        //printf("from in to out at %d\n",i);
        in_interval=0; 
        if (milk_time > longest_milk_time) {
          longest_milk_time=milk_time;
        }
        milk_time=0;
      }
      idle_time++;
    }
    else {
      if (in_interval==0) {
        printf("from out to in at %d\n",i);
        in_interval=1;
        if (idle_time > longest_idle_time) {
          longest_idle_time=idle_time;
        }
        idle_time=0;
      }
      milk_time++;
    }
  }
  printf("%d %d\n",longest_milk_time-1,longest_idle_time+1);
  return 0;
}
