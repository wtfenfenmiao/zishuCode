#include<stdio.h>
#include<string.h>
#include<ctype.h>


//我写的，很麻烦
/*
char mirr(char ch,const char* rev)
{
    if(isalpha(ch)) return rev[ch-'A'];
    else return rev[ch-'0'+25];
}

int main()
{
    freopen("example_3_3_in.txt","r",stdin);
    freopen("example_3_3_out.txt","w",stdout);
    const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";   //char*当string用就行
    const char* msg[]={"is not a palindrome.","is a regular palindrome.","is a mirrored string.","is a mirrored palindrome."};
    char s[30];
    while(scanf("%s",s)==1)
    {
        bool ispali=true;
        bool ismirr=true;
        int si=strlen(s);
        for(int i=0;i<(si+1)/2;++i)
        {
            if(!ispali&&!ismirr)
                break;
            if(ispali)
            {
                if(s[i]!=s[si-1-i])
                    ispali=false;
            }
            if(ismirr)
            {
                if(mirr(s[i],rev)!=s[si-1-i])
                    ismirr=false;
            }
        }
        if(ispali)
        {
            if(ismirr)
                printf("%s -- %s\n\n",s,msg[3]);
            else
                printf("%s -- %s\n\n",s,msg[1]);
        }
        else
        {
            if(ismirr)
                printf("%s -- %s\n\n",s,msg[2]);
            else
                printf("%s -- %s\n\n",s,msg[0]);
        }

    }
    return 0;
}
*/

char mirr(char ch,const char* rev)
{
    if(isalpha(ch)) return rev[ch-'A'];
    else return rev[ch-'0'+25];
}

int main()
{
    freopen("example_3_3_in.txt","r",stdin);
    freopen("example_3_3_out.txt","w",stdout);
    const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    const char* msg[]={"is not a palindrome.","is a regular palindrome.","is a mirrored string.","is a mirrored palindrome."};
    char s[30];
    while(scanf("%s",s)!=EOF)
    {
        int si=strlen(s);
        int ispali=1;
        int ismirr=1;
        for(int i=0;i<(si+1)/2;++i)
        {
            if(s[i]!=s[si-1-i]) ispali=0;
            if(mirr(s[i],rev)!=s[si-1-i]) ismirr=0;
        }
        printf("%s -- %s\n\n",s,msg[ispali+2*ismirr]);
    }
    return 0;
}



//系统可以提交的
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 1010
char mirr(char ch,const char* mirror)
{
    if(isalpha(ch)) return mirror[ch-'A'];
    else return mirror[ch-'0'+25];
}

int main()
{
    const char* meg[]={"is not a palindrome.","is a regular palindrome.","is a mirrored string.","is a mirrored palindrome."};
    const char* mirror="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    char s[maxn];
    while(scanf("%s",s)!=EOF)
    {
        int si=strlen(s);
        int ismirror=1;
        int ispali=1;
        for(int i=0;i<(si+1)/2;++i)
        {
            if(s[i]!=s[si-1-i]) ispali=0;
            if(mirr(s[i],mirror)!=s[si-1-i]) ismirror=0;
        }
        printf("%s -- %s\n\n",s,meg[ispali+2*ismirror]);
    }
    return 0;
}

