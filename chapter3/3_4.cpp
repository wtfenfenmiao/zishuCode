#include<stdio.h>
#include<string.h>
int main()
{

    char s[20];
    while(scanf("%s",s)!=EOF)
    {
        int con=0;
        char buff[99];
        for(int abc=100;abc<=999;++abc)
        {
            for(int de=10;de<=99;++de)
            {
                int le=abc*(de/10);
                int ri=abc*(de%10);
                int sum=abc*de;
                sprintf(buff,"%d%d%d%d%d",abc,de,le,ri,sum);   //和printf,fprintf类似，这个sprintf是输出到字符串
                bool flag=true;
                for(int i=0;i<strlen(buff);++i)
                {
                    if(strchr(s,buff[i])==NULL)    //在一个字符串中查找单个字符。在s中查找buff[i]
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%d\n-----\n%d\n\n",++con,abc,de,le,ri,sum);
                }
            }
        }
        printf("The number of solutions = %d\n",con);
    }
    return 0;
}
