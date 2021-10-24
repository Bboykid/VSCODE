#include<iostream>
#include<vector>

using namespace std;

int CMax,N,Sp,M;
int bikes[501];
int dis[501][501];  //矩阵表示两个结点的距离
vector<int> v[501]; //每个vector表示其相邻的节点

int minDis[501];
vector<int>path;
int final_dis=999999,final_send,final_take;
vector<int> final_ans;

void dfs(int curStation,int curDis,int curSend,int curTake)
{
    if(curDis>minDis[curStation])
        return;
    path.emplace_back(curStation);
    if(curStation==Sp)
    {
        if(curDis<final_dis || (curDis==final_dis && curSend<final_send) ||(curDis==final_dis && curSend==final_send && curTake<final_take))
        {
            //update final answer
            final_dis = curDis;
            final_send = curSend;
            final_take = curTake;
            final_ans = path;
        }
        
    }
    else
        {
            if(curDis<minDis[curStation])
                 minDis[curStation]=curDis;
            for(int x:v[curStation])
            {
                if(curTake+bikes[x]<(CMax/2))
                {
                    dfs(x,curDis+dis[curStation][x],curSend+((CMax/2)-bikes[x]-curTake),0);
                }
                else
                {
                    dfs(x,curDis+dis[curStation][x],curSend,curTake+bikes[x]-(CMax/2));
                }
            }
        }
    path.pop_back();
}

int main()
{
            int i,j,k;
    cin>>CMax>>N>>Sp>>M;
    for( i=1;i<=N;i++)
    {
        cin>>bikes[i];
    }
    
    while(M--)
    {

        cin>>i>>j>>k;
        dis[i][j]=k;
        dis[j][i]=k;
        v[i].emplace_back(j);
        v[j].emplace_back(i);
    }
    for(i=0;i<=N;i++)
    {
        minDis[i]=999999;
    }
    
    dfs(0,0,0,0);
    
    cout<<final_send<<' ';
    cout<<final_ans[0];
    for(int i=1;i<final_ans.size();i++)
    {
        cout<<"->"<<final_ans[i];
    }
    cout<<' '<<final_take;

    return 0;
}