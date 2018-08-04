#include<stdio.h>
int main()
{
    freopen("example_3_4_in.txt","r",stdin);
    freopen("example_3_4_out.txt","w",stdout);
    char c;
    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";   //定义常量数组无需指明大小，编译器会计算
    while((c=getchar())!=EOF)
    {
        int i;
        for(i=1;s[i]&&s[i]!=c;++i);
        if(s[i])
            putchar(s[i-1]);
        else
            putchar(c);
    }
    return 0;
}


//可以提交的
#include<stdio.h>

int main()
{
    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";   //这道题的亮点是常量数组。最后一个是\0可以用来判断
    char c;
    while((c=getchar())!=EOF)
    {
        int i;
        for(i=0;s[i]&&s[i]!=c;++i);
        if(s[i]) printf("%c",s[i-1]);     //print(s[i-1])不行
        else printf("%c",c);
    }
    return 0;
}

