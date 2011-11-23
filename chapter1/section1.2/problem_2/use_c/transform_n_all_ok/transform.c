/*
ID: wernheo1
LANG: C
TASK: transform
*/

#include<stdio.h>
#define LIMIT 20

int rotation90_same(char *before, char *after, int size);
int rotation180_same(char *before, char *after, int size);
int rotation270_same(char *before, char *after, int size);
int reflection_same(char *before, char *after, int size);
int reflection_and_rotation90_same(char *before, char *after, int size);
int reflection_and_rotation180_same(char *before, char *after, int size);
int reflection_and_rotation270_same(char *before, char *after, int size);
int combination_same(char *before, char *after, int size);
int no_change(char *before, char *after, int size);

int main() {
  int i,j,size;
  FILE *in,*out;
  in = fopen("transform.in", "r");
  out = fopen ("transform.out", "w");
  fscanf(in, "%d", &size);

  char before[LIMIT][size];
  char str[LIMIT];
  char after[LIMIT][size];

  for (i=0;i<size;i++) {
    fscanf(in, "%s", str);
    for (j=0;j<size;j++) {
      before[i][j]=str[j];
    }
  }
  for (i=0;i<size;i++) {
    fscanf(in, "%s", str);
    for (j=0;j<size;j++) {
      after[i][j]=str[j];
    }
  }
  fclose(in);
  if (rotation90_same(&before[0][0], &after[0][0], size)) {
    fprintf(out,"1\n");
  }
  else if (rotation180_same(&before[0][0], &after[0][0], size)) {
    fprintf(out,"2\n");
  }
  else if (rotation270_same(&before[0][0], &after[0][0], size)) {
    fprintf(out,"3\n");
  }
  else if (reflection_same(&before[0][0], &after[0][0], size)) {
    fprintf(out,"4\n");
  }
  else if (combination_same(&before[0][0], &after[0][0], size)) {
    fprintf(out,"5\n");
  }
  else if (no_change(&before[0][0], &after[0][0], size)) {
    fprintf(out,"6\n");
  }
  else {
    fprintf(out,"7\n");
  }
  fclose(out);

  return 0;
}
int no_change(char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[i][j]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[i*size+j];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
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
      //printf("after(%d,%d)%c=before(%d,%d)%c\n",i,j,after_char,size-i-1,size-j-1,before_char);
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
int reflection_and_rotation90_same(char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[i][size-j-1]) { return 0; }//feflection_horizontally
      //if (after[i][j]!=before[size-j-1][i]) { return 0; }//90
      //if (after[i][j]!=before[size-j-1][size-i-1]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[(size-j-1)*size+(size-i-1)];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}
int reflection_and_rotation180_same(char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[i][size-j-1]) { return 0; }//feflection_horizontally
      //if (after[i][j]!=before[size-i-1][size-j-1]) { return 0; }//180
      //if (after[i][j]!=before[size-i-1][j]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[(size-i-1)*size+j];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}
int reflection_and_rotation270_same(char *before, char *after, int size) {
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      //if (after[i][j]!=before[i][size-j-1]) { return 0; }//feflection_horizontally
      //if (after[i][j]!=before[j][size-i-1]) { return 0; }//270
      //if (after[i][j]!=before[j][i]) { return 0; }
      char after_char=after[i*size+j];
      char before_char=before[j*size+i];
      if (after_char!=before_char) { return 0; }
    }
  }
  return 1;
}
int combination_same(char *before, char *after, int size) {
  //if (reflection_and_rotation90_same(&before[0][0], &after[0][0], size) || reflection_and_rotation180_same(&before[0][0], &after[0][0], size) || reflection_and_rotation270_same(&before[0][0], &after[0][0], size)) {
  if (reflection_and_rotation90_same(before, after, size) || reflection_and_rotation180_same(before, after, size) || reflection_and_rotation270_same(before, after, size)) {
    return 1;
  }
  else {
    return 0;
  }
}
