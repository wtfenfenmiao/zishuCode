#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 10008

//这个是错的！
int main()
{
    freopen("test_3_10_in.txt","r",stdin);
    //freopen("test_3_10_out.txt","w",stdout);
    int w[6],h[6];
    while(scanf("%d %d",&w[0],&h[0])!=EOF)
    {
        int con[maxn];
        memset(con,0,sizeof(con));
        con[w[0]]+=2;
        con[h[0]]+=2;
        for(int i=1;i<6;++i)
        {
            scanf("%d %d",&w[i],&h[i]);
            con[w[i]]+=2;
            con[h[i]]+=2;
        }
        bool flag=true;
        for(int i=0;i<maxn;++i)
        {
            if(con[i]!=0&&con[i]%4!=0)
            {
                flag=false;
                break;
            }
        }


        printf("%s\n",flag?"POSSIBLE":"IMPOSSIBLE");


    }
    return 0;



}
