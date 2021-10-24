#include<stdlib.h>

//结点定义
typedef int ElemType;
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
    L->prior = NULL;
    L->next = NULL;
    return true;
}

void testDLinkList()
{
    DLinkList L;
    InitDLinkList(L);
}

bool Empty(DLinkList L)
{
    if(L->next == NULL)
        return true;
    else
        return false;
}

//在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if( p == NULL )
        return false;
    if( p->next != NULL )
        p->next->prior = s;
    s->next = p->next;
    p->next = s;
    s->prior = p;
}

bool DeleteNextNode(DNode *p)
{
    if(p == NULL) return false;
    DNode *q = p->next;
    if( q == NULL) return false;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

void DestroyList(DLinkList &L)
{
    while (L->next != NULL)
    {
        /* code */
        DeleteNextNode(L);
    }
    free(L);
    L = NULL;
}