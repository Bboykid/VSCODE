/**
 * @file A1004.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Copyright (c) 2021
 * 
 * INPUT:
 *  N:结点数
 *  M:非叶节点数
 *  M行
 *      ID:结点ID K:孩子数 ID[]:每个孩子节点的ID
 * 
 * OUTPUT:
 *  number of leaves every level 
 * 
 * 
 */

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * @brief 算法思想
 * 方案1：
 * 
 * map<int,vector<int>>: 层数，及其对应的节点的id
 * NonLeaf[N]:每一层的非叶节点数
 * 
 * 读取每一行时：
 *      读取第一个数ID:从map中寻找其所在的层次level,第level层非叶节点+1(NonLeaf[level]+1)      @tip:这里不好找层次，此方案不好
 *      对于其K个孩子：他们的层次都为(level+1)，将其存入map<level+1>中
 *  
 * 输出时:
 *      map中元素的数量为其层次数
 *      第i层中vector.size()-NonLeaf[i]为其叶子结点数
 *
 * 
 * 方案2：（更快）
 *  不完全对，建立在输入有序的情况下正确
 *  int IdLevel[N];//记录每个结点的层次
 *  int num[N];//记录每层的叶子节点数
 *  
 */
const  int MaxN = 110;

int N;//总结点数
int M;//非叶节点数
int IdLevel[MaxN];//每个结点的层次
int num[MaxN];//每层的叶子结点数
int Level;//总层次数

int main(int argc, char const *argv[])
{
    int ID,K,temp;//ID表示输入非叶节点的ID，K表示其孩子数，temp暂存孩子的ID
    int h;//表示输入的非叶节点的孩子的层次数;
    //初始化
    fill(IdLevel,IdLevel+MaxN,0);
    fill(num,num+MaxN,0);

    IdLevel[1] = 1;
    num[1]=1;//第一层只有根节点

    cin>>N>>M;

    for(int i=0; i<M; i++ )
    {
        cin>>ID>>K;
        h = IdLevel[ID] + 1;
        //非叶节点 K!=0
        if(h>Level)
        {
            Level = h;
        }
        for(int j=0; j<K; j++)
        {
            cin>>temp;
            IdLevel[temp] = h;
            num[h]++;
        }
        num[h-1]--;//非叶节点所在的层次中叶子结点数-1
    }

    //OUTPUT
    cout<<num[1];
    if( Level>=2 )
    {
        for(int i = 2; i<=Level;i++ )
        {
            cout<<" "<<num[i];
        }
    }
    return 0;
}
