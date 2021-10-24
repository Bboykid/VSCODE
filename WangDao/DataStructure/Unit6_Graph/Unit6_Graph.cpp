/**
 * @file Unit6_Graph.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//图的存储类型
//邻接矩阵
#define MaxVertexNum 100        //顶点数目的最大值
typedef char VertexType;        //顶点的数据类型
typedef int EdgeType;           //带权图中边上权值的数据类型
typedef struct {
    VertexType Vex[MaxVertexNum];//顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
    int vexnum,arcnum; //图的当前顶点数和弧数
}MGraph;

// 邻接表
typedef strcut ArcNode {        //边表结点
    int adjvex;                 //该弧所指向的顶点的位置
    struct ArcNode *next;       //指向下一条弧的指针
    //InfoType info;            //网的边权值
}ArcNode;

typedef sturct VNode {          //顶点表结点
    VertexType data;            //顶点信息
    ArcNode *first;             //指向第一条依附该顶点的的弧的指针
}VNode,AdjList[MaxVertexNum];

typedef struct{
    AdjList vertice;
    int vexnum,arcnum;
}  ALGraph;

//ADT
Adjacent(G,x,y);        //判断图G是否存在边<x,y>或(x,y)
Neighbors(G,x);         //列出图G中与结点x邻接的边
InsertVertex(G,x);      //在图中插入顶点x
DeleteVertex(G,x);      //在图中删除顶点x
AddEdge(G,x,y);         //若边(x,y)或<x,y>不存在，则向图中添加该边
RemoveEdge(G,x,g);      //若边(x,y)或<x,y>存在，则从图中删除该边
FirstNeighbor(G,x);     //求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1
NextNeighbor(G,x,y);    //假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个顶点，则返回-1
Get_edge_value(G,x,y);  //获取图中边对应的权值
Set_edge_value(G,x,y);  //设置图中边对应的权值


/**
 * @brief BFS
 * 
 */
bool visited[MaxVertexNum];     //访问标记数组
void BFSTraverse(Graph G)
{
    for(i=0; i<G.vexnum; ++i)
        visited[i] = false;     //标记访问数组
    InitQueue(Q);               //初始化辅助队列
    for(i=0 ; i<G.vexnum; ++i)
    {
        if(!visited[i])         //对每一个连通分量进行BFS
            BFS(G,i);   
    }
}
void BFS(Graph G, int v)
{
    visit(v);
    visited[v] = TRUE;
    Enqueue(Q,v);
    while(!Q.isEmpty(Q))
    {
        Dequeue(Q,v);
        for( w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w) )
        {
            if(!visited[w])
            {
                visit(w);
                visited[w] = TRUE;
                Enqueue(Q,v);
            }
        }
    }
}
//  BFS求解非带权图的单元最短路径
void BFS_Min_Distance(Graph G,int u) //图G中到顶点u边数最少的路径
{   
    //d[i]表示从u到i的最短路径
    for( i=0; i<G.vexnum; ++i )
    {
        d[i] = -1; //初始化路径长度
    }
    visited[u] = TRUE;
    d[u] = 0;
    EnQueue(Q,u);
    while( !isEmpty(Q) )
    {
        DeQueue(Q,u);
        for( w = FirstNeighbor(u); w>=0; w=NextNeighbor(U) )
        {
            if(!visited[w])
            {
                d[w] = d[u] + 1;    //路径长度+1
                visited[w] = TRUE;
                EnQueue(Q,w);       //结点入队
            }
        }
    }
}




/**
 * @brief DFS
 * 
 */
void DFSTraverse(Graph G)
{
    for( v=0; v<G.vexnum; ++v )
        visited[v] = false;
    for( v=0; v<G.vexnum; ++v )
    {
        if(!visited[v])
            DFS(G,v);
    }
}
void DFS(Graph G,int v)
{
    visit(v);
    visited[v] = True;
    for( w=FirstNeighbor(G,v); w>=0; w=NextNeighbor(G,v,w) )
    {
        if(!visited[w])
            DFS(G,w);
    }
}

