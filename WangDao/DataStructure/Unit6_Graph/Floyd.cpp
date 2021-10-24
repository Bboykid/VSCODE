#include<cstdio>
#include<algorithm>
using namespace std;

const int INF = 10000000;
const int MAXV = 100;
int n,m; // n为顶点数，m为边数
int dis[MAXV][MAXV];// dist[i][j]表示从顶点i到顶点j的距离

/**
 * @brief 
 *      比较A[i][j]与 A[i][k]+A[k][j]，k结点为中转结点 
 * 
 */

void Floyd()
{
    for( int k = 0 ; k < n; k++ )
    {
        for( int i = o ; i < n; i++ )
        {
            for( int j = 0; j<n; j++ )
            {
                if( dis[i][k]!=INF && dis[i][j] > dis[i][k] + dis[k][j] )
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}