#include<stdio.h>
int main()
{
    int n,m;
    int Kase=0;
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0&&m!=0))
    {
        double sum=0.0;
        for(int i=n;i<=m;++i)
            sum+=1.0/i/i;         //这个不能用1.0/(i*i),这个i*i会溢出。这是个陷阱
        printf("Case %d: %.5lf\n",++Kase,sum);
    }
    return 0;
}
