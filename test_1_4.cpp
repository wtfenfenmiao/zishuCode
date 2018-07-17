#include<stdio.h>
#include<math.h>

#define PI 3.14159265
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0||n>360)
        {
           printf("wrong!");
           break;
        }
        printf("%f\n",sin(n*PI/180));
        printf("%f\n",cos(n*PI/180));
    }
    return 0;
}
