
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;


const int maxn=205;
int re[maxn];
int ifvis[maxn][maxn];
int cap[3];

struct Node
{
    int v[3];
    int dist;
    bool operator < (const Node& rhs) const
    {
        return dist>rhs.dist;
    }
    bool operator > (const Node& rhs) const
    {
        return dist<rhs.dist;
    }
};

void update_re(Node& t)
{
    for(int i=0;i<3;++i)
    {
        int te=t.v[i];
        if(re[te]==-1||t.dist<re[te])
            re[te]=t.dist;
    }
}

void solve(int a,int b,int c,int d)
{
    memset(cap,0,sizeof(cap));
    memset(ifvis,0,sizeof(ifvis));
    memset(re,-1,sizeof(re));
    cap[0]=a;
    cap[1]=b;
    cap[2]=c;
    Node start;
    start.v[0]=0;
    start.v[1]=0;
    start.v[2]=c;
    start.dist=0;
    ifvis[0][0]=1;
    priority_queue<Node> qu;
    qu.push(start);
    while(!qu.empty())
    {
        Node temp=qu.top();
        qu.pop();
        update_re(temp);
        if(re[d]!=-1)
            break;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                if(i==j||temp.v[i]==0||temp.v[j]==cap[j])
                    continue;
                int amount=min(cap[j],temp.v[i]+temp.v[j])-temp.v[j];
                Node ne;
                memcpy(&ne,&temp,sizeof(temp));
                ne.v[i]-=amount;
                ne.v[j]+=amount;
                ne.dist+=amount;
                if(!ifvis[ne.v[0]][ne.v[1]])
                {
                    ifvis[ne.v[0]][ne.v[1]]=1;
                    qu.push(ne);
                }
            }
        }
    }
    while(d>=0)
    {
        if(re[d]>=0)
        {
            cout<<re[d]<<" "<<d<<endl;
            return;
        }
    --d;
    }
}


int main()
{
    freopen("example_7_8_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        solve(a,b,c,d);
    }
    return 0;
}

//下面这种是用指针的
/*
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;


const int maxn=205;
int re[maxn];
int ifvis[maxn][maxn];
int cap[3];

struct Node
{
    int v[3];
    int dist;
};

struct Ncmp
{
    bool operator()(Node* const x,Node* const y)
    {
        return x->dist>y->dist;
    }
};

void update_re(Node* t)
{
    for(int i=0;i<3;++i)
    {
        int te=t->v[i];
        if(re[te]==-1||t->dist<re[te])
            re[te]=t->dist;
    }
}

void solve(int a,int b,int c,int d)
{
    memset(cap,0,sizeof(cap));
    memset(ifvis,0,sizeof(ifvis));
    memset(re,-1,sizeof(re));
    cap[0]=a;
    cap[1]=b;
    cap[2]=c;
    Node* start=new(Node);
    start->v[0]=0;
    start->v[1]=0;
    start->v[2]=c;
    start->dist=0;
    ifvis[0][0]=1;
    priority_queue<Node*,vector<Node*>,Ncmp> qu;
    qu.push(start);
    while(!qu.empty())
    {
        Node* temp=qu.top();
        qu.pop();
        update_re(temp);
        if(re[d]!=-1)
            break;
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                if(i==j||temp->v[i]==0||temp->v[j]==cap[j])
                    continue;
                int amount=min(cap[j],temp->v[i]+temp->v[j])-temp->v[j];
                Node* ne=new(Node);
                memcpy(ne,temp,sizeof(*temp));
                ne->v[i]-=amount;
                ne->v[j]+=amount;
                ne->dist+=amount;
                if(!ifvis[ne->v[0]][ne->v[1]])
                {
                    ifvis[ne->v[0]][ne->v[1]]=1;
                    qu.push(ne);
                }
            }
        }
    }
    while(d>=0)
    {
        if(re[d]>=0)
        {
            cout<<re[d]<<" "<<d<<endl;
            return;
        }
        --d;
    }
}


int main()
{
    //freopen("example_7_8_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        solve(a,b,c,d);
    }
    return 0;
}

*/
