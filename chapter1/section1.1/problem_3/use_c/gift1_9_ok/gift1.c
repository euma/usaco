/*
ID: wernheo1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int main(void)
{
  FILE *in, *out;
  char * return_pointer;
  char * ptr;
  int i=0;
  int j=0;
  int index=0;
  char str_buf[MAX_LEN + 1]; // One extra byte needed for the null character
  char name[10][MAX_LEN+1];
  char search_name[MAX_LEN+1]="vick";
  int money[10]={0};
  int money_self[10]={0};
  int divide;
  char *separate=" ";
  char *token;

  in = fopen("gift1.in", "r");
  if (in == NULL) { exit (1); }

  return_pointer=fgets(str_buf, sizeof str_buf, in);
  if (return_pointer == NULL) { exit (2); }
  int NP=atoi(str_buf);

  for (i=0;i<NP;i++) {
    return_pointer=fgets(str_buf, sizeof str_buf, in);
    if (return_pointer == NULL) { exit (2); }
    /*find and replace newnline to \0*/
    if( (ptr = strchr(str_buf, '\n')) != NULL)
      *ptr = '\0';
    strcpy(name[i],str_buf);
  }
  for (j=0;j<NP;j++) {
    //get search name
    return_pointer=fgets(str_buf, sizeof str_buf, in);
    if (return_pointer == NULL) { exit (2); }
    /*find and replace newnline to \0*/
    if( (ptr = strchr(str_buf, '\n')) != NULL)
      *ptr = '\0';
    strcpy(search_name,str_buf);
    /* find index of given name at name array */
    index=0;
    while(index < NP && name[index] !=NULL )
    {
      if (strcmp(name[index],search_name) == 0) { break; }
      index++;
    }
    /*get money for index people*/
    return_pointer=fgets(str_buf, sizeof str_buf, in);
    if (return_pointer == NULL) { exit (2); }
    /*find and replace newnline to \0*/
    if( (ptr = strchr(str_buf, '\n')) != NULL)
      *ptr = '\0';
    token = strtok( str_buf, " " );
    if ( token != NULL ) {
      money_self[index]=atoi(token);
      money[index]= money[index]+money_self[index];
      // Get next token: 
      token = strtok( NULL, separate );
    }
    if ( token != NULL ) {
      // While there are tokens in "string"
      divide=atoi(token);
    }
    int give_per_people=0;
    int left_for_self=0;
    if (money_self[index] == 0) {
      give_per_people=0;
      left_for_self=0;
    } else if (divide == 0) {
      give_per_people=0;
      left_for_self=money_self[index];
    } else {
      give_per_people = money_self[index] / divide;
      left_for_self = money_self[index] % divide;
    }
    int given_money=money_self[index]-left_for_self;
    money[index]= money[index]-given_money;
    i=0;
    while (i<divide) {
      return_pointer=fgets(str_buf, sizeof str_buf, in);
      if (return_pointer == NULL) {
	perror("Failed to get string in opened file \"gift1.in\"");
	exit (3);
      }
      /*find and replace newnline to \0*/
      if( (ptr = strchr(str_buf, '\n')) != NULL)
	*ptr = '\0';
      strcpy(search_name,str_buf);
      index=0;
      while(index < NP && name[index] !=NULL )
      {
	if (strcmp(name[index],search_name) == 0) { break; }
	index++;
      }
      money[index]=money[index]+give_per_people;
      i++;
    }
  }
  out = fopen("gift1.out", "w");
  for(i=0;i<NP;i++) {
    fprintf(out,"%s %d\n",name[i],money[i]-money_self[i]);
  }

  fclose(in);
  fclose(out);
  exit (0);
  return 0;
}
