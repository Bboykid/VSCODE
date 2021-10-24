
void quickSort(int A[], int left, int right)
{
    //*************
    //注意这一个起始条件
    if(left < right)//*************
    //*************
    {
        int key = A[left];
        int i = left, j =right;

        while ( i < j )
        {
            while( A[j] > key && i < j )
            {
                j--;
            }
            A[i] = A[j];

            while( A[i] <= key && i < j )
            {
                i++;
            }
            A[j] = A[i];
        }
        A[i] = key;
        quickSort(A,left,i-1);
        quickSort(A,i+1,right);
    }
    else
        return;
}