#define Elemtype char

typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


void Visit(BiTree T);

/**
 * @brief 遍历
 * 
 */

//递归形式

//先序遍历
void PreOrder(BiTree T)
{
    if(T!=NULL)
    {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BiTree T)
{
    if( T!=NULL )
    {
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BiTree T)
{
    if( T!=NULL )
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);       
    }
}

/**
 * @brief 遍历的非递归算法
 * 
 * 中序遍历：
 * 利用栈：
 * 循环：
 *      当前结点存在，入栈
 *      当前结点的左孩子存在时，左孩子入栈
 *      左孩子不存在时，栈顶元素出栈，访问，检查栈顶元素的右孩子回到第一步,直到栈空
 */
void InOrder2(BiTree T)
{
    BiTree p = T;
    InitStack(S);

    while( p!=NULL || !IsEmpty(S) )//栈非空或者p存在时循环，也就是当栈空且p不存在时才结束
    {
        if(p!=NULL)
        {
            Push(S,p);
            p = p->lchild;
        }
        else
        {
            Pop(S,p);
            Visit(p);
            p = p->rchild;
        }
    }
}


//层次遍历
void LawyerOrder(BiTree T)
{
    InitQueue(Q);//初始化辅助队列
    BiTree P;
    EnQueue(Q,T);//根节点入队
    while( !IsEmpty(Q) )//队列非空
    {
        DeQueue(Q,P);
        visit(P);
        if(P->lchild)//左子树不空，将左子树根节点入队
        {
            EnQueue(Q,P->lchild);
        }
        if(P->rchild)//右子树不空，将右子树根节点入队
        {
            EnQueue(P->rchild);
        }
    }

}

/**
 * @brief 由遍历序列构造二叉树
 * 
 * 由二叉树的先序和中序可以构造二叉树
 *  
 */
