/**
 * @file SqQueue.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-07
 * 
 * @copyright Copyright (c) 2021
 *
 * InitQueue(&Q)
 * DestroyQueue(&Q)
 * EnQueue(&Q, x)
 * DeQueue(&Q,&x)
 * GetAhead(&Q,&x)
 * QueueEmpty(Q)
 */

#include<stdlib.h>
#define MaxSize 10

typedef int ElemType;
typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;
} SqQueue;

void InitQueue(SqQueue &Q)
{   
    Q.front = 0;
    Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

bool QueueFull(SqQueue Q)
{
    if((Q.rear+1) % MaxSize == Q.front)
        return true;
    else    
        return false;
}

bool EnQueue(SqQueue &Q, ElemType x)
{
    if( (Q.rear+1)%MaxSize == Q.front )
        return false;
    Q.data[Q.rear] = x;
    Q.rear= (Q.rear+1)%MaxSize;
    return false;
}

bool DeQueue(SqQueue &Q, ElemType &x)
{
    if(Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
}

bool GetHead(SqQueue Q, ElemType &x)
{
    if(Q.rear == Q.front)
        return false;
    x=Q.data[Q.front];
    return true;
}