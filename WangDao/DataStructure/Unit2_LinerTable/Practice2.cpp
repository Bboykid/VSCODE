#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

/**
 * @brief 基本操作的实现
 * 
 */

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L);

//尾插法建立单链表
LinkList Lsit_TailInsert(LinkList &L);

// 按序号查找节点值
LNode *GetElem(LinkList L,int i);

//按值查找表结点
LNode *LocateElem(LinkList,ElemType e);

/**
 * @brief 双链表数据结构
 * 
 */
typedef struct DNode{
    ElemType data;
    DNode *prior,*next;
} DNode, *DLinkList;




/**
 * Practice
 * 
 */

//1
//递归实现
void Del_x(LinkList &L,ElemType x)
{
    if(L == NULL)
        return;
    LNode *p;
    if(L->data == x)
    {
        p = L;
        free(p);
        L=L->next;
        Del_x(L,x);
    }
    else
    {
        Del_x(L->next,x);
    }
}


//2 
//带头结点
//常规解法
void Del_x_2(LinkList L,ElemType x)
{
    LNode *pre = L;
    LNode *p = L->next;
    LNode *temp;
    while (p!=NULL)
    {
        if(p->data == x)
        {
            pre->next = p->next;
            temp = p;
            p = p->next;
            free(temp);
        }
        else
        {
            pre = pre->next;
            p = p->next;
        }
    }   
}
//利用尾插法建立单链表，结点值不是x的插入到头结点后，否则释放
//尾插法顺序不变，不考虑顺序的话，头插法也可行
void Del_x_3(LinkList &L,ElemType x)
{
    LNode *p = L->next,*q,*Tail=L;
    while(p!=NULL)
    {
        if(p->data == x)
        {
            q = p;
            p = p->next;
            free(q);
        }
        else
        {
            Tail->next = p;
            Tail = p;
            p = p->next;
        }
    }
    Tail->next = NULL;
}


//3
//解法1： Reverse 采用头插法即可
//解法2： 利用栈
//解法3： 既然可以利用栈，就可以利用递归
void Print(ElemType e);//输出函数
void R_Print(LinkList L)
{
    //递归
    if(L->next != NULL)
        R_Print(L->next);
    //输出
    if(L != NULL) 
        Print(L->data);    
}
//忽略头结点
void Solution3(LinkList L)
{
    if(L!= NULL)
        R_Print(L->next);
}


//4
//删除最小节点
//my method: double ptr
void Del_Min(LinkList &L)
{
    LNode *p,*pre,*p_min,*pre_min;
    //初始化
    pre = L;
    p = L->next;
    p_min = p;
    pre_min = pre;
    // search the min
    while ( p != NULL )
    {
        if(p->data < p_min->data)
        {
            pre_min =pre;
            p_min = p;
        }
        p = p->next;
        pre = pre->next;
    }
    //delelte node
    pre_min->next = p_min->next;
    free(p_min);
}

//5
//就地逆置，利用头插法，空间复杂度为O(1)
//解法1：利用头插法
void Reverse_1(LinkList &L)
{
    LNode *p = L->next,*q;
    while ( p!= NULL)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}
//解法2：遍历翻转
void Reverse_2(LinkList &L)
{
    LNode *p = L->next,*r,*pre;
    r = p->next;
    p->next = NULL;//第一个结点作为末尾结点，next指针为空
    while( r!= NULL )//r==NULL是，p为最后一个结点
    {
        pre = p;
        p = p->next;
        r = r->next;
        p->next = pre;
    }
    L->next = p;//处理最后一个结点（逆置后成为第一个结点）
}


//6
//单链表排序
//解法1：将单链表转化为顺序表，对顺序表进行排序，在通过顺序表实现单链表（顺序表可用快排，和归并排序，时间复杂度为(nlogn)
//解法2：直接插入排序（时间复杂度为O(n平方),对每一个待插入的节点，找到其直接前驱
void InserLinkListSort(LinkList &L)
{
    LNode *p= L->next,*pre,*q;
    LNode *r= p->next;//r为p的后继结点，保证不断链
    p->next = NULL;//将p的后继指向空，这样若p为排序后最后一个结点，不必再对其进行操作
    while( p!=NULL )
    {
        r = p->next;//保存后继结点，保证不断链
        pre =L;
        q = pre->next;
        //若有序链表中结点的值 >= 待插入结点的值 或 有序链表扫描到最后，扫描停止
        while( p->data < q->data && q!=NULL )
        {
            pre = pre->next;
            q = q->next;
        }
        //将待插入结点的值插入的q结点的前面
        pre->next = p;
        p->next=q;
        p = r;//p后继，扫描元链表中剩下的元素

    }

}


