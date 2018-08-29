#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=105;
long long int save[maxn];
int T;

void exgcd(long long int a,long long int b,long long int& d,long long int& x,long long int& y)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

bool is_true(long long int a,long long int b)
{
    for(int i=2;i<=2*T;++i)
    {
        int temp=(a*save[i-1]+b)%10001;
        if(i%2==0)
            save[i]=temp;
        else
        {
            if(temp!=save[i])
                return false;
        }
    }
    return true;
}

void print()
{
    for(int i=2;i<=2*T;i+=2)
    {
        cout<<save[i]<<endl;
    }
}

int main()
{
    memset(save,0,sizeof(save));
    freopen("example_10_2_in.txt","r",stdin);
    cin>>T;
    for(int i=1;i<=2*T;i+=2)
    {
        scanf("%lld",&save[i]);
    }
    //print();
    for(int a=0;a<=10000;++a)
    {
        long long int ctemp=save[3]-a*a*save[1];
        long long int b;
        long long int atemp=a+1;
        int btemp=10001;
        long long int y;
        long long int gcd;
        exgcd(atemp,btemp,gcd,b,y);
        if(ctemp%gcd!=0)
            continue;
        b=b*ctemp/gcd;
        //cout<<ctemp<<" "<<atemp<<" "<<btemp<<" "<<gcd<<" "<<b<<" "<<y<<endl;
        bool flag=false;
        //cout<<b<<endl;
        if(is_true(a,b))
        {
            print();
            break;
        }
    }
    return 0;
}
