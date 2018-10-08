#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("example_10_10_in.txt","r",stdin);
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        double re=1.0;
        re=re*(a*b+b*(b-1));
        //cout<<re<<endl;
        re=re/((a+b)*(a+b-c-1));
        printf("%.5f\n",re);
    }
}
