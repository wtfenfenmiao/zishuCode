#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

const int maxn=200;
set<int> prime;
int vis[maxn];
int kase=0;

void findprime(vector<int>& re,int cur,int n)
{
    if(cur==n)
    {
        int sum=re[cur-1]+re[0];
        if(prime.count(sum))
        {

            for(int i=0;i<cur-1;++i)
            {
                cout<<re[i]<<" ";
            }
            cout<<re[cur-1]<<endl;
        }
    }
    else
    {
        for(int i=2;i<=n;++i)
        {
            if(!vis[i]&&prime.count(i+re[cur-1]))
            {
                re.push_back(i);
                vis[i]=1;
                findprime(re,cur+1,n);
                vis[i]=0;
                re.pop_back();
            }
        }
    }
}


int main()
{
    prime.insert(2);
    prime.insert(3);
    prime.insert(5);
    prime.insert(7);
    prime.insert(11);
    prime.insert(13);
    prime.insert(17);
    prime.insert(19);
    prime.insert(23);
    prime.insert(29);
    prime.insert(31);
    prime.insert(37);
    prime.insert(41);
    prime.insert(43);
    int n;
    while(cin>>n)
    {
        if(kase)
            cout<<endl;
        cout<<"Case "<<++kase<<":"<<endl;
        vector<int> re;
        re.push_back(1);
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        findprime(re,1,n);
    }
    return 0;
}
