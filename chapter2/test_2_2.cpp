#include<stdio.h>
int main()
{
    freopen("test_2_2_in.txt","r",stdin);
    freopen("test_2_2_out.txt","w",stdout);
    int a,b,c;
    int kase=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        int re=(a*70+b*21+c*15)%105;
        if(re>=10&&re<=100)
            printf("Case %d: %d\n",++kase,re);
        else
            printf("Case %d: No answer\n",++kase);
    }
    return 0;
}
