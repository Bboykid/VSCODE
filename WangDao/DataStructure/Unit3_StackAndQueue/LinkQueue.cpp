#include<stdlib.h>

typedef int Elemtype;
/**
 * @brief 队列的链式存储结构
 * 
 */
//链式队列结点
typedef struct LinkNode
{
    Elemtype data;
    struct LinkNode *next;
}LinkNode;

//链式队列
typedef struct 
{
    LinkNode *front,*rear;
}LinkQueue;

void InitLinkQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next= NULL;
}

bool isEmpty(LinkQueue &Q)
{
    if(Q.front == Q.rear)   return true;
    else return false;
}

void EnQueue(LinkQueue &Q,Elemtype x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
}

bool DeQueue(LinkQueue &Q,Elemtype &x)
{
    if(Q.front == Q.rear)
        return false;
    x = Q.front->data;
    LinkNode *t = Q.front->next;
    Q.front->next = t->next;
    //若果原队列只有一个结点
    if(Q.rear = t)
        Q.rear = Q.front;
    free(t);
    return true;
}