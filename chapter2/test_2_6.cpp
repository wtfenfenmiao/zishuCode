#include<stdio.h>
//version1 我写的，有点，麻烦......
/*
bool thistrue(int first)
{
    int a=first/100;
    int b=(first%100)/10;
    int c=first%10;
    if(a==b||a==c||b==c||a==0||b==0||c==0)
        return false;
    return true;
}

bool eachtrue(int first,int second)
{
    int a=first/100;
    int b=(first%100)/10;
    int c=first%10;
    int d=second/100;
    int e=(second%100)/10;
    int f=second%10;
    if(a==0||b==0||c==0||d==0||e==0||f==0)
        return false;
    if(a==d||a==e||a==f)
        return false;
    if(b==d||b==e||b==f)
        return false;
    if(c==d||c==e||c==f)
        return false;
    return true;
}
int main()
{
    for(int first=123;first<=329;++first)
    {
        if(!thistrue(first))
            continue;
        int second=first*2;
        if(!thistrue(second)||!eachtrue(first,second))
            continue;
        int third=first*3;
        if(!thistrue(third)||!eachtrue(first,third)||!eachtrue(second,third))
            continue;
        printf("%d %d %d\n",first,second,third);
    }
    return 0;

}
*/


//version2 哈希表
int main()
{
    int ha[10]={0};
    for(int first=123;first<=329;++first)
    {
        int s=0;
        int second=first*2;
        int third=first*3;
        ha[first/100]=ha[(first%100)/10]=ha[first%10]=1;
        ha[second/100]=ha[(second%100)/10]=ha[second%10]=1;
        ha[third/100]=ha[(third%100)/10]=ha[third%10]=1;
        for(int i=1;i<=9;++i)
        {
            s+=ha[i];
            ha[i]=0;
        }
        if(s==9)
            printf("%d %d %d\n",first,second,third);
    }
    return 0;
}



