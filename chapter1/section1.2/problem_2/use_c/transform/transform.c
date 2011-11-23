#include<stdio.h>
int rotation90_same (char **before, char **after);
int rotation180_same (char **before, char **after);
int rotation270_same (char **before, char **after);
int reflection_same (char **before, char **after);
int combination_same (char **before, char **after);
int no_change_same (char **before, char **after);
int invalid_transformation (char **before, char **after);

int main() {

  int size=3;
  char before[size][size]={{'@','-','@'},{'-','-','-'},{'@','@','-'}};
  char after[size][size]={{'@','-','@'},{'@','-','-'},{'-','-','@'}};
  int i,j;
  if (rotation90_same(before,after))
  { printf("1"); }
  else if (rotation180_same(before,after))
  { printf("2"); }
  else if (rotation270_same(before,after))
  { printf("3"); }
  else if (reflection_same(before,after))
  { printf("4"); }
  else if (combination_same(before,after))
  { printf("5"); }
  else if (no_change_same(before,after))
  { printf("6"); }
  else if (invalid_transformation(char **before, char **after))
  { printf("7"); }
  else { printf("0"); }

  return 0;
}
int rotation90_same (char **before, char **after, int size) {
  char tmp_before[size][size];
  int i,j;
  for (i=0;i<size;i++) {
    for (j=0;j<size;j++) {
      tmp_before[i][j]=before[i][j];
    }
  }
  if (size % 2 == 0) {}
  else {}
}
int rotation180_same (char **before, char **after) {
}
int rotation270_same (char **before, char **after) {
}
int reflection_same (char **before, char **after) {
}
int combination_same (char **before, char **after) {
}
int no_change_same (char **before, char **after) {
}
int invalid_transformation (char **before, char **after) {
}
