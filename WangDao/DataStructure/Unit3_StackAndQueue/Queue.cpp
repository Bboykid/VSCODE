#include<stdlib.h>

#define MaxSize 100

typedef int Elemtype;
//顺序队列
typedef struct Queue
{
    Elemtype data[MaxSize];
    int rear,front;
}SqQueue;





