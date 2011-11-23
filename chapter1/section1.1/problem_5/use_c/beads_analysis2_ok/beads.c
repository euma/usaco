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
  int i;
  FILE *in,*out;
  in = fopen("beads.in", "r");
  out = fopen ("beads.out", "w");

  int n;
  char tmp[400], s[800];
  fscanf(in, "%d %s", &n, tmp);

  strcpy(s, tmp);
  strcat(s, tmp);

  int left[800][2], right[800][2];
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

  int m = 0;
  for (i=0; i<2 * n; i++)
    m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
  m = min(m, n);
  fprintf(out, "%d\n", m);
  fclose(in);
  fclose(out);
  exit(0);
  return 0;
}
