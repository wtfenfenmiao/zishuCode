//求圆柱的体积
#include<stdio.h>
#include<math.h>
int main()
{
	const double pi=acos(-1.0);
	double r,h,s;
	scanf("%lf%lf",&r,&h);
	s=pi*r*r*2+2*pi*r*h;
	printf("Aera=%.3f\n",s);
	return 0;
}