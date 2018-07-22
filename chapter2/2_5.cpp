//#define LOCAL     //�ô�LOCAL���֣����������ļ��ض���û�����о���ֱ����������������
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
    while(scanf("%d",&x)==1)    //��!=EOFЧ��һ��
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
    //���ļ��ض���
    freopen("2_5_rein.txt","r",stdin);
    freopen("2_5_reout.txt","w",stdout);
    int n=0;
    int Min=INT_MAX;
    int Max=INT_MIN;
    int x;
    int sum=0;
    while(scanf("%d",&x)==1)    //��!=EOFЧ��һ��
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
    //�ļ��ض����local
    #ifdef LOCAL
        freopen("2_5_rein.txt","r",stdin);
        freopen("2_5_reout.txt","w",stdout);
    #endif // LOCAL
    int n=0;
    int Min=INT_MAX;
    int Max=INT_MIN;
    int x;
    int sum=0;
    while(scanf("%d",&x)==1)    //��!=EOFЧ��һ��
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

    //�ļ���û���ض���
    FILE *in,*out;
    in=fopen("2_5_in.txt","rb");
    out=fopen("2_5_out.txt","wb");
    /*    //�����in��out��ֵ�����������У��Ǿͺ�С�ڿ��������һ����
    in=stdin;
    out=stdout;
    */
    int n=0;
    int Min=INT_MAX;
    int Max=INT_MIN;
    int x;
    int sum=0;
    while(fscanf(in,"%d",&x)==1)    //��!=EOFЧ��һ��
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
