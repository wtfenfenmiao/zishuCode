#include<stdio.h>
int main()
{
    //��򵥵ģ������������(ʮ���Ϳ�ʼ�����)��Ҳ�����ٶ���������
    /*
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            int temp=1;
            for(int j=1;j<=i;++j)
            {
                temp*=j;
            }
            sum+=temp;
        }
        printf("%d\n",sum%1000000);
    }
    */
    //���û����������ˣ�����Ч�ʵ�(������1000000��ʱ��ʱ)������һ����ѧ֪ʶ���Ӽ��˳����������㣬������ȡ�����ȡ��������һ��
    /*
    int n;
    const int MOD=1000000;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            int temp=1;
            for(int j=1;j<=i;++j)
            {
                temp=(temp*j)%MOD;
            }
            sum=(sum+temp)%MOD;
        }
        printf("%d\n",sum);
    }
    */

    //����Ĳ�����25������λ����0�ˣ����Ա�25��Ľ׳˺���λ����0.����ûӰ�죬����n>25��ʱ������𰸾��Ƕ�ֵ��
    int n;
    const int MOD=1000000;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>25)
            n=25;
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            int temp=1;
            for(int j=1;j<=i;++j)
            {
                temp=(temp*j)%MOD;
            }
            sum=(sum+temp)%MOD;
        }
        printf("%d\n",sum);
    }


    return 0;

}
