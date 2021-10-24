/**
 * @file practice141.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-21
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


void Visit(BiTree T);

/**
 * @brief 1
 * 非空二叉树的先序序列和后序序列正好相反，该二叉树的形态是什么？
 * 非叶结点只有一个孩子
 * 二叉树的先序序列是NLR，后序序列是LRN，要是NLR=NRL成立，L或R至少有一个为空，二叉树每层只有一个结点，其高度等于结点个数。
 * 
 */

/**
 * @brief 2
 * 正好相同？
 * NLR= LRN，LR都为空
 * 只有根节点。
 * 
 */

/**
 * @brief 3 后序遍历二叉树的非递归算法
 * 利用栈完成后序遍历
 * 若有对于栈顶的每个结点，有左孩子，左孩子进栈，遍历指针指向栈顶结点；若无左孩子但是有右孩子，且右孩子未被访问过，右孩子进栈；其他情况出栈。
 * 如何检查右孩子有没有被访问过，利用一个指针，在结点出栈时，指向该结点，表示访问过。
 */
void PostOrder2(BiTree T)
{
    Stack S;
    InitStack(S);
    BiTNode *p,*r;//p指针遍历二叉树，r指针保存出栈结点
    p = T;
    r = NULL;
    while( !IsEmpty(S) || p )//栈非空
    {
        if(p!=NULL)//p存在入栈
        {
            Push(S,p);
            p = p->lchild;//优先向左
        }
        else //向右转移
        {
            GetTop(S,p);
            if( p->rchild && p->rchild!=r )//p的右孩子存在且未被访问过
            {
                p = p->rchild;
                // Push(S,p); 不必再push，仅需转移方向即可
            }
            else //进行出栈操作
            {
                Pop(S,p);
                Visit(p);
                r=p;//记录表示p被访问过
                p = NULL;
            }
        }
    }
}



/**
 * @brief 4 自下到上、从右到左的层次遍历算法
 *  利用队列 
 */
//my method:修改结点入队顺序，让右孩子先入队，自右向左，自上到下（看错题了）
void LawyerOrder2(BiTree T)
{
    Queue Q;
    InitQueue(Q);
    BiTNode *p;
    p = T;
    EnQueue(Q,p);
    while( !IsEmpty(Q) )//队列Q空时结束
    {
        DeQueue(Q,p);//出队列
        Visit(p);
        if(p->rchild!=NULL)//右孩子先入队
            EnQueue(p->rchild);
        if(p->lchild!=NULL)
            EnQueue(p->lchild);
    }
    
}
//text method: 利用栈逆序输出,每一次的结点
void InvertLawyer(BiTree T)
{
    Stack S;
    Queue Q;
    if(T!=NULL)
    {
        
        InitStack(S);
        InitQueue(Q);
        BiTNode *p;
        p = T;
        Push(Q,p);
        while( !IsEmpty(Q) )
        {
            if(p->lchild!=NULL)
                Push(Q,p->lchild);
            if(p->rchild!=NULL)
                Push(Q,p->rchild);
        }
        while(!IsEmpty(S))
        {
            Pop(S,p);
            Visit(p);
        }
    }   
}

/**
 * @brief 5 非递归算法求二叉树高度（二叉链表）
 * 
 * 算法思想：利用层次遍历，每层结束高度加1，设置一个标记，表示层结束
 * 
 */
// My method:
int HeightOfTree(BiTree T)
{
    if(!T)
        return 0;
    BiTNode *tag =(BiTNode *)malloc(sizeof(BiTNode));//创建一个标志，表示一层结束
    BiTNode *p = T;
    Queue Q;//创建一个队列
    InitQueue(Q);
    int level = 0;
    EnQueue(Q,p);
    EnQueue(Q,tag);
    while( !IsEmpty(Q) )//Q空时结束
    {
        DeQueue(Q,p);//出队
        if( p==tag && !IsEmpty(Q) )//一层结束,且队中还有结点，即有下一层
        {
            level++;
            EnQueue(Q,tag);//再次入队
        }
        else//结点出队
        {
            //孩子入队
            if(p->lchild!=NULL)
                EnQueue(Q,p->lchild);
            if(p->rchild!=NULL)
                EnQueue(Q,p->rchild);
        }
    }
    return level;
}
//text method:利用数组队列 
int BtDepth(BiTree T)
{
    if(!T)
        return 0;
    int front=-1,rear=-1;
    int last=0,level=0;
    BiTree Q[MaxSize];
    Q[++rear]=T;
    BiTree p;
    while( front<rear )//对不空
    {
        p=Q[++front];//出队
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rear] = p->rchild;
        if(front==last)
        {
            level++;//层数加1
            last = rear;//新的层结束标记
        }
    }
    return level;    
}


