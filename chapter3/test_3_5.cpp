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
         //fgets读取一行，用法：fgets (buf, n, fp)。读取不超过n-1个字符（这个字符算上了\n，读算上\n是n-1个字符，然后还要加上\0才是n个，这个一定算好了，要不都是坑啊啊啊）。这个fgets读到\n就停了，然后接着加一个\0。
         //所以对于一行有num个字符（不算\n），留的n至少得是n+2,保证fgets能看到\n，并且能塞\0
         //n<=num,
         fgets(s[0],Len+2,stdin);
         //fgets,fgets( ,n, ),读入的字符数是n-1,\n也要算在内，因为这个fgets是读到\n停的，如果不把\n的地方留出来，也就是如果fgets没来得及读到\n地方就不够了，就补\0了，那下次还会读\n...所以这里是5个字母，一个\n，然后再加一个，就要是7
         if(s[0][0]=='Z')
            break;
         printf("Puzzle #%d:\n",++kase);
         //if(s[0][Len-1]=='\n')
         //   s[0][Len-1]='\0';    //这个还是fgets的问题，如果这一行是ABCD这种，空白正好是最后一个，后面直接接\n，那这个第五个格就是\n不是空白了
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
                if(!isalpha(s[x][y]))   //之前用的==' '，就不行，因为有一个\n，fgets的锅
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
         getchar();    //换新例子的时候有个回车，需要读了，要不fgets就会读掉这个回车，然后就乱套了......
     }
     return 0;
 }
