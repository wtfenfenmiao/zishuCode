#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#include<set>

using namespace std;

const int maxn=100005;

int d[maxn];
//int d2[maxn];

map<int,map<int,vector<int> > > color;
vector<int> colorRe;
int n,m;

void bfs1()
{
    queue<int> qu;
    d[n]=0;
    qu.push(n);
    while(!qu.empty())
    {
        int thisnode=qu.front();
        qu.pop();
        //cout<<"th:"<<thisnode<<endl;
        if(thisnode==1)
            return;
        for(map<int,vector<int> >::iterator it=color[thisnode].begin();it!=color[thisnode].end();++it)
        {
            //cout<<"there"<<endl;
            int i=it->first;
            if(d[i]==-1)
            {
                d[i]=d[thisnode]+1;
                qu.push(i);
            }
        }
    }
}


void bfs2()
{
    queue<int> qu;
    qu.push(1);
    int dnow=d[1];
    //d2[1]=1;
    while(!qu.empty())
    {
        if(dnow==0)
            return;
        set<int> preNode;
        //cout<<"out:";
        while(!qu.empty())
        {
            //cout<<qu.front()<<" ";
            preNode.insert(qu.front());
            qu.pop();
        }
        //cout<<endl;
        dnow-=1;
        map<int,vector<int> > color_node;
        for(set<int>::iterator it=preNode.begin();it!=preNode.end();++it)
        {
            for(map<int,vector<int> >::iterator it1=color[*it].begin();it1!=color[*it].end();++it1)
            {
                int nextNode=it1->first;
                if(d[nextNode]==dnow)
                {
                    for(int i=0;i<it1->second.size();++i)
                    {
                        color_node[it1->second[i]].push_back(nextNode);
                    }
                }
            }
        }
        map<int,vector<int> >::iterator it=color_node.begin();
        colorRe.push_back(it->first);
        for(int i=0;i<it->second.size();++i)
        {
            qu.push(it->second[i]);
        }
        //for(;it!=color_node.end();++it)
        //{
        //    cout<<"color:"<<it->first<<endl;
        //    cout<<"node:";
        //    for(int i=0;i<it->second.size();++i)
        //        cout<<it->second[i]<<" ";
        //    cout<<endl;
        //}
    }
}

void printd()
{
    for(int i=0;i<6;++i)
        cout<<d[i]<<" ";
    cout<<endl;
}

void printcolor()
{
    for(map<int,map<int,vector<int> > >::iterator it=color.begin();it!=color.end();++it)
    {
        cout<<"start:"<<it->first<<endl;
        for(map<int,vector<int> >::iterator it2=it->second.begin();it2!=it->second.end();++it2)
        {
            cout<<"end:"<<it2->first<<endl;
            for(int i=0;i<it2->second.size();++i)
            {
                cout<<"color:"<<it2->second[i]<<endl;
            }
        }
    }
}

int main()
{
    //freopen("example_6_20_in.txt","r",stdin);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        //cout<<n<<" "<<m<<endl;
        memset(d,-1,sizeof(d));
        color.clear();
        //memset(d2,0,sizeof(d2));
        colorRe.clear();
        while(m--)
        {
            int x,y,c;
            cin>>x>>y>>c;
            //cout<<x<<" "<<y<<" "<<c<<endl;
            color[x][y].push_back(c);
            color[y][x].push_back(c);
        }
        //printcolor();
        bfs1();
        cout<<d[1]<<endl;
        //printd();
        bfs2();

        for(int i=0;i<colorRe.size()-1;++i)
        {
            cout<<colorRe[i]<<" ";
        }
        cout<<colorRe[colorRe.size()-1]<<endl;
    }
    return 0;
}

