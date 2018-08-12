#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    //freopen("test_5_6_in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        map<int,vector<int> > vecmap;
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            vecmap[y].push_back(x);
        }
        double mean;
        bool flag=true;
        string out="YES";
        for(map<int,vector<int> >::iterator it=vecmap.begin();it!=vecmap.end();++it)
        {
            vector<int> temp=it->second;
            double sum=0.0;
            for(int i=0;i<temp.size();++i)
            {
                sum+=temp[i];
            }
            sum/=temp.size();
            if(flag)
            {
                mean=sum;
                flag=false;
            }
            else
            {
                if(sum!=mean)
                {
                    out="NO";
                    break;
                }
            }
        }
        cout<<out<<endl;
    }
}
