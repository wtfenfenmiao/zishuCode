#include<stdio.h>
#include<string.h>
#define maxn 100000

int main()
{


    //freopen("test_3_9_in.txt","r",stdin);
    //freopen("test_3_9_out.txt","w",stdout);
    char s[maxn];
    char t[maxn];
    while(scanf("%s %s",s,t)!=EOF)
    {
        int sj=0;
        for(int i=0;i<strlen(t);++i)
        {
            if(t[i]==s[sj])
                ++sj;
            if(sj==strlen(s))
                break;
        }
        printf("%s\n",sj==strlen(s)?"Yes":"No");
    }
    return 0;

}
