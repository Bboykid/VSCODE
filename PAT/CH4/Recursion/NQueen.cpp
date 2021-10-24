/**
 * @file NQueen.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//method1
//全排列改进法
#include<iostream>
#include<math.h>
using namespace std;


const int maxn = 11;
int n, P[maxn],Exist[maxn] = {false};

int count1 = 0;
void generateP(int index)
{
    //递归边界
    if( index == n + 1 )
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            /* code */
            for (int j = i+1; j < n; j++)
            {
                /* code */
                if(abs(i-j) == (P[i]-P[j]))
                {
                    flag = false;
                    break;
                }
            }
            
        }
        if(flag) 
            count1++;
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        /* code */
        if (Exist[x]==false)
        {
            Exist[x] = true;
            P[index] = x;
            generateP(index+1);
            //回归时清除脏数据
            Exist[x] = false;
        }
        
    }
    
}

//method2 回溯法
//直接对解空间树进行一个限界

void generateP(int index)
{
    //递归边界
    if( index == n + 1 )
    {
       
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        /* code */
        if (Exist[x]==false)
        {
            bool flag = true;
            for (int pre = 1; pre < index; pre++)
            {
                if(abs(index - pre) == abs(P[x] - P[pre]) )
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                    Exist[x] = true;
                P[index] = x;
                generateP(index+1);
                //回归时清除脏数据
                Exist[x] = false;
            }
        
        }
        
    }
    
}

