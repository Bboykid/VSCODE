#include<stdlib.h>
#define MaxSize 50

/**
 * @brief ADT
 * 
 * InitStack(&S);
 * StackEmpty(&S);
 * Push(&S,x);
 * Pop(&S,&x);
 * GetTop(S,&x);
 * DestroyStack(&S); 
 * 
 */

//顺序栈
typedef int Elemtype;
typedef struct {
    Elemtype data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, Elemtype x)
{
    if( S.top == MaxSize-1 )
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, Elemtype &x)
{
    if(S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S,Elemtype &x)
{
    if(S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}




