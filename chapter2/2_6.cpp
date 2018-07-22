#include<stdio.h>
#include<limits.h>

int main()   //这个输入输出很常规
{
    /*
    //没用文件重定向的
    int n=0;
    int x=0;
    int kase=0;
    while(scanf("%d",&n)!=EOF && n)
    {
        int sum=0;
        int Min=INT_MAX;
        int Max=INT_MIN;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&x);
            sum+=x;
            if(x<Min)
                Min=x;
            if(x>Max)
                Max=x;
        }
        if(kase)
            printf("\n");
        printf("case %d: %d %d %.3f\n",++kase,Min,Max,(double)sum/n);
    }
    */

    //用文件重定向
    int n=0;
    int x=0;
    int kase=0;
    freopen("2_6_rein.txt","r",stdin);
    freopen("2_6_reout.txt","w",stdout);
    while(scanf("%d",&n)!=EOF && n)
    {
        int sum=0;
        int Min=INT_MAX;
        int Max=INT_MIN;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&x);
            sum+=x;
            if(x<Min)
                Min=x;
            if(x>Max)
                Max=x;
        }
        if(kase)
            printf("\n");
        printf("case %d: %d %d %.3f\n",++kase,Min,Max,(double)sum/n);
    }
    return 0;
}
