#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=10001;

int N;  //结点数
vector<int> edge[MaxN];
bool visited[MaxN];
int tempH=0;
vector<int> H;
int maxH=0;

void dfs(int curNode,int curHeight)
{
    if(curHeight > tempH)
        tempH = curHeight;
    visited[curNode]=false; //标记为已访问
    for(int x: edge[curNode])
    {
        if(visited[x])    //没被访问过
        {
            dfs(x,curHeight+1);
        }
    }
}

int main()
{
    cin>>N;
    for(int i=0; i<N-1; i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].emplace_back(y);//x与y相连
        edge[y].emplace_back(x);//y与x相连
    }
    
    H.emplace_back(0);
    for(int i=1; i<=N ;i++)
    {
        tempH=0;
        fill(visited,visited+N+1,true);    //标记为未访问
        dfs(i,1);
        H.emplace_back(tempH);
    }
    
    for(int i=1;i<=N;i++)
    {
        if(H[i]>maxH)
            maxH=H[i];
    }
    for(int i=0; i<=N;i++)
    {
        if(H[i]==maxH)
        {
            cout<<i<<endl;
        }
    }
    
    return 0;
}
