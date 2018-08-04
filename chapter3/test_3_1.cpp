#include<stdio.h>
#define maxn 100

int main()
{
    int n;
    scanf("%d",&n);
    char s[maxn];
    while(n--)
    {
        scanf("%s",s);
        int con=0;
        int seq=0;
        for(int i=0;s[i];++i)
        {
            con+=seq;
            if(s[i]=='X')
            {
                seq=0;
            }
            else
            {
                ++seq;
            }
        }
        con+=seq;
        printf("%d\n",con);
    }
    return 0;
}
