#include<stdio.h>
int main()
{
    freopen("example_3_4_in.txt","r",stdin);
    freopen("example_3_4_out.txt","w",stdout);
    char c;
    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";   //���峣����������ָ����С�������������
    while((c=getchar())!=EOF)
    {
        int i;
        for(i=1;s[i]&&s[i]!=c;++i);
        if(s[i])
            putchar(s[i-1]);
        else
            putchar(c);
    }
    return 0;
}


//�����ύ��
#include<stdio.h>

int main()
{
    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";   //�����������ǳ������顣���һ����\0���������ж�
    char c;
    while((c=getchar())!=EOF)
    {
        int i;
        for(i=0;s[i]&&s[i]!=c;++i);
        if(s[i]) printf("%c",s[i-1]);     //print(s[i-1])����
        else printf("%c",c);
    }
    return 0;
}

