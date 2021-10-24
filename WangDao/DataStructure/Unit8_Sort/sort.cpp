#include<stdlib.h>
using namespace std;

typedef int ElemType;


/**
 * @brief 插入排序
 * 
 */

//直接插入排序
void InsertSort(ElemType A[], int n)
{
    int i,j;
    ElemType temp;
    for( i = 1 ; i < n; i++ )
    {
        temp = A[i];
        for( j=i-1 ; temp < A[j]; --j )
        {
            A[j+1] = A[j];
        }
        A[j+1] = temp;
    }
}

// 折半插入排序（查找操作利用折半查找完成）
void HalfInsertSort(ElemType A[],int n)
{
    int i,j,low,high,mid;
    ElemType temp;
    for( i=1 ; i<n ; i++ )
    {
        temp = A[i];
        //设置折半查找的范围(前部有序的范围)
        low = 0;
        high = i-1;
        while( low <= high )
        {
            mid = (low+high)/2;
            //找小于A[i]的下标(已知表中无与A[i]相同的值)
            // if( A[mid]==temp )
            // {
            //     break;
            // }
            if( A[mid] < temp ) //查找右半子表
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        //将表后移
        for( j=i-1; j>=high+1; j-- )
        {
            A[j+1] = A[j];
        }
        A[high+1] = temp;

    }
}


//希尔排序
void ShellSort(ElemType A[],int n)
{
    //A[0]是暂存单元
    int d,i,j;
    for(d=n/2; d>=1; d=d/2)
    {
        for( i=d+1; i<=n ; i++ )
        [
            if( A[i]<A[i+d] )
            {
                A[0] = A[i];//暂存在A[0]
                for( j = i-d; j>0&& A[0]<A[j]; j-=d )
                {
                    A[j+d] = A[j];
                }
                A[j+d] = A[0];
            }
        ]
    }
}


//交换排序

//冒泡排序
void BubbleSort(ElemType A[],int n)
{
    int i,j;
    for( i=0 ;i < n-1 ; i++ )
    {
        for( j= n-1; j>i; j-- )
        {
            if( A[j] < A[j-1] )
            {
                swap(A[j-1],A[j]);
            }
        }
    }
}

//快速排序
void QuickSort(ElemType A[],int low, int high)
{
    if( low < high )
    {
        int i,j;
        i = left;
        j = right;
        ElemType k = A[low];
        while( i<j )
        {
            while( A[j]>k && i<j )
                j--;
            A[i] = A[j];

            while( A[i]<k && i<j )
                i++;
            A[j] = A[i];
        }
        A[i] = k;
        QuickSort(A,low,i-1);
        QuickSort(A,i+1,high);
    }
    else
        return;
}





/**
 * @brief 堆排序
 * 
 * 最大堆
 * 1. 初始化堆——自下向上调整为最大堆
 * 
 */

void BuildMaxHeap(ElemType A[],int len)
{
    for(int i=n/2; i>0;i--)
    {
        //从下向上逐步调整
        HeadAjust(A,i,len);
    }
}

void HeadAjust(ElemType A[],int k;int len)
{
    ElemType temp = A[k];
    for(int i=2*k;i<len;i*=2)
    {
        if(i<len && A[i]<A[i+1])
            i++;
        if(temp>A[i]) break;
        else{
            A[k] = A[i];
            A[i] = temp;
        }
    }
}