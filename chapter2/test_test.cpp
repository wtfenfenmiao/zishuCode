#include<stdio.h>
//��Ŀ1
/*
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=2*n;i+=2)
    {
        printf("%d\n",i);   //��һ�в����Ļ���һ��ֱ��i*2����
    }
    return 0;
}
*/
//��Ŀ2,�Ҳµ�û���������ͣ����������Ϊi�Ͳ������10......������10.0Ҳ���С���ô��for��������ͣ���Ҫ�ñ��......
int main()
{
    double i;
    for(i=0;i!=10;i+=0.1)
    {
        printf("%.1f\n",i);
    }
    return 0;
}
