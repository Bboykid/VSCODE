#include<iostream>
#include<queue>
using namespace std;

const int maxn = 30;

//结点结构
typedef struct BiNode
{
    int data;
    BiNode *left;
    BiNode *right;
}BiNode,*BiTree;

int N;
//后序及中序遍历序列
int post[maxn];
int in[maxn];

BiTree initTree(int postL,int postR, int inL, int inR)
{
    //判断后序遍历序列是否结束
    if(postL > postR)
        return NULL;
    BiNode *root = new BiNode;
    root->data = post[postR];
    int k;//k 保存根节点中序遍历序列的下标
    //GetK
    for( k=inL; k<=inR ;k++)
    {
        if( in[k]==post[postR] )
            break;
    }
    //划分子树的子序列
    int leftNum = k - inL;//左子树的结点个数
    root->left = initTree(postL,postL+leftNum-1, inL, inL + leftNum -1);
    root->right = initTree( postL +leftNum, postR-1, k+1,inR );

    return root;
}

int num = 0;

void LevelTraverse(BiTree root)
{
    BiNode *temp;
    queue<BiNode *> Q;
    Q.push(root);
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        cout<<temp->data;
        if(num<N)
        {
            cout<<" ";
        }
        if(temp->left!=NULL)
            Q.push(temp->left);
        if(temp->right!=NULL)
            Q.push(temp->right);
    }
}

int main(int argc, char const *argv[])
{
    cin>>N;
    for(int i=0;i<N;i++ )
    {
        cin>>post[i];
    }
    for(int i=0;i<N;i++ )
    {
        cin>>in[i];
    }
    BiTree root = initTree(0,N-1,0,N-1);
    LevelTraverse(root);

    return 0;
}
