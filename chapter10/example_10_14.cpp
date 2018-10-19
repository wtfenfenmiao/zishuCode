//这个办法算c的时候会溢出......用动态规划吧，别用这个了

#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;


const int maxn=1005;
int f[maxn];


int main()
{
    freopen("example_10_14_in.txt","r",stdin);
    freopen("example_10_14_out.txt","w",stdout);
    memset(f,-1,sizeof(f));
    f[0]=1;
    int kase;
    scanf("%d",&kase);
    for(int k=1;k<=kase;++k)
    {
        int n;
        scanf("%d",&n);
        cout<<"Case "<<k<<": ";
        if(f[n]!=-1)
        {
            cout<<f[n]<<endl;
            continue;
        }
        for(int i=0;i<=n;++i)
        {
            if(f[i]!=-1)
                continue;
            f[i]=0;
            long long c=1;
            for(int j=1;j<=i;++j)
            {
                //cout<<"there"<<endl;
                c=c*(i-j+1)/j;
                cout<<c<<endl;
                f[i]+=((c%10056)*f[i-j])%10056;
                f[i]=f[i]%10056;
            }
        }

        cout<<f[n]<<endl;



    }
}
