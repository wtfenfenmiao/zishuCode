#include<stdio.h>
#define maxn 105
int a[maxn];  //����÷ŵ����涨�壬����ŵ�main���棬���ܶ����̫�󣬳�������ֻ�ж�����������ܶ���ĺܴ󡣷���������1000000�ͱ���
int main()
{

    int num;
    int n=0;
    while(scanf("%d",&num)!=EOF)
        a[n++]=num;
    for(int i=n-1;i>0;--i)
        printf("%d ",a[i]);
    printf("%d\n",a[0]);         //�����Ƿ�ֹ�������ո��
    return 0;
}
