#include<stdio.h>
#include<math.h>
int main()
{
    //只有一个7744
    //做法1，遍历aabb形式的数，看看是不是平方数
    for(int a=1;a<=9;++a)
    {
        for(int b=0;b<=9;++b)
        {
            int num=a*1100+b*11;
            int sqrt_num=floor(sqrt(num)+0.5);   //这个+0.5再floor作用是四舍五入，float运算有误差，直接用floor可能会错，比如如果1开根号可能算成0.999999999，一floor就是0了，对的就给算成错的了，四舍五入用来防止浮点数误差
            if(sqrt_num*sqrt_num==num)
                printf("%d\n",num);
        }
    }

    //做法2，遍历平方数

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
