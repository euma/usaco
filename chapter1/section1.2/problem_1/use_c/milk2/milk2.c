#include<stdio.h>
int main() {
  int i, j, temp;
  int size=3;
  int start[3]={300,700,1500};
  int end[3]={1000,1200,2100};

  printf("sort before:\n");
  for (i=0;i<size;i++) {
    printf("%d %d\n",start[i],end[i]);
  }
  for (i = (size - 1); i > 0; i--) {
    for (j = 1; j <= i; j++) {
       if (start[j-1] > start[j]) {
         temp = start[j-1];
         start[j-1] = start[j];
         start[j] = temp;
         temp = end[j-1];
         end[j-1] = end[j];
         end[j] = temp;
       }
    }
  }
  printf("sort after:\n");
  for (i=0;i<size;i++) {
    printf("%d %d\n",start[i],end[i]);
  }
  return 0;
}
