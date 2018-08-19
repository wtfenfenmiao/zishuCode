#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int maxdepth=10;

int depNum[maxdepth];

int leaf[1<<maxdepth];

void findnum(string& str,int idx,int& start,int& endd)
{
    //cout<<"s:"<<start<<"  e:"<<endd<<endl;
    if(start==endd)
        return;
    char num=str[depNum[idx]];
    if(num=='0')
    {
        endd=start+(endd-start+1)/2-1;
    }
    else
    {
        start=start+(endd-start+1)/2;
    }
    findnum(str,idx+1,start,endd);
}

int main()
{
    //freopen("test_6_2_in.txt","r",stdin);
    int depth;
    int kase=0;
    while(scanf("%d",&depth)!=EOF&&depth!=0)
    {
        printf("S-Tree #%d:\n",++kase);
        //cout<<depth<<endl;
        memset(depNum,0,sizeof(depNum));
        memset(leaf,0,sizeof(leaf));
        string str;
        for(int i=0;i<depth;++i)
        {
            cin>>str;
            //cout<<str<<endl;
            depNum[i]=str[1]-'0'-1;
        }
        int n;
        cin>>str;
        //cout<<str<<endl;
        for(int i=0;i<(1<<depth);++i)
        {
            leaf[i]=str[i]-'0';
        }

        scanf("%d",&n);
        //cout<<n<<endl;
        while(n--)
        {
            cin>>str;
            //cout<<str<<endl;
            int start=0;
            int endd=(1<<depth)-1;
            findnum(str,0,start,endd);
            cout<<leaf[start];
        }
        cout<<endl<<endl;
    }
}


