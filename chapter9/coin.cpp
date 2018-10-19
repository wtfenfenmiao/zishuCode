#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

const int maxn=1000;
const int maxcoin=20;
int Smax[maxn];    //��xԪ�����Smax[x]��Ӳ��
int Smin[maxn];    //��xԪ������Smin[x]��Ӳ��
bool ifcom[maxn];    //��xԪ������Ѿ������
int coin[maxcoin];   //�����20��Ӳ��
int n;   //Ҫ�ն���Ԫ


//���仯���������յ㿪ʼ�㣬������Ӳ����
int dpEndMax(int co,vector<int>& coinsave)
{
    //cout<<"now:"<<co<<endl;
    if(ifcom[co])
        return Smax[co];
    ifcom[co]=true;
    int& ans=Smax[co];
    int thissave=-1;
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i])
        {
            int temp=dpEndMax(co-coin[i],coinsave);
            if(temp==-1)
                continue;
            if(ans<temp+1)
            {
                ans=temp+1;
                thissave=i;
            }
        }
    }
    if(thissave!=-1)
        coinsave[co]=coin[thissave];
    //cout<<"co:"<<ans<<endl;
    return ans;
}



//���仯���������յ㿪ʼ�㣬�����ٵ�Ӳ����
int dpEndMin(int co,vector<int>& coinsave)
{
    if(ifcom[co])
        return Smin[co];
    ifcom[co]=true;
    int& ans=Smin[co];
    ans=INT_MAX;
    int thissave=-1;
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i])
        {
            int temp=dpEndMin(co-coin[i],coinsave);
            if(temp==-1)
                continue;
            if(ans>temp+1)
            {
                ans=temp+1;
                thissave=i;
            }
        }
    }
    if(ans==INT_MAX)
        ans=-1;
    if(thissave!=-1)
        coinsave[co]=coin[thissave];
    return ans;
}

//��ӡ�ֵ�����С�ģ����������ķ�������һ�ְ취
void printMax(int co)
{
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i]&&Smax[co]==Smax[co-coin[i]]+1)  //֮ǰд�ɣ�&&Smax[co-coin[i]]!=-1�������õ�����Ŀǰ���������У��ֵ�����С�ģ�����һ������max��Ҫ���������ˣ�Ҫ�������
        {
            cout<<coin[i]<<endl;
            printMax(co-coin[i]);
            break;
        }
    }
}

void printMin(int co)
{
    for(int i=0;i<maxcoin&&coin[i];++i)
    {
        if(co>=coin[i]&&Smin[co]==Smin[co-coin[i]]+1)
        {
            cout<<coin[i]<<endl;
            printMin(co-coin[i]);
            break;
        }
    }
}


//���仯����������㿪ʼ�㣬������Ӳ��������д�ˣ������Ǹ�����
int dpStartMax(int co,vector<int>& coinsave)
{

}

//���仯����������㿪ʼ�㣬�����ٵ�Ӳ��������д�ˣ������Ǹ�����
int dpStrtMin(int co,vector<int>& coinsave)
{

}

//����,�о�����Ӳ�ҵ�coin[]�ô�С�����ź���
void ditui(vector<int>& savemin,vector<int>& savemax)
{
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<maxcoin&&coin[j];++j)
        {
            if(Smax[i]!=-1)
            {
                if(Smax[i+coin[j]]<Smax[i]+1)
                {
                    Smax[i+coin[j]]=Smax[i]+1;
                    savemax[i+coin[j]]=coin[j];
                    //cout<<"max:"<<i+coin[j]<<" "<<coin[j]<<endl;
                }
            }



            if(Smin[i]!=-1)
            {
                if(Smin[i+coin[j]]==-1)
                    Smin[i+coin[j]]=INT_MAX;
                if(Smin[i+coin[j]]>Smin[i]+1)
                {
                    Smin[i+coin[j]]=Smin[i]+1;
                    savemin[i+coin[j]]=coin[j];
                    //cout<<"min:"<<i+coin[j]<<" "<<coin[j]<<endl;
                }
                if(Smin[i+coin[j]]==INT_MAX)
                    Smin[i+coin[j]]=-1;
            }


        }
    }
}



