/*
ID: wernheo1
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXMILKING 5000

typedef struct Milk	Milk;
struct Milk {
    int price;
    int amount;
};

Milk milk[MAXMILKING];
int nmilk;

int milkcmp(const void *va, const void *vb) {
    Milk *a, *b;

    a = (Milk*)va;
    b = (Milk*)vb;

    if(a->price > b->price) {
	return 1;
    }
    else if(a->price == b->price && a->amount > b->amount) {
	return -1;
    }
    else {
	return 0;
    }
}

int main(void) {
    FILE *fin, *fout;
    int i;
    int namount;

    fin = fopen("milk.in", "r");
    fout = fopen("milk.out", "w");
    assert(fin != NULL && fout != NULL);

    /*  read input, sort */
    fscanf(fin, "%d %d", &namount, &nmilk);
    for(i=0; i<nmilk; i++)
	fscanf(fin, "%d %d", &milk[i].price, &milk[i].amount);

    qsort(milk, nmilk, sizeof(Milk), milkcmp);

    for(i=0; i<nmilk; i++) {
	printf("%d %d\n", milk[i].price, milk[i].amount);
    }
    exit(0);
    return 0;
}
