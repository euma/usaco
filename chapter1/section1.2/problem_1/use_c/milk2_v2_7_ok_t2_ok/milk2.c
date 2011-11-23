/*
ID: wernheo1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>

int interval_position(int i,int start[],int end[],int size);
int main() {
  int i,j,size,temp;
  FILE *in,*out;
  in = fopen("milk2.in", "r");
  out = fopen ("milk2.out", "w");
  fscanf(in, "%d", &size);

  int start[size];
  int end[size];
  for (i=0;i<size;i++) {
    fscanf(in, "%d %d", &start[i],&end[i]);
  }

  /*use bubble sort to sort start time array and end time array*/
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

  int milk_time=0;
  int longest_milk_time=-1;
  int idle_time=0;
  int longest_idle_time=-1;
  int end_time=0;

  int current_state=1;
  int preview_state=0;
  /*state 0 mean outside of [a,b], a<b*/
  /*state 1 mean at a, a<b*/
  /*state 2 mean inside of (a,b), a<b*/
  /*state 3 mean at b, a<b*/
  for (i=0;i<size;i++) {
    if (end[i]>end_time) { end_time=end[i]; }
  }
  for (i=start[0];i<=end_time;i++) {
    current_state=interval_position(i,start,end,size);
    //printf("%d: %d %d %d %d\n",i,milk_time,idle_time, preview_state,current_state);
    if (preview_state==0 && current_state==1) {
      if (idle_time > longest_idle_time) {
        longest_idle_time=idle_time;
      }
      idle_time=0;
      milk_time++;
    }
    else if (preview_state==1 && current_state==2) {
      milk_time++;
    }
    else if (preview_state==2 && current_state==2) {
      milk_time++;
    }
    else if (preview_state==2 && current_state==3) {
      if (i+1>size && interval_position(i+1,start,end,size)!=2) {
        if (milk_time > longest_milk_time) {
          longest_milk_time=milk_time;
        }
        milk_time=0;
        idle_time++;
      } else {
        milk_time++;
      }
    }
    else if (preview_state==3 && current_state==2) {
      milk_time++;
    }
    else if (preview_state==3 && current_state==1) {
      if (idle_time > longest_idle_time) {
        longest_idle_time=idle_time;
      }
      idle_time=0;
      milk_time++;
    }
    else if (preview_state==3 && current_state==0) {
      idle_time++;
    }
    else if (preview_state==0 && current_state==0) {
      idle_time++;
    }
    preview_state=current_state;
  }
  fprintf(out,"%d %d\n",longest_milk_time,longest_idle_time);

  exit(0);
  return 0;
}
int interval_position(int i,int start[],int end[],int size) {
  int j;
  for (j=0;j<size;j++) {
    if (i>start[j] && i<end[j]) {
      return 2;
    }
  }
  for (j=0;j<size;j++) {
    if (i==end[j]) {
      return 3;
    }
  }
  for (j=0;j<size;j++) {
    if (i==start[j]) {
      return 1;
    }
  }
  return 0; 
}
