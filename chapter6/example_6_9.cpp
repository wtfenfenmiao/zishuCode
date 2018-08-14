/*
#include<iostream>
#include<cstdio>

using namespace std;


struct Node
{
    Node* left;
    Node* right;
    int leftD;
    int rightD;
    int val;
    Node(Node* left=NULL,Node* right=NULL,int leftD=0,int rightD=0,int val=0):left(left),right(right),leftD(leftD),rightD(rightD),val(val){}

};


void buildTree(Node *root)
{
    int wl,dl,wr,dr;
    cin>>wl>>dl>>wr>>dr;
    //cout<<"左重："<<wl<<"左长："<<dl<<"右重："<<wr<<"右长："<<dr<<endl;
    Node* left=new(Node);
    Node* right=new(Node);
    left->val=wl;
    right->val=wr;
    root->left=left;
    root->right=right;
    root->leftD=dl;
    root->rightD=dr;
    if(!left->val)
        buildTree(left);
    if(!right->val)
        buildTree(right);
}

bool findresult(Node* root,int& sum)
{
    //cout<<"thisroot:"<<root->val<<endl;
    //cout<<"thissum:"<<sum<<endl<<endl;
    if(!root->left&&!root->right)
    {
        sum+=root->val;
        return true;
    }
    int temp=sum;
    bool l=findresult(root->left,sum);
    int lw=sum;

    sum=temp;
    bool r=findresult(root->right,sum);
    int rw=sum;
    //cout<<"root:"<<root->val<<" "<<root->leftD<<" "<<root->rightD<<endl;
    //cout<<"lw:"<<lw<<endl;
    //cout<<"rw:"<<rw<<endl<<endl;
    if(l&&r&&lw*root->leftD==rw*root->rightD)
    {
        sum=root->val+lw+rw;
        return true;
    }
    return false;
}
int main()
{
    //freopen("example_6_9_in.txt","r",stdin);
    int kase;
    scanf("%d",&kase);
    getchar();
    getchar();
    int cnt=0;
    while(kase--)
    {
        if(cnt++)
        {
            cout<<endl;
        }
        Node* root=new(Node);
        root->val=0;
        buildTree(root);
        int sum=0;
        bool re=findresult(root,sum);
        printf(re?"YES\n":"NO\n");
    }
    return 0;
}
*/

//别人家简洁的代码

#include<cstdio>
#include<iostream>

using namespace std;

bool solve(int &W)
{
    bool lt=true;
    bool rt=true;
    int lw,rw,ld,rd;
    cin>>lw>>ld>>rw>>rd;
    if(!lw) lt=solve(lw);
    if(!rw) rt=solve(rw);
    W=lw+rw;
    return lt&&rt&&lw*ld==rw*rd;
}
int main()
{
    //freopen("example_6_9_in.txt","r",stdin);
    int kase;
    int W=0;
    scanf("%d",&kase);
    while(kase--)
    {
        if(solve(W))
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        if(kase)
            cout<<endl;
    }
    return 0;
}
