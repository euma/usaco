/*
ID: wernheo1
LANG: C
TASK: milk
*/

#include<stdio.h>

#define MAXPRICE 1001
/* there we know the max price is 1000 */

int amount_for_price[MAXPRICE]={0};
int N, M;

int Cal(void);
int Read(void);

int main(void) {
    Read();
    Cal();
    return 0;
}

int Cal(void) {
    int i;
    int price_total=0;
    int milk_total=0;
    for(i=0;i<MAXPRICE;i++) {
	if(amount_for_price[i]) {
	    if(milk_total+amount_for_price[i]<N) {
		price_total+=(i*amount_for_price[i]);
		milk_total+=amount_for_price[i];
	    }
	    else {
		int amount_needed = N-milk_total;
		price_total+=(i*amount_needed);
		break;
	    }
	}
    }
    {
	FILE* out=fopen("milk.out","w");
	fprintf(out,"%d\n",price_total);
	fclose(out);
    }
    return 0;
}

int Read(void) {
    FILE* in = fopen("milk.in","r");
    int i, price, amount;
    /* total milk amount = N, number of farmers is M. */
    fscanf(in,"%d %d",&N,&M);
    for(i=0;i<M;i++) {
	fscanf(in, "%d %d", &(price), &(amount));
	amount_for_price[price]+=amount;/* for same price there will add amount together. Here storing all the data into a array! There array automate sort data, because array's index is from small to big arrangement. The price is index so sort is complete when we store the data! */
	//there we don't care at the same price how have how many amount of milk.
    }
    fclose(in);
    return 0;
}
