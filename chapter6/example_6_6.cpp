
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const long long maxn=(1<<20);

bool door[maxn];

int findpos(int pos)
{
    if(door[pos])
        return pos*2+1;
    else
        return pos*2;
}


int main()
{
    //freopen("example_6_6_in.txt","r",stdin);
    int D,n;
    while(scanf("%d %d",&D,&n)!=EOF)
    {
        //cout<<D<<" "<<n<<endl;
        memset(door,0,sizeof(door));
        int out;
        while(n--)
        {
            //cout<<"*************************************"<<endl;
            //cout<<(1<<(D-1))<<endl;
            out=1;
            while(out<(1<<(D-1)))
            {
                //cout<<"out:"<<out<<endl;
                int temp=out;
                out=findpos(temp);
                door[temp]=!door[temp];
            }
        }
        printf("%d\n",out);


    }
    return 0;
}




//一个意思的另一种写法

#include<cstdio>
#include<cstring>

const int maxn=20;
bool door[1<<20];

int main()
{
    freopen("example_6_6_in.txt","r",stdin);
    int D,n;
    while(scanf("%d %d",&D,&n)!=EOF)
    {
        memset(door,0,sizeof(door));
        int total=(1<<D)-1;
        int out;
        while(n--)
        {
            out=1;
            while(1)
            {
                door[out]=!door[out];
                out=door[out]?out*2:out*2+1;
                if(out>total)
                    break;
            }
        }
        printf("%d\n",out/2);
    }
    return 0;
}



//分析的,省去了大数组。大数组很要命
#include<cstdio>

using namespace std;


int main()
{
    //freopen("example_6_6_in.txt","r",stdin);
    int D,n;
    while(scanf("%d %d",&D,&n)!=EOF)
    {
        int out=1;
        for(int i=0;i<D-1;++i)
        {
            if(n%2==0)
            {
                out=out*2+1;
                n/=2;
            }
            else
            {
                out*=2;
                n=n/2+1;
            }
        }
        printf("%d\n",out);
    }
}

