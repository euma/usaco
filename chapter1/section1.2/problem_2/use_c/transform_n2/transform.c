#include<stdio.h>
int rotation90_same (char *before, char *after, int size);

int main() {
  int size=2;
  char before[2][2]={{'@','-'}, {'-','-'}};
  char after[2][2]={{'-','@'},{'-','-'}};
  if (rotation90_same(&before[0][0], &after[0][0], size)) {
    printf("#1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.\n");
  }
  else {
    printf("not: #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.\n");
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
