//�鲢����
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


//��Щʱ�򣬽���������30�꿪ʼ����һЩ�£�������ʮ�껹������һЩ�£����磬�ҿ��Ըı�һЩ��������
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
    vec.insert(vec.begin()+s,temp.begin(),temp.end());     //������ҿ���һ���ô��������stl��begin��end��һ�µ�
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
