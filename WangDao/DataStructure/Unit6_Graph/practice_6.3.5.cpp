/**
 * @file practice_6.3.5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#define MaxVertexNum 100        //顶点数目的最大值
typedef char VertexType;        //顶点的数据类型
typedef int EdgeType;           //带权图中边上权值的数据类型
//2
/**
 * @brief 判断一个无向图G是否为一颗树
 * 
 * 若无向图为一颗树，则进行依次遍历就可以访问到图所有的顶点与所有的边
 * 
 */

bool JudgeTree(Graph G)
{
    // 1. 初始化
    bool visited[MaxVertexNum];
    for( i=1; i<G.vexnum; ++i )
    {
        visited[i] = false;
    }
    int VNum = 0, ENum = 0; //记录访问的顶点数与边数
    // 2. 对图进行一次深度优先遍历
    DFS(G,1,VNum,ENum,visited);

    // 3. 判断所有的顶点是否被访问 判断所有的边是否被访问
    if( VNum==G.vexnum && ENum = 2*(G.vexnum-1)) // 每条边被访问两次
        return true;
    else 
        return false;

} 
void DFS(Graph G, int v, int &VNum, int &ENum, bool visited[] )
{
    visited[v] = true;
    VNum++;
    for(int w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v))
    {
        if( !visited[w] )//该顶点还没有被访问
        {
            ENum++;
            DFS(G,w,VNum,ENum,visited);
        }
    }
}


// 3
/**
 * @brief 图的非递归DFS(用邻接表表示)
 * 
 */
// Text method: 从后往前（顺序入栈，逆序出栈）
void DFS2(Graph G, int v)
{
    //初始化
    Stack S;    
    InitStack(S);
    int k;
    bool visited[MaxVertexNum];
    for( int i = 1; i<=G.vexnum; ++i )
    {
        visited[i] = false;
    }
    //从v结点开始进栈
    Push(S,v);
    visited[v] = true;
    while( !isEmpty(S) )//栈非空
    {
        k = Pop(S);
        visit(k)
        for( w=FirstNeighbor(G,k); w>=0; w=NextNeighbor(G,k,w));
        {
            if( !visited[w] )
            {
                Push(S,w);
                visited[w];
            }
        }
    }

}


// 4
/**
 * @brief 判断是否存在 vi到vj的路径 (邻接表，有向图) 
 * 两种方式： DFS 和 BFS
 * 
 */


// 5
/**
 * @brief 输出Vi到Vj的所有简单路径
 * 
 */