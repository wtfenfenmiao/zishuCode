#include<stdio.h>
#include<math.h>
int main()
{
    //ֻ��һ��7744
    //����1������aabb��ʽ�����������ǲ���ƽ����
    for(int a=1;a<=9;++a)
    {
        for(int b=0;b<=9;++b)
        {
            int num=a*1100+b*11;
            int sqrt_num=floor(sqrt(num)+0.5);   //���+0.5��floor�������������룬float��������ֱ����floor���ܻ���������1�����ſ������0.999999999��һfloor����0�ˣ��Եľ͸���ɴ���ˣ���������������ֹ���������
            if(sqrt_num*sqrt_num==num)
                printf("%d\n",num);
        }
    }

    //����2������ƽ����

    for(int i=30;;++i)
    {
        int num2=i*i;
        if(num2<1000)
            continue;
        if(num2>9999)
            break;
        int aa=num2/100;
        int bb=num2%100;
        if((aa/10==aa%10)&&(bb/10==bb%10))
            printf("%d\n",num2);
    }



    return 0;
}
