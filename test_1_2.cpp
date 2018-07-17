#include<stdio.h>
int main()
{
    float f;
    while(scanf("%f",&f)!=EOF)
    {
        printf("%.3f\n",5.0*(f-32.0)/9.0);
    }
    return 0;
}
