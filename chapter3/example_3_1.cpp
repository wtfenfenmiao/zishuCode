#include<stdio.h>
int main()
{
    freopen("example_3_1_in.txt","r",stdin);
    freopen("example_3_1_out.txt","w",stdout);
    char c;
    bool flag=true;
    //这个while里的赋值可以学习一下
    while((c=getchar())!=EOF)     //不能用scanf了，scanf遇到空格和回车会停下。还可以用fgetc(fin)
    {
        if(c=='"')
        {
          c=flag?'@':'$';
          flag=!flag;
        }
        printf("%c",c);
    }
    printf("\n");
    return 0;
}
