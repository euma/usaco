#include<stdio.h>

#define MAXPRICE 1001

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
    fscanf(in,"%d %d",&N,&M);
    for(i=0;i<M;i++) {
        fscanf(in, "%d %d", &(price), &(amount));
        amount_for_price[price]+=amount;
    }
    fclose(in);
    return 0;
}
