/*
//��д�ġ�������Щ�鷳����һ�������ѵ���±�������ڲ��������ܴ�1��ʼ�ʹ�1��ʼ��.....
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 22
bool flag[maxn];   //��ʼ��Ϊfalse����ȥһ��trueһ��
int kbegin;
int mbegin;
int left;



void findout(int n,int k,int m)
{
    int temp=k;
    while(temp--)
    {
        while(flag[(kbegin+1)%n])
        {
            kbegin=(kbegin+1)%n;
        }
        kbegin=(kbegin+1)%n;
    }

    temp=m;
    while(temp--)
    {
        while(flag[(mbegin+n-1)%n])
        {
            mbegin=(mbegin+n-1)%n;
        }
        mbegin=(mbegin+n-1)%n;
    }
    if(kbegin==mbegin)
    {
        printf("%3d",mbegin+1);
        flag[mbegin]=true;
        --left;
    }
    else
    {
        printf("%3d%3d",kbegin+1,mbegin+1);
        flag[mbegin]=true;
        flag[kbegin]=true;
        left-=2;
    }
}

int main()
{
    //freopen("example_4_3_in.txt","r",stdin);
    //freopen("example_4_3_out.txt","w",stdout);
    int n,k,m;
    while(scanf("%d %d %d",&n,&k,&m)!=EOF&&n!=0)
    {
        memset(flag,0,sizeof(flag));
        left=n;
        kbegin=n-1;
        mbegin=0;
        while(1)
        {
            findout(n,k,m);
            if(left)
                printf(",");
            else
                break;
        }
        printf("\n");
    }
}
*/

//�����˼·��˼·һ���������������ˡ��������ˣ�����Ҳ�������ˡ�
//ȫ�ֱ���Ҫ���ã�ҲҪ�����á����پ���
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define maxn 30
bool flag[maxn];
int n,k,m;


int go(int start,int t,int d)
{
    while(t--)
    {
        do{
            start=(start+n-1+d)%n+1;
        }while(flag[start]);
    }
    return start;
}


int main()
{
    while(scanf("%d %d %d",&n,&k,&m)!=EOF&&n!=0)
    {
        memset(flag,0,sizeof(flag));
        int left=n;
        int p=n;
        int q=1;
        while(left)
        {
            p=go(p,k,1);
            q=go(q,m,-1);
            printf("%3d",p);
            --left;
            if(q!=p)
            {
                printf("%3d",q);
                --left;
            }
            flag[p]=flag[q]=true;
            if(left)
                printf(",");
        }
        printf("\n");
    }
    return 0;
}
