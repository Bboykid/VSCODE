/**
 * @file A1003.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-27
 * 
 * @copyright Copyright (c) 2021
 * 
 * 说明：此题利用Dijstra算法，在遍历的过程中修改几个步骤
 * 
 * 
 */
#include<iostream>
//memset函数的头文件
#include <cstring>

//fill函数的头文件
#include <algorithm>
using namespace std;
const int MaxV = 510;
const int INF = 100000000;

int N; //the number of cities 
int M; //the number of edges(roads)
int now,dest;//当前城市，目的地
int weights[MaxV]; //每个城市救援队的数目
int Matrix[MaxV][MaxV]; //邻接矩阵存储边
bool vis[MaxV];//标记该城市是否被访问过
int w[MaxV];//每个城市的最大权值
int num[MaxV];//路径条数
int dis[MaxV];//当前结点到每个结点的最小距离

void Dijstra(int st)
{
    fill(dis,dis+MaxV,INF);
    fill(num,num+MaxV,0);
    fill(w,w+MaxV,0);

    //初始化
    dis[st]=0;
    w[st]=weights[st];
    num[st] = 1;
    
    for(int i = 0 ; i<N; i++)
    {    //寻找距离当前结点最近的点
        int Min = INF,u=-1;
        for(int j = 0 ; j<N; j++)
        {
            if(vis[j]==false && dis[j]<Min)
            {
                u = j;
                Min = dis[j];
            }
        }
        if(u==-1)  return; //剩下的节点非连通

        vis[u] = true;//标记已访问
        //以u结点为起点，访问下一节点（更新dis)
        for(int v = 0 ; v < N; v++)
        {
            if(vis[v]==false && Matrix[u][v]!=INF)
            {
                if(dis[u]+Matrix[u][v] < dis[v])
                {
                    dis[v] = dis[u] + Matrix[u][v];
                    w[v] = w[u] + weights[v];
                    num[v] = num[u];
                }
                //找到一条相同长度的路径
                else if(dis[u]+Matrix[u][v]==dis[v])
                {
                    if(w[u]+weights[v]>w[v])
                    {
                        w[v] = w[u] + weights[v];
                    }
                    num[v] +=num[u];
                }
            }
        }


    }


}

int main(int argc, char const *argv[])
{
    cin>>N>>M>>now>>dest;
    for (int i = 0; i < N ; i++)
    {
        cin>>weights[i];
    }
    int a,b,len;
    fill(Matrix[0], Matrix[0]+MaxV*MaxV, INF);    //初始化图G，这里G为二维数组所以要*的形式
    //输入图的边
    for(int i = 0; i<M; i++ )
    {
        cin>>a>>b>>len;
        Matrix[a][b] = len;
        Matrix[b][a] = len;
    }
    Dijstra(now);
    cout<<num[dest]<<" "<<w[dest];

    return 0;
}
