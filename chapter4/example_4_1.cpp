#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define maxn 105

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}


int main()
{
    //freopen("example_4_1_in.txt","r",stdin);
    //freopen("example_4_1_out.txt","w",stdout);
    int a[26];
    int b[26];
    char s1[maxn];
    char s2[maxn];
    while(scanf("%s",s1)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%s",s2);
        int si1=strlen(s1);
        int si2=strlen(s2);
        if(si1!=si2)
        {
            printf("NO\n");
            continue;
        }
        for(int i=0;i<si1;++i)
        {
            ++a[s1[i]-'A'];
            ++b[s2[i]-'A'];
        }
        qsort(a,26,sizeof(int),cmp);
        qsort(b,26,sizeof(int),cmp);
        int i=0;
        for(i=0;i<26;++i)
        {
            if(a[i]!=b[i])
            {
                printf("NO\n");
                break;
            }
        }
        if(i==26)
            printf("YES\n");
    }
    return 0;
}
