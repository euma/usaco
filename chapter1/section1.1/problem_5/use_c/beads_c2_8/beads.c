/*
ID: wernheo1
LANG: C
TASK: beads
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <assert.h>

/*first deal with rb*/
/*second deal with rbw*/

void next_break(char *s,int len);
int count_beads(char *s,int len);

int main() {
  FILE *fin, *fout;
  int len;
  int head=1;
  int max_head=0;
  int bead_number=0;
  int max_bead=0;

  fin = fopen("beads.in", "r");
  fout = fopen("beads.out", "w");
  assert(fin != NULL && fout != NULL);

  char beads[400];
  fscanf(fin, "%d %s", &len,beads);
  assert(len==strlen(beads));
  bead_number=count_beads(beads,len);
  if (bead_number > max_bead) {
    max_head=head;
    max_bead=bead_number;
  }
  for (head=2;head<=len;head++) {
    next_break(beads,len);
    bead_number=count_beads(beads,len);
    if (bead_number > max_bead) {
      max_head=head;
      max_bead=bead_number;
    }
  }
  fprintf(fout,"%d\n",max_bead);
  exit(0);
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
    count++;
    i++;
  }
  while (i<len) {
    if (s[i]==start) { count++; }
    else if (s[i]=='w') { count++; }
    else { break; }
    i++;
  }
  char end=s[len-1];
  i=len-1;
  while(i>0 && s[i]=='w') {
    end=s[i-1];
    count++;
    i--;
  }
  while (i>=0) {
    if (s[i]==end) { count++; }
    else if (s[i]=='w') { count++; }
    else { break; }
    i--;
  }
  return count;
}
