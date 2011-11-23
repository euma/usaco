    int find=0;
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
	  if (search_name(name2)>=0) {
	    find++;
	    fprintf(out,"%s\n",name2);
	  }
	}
      }
    }
    if (find == 0) {
      fprintf(out,"NONE\n");
    }
