//归并排序
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<sstream>

using namespace std;


bool fillin(vector<int>& vec)
{
    string str;
    if(!getline(cin,str)||str.size()==0)
        return false;
    cout<<"str:"<<str<<endl;
    vec.clear();
    stringstream ss(str);
    int num;
    while(ss>>num)
    {
        vec.push_back(num);
    }
    return true;
}


//有些时候，进步不是你30岁开始不信一些事，而是三十岁还能相信一些事，比如，我可以改变一些东西。晚安
void merge_sort(vector<int>& vec,int s,int e)
{
    cout<<"there:"<<endl;
    if(e-s<=1)
        return;
    int mid=s+(e-s)/2;
    merge_sort(vec,s,mid);
    merge_sort(vec,mid,e);
    vector<int> temp;
    int i=s;
    int j=mid;
    while(i<mid||j<e)
    {
        if(j>=e||(i<mid&&vec[i]<vec[j]))
            temp.push_back(vec[i++]);
        else
            temp.push_back(vec[j++]);
    }
    vec.erase(vec.begin()+s,vec.begin()+e);
    vec.insert(vec.begin()+s,temp.begin(),temp.end());     //用左闭右开的一个好处，和这个stl的begin和end是一致的
}


int main()
{
    freopen("tips_8_4_in.txt","r",stdin);
    vector<int> vec;
    while(fillin(vec))
    {
        merge_sort(vec,0,vec.size());
        for(int i=0;i<vec.size();++i)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
