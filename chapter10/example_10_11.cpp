#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=25;

double pin[maxn];
double pout[maxn];
double sum;

int flag[maxn];

void backtrack(int n,int r,int now)
{
    if(r==0&&now<=n)
    {
        double temp=1.0;
        for(int i=0;i<n;++i)
        {
            //cout<<flag[i];
            temp*=flag[i]==1?pin[i]:(1-pin[i]);
        }
        sum+=temp;
        for(int i=0;i<now;++i)
        {
            if(flag[i])
                pout[i]+=temp;
        }
        //cout<<endl;
        return;
    }
    else if(r>0&&now==n)
    {
        return;
    }
    flag[now]=1;
    backtrack(n,r-1,now+1);
    flag[now]=0;
    backtrack(n,r,now+1);
}

int main()
{
    //freopen("example_10_11_in.txt","r",stdin);
    int n,r;
    int kase=0;
    while(scanf("%d %d",&n,&r)&&n!=0)
    {
        cout<<"Case "<<++kase<<":"<<endl;
        memset(pin,0,sizeof(pin));
        memset(pout,0,sizeof(pout));
        memset(flag,0,sizeof(flag));
        sum=0.0;
        //cout<<"there"<<endl;
        for(int i=0;i<n;++i)
        {
            scanf("%lf",&pin[i]);
        }
        //cout<<"there2"<<endl;
        backtrack(n,r,0);
        for(int i=0;i<n;++i)
        {
            printf("%.6f\n",pout[i]/sum);
        }
    }
}


