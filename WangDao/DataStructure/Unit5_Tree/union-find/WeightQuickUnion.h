#ifndef SORTALGORITHM_WEIGHTEDQUICKUNION_H
#define SORTALGORITHM_WEIGHTEDQUICKUNION_H

/*
author: windyear
time: 2017-11-26
思路描述：
优化思路是减少每次查找树的根节点的路径长度，之前的方法是固定某一棵树连接到另一棵树上。
而每次都将树的节点少的一方连接到多的一方，可以使树的高度限制在lgN，因为节点少的一棵树的节点的高度加一，节点数目至少翻倍，而一棵树至多翻倍lgN次。
这样就可以优化寻根的路径长度。变成对数级别。
*/

class WeightedQuickUnion {
public:
    WeightedQuickUnion(int N);
    ~WeightedQuickUnion();
    void Union(int p, int q);
    int Find(int p);
    bool IsConnected(int p, int q);
    int Count();
private:
    const int klength;
    int* id;
    int* sizeoftree;
    int count;
};


#endif //SORTALGORITHM_WEIGHTEDQUICKUNION_H 