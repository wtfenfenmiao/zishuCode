#include<stdio.h>
#include<string.h>
#define maxn 8
char code[maxn][1<<maxn-1];

char readchar()
{
    char ch;
    while((ch=getchar())=='\n'||ch=='\r');
    return ch;
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

int readcodes()
{
    memset(code,0,sizeof(code));
    code[1][0]=readchar();
    for(int len=2;len<maxn;++len)
    {
        for(int j=0;j<(1<<len)-1;++j)
        {
            char ch=getchar();
            if(ch=='\r'||ch=='\n') return 1;
            if(ch==EOF) return 0;
            code[len][j]=ch;
        }
    }
    //return 1;
}

int main()
{
    //freopen("UVa_sub_in.txt","r",stdin);
    while(readcodes())
    {
        while(1)
        {
            int len=readint(3);
            if(len==0)
                break;
            int deco;
            while((deco=readint(len))!=(1<<len)-1)
            {
                printf("%c",code[len][deco]);
            }
        }
        printf("\n");
    }
    return 0;
}
