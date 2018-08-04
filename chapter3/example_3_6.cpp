#include<stdio.h>
#include<string.h>
#define maxn 110

bool Less(const char* s,int p,int q)
{
    int si=strlen(s);
    for(int i=0;i<si;++i)
    {
        if(s[(p+i)%si]!=s[(q+i)%si])
            return s[(p+i)%si]<s[(q+i)%si];
    }
    return false;
}


int main()
{
    int n;
    scanf("%d",&n);
    char s[maxn];
    while(n--)
    {
        scanf("%s",s);
        int re=0;
        int si=strlen(s);
        for(int i=1;i<si;++i)
        {
            if(Less(s,i,re)) re=i;
        }
        for(int i=0;i<si;++i)
        {
            printf("%c",s[(re+i)%si]);
        }
        printf("\n");
    }
    return 0;

}
