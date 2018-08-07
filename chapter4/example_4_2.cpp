/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 10000
char compu[maxn];
char guess[maxn];
int left;
int wrong;
bool win;
bool lose;

void gue(char ch)
{
    bool flag=true;
    for(int i=0;compu[i];++i)
    {
        if(ch==compu[i])
        {
            compu[i]=' ';
            --left;
            flag=false;
        }
    }
    //printf("%s\n",compu);
    //printf("%d\n",left);
    if(flag)
        ++wrong;
    if(left==0)
        win=true;
    if(wrong==7)
        lose=true;

}


int main()
{
    //freopen("example_4_2_in.txt","r",stdin);
    //freopen("example_4_2_out.txt","w",stdout);
    int rnd;
    while(scanf("%d",&rnd)!=EOF&&rnd!=-1)
    {
        printf("Round %d\n",rnd);
        scanf("%s",compu);
        scanf("%s",guess);
        left=strlen(compu);
        wrong=0;
        win=false;
        lose=false;

        for(int i=0;guess[i];++i)
        {
            //printf("%c\n",guess[i]);
            gue(guess[i]);
            if(win||lose)
                break;
        }
        printf("%s\n",win?"You win.":(lose?"You lose.":"You chickened out."));
    }
    return 0;
}
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 10000
char compu[maxn];
char guess[maxn];
int left;
int wrong;
bool win;
bool lose;


void gue(char ch)
{
    bool flag=true;
    for(int i=0;compu[i];++i)
    {
        if(ch==compu[i])
        {
            compu[i]=' ';
            --left;
            flag=false;
        }
    }
        if(flag)
            ++wrong;
        if(left==0)
            win=true;
        if(wrong==7)
            lose=true;
}


int main()
{
    //freopen("example_4_2_in.txt","r",stdin);
    //freopen("example_4_2_out.txt","w",stdout);
    int rnd;
    while(scanf("%d",&rnd)!=EOF&&rnd!=-1)
    {
        printf("Round %d\n",rnd);
        scanf("%s",compu);
        scanf("%s",guess);
        left=strlen(compu);
        wrong=0;
        win=false;
        lose=false;
        for(int i=0;guess[i];++i)
        {
            gue(guess[i]);
            if(win||lose)
                break;
        }
        printf("%s\n",win?"You win.":(lose?"You lose.":"You chickened out."));
    }
    return 0;
}
























