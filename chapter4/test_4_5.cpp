#include<stdio.h>
#include<string.h>
#define maxn 1005
int saveIp[maxn][4];
bool chooseCol[4];   //这一列是不是有不一样的。有就是true。


void deal(char* s,int n)   //s塞进第n行
{
    int i=0;
    int num=0;
    int col=0;
    while(s[i])
    {
        if(s[i]=='.')
        {
            saveIp[n][col++]=num;
            num=0;
        }
        else
            num=num*10+s[i]-'0';
        ++i;
    }
    saveIp[n][3]=num;

    if(n!=0)
    {
        for(int i=0;i<4;++i)
        {
            if(saveIp[n][i]!=saveIp[0][i])
                chooseCol[i]=true;
        }
    }
}

int finddiff(int col,int n)
{
    int re=1;
    for(re=1;re<=8;++re)
    {
        int temp=(1<<(8-re));
        int start=saveIp[0][col]&temp;
        for(int i=1;i<n;++i)
        {
            if(start!=(saveIp[i][col]&temp))
                return re-1;
        }
    }
    return 8;


}


void printsaveIp(int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<4;++j)
        {
            printf("%d ",saveIp[i][j]);
        }
        printf("\n");
    }
}

void printchooseCol()
{
    for(int i=0;i<4;++i)
        printf("%d ",chooseCol[i]);
    printf("\n");
}

int main()
{
    //freopen("test_4_5_in.txt","r",stdin);
    int n;
    char s[30];
    while(scanf("%d",&n)!=EOF)
    {
        //printf("n:%d\n",n);
        int minNet[4]={0};
        int mask[4]={0};
        memset(saveIp,0,sizeof(saveIp));
        memset(chooseCol,0,sizeof(chooseCol));
        for(int i=0;i<n;++i)
        {
            scanf("%s",s);
            //printf("ip:%s\n",s);
            deal(s,i);
            //printsaveIp(n);
            //printchooseCol();
        }
        int i=0;
        while(i<4&&!chooseCol[i])
        {
            minNet[i]=saveIp[0][i];
            mask[i]=255;
            //printf("minNet[%d]:%d   mask[%d]:%d\n",i,minNet[i],i,mask[i]);
            ++i;
        }
        if(i<4)
        {
            int num=finddiff(i,n);    //高num位都相同
            //printf("num:%d\n",num);
            mask[i]=255-(1<<(8-num))+1;
            minNet[i]=saveIp[0][i]&mask[i];
            //printf("minNet[%d]:%d   mask[%d]:%d\n",i,minNet[i],i,mask[i]);
            ++i;
        }
        while(i<4)
        {
            mask[i]=0;
            minNet[i]=0;
            //printf("minNet[%d]:%d   mask[%d]:%d\n",i,minNet[i],i,mask[i]);
            ++i;
        }

        for(int k=0;k<3;++k)
        {
            printf("%d.",minNet[k]);
        }
        printf("%d\n",minNet[3]);
        for(int k=0;k<3;++k)
        {
            printf("%d.",mask[k]);
        }
        printf("%d\n",mask[3]);


    }
    return 0;
}
