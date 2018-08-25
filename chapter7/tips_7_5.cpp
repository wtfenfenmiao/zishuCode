//第一版，不考虑效率，只考虑思路。非常慢，真的，非常慢......将近3s
/*
#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include<queue>

using namespace std;



vector<int> start;
vector<int> endd;
int cnt=0;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

void dfs()
{
    queue<vector<int> > qu;
    set<vector<int> > se;
    qu.push(start);
    se.insert(start);
    while(!qu.empty())
    {
        int si=qu.size();
        for(int i=0;i<si;++i)
        {
            vector<int> temp=qu.front();
            qu.pop();
            if(temp==endd)
                return;
            int j;
            for(j=0;j<temp.size();++j)
            {
                if(temp[j]==0)
                    break;
            }
            int x=j/3;
            int y=j%3;
            for(int k=0;k<4;++k)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(newx<0||newx>=3||newy<0||newy>=3)
                    continue;
                vector<int> newvec=temp;
                int newz=newx*3+newy;
                newvec[newz]=temp[j];
                newvec[j]=temp[newz];
                if(!se.count(newvec))
                {
                    qu.push(newvec);
                    se.insert(newvec);
                }
            }
        }
        ++cnt;
    }
    cnt=-1;
}

int main()
{
    freopen("tips_7_5_in.txt","r",stdin);
    int n=9;
    while(n--)
    {
        int num;
        scanf("%d",&num);
        start.push_back(num);
    }
    n=9;

    while(n--)
    {
        int num;
        scanf("%d",&num);
        endd.push_back(num);
    }
    dfs();
    cout<<cnt<<endl;
    return 0;
}
*/


//第二版，用数组，快一点
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<unordered_set>

using namespace std;



typedef int State[9];
const int maxn=370000;   //状态最多362880个
State st[maxn];
State endd;
int dist[maxn];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
set<int> se;
//unordered_set<int> se;
const int hashsize=1000003;
int has[hashsize];   //hash用
int nex[hashsize];

int ha(int rear)
{
    int v=0;
    for(int i=0;i<9;++i) v=v*10+st[rear][i];
    return v%hashsize;
}


//hash函数，不到0.5s，快很多了

void init_table()
{
    int s=ha(1);
    nex[1]=has[s];
    has[s]=1;
}

bool is_insert(int rear)
{
    int s=ha(rear);
    int u=has[s];
    while(u)
    {
        if(memcmp(st[u],st[rear],sizeof(st[rear]))==0) return false;
        u=nex[u];

    }
    nex[rear]=has[s];
    has[s]=rear;
    return true;
}

//用set判断是不是重了，不到1s（接近1s）
//用unordered_set（hash set的话不到0.6s），还是比hash数组慢
/*
void init_table()
{
    int v=0;
    for(int i=0;i<9;++i) v=v*10+st[1][i];
    se.insert(v);
}

bool is_insert(int rear)
{
    int v=0;
    for(int i=0;i<9;++i) v=v*10+st[rear][i];
    if(se.count(v))
        return false;
    else
    {
        se.insert(v);
        return true;
    }
}
*/

int bfs()
{
    init_table();
    int fr=1;
    int rear=2;
    while(fr<rear)
    {
        State& s=st[fr];
        if(memcmp(s,endd,sizeof(s))==0)
        {
            return fr;
        }
        int i;
        for(i=0;i<9;++i)
        {
            if(s[i]==0) break;
        }
        int x=i/3;
        int y=i%3;
        for(int k=0;k<4;++k)
        {
            int newx=x+dx[k];
            int newy=y+dy[k];
            int newz=newx*3+newy;
            if(newx<0||newx>=3||newy<0||newy>=3)
                continue;
            State& t=st[rear];
            memcpy(&t,&s,sizeof(s));
            t[i]=s[newz];
            t[newz]=s[i];
            dist[rear]=dist[fr]+1;
            //cout<<rear<<endl;
            if(is_insert(rear))
            {
                ++rear;
            }
        }
        ++fr;
    }
    return 0;
}



int main()
{

    freopen("tips_7_5_in.txt","r",stdin);
    memset(st,0,sizeof(st));
    memset(endd,0,sizeof(endd));
    memset(dist,0,sizeof(dist));
    memset(has,0,sizeof(has));
    memset(nex,0,sizeof(nex));
    for(int i=0;i<9;++i) scanf("%d",&st[1][i]);
    for(int i=0;i<9;++i) scanf("%d",&endd[i]);
    int re=bfs();
    cout<<((re==0)?(-1):(dist[re]))<<endl;
}
