#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%400==0||(n%100!=0&&n%4==0))   //���꣬�ܱ�4�������ǲ��ܱ�100�����ġ��ܱ�400�����Ľ��������ꡣ
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
