#include<stdio.h>
#include<ctype.h>
#define Len 5
 int main()
 {
    //freopen("test_3_5_in.txt","r",stdin);
    //freopen("test_3_5_out.txt","w",stdout);
    char s[Len][Len];
    int kase=0;
     while(1)
     {
         //fgets��ȡһ�У��÷���fgets (buf, n, fp)����ȡ������n-1���ַ�������ַ�������\n��������\n��n-1���ַ���Ȼ��Ҫ����\0����n�������һ������ˣ�Ҫ�����ǿӰ������������fgets����\n��ͣ�ˣ�Ȼ����ż�һ��\0��
         //���Զ���һ����num���ַ�������\n��������n���ٵ���n+2,��֤fgets�ܿ���\n����������\0
         //n<=num,
         fgets(s[0],Len+2,stdin);
         //fgets,fgets( ,n, ),������ַ�����n-1,\nҲҪ�����ڣ���Ϊ���fgets�Ƕ���\nͣ�ģ��������\n�ĵط���������Ҳ�������fgetsû���ü�����\n�ط��Ͳ����ˣ��Ͳ�\0�ˣ����´λ����\n...����������5����ĸ��һ��\n��Ȼ���ټ�һ������Ҫ��7
         if(s[0][0]=='Z')
            break;
         printf("Puzzle #%d:\n",++kase);
         //if(s[0][Len-1]=='\n')
         //   s[0][Len-1]='\0';    //�������fgets�����⣬�����һ����ABCD���֣��հ����������һ��������ֱ�ӽ�\n�����������������\n���ǿհ���
         for(int i=1;i<Len;++i)
         {
             fgets(s[i],Len+2,stdin);
            //if(s[i][Len-1]=='\n')
            //s[i][Len-1]='\0';
         }

/*
        for(int i=0;i<Len;++i)
        {
            //printf("there\n");
            for(int j=0;j<Len-1;++j)
            {

                printf("%c ",s[i][j]);
            }
            printf("%c\n",s[i][Len-1]);
        }
        printf("\n");
*/
        int x;
        int y;
        bool flag=false;
        for(x=0;x<Len;++x)
        {
            for(y=0;y<Len;++y)
            {
                if(!isalpha(s[x][y]))   //֮ǰ�õ�==' '���Ͳ��У���Ϊ��һ��\n��fgets�Ĺ�
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }

         char order;
         while((order=getchar())!=EOF&&order!='0')
         {
             //printf("%c",order);
             //printf("%d",flag);
             //printf("\n");
             if(flag)
             {
                 switch (order)
                {
                    case 'A': if(x==0)flag=false;  else {s[x][y]=s[x-1][y]; s[--x][y]=' ';} break;
                    case 'B': if(x==Len-1)flag=false;  else {s[x][y]=s[x+1][y]; s[++x][y]=' ';} break;
                    case 'L': if(y==0)flag=false;  else {s[x][y]=s[x][y-1]; s[x][--y]=' ';} break;
                    case 'R': if(y==Len-1)flag=false;  else {s[x][y]=s[x][y+1]; s[x][++y]=' ';} break;
                    default:break;
                }
             }

         }

         if(flag)
         {
             for(int i=0;i<Len;++i)
             {
                 for(int j=0;j<Len-1;++j)
                 {
                     printf("%c ",s[i][j]);
                 }
                 printf("%c\n",s[i][Len-1]);
             }
             printf("\n");
         }
         else
         {
             printf("This puzzle has no final configuration.\n\n");
         }
         getchar();    //�������ӵ�ʱ���и��س�����Ҫ���ˣ�Ҫ��fgets�ͻ��������س���Ȼ���������......
     }
     return 0;
 }
