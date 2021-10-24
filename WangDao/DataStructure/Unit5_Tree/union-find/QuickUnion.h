#ifndef SORTALGORITHM_QUICKUNION_H
#define SORTALGORITHM_QUICKUNION_H

class QuickUnion
{
private:
    const int klength;
    int *id;   //id数组
    int count; //分量数量
public:
    QuickUnion(int N);
    ~QuickUnion();
    void Union(int p, int q);
    int Find(int p);
    bool Connected(int p, int q);
    int Count();
};

#endif //SORTALGORITHM_QUICKUNION_H