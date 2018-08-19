#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>

using namespace std;


int nei[26][26];
int sear[26];
int in[26];
int out[26];
int cnt=0;
set<int> se;

void printnei()
{
    for(int i=0;i<26;++i)
    {
        for(int j=0;j<26;++j)
        {
            cout<<nei[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printsear()
{

        for(int j=0;j<26;++j)
        {
            cout<<sear[j]<<" ";
        }
        cout<<endl;
}
void dfs(int u)
{
    //cout<<"there2"<<endl;
    sear[u]=1;
    --cnt;
    for(int v=0;v<26;++v)
    {
        if(nei[u][v]&&!sear[v])
        {
            //cout<<u+'a'<<" "<<v+'a'<<endl;
            //cout<<"s:"<<sear[u][v]<<endl;
            //cout<<"n:"<<nei[u][v]<<endl;
           dfs(v);
        }
    }
}






int main()
{
    //freopen("example_6_16_in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    //cout<<kase<<endl;
    while(kase--)
    {
        memset(out,0,sizeof(out));
        memset(in,0,sizeof(in));
        memset(nei,0,sizeof(nei));
        memset(sear,0,sizeof(sear));
        se.clear();
        cnt=0;
        int n;
        scanf("%d",&n);
        //cout<<n<<endl;
        while(n--)
        {
            string word;
            cin>>word;
            //cout<<word<<endl;
            int s=word[0]-'a';
            int e=word[word.size()-1]-'a';
            ++out[s];
            ++in[e];
              nei[s][e]=1;
              nei[e][s]=1;
            se.insert(e);
            se.insert(s);


        }
        cnt=se.size();
        dfs(*se.begin());     //连通就是连通，最简单的连通，别想太多
        //printnei();
       // cout<<"cntbefore:"<<cnt<<endl;
        int jiDu=0;
        int large=0;
        int small=0;
        //cout<<"cnt:"<<cnt<<endl;
        if(cnt!=0)
        {
            printf("The door cannot be opened.\n");
            continue;
        }
        for(int i=0;i<26;++i)
        {
            if(in[i]!=out[i])
            {
                ++jiDu;
                if(in[i]-out[i]==1)
                    ++large;
                else if(out[i]-in[i]==1)
                    ++small;
            }
        }
        if(jiDu>2)
        {
            printf("The door cannot be opened.\n");
            continue;
        }

        if(jiDu==2&&(!(large==1&&small==1)))
        {
            printf("The door cannot be opened.\n");
            continue;
        }
        printf("Ordering is possible.\n");

    }
    return 0;
}
