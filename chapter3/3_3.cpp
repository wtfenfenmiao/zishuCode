#include<stdio.h>
#include<string.h>
#define maxn 20
int block[maxn][maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {

        memset(block,0,sizeof(block));
        //int num=0;
        //int i=0;
        //int j=n-1;
        //block[i][j]=++num;
        int i,j,num;
        num=block[i=0][j=n-1]=1;    //�����
        while(num<n*n)
        {
            while(i+1<n&&block[i+1][j]==0)   block[++i][j]=++num;    //���жϣ����ƶ��������Ų�˲������ٺ��ˣ����۱Ƚϴ󡣲������ж�
            while(j-1>=0&&block[i][j-1]==0)  block[i][--j]=++num;
            while(i-1>=0&&block[i-1][j]==0)  block[--i][j]=++num;
            while(j+1<n&&block[i][j+1]==0)   block[i][++j]=++num;
        }
        for(int k=0;k<n;++k)
        {
            for(int l=0;l<n;++l)
            {
                printf("%3d",block[k][l]);
            }
            printf("\n");
        }
    }
    return 0;
}
