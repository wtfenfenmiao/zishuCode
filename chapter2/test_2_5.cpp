#include<stdio.h>
int main()
{
    int a,b,c;
    int Kase=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF&&(a!=0&&b!=0&&c!=0))
    {
        printf("Case %d: %.*f\n",++Kase,c,1.0*a/b);      //printf("%.*f",n,a)��a����nλС��
    }
    return 0;
}
