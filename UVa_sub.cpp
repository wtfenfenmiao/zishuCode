#include<cstdio>

//一个返回栈内存指针的错误典范，运行会停止工作
int* test()
{
    int *a;
    *a=7;
    return a;
}

int main()
{
    int* a;
    a=test();
    printf("%d\n",*a);
    return 0;
}
