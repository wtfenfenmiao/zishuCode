#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 12

int main()
{
    //freopen("test_3_6_in.txt","r",stdin);
    //freopen("test_3_6_out.txt","w",stdout);
    int row,col;
    int kase=0;
    char s[maxn][maxn];
    while(scanf("%d %d",&row,&col)!=EOF&&row!=0)
    {
        if(kase)
            printf("\n");
        printf("puzzle #%d:\n",++kase);
        char acro[maxn*maxn][maxn];
        char down[maxn*maxn][maxn];
        for(int i=0;i<maxn*maxn;++i)
        {
            memset(acro[i],0,sizeof(acro[i]));
            memset(down[i],0,sizeof(down[i]));
        }
        for(int i=0;i<row;++i)
        {
            scanf("%s",s[i]);
        }

        int con=1;
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                int num=0;
                if(s[i][j]!='*'&&(i==0||j==0||(i!=0&&s[i-1][j]=='*')||(j!=0&&s[i][j-1]=='*')))
                    num=con++;

                //across
                if(num&&(j==0||s[i][j-1]=='*'))
                {
                    int k=j;
                    while(k<col&&s[i][k]!='*')
                    {
                        acro[num][k-j]=s[i][k];
                        ++k;
                    }

                }
                //down
                if(num&&(i==0||s[i-1][j]=='*'))
                {
                    int k=i;
                    while(k<row&&s[k][j]!='*')
                    {
                        down[num][k-i]=s[k][j];
                        ++k;
                    }
                }
                //dowm
            }
        }
        printf("Across\n");
        for(int i=0;i<maxn*maxn;++i)
        {
            if(strlen(acro[i])!=0)
                printf("%3d.%s\n",i,acro[i]);
        }
        printf("Down\n");
        for(int i=0;i<maxn*maxn;++i)
        {
            if(strlen(down[i])!=0)
                printf("%3d.%s\n",i,down[i]);
        }
    }
}
