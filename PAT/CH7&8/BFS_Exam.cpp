#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 100;

struct node
{
    int x,y;
}Node;
int n,m;
int X[]= {0,0,1,-1};
int Y[] ={1,-1,0,0};

int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

bool valid(int x, int y)
{
    if( x >= n || y >=n || x < 0 || y < 0 )
        return false;
    if(matrix[x][y] == 0 || inq[x][y] == true)
        return false;
    return true;
}

void BFS(int x, int y)
{
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);
    inq[x][y] = true;

    while ( !Q.empty() )
    {
        node top = Q.front();
        Q.pop();
        for( int i =0 ;i<4 ; i++)
        {
            int newX = top.x+X[i],newY =top.y+Y[i];
            if(valid(newX,newY))
            {
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d",&n,&m);
      for(int x =0; x<n; x++)
    {
        for(int y = 0; y<m; y++)
        {
            scanf("%d",&matrix[x][y]);
        }
    }
    int ans = 0;
    for(int x =0; x<n; x++)
    {
        for(int y = 0; y<m; y++)
        {
            if (matrix[x][y] == 1 && inq[x][y] == false)
            {
                ans++;//增加一个连通分量
                BFS(x,y);
            }
            
        }
    }

    return 0;
}
