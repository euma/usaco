#include<stdio.h>
#include<string.h>
/*first deal with rb*/
/*second deal with rbw*/

void next_break(char *s,int len);
int count_beads(char *s,int len);

int main() {
  //char beads[]="wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
  int i,len;
  int head=1;
  char beads[]="brbrrrbbbrrrrrbrrbbrbbbbrrrrb";
  //printf("%d\n",strlen(beads));
  len=strlen(beads);

  printf("\n------------%d------%d-------\n",head,count_beads(beads,len));
  for (i=0;i<len;i++) {
    printf("%c",beads[i]);
  }
  for (head=2;head<=len;head++) {
    next_break(beads,len);
    printf("\n------------%d-----%d--------\n",head,count_beads(beads,len));
    for (i=0;i<len;i++) {
      printf("%c",beads[i]);
    }
  }
  printf("\n");
  return 0;
}
void next_break(char *s,int len) {
  int i;
  char tmp_chars[len+1];
  for (i=0;i<len;i++) {
    tmp_chars[i]=s[i];
  }
  for (i=0;i<len-1;i++) {
    s[i]=tmp_chars[i+1];
  }
  s[len-1]=tmp_chars[0];
}
int count_beads(char *s,int len) {
  int i;
  char start=s[0];
  int count=1;
  for (i=1;i<len;i++) {
    if (s[i]==start) { count++; }
    else { break; }
  }
  char end=s[len-1];
  printf("(%c %c)",start,end);
  count++;
  for (i=len-2;i>=0;i--) {
    if (s[i]==end) { count++; }
    else { break; }
  }
  return count;
}
