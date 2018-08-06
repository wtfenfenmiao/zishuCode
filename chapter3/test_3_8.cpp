#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 3003
//黔驴技穷，就是没过,不知道哪的问题
int main()
{

    //freopen("test_3_8_in.txt","r",stdin);
    //freopen("test_3_8_out.txt","w",stdout);
    int m;   //分子
    int n;   //分母
    bool beginflag=true;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        if(beginflag)
        {
            beginflag=false;
        }
        else
        {
            printf("\n");
        }

        int repeat[maxn];
        memset(repeat,0,sizeof(repeat));
        int before=m/n;    //小数点之前
        char after[maxn];   //小数点之后
        memset(after,0,sizeof(after));
        int afnum=m%n;
        //printf("afnum:%d\n",afnum);
        int con=0;

            //printf("there1\n");
            while(afnum!=0&&repeat[afnum]==0)
            {
                repeat[afnum]=con+1;
                //printf("repeat:%d,%d\n",afnum,repeat[afnum]);
                afnum*=10;
                while(afnum<n)
                {
                    afnum*=10;
                    after[con++]='0';
                }
                after[con++]=afnum/n+'0';
                afnum=afnum%n;
            }


        printf("%d/%d = %d.",m,n,before);



        if(con>50)
        {
            //printf("case2\n");
            //printf("%d\n",afnum);
            //printf("%d\n",con);
            //printf("%d\n",repeat[afnum]);
            for(int i=0;i<repeat[afnum]-1;++i)
            {
                printf("%c",after[i]);
            }
            printf("(");
            for(int i=repeat[afnum]-1;i<50;++i)
            {
                printf("%c",after[i]);
            }
            printf("...)\n");
            printf("   %d = number of digits in repeating cycle\n",afnum==0?1:con-repeat[afnum]+1);
        }

        else if(afnum==0)
        {
            //printf("case3\n");
            for(int i=0;after[i];++i)
                printf("%c",after[i]);
            printf("(0)\n");
            printf("   %d = number of digits in repeating cycle\n",1);

        }

        else
        {
            //printf("case4\n");
            for(int i=0;i<repeat[afnum]-1;++i)
            {
                printf("%c",after[i]);
            }
            printf("(");
            for(int i=repeat[afnum]-1;i<con;++i)
            {
                printf("%c",after[i]);
            }
            printf(")\n   %d = number of digits in repeating cycle\n",con-repeat[afnum]+1);

        }

    }
    return 0;


}
