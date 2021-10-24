#include<stdlib.h>

int JudgeLegal(char A[])
{
    int i = 0;//下标
    int j=0,k=0;//j为入栈次数，k为出栈次数
    while(A[i]!='\0')
    {
        switch(A[i])
        {
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                break;
            if( k > j )
                return 0;//序列非法
        }
    }
    if( j!=k )
        return 0;
    else
        return 1;//序列合法
}



/**
 * @brief design a share stack
 * 
 * 
 */
const int MaxSize = 100;
typedef int Elemtype;
typedef struct
{
    Elemtype data[MaxSize];
    int top[2];//共享栈的两个指针
} stk;


/**
 * @brief 2019统考真题
 * 问题简述：
 *  设计一个队列，满足条件：
 *      1. 初始时队列为空
 *      2. 入队时，允许增加队列占用空间
 *      3. 出队后，出队元素所占的空间可重复使用，即队列所占空间只增不减。
 *      4. 入队操作和出队操作的时间复杂度都为O(1)
 * 回答一下问题：
 *  1. 该队列是应选择链式存储结构还是顺序存储结构
 *  2. 画出初始队列的状态，并给出判断队空和队满的条件
 *  3. 画出第一元素入队后的队列状态
 *  4. 给出入队操作和出队操作的基本过程
 * 
 * 解答：
 *  1. 顺序存储无法满足要求2的队列占用空间随着入队操作而增加。
 * 根据要求分析：1容易满足；链式存储方便开辟新空间，2满足；3出队后的节点不能真正的释放，而是放在队尾尾指针的后面，共新结点入队时使用。
 * 2.队空：front = next; 队满：front = rear->next
 * 3.
 * 4.
 * 伪代码的形式：
 *  入队操作：
 *      if(front = rear->next) //队满
 *      {
 *          开辟一个新结点
 *          插入到队尾结点后面(队尾指针后移)
 *      }
 *      入队元素保存在到rear所指结点中；
 *      rear = rear->next；
 *      返回;
 *  出队操作：
 *      if(front == rear) //队空
 *      {
 *          出队失败;
 *          返回;
 *      }
 *      取出front所指结点中的元素e;
 *      将front所指结点内容清空并插入带rear后面
 *      front后移;
 *      返回e;
 */






