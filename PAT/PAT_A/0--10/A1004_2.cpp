#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN = 100;

int N;//总结点数
int M;//非叶节点数
vector<int> child[MaxN];//每个vector保存非叶节点的id
int MaxLevel=0;//最大层次
int num[MaxN]={0};//每层的叶子结点数

void dfs(int curId,int curLevel)
{
    if(curLevel>MaxLevel)
        MaxLevel=curLevel;
    if(child[curId].size()>0)
    {
        for(auto x:child[curId])
        {
            dfs(x,curLevel+1);
        }
    }
    else
    {
        num[curLevel]++;
    }
}


int main(int argc, char const *argv[])
{
    int ID,K,temp;
    cin>>N>>M;
    for(int i = 0 ; i<M; i++ )
    {
        cin>>ID>>K;
        while (K--)
        {
            cin>>temp;
            child[ID].emplace_back(temp);
        }
        
    }

    dfs(1,1);

    //OUTPUT
    for(int i=1; i<=MaxLevel; i++)
    {
        if(i>1) cout<<' ';
        cout<<num[i];
    }

    return 0;
}
