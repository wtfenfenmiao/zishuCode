#include<stdio.h>
#define maxm 53
#define maxn 1003
int main()
{
    //freopen("test_3_7_in.txt","r",stdin);
    //freopen("test_3_7_out.txt","w",stdout);
    char s[maxm][maxn];
    char DNA[4]={'A','C','G','T'};
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int m;
        int n;
        int err=0;
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;++i)
        {
            scanf("%s",s[i]);
        }

        for(int i=0;i<n;++i)
        {
            int li[4]={0};
            for(int j=0;j<m;++j)
            {
                switch(s[j][i])
                {
                    case 'A':++li[0];break;
                    case 'C':++li[1];break;
                    case 'G':++li[2];break;
                    case 'T':++li[3];break;
                    default:break;
                }
            }
            int temp=li[0];
            int thisDNA=0;
            for(int k=1;k<4;++k)
            {
                if(li[k]>temp)
                {
                    temp=li[k];
                    thisDNA=k;
                }
            }
            err+=(m-temp);
            printf("%c",DNA[thisDNA]);
        }
        printf("\n%d\n",err);
    }
    return 0;


}
