#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=100010;
char s[maxn];
int next[maxn];


int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int n=strlen(s);
        memset(next,0,sizeof(next));
        int cur=0;
        int last=0;
        next[0]=0;
        for(int i=1;i<=n;++i)
        {
            if(s[i-1]=='[') cur=0;
            else if(s[i-1]==']') cur=last;
            else
            {
                next[i]=next[cur];
                next[cur]=i;
                if(cur==last) last=i;
                cur=i;
            }
        }
        int i=next[0];
        while(i!=0)
        {
            printf("%c",s[i-1]);
            i=next[i];
        }
        printf("\n");
    }
    return 0;
}
