#include<stdio.h>
int main()
{
    //1.int����������Сֵ�����ֵ�Ƕ��٣�
    int i=0;
    int Max;
    int Min;
    while(1)
    {
        if(i+1<0)
        {
            Max=i;
            Min=i+1;    //int�����ֵ�Ӹ�1�ͱ����Сֵ��
            break;
        }
        ++i;
    }
    printf("%d\n",Max);
    printf("%d\n",Min);


    //2.double�͸������ܾ�ȷ������λС��?   0.33333333333333331000����ô����16λ
    double a=1.0;
    double b=3.0;
    printf("%.20lf\n",a/b);


    //3.double�͸������������ֵ����С����ֵ�ֱ��Ƕ��٣�
    //�������ִ�е��쳤�ؾã�������û����......ͣ��
    double t=0.0000000000000001;
    for(;t>0;t+=0.0000000000000001)
    {
    }
    printf("%.100lf\n%.100lf\n%.100lf\n",t,t-0.0000000000000001,t-1);




    return 0;
}
