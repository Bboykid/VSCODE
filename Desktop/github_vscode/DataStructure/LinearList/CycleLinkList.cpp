
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

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if( L == NULL )
        return false;//内存分配失败
    L->next=L;//头结点指向头结点
    return true;
}

bool Empty(LinkList L)
{
    if(L->next == L)
        return true;
    else
        return false;
}

bool isTail(LinkList L,LNode *p)
{
    if(p->next == L)
        return true;
    else
        return false;
}

/***************************************/
//双端循环链表
struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
};
typedef struct DNode DNode;
typedef struct DNode *DLinkList;

bool InitDLinkList(DLinkList &L)
{
    L=(DNode*)malloc(sizeof(DNode));
    if(L == NULL )
        return false;
    L->prior = L;
    L->next = L;
    return true;
}

bool Empty(DLinkList L)
{
    if(L->next == L)
        return true;
    else
        return false;
}

bool isTail(DLinkList L,DNode *p)
{
    if(p->next == L)
        return true;
    else
        return false;
}

bool InsertNextDNode(DNode *p, DNode *s)
{
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true; 
}