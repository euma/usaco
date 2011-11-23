/*
ID: wernheo1
LANG: C
TASK: dualpal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

/* is string s a palindrome? */
int ispal(char *s) {
    char *t; 
    for(t=s+strlen(s)-1; s<t; s++, t--)
	if(*s != *t)
	    return 0;
    return 1;
}

/* put the base b representation of n into s: 0 is represented by "" */

void numbconv(char *s, int n, int b) {
    int len;
    if(n == 0) {
	strcpy(s, "");
	return;
    }

    /* figure out first n-1 digits */
    /*there use recursive function*/
    numbconv(s, n/b, b);

    /* add last digit */
    /* compute how many current digit*/
    len = strlen(s);
    /*add next digit*/
    s[len] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % b];
    s[len+1] = '\0';
}

int main(void) {
    char t[20];
    int i, base;
    int n,s;
    FILE *fin, *fout;

    fin = fopen("dualpal.in", "r");
    fout = fopen("dualpal.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &n, &s);
    int get=0;
    for(i=s+1;i < pow(2,32) && get<n; i++) {
	printf("%d: ",i);
	int find=0;
	for (base=2;base<=10;base++) {
	    numbconv(t, i, base);
	    if(ispal(t)) {
		printf("%s<%d> ", t, base);
		find++;
	    }
	    if (find > 1) { printf("(%d)\n",i); get++; break; }
	}
	printf("\n");
    }
    exit(0);
    return 0;
}
