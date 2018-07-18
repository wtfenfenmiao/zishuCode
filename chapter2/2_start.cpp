#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
