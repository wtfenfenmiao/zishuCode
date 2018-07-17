#include<stdio.h>
int main()
{
    printf("%%d\n");    //这样能输出%d
    int a,b;
    scanf("%d%d",&a,&b);    //同一行输入12和2，不同两行输入12和2，这两种情况花样加空格tab和空行，这些都能得到想要的输出。
    printf("%d %d\n",a,b);   //如果输入12 s，这个能输出12 8，但是下面那个停不下来，会一直输出12 8......

    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d %d\n",a,b);
    }

    return 0;
}
