#include<stdlib.h>
using namespace std;

typedef int ElemType;


/**
 * @brief 插入排序
 * 
 */


void InsertSort(ElemType A[],int n)
{
    for(int i=2; i<=n; i++)
    {
        if(A[i]<A[i-1]) {
            A[0] = A[i];
            for(int j=i-1;A[0]<A[j];j--)
            {
                A[j+1] = A[j];
            }
            A[j+1] = A[0];
        }
    }

}


/**
 * @brief 折半插入排序
 * 
 * 插入排序的查找部分利用折半查找
 * 
 */

void InsertSort2(ElemType A[],int n)
{
    int i,j,low,high,mid;
    for(i=2;i<=n;i++){
        if(A[i]<A[i-1])
        {
            A[0] = A[i];
            low =1;
            high=i-1;
            while(low<=high) {
                mid = (low+high)/2;
                if(A[mid]<A[i]) {
                    low = mid+1;
                }else {
                    high=mid-1;
                }
            }
            for(j=i;j>=high+1;j--) {
                A[j+1] = A[j];
            }
            A[high+1] = A[0]

        }
    }
}


/**
 * @brief 希尔排序
 * 
 * 理论上
 *  分成dk个数组,每个数组内部有序
 * 实际上
 *  分步长，虚拟数组
 */

void ShellSort(ElemType A[],int n)
{
    for(int dk=n/2;dk>=1;dk=dk/2){
        for(int i=dk+1;i<=n;i++){
            if(A[i] < A[i-dk]) {
                A[0] = A[i];
                for(int j=i-dk;j>0&&A[0]<A[j];j=j-dk){
                    A[j+dk] = A[j]; 
                }
                A[j+dk] = A[0];
            }
        }
    }

}






/**
 * @brief 交换排序
 * 
 */

/**
 * @brief 冒泡排序
 * 
 */

void BubbleSort(ElemType A[],int n)
{
    int flag;
    for(int i=n-1; i>0;i--)
    {
        flag = 0
        for(int j= 0;j<i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if(flag==1){
            break;
        }
    }
}



/**
 * @brief 快速排序
 * 
 */

void QuickSort(ElemType A[],int low,int high)
{
    if( low < high )
    {
        int i=low,j=high;
        ElemType p = A[low];

        while( i<j ) 
        {
            while( i<j && A[j]>p ) j--;
            A[i] = A[j];
            while( i<j && A[i]<p ) i++;
            A[j] = A[i];
        }
        A[i] = p;
        QuickSort(A,low,i-1);
        QuickSort(A,i+1,high);
    }
    else
        return;

}



/**
 * @brief 归并排序
 * 
 */

// left-mid 为第一个表 mid+1-right为第二个表
//二表归并
void Merge(ElemType A[],int left,int mid,int right)
{
    for(int i=left; i<=right;i++)
    {
        B[i] = A[i];
    }
    for(int k=left,i=left,j=mid+1;i<=mid&&j<=right;k++)
    {
        if(B[i]<B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    while(i<=mid) A[k++] = B[i++];
    while(j<=right) A[k++] = B[j++]
}

void MergeSort(ElemType A[],int left,int right)
{
    if(left<right)
    {
        int mid = (low+high)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        Merge(A,left,mid,right);
    }
}


