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
