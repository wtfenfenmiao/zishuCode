#include<stdio.h>
int main()
{

    int n;
    int num;
    scanf("%d",&n);
    while(n--)
    {
        int re[10]={0};
        scanf("%d",&num);
        for(int nu=1;nu<=num;++nu)
        {
            int temp=nu;
            while(temp)
            {
                ++re[temp%10];
                temp/=10;
            }

        }
        printf("%d",re[0]);
        for(int i=1;i<10;++i)
        {
            printf(" %d",re[i]);
        }
        printf("\n");
    }
    return 0;
}
