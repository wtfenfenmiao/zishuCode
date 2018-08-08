#include<stdio.h>
#include<string.h>
int listindex[6][6]={{1,2,4,5,3,6},{2,4,1,3,6,5},{3,2,1,5,6,4},{4,2,6,5,1,3},{5,4,6,3,1,2},{6,2,3,5,4,1}};
char left[8];
char right[8];
char total[15];


bool isSame(int leftidx,int rightidx,int inIdx)
{
    //printf("leftIndex:");
    //for(int i=0;i<6;++i)
    //    printf("%d",listindex[leftidx][i]);
    //printf("\n");
    //printf("rightIndex:");
    //for(int i=0;i<6;++i)
    //    printf("%d",listindex[rightidx][i]);
    //printf("\n");
    int l=listindex[leftidx][0];
    int r=listindex[rightidx][0];
    //printf("l:%d r:%d leftcolor:%c  rightcolor:%c\n",l,r,left[l],right[r]);
    if(left[l]!=right[r])
        return false;
    l=listindex[leftidx][5];
    r=listindex[rightidx][5];
    //printf("l:%d r:%d leftcolor:%c  rightcolor:%c\n",l,r,left[l],right[r]);
    if(left[l]!=right[r])
        return false;
    for(int i=0;i<4;++i)
    {
        l=listindex[leftidx][i+1];
        r=listindex[rightidx][((i+inIdx)%4)+1];
        //printf("l:%d r:%d leftcolor:%c  rightcolor:%c\n",l,r,left[l],right[r]);
        if(left[l]!=right[r])
            return false;
    }
    return true;
}


int main()
{
    //freopen("test_4_4_in.txt","r",stdin);
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    while(scanf("%s",total)!=EOF)
    {
        left[0]='0';
        right[0]='0';
        for(int i=0;i<6;++i)
        {
            left[i+1]=total[i];
            right[i+1]=total[i+6];
        }
        left[7]='\0';
        right[7]='\0';
        //printf("left:%s   right:%s\n",left,right);
        bool flag=false;
        for(int rightidx=0;rightidx<6;++rightidx)
        {
            for(int inIdx=0;inIdx<4;++inIdx)
            {
                //printf("rightidx:%d   inIdx:%d\n",rightidx,inIdx);
                if(isSame(0,rightidx,inIdx))
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        printf("%s\n",flag?"TRUE":"FALSE");

    }
    return 0;
}

