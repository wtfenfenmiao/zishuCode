#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
#define maxn 30
vector<int> save[30];
int n;

void findplace(int num,int &place,int &height)
{
    for(place=0;place<n;++place)
    {
        for(height=0;height<save[place].size();++height)
        {
            if(save[place][height]==num)
                return;
        }
    }
}

void re(int p,int h)
{
    //printf("re   p:%d h:%d\n",p,h);
    for(int i=h+1;i<save[p].size();++i)
    {
        int temp=save[p][i];
        save[temp].push_back(temp);
    }
    save[p].resize(h+1);
}

void moveon(int p1,int h1,int p2)
{
    //printf("moveon   p1:%d h1:%d p2:%d\n",p1,h1,p2);
    for(int i=h1;i<save[p1].size();++i)
    {
        save[p2].push_back(save[p1][i]);
    }
    save[p1].resize(h1);
}

void pri()
{
    for(int i=0;i<n;++i)
    {
        printf("%d:",i);
        int j;
        for(j=0;j<save[i].size();++j)
            printf(" %d",save[i][j]);
        printf("\n");
    }
}

int main()
{
    //freopen("example_5_2_in.txt","r",stdin);
    cin>>n;
    //cout<<n<<endl;
    for(int i=0;i<n;++i)
    {
        save[i].push_back(i);
    }
    string s1,s2;
    int num1,num2;
    while(cin>>s1>>num1>>s2>>num2)
    {
        //cout<<s1<<" "<<num1<<" "<<s2<<" "<<num2<<endl;
        int p1,p2,h1,h2;
        findplace(num1,p1,h1);
        findplace(num2,p2,h2);
        if(p1==p2)
            continue;
        //printf("p1:%d  p2:%d  h1:%d  h2:%d\n",p1,p2,h1,h2);
        if(s1=="move")  re(p1,h1);
        if(s2=="onto")  re(p2,h2);
        moveon(p1,h1,p2);
        //pri();
    }
    pri();

    return 0;
}
