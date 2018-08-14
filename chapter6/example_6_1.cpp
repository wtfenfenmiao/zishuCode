//一个map存指令时间
//一个map存变量名
//一个dequeue，成员是queue。指令队列
//一个queue，组织队列

#include<cstdio>
#include<string>
#include<deque>
#include<queue>
#include<map>
#include<iostream>
#include<sstream>
using namespace std;

map<string,int> varmap;

void print(int ID,string str)
{
    stringstream ss(str);
    string temp;
    ss>>temp;
    ss>>temp;
    cout<<ID+1<<": "<<varmap[temp]<<endl;
}

void printvec(vector<queue<string> > vec)
{
    int cnt=0;
    for(int i=0;i<vec.size();++i)
    {
        cout<<"ID:"<<++cnt<<endl;
        int si=vec[i].size();
        for(int j=0;j<si;++j)
        {
            cout<<vec[i].front()<<endl;
            vec[i].push(vec[i].front());
            vec[i].pop();
        }
        cout<<"***************************************************"<<endl;
    }
}

void printqueue(int ID,queue<string> qu)
{
    cout<<"++++++++++++++++++++++++++++++++"<<endl;
    cout<<"ID:"<<ID<<endl;
    int si=qu.size();
    for(int i=0;i<si;++i)
    {
        cout<<qu.front()<<endl;
        qu.push(qu.front());
        qu.pop();
    }
    cout<<"++++++++++++++++++++++++++++++++"<<endl;
}

void give(string str)
{
    stringstream ss(str);
    string var,temp;
    int num;
    ss>>var;
    ss>>temp;
    ss>>num;
    varmap[var]=num;
}

char whichorder(string order)
{
    int cnt=0;
    stringstream ss(order);
    string str;
    while(ss>>str) ++cnt;
    if(cnt==3)
        return 'v';
    else
        return order[0];

}
int main()
{
    freopen("example_6_1_in.txt","r",stdin);
    int n;
    int time[5]={0};
    int Q;  //每次最多运行Q个单位时间
    bool isBlock=false;
    vector<queue<string> > orderID;
    deque<int>  orderQueue;
    queue<int>  blockQueue;

    //cin>>n>>give>>print>>lock>>unlock>>endd>>Q;
    cin>>n>>time[0]>>time[1]>>time[2]>>time[3]>>time[4]>>Q;
    getchar();
    //cout<<" "<<n<<" "<<time[0]<<" "<<time[1]<<" "<<time[2]<<" "<<time[3]<<" "<<time[4]<<" "<<Q<<endl;
    while(n--)
    {
        queue<string> order;
        string strtemp;
        while(1)
        {
            getline(cin,strtemp);
            if(strtemp=="end")
                break;
            order.push(strtemp);
        }
        order.push(strtemp);
        orderID.push_back(order);
        orderQueue.push_back(orderID.size()-1);
    }

    //printvec(orderID);
    while(!orderQueue.empty())
    {
        int thisorderID=orderQueue.front();
        orderQueue.pop_front();
        int restTime=Q;
        bool ifIns=true;  //这个是否插回双向队列
        while(1)
        {
            bool ifbreak=false;
            string thisorder=orderID[thisorderID].front();
            //cout<<"thisorder:"<<thisorderID<<"   "<<thisorder<<endl;
            switch(whichorder(thisorder))
            {
                case 'p':if(time[1]>restTime) {ifbreak=true;break;} print(thisorderID,thisorder); restTime-=time[1]; break;
                case 'l':if(time[2]>restTime) {ifbreak=true;break;} if(isBlock){blockQueue.push(thisorderID);ifbreak=true;ifIns=false;break;} restTime-=time[2];isBlock=true;break;
                case 'u':if(time[3]>restTime) {ifbreak=true;break;} isBlock=false;if(!blockQueue.empty()){orderQueue.push_front(blockQueue.front());blockQueue.pop();}restTime-=time[3];break;
                case 'e':if(time[4]>restTime) {ifbreak=true;break;} restTime-=time[4];ifIns=false;ifbreak=true;break;
                case 'v':if(time[0]>restTime) {ifbreak=true;break;} give(thisorder); restTime-=time[0];break;
                default:break;
            }
            if(ifbreak)
                break;
            //cout<<"truepop"<<endl;
            //printqueue(thisorderID,orderID[thisorderID]);
            orderID[thisorderID].pop();
            //printqueue(thisorderID,orderID[thisorderID]);

        }
        if(ifIns)
            orderQueue.push_back(thisorderID);
    }
    return 0;
}
