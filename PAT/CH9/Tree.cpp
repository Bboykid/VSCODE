#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

node *newNode(int v)
{
    node *Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void search(node *root,int x,int newdata)
{
    if(root == NULL)
        return;
    if(root->data = x)
        root->data = newdata;
    search(root->lchild,x,newdata);
    search(root->rchild,x,newdata);
}

void inorder(node* root)
{
    if(root == NULL)
        return;
    inorder(root->lchild);
    printf("%d\n",root->data);
    inorder(root->rchild);
}

void LayerOrder(node *root)
{
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *now = q.front();
        q.pop();
        printf("%d",now->data); 
       if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
}