//7
//删除给定两值之间的元素
/**
 * 遍历结点，双指针，一个之结点的直接前驱
 */
void Del_From_To(LinkList &L, int a, int b )//删除值介于a,b之间的的节点
{
    LNode *p,*pre,*temp;
    pre = L;
    p = L->next;
    while ( p!=NULL )
    {
        if( p->data > a && p->data < b)
        {
            pre->next = p->next;
            temp = p;
            p = p->next;
            free(temp);
        }
        else
        {
            p=p->next;
            pre = pre->next;
        }
    }
    
}


//8
//找出两个单链表的公共节点
//解法1：暴力求解，假设两个单链表A,B，对B中的每一个节点都在A中遍历一遍，看看有没有走过，时间复杂度Wie（mn)
//解法2：对于第一个公共节点，之后不会出现分叉，找到第一个相同的就可以了
// 1. 利用栈，将A，B每个节点进入不同的栈，然后逐个弹出，直到弹出节点不同为止。
// 2. 课本解法：找出长表和短表，计算表长之差，然后长表遍历结点先走，确保两个表同时到达最后
int Length(LinkList L);
LinkList Search_1st_Common(LinkList L1, LinkList L2)
{
    int len1 = Length(L1);
    int len2 = Length(L2);
    int distance;
    LinkList LongList,ShortList;
    if(len1 > len2)
    {
        LongList = L1->next;
        ShortList = L2->next;
        distance = len1 - len2;
    }
    else{
        LongList = L2->next;
        ShortList = L1->next;
        distance = len2-len1;
    }
    while (distance--)
    {
        LongList = LongList->next;
    }
    while (LongList != NULL)
    {
        if(LongList == ShortList)
            return LongList;
        else
        {
            LongList = LongList->next;
            ShortList = ShortList->next;
        }
    }
    return NULL;
    
    
}


//9
//递增输出单链表的值
//解法1：只利用单链表，每次找到链表中的最小值结点，输出并释放，时间复杂度为O(N平方)
//解法2：利用数组，将链表的值存到数组中去，再用排序算法进行排序，时间复杂度最低为O(NlogN)，但是需要额外的辅助空间
//这里用解法1实现，参考4，删除最小结点
void OutAndFree(LinkList &L)
{
    LNode *p,*p_min,*pre,*pre_min;
    while(L->next!=NULL)//头结点的next为空，则循环结束
    {
        p =L->next;
        p_min = p;
        pre = L;
        pre_min = pre;
        while ( p->next!= NULL )//遍历链表至末尾
        {
            if(p->data < p_min->data)
            {
                p_min = p;
                pre_min = pre;
            }
            p=p->next;
            pre = pre->next;
        }
        //输出并释放结点
        Print(p_min->data);
        pre_min->next = p_min->next;
        free(p_min);
    }
    free(L);
}
//参考答案，只用了一个pre指针指向最小结点的直接前驱，两种解答差不多，这个更精简
void OutAndFree_2(LinkList &L)
{
    LNode *p,*pre;
    while (L->next!=NULL)
    {
        pre = L;
        p = pre->next;
        while(p->next != NULL)
        {
            if(p->next->data < pre->next->data)
            {
                pre = p;
            }
            p = p->next;
        }
        Print(pre->next->data);
        LNode *t = pre->next;
        pre->next = t->next;
        free(t);
    }
    free(L);
}



//10
//分解为两个单链表，一个保存奇数序号的结点，另一个保存偶数序号的结点。
//保持相对顺序不变，用尾插法
//解法1：设置序号变量，bool型，也可设置int型
void DivideList(LinkList &L, LinkList &A, LinkList &B)
{
    //无节点直接返回
    if(L->next == NULL)
        return;
    LNode *p,*tailA,*tailB,*temp;
    tailA =A;
    tailB =B;
    p = L->next;//p初始化为L的第一个结点
    bool flag = true;//计数器,flag为true时表示奇数
    while ( p != NULL)
    {
        temp = p;
        p = p->next;
        if(flag)//奇数项
        {
            temp->next =NULL;//next置空
            tailA->next = temp;
            tailA = tailA->next;
        }
        else
        {
            temp->next =NULL;//next置空
            tailB->next = temp;
            tailB = tailB->next;
        }
        flag = !flag;//计数器
    }
    free(L);
}
//解法2：直接在while循环中执行两次插入，一次daoA，一次到B


//11
//与上题相仿，只是B表用头插法进行逆置
//略


//12
//去掉重复元素，递增表，没啥好说的，Easy


