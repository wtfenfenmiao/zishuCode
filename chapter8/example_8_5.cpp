#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    //freopen("example_8_5_in.txt","r",stdin);
    int n;
    while(cin>>n&&n!=0)
    {
        long long int le=0;
        long long int re=0;
        for(int i=0;i<n;++i)
        {
            long long int num;
            cin>>num;
            re+=labs(le);
            le+=num;
        }
        cout<<re<<endl;
    }
    return 0;
}
