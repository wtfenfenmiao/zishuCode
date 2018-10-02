#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
char first[6][5];
char second[6][5];
char same[6][5];
int samenum[5];

string fi[5];
string se[5];

void findpass2(int n,int& k,string& re)
{
    if(n==0)
    {
        --k;
        return;
    }
    for(int i=0;i<6;++i)
    {
        if(same[i][5-n]==0)
            return;
        string temp=re;
        re+=same[i][5-n];
        //cout<<re<<endl;
        findpass2(n-1,k,re);
        if(k==0)
            return;
        re=temp;
    }
}

void findpass(int n,int k,string& re,int factorial)
{
    if(n==0||k==0)
        return;
    if(same[5-n]==0)
        return;
    if(k>factorial)
        return;
    factorial/=samenum[5-n];
    int start=0;
    while(start<6&&same[start][5-n]!=0&&k>factorial)
    {
        k-=factorial;
        ++start;
    }
    re+=same[start][5-n];
    //cout<<"k:"<<k<<endl;
    //cout<<re<<endl;
    --n;
    findpass(n,k,re,factorial);
}

void printsamenum()
{
    for(int i=0;i<5;++i)
        cout<<samenum[i]<<" ";
    cout<<endl;
}

void printsame()
{
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<6;++j)
        {
            if(same[j][i]!=0)
                cout<<same[j][i]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    //freopen("example_10_8_in.txt","r",stdin);
    //freopen("example_10_8_out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int k;
        scanf("%d",&k);
        //cout<<k<<endl;
        for(int i=0;i<6;++i)
        {
            scanf("%s",first[i]);
        }
        for(int i=0;i<6;++i)
        {
            scanf("%s",second[i]);
        }
        memset(same,0,sizeof(same));
        memset(samenum,0,sizeof(same));
        memset(fi,0,sizeof(fi));
        memset(se,0,sizeof(se));

        for(int i=0;i<5;++i)
        {
            for(int j=0;j<6;++j)
            {
                fi[i]+=first[j][i];
                se[i]+=second[j][i];
            }
            sort(fi[i].begin(),fi[i].end());
            sort(se[i].begin(),se[i].end());
        }

        for(int i=0;i<5;++i)
        {
            int s1=0;
            int s2=0;
            int cnt=0;
            while(s1<6&&s2<6)
            {
                if(fi[i][s1]==se[i][s2])
                {
                    if(cnt==0||same[cnt-1][i]!=fi[i][s1])
                    {
                        ++samenum[i];
                        same[cnt++][i]=fi[i][s1];
                    }

                    ++s1;
                    ++s2;
                    /*
                    int left=1;
                    int right=1;
                    while(s1+1<6&&fi[i][s1+1]==fi[i][s1])  //开始理解错了写成了留重
                    {
                        ++left;
                        ++s1;
                    }
                    while(s2+1<6&&se[i][s2+1]==se[i][s2])
                    {
                        ++right;
                        ++s2;
                    }
                    samenum[i]+=left*right;
                    for(int l=0;l<left*right;++l)
                    {
                        same[cnt++][i]=fi[i][s1];
                    }
                    ++s1;
                    ++s2;
                    */

                }
                else if(fi[i][s1]<se[i][s2])
                    ++s1;
                else
                    ++s2;
            }
        }


        //printsamenum();
        //printsame();
        int factorial=1;
        for(int i=0;i<5;++i)
        {
            factorial*=samenum[i];
        }
        string re="";
        /*
        findpass(5,k,re,factorial);   //第一种，正常解法
        if(re.size()!=5)
            cout<<"NO"<<endl;
        else
            cout<<re<<endl;
        */
        findpass2(5,k,re);
        if(k!=0)            //第二种，因为k不大于7777，所以可以暴力枚举
            cout<<"NO"<<endl;
        else
            cout<<re<<endl;
    }
}


