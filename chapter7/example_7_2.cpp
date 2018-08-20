#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=20;
int save[maxn];

int main()
{
    //freopen("example_7_2_in.txt","r",stdin);
    int n;
    int kase=0;
    while(cin>>n)
    {
        memset(save,0,sizeof(save));
        long long ma=0;
        int i;
        for(i=0;i<n;++i)
        {
            scanf("%d",&save[i]);
            //cout<<save[i]<<endl;
        }

        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                int t=i;
                long long prod=1;
                while(t<=j)
                {
                    prod*=save[t];
                    ++t;
                }
                if(prod>ma)
                    ma=prod;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",++kase,ma<0?0:ma);
    }
}
