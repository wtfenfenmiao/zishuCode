//这个代码的输出写的不好。其实可以函数只返回true或者false，然后在main输出。这样就要弄一些全局变量了。
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;


struct Node
{
    Node* left;
    Node* right;
    bool given;
    int val;
    Node(Node* left=NULL,Node* right=NULL,int val=0,bool given=false):left(left),right(right),val(val),given(given){};
};

void BFS(Node* root)
{
    bool flag=true;
    vector<int> save;
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        int si=qu.size();
        for(int i=0;i<si;++i)
        {
            Node* temp=qu.front();
            qu.pop();
            if(temp->val==0)
            {
                flag=false;
                break;
            }
            save.push_back(temp->val);
            if(temp->left)
                qu.push(temp->left);
            if(temp->right)
                qu.push(temp->right);
        }
        if(!flag)
            break;
    }
    if(!flag)
        cout<<"not complete"<<endl;
    else
    {
        int i;
        for(i=0;i<save.size()-1;++i)
        {
            cout<<save[i]<<" ";
        }
        cout<<save[i]<<endl;
    }
}

void findorder(string pa,int& val,string& order)
{
    int i;
    for(i=0;i<pa.size();++i)
    {
        if(pa[i]==',')
        {
            val=atoi(pa.substr(1,i-1).c_str());
            break;
        }
    }
    order=pa.substr(i+1,pa.size()-i-2);

}

bool inser(Node* root,int val,string order)
{
    for(int i=0;i<order.size();++i)
    {
        if(order[i]=='L')
        {
            if(!(root->left))
            {
                Node* left=new(Node);
                root->left=left;
            }
            root=root->left;
        }
        else if(order[i]=='R')
        {
            if(!(root->right))
            {
                Node* right=new(Node);
                root->right=right;
            }
            root=root->right;
        }
    }
    if(root->given)
        return false;   //插入失败
    root->val=val;
    root->given=true;
    return true;
}

void remov(Node* root)
{
    if(root==NULL)
        return;
    remov(root->left);
    remov(root->right);
    delete root;
}
int main()
{
    //freopen("example_6_7_in.txt","r",stdin);
    while(1)
    {
        string pa;
        Node* root=new(Node);
        bool flag=false;
        bool suc=true;
        while(cin>>pa)
        {
            //cout<<pa<<endl;
            flag=true;
            if(pa=="()")
                break;
            if(!suc)
                continue;
            int val=0;
            string order="";
            findorder(pa,val,order);
            suc=inser(root,val,order);   //是否成功插入
            if(!suc)
                continue;
        }
        if(!flag)
        {
            remov(root);
            break;
        }
        if(suc)
            BFS(root);
        else
            cout<<"not complete"<<endl;
        remov(root);
        //理论上这里应该再来个销毁树。
    }
    return 0;
}
