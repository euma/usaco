#include<stdio.h>
int rotation90_same(char *before, char *after, int size);
int rotation180_same(char *before, char *after, int size);
int rotation270_same(char *before, char *after, int size);
int reflection_same(char *before, char *after, int size);

void test_rotation_90() {
  int size=4;
  char before[4][4]={{'@','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}};
  char after[4][4]={{'-','-','-','@'}, {'-','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}};
  if (rotation90_same(&before[0][0], &after[0][0], size)) {
    printf("#1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.\n");
  }
  else {
    printf("not #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.\n");
  }
}
void test_rotation_180() {
  int size=4;
  char before[4][4]={{'@','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}};
  char after[4][4]={{'-','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}, {'-','-','-','@'}};
  if (rotation180_same(&before[0][0], &after[0][0], size)) {
    printf("#2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.\n");
  }
  else {
    printf("not: #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.\n");
  }
}

void test_rotation_270() {
  int size=4;
  char before[4][4]={{'@','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}};
  char after[4][4]={{'-','-','-','-'}, {'-','-','-','-'}, {'-','-','-','-'}, {'@','-','-','-'}};
  if (rotation270_same(&before[0][0], &after[0][0], size)) {
    printf("#3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.\n");
  }
  else {
    printf("not #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.\n");
  }
}

void test_reflection() {
  int size=4;
  char before[4][4]={{'-','-','-','@'}, {'@','-','@','-'}, {'@','-','-','-'}, {'-','-','-','@'}};
  char after[4][4]={{'@','-','-','-'}, {'-','@','-','@'}, {'-','-','-','@'}, {'@','-','-','-'}};
  if (reflection_same(&before[0][0], &after[0][0], size)) {
    printf("#4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).\n");
  }
  else {
    printf("not #4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).\n");
  }
}

int main() {

  test_rotation_90();
  test_rotation_180();
  test_rotation_270();
  test_reflection();
  return 0;
}
int rotation90_same(char *before, char *after, int size) {
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
int rotation180_same(char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[size-i-1][size-j-1]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[(size-i-1)*size+(size-j-1)];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}
int rotation270_same(char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[j][size-i-1]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[j*size+(size-i-1)];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}
int reflection_same(char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[i][size-j-1]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[i*size+(size-j-1)];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}

      //if (after[i][j]!=before[size-j-1][i]) { return 0; }//90
      //if (after[i][j]!=before[size-i-1][size-j-1]) { return 0; }//180
      //if (after[i][j]!=before[j][size-i-1]) { return 0; }//270
      //if (after[i][j]!=before[i][size-j-1]) { return 0; }//feflection_horizontally
