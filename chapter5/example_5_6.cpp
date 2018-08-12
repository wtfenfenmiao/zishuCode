#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<iostream>

#define maxn 1005

using namespace std;

int main()
{
    //freopen("example_5_6_in.txt","r",stdin);
    int team;
    int kase=0;
    while(scanf("%d",&team)!=EOF&&team!=0)
    {
        printf("Scenario #%d\n",++kase);
        map<int,int> member_team;
        queue<int> q,qu[maxn];
        while(team--)
        {
            int n;
            scanf("%d",&n);
            while(n--)
            {
                int member;
                scanf("%d",&member);
                member_team[member]=team;
            }
        }
        string command;

        while(cin>>command)
        {
            if(command[0]=='S')
                break;
            if(command[0]=='E')
            {
                int member;
                cin>>member;
                if(qu[member_team[member]].empty())
                    q.push(member_team[member]);
                qu[member_team[member]].push(member);
            }
            if(command[0]=='D')
            {
                int outmember=qu[q.front()].front();
                qu[q.front()].pop();
                if(qu[q.front()].empty())
                {
                    q.pop();
                }
                printf("%d\n",outmember);
            }
        }
        printf("\n");




    }
    return 0;
}
