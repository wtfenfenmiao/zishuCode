#include<iostream>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

const int maxn=105;
int place[maxn];
int nplace;
int order;

struct moveway   //一种运转模式一个struct.
{
    map<int,int> in;
    map<int,int> out;
};

struct moveway* M[maxn];    //结构体数组

bool findresult()
{
    for(int i=0;i<order;++i)
    {
        bool flag=false;
        for(map<int,int>::iterator it=(M[i]->out).begin();it!=(M[i]->out).end();++it)
        {
            int p=it->first;
            int pnum=it->second;
            if(place[p]<pnum)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            continue;
        for(map<int,int>::iterator it=(M[i]->out).begin();it!=(M[i]->out).end();++it)
        {
            int p=it->first;
            int pnum=it->second;
            place[p]-=pnum;
        }
        for(map<int,int>::iterator it=(M[i]->in).begin();it!=(M[i]->in).end();++it)
        {
            int p=it->first;
            int pnum=it->second;
            place[p]+=pnum;
        }
        return true;

    }
    return false;
}

void dele(int orde)
{
    for(int i=0;i<orde;++i)
    {
        delete(M[i]);
    }
}


int main()
{
    freopen("test_6_7_in.txt","r",stdin);
    int kase=0;

    while(cin>>nplace&&nplace!=0)
    {
        //cout<<nplace<<endl;
        memset(place,0,sizeof(place));
        for(int i=1;i<=nplace;++i)
        {
            scanf("%d",&place[i]);
            //cout<<place[i]<<" ";
        }
        //cout<<endl;

        cin>>order;
        for(int i=0;i<order;++i)
        {
            moveway* t=new(moveway);
            int num;
            while(cin>>num&&num!=0)
            {
                //cout<<num<<" ";
                if(num<0)
                    ++(t->out)[-num];
                else
                    ++(t->in)[num];
            }
            //cout<<endl;
            M[i]=t;
        }
        int testnum;
        cin>>testnum;
        //cout<<testnum<<endl;
        int temp=testnum;
        while(temp)
        {
            if(!findresult())
                break;
            --temp;
        }
        if(temp==0)
            printf("Case %d: still live after %d transitions\n",++kase,testnum);
        else
            printf("Case %d: dead after %d transitions\n",++kase,testnum-temp);
        cout<<"Places with tokens:";
        for(int i=1;i<=nplace;++i)
        {
            if(place[i])
                printf(" %d (%d)",i,place[i]);
        }
        printf("\n\n");
        dele(order);

    }
    return 0;
}


