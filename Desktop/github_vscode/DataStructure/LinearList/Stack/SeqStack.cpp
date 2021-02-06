#include<stdio.h>
#define MaxSize 10

typedef int ElemType;
typedef struct SeqStack
{
    ElemType data[MaxSize];
    int top;
} SqStack;

void testStack()
{
    SqStack S;
}


//设计方式 top指向栈顶元素
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

bool Push(SqStack &S, ElemType x)
{
    //栈满
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x)
{
    if(S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}