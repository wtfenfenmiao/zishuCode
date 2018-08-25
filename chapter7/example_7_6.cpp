#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

using namespace std;

map<char,vector<char> > lin;
map<char,int> al_idx;

void findre(vector<char>& refinal,vector<char>& re,int& maxwid,int& thiswid,int cur)
{
    if(cur==al_idx.size())
    {
        //for(int i=0;i<re.size();++i)
        //{
        //    cout<<re[i];
        //}
        //cout<<endl;
        //cout<<thiswid<<endl;
        if(thiswid<maxwid)
        {
            refinal=re;
            maxwid=thiswid;
        }
    }
    else
    {
        for(map<char,int>::iterator it=al_idx.begin();it!=al_idx.end();++it)
        {
            if(it->second==-1)
            {
                if(lin[it->second].size()>=maxwid)   //剪枝
                    continue;
                bool flag=true;
                int thiswidtemp=thiswid;
                for(int i=0;i<lin[it->first].size();++i)
                {
                    char temp=lin[it->first][i];
                    //cout<<it->first<<":"<<temp<<endl;
                    if(al_idx[temp]!=-1)
                    {
                        int thisw=cur-al_idx[temp];
                        if(thisw>thiswid)
                            thiswid=thisw;
                        if(thiswid>=maxwid)
                        {
                            flag=false;
                            break;
                        }
                    }
                }
                if(!flag)
                    continue;
                it->second=cur;
                re.push_back(it->first);
                //cout<<"this:"<<endl;
                //for(int i=0;i<re.size();++i)
                //    cout<<re[i];
                //cout<<endl;
                //cout<<thiswid<<endl;
                findre(refinal,re,maxwid,thiswid,cur+1);
                thiswid=thiswidtemp;
                it->second=-1;
                re.pop_back();
            }
        }
    }
}


void printlin()
{
    for(map<char,vector<char> >::iterator it=lin.begin();it!=lin.end();++it)
    {
        cout<<it->first<<":";
        for(int i=0;i<it->second.size();++i)
        {
            cout<<it->second[i];
        }
        cout<<endl;
    }
}

void printidx()
{
    for(map<char,int>::iterator it=al_idx.begin();it!=al_idx.end();++it)
    {
        cout<<it->first<<":"<<it->second<<endl;
    }
}
int main()
{
   // freopen("example_7_6_in.txt","r",stdin);
    string str;
    while(cin>>str&&str[0]!='#')
    {
        lin.clear();
        al_idx.clear();
        char thisalpha;
        for(int i=0;i<str.size();++i)
        {
            if(i!=str.size()-1&&str[i+1]==':')
            {
                al_idx[str[i]]=-1;
                thisalpha=str[i];
            }
            else if(isalpha(str[i]))
            {
                al_idx[str[i]]=-1;
                lin[thisalpha].push_back(str[i]);
                lin[str[i]].push_back(thisalpha);      //别忘了两头加！
            }
        }
        //printlin();
        //printidx();
        int maxwid=al_idx.size();
        //cout<<"max:"<<maxwid<<endl;
        int thiswid=0;
        vector<char> re;
        vector<char> refinal;
        findre(refinal,re,maxwid,thiswid,0);
        for(int i=0;i<refinal.size();++i)
        {
            cout<<refinal[i]<<" ";
        }
        cout<<"-> "<<maxwid<<endl;
    }
    return 0;
}
