/*
ID: wernheo1
LANG: C
TASK: milk
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAXP 1000

int main() {

    FILE *fin,*fout;
    fin = fopen("milk.in", "r");
    fout = fopen("milk.out", "w");
    assert(fin != NULL && fout != NULL);

    int i, N, M;
    int P[MAXP+1];

    fscanf(fin, "%d %d", &N, &M);
    //M stands for number of farmers
    //N stands for amount of milk needed to collect!
    //P[price]=amount
    for (i = 0; i <= MAXP; i++)
	P[i]=0;
    for (i = 0; i < M; i++) {
	int price, amt;
	fscanf(fin, "%d %d", &price, &amt);

	/* we can add amounts that cost the same price
	   since x gallons costing c cents and y gallons costing c cents
	   is the same as x+y gallons costing c cents
	   */
	P[price] += amt;
    }
    fclose(fin);

    // greedy choice: take as much of the item that
    // has the least price per gallon
    int res = 0;
    int p;
    for (p = 0; p<=MAXP && N>0; p++) {
	if (P[p]>0) {
	    res+=p*(N<P[p]?N:P[p]);
	    N-=P[p];
	}
    }
    fprintf(fout,"%d\n",res);
    fclose(fout);

    return 0;
}
