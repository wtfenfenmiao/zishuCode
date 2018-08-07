#include<stdio.h>
#define maxn 8
char code[maxn][1<<maxn-1];   //<<de优先级低，这里是1<<7，够用了


char readchar()
{
    char ch;
    while(1)
    {
        ch=getchar();
        if(ch!='\n'&&ch!='\r')
            return ch;
    }
}


int readcodes()
{
    code[1][0]=readchar();
    for(int len=2;len<maxn;++len)
    {
        for(int num=0;num<(1<<len)-1;++num)
        {
            char ch=getchar();
            if(ch==EOF) return 0;
            if(ch=='\n'||ch=='\r') return 1;
            code[len][num]=ch;
        }
    }
    return 1;
}



int readint(int len)
{
    int re=0;
    while(len--)
    {
        re=re*2+readchar()-'0';
    }
    return re;
}


int main()
{
    //freopen("example_4_4_in.txt","r",stdin);
    //freopen("example_4_4_out.txt","w",stdout);
    while(readcodes())
    {
        while(1)
        {
            int len=readint(3);
            if(len==0)
                break;
            int deco=0;
            while((deco=readint(len))!=(1<<len)-1)
            {
                printf("%c",code[len][deco]);
            }
        }
        printf("\n");
    }
}
