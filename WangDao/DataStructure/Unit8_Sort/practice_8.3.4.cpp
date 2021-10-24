
typedef int ElemType;
/**
 * @brief 双向冒泡排序算法
 * 
 */
void DoubleBubbleSort(ElemType A[],int n)
{
    int low = 0; high = n-1 ;
    while( low < high )
    {
        for( int i = low ; i <high; i++ )
        {
            if(A[i]>A[i+1])
            {
                swap(A[i],A[i+1]);
            }
        }
        high--;
        for( int j = high; j>low; j-- )
        {
            if(A[j]<A[j-1])
            {
                swap(A[j],A[j-1]);
            }
        }
        low++;
    }
}


//3
/**
 * @brief 将所有奇数移到偶数前面
 * 利用快速排序的思想
 * 
 */
void OddFirst(int A[], int n)
{
    int low=0,high = n-1;
    while(low<high)
    {
        while (i<j && A[i]&2!=0 )//向后寻找第一个偶数元素
        {
            i++;
        }
        while(i<j && A[j]&2==0 )//向前寻找第一个奇数元素
        {
            j--;
        }
        if(i<j);
            swap(A[i],A[j]);
        i++;
        j--;
    }
}

//5
//寻找第k小元素
/**
 * @brief 
 * 方法：
 *  1. 排序
 *  2. 最小堆
 *  3. 利用快速排序的思想
 * 
 */
void FindK(ElemType A[],int k,int low ,int high)
{
    int pivot = A[low];
    int low_temp = low;
    int high_temp = high;
    while(low < high)
    {
        while(low<high && A[high] >= pivot )
            high--;
        a[low] = a[high];
        while(low<high && A[low] <= pivot )
            low++;
        a[high] = a[low];

    }
    a[low] = pivot;
    if( low==k )
        return a[low];
    if( low>k )//在右侧寻找
        return FindK(A,k,low_temp,low-1);
    else
        return FindK(A,k,low+1,high_temp);
}

//6
/**
 * @brief 
 * 利用快速排序的思想
 * 枢轴位置i
 *  1.i = n.2;
 *  2. i<n/2;
 *  3. i>n/2
 */
int setPartition(int a[],int n)
{
    int pivotkey,low=0,low0=0,high=n-1,high0=n-1,flag=1,k=n/2,i;
    int s1=0,s2=0;
    while(flag)
    {
        pivotkey = a[low];
        while(low<high)
        {
            while(low<high && a[high]>=pivotkey )
                --high;
            if(low!=high)
                a[low] = a[high];
            
            while(low<high && a[low]<=pivotkey )
                ++low;
            if(low!=high)
                a[high] = a[low];
        }
        a[low] = pivotkey;
        if(low==k-1)
            flag=0;
        else
        {
            if(low<k-1)
            {
                low0=++low;
                high = high0;
            }
            else
            {
                high0 = --high;
                low = low0;
            }
        }
    }
    for(i=0; i<k; i++)
        s1+=a[i];
    for(i=k; i<n; i++)
        s2+=a[i];

}

typedef enum{RED,WHITE,BLUE} color;//枚举值
void Flag_Arrange(color a[],int n)
{
    int i,j,k;
    i=0;//i之前的元素全为红
    j=0;//工作指针
    k=n-1;//k之后的元素全为蓝
    while( j<=k )
    {
        switch(a[j])
        {
            case RED:
                swap(a[i],a[j]);
                i++;
                j++;
                break;
            case WHITE:
                j++;
                break;
            case BLUE:
                swap(a[j],a[k]);//不设置j++
                k--;
                break;
        }
    }
}
