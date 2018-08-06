#include<stdio.h>
#include<string.h>
#define maxn 12
int main()
{
    //freopen("test_3_6_in.txt","r",stdin);
    //freopen("test_3_6_out.txt","w",stdout);
    int row,col;
    char s[maxn][maxn];
    //int num[maxn][maxn];

    int kase=0;
    while(scanf("%d %d",&row,&col)!=EOF&&row!=0)
    {
        if(kase)
            printf("\n");
        printf("puzzle #%d:\n",++kase);
        int con=1;
        char acrossout[maxn*maxn][maxn];             //这样的数组一定要初始化memset一下，否则刚开始是随机填的，不一定输出什么玩意......
        char downout[maxn*maxn][maxn];
        for(int i=0;i<row;++i)
        {
            scanf("%s",s[i]);
        }

        for(int i=0;i<maxn*maxn;++i)
        {
            memset(acrossout[i],0,sizeof(acrossout[i]));
            memset(downout[i],0,sizeof(downout[i]));
        }
        /*
        for(int i=0;i<row;++i)
            printf("%s\n",s[i]);
        */
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                //printf("this is:%c\n",s[i][j]);
                int num=0;
                if(s[i][j]!='*'&&(i==0||j==0||(i!=0&&s[i-1][j]=='*')||(j!=0&&s[i][j-1]=='*')))
                    num=con++;
                //printf("this num:%d\n",num);
                //across
                if(num!=0&&(j==0||s[i][j-1]=='*'))
                {
                    //printf("there\n");
                    int k=j;
                    while(k<col&&s[i][k]!='*')
                    {
                        acrossout[num][k-j]=s[i][k];
                        //printf("%c",s[i][k]);
                        ++k;
                    }
                    //acrossout[num][k-j]='\0';
                    //printf("\n");

                }
                //down
                if(num!=0&&(i==0||s[i-1][j]=='*'))
                {
                    //printf("there2\n");
                    int k=i;
                    while(k<row&&s[k][j]!='*')
                    {
                        downout[num][k-i]=s[k][j];
                        //printf("%c",s[i][k]);
                        ++k;
                    }
                    //downout[num][k-j]='\0';
                     //printf("\n");

                }
            }
        }
        printf("Across\n");
        for(int i=0;i<maxn*maxn;++i)
        {
            if(strlen(acrossout[i])!=0)
                printf("%3d.%s\n",i,acrossout[i]);
        }
        printf("Down\n");
        for(int i=0;i<maxn*maxn;++i)
        {
            if(strlen(downout[i])!=0)
                printf("%3d.%s\n",i,downout[i]);
        }
    }
}
