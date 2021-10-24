#include<iostream>
#include<queue>
using namespace std;

const int maxn = 50 ;


struct node
{
    int data;
    node *lchild;
    node *rchild;
};


int N;// count of nodes
int post[maxn];
int in[maxn];


node *initTree(int postL, int postR,int inL,int inR)
{
    if(postL > postR)
        return NULL;
    node *root = new node;
    root->data = post[postR];
    int k;
    int numOfLeft;
    for(k = inL; k <= inR; k++)
    {
        if(post[postR] == in[k])
        {
            break;
        }
    }
    numOfLeft = k - inL;
    // cout<<root->data<<" ";
    root->lchild = initTree(postL,postL+ numOfLeft -1,inL,k-1);
    root->rchild = initTree(postL+numOfLeft,postR-1,k+1,inR);
    return root;

}

int num = 0;
void layerTraverse(node *root)
{

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *Node = q.front();
        q.pop();
        // cout<<Node->data;
        cout<<Node->data;
        num++;
        if(num<N) cout<<" ";
        if(Node->lchild != NULL) q.push(Node->lchild);
        if(Node->rchild != NULL) q.push(Node->rchild);
        
    }
    
}


int main(int argc, char const *argv[])
{
    cin>>N;
    for(int i =0 ; i<N; i++)
        cin>>post[i];
    for(int i =0 ; i<N; i++)
        cin>>in[i];
    
    node *root = initTree(0,N-1,0,N-1);
    layerTraverse(root);


    return 0;
}
