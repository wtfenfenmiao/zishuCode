#include<cstdio>
#include<iostream>
#include<map>
#include<utility>
#include<set>

using namespace std;

map<pair<int,int>,int> pairID_num;




void con(int a,int b,int d)
{
    pair<int,int> pa;
    pa.first=a;
    pa.second=b;
    if(!pairID_num.count(pa))
        pairID_num[pa]=0;
    pairID_num[pa]+=d;
}

int main()
{
    //freopen("test_5_4_in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        pairID_num.clear();
        for(int i=0;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            if(a<b)
                con(a,b,1);
            else
                con(b,a,-1);
        }
        bool flag=true;
        for(map<pair<int,int>,int>::iterator it=pairID_num.begin();it!=pairID_num.end();++it)
        {
            if(it->second!=0)
            {
                flag=false;
                break;
            }
        }
        printf(flag?"YES\n":"NO\n");
    }
    return 0;
}

