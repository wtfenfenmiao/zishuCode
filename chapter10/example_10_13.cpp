#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=35;
int f[maxn];

int main()
{
    int n;
    memset(f,-1,sizeof(f));
    f[0]=0;
    f[1]=0;
    f[2]=0;
    while(scanf("%d",&n)&&n!=0)
    {
        if(f[n]!=-1)
        {
            cout<<f[n]<<endl;
            continue;
        }
        for(int i=3;i<=n;++i)
        {
            if(f[i]!=-1)
                continue;
            f[i]=1<<(i-3);
            for(int j=2;j<=i-2;++j)
            {
                //cout<<"there"<<endl;
                f[i]+=(1<<(i-j-2))*((1<<(j-2))-f[j-2]);
            }
        }
        cout<<f[n]<<endl;

    }
}
