/*
ID: wernheo1
LANG: C
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>
#define LIMIT 1000000

int main() {
  int i,j,size;
  FILE *in,*out;
  in = fopen("milk2.in", "r");
  out = fopen ("milk2.out", "w");
  fscanf(in, "%d", &size);
  int beginning,ending;
  int max_ending=0, min_beginning=LIMIT+1;

  char milking[LIMIT];
  char flowing[LIMIT];
  for (i=0;i<LIMIT;i++) {
    milking[i]=0;flowing[i]=0;
  }
  for (i=0;i<size;i++) {
    fscanf(in, "%d %d", &beginning,&ending);
    if (ending>max_ending) { max_ending=ending; }
    if (beginning<min_beginning) { min_beginning=beginning; }
    for (j=beginning;j<=ending;j++) {
      milking[j]=1;flowing[j]=1;
      if (j==ending) { flowing[j]=0; }
    }
  }

  int milk_time=0;
  int longest_milk_time=-1;
  int idle_time=0;
  int longest_idle_time=-1;

  for (i=min_beginning;i<=max_ending;i++) {
    if (milking[i]==1 && flowing[i]==1) {
      if (idle_time > longest_idle_time) {
        longest_idle_time=idle_time;
      }
      idle_time=0;
      milk_time++;
    }
    else if (milking[i]==1 && flowing[i]==0) {
      if (milk_time > longest_milk_time) {
        longest_milk_time=milk_time;
      }
      milk_time=0;
      idle_time++;
    }
    else if (milking[i]==0 && flowing[i]==0) {
      idle_time++;
    }
  }
  fprintf(out,"%d %d\n",longest_milk_time,longest_idle_time);

  exit(0);
  return 0;
}
