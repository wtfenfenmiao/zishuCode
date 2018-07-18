#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int count=0;
        long long temp=n;     //输入987654321程序会崩，然而这个987654321在10^9内，所以要加这一个，防止溢出
        while(temp>1)
        {
            if(temp%2==1)
                temp=3*temp+1;
            else
                temp/=2;
            ++count;
            //printf("%d\n",temp);  调试用
        }
        printf("%d\n",count);
    }
}
