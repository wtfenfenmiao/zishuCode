#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>

using namespace std;

const int maxn=26;
int nei[maxn][maxn];
bool ifsear[maxn];
int cnt=0;
set<int> se;
int in[maxn];
int out[maxn];

void dfs(int u)
{
    ifsear[u]=true;
    --cnt;
    for(int v=0;v<maxn;++v)
    {
        if(nei[u][v]&&!ifsear[v])
            dfs(v);
    }
}

int main()
{
    //freopen("example_6_16_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        int n;
        cin>>n;
        memset(nei,0,sizeof(nei));
        memset(ifsear,0,sizeof(ifsear));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        se.clear();
        while(n--)
        {
            string word;
            cin>>word;
            int s=word[0]-'a';
            int e=word[word.size()-1]-'a';
            se.insert(s);
            se.insert(e);
            nei[s][e]=nei[e][s]=1;
            ++in[e];
            ++out[s];
        }
        cnt=se.size();
        //cout<<"b:"<<cnt<<endl;
        dfs(*se.begin());
        //cout<<"a:"<<cnt<<endl;
        if(cnt!=0)
        {
            cout<<"The door cannot be opened."<<endl;
            continue;
        }
        int jiDu=0;
        int large=0;
        int small=0;
        for(int i=0;i<maxn;++i)
        {
            if(in[i]!=out[i])
            {
                ++jiDu;
                if(in[i]-out[i]==1)
                    ++large;
                else if(in[i]-out[i]==-1)
                    ++small;
            }
        }
        if(jiDu>2)
        {
            cout<<"The door cannot be opened."<<endl;
            continue;
        }
        if(jiDu==2&&!(large==1&&small==1))
        {
            cout<<"The door cannot be opened."<<endl;
            continue;
        }
        cout<<"Ordering is possible."<<endl;

    }
    return 0;
}
