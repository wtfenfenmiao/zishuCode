#include<stdio.h>
int main()
{
    int n,m;
    int Kase=0;
    while(scanf("%d%d",&n,&m)!=EOF&&(n!=0&&m!=0))
    {
        double sum=0.0;
        for(int i=n;i<=m;++i)
            sum+=1.0/i/i;         //���������1.0/(i*i),���i*i����������Ǹ�����
        printf("Case %d: %.5lf\n",++Kase,sum);
    }
    return 0;
}
