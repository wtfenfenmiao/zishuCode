#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>

using namespace std;

map<long long,long long> sum_unchange;  //某个秤砣为基准的总重量：这个重量下能不改重量的秤砣数
long long sum;   //有多少个秤砣

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
        ++sum;
        ++sum_unchange[w<<depth];
    }
}

int main()
{
    //freopen("test_6_6_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        sum_unchange.clear();
        sum=0;
        string str;
        cin>>str;
        dfs(str,0,str.size()-1,0);
        int mi=sum;
        for(map<long long,long long>::iterator it=sum_unchange.begin();it!=sum_unchange.end();++it)   //注意这个，类型的问题，int撑不住得long long
        {
            //cout<<it->first<<" "<<it->second<<endl;
            int thisnum=it->second;
            if(sum-thisnum<mi)
                mi=sum-thisnum;
        }
        cout<<mi<<endl;
    }
}
