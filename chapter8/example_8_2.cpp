#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;


int main()
{
    //freopen("example_8_2_in.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        cout<<2<<" "<<n<<" "<<n<<endl;
        for(int i=0;i<n;++i)
        {
            char ou=i>=26?'a'-26+i:'A'+i;
            for(int j=0;j<n;++j)
            {
                cout<<ou;
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cout<<(char)(j>=26?'a'-26+j:'A'+j);
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
