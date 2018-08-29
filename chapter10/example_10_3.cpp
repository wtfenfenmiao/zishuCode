#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn=10010;
int fprime[maxn];
vector<int> prime;


void findprime()
{
    for(int i=2;i<maxn;++i)
    {
        if(fprime[i]==0)
        {
            //cout<<i<<endl;
            prime.push_back(i);
            for(int j=i*i;j<maxn;j+=i)
                fprime[j]=1;
        }
    }
}


void add_eachnum(int num,int pos)
{
    for(int i=0;i<prime.size();++i)
    {
        while(num%prime[i]==0)
        {
            fprime[prime[i]]+=pos;
            num/=prime[i];
        }
        if(num==1)
            break;
    }
}

void add_num(int num,int pos)
{
    for(int i=1;i<=num;++i)
    {
        add_eachnum(i,pos);
    }
}

void printprime()
{
    for(int i=0;i<prime.size();++i)
    {
        cout<<prime[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    //freopen("example_10_3_in.txt","r",stdin);
    int p,q,r,s;
    memset(fprime,0,sizeof(fprime));
    findprime();
    //printprime();
    while(cin>>p>>q>>r>>s)
    {
        memset(fprime,0,sizeof(fprime));
        add_num(p,1);
        add_num(q,-1);
        add_num(r,-1);
        add_num(s,1);
        add_num(p-q,-1);
        add_num(r-s,1);
        double re=1.0;
        for(int i=0;i<prime.size();++i)
        {
            //if(fprime[prime[i]])
            //    cout<<prime[i]<<":"<<fprime[prime[i]]<<endl;
            re*=(double)pow(prime[i],fprime[prime[i]]);
        }
        printf("%.5f\n",re);
    }
    return 0;
}
