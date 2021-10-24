#include "QuickUnion.h"

QuickUnion::QuickUnion(int N) : klength(N), count(N)
{
    id = new int[klength];
    //设置id[i]=i表示为根节点，也可以用负数来表示。
    for (int i = 0; i < N; i++)
        id[i] = i;
}

QuickUnion::~QuickUnion()
{
    delete[] id;
}

int QuickUnion::Count()
{
    return count;
}

bool QuickUnion::Connected(int p, int q)
{
    return Find(p) == Find(q);
}

int QuickUnion::Find(int p)
{
    while (p != id[p])
    {
        p = id[p];
    }
    return p;
}
void QuickUnion::Union(int p, int q)
{
    int pRoot = Find(p);
    int qRoot = Find(q);
    //如果p q已经在相同的分量中 则不用采取任何行动
    if (pRoot == qRoot)
        return;
    id[pRoot] = qRoot;
    count--;
    return;
}