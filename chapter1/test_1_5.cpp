#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
        {
            printf("wrong!\n");
            continue;
        }
        if(n<4)
        {
            printf("%.2f\n",95.0*n);
        }
        else
        {
            printf("%.2f\n",95*n*0.85);
        }
    }
    return 0;
}
