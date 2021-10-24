/**
 * @file StaticLinkList.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-06
 * 
 * @copyright Copyright (c) 2021
 * 
 * 静态链表
 * 
 */

#include<stdlib.h>
#define MaxSize 10

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    int next;
}SLinkList[MaxSize];

void testSLinkList()
{
    SLinkList a;
}

/** 等价于
 * 
struct Node
{
    ElemType data;
    int next;
}

void testSLinkList()
{
    struct Node a[MaxSize];
}
**/