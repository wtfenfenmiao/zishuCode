#include<stdio.h>
#define maxn 100000+10
int main()
{
    char s[maxn];
    scanf("%s",s);
    int tot=0;
    for(int i=0;i<s[i]!='\0';i++)
        if(s[i]=='1') tot++;
    printf("%d\n",tot);
}
