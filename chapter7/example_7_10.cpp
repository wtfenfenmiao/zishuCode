#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;


int n;
vector<int> save;
int maxd;
unordered_set<int> se;


int finderr(vector<int>& vec)
{
    int re=0;
    for(int i=1;i<vec.size();++i)
    {
        if(vec[i]!=vec[i-1]+1)
            ++re;
    }
    return re;
}


void init_table()
{
    se.clear();
    int v=0;
    for(int i=0;i<save.size();++i)
        v=v*10+save[i];
    se.insert(v);
}
bool is_insert(int &v)
{
    if(se.count(v))
        return false;
    se.insert(v);
    return true;
}

void printvec(vector<int>& vec)
{
    for(int i=0;i<vec.size();++i)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

bool solve(int dnow,vector<int> thissave,int errcnt)
{
    //cout<<"start:"<<dnow<<" "<<errcnt<<endl;
    //printvec(thissave);
    //cout<<endl;
    if(dnow==maxd)
    {
        if(errcnt) return false;
        return true;
    }
    if((maxd-dnow)*3<errcnt)
        return false;
    for(int nu=1;nu<n;++nu)
    {
        for(int po=0;po<=n-nu;++po)
        {
            //把po往后数nu个拿出去 n-nu+1
            vector<int> toinsert;
            toinsert.assign(thissave.begin()+po,thissave.begin()+po+nu);
            vector<int> temp=thissave;
            temp.erase(temp.begin()+po,temp.begin()+po+nu);
            for(int i=0;i<=n-nu;++i)
            {
                vector<int> temp1=temp;
                temp1.insert(temp1.begin()+i,toinsert.begin(),toinsert.end());
                //cout<<"遍历："<<endl;
                //cout<<"原来：";
                //printvec(thissave);
                //cout<<"现在：";
                //printvec(temp1);
                int vsum=0;
                for(int k=0;k<temp1.size();++k)
                    vsum=vsum*10+temp1[k];
                if(is_insert(vsum))
                {
                    //printvec(temp1);
                    int newerrcnt=finderr(temp1);
                    if(solve(dnow+1,temp1,newerrcnt))
                    {
                        return true;
                    }
                    se.erase(vsum);   //回溯法一定要记得状态还原！
                }
            }
        }
    }
    return false;
}


int main()
{
    //freopen("example_7_10_in.txt","r",stdin);
    //freopen("example_7_10_out.txt","w",stdout);
    int kase=0;
    while(cin>>n&&n!=0)
    {
        save.clear();
        int errcnt=0;
        for(int i=0;i<n;++i)
        {
            int num;
            scanf("%d",&num);
            save.push_back(num);
            if(i!=0&&(save[i]!=save[i-1]+1))
                ++errcnt;
        }
        for(maxd=0;;++maxd)
        {
            //cout<<"坐标："<<maxd<<endl;
            init_table();
            bool flag=solve(0,save,errcnt);
            if(flag)
                break;
        }
        cout<<"Case "<<++kase<<": "<<maxd<<endl;
    }
    return 0;
}
