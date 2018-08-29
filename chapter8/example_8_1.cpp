#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>

using namespace std;

void fip(vector<int>& pan,int bottom)
{
    int idx=0;
    int mx=pan[0];
    for(int i=1;i<=bottom;++i)
    {
        if(pan[i]>mx)
        {
            idx=i;
            mx=pan[i];
        }
    }
    if(idx==bottom)
        return;
    if(idx!=0)
        cout<<pan.size()-idx<<" ";
    cout<<pan.size()-bottom<<" ";
    vector<int> temp;
    temp.assign(pan.begin()+idx+1,pan.begin()+bottom+1);
    pan.erase(pan.begin()+idx+1,pan.begin()+bottom+1);
    reverse(temp.begin(),temp.end());
    pan.insert(pan.begin(),temp.begin(),temp.end());
}


int main()
{
    //freopen("example_8_1_in.txt","r",stdin);
    string str;
    while(getline(cin,str)&&str.size()!=0)
    {
        vector<int> pan;
        cout<<str<<endl;
        int num;
        stringstream ss(str);
        while(ss>>num)
        {
            pan.push_back(num);
        }
        for(int i=pan.size()-1;i>=0;--i)
            fip(pan,i);
        cout<<0<<endl;
    }
    return 0;
}
