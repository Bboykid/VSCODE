#include"WeightQuickUnion.h"

WeightedQuickUnion::WeightedQuickUnion(int N):klength(N),count(N) {
    id=new int[klength];
    sizeoftree=new int[klength];
    for (int i = 0; i < klength; i++)
    {
        id[i]=i;
        sizeoftree[i]=i;
    }
    
}
WeightedQuickUnion::~WeightedQuickUnion(){
    delete[] id;
    delete[] sizeoftree;
}
int WeightedQuickUnion::Find(int p) {
    while (p!=id[p])
    {
        p = id[p];
    }
    return p;   
}
void WeightedQuickUnion::Union(int p,int q){
    int pRoot=Find(p);
    int qRoot=Find(q);
    if(pRoot==qRoot) return;

    if (sizeoftree[pRoot]<sizeoftree[qRoot]) {
        id[pRoot] = qRoot;
        sizeoftree[qRoot]+=sizeoftree[pRoot];
    }
    else {
        id[qRoot]=pRoot;
        sizeoftree[pRoot]+=sizeoftree[qRoot];
    }
    count--;
}

int WeightedQuickUnion::Count() {
    return count;
}

bool WeightedQuickUnion::IsConnected(int p,int q)
{
    return Find(p)==Find(q);
}