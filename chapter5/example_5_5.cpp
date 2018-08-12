/*
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include<iostream>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
typedef set<int> Set;
vector<Set> Setcache;
map<Set,int> IDcache;

int ID(Set x)
{
    if(IDcache.count(x))   return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;
}


int main()
{

    //freopen("example_5_5_in.txt","r",stdin);
    int kase;
    cin>>kase;
    //cout<<"kase:"<<kase<<endl;
    while(kase--)
    {
        stack<int> st;
        int n;
        cin>>n;
        //cout<<"n:"<<n<<endl;
        while(n--)
        {
            string command;
            cin>>command;
            //cout<<"command:"<<command<<endl;

            if(command[0]=='P') st.push(ID(Set()));

            else if(command[0]=='D')
            {

                st.push(st.top());
            }
            else
            {
                Set set1=Setcache[st.top()];
                st.pop();
                Set set2=Setcache[st.top()];
                st.pop();
                Set x;
                if(command[0]=='U') set_union(ALL(set1),ALL(set2),INS(x));
                if(command[0]=='I') set_intersection(ALL(set1),ALL(set2),INS(x));
                if(command[0]=='A') {x=set2; x.insert(ID(set1));}
                st.push(ID(x));
            }
            cout<<Setcache[st.top()].size()<<endl;
        }
        cout<<"***"<<endl;

    }

}
*/

#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;


int ID(Set x)
{
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;
}


int main()
{
    //freopen("example_5_5_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        stack<int> st;
        int n;
        cin>>n;
        while(n--)
        {
            string command;
            cin>>command;
            if(command[0]=='P') st.push(ID(Set()));
            else if(command[0]=='D') st.push(st.top());
            else
            {
                Set x;
                Set set1=Setcache[st.top()]; st.pop();
                Set set2=Setcache[st.top()]; st.pop();
                if(command[0]=='U') set_union(ALL(set1),ALL(set2),INS(x));
                if(command[0]=='I') set_intersection(ALL(set1),ALL(set2),INS(x));
                if(command[0]=='A') {x=set2;x.insert(ID(set1));}
                st.push(ID(x));
            }
            cout<<Setcache[st.top()].size()<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}




















