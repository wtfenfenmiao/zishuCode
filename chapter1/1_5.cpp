#include<stdio.h>
int main()
{
    //first method
    /*
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a<=b&&b<=c) printf("%d %d %d\n",a,b,c);
        else if(a<=c&&c<=b) printf("%d %d %d\n",a,c,b);
        else if(b<=a&&a<=c) printf("%d %d %d\n",b,a,c);
        else if(b<=c&&c<=a) printf("%d %d %d\n",b,c,a);
        else if(c<=a&&a<=b) printf("%d %d %d\n",c,a,b);
        else printf("%d %d %d\n",c,b,a);
    }
    */

    //second method
    int a,b,c,t;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a>b) {t=a;a=b;b=t;}
        if(a>c) {t=a;a=c;c=t;}
        if(b>c) {t=b;b=c;c=t;}
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
