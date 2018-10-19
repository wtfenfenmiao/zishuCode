#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

const int maxn=20;
int triangle[maxn][maxn];
int re[maxn][maxn];
int n;

void print_triangle()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            cout<<triangle[i][j]<<" ";
        }
        cout<<endl;
    }
}

//记忆化搜索
int dp(int i,int j)
{
    if(re[i][j]!=0||triangle[i][j]==-1)
        return re[i][j];
    int& ans=re[i][j];
    ans=triangle[i][j]+max(dp(i+1,j),dp(i+1,j+1));
    return ans;
}

//递推
int dp2()
{
    for(int i=n-1;i>=0;--i)
    {
        for(int j=0;j<=i;++j)
        {
            re[i][j]=triangle[i][j]+max(re[i+1][j],re[i+1][j+1]);
            //cout<<"i:"<<i<<" "<<"j:"<<j<<" "<<re[i][j]<<endl;
        }
    }
    return re[0][0];
}


//打印字典序最小的那个
void printMinDic(int row,int col)
{
    if(triangle[row][col]==-1)
        return;
    cout<<"("<<row<<","<<col<<")"<<endl;
    for(int j=col;j<=col+1;++j)
    {
        if(re[row][col]-triangle[row][col]==re[row+1][j])
        {
            printMinDic(row+1,j);
            break;
        }
    }
}


//这样的问题刷leetcode也常遇到......不是打多了就是打少了
vector<vector<string>> computeAll(int row,int col)
{
    vector<vector<string>> rev;
    if(triangle[row][col]==-1)
    {
        return rev;
    }

    for(int j=col;j<=col+1;++j)
    {
        if(re[row][col]-triangle[row][col]==re[row+1][j])
        {
            string str="("+to_string(row)+","+to_string(col)+")";
            vector<vector<string>> temp;
            temp=computeAll(row+1,j);
            for(int i=0;i<temp.size();++i)
            {

                temp[i].push_back(str);
                rev.push_back(temp[i]);
            }
            if(rev.size()==0)
            {
                vector<string> st;
                st.push_back(str);
                rev.push_back(st);
            }
        }
    }

    return rev;
}

//打印所有的方案

void printAll()
{
    vector<vector<string>> rev;
    rev=computeAll(0,0);
    for(int i=0;i<rev.size();++i)
    {
        for(int j=0;j<rev[i].size();++j)
        {
            cout<<rev[i][j]<<endl;
        }
        cout<<endl;
    }
}





int main()
{
    freopen("digital_triangle_in.txt","r",stdin);
    memset(triangle,-1,sizeof(triangle));
    memset(re,0,sizeof(re));
    cout<<"there"<<endl;
    scanf("%d",&n);
    cout<<n<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            scanf("%d",&triangle[i][j]);
        }
    }
    print_triangle();
    cout<<"dp1:"<<dp(0,0)<<endl;
    memset(re,0,sizeof(re));
    cout<<"dp2:"<<dp2()<<endl;
    printMinDic(0,0);
    cout<<"print:"<<endl;
    printAll();

}
