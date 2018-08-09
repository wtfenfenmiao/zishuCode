/*
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 10005

int main()
{
    //freopen("example_5_1_in.txt","r",stdin);
    int N,Q;
    int kase=0;
    while(scanf("%d %d",&N,&Q)!=EOF && N!=0)
    {
        cout<<"CASE# "<<++kase<<":"<<endl;
        vector<int> num;
        for(int i=0;i<N;++i)
        {
            int thisnum;
            scanf("%d",&thisnum);
            num.push_back(thisnum);
        }
        sort(num.begin(),num.end());
        for(int i=0;i<Q;++i)
        {
            int tofind;
            scanf("%d",&tofind);
            if(find(num.begin(),num.end(),tofind)!=num.end())
            {
                cout<<tofind<<" found at "<<find(num.begin(),num.end(),tofind)-num.begin()+1<<endl;
            }
            else
            {
                cout<<tofind<<" not found"<<endl;
            }
        }
    }
    return 0;
}
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 100005
using namespace std;
int num[maxn];

int main()
{
    //freopen("example_5_1_in.txt","r",stdin);
    int N,Q;
    int kase=0;
    while(scanf("%d %d",&N,&Q)==2&&N!=0)
    {
        printf("CASE# %d:\n",++kase);
        for(int i=0;i<N;++i)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+N);
        while(Q--)
        {
            int tofind;
            scanf("%d",&tofind);
            int fi=lower_bound(num,num+N,tofind)-num;
            if(num[fi]==tofind)
                printf("%d found at %d\n",tofind,fi+1);
            else
                printf("%d not found\n",tofind);
        }
    }
    return 0;
}




