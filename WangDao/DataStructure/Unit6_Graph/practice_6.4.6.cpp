/**
 * @file practice_6.4.6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#define MaxVertexNum 100        //顶点数目的最大值
typedef char VertexType;        //顶点的数据类型
typedef int EdgeType;           //带权图中边上权值的数据类型

/**
 * @brief DFS如何实现拓扑排序？
 * 
 * @analisis:   
 *      DFS递归调用
 *    1.假设结点u是结点v的祖先，在调用DFS访问u的过程中，必然会调用DFS访问v，
 *      且访问u的结束时间一定晚于其子孙v的结束时间。因此，可以设置一个时间标记，在DFS结束的时候记录每个结点的访问DFS调用的结束时间。
 *      u的结束时间，一定晚于v的结束时间。 
 *    2.若结点u和v没有关系，这两个结点的拓扑关系任意。
 *
 */

//  下面对DFS进行改造，在其结束时加一个时间
int time = 0;
int visited[MaxVertexNum];
int times[MaxVertexNum];
void DFSTraveser(Graph G)
{

}
void DFS(Graph G, int u) //对结点u进行 DFS
{
    visited[u] = true;
    visit(u);
    for( w=FirstNeighbor(G,u); w>=0; w=NextNeighbor(G,u,w))
    {
        if( !visited[w])
        {
            DFS(G,w);
        }
    }    
    time++;
    times[u] = time;    
}
/**
 * 深度优先遍历结束后，可以按结束时间降序输出，得到的序列为拓扑排序
 * 
 */



//  11(2014统考真题)
/**
 * @brief OSPF
 * 
 */





//  12(2018统考真题)
/**
 * @brief 
 * 
 */