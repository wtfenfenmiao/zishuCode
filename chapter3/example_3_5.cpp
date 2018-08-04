#include<stdio.h>
#include<string.h>
#define maxn 100100
int re[maxn];

int main()
{
    memset(re,0,sizeof(re));
    for(int i=1;i<=100000;++i)
    {
        int x=i;
        int y=i;
        while(y!=0)
        {
            x+=y%10;
            y/=10;
        }
        if(re[x]==0)
            re[x]=i;
    }
    int n;
    int kase;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&kase);
        printf("%d\n",re[kase]);
    }

    return 0;
}
