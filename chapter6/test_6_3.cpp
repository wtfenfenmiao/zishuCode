#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;


string pre;
string mid;

struct Node
{
    Node* left;
    Node* right;
    char val;
    Node(Node* left=NULL,Node* right=NULL,char val=' '):left(left),right(right),val(val){}
};

Node* buildTree(int ps,int pd,int ms,int md)
{
    if(ps>pd)
        return NULL;
    Node* root=new(Node);
    root->val=pre[ps];
    int midroot;
    for(midroot=ms;midroot<=md;++midroot)
    {
        if(mid[midroot]==root->val)
            break;
    }
    root->left=buildTree(ps+1,ps+midroot-ms,ms,midroot-1);
    root->right=buildTree(ps+midroot-ms+1,pd,midroot+1,md);
    return root;
}

void after(Node* root)
{
    if(root==NULL)
        return;
    after(root->left);
    after(root->right);
    cout<<root->val;
}


int main()
{
    //freopen("test_6_3_in.txt","r",stdin);
    while(cin>>pre)
    {
        cin>>mid;
        Node* root;
        root=buildTree(0,pre.size()-1,0,mid.size()-1);
        after(root);
        cout<<endl;
    }
    return 0;
}
