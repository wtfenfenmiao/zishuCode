#include<stdio.h>
int main()
{
    freopen("example_3_1_in.txt","r",stdin);
    freopen("example_3_1_out.txt","w",stdout);
    char c;
    bool flag=true;
    //���while��ĸ�ֵ����ѧϰһ��
    while((c=getchar())!=EOF)     //������scanf�ˣ�scanf�����ո�ͻس���ͣ�¡���������fgetc(fin)
    {
        if(c=='"')
        {
          c=flag?'@':'$';
          flag=!flag;
        }
        printf("%c",c);
    }
    printf("\n");
    return 0;
}
