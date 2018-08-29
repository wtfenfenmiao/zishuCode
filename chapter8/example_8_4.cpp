#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>

using namespace std;

int n;

struct Node
{
    int x;
    int y;
    int idx;
    int val;

}Ax[5005],Ay[5005];



bool cmp(Node n1,Node n2)
{
    //if(n1.y==n2.y)
    //{
    //    return n1.x>n2.x;
    //}
    return n1.y<n2.y;
}

bool cmp1(Node n1,Node n2)
{
    return n1.idx<n2.idx;
}

void printAx()
{
    cout<<"Ax:"<<endl;
    for(int i=0;i<n;++i)
    {
        printf("l:%d  r:%d   idx:%d   val:%d\n",Ax[i].x,Ax[i].y,Ax[i].idx,Ax[i].val);
    }
}


void printAy()
{
    cout<<"Ay:"<<endl;
    for(int i=0;i<n;++i)
    {
        printf("l:%d  r:%d   idx:%d   val:%d\n",Ay[i].x,Ay[i].y,Ay[i].idx,Ay[i].val);
    }
}

int main()
{
    //freopen("example_8_4_in.txt","r",stdin);
    while(cin>>n&&n!=0)
    {
        set<int> idxx;
        set<int> idxy;
        memset(Ax,0,sizeof(Ax));
        memset(Ay,0,sizeof(Ay));
        for(int i=0;i<n;++i)
        {
            Ax[i].idx=i;
            Ay[i].idx=i;
            scanf("%d %d %d %d",&Ax[i].x,&Ay[i].x,&Ax[i].y,&Ay[i].y);
        }
        sort(Ax,Ax+n,cmp);
        sort(Ay,Ay+n,cmp);
        //printAx();
        //printAy();
        bool flag=true;
        for(int i=0;i<n;++i)
        {
            int xval=Ax[i].x;
            while(xval<=Ax[i].y&&idxx.count(xval))
            {
                ++xval;
            }
            if(xval>Ax[i].y)
            {
                flag=false;
                break;
            }
            Ax[i].val=xval;
            idxx.insert(xval);

            int yval=Ay[i].x;
            while(yval<=Ay[i].y&&idxy.count(yval))
            {
                ++yval;
            }
            if(yval>Ay[i].y)
            {
                flag=false;
                break;
            }
            Ay[i].val=yval;
            idxy.insert(yval);
            //cout<<"there:"<<endl;
            //printAx();
            //printAy();
        }
        //printAx();
        //printAy();


        if(!flag)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        sort(Ax,Ax+n,cmp1);
        sort(Ay,Ay+n,cmp1);
        for(int i=0;i<n;++i)
        {
            cout<<Ax[i].val<<" "<<Ay[i].val<<endl;
        }
    }
    return 0;
}
