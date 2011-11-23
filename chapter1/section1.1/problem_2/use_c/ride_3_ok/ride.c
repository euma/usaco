/*
ID: wernheo1
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char comet[7];
    char group[7];
    int i;
    int comet_number=1;
    int group_number=1;

    fscanf (fin, "%s\n%s", comet, group);
    for (i=0;i<(int)strlen(comet);i++) {
      comet_number = comet_number*(comet[i]-'A'+1);
    }
    for (i=0;i<(int)strlen(group);i++) {
      group_number = group_number*(group[i]-'A'+1);
    }
    if (group_number % 47 == comet_number % 47) {
      fprintf (fout, "%s\n", "GO");
    } else {
      fprintf (fout, "%s\n", "STAY");
    }

    fclose(fin);
    fclose(fout);
    exit (0);
    return 0;
}
