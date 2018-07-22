//#define LOCAL     //用带LOCAL这种，有这行是文件重定向，没有这行就是直接在命令行里敲了
#include<stdio.h>
#include<limits.h>
int main()
{
    /*
    //naive way
    int n=0;
    int Min=INT_MAX;
    int Max=INT_MIN;
    int x;
    int sum=0;
    while(scanf("%d",&x)==1)    //和!=EOF效果一样
    {
        sum+=x;
        if(x<Min)
            Min=x;
        if(x>Max)
            Max=x;
        ++n;
    }
    printf("%d %d %.3f\n",Min,Max,(double)sum/n);
    */

    /*
    //用文件重定向
    freopen("2_5_rein.txt","r",stdin);
    freopen("2_5_reout.txt","w",stdout);
    int n=0;
    int Min=INT_MAX;
    int Max=INT_MIN;
    int x;
    int sum=0;
    while(scanf("%d",&x)==1)    //和!=EOF效果一样
    {
        sum+=x;
        if(x<Min)
            Min=x;
        if(x>Max)
            Max=x;
        ++n;
    }
    printf("%d %d %.3f\n",Min,Max,(double)sum/n);
    */

    /*
    //文件重定向加local
    #ifdef LOCAL
        freopen("2_5_rein.txt","r",stdin);
        freopen("2_5_reout.txt","w",stdout);
    #endif // LOCAL
    int n=0;
    int Min=INT_MAX;
    int Max=INT_MIN;
    int x;
    int sum=0;
    while(scanf("%d",&x)==1)    //和!=EOF效果一样
    {
        sum+=x;
        if(x<Min)
            Min=x;
        if(x>Max)
            Max=x;
        ++n;
    }
    printf("%d %d %.3f\n",Min,Max,(double)sum/n);
    */

    //文件，没有重定向
    FILE *in,*out;
    in=fopen("2_5_in.txt","rb");
    out=fopen("2_5_out.txt","wb");
    /*    //如果把in和out赋值成下面这两行，那就和小黑框输入输出一样了
    in=stdin;
    out=stdout;
    */
    int n=0;
    int Min=INT_MAX;
    int Max=INT_MIN;
    int x;
    int sum=0;
    while(fscanf(in,"%d",&x)==1)    //和!=EOF效果一样
    {
        sum+=x;
        if(x<Min)
            Min=x;
        if(x>Max)
            Max=x;
        ++n;
    }
    fprintf(out,"%d %d %.3f\n",Min,Max,(double)sum/n);
    fclose(in);
    fclose(out);






    return 0;
}
