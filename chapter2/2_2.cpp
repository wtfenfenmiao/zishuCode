#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int count=0;
        long long temp=n;     //����987654321��������Ȼ�����987654321��10^9�ڣ�����Ҫ����һ������ֹ���
        while(temp>1)
        {
            if(temp%2==1)
                temp=3*temp+1;
            else
                temp/=2;
            ++count;
            //printf("%d\n",temp);  ������
        }
        printf("%d\n",count);
    }
}
