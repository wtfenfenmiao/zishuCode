#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=100000;
int xv[maxn];
int yv[maxn];


int main()
{
    int n;
    while(cin>>n)
    {
        int cnt=0;

        for(int y=n+1;y<=2*n;++y)
        {
            if(n*y%(y-n)==0)
            {
                int x=(n*y)/(y-n);
                xv[cnt]=x;
                yv[cnt]=y;
                ++cnt;
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;++i)
        {
            printf("1/%d = 1/%d + 1/%d\n",n,xv[i],yv[i]);
        }
    }
    return 0;
}
