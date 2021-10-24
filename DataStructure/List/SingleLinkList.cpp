#include<stdlib.h>

//结点定义
typedef int ElemType;
struct LNode
{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;

/**不带头结点的单链表
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
**/

//带头结点的单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if( L == NULL )
        return false;//内存分配失败
    L->next=NULL;//头结点之后暂时没有结点
    return true;
}

bool Empty(LinkList L)
{
    return (L->next==NULL);
}

int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while( p->next!=NULL )
    {
        p = p->next;   
        len++;
    }
    return len;
}

LNode *GetElem(LinkList L,int i)
{
    if( i == 0 )
        return L;
    if( i < 1 )
        return NULL;
    LNode *p=L;
    int j = 0;
    while(p!=NULL && j < i)
    {
        p = p->next;
        j++;
    }
    /**
     * if(p == NULL)
     *  return NULL;
     * 
     */
    
    return p;
}

LNode *LocateElem(LinkList L, ElemType e) 
{
    LNode *p = L;
    while( p!=NULL && p->data != e )
    {
        p=p->next;
    }
    return p;
}

//指定位序的插入
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if( i < 1 )
        return false;
    //待插入的结点
    LNode * s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next =NULL;
    /**
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p = L;
    int j = 0;
    while( p!=NULL && j < i - 1 )
    {
        p=p->next;
        j++;
    }
    **/
    LNode *p = GetElem(L, i-1);
    //*****************//
    // i 的值不合法 i的值过大
    if( p == NULL )
        return false;
    //*****************//
    s->next = p->next;
    p->next = s;
    return true;
}

//指定结点的插入
//后插
bool InsertNextNode(LNode *p, ElemType e)
{
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//前插
bool InsertPriorNode(LNode *p, ElemType e)
{
    if(p == NULL )
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if( i < 1 )
        return false;
    LNode *p = GetElem(L,i-1);
    /**
    LNode *p;
    int j = 0;
    p = L;
    while(p!=NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    **/
    if( p == NULL )
        return false;
    if( p->next == NULL )
        return false;
    LNode *s = p->next;
    p->next = s->next;
    e = s->data;
    free(s);
    return true;
}

//按结点删除
//指定结点删除
bool DeleteNode(LNode *p)
{
    if( p == NULL )
        return false;
    /**
    if(p->next == NULL)
    **/
    p->data = p->next->data;
    LNode *q = p->next;
    p->next = p->next->next;
    free(q);
    return true;
}

void Traverse(LinkList &L)
{
    if(L->next == NULL)
        return;
    if(L->next->next == NULL)
        return;
    LNode *p,*pre;
    pre = L->next;
    p = pre->next;
    while( p!= NULL )
    {
        pre->next = p->next;
        //insert p
        p->next = L->next;
        L->next = p;
        p = pre->next;
    }
    
}