#include<stdlib.h>

/**
 * @brief 链栈
 * 
 */

typedef int Elemtype;
typedef struct Linknode{
    Elemtype data;
    struct Linknode *next;
} *LiStack;