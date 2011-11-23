/*
ID: wernheo1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int
hash(char *s)
{
	int i, h;

	h = 1;
	for(i=0; s[i] && isalpha(s[i]); i++)
		h = ((s[i]-'A'+1)*h) % 47;
	return h;
}

int
main(void)
{
	FILE *in, *out;
	char comet[100], group[100];  /* bigger than necessary, room for newline */

	//in = fopen("input.txt", "r");
	//in = fopen("ride.in", "r");
	in = fopen("ride.in.2", "r");
	//out = fopen("output.txt", "w");
	out = fopen("ride.out", "w");

	fgets(comet, sizeof comet, in);
	fgets(group, sizeof group, in);

	if(hash(comet) == hash(group))
		fprintf(out, "GO\n");
	else
		fprintf(out, "STAY\n");
	exit (0);
	return 0;
}
