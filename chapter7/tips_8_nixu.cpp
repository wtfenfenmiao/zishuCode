#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<vector>
using namespace std;



bool fillin(vector<int>& vec)
{
    vec.clear();
    string str;
    getline(cin,str);
    stringstream ss(str);
    int num;
    while(ss>>num)
    {
        vec.push_back(num);
    }
    cout<<"si:"<<vec.size()<<endl;
    return vec.size();
}

int findreverse(vector<int>& vec,int s,int e)
{
    if(e-s<=1)
        return 0;
    int mid=s+(e-s)/2;
    int l=findreverse(vec,s,mid);
    int r=findreverse(vec,mid,e);
    int re=l+r;
    int i=s;
    int j=mid;
    vector<int> temp;
    while(i<mid||j<e)
    {
        if(j>=e||(i<mid&&vec[i]<=vec[j]))
            temp.push_back(vec[i++]);
        else
        {
            re+=(mid-i);
            temp.push_back(vec[j++]);
        }
    }
    vec.erase(vec.begin()+s,vec.begin()+e);
    vec.insert(vec.begin()+s,temp.begin(),temp.end());
    return re;
}

int main()
{
    freopen("tips_8_4_in.txt","r",stdin);
    vector<int> vec;
    while(fillin(vec))
    {
        cout<<findreverse(vec,0,vec.size())<<endl;
    }
    return 0;
}
