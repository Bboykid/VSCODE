#include<stdlib.h>
using namespace std;

typedef int ElemType;


/**
 * @brief 插入排序
 * 
 *  直接插入排序
 *  折半插入排序
 *  希尔排序
 * 
 */



void insertSort(ElemType A[],int n)
{
    for(int i=2; i<=n ;i++)
    {
        if(A[i]<A[i-1])
        {
            int j;
            A[0] = A[i];
            for(j=i-1; A[j]<A[0];j--)
            {
                A[j+1] = A[j];
            }
            A[j+1] = A[0];
        }
    }
}


void insertSort2(ElemType A[], int n)
{
    for(int i=2; i<=n; i++)
    {
        if(A[i]<A[i-1])
        {
            A[0]=A[i];
            int low=1,high = i-1,mid;
            while(low<=high)
            {
                mid = (low+high)/2;
                if(A[mid]<A[0])
                    low = mid+1;
                else
                    high = mid-1;
            }
            for(int j=i-1;j>high;j--)
            {
                A[j+1] = A[j];
            }
            A[high+1] = A[0];
        }
    }
}



void shellSort(ElemType A[],int n)
{
    for(int dk=n/2; dk>=1; dk=dk/2)
    {
        int i;
        for(i=dk+1;i<=n;i++)
        {
            if(A[i]<A[i-dk])
            {
                int j;
                A[0] = A[i];
                for(j=i-dk; j>0&&A[0]<A[j];j-=dk)
                {
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
 * 冒泡排序
 * 快速排序
 * 
 */

void bubbleSort(ElemType A[],int n)
{
    for(int i=0; i<n-1;i++)
    {
        int flag = 1;
        for(int j=n-2;j>=i;j--)
        {
            if(A[j+1]<A[j])
            {
                  swap(A[j+1],A[j]);
                  flag=0;
            }
        }
        if(flag)
            break;
    }
}


void quickSort(ElemType A[],int low,int high)
{
    if(low<high)
    {
        int i=low,j=high;
        ElemType pivot = A[low];
        while(i<j)
        {
            while(i<j && A[j]>pivot) j--;
            A[i] = A[j];
            while(i<j && A[i]<pivot) i++;
            A[j] = A[i];
        }
        A[i]=pivot;

        quickSort(A,low,i-1);
        quickSort(A,i+1,high);

    }

}




/**
 * @brief 选择排序
 * 
 * 简单选择排序
 * 堆排序
 * 
 */



void selectSort(ElemType A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min =i;
        for(int j=i+1; i<n;i++)
        {
            if(A[j]<A[min])
                min=j;
        }
        swap(A[i],A[min]);
    }
}



void buildMaxHeap(ElemType A[],int len)
{
    for(int i=len/2; i>0; i--)
    {
        HeapAjust(A,i,len);
    }
}

void HeapAjust(ElemType A[],int k,int len)
{
    A[0] = A[k];
    for(int i=2*k; i<=n; i*=2)
    {
        if(A[i+1]>A[i] && i<len)
            i++;
        if(A[0]>=A[i])
            break;
        else
        {
            A[k] = A[i];
            k=i;
        }
    }
    A[k] = A[0];
}



/**
 * @brief 归并排序
 * 
 */

//二路归并排序

void merge(ElemType A[],int low,int mid,int high)
{
    ElemType B[maxn];
    for(int i =low; i<=high ; i++)
    {
        B[i] = A[i];
    }
    int i,j,k;
    for( i=low,j=mid+1;k=low; i<=mid&&j<=high;)
    {
        if(B[i]<B[j])   A[k++] =B[i++];
        else A[k++] = B[j++];
    }
    
    while(i<=mid) A[k++] = B[i++];
    while(j<=high) A[k++] = B[j++];

}

void mergeSort(ElemType A[],int low,int high)
{
    int mid = (low+high)/2;
    mergeSort(A,low,mid);
    mergeSort(A,mid+1,high);
    merge(A,low,mid,high);
}