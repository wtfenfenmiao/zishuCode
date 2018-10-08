#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


const int maxn=105;
char s[maxn];

int main()
{
    //freopen("example_10_9_in.txt","r",stdin);
    while(scanf("%s",s)!=EOF)
    {
        int cot=0;
        int cot0=0;
        int i;
        for(i=0;s[i];++i)
        {
            if(s[i]=='0')
            {
                ++cot0;
                if(s[i+1]=='0')
                    ++cot;
            }
        }
        if(i>=1&&s[0]=='0'&&s[i-1]=='0')
            ++cot;
        double f1=(double)cot/cot0;
        double f2=(double)(cot0)/i;
        //cout<<f1<<" "<<f2<<endl;
        cout<<(f1>f2?"SHOOT":(f1==f2?"EQUAL":"ROTATE"))<<endl;
    }
}
