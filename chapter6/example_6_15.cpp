#include<cstdio>
#include<cstring>
#include<iostream>
//这道题的debug经验告诉我，最简单的bug，很可能，耗时最久......
using namespace std;

const int maxn=105;

bool nei[maxn][maxn];

int result[maxn];
int n,m;
int t=maxn-1;
int dfscondi[maxn];

bool Dfs(int u)
{
    //cout<<"there2:"<<u<<" "<<n<<endl;
    dfscondi[u]=-1;
    for(int v=1;v<=n;++v)
    {
        //cout<<"e:"<<u<<v<<endl;
        if(nei[u][v])
        {
            //cout<<"t1"<<endl;
            if(dfscondi[v]==-1) return false;  //有环
            if((!dfscondi[v])&&(!Dfs(v))) return false;
        }
    }
    dfscondi[u]=1;
    //cout<<"t:"<<t<<endl;
    result[t--]=u;
    //cout<<result[t+1]<<endl;
    return true;
}

bool topu()
{
    //cout<<"there1"<<endl;
    for(int u=1;u<=n;++u)
    {
        //cout<<"there3:"<<u<<endl;
        if(!dfscondi[u])
        if(!Dfs(u))
            return false;

    }
    //cout<<"there4"<<endl;
    return true;
}

int main()
{
    //freopen("example_6_15_in.txt","r",stdin);
    while(scanf("%d %d",&n,&m)!=EOF&&n!=0)
    {
        //cout<<n<<" "<<m<<endl;
        t=maxn-1;
        memset(nei,0,sizeof(nei));
        memset(result,0,sizeof(result));
        memset(dfscondi,0,sizeof(dfscondi));
        while(m--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            //cout<<"val:"<<x<<" "<<y<<endl;
            nei[x][y]=true;
        }
        topu();
        for(int i=maxn-n;i<maxn-1;++i)
            printf("%d ",result[i]);
        printf("%d\n",result[maxn-1]);
    }
    return 0;
}


/*再做一遍
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;


const int maxn=105;

bool nei[maxn][maxn];
int condi[maxn];
int result[maxn];
int t;
int n,m;

bool dfs(int u)
{
    condi[u]=-1;
    for(int v=1;v<=n;++v)
    {
        if(nei[u][v])
        {
            if(condi[v]==-1) return false;
            if(!condi[v]&&!dfs(v)) return false;
        }

    }
    condi[u]=1;
    //cout<<u<<endl;
    result[t--]=u;
    return true;
}

bool topu()
{
    for(int i=1;i<=n;++i)
    {
        //cout<<i<<endl;
        if(!condi[i])
        if(!dfs(i))
            return false;
    }
    return true;
}

int main()
{
    //freopen("example_6_15_in.txt","r",stdin);
    while(scanf("%d %d",&n,&m)!=EOF&&n!=0)
    {
        t=maxn-1;
        memset(nei,0,sizeof(nei));
        memset(result,0,sizeof(result));
        memset(condi,0,sizeof(condi));
        while(m--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            nei[x][y]=true;
        }
        topu();
        for(int i=maxn-n;i<maxn-1;++i)
        {
            printf("%d ",result[i]);
        }
        printf("%d\n",result[maxn-1]);
    }
    return 0;
}

*/
