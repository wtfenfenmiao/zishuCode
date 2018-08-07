#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 30
bool flag[maxn];
int n,k,m;

int go(int start,int t,int d)
{
    while(t--)
    {
        do
        {
            start=(start-1+d+n)%n+1;
        }
        while(flag[start]);
    }
    return start;
}



int main()
{
    while(scanf("%d %d %d",&n,&k,&m)!=EOF&&n!=0)
    {
        memset(flag,0,sizeof(flag));
        int left=n;
        int p=n;
        int q=1;
        while(left)
        {
            p=go(p,k,1);
            q=go(q,m,-1);
            printf("%3d",p);
            --left;
            if(q!=p)
            {
                printf("%3d",q);
                --left;
            }
            flag[p]=flag[q]=true;
            if(left)
                printf(",");
        }
        printf("\n");
    }
    return 0;
}
