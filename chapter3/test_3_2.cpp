#include<stdio.h>
#include<ctype.h>
#define maxn 105          //¸÷ÖÖÐ¡bug°¡......
int main()
{
    double mol[26]={0};
    mol['C'-'A']=12.01;
    mol['H'-'A']=1.008;
    mol['O'-'A']=16.00;
    mol['N'-'A']=14.01;

    int n;
    char s[maxn];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        char preAlpha=s[0];
        int i=1;
        int prenum=0;
        double sum=0.0;
        while(s[i])
        {
            if(isalpha(s[i]))
            {
                sum+=mol[preAlpha-'A']*(prenum==0?1:prenum);
                preAlpha=s[i];
                prenum=0;
            }
            else
            {
                prenum=prenum*10+s[i]-'0';
            }
            ++i;
        }
        sum+=mol[preAlpha-'A']*(prenum==0?1:prenum);

        printf("%.3f\n",sum);
    }
    return 0;
}
