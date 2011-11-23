/*
ID: wernheo1
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_WIDTH 12
#define CHAR_SET 27

int main() {
  FILE *in = fopen ("namenum.in", "r");
  FILE *in2 = fopen ("dict.txt", "r");
  FILE *out = fopen ("namenum.out","w");
  int nsolutions = 0;
  int numlen;
  char word[NAME_WIDTH+1], num[NAME_WIDTH+1], *p, *q, map[CHAR_SET];
  map['\0']='\0'; //map[0]=0;
  map['A'-'A'+1] = map['B'-'A'+1] = map['C'-'A'+1] = '2';
  map['D'-'A'+1] = map['E'-'A'+1] = map['F'-'A'+1] = '3';
  map['G'-'A'+1] = map['H'-'A'+1] = map['I'-'A'+1] = '4';
  map['J'-'A'+1] = map['K'-'A'+1] = map['L'-'A'+1] = '5';
  map['M'-'A'+1] = map['N'-'A'+1] = map['O'-'A'+1] = '6';
  map['P'-'A'+1] = map['R'-'A'+1] = map['S'-'A'+1] = '7';
  map['T'-'A'+1] = map['U'-'A'+1] = map['V'-'A'+1] = '8';
  map['W'-'A'+1] = map['X'-'A'+1] = map['Y'-'A'+1] = '9';
  fscanf (in, "%s",num);
  numlen = strlen(num);
  while (fscanf (in2, "%s", word) != EOF) {
    /*when *p='\0' and *q='\0', *p && *q == 0*/
    for (p=word, q=num; *p && *q; p++, q++) {
      if ((int)(*p) !=0 && map[(int)(*p)-'A'+1] != *q)
	break;
      else if ((int)(*p) ==0 && 0 != *q)
	break;
    }
    if (*p == '\0' && *q == '\0') {
      fprintf (out, "%s\n", word);
      nsolutions++;
    }
  }
  if (nsolutions == 0) fprintf(out,"NONE\n");
  return 0;
}
