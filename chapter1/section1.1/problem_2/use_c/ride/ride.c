/*
ID: wernheo1
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
int main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char a[7];
    char b[7];
    fscanf (fin, "%s\n%s", a, b);
    printf("%s\n",a);
    printf("%s\n",b);
    fprintf (fout, "%s\n", "GO");
    fclose(fin);
    fclose(fout);
    exit (0);
    return 0;
}
