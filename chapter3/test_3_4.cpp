#include<stdio.h>
#include<string.h>
#define maxn 120
//�����벻Ҫ��#define LOCAL���֣������ˣ�
int main()
{
    int n;
    scanf("%d",&n);
    char s[maxn];
    while(n--)
    {
        scanf("%s",s);
        int si=strlen(s);
        int rek;
        int i;
        for(rek=1;rek<=si;++rek)
        {
            if(si%rek!=0)
                continue;
            for(i=rek;i<si;++i)
            {
                if(s[i]!=s[i%rek])
                    break;
            }
            if(i==si)
                break;
        }
        printf("%d\n",rek);
        if(n)
            printf("\n");
    }
}
