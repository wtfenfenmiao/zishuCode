#include<stdio.h>
int main()
{
	int a,b,m,n;
	while(scanf("%d%d",&n,&m)!=EOF)
    {
        a=(4*n-m)/2;
        b=m/2-n;
        if(m%2==1||a<0||b<0)
            printf("%s\n","no answer");
        else
            printf("%d %d\n",a,b);
    }
	return 0;
}
