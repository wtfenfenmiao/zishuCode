//n皇后问题



#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;


const int maxn=100000;
int vis[2][maxn*2];

void printQueen(vector<int>& re)
{
    for(int i=0;i<re.size();++i)
    {
        int thisnum=re[i];
        int s=0;
        while(s<thisnum)
        {
            cout<<0;
            ++s;
        }
        cout<<re.size();
        ++s;
        while(s<re.size())
        {
            cout<<0;
            ++s;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}



void findQueen(vector<int>& re,set<int>& se,int total,int n)
{
    if(total==n)
    {
        //for(int i=0;i<re.size();++i)
        //    cout<<re[i];
        //cout<<endl;
        printQueen(re);
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            if(se.count(i))
                continue;
            bool flag=true;
            for(int j=0;j<total;++j)
            {
                if(re[j]==i+j-total||re[j]==i-j+total)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                re.push_back(i);
                se.insert(i);
                findQueen(re,se,total+1,n);
                se.erase(i);
                re.pop_back();
            }
        }
    }
}

void findQueenFaster(vector<int>& re,int cur,int n)
{
    if(cur==n)
    {
        printQueen(re);
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n])
            {
                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
                re.push_back(i);
                findQueenFaster(re,cur+1,n);
                re.pop_back();
                vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
            }
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        vector<int> re;
        set<int> se;
        //findQueen(re,se,0,n);
        findQueenFaster(re,0,n);     //这个效率更高，判断列和对角线是否冲突不用遍历了
    }
    return 0;
}





