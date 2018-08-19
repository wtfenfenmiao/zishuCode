#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>

using namespace std;

const int maxn=25;
const int movex[4]={1,0, 0,-1};
const int movey[4]={0,1,-1, 0};

int m,n,lb;
bool block[maxn][maxn];
int d[maxn][maxn][maxn*maxn];

struct Node
{
    int x;
    int y;
    int lb;
    Node(int x=0,int y=0,int lb=0):x(x),y(y),lb(lb){}
};

bool inside(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n)
    {
        return false;
    }
    return true;
}

int findmin()
{
    int minlen=maxn*maxn;
    Node* root=new(Node);
    root->x=0;
    root->y=0;
    root->lb=lb;
    queue<Node*> qu;
    d[0][0][lb]=0;
    qu.push(root);
    while(!qu.empty())
    {
        Node* temp=qu.front();
        qu.pop();
        int x=temp->x;
        int y=temp->y;
        int lbt=temp->lb;
        //cout<<"x:"<<x<<"  "<<"y:"<<y<<"  "<<"lbt:"<<lbt<<endl;
        if(x==m-1&&y==n-1)
        {
            if(d[x][y][lbt]<minlen)
                minlen=d[x][y][lbt];
        }
        for(int i=0;i<4;++i)
        {
            int xt=x+movex[i];
            int yt=y+movey[i];
            if(inside(xt,yt))
            {
                int lbtemp=(block[xt][yt]==1)?lbt-1:lb;
                if(lbtemp>=0)
                {
                    if(d[xt][yt][lbtemp]==-1)
                    {
                        Node* v=new(Node);
                        v->x=xt;
                        v->y=yt;
                        v->lb=lbtemp;
                        d[xt][yt][lbtemp]=d[x][y][lbt]+1;
                        qu.push(v);
                    }
                }
            }
        }
    }
    return minlen;
}

int main()
{
    //freopen("test_6_5_in.txt","r",stdin);
    //freopen("test_6_5_out.txt","w",stdout);
    int kase;
    cin>>kase;
    int cnt=0;
    while(kase--)
    {
        //cout<<"kase:"<<++cnt<<endl;
        memset(block,0,sizeof(block));
        memset(d,-1,sizeof(d));
        cin>>m>>n>>lb;
        //cout<<m<<" "<<n<<endl;
        //cout<<lb<<endl;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d",&block[i][j]);
               //cout<<block[i][j]<<" ";
            }
            //cout<<endl;
        }
        int result=findmin();
        result=(result>m*n)?(-1):(result);
        cout<<result<<endl;
    }
}