void print_Smax()
{
    for(int i=0;i<=n;++i)
        cout<<i<<" "<<Smax[i]<<endl;
}

void print_Smin()
{
    for(int i=0;i<=n;++i)
        cout<<i<<" "<<Smin[i]<<endl;
}

int main()
{
    freopen("coin_in.txt","r",stdin);
    scanf("%d",&n);
    //cout<<n<<endl;
    memset(coin,0,sizeof(coin));
    int i=0;
    while(scanf("%d",&coin[i++])!=EOF);
    //for(int i=0;i<maxcoin&&coin[i];++i)
    //{
    //    cout<<coin[i]<<endl;
    //}




    memset(Smax,-1,sizeof(Smax));
    Smax[0]=0;    //-1�ǲ����ڡ�0����������ڣ���0Ԫ��Ҫ0��Ӳ�ҡ�������Ӵ�3Ԫ������Ͳ����ڣ�����-1
    memset(ifcom,0,sizeof(ifcom));
    ifcom[0]=true;

    vector<int> coinSaveMax(n,0);
    cout<<"���յ㿪ʼ��������ٸ�Ӳ�ң�"<<dpEndMax(n,coinSaveMax)<<endl;   //����nԪû�չ���Ҫ�㵽0
    cout<<"���յ㿪ʼ��������ٸ�Ӳ�ҷ�����"<<endl;   //����nԪû�չ���Ҫ�㵽0
    int te=n;
    while(te!=0)
    {
        cout<<coinSaveMax[te]<<endl;
        te-=coinSaveMax[te];
    }
    cout<<"���ڶ����㷨��"<<endl;
    printMax(n);
    cout<<endl;
    //print_Smax();


    memset(Smin,-1,sizeof(Smin));
    Smin[0]=0;    //-1�ǲ����ڡ�0����������ڣ���0Ԫ��Ҫ0��Ӳ�ҡ�������Ӵ�3Ԫ������Ͳ����ڣ�����-1
    memset(ifcom,0,sizeof(ifcom));
    ifcom[0]=true;
    vector<int> coinSaveMin(n,0);
    cout<<"���յ㿪ʼ������ٶ��ٸ�Ӳ�ң�"<<dpEndMin(n,coinSaveMin)<<endl;   //����nԪû�չ���Ҫ�㵽0
    cout<<"���յ㿪ʼ������ٶ��ٸ�Ӳ�ҷ�����"<<endl;   //����nԪû�չ���Ҫ�㵽0
    te=n;
    while(te!=0)
    {
        //cout<<"te:"<<te<<endl;
        cout<<coinSaveMin[te]<<endl;
        te-=coinSaveMin[te];
    }
    cout<<"���ٵڶ����㷨��"<<endl;
    printMin(n);
    cout<<endl;
    //print_Smin();


    memset(Smax,0,sizeof(Smax));
    memset(Smax,-1,sizeof(Smax));
    Smax[0]=0;    //-1�ǲ����ڡ�0����������ڣ���0Ԫ��Ҫ0��Ӳ�ҡ�������Ӵ�3Ԫ������Ͳ����ڣ�����-1
    memset(Smin,0,sizeof(Smin));
    memset(Smin,-1,sizeof(Smin));
    Smin[0]=0;    //-1�ǲ����ڡ�0����������ڣ���0Ԫ��Ҫ0��Ӳ�ҡ�������Ӵ�3Ԫ������Ͳ����ڣ�����-1


    vector<int> savemin(n,0);
    vector<int> savemax(n,0);
    ditui(savemin,savemax);
    cout<<Smin[n]<<" "<<Smax[n]<<endl;
    te=n;
    while(te!=0)
    {
        //cout<<"te:"<<te<<endl;
        cout<<savemin[te]<<endl;
        te-=savemin[te];
    }
    cout<<endl;
    te=n;

    while(te!=0)
    {
        //cout<<"te2:"<<te<<endl;
        cout<<savemax[te]<<endl;
        te-=savemax[te];
    }
    cout<<endl;


}
