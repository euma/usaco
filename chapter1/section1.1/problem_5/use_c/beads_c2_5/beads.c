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
  int max_head=0;
  int bead_number=0;
  int max_bead=0;
  //char beads[]="wwwbbwrrwww";//12 ok!
  //char beads[]="wwwwwww";//14 ok!
  //char beads[]="wwwwwwwb";//16 ok!
  //char beads[]="rwwwwwww";//16 ok!
  char *beads[4];
  beads[0]="wwwbbwrrwww";
  beads[1]="wwwwwww";
  beads[2]="wwwwwwwb";
  beads[3]="rwwwwwww";
  for (i=0;i<4;i++) {
    len=strlen(beads[i]);
    bead_number=count_beads(beads[i],len);
    printf("%s %d\n",beads[i],bead_number);
  }
//  if (bead_number > max_bead) {
//    max_head=head;
//    max_bead=bead_number;
//  }
//  printf("\n------------%d------%d-------\n",head,bead_number);
//  for (i=0;i<len;i++) {
//    printf("%c",beads[i]);
//  }
//  for (head=2;head<=len;head++) {
//    next_break(beads,len);
//    bead_number=count_beads(beads,len);
//    if (bead_number > max_bead) {
//      max_head=head;
//      max_bead=bead_number;
//    }
//    printf("\n------------%d-----%d--------\n",head,bead_number);
//    for (i=0;i<len;i++) {
//      printf("%c",beads[i]);
//    }
//  }
//  printf("\n");
//  printf("%d %d\n",max_head,max_bead);
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
  int count=0;
  i=0;
  while(i<len-1 && s[i]=='w') {
    start=s[i+1];
    //printf("start = (%c,%d)\n",start,i+1);
    count++;
    i++;
  }
  //printf("i = %d\n",i);
  while (i<len) {
    if (s[i]==start) { count++; }
    else if (s[i]=='w') { count++; }
    else { break; }
    i++;
  }
  char end=s[len-1];
  i=len-1;
  //printf("i = %d\n",i);
  while(i>0 && s[i]=='w') {
    end=s[i-1];
    //printf("end = (%c,%d)\n",end,i-1);
    count++;
    i--;
  }
  //printf("count = %d\n",count);
  //printf("i = %d\n",i);
  while (i>=0) {
    if (s[i]==end) { count++; }
    else if (s[i]=='w') { count++; }
    else { break; }
    i--;
  }
  return count;
}
