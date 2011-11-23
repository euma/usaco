#include<stdio.h>
int is_connect(int start1,int end1,int start2,int end2) {
  if (start1<=start2 && start2<=end1) {
    return 1;
  }
  else if (start1<=end2 && end2<=end1) {
    return 1;
  }
  else { return 0; }
}
int main() {
  int j, i_start; //temp;
  int size=3;
  int start[3]={300,700,1500};
  int end[3]={1000,1200,2100};

//  printf("sort before:\n");
//  for (i=0;i<size;i++) {
//    printf("%d %d\n",start[i],end[i]);
//  }
//  for (i = (size - 1); i > 0; i--) {
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
//  for (i=0;i<size;i++) {
//    printf("%d %d\n",start[i],end[i]);
//  }
  int idle_time=0;
  int longest_idle_time=0;

  int milk_time=0;
  int longest_milk_time=0;

  int connect_end;
  int connect_start;

  i_start=0;/*i stand for current connect start point*/
  connect_start=i_start;
  while (i_start<size-1) {
    int find=0;
    for (j=i_start+1;j<size;j++) {
      if (is_connect(start[i_start],end[i_start],start[j],end[j])) {
        find++;
        if (end[j]>=end[i_start]) {
          i_start=j;
        }
      }
      else { break; }
    }
    if (find > 0) { continue; }
    else {
      printf("%d\n",i_start);
       milk_time=end[i_start]-start[connect_start];
      if (milk_time > longest_milk_time) { longest_milk_time=milk_time; }
      if (i_start+1<size) {
        idle_time=start[i_start+1]-end[i_start];
        if (idle_time > longest_idle_time) { longest_idle_time=idle_time; }
        connect_start=i_start+1;
      }
      i_start++;
    }
  }
  printf("%d %d\n",longest_milk_time,longest_idle_time);
  return 0;
}