//13
//两个递增的归并成一个递减的单链表，归并排序的思想，头插法逆置就可以了
void MergeAndReverse(LinkList &A, LinkList &B, LinkList &C)
{
    LNode *pA,*pB,*t;
    pA = A->next;
    pB = B->next;
    while ( pA!=NULL && pB!=NULL )
    {
           //头插法将小的插入
        if(pA->data < pB->data)
        {
            t = pA;
            pA = pA->next;
            t->next = C->next;
            C->next = t;
        }
        else
        {
            t = pB;
            pB = pB->next;
            t->next = C->next;
            C->next = t;
        }
    }
    //剩余结点归并
    while(pA!=NULL)
    {
        t = pA;
        pA = pA->next;
        t->next = C->next;
        C->next = t;
    }
    while(pB!=NULL)
    {
        t = pB;
        pB = pB->next;
        t->next = C->next;
        C->next = t;
    }
}


//14
//从A和B的公共元素中产生单链表C（A和B为递增链表）
//说明：公共元素指 值相同，不是结点相同
LinkList GetCommon(LinkList &A,LinkList &B)
{
    LNode *pA,*pB;
    LinkList C = (LinkList)malloc(sizeof(LNode));
    C->next = NULL;
    //尾插法
    LNode *tail = C;
    pA = A->next;
    pB = B->next;
    while(pA!=NULL &&pB!=NULL)
    {
       // 公共元素，添入C
        if(pA->data == pB->data)
        {
            LNode *temp = (LNode *)malloc(sizeof(LNode));
            temp->data = pA->data;
            temp->next = NULL;
            tail->next = temp;
            tail=tail->next;
            //pA,pB同时后移
            pA = pA->next;
            pB = pB->next;
        }
        //小的指针后移
        else if(pA->data < pB->data)
        {
            pA = pA->next;
        }
        else
        {
            pB = pB->next;
        }
    }
    return C;
}



//15
//与上题类似，只是合并存放到A中
void Union(LinkList &A,LinkList &B)
{
    LNode *pA,*pB,*tail,*temp;//pA,pB用来扫描两个链表,tail用来插入结点,temp用来临时存放结点
    tail = A;
    pA = A->next;
    pB = B->next;
    while (pA && pB)
    {
        //公共元素
        if( pA->data == pB->data )
        {
            //尾插法插入元素
            temp = pA;
            pA = pA->next;
            temp->next = NULL;
            tail->next = temp;
            tail = tail->next;
            //释放掉B中结点
            temp = pB;
            pB = pB->next;
            free(temp);
        }
        else if( pA->data < pB->data )
        {
            //A指针后移，并释放结点
            temp = pA;
            pA = pA->next;
            free(temp);
        }
        else
        {
            temp = pB;
            pB = pB->next;
            free(pB);
        }
    }
    //遍历结束，释放剩余结点
    while (pA)
    {
        temp = pA;
        pA = pA->next;
        free(temp);
    }
    while (pB)
    {
        temp = pB;
        pB = pB->next;
        free(temp);
    }
    //释放B的头结点
    free(B);
    
}


//16
//判断连续子序列
int Pattern(LinkList A,LinkList B)
{
    LNode *pa,*pb,*q;
    pa = A;
    pb = B;
    //记住A的开始结点
    q = A;
    while (pa && pb)
    {
        if(pa->data == pb->data)//结点值相同
        {
            pa=pa->next;
            pb = pb->next;
        }
        else
        {
            q = q->next;
            pa = q;
            pb = B;
        }
    }
    if(pb==NULL)
        return 1;//B是A的子串
    else
        return 0;//B不是A的字串
    
}


