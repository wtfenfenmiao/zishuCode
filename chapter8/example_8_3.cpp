#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

const int maxn=4005;
int A[4][maxn];

int n;

void printA()
{
    for(int j=0;j<n;++j)
    {
        for(int i=0;i<4;++i)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //freopen("example_8_3_in.txt","r",stdin);
    int kase;
    cin>>kase;
    int kn=0;
    while(kase--)
    {
        if(kn++)
            cout<<endl;
        cin>>n;
        for(int j=0;j<n;++j)
        {
            for(int i=0;i<4;++i)
            {
                scanf("%d",&A[i][j]);
            }
        }
        //printA();
        int cnt=0;
        unordered_map<int,int> ha;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                ha[-A[0][i]-A[1][j]]+=1;
            }
        }
        unordered_map<int,int> has;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int sum=A[2][i]+A[3][j];
                if(ha.count(sum))
                    has[sum]+=ha[sum];
            }
        }
        for(unordered_map<int,int>::iterator it=has.begin();it!=has.end();++it)
        {
            cnt+=it->second;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
