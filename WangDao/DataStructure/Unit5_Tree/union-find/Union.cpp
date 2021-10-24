
int Find(int S[], int x) //找到x的根
{
    while (S[x] >= 0)
    {
        x = S[x];
    }
    return x;
}

int Find2(int S[], int x)//优化的Find算法
{
    int root = x;
    while(S[root]>=0)
    {
        root = S[root];
    }
    while(x!=root)
    {
        int t= S[x];    //t保存x的父节点
        S[x] == root;   //x直接挂到根下面
        x = t;      
    }
}


void Union(int S[], int root1, int root2)
{
    if(S[root1] != S[root2])
    {
        S[root2] = root1;
    }
}

///Union的优化，小树并到大树
void Union2(int S[],int root1,int root2)
{
    if(root1 != root2)
    {
        
        if(S[root1] < S[root2])
        {
            S[root2] = root1;
            S[root1] += S[root2];
        }
        else
        {
            S[root1] =root2;
            S[root2] += S[root1];
        }
    }
}


//application1 
//判断图的连通分量数
int ComponentCount(int grid[n][n])
{
    int S[n];//创建并初始化并查集
    for(int i=0;i<=n;i++)
    {
        S[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(grid[i][j]>0)//存在边
            {
                int root1 = Find(S,i);
                int root2 = Find(S,j);
                if(root1 != root2)
                {
                    Union(S[],root1,root2);
                }
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(S[i]<0)
            count++;
    }
    return count;
}


int ComponentCount(int grid[n][n])
{
    int S[n];//创建并初始化并查集
    for(int i=0;i<=n;i++)
    {
        S[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(grid[i][j]>0)//存在边
            {
                int root1 = Find(S,i);
                int root2 = Find(S,j);
                if(root1 != root2)
                {
                    Union(S[],root1,root2);
                }
                else{
                    return 1;
                }
            }
        }
    }

}