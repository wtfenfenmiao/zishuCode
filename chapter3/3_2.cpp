#include<stdio.h>
#include<string.h>    //memset
#define maxn 1050
int light[maxn];
int main()
{
    int n,k;

    while(scanf("%d %d",&n,&k)!=EOF)
    {
        memset(light,0,sizeof(light));     //初始值都弄成0
        bool first=true;
        for(int i=1;i<=k;++i)
        {
            for(int j=i;j<=n;j+=i)
            {
                light[j-1]=!light[j-1];
            }
        }
        for(int i=0;i<n;++i)
        {
            if(light[i])
            {
                if(first)
                    first=false;
                else
                    printf(" ");
                printf("%d",i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
