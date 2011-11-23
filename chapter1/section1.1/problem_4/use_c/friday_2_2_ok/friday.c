/*
ID: wernheo1
LANG: C
TASK: friday
*/

#include<stdio.h>
#include<stdlib.h>

int is_leap_year(int year);

int main() {

  int N=0;
  int start_year=1900;
  int start_month=1;
  int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  int week[8]={0};
  int start_day=1;
  int start_week=1;
  int current_week=start_week;
  int i,j,k;

  FILE *fin, *fout;
  fin = fopen("friday.in", "r");
  fout = fopen("friday.out", "w");

  fscanf(fin,"%d",&N);
  //printf("%d\n",N);
  int last_year=1900+N-1;

  for (i=start_year;i<=last_year;i++) {
    if (is_leap_year(i)) {
      month[2]=29;
    } else {
      month[2]=28;
    }
    for (j=start_month;j<=12;j++) {
      for (k=start_day;k<=month[j];k++) {
	if (current_week % 7 == 1) { current_week=1; }
	if (k == 13) { week[current_week]++; }
	current_week++;
      }
    }
  }
  fprintf(fout,"%d ",week[6]);
  fprintf(fout,"%d ",week[7]);
  for (i=1;i<5;i++) {
    fprintf(fout,"%d ",week[i]);
  }
  fprintf(fout,"%d\n",week[5]);
  exit(0);
  return 0;
}
int is_leap_year(int year) {
 /* 
 // leap year:
 // is divisable by 4 and not by 100
 // is divisable by 400 
 */
 if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  return 1; /* leap */
 else
  return 0; /* no leap */
}
