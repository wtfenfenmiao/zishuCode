//思路就是俩队列，一个普通一个优先。注意index的变化，之前死在了index上

#include<queue>
#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    //freopen("test_5_7_in.txt","r",stdin);
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
                q.pop();
                pq.pop();
                --index;
            }
            else
            {
                if(index==0)
                {
                   index=q.size()-1;
                }
                else
                    --index;
                q.push(q.front());
                q.pop();

            }
        }
    }
    return 0;
}
