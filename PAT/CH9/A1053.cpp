#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 110;

struct node {
    int weight;
    vector<int> child;
}Node[maxn];

bool cmp(int a, int b)
{
    return Node[a].weight>Node[b].weight;
}
int n;// count of nodes
int m;// count of layers
int S;
int path[maxn];
void DFS(int index , int num , int sum)
{
    //递归出口
    if(sum > S ) return;
    if(sum == S )
    {
        if(Node[index].child.size() != 0 )// is not 
            return;
        for( int j = 0 ; j < num; j++ )
        {
            cout<<path[j]<<" ";
        }
        cout<<endl;
        return;
    }
    int temp;
    for(int i = 0 ; i <Node[index].child.size(); i++)
    {
        temp = Node[index].child[i];
        path[num] = temp;
        sum += Node[temp].weight;
        DFS(temp,++num,sum);
    }
}


int main(int argc, char const *argv[])
{
    cin>>n>>m>>S;

    for(int i = 0 ; i <n; i++)
    {
        cin>>Node[i].weight;
    }

    int id,child_cnt,temp;
    for(int i = 0 ; i<m ; i++)
    {
        cin>>id>>child_cnt;
        for (int i = 0; i < child_cnt; i++)
        {
            cin>>temp;
            Node[id].child.push_back(temp);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);

    }

    return 0;
}
