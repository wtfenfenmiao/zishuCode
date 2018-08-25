#include<iostream>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

void findfull(vector<int>& re,set<int>& se,int nthis,int total)
{
    if(nthis==0)
    {
        for(int i=0;i<re.size();++i)
        {
            cout<<re[i];
        }
        cout<<endl;
    }
    else
    {
        for(int i=1;i<=total;++i)
        {
            if(!se.count(i))
            {
                re.push_back(i);
                se.insert(i);
                findfull(re,se,nthis-1,total);
                re.pop_back();
                se.erase(i);
            }
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> re;
        set<int> se;
        findfull(re,se,n,n);
    }
    return 0;
}
