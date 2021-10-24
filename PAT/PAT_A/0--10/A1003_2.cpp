#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXV = 510;//最多的节点数
const int INF = 100000000;

int N;  //结点数
int M;  //边数
int start,dest;//起点与终点
int G[MAXV][MAXV]; //邻接矩阵用来存放边的信息
int rescues[MAXV];//每个城市救援队的数量

bool visited[MAXV]; //遍历过程中，用来表示节点是否访问过
int d[MAXV];    //遍历过程中 表示起点到当前结点的最小距离
int w[MAXV];    //到当前结点的最大权值(救援队数量)
int num[MAXV];//能够达到最小距离的所有路径数目

void Dijstra(int st)
{
    //初始化
    fill(d,d+MAXV,INF);
    fill(w,w+MAXV,0);
    fill(num,num+MAXV,0);

    d[st] = 0;
    w[st] = rescues[st];
    num[st] = 1;

    //遍历N轮
    for(int i=0; i<N; i++)
    {
        //寻找未被访问的距离起点最小的节点
        int u = -1,Min = INF;
        for(int j=0; j<N; j++)
        {
            if(visited[j]==false && d[j]<Min )
            {
                u=j;
                Min = d[j];
            }
        }
        
        if(u==-1)   return;//没找到，遍历结束或仅剩非连通节点
    
        visited[u] = true;//标记已被访问

        //以u为中间结点找到访问下一节点
        for(int v=0; v<N; v++)
        {
            //v未被访问且以u为中间结点距离别原来的小
            // if( visited[v]==false && d[u]+G[u][v]<d[v] )
            if(visited[v]==false && G[u][v]!=INF)
            {
                if(d[u]+G[u][v]<d[v])
                {
                    //更新d[v]
                    d[v] = d[u]+G[u][v];
                    //更新权值
                    w[v] = w[u] + rescues[v];
                    //更新路径数目 = 到u的路径数
                    num[v] = num[u];
                }
                 //距离相等
                // else if(visited[v]==false && d[u]+G[u][v]==d[v])
                else if( d[u]+G[u][v] == d[v])
                {
                    //判断权值大小
                    if(w[u]+rescues[v] > w[v])
                    {
                        w[v] = w[u]+rescues[v];
                    }
                    //更新路径数
                    num[v] += num[u];
                }
            }
           
        }
    }

}


int main(int argc, char const *argv[])
{
    //输入城市数目
    cin>>N>>M>>start>>dest;
    //初始化图
    fill(G[0],G[0]+MAXV*MAXV,INF);
    //输入每个城市救援队的数量
    for(int i=0; i<N; i++)
        cin>>rescues[i];
    //边的信息
    int x,y,len;
    for(int i=0; i<M; i++)
    {
        cin>>x>>y>>len;
        G[x][y] = len;
        G[y][x] = len;
    }
    Dijstra(start);
    
    //输出结果
    cout<<num[dest]<<" "<<w[dest];
    return 0;
}
