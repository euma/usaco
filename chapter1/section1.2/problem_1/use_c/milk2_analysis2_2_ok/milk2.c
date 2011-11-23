/*
ID: wernheo1
LANG: C
TASK: milk2
*/

/* sort the starting and ending times, then go through them from
 *  start to finish, keeping track of how many farmers are milking
 *   between each "event" (a single farmer starting and stopping). */

#include <stdlib.h>
#include <stdio.h>

typedef struct event event;
struct event
{
 long seconds;   /* seconds since 5 am */
 signed char ss; /* start = 1, stop = -1 (delta number of farmers milking)
*/
};

/*when return is negative then a.seconds=300 b.seconds=500 or a.seconds=300 a.ss=1 b.seconds=300 b.ss=-1*/
/*when return is positive then a.seconds=500 b.seconds=300 or a.seconds=300 a.ss=-1 b.seconds=300 b.ss=1*/
/*when return is zero then a.seconds=300 a.ss=-1 b.seconds=300 b.ss=-1 or a.seconds=300 a.ss=-1 b.seconds=300 b.ss=-1*/
int eventcmp (const event *a, const event *b)
{
 if (a->seconds != b->seconds)
  return (a->seconds - b->seconds); /* 300 before 500 */

 return (b->ss - a->ss); /* 1 (start) before -1 (stop) */
}

int main ()
{
 FILE *in;
 FILE *out;

 in=fopen("milk2.in","r");
 out=fopen("milk2.out","w");

 int num_intervals, num_events, i;
 event events[5000 * 2];

 fscanf(in,"%d",&num_intervals);
 num_events = num_intervals * 2;
 for (i = 0; i < num_intervals; ++i)
 {
  fscanf(in,"%ld",&events[2*i  ].seconds); events[2*i  ].ss = 1;
  fscanf(in,"%ld",&events[2*i+1].seconds); events[2*i+1].ss = -1;
 }

 //for (i = 0; i < num_events; ++i) {
  //out << events[i].seconds << (events[i].ss == 1 ? " start" : " stop") << endl;
  //printf("%d: %ld %d\n",i, events[i].seconds, events[i].ss);
 //}
 //printf("\n----------------------------\n");

 qsort(events, num_events, sizeof(event),
  (int(*)(const void*, const void*)) eventcmp);

 //for (i = 0; i < num_events; ++i) {
  //out << events[i].seconds << (events[i].ss == 1 ? " start" : " stop") << endl;
  //printf("%d: %ld %d\n",i, events[i].seconds, events[i].ss);
 //}

 int num_milkers = 0, was_none = 1;
 int longest_nomilk = 0, longest_milk = 0;
 int istart, ilength;

 for (i = 0; i < num_events; ++i)
 {
  num_milkers += events[i].ss;

  /* num_milkers==0 and was_none==0*/
  if (!num_milkers && !was_none)
  {
   /* there are suddenly no milkers. */
   ilength = (events[i].seconds - istart);
   if (ilength > longest_milk)
    longest_milk = ilength;
   istart = events[i].seconds;
  }
  /* num_milkers!=0 and was_none!=0*/
  else if (num_milkers && was_none)
  {
   /* there are suddenly milkers. */
   /* when i==0 num_milkers==1 and was_none==1*/
   if (i != 0)
   {
    ilength = (events[i].seconds - istart);
    if (ilength > longest_nomilk)
     longest_nomilk = ilength;
   }
   istart = events[i].seconds;
  }

  was_none = (num_milkers == 0);
 }

 fprintf(out,"%d %d\n",longest_milk,longest_nomilk);

 exit(0);
 return 0;
}
