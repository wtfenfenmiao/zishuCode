#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 10
bool boardH[maxn][maxn];
bool boardV[maxn][maxn];


int findsquare(int x,int y,int len)   //在n*n的board中，从x，y开始边长len的正方形是否存在。存在1，不存在0。不用考虑x+len超范围，之前挡了
{
    for(int i=0;i<len;++i)
    {
        //printf("x:%d y:%d ?:%d\n",x+i,y,boardV[x+i][y]);
        //printf("x:%d y:%d ?:%d\n",x+i,y+len,boardV[x+i][y+len]);
        //printf("x:%d y:%d ?:%d\n",x,y+i,boardH[x][y+i]);
        //printf("x:%d y:%d ?:%d\n",x+len,y+i,boardH[x+len][y+i]);
        if((!boardV[x+i][y])||(!boardV[x+i][y+len])||(!boardH[x][y+i])||(!boardH[x+len][y+i]))
            return 0;
        //printf("\n");
    }
    return 1;

}

void printboard(int n)
{
    printf("H:\n");
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%d ",boardH[i][j]);
        printf("\n");
    }
        printf("V:\n");
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%d ",boardV[i][j]);
        printf("\n");
    }

}



int main()
{
    //freopen("test_4_2_in.txt","r",stdin);
    int n,num;
    int kase=0;
    int first=true;
    while(scanf("%d %d",&n,&num)!=EOF)
    {
        //printf("n:%d  num:%d\n",n,num);
        if(first)
        {
            first=false;
        }
        else
        {
            printf("\n**********************************\n\n");
        }
        printf("Problem #%d\n\n",++kase);
        bool flag=false;
        memset(boardH,0,sizeof(boardH));
        memset(boardV,0,sizeof(boardV));
        for(int i=0;i<num;++i)
        {
            getchar();
            char dir;
            int x;
            int y;
            scanf("%c %d %d",&dir,&x,&y);
            //printf("dir:%c x:%d y:%d\n",dir,x,y);
            if(dir=='H')
                boardH[x][y]=true;
            else
                boardV[y][x]=true;
        }
        //printboard(n);
        for(int len=1;len<n;++len)
        {
            int sum=0;
            for(int x=1;x<=n-len;++x)
            {
                for(int y=1;y<=n-len;++y)
                {

                    int rethis=findsquare(x,y,len);
                    //printf("findx:%d findy:%d len:%d rethis:%d\n",x,y,len,rethis);
                    sum+=rethis;
                }
            }
            if(sum!=0)
            {
                printf("%d square (s) of size %d\n",sum,len);
                flag=true;
            }
        }
        if(!flag)
            printf("No completed squares can be found.\n");

    }
}
