/*
	ID:stackex1
	LANG:C
	PROG:beads
*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

char str[MAX_LEN], tmp[MAX_LEN];

int work()
{
	int i, j, l, bl, rl, res;
	int bidx, ridx, widx;
	l = strlen(str);
	/*字符串中没有b*/
	i = 0;
	while(i < l && str[i] != 'b') ++i;
	if(i == l) return (l >> 1);
	/*字符串中没有r*/
	i = 0;
	while(i < l && str[i] != 'r') ++i;
	if(i == l) return (l >> 1);
	/*去除前导的字符w*/
	i = 0;
	while(str[i] == 'w') ++i;
	/*开始计算长度*/
	bl = rl = res = j = 0;
	bidx = ridx = widx = 0;
	while(i < l)
	{
		switch(str[i])
		{
		case 'r':
			while(i < l && (str[i] == 'r' || str[i] == 'w'))
			{
				if(str[i] == 'r') ridx = i;
				++i;
				++rl;
			}
			rl += j;
			break;
		case 'b':
			while(i < l && (str[i] == 'b' || str[i] == 'w'))
			{
				if(str[i] == 'b') bidx = i;
				++i;
				++bl;
			}
			bl += j;
			break;
		default:
			break;
		}
		if((widx - ridx)*(widx - bidx) < 0)
		{
			if(res < bl + rl - j) res = bl + rl - j;
		}
		else
		{
			if(res < bl + rl) res = bl + rl;
		}
		j = 0;
		/*如果当前字符是b*/
		if(str[i] == 'b') bl = 0;
		/*如果当前字符是r*/
		else if(str[i] == 'r') rl = 0;
		/*如果前一个是w则回溯*/
		if(str[i - 1] == 'w')
		{
			j = i;
			--i;
			while(str[i] == 'w') --i;
			++i;
			widx = i;
			j -= i;
			i += j;
		}
	}
	return res > l/2 ? l/2 : res;
}

int main(int argc, char **argv)
{
	int n, i;

	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");

	fscanf(fin, "%d%*c", &n);
	fscanf(fin, "%s", tmp);

	memset(str, 0, sizeof(str));
	strcat(str, tmp);
	strcat(str, tmp);

	fprintf(fout, "%d\n", work());

	fclose(fin);
	fclose(fout);

	return 0;
}
