#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

bool isdifficult(vector<char>& re)
{
    for(int i=1;i<=re.size()/2;++i)
    {
        int s2=re.size()-i;
        int s1=s2-i;
        int j;
        for(j=0;j<i;++j)
        {
            if(re[s1+j]!=re[s2+j])
                break;
        }
        if(j==i)
            return false;
    }
    return true;
}

void findse(vector<char>& re,int& cur,int k,int n)
{
    if(cur==k)
    {
        int cnt=0;
        for(int i=0;i<re.size();++i)
        {
            if(i!=0&&i%4==0)
            {
                ++cnt;
                if(cnt%16==0)
                    cout<<endl;
                else
                    cout<<" ";
            }
            cout<<re[i];
        }
        cout<<endl;
        cout<<re.size()<<endl;
    }
    else if(cur>k)
        return;
    else
    {
        for(int i=0;i<n;++i)
        {
            re.push_back('A'+i);
            if(isdifficult(re))
            {
                cur+=1;
                findse(re,cur,k,n);
            }
            re.pop_back();
        }
    }
}



int main()
{
    int k,n;
    while(cin>>k>>n&&k!=0)
    {
        vector<char> re;
        int cur=0;
        findse(re,cur,k,n);
    }
    return 0;
}
