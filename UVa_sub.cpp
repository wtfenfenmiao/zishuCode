#include<cstdio>

//һ������ջ�ڴ�ָ��Ĵ���䷶�����л�ֹͣ����
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
