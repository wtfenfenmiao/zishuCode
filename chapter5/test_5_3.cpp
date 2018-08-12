#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

int main()
{
    //freopen("test_5_3_in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        if(n==1)   //一张牌的时候
        {

            printf("Discarded cards:\nRemaining card: %d\n",1);
            continue;
        }
        queue<int> qu;
        for(int i=0;i<n;++i)
            qu.push(i+1);
        printf("Discarded cards:");
        while(qu.size()>2)
        {
            printf(" %d,",qu.front());
            qu.pop();
            qu.push(qu.front());
            qu.pop();
        }

        printf(" %d\n",qu.front());
        qu.pop();
        printf("Remaining card: %d\n",qu.front());
    }
}
