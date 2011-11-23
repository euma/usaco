#include <stdio.h>
#include <string.h>

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n,max;
    int toLeft[1000][2];
    int toRight[1000][2];
    char str[500];
    char tmp[1000];
    scanf("%d%*c",&n);
    gets(str);
    strcpy(tmp,str);
    strcat(tmp,str);
    int i;
    toRight[2*n][0] = 0;   //toRight[i]表示从i...n
    toRight[2*n][1] = 0;
    toLeft[0][0] = 0;   //toLeft[i]的统计值并不包括其本身,是指在i之前所收集的元素,即toLeft[i]表示的是从0...i-1
    toLeft[0][1] = 0;
    for(i = 1; i < 2*n; ++i)
    {
        if(tmp[i-1] == 'b')
        {
            toLeft[i][0] = toLeft[i-1][0] + 1;
            toLeft[i][1] = 0;
        }
        else if(tmp[i-1] == 'r')
        {
            toLeft[i][0] = 0;
            toLeft[i][1] = toLeft[i-1][1] + 1;    
        }
        else if(tmp[i-1] == 'w')
        {
            toLeft[i][1] = toLeft[i-1][1] + 1;
            toLeft[i][0] = toLeft[i-1][0] + 1;
        }
    }
    
    
    for(i = n*2 - 1; i >= 0; --i)
    {
        if(tmp[i] == 'b')
        {
            toRight[i][0] = toRight[i+1][0] + 1;
            toRight[i][1] = 0;
        }
        else if(tmp[i] == 'r')
        {
            toRight[i][0] = 0;
            toRight[i][1] = toRight[i+1][1] + 1;    
        }
        else if(tmp[i] == 'w')
        {
            toRight[i][1] = toRight[i+1][1] + 1;
            toRight[i][0] = toRight[i+1][0] + 1;
        }
    }
    max = 0;
    int l,r;
    for(i = 0; i < n*2; ++i)
    {
        l = getMax(toLeft[i][0],toLeft[i][1]);
        r = getMax(toRight[i][0],toRight[i][1]);
        max = getMax(max, l+r);
    }
    if(max > n) max = n;
    printf("%d ",max);
    return 0;
}
