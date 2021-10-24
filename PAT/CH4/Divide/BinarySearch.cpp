#include<stdio.h>

int binarySearch(int A[], int left, int right, int key)
{
    int mid;
    while (left <= right)
    {
        mid = (left +right)/2;
        if( A[mid] == key)
        {
            return mid;
        }
        else if(A[mid] > key)
        {
            right = mid -1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return -1;
}