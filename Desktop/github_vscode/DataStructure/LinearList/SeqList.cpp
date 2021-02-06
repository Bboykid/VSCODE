#include<stdlib.h>
#define InitSize 10

typedef int ElementType;
//顺序表 第i个元素存放在data[i-1]位
typedef struct 
{
    ElementType *data;
    int length;
    int MaxSize;
} SeqList;

void InitList( SeqList &L )
{
    L.data = (ElementType*)malloc(sizeof(ElementType)* InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseListSize( SeqList &L, int len ) 
{
    ElementType *p = L.data;
    L.data = (ElementType*)malloc(sizeof(ElementType)*(L.MaxSize + len));
    for( int i = 0 ; i < L.length; i++ ) 
    {
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

bool ListInsert(SeqList &L, int i, ElementType e)//在i位置插入元素e
{
    if( i < 1 || i > L.length + 1 )
        return false;
    if( L.length >= L.MaxSize )
        return false;
    for(int j = L.length; j >= i; j-- )
    {
        L.data[j] = L.data[j-1];
    }
    //第i个元素放在 data[i-1]处
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int i , ElementType &e)
{
    if( i < 1 || i > L.length )
        return false;
    e = L.data[i-1];
    for(int j = i ; j<L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

// search by position
ElementType GetElem(SeqList L, int i)
{
    return L.data[i-1];
}
// search the location of a value
int LocateElem( SeqList L, ElementType e)
{
    for(int i = 0 ; i < L.length; i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}
