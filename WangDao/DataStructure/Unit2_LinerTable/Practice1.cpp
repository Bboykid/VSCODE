#include<stdlib.h>
#define InitSize 100
#define maxsize 100

typedef int ElementType;
//顺序表 第i个元素存放在data[i-1]位
typedef struct 
{
    ElementType *data;
    int length;
    int MaxSize;
} SeqList;

void InitList( SeqList &L )
{
    L.data = (ElementType*)malloc(sizeof(ElementType)* InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseListSize( SeqList &L, int len ) 
{
    ElementType *p = L.data;
    L.data = (ElementType*)malloc(sizeof(ElementType)*(L.MaxSize + len));
    for( int i = 0 ; i < L.length; i++ ) 
    {
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

bool ListInsert(SeqList &L, int i, ElementType e)//在i位置插入元素e
{
    if( i < 1 || i > L.length + 1 )
        return false;
    if( L.length >= L.MaxSize )
        return false;
    for(int j = L.length; j >= i; j-- )
    {
        L.data[j] = L.data[j-1];
    }
    //第i个元素放在 data[i-1]处
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int i , ElementType &e)
{
    if( i < 1 || i > L.length )
        return false;
    e = L.data[i-1];
    for(int j = i ; j<L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

// search by position
ElementType GetElem(SeqList L, int i)
{
    return L.data[i-1];
}
// search the location of a value
int LocateElem( SeqList L, ElementType e)
{
    for(int i = 0 ; i < L.length; i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}

void PrintList(SeqList L);

bool Empty(SeqList L);

void DestroyList(SeqList &L);

// 综合应用题


// 1
bool Del_Min_solution1(SeqList &L, ElementType &value)
{
    //空表，返回false
    if(L.length == 0)
        return false;
    ElementType min = L.data[0];
    int pos = 0;

    for(int i = 0 ; i<L.length ; i++)
    {
        if(L.data[i] < min)
        {
            min = L.data[i];
            pos = i;
        }
    }
    
    //空出的位置由最后一个数填补
    ElementType key = L.data[L.length--];
    L.data[pos] = key;

    // 顺序表长度减一
    L.length--;

    //返回 最小值
    value = min;
    //返回操作成功
    return true;

}

// 2
void Traver_solution2(SeqList &L)
{
    int mid = L.length/2;
    ElementType temp;
    for (int i = 0; i < mid; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[ L.length - 1 - i ];//将倒数第 i个数换成 第i个数(从0开始)
        L.data[ L.length - 1 - i ] = temp;
    }
}

// 3
void DelX_solution3(SeqList &L, ElementType x)
{
    int cnt = 0;
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i] != x )
        {
            L.data[cnt] = L.data[i];
            cnt++;
        }
    }
    L.length = cnt;   

}
//method 2
void DelX_solution3_2(SeqList &L, ElementType x)
{
    // x的个数
    int cnt_x = 0;
    int i = 0;
    while ( i<L.length)
    {
        if( L.data[i] == x )
            cnt_x++;
        else
            L.data[i-x] = L.data[i];
        i++;
    }
    L.length = L.length - cnt_x;
    
}


//4
bool  Del_s_t(SeqList &L,int s, int t)
{
    if (L.length <= 0 || s > t )
    {
        return false;
    }
    int start = 0,end = L.length-1;
    for (int i = 0; i < L.length; i++)
    {
        if( L.data[i] >= s )
        {
            start = i;
            break;
        }
    }
    if(start >= L.length )
        return false;
    
    for (int i = start; i < L.length; i++)
    {
        if( L.data[i] > t )
        {
            end = i;
            break;
        }
    }

    for (int i = start,j = end; j < L.length ; i++,j++)
    {
        L.data[i] = L.data[j];
    }
    L.length -= end - start - 1;
    return true;
}

//5
bool Del_s_t_2(SeqList &L, int s ,int t)
{
    int cnt = 0;
    int i;
    
    if( L.length <= 0 || s > t )
        return false;
    
    for( i=0 ; i<L.length; i++ )
    {
        
        if( L.data[i] >= s && L.data[i] <= t )
        {
            cnt++;
        }
        else
        {
            L.data[ i - cnt ] = L.data[i];
        }
                
    }
    L.length -= cnt;
    
    return true;    
}

//6
bool Del_same(SeqList &L)
{
    if( L.length == 0)
        return false;
    int cnt = 0;//删除元素的个数
    int i;
    //从第二个开始遍历
    for (i = 1; i < L.length; i++)
    {
        if (L.data[i-1] == L.data[i])
        {
            cnt++;
        }
        else
        {
            L.data[i-cnt] = L.data[i];
        }
        
    }
    L.length -= cnt;
    return true;
}
//method2
bool Del_same_2(SeqList &L)
{
    if(L.length == 0)
        return false;
    int i,j;
    for( i=0, j=1 ; j<L.length; j++)
    {
        if(L.data[i] != L.data[j] )
            L.data[i++] = L.data[j];
    }
    L.length = i+1;
    return true;
}

//7 有重复
bool Merge_List(SeqList A,SeqList B,SeqList &L)
{
    if(A.length + B.length > maxsize)
        return false;
    int i =0, j=0 ,k=0;
    while ( i<A.length && j<B.length )
    {
        if( A.data[i] <= B.data[j] )
            L.data[k++] = A.data[i++]; 
        else    
            L.data[k++] = B.data[j++];
    }
    while ( i < A.length)
        L.data[k++] = A.data[i++];
    while( j < B.length)
        L.data[k++] = B.data[j++];
    
    L.length = k;
    return true;
}


//8
void Reverse(ElementType A[] ,int left,int right, int size)
{
    if( left >= right || right > size )
    {
        return;
    }
    int mid = (left+right)/2;
    for (int i = 0; i <= mid -left; i++)
    {
        ElementType temp = A[left+i];
        A[left+i] = A[right -i];
        A[right - i] =temp;
    }
}

void Exchange(ElementType A[],int m ,int n, int size)
{
    Reverse(A,0,m+n-1,size);
    Reverse(A,0,n-1,size);
    Reverse(A,n,m+n-1,size);
}


//9 search a key--x and exchange the next
bool Search_Exchange(ElementType L[],ElementType x,int n)//n 为顺序表中元素个数
{
    int low =0, high = n-1,mid;
    while (low <= high)
    {
        mid = (low +high)/2;
        if( L[mid] == x )
            break;
        else if( L[mid] < x )
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(L[mid] == x && mid != n-1)//若x为顺序表中最后一个元素的值，则不执行该操作
    {
        ElementType temp = L[mid];
        L[mid] = L[mid +1];
        L[mid + 1] =temp;
    }
    if(low > high)//查找失败，执行插入操作
    {
        for (int i = n ; i > mid; i--)
        {
            L[i] = L[i-1];
        }
        L[mid] = x;
    }
}


//10 (2020统考)
// move left n position 
/**
 * 算法基本思想
 * 将整个数组看成两个数组
 * A(1 ~ p) B(p+1 ~ n)
 * L(A,B) -> L(B,A)
 * 先将 A，B 翻转  L -> {a(p-1),a(p-2),...,a(0),  a(n-1),a(n-2),...,a(p) }
 * 此时从右往左看 正是所求数组
 * 因此将整体翻转得到结果
 */
void Reverse(ElementType L[], int left, int right)
{
    int i,j,cnt;
    cnt = (right - left +1)/2;
    ElementType temp;
    for( i = 0; i<cnt; i++)
    {
        temp = L[i];
        L[i] = L[right -i];
        L[right -i] = temp;
    }
}

void solution(ElementType L[],int p,int n)
{
    Reverse(L,0,p-1);
    Reverse(L,p,n-1);
    Reverse(L,0,n-1);
}



//11 (2011统考)
/**
 * @brief 算法思想
 * 采用分治法
 * 分别求两个升序序列A,B的中位数，比较之后舍弃不可能成为中位数的值
 * 过程如下：
 * 设 a,b 分别为A，B的中位数
 * 1. a = b,则 a或b 为所求的中位数
 * 2. a < b,则舍弃A序列中小的一半，舍弃B序列中大的一半，两次舍弃的长度相等
 * 3. a > b,则舍弃A序列中较大的一半，舍弃B序列中较小的一半，两次舍弃的长度相等
 * 
 */

int M_Search(int A[], int B[], int n)
{
    //s1,d1,m1 为序列A的首位数，末位数，中位数的下标
    int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
    while (s1 != d1 && s2 != d2)//A，B都只剩一个数时结束
    {
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if( A[m1] == B[m2] )
            return A[m1];
        else if( A[m1] < B[m2] )//A的中位数小于B的中位数
            {
                if( (s1+d1)%2 == 0 )//元素个数为奇数
                {
                    s1 = m1;
                    d2 = m2;
                }
                else
                {
                    s1 = m1 + 1;
                    d2 = m2;
                }
            }
        else
        {
            if( (s1+d1)%2 == 0)
            {
                d1 = m1;
                s2 = m2;
            }
            else
            {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return A[s1]<B[s2] ? A[s1] : B[s2];//返回小的
}


//12 (2013统考)
/**
 * @brief 算法思想
 * 主元素的个数一定大于数组元素个数的一半
 * 若设置一个计数器，遍历一边数组，遇到主元素加1，遇到非主元素减1，遍历结束后，计数器的值一定是个正数
 * 利用这个特点来甄别主元素
 * 
 */
int Majority(int A[], int n)
{
    // first step: choose the candidate
    int count = 0;
    int key = A[0];
    for( int i = 1 ; i<n; i++ )
    {
        if(A[i] == key)
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count < 0)
        {
            key = A[i];
            count = 1;
        }
    }
    //check the qualification
    int cnt = 0;
    for(int i = 0 ; i<n ;i++)
    {
        if( A[i] == key )
            cnt++;
    }
    if(cnt > n/2) return key;
    else return -1;
}



//13 (2018统考)
/**
 * my method
 * @brief 算法思想
 * 要求时间上尽可能高效
 * 不妨用空间换时间
 * 给了 n 个正数，那么 未出现的最小正整数一定在(1~n+1)之间
 * 设置一个标志数组，遍历原数组，若原数组的值在1~n内,则标志数组设为false,其它情况不予考虑也不影响
 * 最后遍历标志数组，找出标志位为true的最小下标
 * 
 */

int Find_Min_Int(int A[],int n)
{
    bool *flag = (bool*)malloc(sizeof(bool)*(n+2));
    for(int i = 0 ;i < n ;i++)
    {
        if(A[i]>0 && A[i] <=n )
        {
            flag[A[i]] =false;
        }
    }
    for(int i =1 ;i<n+2; i++)
    {
        if(flag[i] == true)
            return i;
    }
}


// 14 （2020统考）
/**
 * @brief 算法思想
 * 
 * 1. 使用D_Min记录所有已处理的三元组的最小距离，初值为一个足够大的整数
 * 2. 集合 S1,S2,S3分别保存在数组A,B,C中。
 * 数组的下标变量i=j=k=0,当i<|S1|、j<|S2|、k<|S3|时，|S|表示集合中元素的个数，循环执行下面的操作。
 *  (a) 计算(A[i],B[j],C[k]的距离D)
 *  (b) 若D<D_Min，则D_Min=D
 *  (c) 将 A[i],B[j],C[k]的最小值的下标加1
 * 3. 输出D_Min，结束
 * 
 */

const int MAX = 1000000;
int abs_(int a)//计算绝对值
{
    if(a<0)
        return -a;
    else
        return a;
}

bool Is_Min(int a, int b, int c)//a是否是三者中的最小值
{
    if(a<=b && a<=c)
        return true;
    else
        return false;
}

int findMinofTrip(int A[], int B[],int C[],int length_A,int length_B,int length_C)
{
    int i,j,k,D,D_Min = MAX;
    i=j=k=0;
    while( i<length_A && j<length_B && k<length_C && D_Min>0 )
    {
        //当前距离之和
        D = abs_(A[i]-B[j]) + abs_(A[i]-C[k]) + abs_(B[j]-C[k]);
        if( D<D_Min )//update
            D_Min = D;
        //跳到下一节点
        if(Is_Min(A[i],B[j],C[k]))
            i++;
        else if(Is_Min(B[j],A[i],C[k]))
            j++;
        else
            k++;
    }
    return D_Min;
}