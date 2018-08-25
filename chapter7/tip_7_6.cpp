#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=1000000;
int maxd;
int ans[maxn];
int tempans[maxn];


long long gcd(long long x,long long y)
{
    long long re=1;
    while(x%2==0&&y%2==0)
    {
        re*=2;
        x/=2;
        y/=2;
    }
    while(x!=y)
    {
        long long temp=y-x;
        y=max(x,temp);
        x=min(x,temp);
    }
    re*=x;
    return re;
}

int getfirst(long long a,long long b)
{
    int i;
    for(i=1;;++i)
    {
        if(b<=a*i)
            break;
    }
    cout<<"get:"<<a<<" "<<b<<" "<<i<<endl;
    return i;
}

bool comp(int dnow)
{
    for(int i=dnow;i>=0;--i)
    {
        if(ans[i]!=tempans[i])
            return ans[i]==-1||tempans[i]<ans[i];
    }
    return false;
}

bool backtrack(int dnow,int from,long a,long b)
{
    cout<<"st:"<<maxd<<" "<<dnow<<" "<<from<<" "<<a<<" "<<b<<endl;
    if(dnow==maxd)
    {
        cout<<"there"<<endl;
        if(b%a||b/a<=from) return false;
        cout<<"there2"<<endl;
        tempans[dnow]=b/a;

        cout<<"tempans:"<<endl;
        for(int i=0;i<=maxd;++i)
        {
            cout<<tempans[i]<<" ";
        }
        if(comp(dnow)) memcpy(ans,tempans,sizeof(long long)*(dnow+1));
        return true;
    }
    cout<<"from:"<<from<<endl;
    cout<<"g:"<<getfirst(a,b)<<endl;
    int start=max(from,getfirst(a,b));
    cout<<"start:"<<start<<endl;
    bool flag=false;
    for(int i=start;;++i)
    {
        cout<<"comp:"<<(maxd-dnow+1)*b<<" "<<a*i<<endl;
        if((maxd-dnow+1)*b<=a*i) break;
        long long anew=a*i-b;
        cout<<"anew:"<<anew<<endl;
        long long bnew=b*i;
        cout<<"bnew:"<<bnew<<endl;     //存在大数溢出问题
        long long g=gcd(anew,bnew);
        cout<<"yuefen:"<<g<<endl;
        cout<<"next:"<<i+1<<" "<<anew/g<<" "<<bnew/g<<endl;
        tempans[dnow]=i;
        if(backtrack(dnow+1,i+1,anew/g,bnew/g)) flag=true;
        tempans[dnow]=-1;
    }
    return flag;
}


int main()
{
    long long a;
    long long b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
    for(maxd=0;;++maxd)
    {
        cout<<"最大坐标："<<maxd<<endl;
        memset(ans,-1,sizeof(ans));
        bool flag=backtrack(0,getfirst(a,b),a,b);
        if(flag)
            break;
    }
    for(int i=0;i<=maxd;++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
