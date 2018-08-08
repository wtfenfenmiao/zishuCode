//���ⲻ���ˣ���bug���в������ݾͺ��ˣ��۵Ŀ޳���......

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define gridmax 12
#define maxn 8
bool board[gridmax][gridmax];   //���λ����û������
char qizi[maxn][3];   //��һ�������ӵ����֣�������������
int n;

//��������true����������false


bool isGeneral(int rx,int ry,int bx,int by)   //falseû������true����
{
    if(ry!=by)
        return false;
    for(int i=bx+1;i<rx;++i)
    {
        if(board[i][ry])
            return false;
    }
    return true;
}

bool isChariot(int rx,int ry,int bx,int by)
{
    if((ry!=by)&&(rx!=bx))
        return false;
    if((ry==by)&&(rx==bx))
        return false;     //������
    if(ry==by&&abs(rx-bx)==1)
        return true;
    if(rx==bx&&abs(ry-by)==1)
        return true;
    for(int i=bx+1;i<rx;++i)
    {
        if(board[i][ry])
            return false;
    }
    if(by<ry)
    {
        int t=ry;
        ry=by;
        by=t;
    }
    for(int i=ry+1;i<by;++i)
    {
        if(board[rx][i])
            return false;
    }
    return true;
}


bool isCannon(int rx,int ry,int bx,int by)
{
    if((ry!=by)&&(rx!=bx))
        return false;
    if((ry==by)&&(rx==bx))
        return false;     //������
    int cnt=0;
    for(int i=bx+1;i<rx;++i)
    {
        if(board[i][ry])
            ++cnt;
    }
    if(cnt==1)
        return true;
    if(ry==by)
        return false;
    cnt=0;
    if(by<ry)
    {
        int t=ry;
        ry=by;
        by=t;
    }
    for(int i=ry+1;i<by;++i)
    {
        if(board[rx][i])
            ++cnt;
    }
    if(cnt==1)
        return true;
    return false;
}


bool isHorse(int rx,int ry,int bx,int by)
{
    int xa=rx-bx;
    int ya=ry-by;
    //printf("horse rx=%d ry=%d\n",rx,ry);
    //printf("horse bx=%d by=%d\n",bx,by);
    //printf("horse xa=%d ya=%d\n",xa,ya);
    if(!((abs(xa)==1&&abs(ya)==2)||(abs(xa)==2&&abs(ya)==1)))
        return false;
    if(xa==2)
    {
        if(board[rx-1][ry])
            return false;
    }
    if(xa==-2)
    {
        if(board[rx+1][ry])
            return false;
    }
    if(ya==2)
    {
        if(board[rx][ry-1])
            return false;
    }
    if(ya==-2)
    {
        if(board[rx][ry+1])
            return false;
    }
    return true;

}


bool ifjiangjun(int bx,int by)    //�������ӣ�һ���ܽ�ס���ǽ�ס�ˣ�true
{
    bool flag=false;
    for(int i=0;i<n;++i)
    {
        char thisqizi=qizi[i][0];
        int rx=qizi[i][1]-'0';
        int ry=qizi[i][2]-'0';
        switch(thisqizi)
        {
            case 'G':flag=isGeneral(rx,ry,bx,by);break;
            case 'R':flag=isChariot(rx,ry,bx,by);break;
            case 'H':flag=isHorse(rx,ry,bx,by);break;
            case 'C':flag=isCannon(rx,ry,bx,by);break;
            default:break;
        }
        //printf("bx:%d by:%d qizi:%c flag:%d\n",bx,by,thisqizi,flag);
        if(flag)
            return true;
    }
    return false;
}


int main()
{
    freopen("test_4_1_in.txt","r",stdin);
    int bx,by;
    while(scanf("%d %d %d",&n,&bx,&by)!=EOF&&n!=0)
    {
        //printf("n:%d bx:%d by:%d\n",n,bx,by);
        memset(qizi,0,sizeof(qizi));
        memset(board,0,sizeof(board));
        char qi;
        int x,y;
        for(int i=0;i<n;++i)
        {
            getchar();
            scanf("%c %d %d",&qi,&x,&y);
            //printf("qi:%c x:%d y:%d\n",qi,x,y);
            qizi[i][0]=qi;
            qizi[i][1]=x+'0';
            qizi[i][2]=y+'0';
            board[x][y]=true;
        }
        bool ifalive=false;  //


        if(by-1>=4)
        {
            ifalive=!ifjiangjun(bx,by-1);
            //printf("there1 bx=%d  by=%d  ifalive=%d\n",bx,by-1,ifalive);
        }
        if(!ifalive&&by+1<=6)
        {
            ifalive=!ifjiangjun(bx,by+1);
            //printf("there2 bx=%d  by=%d  ifalive=%d\n",bx,by+1,ifalive);
        }
        if(!ifalive&&bx-1>=1)
        {
            ifalive=!ifjiangjun(bx-1,by);
            //printf("there3 bx=%d  by=%d  ifalive=%d\n",bx-1,by,ifalive);
        }
        if(!ifalive&&bx+1<=3)
        {
            ifalive=!ifjiangjun(bx+1,by);
            //printf("there4 bx=%d  by=%d  ifalive=%d\n",bx+1,by,ifalive);
        }
        printf("%s\n",ifalive?"NO":"YES");
        getchar();
        getchar();
    }
    return 0;
}
