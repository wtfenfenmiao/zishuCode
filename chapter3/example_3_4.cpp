#include<stdio.h>
#define maxn 1010
int number[maxn];
int guess[maxn];

int main()
{
    freopen("example_3_4_in.txt","r",stdin);
    freopen("example_3_4_out.txt","w",stdout);
    int num;
    int con=0;
    while(scanf("%d",&num)!=EOF&&num!=0)
    {
        printf("Game %d:\n",++con);
        int conNum[10]={0};
        for(int i=0;i<num;++i)
        {
            scanf("%d",&number[i]);
            ++conNum[number[i]];
        }
        while(1)
        {
            int conGuess[10]={0};
            int A=0;
            int B=0;
            for(int i=0;i<num;++i)
            {
                scanf("%d",&guess[i]);
                if(number[i]==guess[i]) ++A;
                ++conGuess[guess[i]];
            }
            if(guess[0]==0)
                break;
            for(int i=1;i<=9;++i)
            {
                B+=conNum[i]>conGuess[i]?conGuess[i]:conNum[i];
            }
            B-=A;
            printf("(%d,%d)\n",A,B);

        }
    }
    return 0;
}
