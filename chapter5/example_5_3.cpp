/*
#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;
#define maxn 5005;

void dealwith(string &st,set<string>& se)
{
    int start=0;
    while(start<st.size()&&!isalpha(st[start])) ++start;
    int en=start;
    while(en<st.size()&&isalpha(st[en]))
    {
        st[en]=tolower(st[en]);
        ++en;
    }
    //cout<<st.substr(start,en-start)<<endl;
    se.insert(st.substr(start,en-start));

}

void pri(set<string>& se)
{
    set<string>::iterator it=se.begin();
    while(it!=se.end())
    {
        cout<<*it++<<endl;

    }
}
int main()
{
    //freopen("example_5_3_in.txt","r",stdin);
    set<string> se;
    string st;
    while(cin>>st)
    {
        dealwith(st,se);
    }
    pri(se);
    return 0;


}
*/

#include<cstdio>
#include<set>
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    //freopen("example_5_3_in.txt","r",stdin);
    string str,buff;
    set<string> re;
    set<string>::iterator it;
    while(cin>>str)
    {
        for(int i=0;i<str.size();++i)
        {
            if(isalpha(str[i]))
                str[i]=tolower(str[i]);
            else
                str[i]=' ';
        }
        stringstream ss(str);
        while(ss>>buff)
            re.insert(buff);
    }
    it=re.begin();
    while(it!=re.end())
        cout<<*it++<<endl;
}


