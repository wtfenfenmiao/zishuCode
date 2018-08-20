//这个部分不太清楚它到底想干啥，就把想到的都写了
/*
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;


void findFullDup(vector<int>& re,int total,int n)
{
    if(total==0)
    {
        for(int i=0;i<re.size();++i)
        {
            cout<<re[i];
        }
        cout<<endl;
    }
    else
    {
       for(int i=1;i<=n;++i)
        {
            re.push_back(i);
            findFullDup(re,total-1,n);
            re.pop_back();
        }
    }

}


int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> re;
        findFullDup(re,n,n);
    }
    return 0;
}
*/
/*
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<sstream>

using namespace std;


void findFull(vector<int>& re,map<int,int>& num_freq,int cnt)
{
    if(re.size()==cnt)
    {
        for(int i=0;i<cnt;++i)
        {
            cout<<re[i];
        }
        cout<<endl;
    }
    else
    {
        for(map<int,int>::iterator it=num_freq.begin();it!=num_freq.end();++it)
        {
            if(it->second!=0)
            {
                re.push_back(it->first);
                it->second-=1;
                findFull(re,num_freq,cnt);
                it->second+=1;
                re.pop_back();
            }
        }
    }
}

int main()
{
    freopen("tips_7_2_in.txt","r",stdin);
    string str;
    while(getline(cin,str))
    {
        map<int,int> num_freq;
        stringstream ss(str);
        int num;
        int cnt=0;
        while(ss>>num)
        {
            ++cnt;
            ++num_freq[num];
        }
        vector<int> re;
        findFull(re,num_freq,cnt);
    }
}
*/


#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main()
{
    freopen("tips_7_2_in.txt","r",stdin);
    string str;
    while(getline(cin,str))
    {
        stringstream ss(str);
        vector<int> q;
        int num;
        while(ss>>num)
        {
            q.push_back(num);
        }
        sort(q.begin(),q.end());
        do
        {
            for(int i=0;i<q.size();++i)
                cout<<q[i];
            cout<<endl;
        }while(next_permutation(q.begin(),q.end()));
    }
    return 0;
}
