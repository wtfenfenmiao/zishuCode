#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)   //未考虑输入范围的问题
    {
        printf("%.3f\n",(a+b+c)/3.0);
    }
    return 0;
}
