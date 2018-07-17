#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%400==0||(n%100!=0&&n%4==0))   //闰年，能被4整除但是不能被100整除的。能被400整除的叫世纪闰年。
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
