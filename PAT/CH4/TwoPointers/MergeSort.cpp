#include<algorithm>
using namespace std;
const int maxn = 1000;

void merge(int A[], int L1, int R1, int L2, int R2)
{
    int i = L1, j = L2;
    int temp[maxn];
    int k = 0;
    while (i<=R1 && j <= R2)
    {
        if (A[i] < A[j] )
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }
    while( i <= R1 ) temp[k++] = A[i++];
    while( j <= R2 ) temp[k++] = A[j++];

    for (int i = 0; i < k; i++)
    {
        A[L1 + i] = temp[i];
    }
}

void mergeSort(int A[],int left, int right)
{
    if (left < right)
    {
        int mid = (left + right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid + 1, right);
        merge(A,left,mid,mid+1,right);
    }   
}

//迭代实现
void mergeSort2(int A[],int n)
{

    for ( int step = 2; step/2 <= n; step*=2)
    {
        for (int i = 0; i < n; i+=step)
        {
            int mid = i + step/2 -1;
            if (mid + 1 < n)
            {
                merge(A,i,mid,mid+1,min(i + step -1,n));
            }
        }
            
    }
    
}