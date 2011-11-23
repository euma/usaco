#include<stdio.h>
#include<string.h>
/*first deal with rb*/
/*second deal with rbw*/

void next_break(char *s,int *n,int len);

int main() {
  //char beads[]="wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
  int i,j,len;
  char beads[]="brbrrrbbbrrrrrbrrbbrbbbbrrrrb";
  //printf("%d\n",strlen(beads));
  len=strlen(beads);

  int bead_numbers[len+1];
  for (i=0;i<len;i++) {
    bead_numbers[i]=i;
  }

  printf("\n------------1-------------\n");
  for (i=0;i<len;i++) {
    printf("%4c",beads[i]);
  }
  printf("\n");
  for (i=0;i<len;i++) {
    printf("(%2d)",bead_numbers[i]);
  }
  printf("\n");

  for (j=0;j<len-1;j++) {
    next_break(beads,bead_numbers,len);
    printf("\n------------%d-------------\n",j+2);
    for (i=0;i<len;i++) {
      printf("%4c",beads[i]);
    }
    printf("\n");
    for (i=0;i<len;i++) {
      printf("(%2d)",bead_numbers[i]);
    }
    printf("\n");
  }

  return 0;
}
void next_break(char *s,int *n,int len) {
  int i;
  char tmp_chars[len+1];
  char tmp_ints[len+1];
  /*this is counterclockwise rotation*/
  for (i=0;i<len;i++) {
    tmp_chars[i]=s[i];
    tmp_ints[i]=n[i];
  }
  for (i=0;i<len-1;i++) {
    s[i+1]=tmp_chars[i];
    n[i+1]=tmp_ints[i];
  }
  s[0]=tmp_chars[len-1];
  n[0]=tmp_ints[len-1];
}
