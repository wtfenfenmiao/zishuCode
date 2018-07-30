#include<stdio.h>
#define maxn 105
int a[maxn];  //这个得放到外面定义，如果放到main里面，不能定义的太大，程序会崩。只有定义在外面才能定义的很大。放里面上面1000000就崩了
int main()
{

    int num;
    int n=0;
    while(scanf("%d",&num)!=EOF)
        a[n++]=num;
    for(int i=n-1;i>0;--i)
        printf("%d ",a[i]);
    printf("%d\n",a[0]);         //这样是防止输出多余空格的
    return 0;
}
