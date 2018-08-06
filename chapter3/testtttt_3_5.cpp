#include<stdio.h>
#include<ctype.h>
#define Len 5

//这个版本是可以提交的
int main()
{
    //freopen("test_3_5_in.txt","r",stdin);
    //freopen("test_3_5_out.txt","w",stdout);
    char s[Len][Len+2];
    int kase=0;
    while(1)
    {
        fgets(s[0],Len+2,stdin);
        if(s[0][0]=='Z')
            break;
        if(kase)
            printf("\n");
        printf("Puzzle #%d:\n",++kase);
        for(int i=1;i<Len;++i)
            fgets(s[i],Len+2,stdin);

        int x;
        int y;
        bool flag=false;
        for(x=0;x<Len;++x)
        {
            for(y=0;y<Len;++y)
            {
                if(!isalpha(s[x][y]))
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
            if(flag)
            {
                switch(order)
                {
                    case 'A':if(x==0) flag=false; else{s[x][y]=s[x-1][y]; s[--x][y]=' ';} break;
                    case 'B':if(x==Len-1) flag=false; else{s[x][y]=s[x+1][y]; s[++x][y]=' ';} break;
                    case 'L':if(y==0) flag=false; else{s[x][y]=s[x][y-1]; s[x][--y]=' ';} break;
                    case 'R':if(y==Len-1) flag=false; else{s[x][y]=s[x][y+1]; s[x][++y]=' ';} break;
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
            //printf("\n");
        }
        else
        {
            printf("This puzzle has no final configuration.\n");
        }
        getchar();
    }
}
