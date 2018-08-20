#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>

using namespace std;

void findlow(vector<int>& low,int temp,set<int>& se)
{
    if(se.size()==5)
    {
        low.push_back(temp);
        return;
    }

    for(int i=0;i<=9;++i)
    {
        if(!se.count(i))
        {
            se.insert(i);
            temp=temp*10+i;
            findlow(low,temp,se);
            se.erase(i);
            temp=(temp-i)/10;
        }
    }
    return;
}

int main()
{
    int n;
    int kase=0;
    while(cin>>n&&n!=0)
    {
        if(kase++)
            cout<<endl;
        vector<int> low;
        set<int> se;
        int temp=0;
        findlow(low,temp,se);

        int cnt=0;
        for(int i=0;i<low.size();++i)
        {
            //cout<<low[i]<<endl;
            se.clear();
            int high=low[i]*n;
            //cout<<high<<endl;
            if(high/100000!=0)
                break;
            int c=5;
            temp=low[i];
            int cntlow=0;
            while(c--)
            {
                if(temp==0)
                    ++cntlow;
                se.insert(temp%10);
                temp/=10;
            }
            temp=high;
            c=5;
            int cnthigh=0;
            while(c--)
            {
                if(temp==0)
                    ++cnthigh;
                int t=temp%10;
                if(se.count(t))
                    break;
                se.insert(t);
                temp/=10;
            }
            //for(set<int>::iterator it=se.begin();it!=se.end();++it)
            //{
            //    cout<<*it<<" ";
            //}
            //cout<<endl;
            //cout<<c<<endl;
            if(c!=-1)
                continue;
            else
            {
                ++cnt;
                while(cnthigh)
                {
                    cout<<"0";
                    --cnthigh;
                }
                cout<<high<<" / ";
                while(cntlow)
                {
                    cout<<"0";
                    --cntlow;
                }
                cout<<low[i]<<" = "<<n<<endl;
            }
        }
        if(cnt==0)
            printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
