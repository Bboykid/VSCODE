/**
 * @file ThreadTree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021
 * 
 * 线索二叉树
 * 
 */
#define Elemtype char


typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;//左右线索标志：0表示指示左孩子，1表示指示前驱
}ThreadNode,*ThreadTree;


//中序线索化
ThreadNode *pre = NULL;
void visit(ThreadNode *q)
{
    if(q->lchild==NULL)
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    //注意：pre移到最后一个结点时，pre->rchild为NULL，也满足该条件，需要额外赋值
    if( pre->rchild == NULL && pre !=NULL )
    {   
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;     
}

void InThread(ThreadTree T)
{
    if(T!=NULL)
    {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

//中序线索化二叉树T(完整步骤)
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if(T != NULL )
    {
        InThread(T);
        if(pre->rchild == NULL )
            pre->rtag = 1;
    }
}



/**
 * @brief 先序线索化
 *  只要先序有点特殊
 */

void PreThread(ThreadTree T)
{
    if( T!=NULL )
    {
        visit(T);//先处理根结点，若T->lchild为NULL，处理完之后会导致左孩子指向前驱
       if( T->ltag==0 )//不是指向前驱的情况下才继续递归否则会原地打转
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}



/**
 * @brief 寻找后继
 * 
 */

//中序二叉线索树寻找后继
ThreadNode *FirstNode(ThreadNode *p)
{
    //循环找到最左下结点
    while(p->ltag==0)
    {
        p = p->lchild;
    }
    return p;
}

ThreadNode *Next(ThreadNode *p)
{
    if(p->rtag == 0) return FirstNode(p->rchild);
    else return p->rchild;
}

//对中序二叉线索树进行中序遍历
void InOrder(ThreadTree T)
{
    for(ThreadNode *p = FirstNode(T); p!=NULL ; p=Next(p) )
    {
        visit(p);   
    }
}


//中序二叉树寻找前驱
ThreadNode *LastNode(ThreadNode *p)
{
    while( p->rtag == 0 )
        p = p->rchild;
    return p;
}
ThreadNode *PreNode(ThreadNode *p)
{
    if( p->ltag == 1 )  return p->lchild;
    else return LastNode(p->lchild);
}

//逆向中序遍历



/**
 * @brief 先序寻找后继、前驱
 * 
 */

//寻找先序后继
ThreadNode *Next2(ThreadNode *p)
{
    if( p->rtag == 1 )//没有右孩子，rchild直接指向其后继
        return p->rchild;
    else//有右孩子的情况
    {
        if( p->ltag == 0 )//有左孩子，那么左孩子为其后继
            return p->lchild;
        else//没有左孩子，右孩子为其直接后继
            return p->rchild;
    }
}

//寻找先序前驱，找不到
ThreadNode *PreNode2(ThreadNode *p)
{
    if( p->ltag == 1 )//没有左孩子，lchild直接指向其前驱
        return p->lchild;
    else //有左孩子，找不到。
}
//改成三叉链表，有一个指针指向其父节点，就可以找到了
/**
 * 1 p是左孩子，则其前驱为其父节点
 * 2 p是右孩子，且无左兄弟，其前驱为其父节点
 * 3 p是右孩子，且有左兄弟，其前驱为其左兄弟子树中的最后一个被先序遍历的节点
 * 
 */






/**
 * @brief 后序找前驱和后继
 * 
 */







