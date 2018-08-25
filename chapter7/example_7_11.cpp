#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;


int main()
{
    //freopen("example_7_11_in.txt","r",stdin);
    int kase;
    cin>>kase;
    int k=1;
    while(k<=kase)
    {
        unsigned long long int N,s1,v1,s2,v2;
        cin>>N>>s1>>v1>>s2>>v2;
        unsigned long long  int re=0;
        if(N/s1<=s1||N/s2<=s2)
        {
            if(s1<s2)
            {
                unsigned long long  int temp=s1;
                s1=s2;
                s2=temp;
                temp=v1;
                v1=v2;
                v2=temp;
            }
            for(unsigned long long int i=0;i<=N/s1;++i)
            {
                unsigned  long long int sum=i*v1+(N-i*s1)/s2*v2;
                if(sum>re)
                    re=sum;
            }
        }
        else
        {
            //s1个2和s2个1体积相同，若s1*v2>s2*v1,则1不超过s2-1个
            if(s1*v2>s2*v1)
            {
                for(unsigned  long long int i=0;i<s2&&i<=N/s1;++i)
                {
                    unsigned  long long int sum=i*v1+(N-i*s1)/s2*v2;
                    if(sum>re)
                        re=sum;
                }
            }
            else
            {
                for(unsigned  long long int i=0;i<s1&&i<=N/s2;++i)
                {
                    unsigned  long long int sum=i*v2+(N-i*s2)/s1*v1;
                    if(sum>re)
                        re=sum;
                }
            }
        }
        cout<<"Case #"<<k<<": "<<re<<endl;
        ++k;
    }
}
