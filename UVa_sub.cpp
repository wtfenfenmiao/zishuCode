#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

int main()
{
    //freopen("UVa_sub_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        int n,index;
        queue<int> q;
        priority_queue<int> pq;
        cin>>n>>index;
        for(int i=0;i<n;++i)
        {
            int temp;
            cin>>temp;
            q.push(temp);
            pq.push(temp);
        }

        while(1)
        {
            if(q.front()==pq.top())
            {
                if(index==0)
                {
                    cout<<n-q.size()+1<<endl;
                    break;
                }
                --index;
                q.pop();
                pq.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
                if(index==0)
                    index=q.size()-1;
                else
                    --index;
            }
        }
    }
    return 0;
}
