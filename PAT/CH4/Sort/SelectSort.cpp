/**
 * @file SelectSort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-22
 * 
 * @copyright Copyright (c) 2021
 * 
 * 选出最小的元素
 */

void selectSort(int *a, int n) 
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i; i < n; i++)
        {
            /* code */
            if(a[j] < a[k])//选出最小的元素
            {
                k = j;
            }
        }
        int temp = a[i];
        a[i] =a[k];
        a[k] =temp;
        
    }
    
}