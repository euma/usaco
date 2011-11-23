/*
ID: wernheo1
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a,int b) {
  if (a>b) { return a; }
  else { return b; }
}
int min(int a,int b) {
  if (a>b) { return b; }
  else { return a; }
}
int main () {
  int i,j;
  FILE *in,*out;
  in = fopen("beads.in", "r");
  out = fopen ("beads.out", "w");

  int n;
  char tmp[400], s[800];
  fscanf(in, "%d %s", &n, tmp);

  strcpy(s, tmp);
  strcat(s, tmp);

  int left[800][2], right[800][2];
  int real_left[400][2], real_right[400][2];
  left[0][0] = left[0][1] = 0;
  /*left[i][j] j stands for r or b*/

  for (i=1; i<= 2 * n; i++){
    if (s[i - 1] == 'r'){
      left[i][0] = left[i - 1][0] + 1;
      left[i][1] = 0;
    } else if (s[i - 1] == 'b'){
      left[i][1] = left[i - 1][1] + 1;
      left[i][0] = 0;
    } else {
      left[i][0] = left[i - 1][0] + 1;
      left[i][1] = left[i - 1][1] + 1;
    }
  }
  /*collection real left 2d array*/
  for (j=0;j<2;j++) {
    for (i=0;i<n;i++) {
      if (left[i+n+1][j]>n) { real_left[i][j]=n; }
      else { real_left[i][j]=left[i+n+1][j]; }
    }
  }

  right[2 * n][0] = right[2 * n][1] = 0;
  for (i=2 * n - 1; i >= 0; i--){
    if (s[i] == 'r'){
      right[i][0] = right[i + 1][0] + 1;
      right[i][1] = 0;
    } else if (s[i] == 'b'){
      right[i][1] = right[i + 1][1] + 1;
      right[i][0] = 0;
    } else {
      right[i][0] = right[i + 1][0] + 1;
      right[i][1] = right[i + 1][1] + 1;
    }
  }
  /*collection real right 2d array*/
  for (j=0;j<2;j++) {
    if (right[0][j] > n) { real_right[n-1][j]=n; }
    else { real_right[n-1][j]=right[0][j]; }
  }
  for (j=0;j<2;j++) {
    for (i=0;i<n-1;i++) {
      if (right[i+1][j]>n) { real_right[i][j]=n; }
      else { real_right[i][j]=right[i+1][j]; }
    }
  }

  int m = 0;
  for (i=0; i< n; i++)
    m = max(m, max(real_left[i][0], real_left[i][1]) + max(real_right[i][0], real_right[i][1]));
  m = min(m, n);
  fprintf(out, "%d\n", m);
  fclose(in);
  fclose(out);
  exit(0);
  return 0;
}
