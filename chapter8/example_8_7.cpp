
#include<unordered_map>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    //freopen("example_8_7_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        int n;
        cin>>n;
        int i=0;
        int re=0;
        unordered_map<int,int> num_idx;
        for(int j=0;j<n;++j)
        {
            int num;
            cin>>num;
            if(!num_idx.count(num)||num_idx[num]<i)
            {
                re=max(re,j-i+1);
            }
            else
            {
                i=num_idx[num]+1;
            }
            num_idx[num]=j;
        }
        cout<<re<<endl;
    }
    return 0;
}

/*
//这个麻烦一点，但是核心思想还是双指针（滑动窗口）
#include<unordered_map>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<iostream>
using namespace std;
int main()
{
    //freopen("example_8_7_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        vector<int> nu;
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int num;
            cin>>num;
            nu.push_back(num);
        }
        int i=0;
        int j=0;
        int re=0;
        set<int> se;
        while(j<n)
        {
            if(!se.count(nu[j]))
            {
                se.insert(nu[j]);
                ++j;
                re=max(re,j-i);
            }
            else
            {
                se.erase(nu[i++]);
            }
        }
        cout<<re<<endl;
    }
    return 0;
}
*/
/*
//
#include<unordered_map>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<iostream>
using namespace std;
int main()
{
    //freopen("example_8_7_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        vector<int> last;
        unordered_map<int,int> ha;
        vector<int> nu;
        int n;
        cin>>n;

        for(int i=0;i<n;++i)
        {
            int num;
            cin>>num;
            nu.push_back(num);
            if(ha.count(num))
            {
                last.push_back(ha[num]);
            }
            else
            {
                last.push_back(-1);
            }
            ha[num]=i;
        }
        int i=0;
        int j=0;
        int re=0;
        for(j=0;j<n;++j)
        {
            if(last[j]>=i)
            {
                i=last[j]+1;
            }
            re=max(re,j-i+1);
        }
        cout<<re<<endl;
    }
    return 0;
}
*/