/**
 * @brief 6 先序遍历序列和中序遍历序列建立二叉树
 *  利用递归建立，每次确定子树的根节点,先序和中序遍历序列确定左右子树遍历序列的范围
 */

BiTree PreInCreate(Elemtype A[],Elemtype B[],int l1,int h1,int l2,int h2)
{
    //l1,h1为先序序列的开始和结束下标，l2、h2为中序序列的开始和结束下标
    BiTNode * T = (BiTNode *)malloc(sizeof(BiTNode));
    T->data = A[l1];
    int i;
    for(i=l2; i<=h2; i++)
    {
        if(A[l1]==B[i])
            break;
    }
    int llen = i - l2;//左子树长度
    int rlen = h2 - i;//右子树长度
    //有左子树,递归建立左子树
    if(llen)
    {
        T->lchild = PreInCreate(A,B,l1+1,l1+llen,l2,l2+llen-1);
    }
    else
        T->lchild = NULL;
    if(rlen)
    {
        T->rchild = PreInCreate(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
    }
    else
        T->rchild = NULL;

    return T;
}


/**
 * @brief 7 判定二叉树是否为完全二叉树
 * 利用层次遍历，令空结点入队，完全二叉树空结点后应不存在非空结点
 */
int isComplete(BiTree T)
{
    if(T==NULL)
        return 1;//空树为完全二叉树
    BiTNode *p;
    Queue Q;
    InitQueue(Q);
    while( !IsEmpty(Q) )
    {
        Pop(Q,p);
        if(p)//p存在，孩子入队，空结点也入队
        {
            Push(Q,p->lchild);
            Push(Q,p->rchild);
        }
        else//p为空结点，完全二叉树后面应该都是空结点
        {
            while( !IsEmpty(Q) )
            {
                Pop(Q,p);
                if(p==NULL)
                    return 0;//非完全二叉树
            }
        }
    }
    return 1;//完全二叉树
}


//8
/**
 * @brief 计算二叉树的所有双分支结点的个数
 * my method: 遍历每个结点
 * 
 * text method：利用递归
 * 
 */

int DoubleCount(BiTree T)
{
    if(T==NULL)
        return 0;
    if( T->lchild && T->rchild )
    {
        return (DoubleCount(T->lchild)+DoubleCount(T->rchild)+1);
    }
    else if(T->lchild)//只有左子树
    {
        return DoubleCount(T->lchild);
    }
    else //只有右子树
    {
        return DoubleCount(T->rchild);
    }
}


//9
/**
 * @brief 交换左右子树
 * 
 * my method:利用递归
 */

void ChangeLeftRight(BiTree T)
{
    if( T==NULL || (T->lchild==NULL && T->rchild == NULL))//空树或该子树仅有一个结点
        return;
    if( T->lchild!=NULL || T->rchild!=NULL )//有子树
    {
        //交换左右子树
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
    //递归到下一层
    ChangeLeftRight(T->lchild);
    ChangeLeftRight(T->rchild);

}


//10
/**
 * @brief 求先序遍历序列中第k个结点的值
 * 
 * 解法1： 求出先序遍历序列，存到数组中去
 * 解法2： 对先序遍历算法进行微调
 * 
 */
//利用先序遍历算法的非递归算法
Elemtype GetK(BiTree T,int k)
{
    Stack S;
    InitStack(S);
    BiTNode *p = T;
    int cnt = 0;//计数器
    while(p || !IsEmpty(S))
    {
        if(p)
        {
            cnt++;
            if(cnt == k)
                break;
            Push(S,p);
            p = p->lchild;
        }
        else
        {
            Pop(p);
            p = p->rchild;
        }
    }
    if(cnt == k)
        return p->data;
    else
        return -1;//k越界，没有找到
}
//递归算法
int count = 1;//遍历序号的全局变量
Elemtype PreNode(BiTree T, int k)
{
    if( T==NULL )
        return '#';//空结点，返回特殊字符
    if( count==k )
        return T->data;
    count++;//计数器+1
    Elemtype ch;
    ch = PreNode( T->lchild,k);
    if( ch!='#' )
        return ch;
    ch = PreNode(T->rchild,k);
        return ch;
}


//11
/**
 * @brief 删除结点值为x的的根节点的子树
 * 
 */
//递归删除
void DeleteTree(BiTree t)
{
    if(t)
    {
        DeleteTree(t->lchild);
        DeleteTree(t->rchild);
        free(t);
    }
}
//查找节点值为x的结点
//自上而下进行查找，利用层次遍历，不会重复访问结点
void SearchX(BiTree T, Elemtype x)
{
    if(T=NULL)
        return;
    Queue Q;
    InitQueue(Q);
    BiTNode *p;
    p = T;
    Push(Q,T);
    while(!IsEmpty(Q))//Q非空
    {
        Pop(Q,p);//出队列
        if(p->data==x)//若值为x，将该子树删除,自然该结点的孩子也不用入队
            DeleteTree(p);
        else
        {
            if(p->lchild!=NULL)
                Push(Q,p->lchild);
            if(p->rchild!=NULL)
                Push(Q,p->rchild);
        }
        
    }

}



//12
/**
 * @brief 查找值为x的所有结点，并打印值为x的所有祖先，(值为x的结点最多1个)
 * 利用后序遍历
 * 
 */
void Print(Elemtype x);
void GetX_Ancestor(BiTree T,Elemtype x)
{
    if(T==NULL)
        return;
    Stack S;
    InitStack(S);
    BiTNode *p;
    p == T;
    int flag = 0;//标志位，表示找到x
    while( p || !IsEmpty(S) )//S非空,或p存在
    {
        if( p!=NULL )//p非空
        {
            if( p->data==x )
            {
                flag = 1;//修改标志位，表示找到了值为x的节点
                break;//退出循环，栈内结点为x的祖先
            }
            Push(S,p);//p入栈
        }
        else
        {
            GetTop(S,p);//
            if( p->rchild!=NULL )//p的右孩子存在
            {
                p = p->rchild;
            }
            else
            {
                Pop(S,p);
                p = NULL;//改为NULL，防止扰乱循环判定条件
            }
        }
    }
    //打印栈内元素，栈内元素都为x的祖先
    if(flag)
    {
        BiTNode *temp;
        while( !IsEmpty(S) )
        {
            Pop(S,temp);
            Print(temp->data);
        }
    }
    DestroyStack(S);//销毁栈
}


//13
/**
 * @brief 找p和q的最近的公共祖先
 * 
 * 解法1：
 *  用两个栈A、B，A保存p的祖先，B保存q的祖先，问题转换成单链表求第一个共同结点的问题
 * 解法2：
 *  
 */



//14
/**
 * @brief 求非空二叉树b的宽度
 * 解法：利用层次遍历，每层设置标记
 */
//数组法
int TreeMaxWidth(BiTree T)
{
    if( T==NULL )
        return 0;
    //队列用于层次遍历
    BiTNode Q[MaxSize];
    BiTNode *p;
    int front,rear = -1;//队列队首、队尾指针
    int length,max=1;
    int last = 0;//层结束标记
    Q[++rear] = T;
    while( front < rear )//队列非空
    {
        p = Q[++front];

        if( p->lchild )
            Q[++rear] = p->lchild;
        if( p->rchild )
            Q[++rear] = p->rchild;
        if( front == last )
        {
            length = rear - front;
            last = rear;
            if( length > max )
                max = length;
        }
    }

    return max;
}
// text method
/**
 * 采用层次遍历的方法求出所有结点的层次，并将所有结点和对应的层次放在一个队列中。
 * 然后通过扫描队列求出各层结点总数，最大的层结点数即为二叉树的宽度。
 */

struct {
    BiTree data[MaxSize];
    int level[MaxSize];
    int front,rear;
}Qu;

int BTWidth(BiTree b)
{
    BiTree p;
    int k,max,i,n;
    Qu.front = Qu.rear = -1;//队列为空
    Qu.rear++;
    Qu.data[Qu.rear] = b ;//根节点指针入队
    Qu.level[Qu.rear] = 1;
    while(Qu.front < Qu.rear)//队列非空
    {
        Qu.front++;//出队
        p = Qu.data[Qu.front];//出队结点
        k = Qu.level[Qu.front];//出队结点的层次
        if( p->lchild !=NULL )//出队结点有左孩子
        {
            Qu.rear++;
            Qu.data[Qu.rear] = p->lchild;
            Qu.level[Qu.rear] = k+1;
        }
        if( p->rchild!=NULL )//有右孩子
        {
            Qu.rear++;
            Qu.data[Qu.rear] = p->rchild;
            Qu.level[Qu.rear] = k+1;
        }
    }
    //while循环结束后所有结点的层次遍历完成，个结点的层次存储在Q.level[]中
    max = 0;//max保存同一层最多结点的个数
    i = 0;//i扫描队中的所有元素
    k = 1;//k表示从第一层开始查找
    while( i<=Qu.rear )
    {
        n=0;//n统计第k层的结点数
        while(i<=Qu.rear&&Qu.level[i]==k)
        {
            n++;
            i++;
        }
        k = Qu.level[i];//某一层结束，k到下一层
        if( n>max )
            max = n;//更新max
    }
    return max;
}

//15
/**
 * @brief 已知一颗满二叉树的先序，求其后序
 * 满二叉树：左右子树结点数相等
 * 先序的第一个结点作为后序的最后一个结点
 * 递归
 */
void PreToPost(Elemtype pre[],int l1,int h1,Elemtype post[],int l2,int h2)//l1,h1表示先序序列的开始和结束下标，l2,h2表示后序序列的开始和结束下标
{
    int half;
    if( h1>=l1 )
    {
        post[h2] = pre[h1];//该子树的后序的最后一个结点为先序的第一个结点
        half = (h1-l1)/2;//half表示以该结点孩子为跟结点的子树的结点数
        PreToPost(pre,l1+1,l1+half,post,l2,l2+half-1);//递归到左子树
        PreToPost(pre,l1+half+1,h1,post,l2+half,h2-1)//递归到右子树
    }
}


//16
/**
 * @brief 将二叉树的叶结点按从左到右的顺序连接成一个单链表
 * 算法思想：利用中序遍历算法，设置两个指针pre,p，pre用来保存上个遍历的叶子结点，p用来遍历结点，每次检查结点是否是叶子结点，
 * 若是，将其链在pre指向的结点上，pre在转到该结点上。
 * 
 */
//非递归算法(有头结点)
BiTNode *LinkLeafInOrder(BiTree T)
{
    Stack S;
    InitStack(S);
    BiTNode *pre,*p;
    p = T;
    BiTNode *Head = (BiTNode *)malloc(sizeof(BiTNode));//单链表的头结点
    pre = Head;
    while( p || IsEmpty(S))
    {
        if(p)//结点存在，入栈，转向左孩子
        {
            Push(S,p);
            p = p->lchild;
        }
        else//出栈
        {
            Pop(S,p);
            //检查是否为根节点
            if( p->lchild==NULL && p->rchild==NULL )
            {
                pre->rchild = p;
                pre = p;
            }
            //转向右孩子
            p = p->rchild;
        }
    }
    return head;
}
//递归算法
LinkedList InOrderLink(BiTree bt)
{
    if(bt)
    {
        InOrderLink(bt->lchild);
        if(bt->lchild==NULL && bt->rchild==NULL)
        {
            if(pre==NULL)//第一个结点
            {
                head = bt;
                pre = bt;
            }
            else
            {
                pre->rchild = bt;
                pre = bt;
            }
        }
        InOrderLink(bt->rchild);
        pre->child == NULL;//设置链表尾
    }
    return head;
}


//17
/**
 * @brief 判断二叉树是否相似
 * 相似的条件： 1. 都为空树或只有一个根节点 2.左子树相似 3.右子树相似
 */
int similar(BiTree T1,BiTree T2)
{
    int leftS,rightS;
    if(T1==NULL&&T2==NULL)
        return 1;
    else if(T1==NULL || T2==NULL)
        return 0;
    else
    {
        leftS = similar(T1->lchild,T2->lchild);
        rightS = similar(T1->rchild,T2->rchild);
        return leftS&&rightS;
    }
}


//18
/**
 * @brief 写出中序线索二叉树中查找节点的后序遍历的前驱节点的算法
 * 
 * 
 */

typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;//左右线索标志：0表示指示左孩子，1表示指示前驱
}ThreadNode,*ThreadTree;

BiTNode *FindPostPre(ThreadTree T,ThreadTree p)
{
    ThreadNode *q;
    if(p->rtag==0)//p有右孩子
        q = p->lchild;
    else if(p->ltag==0)//p有左孩子
        q = p->ltag;
    else if(p->lchild==NULL)//p为中序序列第一个结点
        q=NULL;
    else
    {
        //顺着线索向上找p的中序前驱，直到其有左孩子结点
        while( p->ltag==1 && p->lchild!=NULL )
            p = p->lchild;
        if( p->ltag ==0 )//祖先有左孩子
            q = q->lchild;
        else
            q = NULL;
    }
    return q;
}


//19
/**
 * @brief 2014统考
 * 求叶子总的带权路径长度wpl
 * 每个结点的带权路径长度为：路径长度*权值
 * 两种解法：
 *  1. 递归（先序遍历）
 *  2. 层次遍历
 * tip: 第k层到根节点的距离为k-1
 */

typedef struct WeightNode{
    int weight;
    struct WeightNode *lchild,*rchild;
}WeightNode,*WeightTree;
//method 1: 递归的先序遍历算法
int WPL1(WeightTree root,int deep)
{
    static int Wpl = 0;
    if( root->lchild==NULL && root->rchild==NULL )//为叶子结点
    {
        Wpl += deep * root->weight;
    }
    if( root->lchild!=NULL )//左子树不空，对左子树遍历
        WPL1(root->lchild,deep+1);
    if( root->rchild!=NULL )//右子树不空
        WPL1(root->rchild,deep+1);
    return Wpl;
}
//层次遍历
int Wpl2(WeightTree root)
{
    int wpl = 0;//wpl
    WeightTree Q[MaxSize];//一个足够长的数组作为队列进行层次遍历
    WeightNode *p;
    int front = -1,rear = -1;//队头与队尾指针
    int last = 0;//层结束标记
    int deep = 0;//距离(根节点到根节点的距离为0) 每层结束后:距离+1==结束的这层的层次==下一层的距离
    Q[++rear] = root;//根节点入队
    while( front < rear ) // 队列非空
    {
        p = Q[++front];//结点出队列
        //检查出队结点是否为叶子结点
        if( p->lchild==NULL && p->rchild==NULL )
            wpl += deep * p->weight;//wpl加上该叶子结点的权值
        //将出队结点的孩子入队
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rear] = p->rchild;
        //检查是否到达下一层
        if(front==last)//该层结束，到达下一层
        {
            last = rear;
            deep++;
        }
    }
    return wpl;
}



//20
/**
 * @brief 2017统考
 *  
 *  中序遍历的改版：
 *      设置一个标记，遇到符号+1，也就是括号数 
 *  
 */
void BiTreeToExp(BiTree root, int deep)
{
    if(root==NULL)  return;
    else if (root->lchild==NULL && root->rchild==NULL)
        cout<<root->data;
    else
    {
        if(deep > 1)
            cout<<"(";
        BiTreeToExp(root->lchild,deep+1);
        cout<<root->data;
        BiTreeToExp(root->rchild,deep+1);
        if(deep > 1)
            cout<<")";
    }
}

