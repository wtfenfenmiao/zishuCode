#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=100010;
int left[maxn];
int right[maxn];


void link(int a,int b)
{
    right[a]=b;
    left[b]=a;
}

int main()
{
    //freopen("example_6_5_in.txt","r",stdin);
    int n,m;
    int kase=0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        for(int i=1;i<=n;++i)
        {
            left[i]=i-1;
            right[i]=(i+1)%(n+1);
        }
        left[0]=n;right[0]=1;
        bool inv=false;
        while(m--)
        {
            int order;
            int x,y;
            scanf("%d",&order);
            if(order==4) inv=!inv;
            else
            {
                scanf("%d %d",&x,&y);
                if(inv&&order!=3) order=3-order;
                if(order==1&&right[x]==y) continue;
                if(order==2&&right[y]==x) continue;
            }
            int lx=left[x];
            int ly=left[y];
            int rx=right[x];
            int ry=right[y];

            if(order==1)
            {
                link(lx,rx);link(ly,x);link(x,y);
            }
            else if(order==2)
            {
                link(lx,rx);link(y,x);link(x,ry);
            }
            else if(order==3)
            {
                if(right[x]==y)
                {
                    link(lx,y);link(y,x);link(x,ry);
                }
                else if(right[y]==x)
                {
                    link(ly,x);link(x,y);link(y,rx);
                }
                else
                {
                    link(lx,y);link(y,rx);link(ly,x);link(x,ry);
                }
            }

        }

        long long sum=0;
        int b=0;
        for(int i=0;i<n;++i)
        {
            b=right[b];
            if(i%2==0) sum+=b;
        }
        if(inv && n%2==0) sum=(long long)n*(n+1)/2-sum;
        printf("Case %d: %lld\n",++kase,sum);
    }
    return 0;
}
