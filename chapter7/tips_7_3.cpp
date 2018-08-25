#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

void findSub(vector<int>& re,int n)
{
    int si=re.size();
    for(int i=0;i<si;++i)
    {
        cout<<re[i];
    }
    cout<<endl;
    for(int i=si?re[si-1]+1:1;i<=n;++i)
    {
        re.push_back(i);
        findSub(re,n);
        re.pop_back();
    }
}

void findSub1(vector<int>& re,int total,int n)
{
    if(total==n)
    {
        for(int i=0;i<n;++i)
            if(re[i]) cout<<i+1;
        cout<<endl;
    }
    else
    {
        re.push_back(1);
        findSub1(re,total+1,n);
        re.pop_back();
        re.push_back(0);
        findSub1(re,total+1,n);
        re.pop_back();
    }
}


void print(int thisnum,int n)
{
    for(int i=1;i<=n;++i)
    {
        if(thisnum&(1<<(i-1))) cout<<i;
    }
    cout<<endl;
}

void findSub2(int n)
{
    for(int i=1;i<(1<<n);++i)
    {
        print(i,n);
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> re;
        //findSub(re,n);   //增量构造法

        //findSub1(re,0,n);  //位向量法
        findSub2(n);
    }
    return 0;
}
