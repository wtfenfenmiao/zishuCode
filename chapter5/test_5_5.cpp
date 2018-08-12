/*合成词，超时
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    freopen("test_5_5_in.txt","r",stdin);
    vector<string> save;
    vector<string> re;
    string str;
    while(cin>>str)
    {
        save.push_back(str);
    }
    for(int i=0;i<save.size();++i)
    {
        for(int j=i+1;j<save.size();++j)
        {
            string temp1=save[i]+save[j];
            string temp2=save[j]+save[i];
            if(count(save.begin(),save.end(),temp1))
                re.push_back(temp1);
            if(count(save.begin(),save.end(),temp2))
                re.push_back(temp2);
        }
    }
    sort(re.begin(),re.end());
    for(int i=0;i<re.size();++i)
    {
        cout<<re[i]<<endl;
    }
    return 0;
}
*/


/*
//拆分词，可以
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    //freopen("test_5_5_in.txt","r",stdin);
    vector<string> vecstr;
    map<string,int> mapstr;
    string str;
    while(cin>>str)
    {
        vecstr.push_back(str);
        mapstr[str]=1;
    }
    for(int i=0;i<vecstr.size();++i)
    {
        //cout<<vecstr[i]<<endl;
        for(int j=1;j<vecstr[i].size();++j)
        {
            //cout<<vecstr[i].substr(0,j)<<" "<<vecstr[i].substr(j)<<endl;
            if(mapstr.count(vecstr[i].substr(0,j))&&mapstr.count(vecstr[i].substr(j)))
            {
                cout<<vecstr[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
*/

#include<cstdio>
#include<set>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    //freopen("test_5_5_in.txt","r",stdin);
    string str;
    vector<string> save;
    set<string> st;
    while(cin>>str)
    {
        save.push_back(str);
        st.insert(str);
    }
    for(int i=0;i<save.size();++i)
    {
        for(int j=1;j<save[i].size();++j)
        {
            if(st.count(save[i].substr(0,j))&&st.count(save[i].substr(j)))
            {
                cout<<save[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
