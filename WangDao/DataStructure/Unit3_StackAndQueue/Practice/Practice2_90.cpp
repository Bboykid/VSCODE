#include<stdlib.h>

typedef char Elemtype;
typedef struct {

}Stack;
/**
 * @brief ADT
 * 
 */
void InitStack(Stack &S);
bool Push(Stack &S,Elemtype e);
bool Pop(Stack &S,Elemtype &e);

/**
 * 1
 * @brief 括号匹配算法
 *  圆括号，方括号，花括号三种，'\0'为终止符
 * 
 */

int Match(char str[])
{
    int i = 0;
    Stack S;
    InitStack(S);
    while (str[i]!='\0')
    {
        switch (str[i])
        {
        case '(':
            Push(S,str[i]);
            break;
        case '{':
            Push(S,str[i]);
            break;
        case '[':
            Push(S,str[i]);
            break;
        //......
        default:
            break;
        }
    }
}