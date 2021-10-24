#include<iostream>
#include<vector>

using namespace std;


int Cmax;//每个站的最大容量
int N,Sp,M; //N站数，Sp问题站，M路数
int bike[501];  //每个车站的车数

int dis[501][501];  
vector<int> v[501]; //存放每个结点的邻居
int minDis[501];
vector<int> path;
int final_Dis=999999,final_Send,final_Take;
vector<int> final_Answer;

void dfs(int curStation,int curDis, int curSend, int curTake)
{
    //分支限界
    if(curDis > minDis[curStation] )    return;
    path.emplace_back(curStation);
    //到达终点
    if(curStation==Sp) {
        if(curDis<final_Dis || (curDis==final_Dis&&curSend<final_Send) || (curDis==final_Dis&&curSend==final_Send&&curTake<final_Take))
        {
            final_Answer = path;
            final_Dis = curDis;
            final_Send = curSend;
            final_Take = curTake;
        }
    }
    else {
        
        if(curDis<minDis[curStation])
            minDis[curStation]= curDis;
        for(int i:v[curStation])
        {
            if( curTake+bike[i]<Cmax/2 )
            {
                dfs(i,curDis+dis[curStation][i],curSend+(Cmax/2-curTake-bike[i]),0);
            }
            else
            {
                dfs(i,curDis+dis[curStation][i],curSend,curTake+bike[i]-Cmax/2);
            }
        }

    }


    path.pop_back();

}

int main()
{
    int i,j,k;
    cin>>Cmax>>N>>Sp>>M;
    for(i=1;i<=N;i++)
    {
        cin>>bike[i];
    }
    while(M--)
    {
        cin>>i>>j>>k;
        //i和j互为邻居
        v[i].emplace_back(j);
        v[j].emplace_back(i);
        dis[i][j]=k;
        dis[j][i]=k;
    }
    for(i=0;i<=N;i++)
    {
        minDis[i]=9999999;
    }

    //深度优先遍历
    dfs(0,0,0,0);

    cout<<final_Send<<' ';
    cout<<final_Answer[0];
    for(int i=1;i<final_Answer.size();i++)
    {
        cout<<"->"<<final_Answer[i];
    }
    cout<<' '<<final_Take;
    return 0;
}