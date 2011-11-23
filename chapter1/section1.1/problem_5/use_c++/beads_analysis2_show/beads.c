#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

FILE *in,*out;

int main () {
  in = fopen("beads.in.2", "r");
  out = fopen ("beads.out.2", "w");

  int n;
  char tmp[400], s[800];
  fscanf(in, "%d %s", &n, tmp);
  printf("%d %s\n",n,tmp);

  strcpy(s, tmp);
  strcat(s, tmp);

  printf("%s\n",s);
  int left[800][2], right[800][2];
  left[0][0] = left[0][1] = 0;
  /*left[i][j] j stands for r or b*/

  printf("i=%d red=%d blue=%d\n",0,left[0][0],left[0][1]);
  for (int i=1; i<= 2 * n; i++){
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
    printf("i=%d red=%d blue=%d\n",i,left[i][0],left[i][1]);
  }

  printf("\n----------------------------\n");
  right[2 * n][0] = right[2 * n][1] = 0;
  printf("i=%d red=%d blue=%d\n",2*n,right[2*n][0],right[2*n][1]);
  for (int i=2 * n - 1; i >= 0; i--){
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
    printf("i=%d red=%d blue=%d\n",i,right[i][0],right[i][1]);
  }
  printf("\n----------------------------\n");

  int m = 0;
  for (int i=0; i<2 * n; i++) {
    m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
    printf("i=%d; %d = max(%d, left_max(%d, %d) + right_max(%d, %d))\n",i ,m, m, left[i][0], left[i][1], right[i][0], right[i][1]);
  }
  m = min(m, n);
  fprintf(out, "%d\n", m);
  fclose(in);
  fclose(out);
  return 0;
}
