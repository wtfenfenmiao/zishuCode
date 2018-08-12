#include<cstdio>
#include<vector>
#include<set>
#include<cmath>
#include<iostream>
using namespace std;


void compuThisnum(vector<int> pre,vector<int>& vec)
{
    int i=0;
    for(i=0;i<pre.size()-1;++i)
    {
        vec.push_back(abs(pre[i+1]-pre[i]));
        //cout<<vec[i]<<" ";
    }
    //cout<<endl;
    vec.push_back(abs(pre[0]-pre[i]));
}

void print(vector<int> vec)
{
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<" ";
    cout<<endl;
}

bool iszero(vector<int> vec)
{
    for(int i=0;i<vec.size();++i)
    {
        if(vec[i]!=0)
            return false;
    }
    return true;
}

int main()
{
    //freopen("test_5_2_in.txt","r",stdin);
    int kase;
    cin>>kase;
    while(kase--)
    {
        int n;
        cin>>n;
        //cout<<n<<endl;
        set<vector<int> > se;
        vector<int> prenum;
        vector<int> thisnum;
        for(int i=0;i<n;++i)
        {
            int temp;
            cin>>temp;
            //cout<<temp<<endl;
            prenum.push_back(temp);
        }
        //cout<<endl;
        //cout<<"prenum:";
        //print(prenum);
        se.insert(prenum);
        string outstr;
        while(1)
        {
            thisnum.clear();
            //printf("there\n");
            compuThisnum(prenum,thisnum);
            //cout<<"thisnum:";
            //print(thisnum);
            if(se.count(thisnum))
            {
                if(iszero(thisnum))
                    outstr="ZERO";
                else
                    outstr="LOOP";
                break;
            }
            se.insert(thisnum);
            prenum=thisnum;
        }
        cout<<outstr<<endl;
    }
}
