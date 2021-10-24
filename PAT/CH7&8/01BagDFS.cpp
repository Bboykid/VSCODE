#include<cstdio>
const int maxn = 30;

int n, W,maxValue;
int weights[maxn],values[maxn];

void DFS(int index, int sumW, int sumV)
{
    if (index == n)
    {
        if(sumW <= W && sumV > maxValue )
            maxValue = sumV;
        return;
    }

    DFS(index + 1, sumW, sumV);
    DFS(index + 1,sumW + weights[index], sumV + values[index]);
    
}

int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&W);
    for(int i = 0 ; i< n ; i++)
    {
        scanf("%d",&weights[i]);
    }
    for(int i = 0 ; i< n ; i++)
    {
        scanf("%d",&values[i]);
    }
    DFS(0,0,0);
    printf("%d\n",maxValue);

    return 0;
}
