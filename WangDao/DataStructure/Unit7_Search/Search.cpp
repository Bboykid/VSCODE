// #include<iostream>
// using namespace std;

#define int Elemtype;

typedef struct {
    Elemtype *elem;
    int len;    
} SSTable;  //顺序表存储结构

// 顺序查找


// 折半查找
int binary_search(int *A,int len, int key)
{
    int low = 0, high = len - 1;
    int mid;
    while(low <= high )
    {
        mid = (low + high) /2 
        if( A[mid] == key )//查找成功
        {
            return mid;
        }
        //向左半查找
        else if( A[mid] > key )
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
//查找失败
        return -1;

}