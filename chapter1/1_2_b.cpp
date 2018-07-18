//三位数反转
#include<stdio.h>

int main()
{
	int m,n;
	scanf("%d",&m);
	n=(m%10)*100+(m/10%10)*10+m/100;
	printf("%d\n",n);
	//printf("%03d",n);     //这个可以把25这种输出成025
	return 0;
}