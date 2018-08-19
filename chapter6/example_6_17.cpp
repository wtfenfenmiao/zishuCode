//我写的，很麻烦
/*
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn=205;

char buff[maxn][maxn];

void solveA(int r,int idx)
{
    printf("%c",buff[r][idx]);
    if(buff[r+1][idx]!='|')
    {
        printf("()");
        //cout<<"there:"<<endl;
        return;
    }
    int st=idx;
    int et=idx;
    while(st>=0&&buff[r+2][st]=='-') --st;
    st+=1;
    while(buff[r+2][et]=='-') ++et;
    et-=1;
    //cout<<"st:"<<st<<" "<<"et:"<<et<<endl;
    printf("(");
    for(int j=st;j<=et;++j)
    {
        if(buff[r+3][j]!='\0'&&buff[r+3][j]!='-'&&buff[r+3][j]!='|'&&buff[r+3][j]!='\n'&&buff[r+3][j]!=' '&&buff[r+3][j]!='#')
        {
            solveA(r+3,j);
        }
    }
    printf(")");
    return;
}

void solve()
{
    for(int i=0;i<=maxn;++i)
    {
        if(buff[0][i]=='#')
        {
            //cout<<"there4:"<<i<<endl;
            printf("()");
            return;
        }
        if(buff[0][i]!='\0'&&buff[0][i]!='-'&&buff[0][i]!='|'&&buff[0][i]!='\n'&&buff[0][i]!=' '&&buff[0][i]!='#')
        {
            //printf("tt:%c\n",buff[0][i]);
            printf("(");
            //cout<<"there2"<<endl;
            solveA(0,i);
            //cout<<"there3"<<endl;
            printf(")");
            //cout<<"end?"<<endl;
            return;
        }

    }

}

int main()
{
    //freopen("example_6_17_in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
        memset(buff,0,sizeof(buff));
        int i=0;
        while(1)
        {
            fgets(buff[i],maxn,stdin);
            if(buff[i][0]=='#')
                break;
            ++i;
        }

        for(int i=0;i<maxn;++i)
        {
            cout<<buff[i];
        }

        solve();
        printf("\n");
    }
}
*/

/*
//大佬的，同样的意思，就能写的很简单
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=205;
char buff[maxn][maxn];

void dfs(int r,int idx)
{
    printf("%c(",buff[r][idx]);
    if(buff[r+1][idx]=='|')
    {
        int st=idx;
        while(st>=0&&buff[r+2][st]=='-') --st;
        for(int i=st+1;buff[r+3][i]!='\0'&&buff[r+2][i]=='-';++i)
        {
            if(!isspace(buff[r+3][i])&&buff[r+3][i]!='#'&&buff[r+3][i]!='-'&&buff[r+3][i]!='|')
                dfs(r+3,i);
        }
    }
    printf(")");
    return;
}

void solve()
{
    memset(buff,0,sizeof(buff));
    int n=0;
    while(1)
    {
        fgets(buff[n],maxn,stdin);
        if(buff[n][0]=='#')
            break;
        ++n;
    }
    printf("(");
    if(n)
    {
        for(int i=0;i<strlen(buff[0]);++i)
        {
            if(!isspace(buff[0][i])&&buff[0][i]!='-'&&buff[0][i]!='#'&&buff[0][i]!='|')
            {
                dfs(0,i);
                break;
            }
        }
    }
    printf(")\n");
}

int main()
{
    //freopen("example_6_17_in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
        solve();
    }
    return 0;
}
*/



//再来一遍
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=205;
char buff[maxn][maxn];


void dfs(int r,int idx)
{
    printf("%c(",buff[r][idx]);
    if(buff[r+1][idx]=='|')
    {
        int st=idx;
        while(st>=0&&buff[r+2][st]=='-') --st;
        for(int i=st+1;buff[r+2][i]=='-'&&buff[r+3][i]!='\0';++i)
        {
            if(!isspace(buff[r+3][i])&&buff[r+3][i]!='#'&&buff[r+3][i]!='-'&&buff[r+3][i]!='|')
                dfs(r+3,i);
        }
    }
    printf(")");
    return;
}


void solve()
{
    memset(buff,0,sizeof(buff));
    int n=0;
    while(1)
    {
        fgets(buff[n],maxn,stdin);
        if(buff[n][0]=='#')
            break;
        ++n;
    }
    printf("(");
    if(n)
    {
        for(int i=0;i<strlen(buff[0]);++i)
        {
            if(buff[0][i]!=' '&&buff[0][i]!='#'&buff[0][i]!='-'&buff[0][i]!='|')
            {
                dfs(0,i);
                break;
            }
        }
    }
    printf(")\n");

}

int main()
{
    //freopen("example_6_17_in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
        solve();
    }
    return 0;
}
