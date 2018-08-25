#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<utility>

using namespace std;

const int maxn=17;
//坐标从1-16,0不算坐标。用来标志这个字母没有
int block[maxn][maxn];  //1是有小写数字或障碍，0是空的
typedef int State[6];  //最多3个字母，每个字母两个数，横纵坐标。
int col,row,n;
State st[1<<25];
State endd;
int dis[1<<25];

int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};

const int hashsize=10000000;
int ha[hashsize];
int nex[hashsize];

void init_table()
{
    int thisnum=0;
    for(int i=0;i<n*2;++i)
    {
        thisnum=thisnum*10+st[1][i];
    }
    thisnum%=hashsize;
    nex[1]=ha[thisnum];
    ha[thisnum]=1;
}

bool is_insert(int rear,int fr)
{

    set<pair<int,int> > se;
    int thisnum=0;
    for(int i=0;i<n;++i)
    {
        int x=st[rear][i*2];
        int y=st[rear][i*2+1];
        thisnum=thisnum*10+x;
        thisnum=thisnum*10+y;
        //cout<<x<<" "<<y<<endl;
        if(x<=0||x>row||y<=0||y>col||block[x][y]==1)
            return false;
        pair<int,int> pa;
        pa.first=x;
        pa.second=y;
        if(se.count(pa))
            return false;
        se.insert(pa);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int rix=st[rear][i*2];
            int riy=st[rear][i*2+1];
            int rjx=st[rear][j*2];
            int rjy=st[rear][j*2+1];
            int fix=st[fr][i*2];
            int fiy=st[fr][i*2+1];
            int fjx=st[fr][j*2];
            int fjy=st[fr][j*2+1];
            //cout<<rix<<" "<<riy<<" "<<rjx<<" "<<rjy<<endl;
            //cout<<fix<<" "<<fiy<<" "<<fjx<<" "<<fjy<<endl;
            if(fix==rjx&&fiy==rjy&&fjx==rix&&fjy==riy)
            {
                //cout<<"false"<<endl;
                return false;

            }

        }
    }
    int haidx=thisnum%hashsize;
    int u=ha[haidx];
    while(u)
    {
        if(memcmp(st[u],st[rear],sizeof(u))==0) return false;
        u=nex[u];
    }
    nex[rear]=ha[haidx];
    ha[haidx]=rear;
    return true;
}

bool issame(State& a,State &b)
{
    for(int i=0;i<n*2;++i)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int solve()
{
    //int cnt=0;
    int fr=1;
    int rear=2;
    dis[1]=0;
    init_table();
    while(fr<rear)
    {
        if(issame(st[fr],endd))
            return fr;
        State& temp=st[fr];

        for(int i=0;i<5;++i)
        {
            for(int j=0;j<5;++j)
            {
                for(int k=0;k<5;++k)
                {
                    st[rear][0]=temp[0]+dx[i];
                    st[rear][1]=temp[1]+dy[i];
                    st[rear][2]=temp[2]+dx[j];
                    st[rear][3]=temp[3]+dy[j];
                    st[rear][4]=temp[4]+dx[k];
                    st[rear][5]=temp[5]+dy[k];
                    dis[rear]=dis[fr]+1;
                    if(is_insert(rear,fr))
                    {
                        //cout<<st[rear][0]<<" "<<st[rear][1]<<" "<<st[rear][2]<<" "<<st[rear][3]<<" "<<st[rear][4]<<" "<<st[rear][5]<<" "<<endl;
                        ++rear;
                        //++cnt;
                    }
                }
            }
        }
        ++fr;
    }
    //cout<<cnt<<endl;
    return 0;
}

void printblock()
{
    for(int i=1;i<=row;++i)
    {
        for(int j=1;j<=col;++j)
            cout<<block[i][j];
        cout<<endl;
    }
}

printstate(State& a)
{
    for(int i=0;i<n*2;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    freopen("example_7_9_in.txt","r",stdin);
    //freopen("example_7_9_out.txt","w",stdout);
    while(cin>>col>>row>>n&&col!=0)
    {
        memset(block,0,sizeof(block));
        memset(st,0,sizeof(st));
        memset(dis,-1,sizeof(dis));
        memset(ha,0,sizeof(ha));
        memset(nex,0,sizeof(nex));
        getchar();
        string str;
        for(int i=0;i<row;++i)
        {
            getline(cin,str);
            for(int j=0;j<col;++j)
            {
                if(str[j]=='#')
                    block[i+1][j+1]=1;
                else if(str[j]=='A'||str[j]=='B'||str[j]=='C')
                {

                    endd[(str[j]-'A')*2]=i+1;
                    endd[(str[j]-'A')*2+1]=j+1;
                }
                else if(str[j]=='a'||str[j]=='b'||str[j]=='c')
                {

                    st[1][(str[j]-'a')*2]=i+1;
                    st[1][(str[j]-'a')*2+1]=j+1;
                    //cout<<str[j]<<" "<<st[1][(str[j]-'a')*2]<<" "<<st[1][(str[j]-'a')*2+1]<<endl;
                }
            }
        }
        //printblock();
        //printstate(st[1]);
        //printstate(endd);
        int re=solve();
        cout<<dis[re]<<endl;

    }
    return 0;
}
