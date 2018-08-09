#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define maxn 30
vector<int> save[maxn];
int n;

void findplace(int num,int &p,int &h)
{
    for(p=0;p<n;++p)
    {
        for(h=0;h<save[p].size();++h)
        {
            if(save[p][h]==num)
                return;
        }
    }
}

void re(int p,int h)
{
    for(int i=h+1;i<save[p].size();++i)
    {
        int temp=save[p][i];
        save[temp].push_back(temp);
    }
    save[p].resize(h+1);
}

void moveon(int p1,int h1,int p2)
{
    for(int i=h1;i<save[p1].size();++i)
    {
        save[p2].push_back(save[p1][i]);
    }
    save[p1].resize(h1);
}

void pri()
{
    for(int i=0;i<n;++i)
    {
        printf("%d:",i);
        for(int j=0;j<save[i].size();++j)
        {
            printf(" %d",save[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //freopen("example_5_2_in.txt","r",stdin);
    cin>>n;
    string s1,s2;
    int n1,n2;
    for(int i=0;i<n;++i)
    {
        save[i].push_back(i);
    }
    while(cin>>s1>>n1>>s2>>n2)
    {
        int p1,p2,h1,h2;
        findplace(n1,p1,h1);
        findplace(n2,p2,h2);
        if(p1==p2)
            continue;
        if(s1=="move")  re(p1,h1);
        if(s2=="onto")  re(p2,h2);
        moveon(p1,h1,p2);
    }
    pri();
    return 0;
}
