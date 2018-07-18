#include<stdio.h>
int main()
{
    //1.int型整数的最小值和最大值是多少？
    int i=0;
    int Max;
    int Min;
    while(1)
    {
        if(i+1<0)
        {
            Max=i;
            Min=i+1;    //int的最大值加个1就变成最小值了
            break;
        }
        ++i;
    }
    printf("%d\n",Max);
    printf("%d\n",Min);


    //2.double型浮点数能精确到多少位小数?   0.33333333333333331000，这么看是16位
    double a=1.0;
    double b=3.0;
    printf("%.20lf\n",a/b);


    //3.double型浮点数最大正数值和最小正数值分别是多少？
    //这个函数执行到天长地久，两天了没跑完......停了
    double t=0.0000000000000001;
    for(;t>0;t+=0.0000000000000001)
    {
    }
    printf("%.100lf\n%.100lf\n%.100lf\n",t,t-0.0000000000000001,t-1);




    return 0;
}
