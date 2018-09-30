#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=50005;
int eula_table[maxn];

int main()
{
    //freopen("example_10_7_in.txt","r",stdin);
    //freopen("example_10_7_out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        memset(eula_table,0,sizeof(eula_table));
        eula_table[1]=1;
        for(int i=2;i<=n;++i)
        {
            if(eula_table[i]==0)
            {
                for(int j=i;j<=n;j+=i)
                {
                    if(eula_table[j]==0)
                    {
                        eula_table[j]=j;
                    }
                    eula_table[j]=eula_table[j]/i*(i-1);
                    //cout<<j<<" "<<eula_table[j]<<endl;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=n;++i)
        {
        //    cout<<eula_table[i]<<" ";
            sum+=eula_table[i];
        }
        //cout<<endl;
        sum=sum*2-1;
        cout<<sum<<endl;
    }
}
