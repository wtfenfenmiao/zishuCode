#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxletter=185;
vector<vector<string> > save;
int maxcol[maxletter];

void print(string str,int len)
{
    cout<<str;
    for(int si=str.size();si<len;++si)
        printf(" ");
}

int main()
{
    //freopen("test_5_1_in.txt","r",stdin);
    string line;
    int row=0;
    memset(maxcol,0,sizeof(maxcol));
    while(getline(cin,line))
    {
        int thiscol=0;
        ++row;
        stringstream ss(line);
        vector<string> thisvec;
        string thisstr;
        while(ss>>thisstr)
        {
            thisvec.push_back(thisstr);
            if(thisstr.size()>maxcol[thiscol])
                maxcol[thiscol]=thisstr.size();
            ++thiscol;
        }
        save.push_back(thisvec);
    }
    for(int i=0;i<row;++i)
    {
        int si=save[i].size();
        int j=0;
        for(j=0;j<si-1;++j)
        {
            print(save[i][j],maxcol[j]);
            printf(" ");
        }
        cout<<save[i][j]<<endl;     //最右面不输出空格！！！
    }
}
