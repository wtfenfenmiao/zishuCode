#include<cstdio>
#include<iostream>
#include<stack>
#include<map>
using namespace std;

map<char,char> fin={{'(',')'},{'[',']'},{'{','}'}};

int main()
{
    //freopen("test_6_1_in.txt","r",stdin);
    //freopen("test_6_1_out.txt","w",stdout);
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        stack<char> st;
        string s;
        //cin>>s;
        getline(cin,s);    //坑在了空字符上。之前用的cin，空字符直接跳过了
        //cout<<s<<endl;
        int i;
        for(i=0;i<s.size();++i)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    break;
                char left=fin[st.top()];
                st.pop();
                if(left!=s[i])
                    break;
            }
        }
        if(i==s.size()&&st.empty())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