//17
//判断循环双链表是否对称
bool Symmetry(DLinkList L)
{
    DNode *p,*q;
    p = L->next;
    q = L->prior;
    while( p->next==q || p==q )
    {
        //不对称
        if( p->data != q->data )
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}


//18
//将两个循环单链表连接成一个循环链表
LinkList Union2List(LinkList &h1,LinkList &h2)
{
    LNode *p,*q;
    p=h1;
    q=h2;
    //先找到两个链表的尾结点
    while(p->next!=h1)
    {
        p=p->next;
    }
    while(q->next!=h2)
    {
        q=q->next;
    }
    //此时p,q为h1,h2的尾结点
    p->next = h2->next;
    q->next = h1;
    return h1;
}


//19
//循环单链表
void Del_All(LinkList &L)
{
    LNode *p,*pre,*p_min,*pre_min;
    while(L->next!=L)
    {
        pre = L;
        p = L->next;
        p_min = p;
        pre_min = pre;
        while( p!= L)
        {
            if(p->data < p_min->data )
            {
                p_min = p;
                pre_min = pre;
            }
            p=p->next;
            pre = pre->next;
        }
        //内循环结束时找到当前最小结点
        pre_min->next = p_min->next;
        free(p_min);
    }
    //释放头结点
    free(L);
}


//20




//21
/**
 * @brief 2009统考
 * 算法思想：
 *  利用两个指针，其中一个先走K步，然后两个指针同时走，先走的到达末尾时，另一个指针正好到倒数第k个结点
 */
int Search_k(LinkList L,int k)
{
    LNode *p,*pre;
    p = L->next;
    pre = L->next;
    int cnt = 0;//计数器
    while ( p != NULL )
    {
        if(cnt<k)   cnt++;
        else pre = pre->next;
        p = p->next;
    }
    //判断查找是否成功
    if( cnt < k )
        return 0;//查找失败
    else
    {
        Print(pre->data);
        return 1;//查找成功
    }
}


//22
int GetLength(LinkList L)
{
    int len = 0;
    while (L->next != NULL)
    {
        L = L->next;
        len++;
    }
    return len;
}

LNode *Find_Add(LinkList str1,LinkList str2)
{
    int len1,len2,dist;
    len1 = GetLength(str1);
    len2 = GetLength(str2);
    //长链表指针先走 |len1-len2|距离
    LNode *longlist,*shortlist;
    //str1 长度 大于等于 str2长度
    if(len1 >= len2)
    {
        dist = len1-len2;
        longlist = str1;
        shortlist = str2;
    }
    //str2长度大于str1的长度
    else
    {
        dist = len2-len1;
        longlist = str2;
        shortlist = str1;
    }
    //长链表先走dist距离
        while(dist--)
        {
            longlist = longlist->next;
        }
        //此时两个指针同时运动，则同时到达链表末尾
        while ( longlist->next !=NULL && longlist->next != shortlist->next)
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
        return longlist; 
}


//23
/**
 * @brief 2015统考
 * 算法思想：用空间换时间
 * 设置一个n长度的数组，遍历链表，对链表中的每个结点，用来保存其data的值是否出现过
 * 时间复杂度O(n)
 * 
 */
void Del_Same(LinkList &L,int n)
{
    //1. 申请n+1位置的辅助空间并初始化
    bool *tag = (bool *)malloc(sizeof(bool)*(n+1));
    for(int i = 0 ; i < n+1 ; i++)
    {
        //辅助空间的每一个结点设置为false，表示没有出现
        tag[i] = false;
    }
    //2. 遍历链表进行操作
    LNode *p = L->next;
    LNode *pre = L;
    LNode *temp;
    int m;//用来表示|data|
    while( p != NULL )
    {
        m = p->data>=0? p->data : -p->data;// m=|p->data|
        if( tag[m]==false )//没有出现过
        {
            tag[m] == true;
            pre = p;
            p = p->next;
        }
        else
        {
            pre->next = p->next;
            temp = p;
            p = p->next;
            free(temp);
        }
    }
    //释放辅助空间
    free(tag);
}


//24
/**
 * @brief 判断链表是否有环，若有，找到环的入口
 * 算法思想：
 *  双指针，速度不同，若一直走下去，若有环，必相遇
 */
LNode* FindLoopStart(LinkList L)
{
    LNode *fast,*slow;
    fast = L;
    slow = L;
    while( slow!=NULL && fast->next->next!=NULL )//慢指针指向空时结束
    {
        slow = slow->next;
        fast = fast->next->next;
        if( slow == fast )
            break;
    }
    if(slow==NULL || fast->next->next==NULL )
        return NULL;
    LNode *p1 = L, *p2 = slow;
    //寻找入口点
    while( p1!= p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


//25
/**
 * @brief 要求尽可能高效，空间复杂度为O(1)
 * 
 * my method:
 * 1. 遍历链表L，获得链表中间结点
 * 2. 建立头头结点L1，L2，L1保存链表前半部分，L2保存后半部分
 * 3. Reverse L2
 * 4. 轮流插入L（尾插法）
 * 时间复杂度为O(N) 空间复杂度为O(1)
 */
void change_list(LinkList &L)
{
    //寻找中间节点
    LNode *p,*q,*r,*s;
    p = q = L;
    while(q!=NULL)
    {
        p = p->next;
        q = q->next;
        if(q->next!=NULL)
            q= q->next;
    }
    q = p->next;//p所指结点为中间节点，q为后半段首节点
    //逆置链表后半段
    while (q!=NULL)
    {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = L->next;
    q = p->next;
    p->next = NULL;//最后一个结点
    while(q!=NULL)
    {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
    
}





