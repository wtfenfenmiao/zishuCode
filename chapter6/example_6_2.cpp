/*
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;




int main()
{
    //freopen("example_6_2_in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {


        queue<int> in;
        for(int i=0;i<n;++i)
        {
            in.push(i+1);
        }
        while(1)
        {
            int num;
            scanf("%d",&num);
            if(num==0)
                break;
            queue<int> in_temp=in;
            stack<int> mid;
            queue<int> out;
            out.push(num);
            for(int i=1;i<n;++i)
            {
                scanf("%d",&num);
                out.push(num);
            }
            while(!out.empty())
            {
                if(!in_temp.empty()&&out.front()==in_temp.front())
                {
                    in_temp.pop();
                    out.pop();
                }
                else if(!in_temp.empty()&&out.front()>in_temp.front())
                {
                    mid.push(in_temp.front());
                    in_temp.pop();
                }
                else
                {
                    if(out.front()!=mid.top())
                    break;
                    out.pop();
                    mid.pop();
                }
            }
            if(out.empty())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}

*/

#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;
const int maxn=1010;
int out[maxn];

int main()
{
    //freopen("example_6_2_in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        while(1)
        {
            memset(out,0,sizeof(out));
            int num;
        scanf("%d",&out[0]);
        if(out[0]==0)
            break;
        for(int i=1;i<n;++i)
        {
            scanf("%d",&out[i]);
        }
        stack<int> mid;
        int A=1;
        int B=0;
        while(B<n)
        {
            if(out[B]==A) {++B;++A;}
            else if(!mid.empty()&&out[B]==mid.top()) {++B;mid.pop();}
            else if(A<=n) mid.push(A++);
            else break;
        }
        printf(B==n?"Yes":"No");
        printf("\n");
        }
        printf("\n");
    }
    return 0;
}

