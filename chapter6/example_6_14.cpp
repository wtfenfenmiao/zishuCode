#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#include<utility>

using namespace std;

struct Node
{
    int r;
    int c;
    int dir;
    Node(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};

const int maxn=11;
bool block[maxn][maxn][4][4];
int d[maxn][maxn][4];
Node* father[maxn][maxn][4];

int dirx[4]={-1,0,1,0};
int diry[4]={0,1,0,-1};

int r1,c1,r2,c2;
char dirin;


set<pair<int,int> > se;



int dir(char di)
{
    switch(di)
    {
        case 'N':return 0;break;
        case 'E':return 1;break;
        case 'S':return 2;break;
        case 'W':return 3;break;
        default:break;
    }
}

int turn(char tu)
{
    switch(tu)
    {
        case 'F':return 0;break; //≤ªπ’Õ‰
        case 'L':return -1;break; //ƒÊ ±’Î
        case 'R':return 1;break; //À≥ ±’Î
        default:break;
    }
}

bool inside(int r,int c)
{
    pair<int,int> pa;
    pa.first=r;
    pa.second=c;
    if(se.count(pa))
    {
        return true;
    }
    return false;
}

void print(Node* u)
{
    vector<Node*> vec;
    vec.push_back(u);
    Node* fa=father[u->r][u->c][u->dir];
    while(fa)
    {
        vec.push_back(fa);
        fa=father[fa->r][fa->c][fa->dir];
    }
    r1-=dirx[dir(dirin)];
    c1-=diry[dir(dirin)];
    Node* start=new(Node);
    start->r=r1;
    start->c=c1;
    vec.push_back(start);
    printf(" ");
    int cnt=0;
    for(int i=vec.size()-1;i>=0;--i)
    {
        ++cnt;
        printf(" (%d,%d)",vec[i]->r,vec[i]->c);
        if(cnt%10==0)
        printf("\n ");
    }
    if(cnt%10!=0)
    printf("\n");
}

void solve()
{
    //cout<<"re:"<<r2<<" "<<c2<<endl;
    queue<Node*> qu;
    Node* u=new Node();
    u->r=r1;
    u->c=c1;
    if(!inside(r1,c1))
    {
        printf("  No Solution Possible\n");
        return;
    }
    u->dir=dir(dirin);
    qu.push(u);
    d[r1][c1][dirin]=1;
    //cout<<"start:"<<u->r<<" "<<u->c<<" "<<u->dir<<endl;
    father[r1][c1][dirin]=NULL;
    while(!qu.empty())
    {
        Node* temp=qu.front();
        qu.pop();
        if(temp->r==r2&&temp->c==c2)
        {
            print(temp);
            return;
        }
        //cout<<"node:"<<temp->r<<" "<<temp->c<<" "<<temp->dir<<endl;
        for(int i=0;i<4;++i)
        {
            Node* v=new(Node);
            v->r=temp->r+dirx[i];
            v->c=temp->c+diry[i];
            v->dir=i;
            //cout<<"innode:"<<i<<":"<<v->r<<" "<<v->c<<" "<<v->dir<<endl;
            //cout<<"decide:"<<temp->r<<" "<<temp->c<<" "<<temp->dir<<" "<<i<<endl;
            if(block[temp->r][temp->c][temp->dir][i]&&inside(v->r,v->c)&&d[v->r][v->c][v->dir]==0)
            {

                qu.push(v);
                //cout<<"push:"<<v->r<<" "<<v->c<<" "<<v->dir<<endl;
                father[v->r][v->c][v->dir]=temp;
                d[v->r][v->c][v->dir]=temp->dir+1;
            }
        }
    }
    printf("  No Solution Possible\n");
    return;

}



int main()
{
    //freopen("example_6_14_in.txt","r",stdin);
    string name;
    while(cin>>name)
    {
        if(name=="END")
            break;
        memset(block,0,sizeof(block));
        memset(d,0,sizeof(d));
        memset(father,0,sizeof(father));
        se.clear();
        cout<<name<<endl;

        cin>>r1>>c1>>dirin>>r2>>c2;
            pair<int,int> pa;
            pa.first=r1;
            pa.second=c1;
            se.insert(pa);
            pa.first=r2;
            pa.second=c2;
            se.insert(pa);
        r1+=dirx[dir(dirin)];
        c1+=diry[dir(dirin)];


        //cout<<r1<<" "<<c1<<endl;
        int xtemp,ytemp;

        while(cin>>xtemp&&xtemp!=0)
        {
            cin>>ytemp;
            //cout<<xtemp<<ytemp<<endl;
            pair<int,int> pa;
            pa.first=xtemp;
            pa.second=ytemp;
            se.insert(pa);
            string order;
            while(cin>>order&&order!="*")
            {
                //cout<<order<<endl;
                int di=dir(order[0]);
                for(int i=1;i<order.size();++i)
                {
                    int tur=turn(order[i]);
                    block[xtemp][ytemp][di][(di+tur+4)%4]=true;
                    //cout<<"block:"<<xtemp<<" "<<ytemp<<" "<<di<<" "<<(di+tur+4)%4<<endl;
                }
            }
            //cout<<endl;
        }

        solve();
    }
    return 0;
}
