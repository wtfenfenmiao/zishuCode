#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100000;
int mr[1000][2];
int nr[1000][2];
int result[maxn];
int n,m;

void printm()
{
    cout<<"m:"<<endl;
    for(int i=0;i<1000;++i)
    {
        if(mr[i][0]==0)
            break;
        cout<<mr[i][0]<<" "<<mr[i][1]<<endl;
    }
}

void printn()
{
    cout<<"n:"<<endl;
    for(int i=0;i<1000;++i)
    {
        if(mr[i][0]==0)
            break;
        cout<<mr[i][0]<<" "<<nr[i][1]<<endl;
    }
}

void resolvem()
{
    int start=0;
    for(int i=2;i*i<=m;++i)
    {
        if(m%i==0)
        {
            mr[start][0]=i;
            mr[start][1]=1;
            m/=i;
            while(m%i==0)
            {
                ++mr[start][1];
                m/=i;
            }
            ++start;
        }
    }
    if(m>1)
    {
        mr[start][0]=m;
        mr[start][1]=1;
    }
}


bool resolve(int top,int bottom)
{
    bool re=true;
    for(int i=0;i<1000;++i)
    {
        if(mr[i][0]==0)
            break;
        while(top%mr[i][0]==0)
        {
            ++nr[i][1];
            top/=mr[i][0];
        }
        while(bottom%mr[i][0]==0)
        {
            --nr[i][1];
            bottom/=mr[i][0];
        }
        if(nr[i][1]<mr[i][1])
            re=false;
    }
    return re;


}

int main()
{
    //freopen("example_10_6.txt","r",stdin);
    //freopen("example_10_6_out.txt","w",stdout);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(result,0,sizeof(result));
        memset(mr,0,sizeof(mr));
        memset(nr,0,sizeof(nr));
        resolvem();
        //printm();
        int cnt=0;
        for(int i=1;i<n-1;++i)
        {
            bool flag=resolve(n-i,i);
            //printn();
            if(flag)
                result[cnt++]=i+1;
        }

        {
            cout<<cnt<<endl;
            for(int i=0;i<cnt;++i)
            {
                cout<<(i==0?"":" ")<<result[i];
            }
            cout<<endl;
        }

    }
}
