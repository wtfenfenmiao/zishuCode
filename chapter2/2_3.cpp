#include<stdio.h>
int main()
{
    //0/785399
    float n=1.0;
    float re=0.0;
    float flag=1.0;
    while(n<=1000001)
    {
        re+=flag/n;
        n+=2;
        flag*=-1.0;
    }
    printf("%f\n",n);
    printf("%f\n",re);

    //验证一下写对了
    double re2=0.0;
    for(int i=0;;++i)
    {
        double term=1.0/(2*i+1);
        if(i%2==0)
            re2+=term;
        else
            re2-=term;
        if(term<0.000001)
            break;
    }
    printf("%f\n",re2);


}
