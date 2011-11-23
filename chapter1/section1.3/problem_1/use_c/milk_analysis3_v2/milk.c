#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct List List;
typedef List *pList;
typedef struct HeadList HeadList;
struct List {
    int farmer;
    struct List * next;
};
struct HeadList {
    pList head;
    pList tail;
};

int main() {

    int cost[5011]={0};
    int amount[5011]={0};
    int sorted[5011]={0};
    int sofar,i,x,want,cnt;
    HeadList csort[1011];
    pList t;

    FILE *fin, *fout;
    fin=fopen("milk.in","r");
    fout=fopen("milk.out","w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &want, &cnt);
    for (i=1;i<=cnt;i++) {
	fscanf(fin, "%d %d", &cost[i],&amount[i]);
    }
    fclose(fin);

    for (i=0;i<=1000;i++) {
	//new(csort[i].head);
	csort[i].head=(pList)malloc(sizeof (List));
	csort[i].tail=csort[i].head;
	csort[i].head->farmer=-1;
    }
    for (i=1;i<=cnt;i++) {
	t=csort[cost[i]].tail;
	if (t->farmer == -1) { t->farmer=i; }
	//new(t^.next);
	List temp;
	temp.farmer=0;
	temp.next=NULL;
	t->next=(pList)malloc(sizeof (List));

	t->next->farmer=-1;
	csort[cost[i]].tail=t->next;
    }
    x=1;
    for (i=0;i<=1000;i++) {
	t=csort[i].head;
	while (t->farmer > 0) {
	    sorted[x]=t->farmer;
	    //inc(x);
	    x++;
	    t=t->next;
	}
    }
    sofar=0;
    for (i=1;i<=cnt;i++) {
	if (want < amount[sorted[i]]) {
	    //inc(sofar,want*cost[sorted[i]]);
	    sofar += want*cost[sorted[i]];
	    want=0;
	    break;
	} else {
	    //inc(sofar,amount[sorted[i]]*cost[sorted[i]]);
	    sofar += amount[sorted[i]]*cost[sorted[i]];
	    //dec(want,amount[sorted[i]]);
	    want -= amount[sorted[i]];
	}
    }
    fprintf(fout,"%d\n",sofar);
    fclose(fout);

    return 0;

}
