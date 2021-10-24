
/**
 * @brief KMP算法
 * 
 */

void get_next(int *next, String TT)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[i];
        }
    }
}

int KMP(String S, String T)
{
    int i = 1, j = 0;
    int next[T.length + 1];
    get_next(next, T);

    while (i <= S.length && j <= T.length)
    {
        if (S[i] == T[j] || j == 0)
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > T.length)
    {
        return i - T.length;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief InsertSort
 * 
 */
void InsertSort(int A[], int n)
{
    int i, j;
    for (i = 2; i < n; i++)
    {
        if (A[i - 1] < A[i])
        {
            A[0] = A[i];
            for (j = i - 1; A[j] < A[0]; j--)
            {
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0];
        }
    }
}

void InsertSort2(int A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (A[i - 1] < A[i])
        {
            A[0] = A[i];
            int low = 1, high = i - 1;
            while (low < high)
            {
                mid = (low+high)/2;
                if(A[mid]<A[0])
                {
                    low = mid+1;
                }
                else
                    high = mid - 1;
            }

            for(int j=i-1; j>high; j--)
            {
                A[j+1] = A[j];
            }
            A[high+1] = A[0];
        }
    }
}


void ShellSort(int A[],int n)
{
    for(int dk=n/2; dk>=1; dk/=2)
    {
        for(int i=1+dk; i<=n; i+=dk)
        {
            if(A[i-dk]<A[i])
            {
                int j;
                A[0]=A[i];
                for(j = i-dk ; A[0]<A[j]&&j>0;j-=dk)
                {
                    A[j+dk] = A[j];
                }
                A[j+dk] = A[0];
            }
        }
    }
}