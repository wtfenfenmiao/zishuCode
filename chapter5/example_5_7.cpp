/*
//优先队列
#include<cstdio>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
int buff[3]={2,3,5};

int main()
{
    set<LL> se;
    priority_queue<LL,vector<LL>,greater<LL>> pq;
    se.insert(1);
    pq.push(1);
    int cnt=1;
    while(cnt<1500)
    {
        LL k=pq.top();
        pq.pop();
        for(int i=0;i<3;++i)
        {
            LL thisnum=k*buff[i];
            if(!se.count(thisnum))
            {
                se.insert(thisnum);
                pq.push(thisnum);
            }
        }
        ++cnt;
    }
    printf("The 1500'th ugly number is %d.\n",pq.top());
}
*/

#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

int main()
{
    LL re[1500];
    re[0]=1;
    int n2=0;
    int n3=0;
    int n5=0;
    int cnt=1;
    while(cnt<1500)
    {
        LL thisnum=min(min(2*re[n2],3*re[n3]),5*re[n5]);
        if(thisnum==2*re[n2]) ++n2;
        if(thisnum==3*re[n3]) ++n3;
        if(thisnum==5*re[n5]) ++n5;
        re[cnt++]=thisnum;
    }
    printf("The 1500'th ugly number is %d.\n",re[1499]);
}
