/*
ID: wernheo1
LANG: C
TASK: namenum
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <assert.h>

#define LIMIT 15
FILE *out;
char name[5000][LIMIT];
int names;

void search_name(char *name2);

int main() {
  int i;
  out = fopen ("namenum.out", "w");
  assert(out != NULL);
  char map[8][3]={
    {'A','B','C'}, {'D','E','F'}, {'G','H','I'}, {'J','K','L'}, {'M','N','O'}, {'P','R','S'}, {'T','U','V'}, {'W','X','Y'}
  };
  //int brand_number=0;
  long long brand_number=0;
  FILE *in;
  in = fopen("namenum.in", "r");
  assert(in != NULL);
  fscanf(in, "%lld", &brand_number);
  fclose(in);

  FILE *data;
  data=fopen("dict.txt","r");
  assert(data != NULL);
  int res=0;
  i=0;
  do {
    res=fscanf(data,"%s",name[i]);
    i++;
  }while(res != EOF);
  names=i;
  for (i=0;i<names;i++) {
    printf("%s\n",name[i]);
  }
  printf("names==%d\n",names);
  fclose(data);

  int size = (int)log10(brand_number) + 1;
  int brand_digit[size];
  i = size;
  while(i >= 0) {
    brand_digit[--i] = brand_number % 10;
    brand_number /= 10;
  }
  for (i=0;i<size;i++) {
    printf("%d\n",brand_digit[i]);
  }
  printf("size is %d\n",size);

  if (size==1) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      char name2[LIMIT];
      int k;
      for (k=0;k<size;k++) {
	name2[k]=map[brand_digit[k]-2][j[k]];
      }
      name2[k]='\0';
      if (search_name(name2)>0) {
	fprintf(out,"%s\n",name2);
      }
    }
  }
  else if (size==2) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
	char name2[LIMIT];
	int k;
	for (k=0;k<size;k++) {
	  name2[k]=map[brand_digit[k]-2][j[k]];
	}
	name2[k]='\0';
	if (search_name(name2)>0) {
	  fprintf(out,"%s\n",name2);
	}
      }
    }
  }
  else if (size==3) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
        for(j[2]=0;j[2]<3;j[2]++) {
	  char name2[LIMIT];
	  int k;
	  for (k=0;k<size;k++) {
	    name2[k]=map[brand_digit[k]-2][j[k]];
	  }
	  name2[k]='\0';
	  if (search_name(name2)>0) {
	    fprintf(out,"%s\n",name2);
	  }
	}
      }
    }
  }
  else if (size==4) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    char name2[LIMIT];
	    int k;
	    for (k=0;k<size;k++) {
	      name2[k]=map[brand_digit[k]-2][j[k]];
	    }
	    name2[k]='\0';
	    if (search_name(name2)>0) {
	      fprintf(out,"%s\n",name2);
	    }
	  }
	}
      }
    }
  }
  else if (size==5) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      char name2[LIMIT];
	      int k;
	      for (k=0;k<size;k++) {
		name2[k]=map[brand_digit[k]-2][j[k]];
	      }
	      name2[k]='\0';
	      if (search_name(name2)>0) {
		fprintf(out,"%s\n",name2);
	      }
	    }
	  }
	}
      }
    }
  }
  else if (size==6) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      for(j[5]=0;j[5]<3;j[5]++) {
		char name2[LIMIT];
		int k;
		for (k=0;k<size;k++) {
		  name2[k]=map[brand_digit[k]-2][j[k]];
		}
		name2[k]='\0';
		if (search_name(name2)>0) {
		  fprintf(out,"%s\n",name2);
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else if (size==7) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      for(j[5]=0;j[5]<3;j[5]++) {
	        for(j[6]=0;j[6]<3;j[6]++) {
		  char name2[LIMIT];
		  int k;
		  for (k=0;k<size;k++) {
		    name2[k]=map[brand_digit[k]-2][j[k]];
		  }
		  name2[k]='\0';
		  if (search_name(name2)>0) {
		    fprintf(out,"%s\n",name2);
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else if (size==8) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      for(j[5]=0;j[5]<3;j[5]++) {
	        for(j[6]=0;j[6]<3;j[6]++) {
	          for(j[7]=0;j[7]<3;j[7]++) {
		    char name2[LIMIT];
		    int k;
		    for (k=0;k<size;k++) {
		      name2[k]=map[brand_digit[k]-2][j[k]];
		    }
		    name2[k]='\0';
		    if (search_name(name2)>0) {
		      fprintf(out,"%s\n",name2);
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else if (size==9) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      for(j[5]=0;j[5]<3;j[5]++) {
	        for(j[6]=0;j[6]<3;j[6]++) {
	          for(j[7]=0;j[7]<3;j[7]++) {
	            for(j[8]=0;j[8]<3;j[8]++) {
		      char name2[LIMIT];
		      int k;
		      for (k=0;k<size;k++) {
			name2[k]=map[brand_digit[k]-2][j[k]];
		      }
		      name2[k]='\0';
                      if (search_name(name2)>0) {
			fprintf(out,"%s\n",name2);
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else if (size==10) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      for(j[5]=0;j[5]<3;j[5]++) {
	        for(j[6]=0;j[6]<3;j[6]++) {
	          for(j[7]=0;j[7]<3;j[7]++) {
	            for(j[8]=0;j[8]<3;j[8]++) {
	              for(j[9]=0;j[9]<3;j[9]++) {
			char name2[LIMIT];
			int k;
			for (k=0;k<size;k++) {
			  name2[k]=map[brand_digit[k]-2][j[k]];
			}
			name2[k]='\0';
                        if (search_name(name2)>0) {
			  fprintf(out,"%s\n",name2);
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else if (size==11) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      for(j[5]=0;j[5]<3;j[5]++) {
	        for(j[6]=0;j[6]<3;j[6]++) {
	          for(j[7]=0;j[7]<3;j[7]++) {
	            for(j[8]=0;j[8]<3;j[8]++) {
	              for(j[9]=0;j[9]<3;j[9]++) {
	                for(j[10]=0;j[10]<3;j[10]++) {
			  char name2[LIMIT];
			  int k;
			  for (k=0;k<size;k++) {
			    name2[k]=map[brand_digit[k]-2][j[k]];
			  }
			  name2[k]='\0';
                          if (search_name(name2)>0) {
			    fprintf(out,"%s\n",name2);
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else if (size==12) {
    int j[size];
    for(j[0]=0;j[0]<3;j[0]++) {
      for(j[1]=0;j[1]<3;j[1]++) {
       for(j[2]=0;j[2]<3;j[2]++) {
	  for(j[3]=0;j[3]<3;j[3]++) {
	    for(j[4]=0;j[4]<3;j[4]++) {
	      for(j[5]=0;j[5]<3;j[5]++) {
	        for(j[6]=0;j[6]<3;j[6]++) {
	          for(j[7]=0;j[7]<3;j[7]++) {
	            for(j[8]=0;j[8]<3;j[8]++) {
	              for(j[9]=0;j[9]<3;j[9]++) {
	                for(j[10]=0;j[10]<3;j[10]++) {
	                  for(j[11]=0;j[11]<3;j[11]++) {
			    char name2[LIMIT];
			    int k;
			    for (k=0;k<size;k++) {
			      name2[k]=map[brand_digit[k]-2][j[k]];
			    }
			    name2[k]='\0';
                            if (search_name(name2)>0) {
			      fprintf(out,"%s\n",name2);
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  else {
    printf("don't count it\n");
  }
  fclose(out);

  return 0;
}
int search_name(char *name2) {
  //printf("%s\n",name2);
  int lb=0;
  int ub=names-1;

  while (1) {
    int m = (lb + ub)/2;
    //if (key < a[m]) {
    if (strcmp(name2,a[m])<0) {
      ub = m - 1;
    }
    else if (strcmp(name2,a[m])>0) {
    //else if (key > a[m]) {
      lb = m + 1;
    }
    else {
      return m;
    }
    if (lb > ub) { return -1; }
  }
}
