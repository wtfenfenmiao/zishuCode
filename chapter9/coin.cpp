#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

const int maxn=1000;
const int maxcoin=20;
int Smax[maxn];    //凑x元最多用Smax[x]个硬币
int Smin[maxn];    //凑x元最少用Smin[x]个硬币
bool ifcom[maxn];    //凑x元的情况已经算过了
int coin[maxcoin];   //最多有20种硬币
int n;   //要凑多少元


//记忆化搜索，从终点开始算，找最多的硬币数
int dpEndMax(int co,vector<int>& coinsave)
{
    //cout<<"now:"<<co<<endl;
    if(ifcom[co])
        return Smax[co];
    ifcom[co]=true;
    int& ans=Smax[co];
    int thissave=-1;
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i])
        {
            int temp=dpEndMax(co-coin[i],coinsave);
            if(temp==-1)
                continue;
            if(ans<temp+1)
            {
                ans=temp+1;
                thissave=i;
            }
        }
    }
    if(thissave!=-1)
        coinsave[co]=coin[thissave];
    //cout<<"co:"<<ans<<endl;
    return ans;
}



//记忆化搜索，从终点开始算，找最少的硬币数
int dpEndMin(int co,vector<int>& coinsave)
{
    if(ifcom[co])
        return Smin[co];
    ifcom[co]=true;
    int& ans=Smin[co];
    ans=INT_MAX;
    int thissave=-1;
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i])
        {
            int temp=dpEndMin(co-coin[i],coinsave);
            if(temp==-1)
                continue;
            if(ans>temp+1)
            {
                ans=temp+1;
                thissave=i;
            }
        }
    }
    if(ans==INT_MAX)
        ans=-1;
    if(thissave!=-1)
        coinsave[co]=coin[thissave];
    return ans;
}

//打印字典序最小的，满足条件的方案的另一种办法
void printMax(int co)
{
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i]&&Smax[co]==Smax[co-coin[i]]+1)  //之前写成，&&Smax[co-coin[i]]!=-1，这样得到的是目前算过的情况中，字典序最小的，而不一定满足max的要求。这个搞错了！要算清楚！
        {
            cout<<coin[i]<<endl;
            printMax(co-coin[i]);
            break;
        }
    }
}

void printMin(int co)
{
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i]&&Smin[co]==Smin[co-coin[i]]+1)
        {
            cout<<coin[i]<<endl;
            printMin(co-coin[i]);
            break;
        }
    }
}


//记忆化搜索，从起点开始算，找最多的硬币数。不写了，就是那个递推
int dpStartMax(int co,vector<int>& coinsave)
{

}

//记忆化搜索，从起点开始算，找最少的硬币数。不写了，就是那个递推
int dpStrtMin(int co,vector<int>& coinsave)
{

}

//递推,感觉这种硬币的coin[]得从小到大排好序
void ditui(vector<int>& savemin,vector<int>& savemax)
{
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<maxcoin&&coin[j];++j)
        {
            if(Smax[i]!=-1)
            {
                if(Smax[i+coin[j]]<Smax[i]+1)
                {
                    Smax[i+coin[j]]=Smax[i]+1;
                    savemax[i+coin[j]]=coin[j];
                    //cout<<"max:"<<i+coin[j]<<" "<<coin[j]<<endl;
                }
            }



            if(Smin[i]!=-1)
            {
                if(Smin[i+coin[j]]==-1)
                    Smin[i+coin[j]]=INT_MAX;
                if(Smin[i+coin[j]]>Smin[i]+1)
                {
                    Smin[i+coin[j]]=Smin[i]+1;
                    savemin[i+coin[j]]=coin[j];
                    //cout<<"min:"<<i+coin[j]<<" "<<coin[j]<<endl;
                }
                if(Smin[i+coin[j]]==INT_MAX)
                    Smin[i+coin[j]]=-1;
            }


        }
    }
}



void print_Smax()
{
    for(int i=0;i<=n;++i)
        cout<<i<<" "<<Smax[i]<<endl;
}

void print_Smin()
{
    for(int i=0;i<=n;++i)
        cout<<i<<" "<<Smin[i]<<endl;
}

int main()
{
    freopen("coin_in.txt","r",stdin);
    scanf("%d",&n);
    //cout<<n<<endl;
    memset(coin,0,sizeof(coin));
    int i=0;
    while(scanf("%d",&coin[i++])!=EOF);
    //for(int i=0;i<maxcoin&&coin[i];++i)
    //{
    //    cout<<coin[i]<<endl;
    //}




    memset(Smax,-1,sizeof(Smax));
    Smax[0]=0;    //-1是不存在。0这种情况存在，凑0元需要0个硬币。这个例子凑3元的情况就不存在，就是-1
    memset(ifcom,0,sizeof(ifcom));
    ifcom[0]=true;

    vector<int> coinSaveMax(n,0);
    cout<<"从终点开始算的最多多少个硬币："<<dpEndMax(n,coinSaveMax)<<endl;   //还有n元没凑够，要算到0
    cout<<"从终点开始算的最多多少个硬币方案："<<endl;   //还有n元没凑够，要算到0
    int te=n;
    while(te!=0)
    {
        cout<<coinSaveMax[te]<<endl;
        te-=coinSaveMax[te];
    }
    cout<<"最多第二种算法："<<endl;
    printMax(n);
    cout<<endl;
    //print_Smax();


    memset(Smin,-1,sizeof(Smin));
    Smin[0]=0;    //-1是不存在。0这种情况存在，凑0元需要0个硬币。这个例子凑3元的情况就不存在，就是-1
    memset(ifcom,0,sizeof(ifcom));
    ifcom[0]=true;
    vector<int> coinSaveMin(n,0);
    cout<<"从终点开始算的最少多少个硬币："<<dpEndMin(n,coinSaveMin)<<endl;   //还有n元没凑够，要算到0
    cout<<"从终点开始算的最少多少个硬币方案："<<endl;   //还有n元没凑够，要算到0
    te=n;
    while(te!=0)
    {
        //cout<<"te:"<<te<<endl;
        cout<<coinSaveMin[te]<<endl;
        te-=coinSaveMin[te];
    }
    cout<<"最少第二种算法："<<endl;
    printMin(n);
    cout<<endl;
    //print_Smin();


    memset(Smax,0,sizeof(Smax));
    memset(Smax,-1,sizeof(Smax));
    Smax[0]=0;    //-1是不存在。0这种情况存在，凑0元需要0个硬币。这个例子凑3元的情况就不存在，就是-1
    memset(Smin,0,sizeof(Smin));
    memset(Smin,-1,sizeof(Smin));
    Smin[0]=0;    //-1是不存在。0这种情况存在，凑0元需要0个硬币。这个例子凑3元的情况就不存在，就是-1


    vector<int> savemin(n,0);
    vector<int> savemax(n,0);
    ditui(savemin,savemax);
    cout<<Smin[n]<<" "<<Smax[n]<<endl;
    te=n;
    while(te!=0)
    {
        //cout<<"te:"<<te<<endl;
        cout<<savemin[te]<<endl;
        te-=savemin[te];
    }
    cout<<endl;
    te=n;

    while(te!=0)
    {
        //cout<<"te2:"<<te<<endl;
        cout<<savemax[te]<<endl;
        te-=savemax[te];
    }
    cout<<endl;


}
