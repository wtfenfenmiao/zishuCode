#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn=20;
int rectangle[maxn][2];   //存每个矩形的长宽，行是这个矩形的编号
int remax[maxn];   //图节点。是以每个矩形作为起点的最长路的长度
bool bian[maxn][maxn];  //边，如果矩形B能覆盖矩形A，则A->B
int n;


int dpMaxHelp(int i)
{
    if(remax[i]!=0)
        return remax[i];
    int& ans=remax[i];
    ans=1;
    for(int j=0;j<n;++j)
    {
        if(bian[i][j])
            ans=max(ans,dpMaxHelp(j)+1);
    }
    cout<<i<<" "<<rectangle[i][0]<<" "<<rectangle[i][1]<<":"<<ans<<endl;
    return ans;
}


//填表法
int dp1()
{
    int rema=0;
    for(int i=0;i<n;++i)
    {
        int temp=dpMaxHelp(i);
        cout<<temp<<endl;
        rema=max(rema,temp);
    }
    return rema;
}

void printMinDicHelp(int index)
{
    cout<<index<<" "<<rectangle[index][0]<<" "<<rectangle[index][1]<<endl;
    for(int i=0;i<n;++i)
    {
        if(remax[i]==remax[index]-1)
        {
            printMinDicHelp(i);
            break;
        }

    }
}

void printMinDic(int rema)
{
    for(int i=0;i<n;++i)
    {
        if(remax[i]==rema)
        {
            printMinDicHelp(i);
            break;
        }
    }
}



//刷表法，这个是错的！这里刷表法不适用！打印出来就知道了！比如5,8加进来的时候，1,2先更新，2,4后更新，但是2,4更新后1,2其实可以更长的，这里算不了。所以这里刷表法不适用！
int dp2()
{
    for(int j=0;j<n;++j)
    {
        if(remax[j]==0)
            remax[j]=1;
        cout<<j<<endl;
        for(int i=0;i<n;++i)
        {
            if(bian[i][j])
            {
                remax[i]=max(remax[i],1+remax[j]);
                cout<<i<<" "<<rectangle[i][0]<<" "<<rectangle[i][1]<<":"<<remax[i]<<endl;
            }
        }
        cout<<endl;
    }
    int rema=0;
    for(int i=0;i<n;++i)
    {
        rema=max(remax[i],rema);
    }
    return rema;
}


void print_rectangle()
{
    for(int i=0;i<n;++i)
    {
        cout<<rectangle[i][0]<<" "<<rectangle[i][1]<<endl;
    }
}

void print_bian()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<bian[i][j]<<" ";
        }
        cout<<endl;
    }
}






int main()
{
    freopen("rectangle_in.txt","r",stdin);
    scanf("%d",&n);
    cout<<n<<endl;
    memset(rectangle,0,sizeof(rectangle));
    memset(remax,0,sizeof(remax));
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&rectangle[i][0],&rectangle[i][1]);
    }
    print_rectangle();
    for(int i=0;i<n;++i)   //这样子防止环。两个相同的，连一个边就行，不要连两个
    {
        for(int j=i+1;j<n;++j)
        {
            if(rectangle[j][0]>=rectangle[i][0]&&rectangle[j][1]>=rectangle[i][1])
                bian[i][j]=true;
            else if(rectangle[i][0]>=rectangle[j][0]&&rectangle[i][1]>=rectangle[j][1])
                bian[j][i]=true;

        }
    }
    print_bian();
    int ma=dp1();
    cout<<"dp1max:"<<ma<<endl;
    printMinDic(ma);
    //memset(remax,0,sizeof(remax));
    //cout<<"dp2max:"<<dp2()<<endl;
}
