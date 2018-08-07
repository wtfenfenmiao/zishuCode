#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 8
char code[maxn][1<<maxn-1];

void printcode()
{
    for(int i=1;i<maxn;++i)
    {
        for(int j=0;j<(1<<i)-1;++j)
        {
            if(code[i][j]==0)
                return;
            printf("%c",code[i][j]);
        }
        printf("\n");
    }
}

char readchar()
{
    char c;
    while(1)
    {
        c=getchar();
        if(c!='\n'&&c!='\r')
            return c;
    }

}

int readcodes()
{
    //printf("therereadcodes!\n");
    memset(code,0,sizeof(code));
    code[1][0]=readchar();
    //printf("code[%d][%d]:%c\n",1,0,code[1][0]);
    for(int i=2;i<maxn;++i)
    {
        for(int j=0;j<(1<<i)-1;++j)
        {
            char ch=getchar();
            if(ch==EOF)
            {
                //printf("rco1\n");
                return 0;
            }

            if(ch=='\n'||ch=='\r')
            {
                //printf("rco2\n");
                return 1;
            }
            //printf("rco3\n");
            code[i][j]=ch;
            //printf("code[%d][%d]:%c\n",i,j,code[i][j]);
        }
    }
    return 1;
}


int readint(int len)
{
    int re=0;
    for(int i=0;i<len;++i)
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
        //printcode();
        while(1)
        {
            int len=readint(3);
            //printf("len:%d\n",len);
            int deco=0;
            if(len==0)
            {
                //printf("there\n");
                break;
            }

            while((deco=readint(len))!=(1<<len)-1)
            {
                //printf("deco:%d\n",deco);
                printf("%c",code[len][deco]);
            }
        }
        printf("\n");

    }
    return 0;
}



