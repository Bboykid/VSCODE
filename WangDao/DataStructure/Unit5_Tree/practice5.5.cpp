/**
 * @file practice5.5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#define MaxSize 1000
#define Elemtype char

typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


// 6
/**
 * @brief 判断二叉树是否为二叉排序树
 * 
 */
//感觉有点问题
/**
    int pre = -32767;
    int JudgeSortTree(BiTree T)
    {  
        //进行中序遍历
        if( T==NULL )//空树
        {
            return 1;
        }
        else
        {
            int bl,br;
            //遍历左子树
            bl = JudgeSortTree(T->lchild);
            if( bl==0 || pre >= T->data )//该结点的左子树不是二叉排序树，或者中序前驱大于等于当前结点
            {
                return 0;//以该结点为根的子树不是二叉排序树
            }
            //记录遍历过的最后一个结点，即中序前驱
            pre = T->data;
            //遍历右子树
            //此时已结记录过了该结点的值作为中序前驱
            br = JudgeSortTree(T->rchild);
            return b2;//若右子树也为二叉排序树，则以该结点为根的子树是二叉排序树
        }
    }
**/
bool IsSearchTree(BiTree T)
{
    if(T==NULL)//空树
        return true;
    else
    {
        if( T->lchild==NULL && T->rchild==NULL )//无子树
            return true;
        else if( T->lchild!=NULL && T->rchild==NULL )//只有左子树
        {
            if( T->data < T->lchild->data )//结点值小于左孩子的值
                return false;
            else
                return IsSearchTree(T->lchild);
        }
        else if( T->lchild==NULL && T->rchild==NULL )//只有右子树
        {
            if( T->data > T->rchild->data )
                return false;
            else
                return IsSearchTree(T->rchild);
        }
        else if( T->lchild!=NULL && T->rchild!=NULL )
        {
            bool left,right;
            if( T->data <T->lchild->data || T->data > T->rchild->data )
                return false;
            else
            {
              return (IsSearchTree(T->lchild) && IsSearchTree(T->rchild));
            }
        }
    }
}

//7
/**
 * @brief 求出指定结点在二叉排序树中的层次
 * 
 */
int GetLevel(BiTree T,BiTNode *p)
{
    int n = 0;
    BiTNode *t = T;
    if(t!=NULL)
    {
        n++;
        while( t->data != p->data )
        {
            if( p->data < t->data )
                t = t->lchild;
            else
                t = t->rchild;
            n++;
        }
    }
    return n;
}

//8
/**
 * @brief 利用二叉树遍历的思想判断一个二叉树是否为平衡二叉树
 * 
 */
void Judge_AVL(BiTree bt,int &balance,int &h)
{
    int bl=0,br=0,hl=0,hr=0;
    if(bt==NULL)//空树
    {
        h = 0;
        balance = 1;
    }
    //叶子结点
    else if( bt->lchild==NULL && bt->rchild==NULL )
    {
        h=1;
        balance = 1;
    }
    else
    {   //递归判断左，右子树，并修改bl,br,hl,hr
        Judge_AVL(bt->lchild,bl,hl);
        Judge_AVL(bt->rchild,br,hr);
        h = ( hl>hr?hl:hr)+1；
        if(abs(hl-hr)<2)//子树的高度差小于2
            balance = bl&&br;
        else
            balance = 0;
    }
}

//10
/**
 * @brief 从大到小输出不小于k的结点
 * 方法1：中序遍历，辅助栈
 * 方法2：先遍历右子树，再到根节点，再到左子树
 * 
 */
//方法1 非递归算法 对所有树都有效
void ShowKplus1(BiTree bt,int k)
{
    Stack S1,S2;
    InitStack(S1);
    InitStack(S2);
    BiTNode *p = bt;
    while( p!=NULL || !IsEmpty(S1) )
    {
        if( p )
        {
            Push(S1,p);
            p = p->lchild;
        }
        else
        {
            Pop(S1,p);
            if(p->data>=k);
                Push(p->data,S2);
            p = p->rchild;
        }
    }
}
//递归算法，对二叉排序树有效
void ShowKplus2(BiTree bt,int k)
{
    if(bt==NULL)
        return;
    //先右子树
    if(bt->rchild!=NULL)
        ShowKplus2(bt->rchild,k);
    if(bt->data >= k)
        printf("%d ",bt->data);
    if(bt->lchild!=NULL)
        ShowKplus2(bt->lchild,k);
}

//12
/**
 * @brief 查找二叉排序树上第k小的结点
 * 
 */
typedef struct BSTNode{
    Elemtype data;
    struct BSTNode *lchild,*rchild;
    int count;
}BSTNode,*BSTree;

BSTNode *Search_k(BSTree t,int k)
{
    if( k<1 || k>t->count )
        return NULL;
    if( t->lchild==NULL )
    {
        if( k==1 )
            return t;
        else 
            return Search_k(t->rchild,k-1);
    }
    else
    {
        if( t->lchild->count == k-1 )
            return t;
        if( t->lchild->count > k-1 )
            return Search_k(t->lchild, k );
        if( t->lchild->count < k-1 )
            return Search_k(t->rchild, k - t->lchild->count - 1);
    }
}

//13
/**
 * @brief 
 * 
 */

//14
/**
 * @brief 
 * 1. 哪种数据结构适宜保存上述具有前缀特性的不等长编码？
 * 2，基于你所设计的数据结构，简述从0/1串到字符串的译码过程。
 * 3. 简述判定某字符串的不等长编码是否具有前缀特性的过程。
 * 
 * （1） 使用一颗二叉树保存字符集中各字符的编码，每个编码对应于从跟开始到达某叶节点的一条路径，路径长度等于编码位数，路径到达的叶节点保存该编码对应的字符。
 * （2） 从左到右依次扫描0/1串中的各位。从根开始，根据串中当前位沿当前结点的左子指针或右子指针下移，直到移动到叶节点位置。输出叶节点中保存的字符。
 *       然后从根开始重复这个过程，直到扫描到0/1串结束，译码完成。
 * （3） 二叉树既可以用于保存各字符的编码，又可用于检测编码是否具有前缀特性。判定编码是否具有前缀特性的过程，也是构建二叉树的过程。
 *          初始时，二叉树中仅含有根节点，其左右指针均为空。依次读入每个编码C，建立/寻找从根开始对应于该编码的一条路径，过程如下：
 *          对每个编码，从左至右扫描C的各位，根据C的当前位沿结点的指针（左指针或右子指针）向下移动。当遇到空指针时，创建新结点，
 *          让空指针指向该新结点并继续移动。沿指针移动的过程中，可能遇到三种情况。
 *              1 若遇到了叶节点（非根），则辨明不具有前缀特性。返回。
 *              2 若在处理C的所有位的过程中，军没有创建新结点，则表明不具有前缀特性，返回。
 *              3 若在处理C的最后一个编码位时创建了新结点，，则继续验证下一个编码。
 *              若所有编码均通过验证，则编码具有前缀特性。
 */

