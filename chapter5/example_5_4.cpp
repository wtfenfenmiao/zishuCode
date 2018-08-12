/*
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

int main()
{
    //freopen("example_5_4_in.txt","r",stdin);
    unordered_map<string,vector<string>> wordmap;
    unordered_map<string,vector<string>>::iterator it;
    set<string> re;
    set<string>::iterator it2;
    string str;
    while(cin>>str)
    {
        if(str=="#")
            break;
        string temp=str;
        transform(str.begin(),str.end(),str.begin(),::tolower);
        sort(str.begin(),str.end());
        wordmap[str].push_back(temp);
    }

    for(it=wordmap.begin();it!=wordmap.end();++it)
    {
        vector<string> temp=it->second;
        if(temp.size()==1)
        {
            re.insert(temp[0]);
        }
    }
    it2=re.begin();
    while(it2!=re.end())
    {
        cout<<*it2++<<endl;
    }
    return 0;
}
*/




#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    //freopen("example_5_4_in.txt","r",stdin);
    string str;
    unordered_map<string,int> wordmap;
    vector<string> save;
    vector<string> re;
    while(cin>>str)
    {
        if(str=="#")
            break;
        save.push_back(str);
        transform(str.begin(),str.end(),str.begin(),::tolower);
        sort(str.begin(),str.end());
        if(!wordmap.count(str))
            wordmap[str]=1;
        else
            ++wordmap[str];
    }
    for(int i=0;i<save.size();++i)
    {
        string temp=save[i];
        transform(temp.begin(),temp.end(),temp.begin(),::tolower);
        sort(temp.begin(),temp.end());
        if(wordmap[temp]==1)
            re.push_back(save[i]);
    }
    sort(re.begin(),re.end());
    for(int i=0;i<re.size();++i)
        cout<<re[i]<<endl;
    return 0;
}
