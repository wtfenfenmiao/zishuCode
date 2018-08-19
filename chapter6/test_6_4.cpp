#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;


const int maxn=8;
const int movex[8]={-1,-2,-2,-1, 1, 2,2,1};
const int movey[8]={2 , 1,-1,-2,-2,-1,1,2};

int block[maxn][maxn];
int s1,s2;
int e1,e2;

struct Node
{
    int x;
    int y;
    Node(int x=0,int y=0):x(x),y(y){}
};

bool inside(int x,int y)
{
    if(x<0||x>=maxn||y<0||y>=maxn)
        return false;
    return true;
}

int findmin()
{
    Node* root=new(Node);
    root->x=s1;
    root->y=s2;
    block[s1][s2]=0;
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        Node* temp=qu.front();
        qu.pop();
        //cout<<"this:"<<temp->x<<" "<<temp->y<<endl;
        if(temp->x==e1&&temp->y==e2)
        {
            //cout<<block[e1][e2]<<endl;
            return block[e1][e2];

        }
        for(int i=0;i<maxn;++i)
        {
            int xt=temp->x+movex[i];
            int yt=temp->y+movey[i];
            //cout<<xt<<"   "<<yt<<endl;
            //cout<<"b:"<<block[xt][yt]<<endl;
            if(inside(xt,yt)&&block[xt][yt]==-1)
            {
                block[xt][yt]=block[temp->x][temp->y]+1;
                Node* v=new(Node);
                v->x=xt;
                v->y=yt;
                qu.push(v);
            }
        }
    }
}

int main()
{
    //freopen("test_6_4_in.txt","r",stdin);
    string start;
    string endd;
    while(cin>>start>>endd)
    {
        memset(block,-1,sizeof(block));
        s1=start[0]-'a';
        s2=start[1]-'1';
        e1=endd[0]-'a';
        e2=endd[1]-'1';
        //cout<<s1<<s2<<endl;
        //cout<<e1<<e2<<endl;
        int minlen=findmin();
        cout<<"To get from "<<start<<" to "<<endd<<" takes "<<minlen<<" knight moves."<<endl;
    }
    return 0;
}


