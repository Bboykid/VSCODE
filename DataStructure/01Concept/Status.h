/**
 * @file Status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef STATUS_H
#define STATUS_H

//状态码
#define TRUE        1
#define FALSE       0
#define YES         1
#define NO          0
#define ERROR       0
#define SUCCESS     1
#define UNSUCCESS   0
#define INFEASIBLE  -1

#ifndef _MATH_H_
#define OVERFLOW    -2
#define UNDERFLOW   -3
#endif

#ifndef NULL
#define NULL    ((void*)0)
#endif

//状态码识别类型

typedef int Status;

/*宏函数*/

#define Wait(x)\
{\
    double _Loop_Num_;\
    for(_Loop_Num_=0.01; _Loop_Num<=100000.0*x;_Loop_Num+=0.01)\
    ;\
}//设立一个空循环

//按Enter键继续
#define PressEnter\
{\
    fflush(stdin);\
    printf("Press Enter...");\
    getchar();\
    fflush(stdin);\
}

#endif