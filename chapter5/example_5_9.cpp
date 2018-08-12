/*
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<utility>
#include<set>
#include<iostream>
using namespace std;
const int maxn=10005;
const int maxm=15;
int save[maxn][maxm];
map<string,int> str_ID;
map<pair<int,int>,int> findmap;
int ID;
int n,m;


void print()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            printf("%d ",save[i][j]);
        }
        printf("\n");
    }
}

void dealstr(int row)
{
    string line;
    getline(cin,line);
    //cout<<line<<endl;
    int si=line.size();
    int start=0;
    int endd=0;
    int col=0;
    while(1)
    {
        while(endd<si&&line[endd]!=',')  ++endd;
        string str=line.substr(start,endd-start);
        //cout<<"str:"<<str<<endl;
        if(!str_ID.count(str)) str_ID[str]=ID++;
        save[row][col]=str_ID[str];
        ++col;
        start=endd+1;
        endd=start;
        if(endd>=si)
        {
            break;
        }
    }

}




void findcr(int &c1,int &c2,int &r1,int &r2)
{

    pair<int,int> pa;
    r1=0;
    r2=0;
    c1=0;
    c2=0;
    for(c1=0;c1<m;++c1)
    {
        for(c2=c1+1;c2<m;++c2)
        {
            findmap.clear();    //问题出在这里，要不可能会出现，不同列的情况。问题在这里
            for(r2=0;r2<n;++r2)
            {
                pa.first=save[r2][c1];
                pa.second=save[r2][c2];
                //cout<<"pair:"<<pa.first<<" "<<pa.second<<endl;
                if(findmap.count(pa))
                {
                    r1=findmap[pa];
                    return;
                }
                findmap[pa]=r2;
            }
        }
    }
    return;
}


int main()
{
    //freopen("example_5_9_in.txt","r",stdin);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        getchar();
        //cout<<n<<" "<<m<<endl;
        memset(save,0,sizeof(save));
        str_ID.clear();

        ID=0;
        for(int i=0;i<n;++i)
        {
            dealstr(i);
        }
        //print();
        int c1;
        int c2;
        int r1;
        int r2;
        findcr(c1,c2,r1,r2);
        //printf("result:%d %d %d %d\n",c1,c2,r1,r2);
        if(c1<m&&c2<m&&r1<n&&r2<n&&(c1!=c2)&&(r1!=r2))
        {
            printf("NO\n%d %d\n%d %d\n",r1+1,r2+1,c1+1,c2+1);
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
*/


#include<cstdio>
#include<map>
#include<cstring>
#include<utility>
#include<iostream>

using namespace std;

const int maxn=10005;
const int maxm=15;
int save[maxn][maxm];

int n,m;
map<string,int> str_ID;
map<pair<int,int>,int> findmap;
pair<int,int> pa;

void print()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            printf("%d ",save[i][j]);
        }
        printf("\n");
    }
}

int ID(string str)
{
    if(str_ID.count(str)) return str_ID[str];
    int temp=str_ID.size();
    str_ID[str]=temp;
    return temp;
}

void dealstr(int row)
{
    string line;
    getline(cin,line);
    //cout<<line<<endl;
    int si=line.size();
    int col=0;
    int start=0;
    int endd=0;
    while(1)
    {
        while(endd<si&&line[endd]!=',') ++endd;
        string str=line.substr(start,endd-start);
        save[row][col]=ID(str);
        ++col;
        start=endd+1;
        endd=start;
        if(endd>=si)
            break;
    }
}

void findrc(int &c1,int &c2,int &r1,int &r2)
{
    c1=c2=r1=r2=0;
    for(c1=0;c1<m;++c1)
    {
        for(c2=c1+1;c2<m;++c2)
        {
            findmap.clear();
            for(r2=0;r2<n;++r2)
            {
                pa.first=save[r2][c1];
                pa.second=save[r2][c2];
                if(findmap.count(pa))
                {
                    r1=findmap[pa];
                    return;
                }
                findmap[pa]=r2;
            }
        }
    }
    return;
}

int main()
{
    //freopen("example_5_9_in.txt","r",stdin);
    while(cin>>n>>m)
    {
        getchar();   //要有。如果有读串行的问题，基本都是\n。适当地方加getchar
        //cout<<n<<m<<endl;
        memset(save,0,sizeof(save));
        str_ID.clear();
        for(int i=0;i<n;++i)
            dealstr(i);
        //print();

        int c1,c2,r1,r2;
        findrc(c1,c2,r1,r2);
        if(c1<m&&c2<m&&r1<n&&r2<n&&c1!=c2&&r1!=r2)
        {
            printf("NO\n%d %d\n%d %d\n",r1+1,r2+1,c1+1,c2+1);
        }
        else
            printf("YES\n");

    }
}








