#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<string>
#include<utility>
#include<map>

using namespace std;

int findmod(int anum,string b,int repeat)
{
    if(anum==0)
        return 0;
    if(b=="0"||b=="")
        return 1%repeat;
    string br="0";
    int ban=0;
    for(int i=0;i<b.size();++i)
    {
        ban=ban*10+b[i]-'0';
        br+=ban/2+'0';
        ban=ban%2;
    }
    int start=0;
    while(start<br.size()&&br[start]=='0') ++start;
    br=br.substr(start);
    int ans=findmod(anum,br,repeat);
    ans=(ans*ans)%repeat;
    if(ban==1) ans=(ans*anum)%repeat;
    return ans;
}


void printvec(vector<int>& vec)
{
    for(int i=0;i<vec.size();++i)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    cout<<"finish"<<endl;
}

int main()
{
    //freopen("example_10_1_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        string a;
        string b;
        int n;
        cin>>a>>b>>n;
        //cout<<"there:"<<a<<" "<<b<<" "<<n<<endl;
        vector<int> vec;
        map<pair<int,int>,int> ma;
        int repeat=0;
        pair<int,int> pa;
        pa.first=0%n;
        pa.second=1%n;
        vec.push_back(pa.first);
        while(!ma.count(pa))
        {
            vec.push_back(pa.second);
            ma[pa]=repeat++;
            int temp=(pa.first+pa.second)%n;
            pa.first=pa.second;
            pa.second=temp;
        }
        int repeatstart=ma[pa];
        //cout<<"repeatstart:"<<repeatstart<<endl;
        vec.pop_back();
        //cout<<"size:"<<vec.size()<<endl;
        //printvec(vec);
        //cout<<"oldrepeat:"<<repeat<<endl;
        repeat=repeat-repeatstart;
        //cout<<"repeat:"<<repeat<<endl;
        //
        int anum=0;
        for(int i=0;i<a.size();++i)
        {
            anum=(anum*10+a[i]-'0')%repeat;
        }
        //cout<<"anum:"<<anum<<endl;
        int idx=findmod(anum,b,repeat);
        //cout<<"idx:"<<idx<<endl;
        cout<<vec[(idx-repeatstart+repeat)%repeat]<<endl;
    }
    return 0;
}
