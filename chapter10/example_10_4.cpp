#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

map<long long int,int> ma;


int main()
{
    //freopen("example_10_4_in.txt","r",stdin);
    long long int n;
    int kase=0;
    while(cin>>n&&n!=0)
    {
        if(n==1)
        {
            printf("Case %d: %d\n",++kase,2);
            continue;
        }
        ma.clear();
        long long int big=n;
        for(long long int i=2;i<=sqrt(big)+1;++i)
        {
            while(n%i==0)
            {
                ++ma[i];
                n/=i;
            }
            if(n==1)
                break;
        }
        if(n!=1)
            ma[n]=1;
        long long int re=0;
        for(map<long long int,int>::iterator it=ma.begin();it!=ma.end();++it)
        {
            //cout<<it->first<<" "<<it->second<<endl;
            //cout<<re<<endl;
            re+=(long long int)(pow(it->first,it->second)+0.5);
            //cout<<re<<endl;
        }
        if(ma.size()==1)
            re+=1;
        printf("Case %d: %lld\n",++kase,re);

    }
    return 0;
}

