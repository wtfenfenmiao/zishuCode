#include<stdio.h>
int main()
{
    //最简单的，会有溢出问题(十几就开始溢出了)，也会有速度慢的问题
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
    //这个没有溢出问题了，但是效率低(很慢，1000000的时候超时)。用了一个数学知识，加减乘除这样的运算，先算再取余和先取余再算结果一样
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

    //神奇的操作，25！后六位就是0了，所以比25大的阶乘后六位都是0.加上没影响，所以n>25的时候这个答案就是定值了
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
