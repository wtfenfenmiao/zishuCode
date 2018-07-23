#include<stdio.h>
//题目1
/*
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=2*n;i+=2)
    {
        printf("%d\n",i);   //上一行不动的话这一行直接i*2就行
    }
    return 0;
}
*/
//题目2,我猜的没错，这个根本停不下来，因为i就不会等于10......不等于10.0也不行。这么看for里就用整型，不要用别的......
int main()
{
    double i;
    for(i=0;i!=10;i+=0.1)
    {
        printf("%.1f\n",i);
    }
    return 0;
}
