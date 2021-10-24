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

// 存放位置从A[1]开始

// 直接插入排序

void InsertSort(ElemType A[],int n)
{
    for(int i=2;i<=n;i++)
    {
        if(A[i]<A[i-1])
        {
            int j;
            A[0] = A[i];
            for(j=i-1;A[0]>A[j];j--)
            {
                A[j+1] = A[j];
            }
            A[j+1] = A[0];
        }
    }

}

void InsertSort2(ElemType A[],int n)
{
    for(int i=2;i<=n; i++)
    {
        if(A[i]<A[i-1])
        {
            A[0] = A[i];
            int low=1,high = i-1,mid;
            while( low<=high )
            {
                mid = (low+high)/2;
                if(A[mid]<A[0]) low = mid+1;
                else high=mid-1;
            }

            for(int j=i-1;j>high;j--)
            {
                A[j+1] = A[j];             
            }
            A[high+1] = A[0];
        }
    }
}


void ShellSort(ElemType A[],int n)
{
    for(int dk=n/2;dk>=1;dk/=2)
    {
        for(int i=dk+1;i<=n;i++)
        {
            if(A[i]<A[i-dk])
            {
                int j;
                A[0] = A[i];
                for(j=i-dk; j>0&&A[0]<A[j]; j=j-dk )
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

void BubbleSort(ElemType A[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        int flag=1;
        for(int j=0; j<=i; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                flag = 1;
            }
        }
        if(flag==0 )
            break;
    }
}

void QuickSort(ElemType A[],int low,int high)
{
   if(low<high)
   {
        ElemType pivot = A[low];
        int i=low,j=high;
        while(i<j)
        {
            while(i<j && A[j]>pivot )
                j--;
            A[i] = A[j];
            while(i<j && A[i]<pivot )
                i++;
            A[j] = A[i];
        }
        A[i] = pivot;
        QuickSort(A,low,i-1);
        QuickSort(A,i+1,high);
   }
   else
    return;

}


/**
 * @brief 选择排序
 * 
 * 简单选择排序
 * 堆排序
 * 
 */

void SelectSort(ElemType A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i; j<n; j++)
        {
            if(A[j]<A[min])
                min = j;
        }
        Swap(A[i],A[min]);
    }
}



//堆排序

//初始堆
void BuildPileHeap(ElemType A[],int len)
{
    for(int i=len/2;i>0;i--)
    {
        HeadAjust(A,i,len);
    }
}

void HeadAjust(ElemType A[],int k,int len);
{
    A[0] = A[k];
    for(int i=2*k;i<len; i=i*2)
    {
        if(A[i+1]>A[i])
            i++;
        if(A[0]>A[i])
            break;
        else
        {
            A[k]=A[i];
            k=i;
        }
    }
    A[k] = A[0];

}




/**
 * @brief 归并排序
 * 
 */
int B[maxn];
void MergeSort(int A[],int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(A,low,mid-1);
        MergeSort(A,mid,high);
        Merge(A,low,mid,high);
    }
}
void Merge(int A[],int low,int mid,int high)
{
    for(int i=low;i<=high;i++)
    {
        B[i]=A[i];
    }   
    int i,k =low,j=mid;
    while(i<mid && j<=high)
    {
        if(B[i]<B[j])
        {
            A[k++]=B[i++];
        }
        else
        {
            A[k++]=B[j++];
        }
    }

    while ( i<mid )
    {
        A[k++] = B[i++];
    }
    while( j<high )
    {
        A[k++] = B[j++];
    }
    
    
}