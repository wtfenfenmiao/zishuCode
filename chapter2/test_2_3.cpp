#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {

        for(int i=0;i<n;++i)
        {
            int sum=2*(n-i)-1;
            for(int j=0;j<i;++j)
                printf(" ");
            for(int j=0;j<sum;++j)
                printf("#");
            for(int j=0;j<i;++j)
                printf(" ");
            printf("\n");
        }
    }
    return 0;
}
