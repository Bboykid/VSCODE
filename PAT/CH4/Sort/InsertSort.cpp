void insertSort(int A[], int n)
{
    for(int i= 2; i <= n ; i++)
    {
        int j =i;
        int temp = A[i];
        while (j>=1 && A[j] < A[i])
        {
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp; 
    }
}