/**
 * @file Dijkstra.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief 伪代码
 * 

for(循环n次)
{
    u = 使用d[u]最小的未被访问结点的编号;
    标记u被访问;
    for( 从u出发所有能到达的顶点v )
    {
        if( v未被访问 && d[u]+u到v距离更小 )
        {
            优化d[v];
            //更新path[v]为u
        }
    }
}

**/

//具体实现

const int MAXV = 1000;
const int INF = 100000000;// INF是一个很大的数

// 1.邻接矩阵表示法
int n,G[MAXV][MAXV];        //顶点数，图的邻接矩阵
int d[MAXV];                //到个顶点的最短距离
int path[MAXV];             //各顶点最短路径的直接前驱
bool visited[MAXV] = {false};//标记是否被访问过

void Dijkstra(int s) // s为起点
{
    //初始化
    fill(d,d+MAXV,INF); 
    d[s] = 0;   

    for( int i = 0; i<n; i++ )//循环n次
    {
        int u = -1,Min = INF;
        //找到是d[u]最小的未被访问结点
        for( int j =0 ; j < n; j++)
        {
            if( d[j] < Min )
            {
                u = j;
                Min = d[j];
            }
        }
        //寻找结束
  
        // 没有找到u，剩下的顶点与u不连通
        if( u==-1 ) return;
  
        //  找到u
        visited[u] = true;//标记已访问
  
        for( int v = 0; v < n; ++v )
        {
            // v未被访问， u到v存在路径。以v为中间结点的路径小于原先的路径d[v]
            if( visited[v]==false && G[u][v]!=INF && d[u] + G[u][v] < d[v] )
            {
                // 优化d[v]
                d[v] = d[u] + G[u][v];
                path[v] = u;
            }
        }
    }

}



// 邻接表版
struct Node {
    int v, dis; // v为边的目标顶点，dis为边的权
}
vector<Node> Adj[MAXV]; //图
int d[MAXV];                //到个顶点的最短距离
int path[MAXV];             //各顶点最短路径的直接前驱
bool visited[MAXV] = {false};//标记是否被访问过

void Dijkstra(int s) // s为起点
{
    //初始化
    fill(d,d+MAXV,INF); 
    d[s] = 0;   

    for( int i = 0; i<n; i++ )//循环n次
    {
        int u = -1,Min = INF;
        //找到是d[u]最小的未被访问结点
        for( int j =0 ; j < n; j++)
        {
            if( d[j] < Min )
            {
                u = j;
                Min = d[j];
            }
        }
        //寻找结束
        // 没有找到u，剩下的顶点与u不连通
        if( u==-1 ) return;
        //  找到u
        visited[u] = true;//标记已访问
        
        //邻接表版本
        for( int j =0 ; j<Adj[u].size(); j++ )
        {
            if( visited[j]==false && d[u]+Adj[u][j].dis < d[v] )
            {
                d[v] = d[u] + Adj[u][j].dis;
                path[v] = u;
            }
        }
    }
}
