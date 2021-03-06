#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>

using namespace std;

long long num;
map<long long,long long> sum_unchange;


void dfs(string& str,int s,int e,int depth)
{
    if(str[s]=='[')
    {
        int p=0;
        for(int i=s+1;i<e;++i)
        {
            if(str[i]=='[') ++p;
            if(str[i]==']') --p;
            if(p==0&&str[i]==',')
            {
                dfs(str,s+1,i-1,depth+1);
                dfs(str,i+1,e-1,depth+1);
            }
        }
    }
    else
    {
        long long w=0;
        while(s<=e)
        {
            w=w*10+str[s++]-'0';
        }
        ++num;
        ++sum_unchange[w<<depth];
    }
}

int main()
{
    //freopen("UVa_sub_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        sum_unchange.clear();
        num=0;
        string str;
        cin>>str;
        dfs(str,0,str.size()-1,0);
        int mi=num;
        for(map<long long,long long>::iterator it=sum_unchange.begin();it!=sum_unchange.end();++it)
        {
            long long thisnum=it->second;
            if(num-thisnum<mi)
                mi=num-thisnum;
        }
        cout<<mi<<endl;
    }
}
