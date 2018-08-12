#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxnum=60;

void print(string s,int len,char a)
{
    int si=s.size();
    cout<<s;
    for(;si<len;++si)
    {
        printf("%c",a);
    }
}


int main()
{
    //freopen("example_5_8_in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        print("",60,'-');
        printf("\n");
        vector<string> svec;
        int M=0;
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            svec.push_back(s);
            M=max(M,(int)(s.size()));
        }
        int col=(maxnum-M)/(M+2)+1;
        int row=(n-1)/col+1;
        sort(svec.begin(),svec.end());
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                int idx=row*j+i;
                if(idx<n) print(svec[idx],j==col-1?M:M+2,' ');
            }
            printf("\n");
        }
    }
}
