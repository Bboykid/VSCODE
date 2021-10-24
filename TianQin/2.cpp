

// Dijkstra

bool visited[n];
int dist[n];
int path[n];
void shortPaht(int n,int v,Graph G,bool visit[],int dist[],int path[])
{
    for(int i=0; i<n; i++)
    {
        if(G[v][i]<INF)
        {
            dist[i]=G[v][i];
            path[i] = v;
        }
    }

    visit[v] = true;
    path[v] = -1;

    for(int i=0; i<n; i++)
    {
        int u=0;
        int min=INF;
        for(int j=0;j<n;j++)
        {
            if(visit[j]==false && dist<min)
            {
                u=j;
                min = dist[j];
            }
        }
        visit[u]=true;

        for(int j=0; j<n; j++)
        {
            if( visit[j]==false && G[u][j]+dist[u] < dist[j] )
            {
                dist[j] = G[u][j] + dist[u];
                path[j] = u;
            }
        }

    }


}