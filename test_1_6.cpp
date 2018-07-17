#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a<=0||b<=0||c<=0)
        {
            printf("not a triangle\n");
            continue;
        }
        if(a+b<=c||abs(a-b)>=c)
        {
            printf("not a triangle\n");
            continue;
        }
        if((a*a+b*b==c*c)||(a*a+c*c==b*b)||(b*b+c*c==a*a))
        {
            printf("yes\n");
        }
        else
            printf("no\n");
    }
    return 0;
}
