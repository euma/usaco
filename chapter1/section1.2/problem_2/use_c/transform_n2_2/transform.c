#include<stdio.h>
int rotation90_same (char *before, char *after, int size);
int rotation180_same (char *before, char *after, int size);

int main() {
  /* test for rotation 90 
 * int size=2;
  char before[2][2]={{'@','-'}, {'-','-'}};
  char after[2][2]={{'-','@'},{'-','-'}};
  if (rotation90_same(&before[0][0], &after[0][0], size)) {
    printf("#1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.\n");
  }
  else {
    printf("not: #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.\n");
  }
  */
  /* test for rotation 180 */
  int size=2;
  char before[2][2]={{'@','-'}, {'-','-'}};
  char after[2][2]={{'-','-'},{'-','@'}};
  if (rotation180_same(&before[0][0], &after[0][0], size)) {
    printf("#2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.\n");
  }
  else {
    printf("not: #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.\n");
  }

  return 0;
}
int rotation90_same (char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[size-j-1][i]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[(size-j-1)*size+i];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}
int rotation180_same (char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[size-i-1][size-j-1]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[(size-i-1)*size+(size-j-1)];
      printf("after(%d,%d) -> before(%d,%d)\n", i, j, size-i-1, size-j-1);
      printf("after(%c) -> before(%c)\n",after_char, before_char);
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}
