#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)   //δ�������뷶Χ������
    {
        printf("%.3f\n",(a+b+c)/3.0);
    }
    return 0;
}
